#include <stdio.h>
#include <rpc/chess_service.pb.h>
#include <rpc/chess_service.grpc.pb.h>
#include "ChessServiceImpl.hpp"
#ifndef NO_GRPC

grpc::Status ChessServiceImpl::ResetBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, google::protobuf::Empty *response) {
    puts("ResetBoard");
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::GetMoves(grpc::ServerContext *context, const magnetic_chess::GetMovesRequest *request, magnetic_chess::GetMovesResponse *response) {
    puts("GetMoves");
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::Move(grpc::ServerContext *context, const magnetic_chess::MoveRequest *request, magnetic_chess::MoveResponse *response) {
    puts("Move");
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::RestorePiece(grpc::ServerContext *context, const magnetic_chess::RestorePieceRequest *request, magnetic_chess::RestorePieceResponse *response) {
    puts("RestorePiece");
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::StreamBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, grpc::ServerWriter<magnetic_chess::GameState> *writer) {
    puts("StreamBoard");
    return grpc::Status::OK;
}

#endif
