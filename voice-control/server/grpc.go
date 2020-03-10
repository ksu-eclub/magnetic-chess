package server

import (
	"context"
	"io"

	"./magnetic_chess"
	"github.com/golang/protobuf/ptypes/empty"
	log "github.com/sirupsen/logrus"
	"google.golang.org/grpc"
)

var (
	stateMap = []int{
		stateUnknown,            // magnetic_chess.GameState_UNKNOWN
		stateWhite | stateTurn,  // magnetic_chess.GameState_PLAYER_A_TURN
		statePurple | stateTurn, // magnetic_chess.GameState_PLAYER_B_TURN
		stateWhite,              // magnetic_chess.GameState_PLAYER_A_WON
		statePurple,             // magnetic_chess.GameState_PLAYER_B_WON
		stateWhite,              // magnetic_chess.GameState_PLAYER_A_RESTORE
		statePurple,             // magnetic_chess.GameState_PLAYER_B_RESTORE
	}
	conn   *grpc.ClientConn
	client magnetic_chess.ChessServiceClient
	board  string
)

func grpcInit() {
	var err error
	conn, err = grpc.Dial("127.0.0.1:50051", grpc.WithInsecure())
	if err != nil {
		errCh <- err
		return
	}
	log.Info("Connected to GRPC server.")
	client = magnetic_chess.NewChessServiceClient(conn)
	startStream()
}

func grpcCleanup() {
	if conn != nil {
		conn.Close()
	}
}

func startStream() {
	stream, err := client.StreamBoard(context.Background(), &empty.Empty{})
	if err != nil {
		errCh <- err
	}
	go (func() {
		update, err := stream.Recv()
		if err != nil {
			if err == io.EOF {
				startStream()
			} else {
				errCh <- err
			}
		}
		if update != nil {
			board = *update.Board
			state = stateMap[*update.State]
		}
	})()
}

func tryMove(piece string, fromX int, fromY int, toX int, toY int) bool {
	matches := []magnetic_chess.MoveRequest{}
	for x := int32(1); x <= 8; x++ {
		for y := int32(1); y < 8; y++ {
			i := x*8 + y - 9
			if ((piece == "x" && board[i] >= 'a' && board[i] <= 'z') ||
				(piece == "X" && board[i] >= 'A' && board[i] <= 'Z') ||
				piece[0] == board[i]) &&
				(fromX == 0 || fromX == int(x)) &&
				(fromY == 0 || fromY == int(y)) {
				res, err := client.GetMoves(context.Background(), &magnetic_chess.GetMovesRequest{
					Tile: &magnetic_chess.Coordinate{
						X: &x,
						Y: &y,
					},
				})
				if err != nil {
					errCh <- err
					return false
				}
				for _, dest := range res.Destinations {
					if (toX == 0 || toX == int(*dest.X)) && (toY == 0 || toY == int(*dest.Y)) {
						matches = append(matches, magnetic_chess.MoveRequest{
							From: &magnetic_chess.Coordinate{
								X: &x,
								Y: &y,
							},
							To: dest,
						})
					}
				}
			}
		}
	}
	switch n := len(matches); n {
	case 1:
		res, err := client.Move(context.Background(), &matches[0])
		if err != nil {
			errCh <- err
			return false
		}
		switch *res.Error {
		case magnetic_chess.MoveResponse_SUCCESS:
			return true
		case magnetic_chess.MoveResponse_NOT_VALID:
			log.Debug("Move not valid")
			break
		case magnetic_chess.MoveResponse_IN_CHECK:
			log.Debug("In check and move does not solve")
			break
		}
		break
	case 0:
		log.Debug("Move didn't find any matches")
		break
	default:
		log.Debugf("Move ambiguous between %d matches", n)
		break
	}
	return false
}
