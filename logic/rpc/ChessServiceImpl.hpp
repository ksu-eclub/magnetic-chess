#ifndef CHESS_SERVICE_IMPL_HPP
#define CHESS_SERVICE_IMPL_HPP

#include <rpc/chess_service.pb.h>
#include <rpc/chess_service.grpc.pb.h>
#ifndef NO_GRPC

class ChessServiceImpl final : public magnetic_chess::ChessService::Service {
    public:
        virtual grpc::Status ResetBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, google::protobuf::Empty *response);
        virtual grpc::Status GetMoves(grpc::ServerContext *context, const magnetic_chess::GetMovesRequest *request, magnetic_chess::GetMovesResponse *response);
        virtual grpc::Status Move(grpc::ServerContext *context, const magnetic_chess::MoveRequest *request, magnetic_chess::MoveResponse *response);
        virtual grpc::Status RestorePiece(grpc::ServerContext *context, const magnetic_chess::RestorePieceRequest *request, magnetic_chess::RestorePieceResponse *response);
        virtual grpc::Status StreamBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, grpc::ServerWriter<magnetic_chess::GameState> *writer);
};

#endif
#endif
