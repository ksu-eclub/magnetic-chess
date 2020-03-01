#ifndef CHESS_SERVICE_IMPL_HPP
#define CHESS_SERVICE_IMPL_HPP

#include <rpc/chess_service.pb.h>
#include <rpc/chess_service.grpc.pb.h>
#ifndef NO_GRPC

#include <mutex>
#include <condition_variable>
#include "../logic.h"

class ChessServiceImpl final : public magnetic_chess::ChessService::Service {
    public:
        ChessServiceImpl();
        virtual grpc::Status ResetBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, google::protobuf::Empty *response);
        virtual grpc::Status GetMoves(grpc::ServerContext *context, const magnetic_chess::GetMovesRequest *request, magnetic_chess::GetMovesResponse *response);
        virtual grpc::Status Move(grpc::ServerContext *context, const magnetic_chess::MoveRequest *request, magnetic_chess::MoveResponse *response);
        virtual grpc::Status RestorePiece(grpc::ServerContext *context, const magnetic_chess::RestorePieceRequest *request, magnetic_chess::RestorePieceResponse *response);
        virtual grpc::Status StreamBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, grpc::ServerWriter<magnetic_chess::GameState> *writer);
        virtual void OnBoardChange(color_t turn, state_t state, char board[64]);
    
    private:
        std::mutex mtx;
        std::condition_variable cv;
        magnetic_chess::GameState gameState;
        char boardBuf[65];
};

#endif
#endif
