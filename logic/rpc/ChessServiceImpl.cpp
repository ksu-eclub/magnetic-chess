#include <stdio.h>
#include <unistd.h>
#include <rpc/chess_service.pb.h>
#include <rpc/chess_service.grpc.pb.h>
#include "../logic.h"
#include "ChessServiceImpl.hpp"
#ifndef NO_GRPC

#define MOVES_BUFFER_SIZE 16

grpc::Status ChessServiceImpl::ResetBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, google::protobuf::Empty *response) {
    reset_board();
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::GetMoves(grpc::ServerContext *context, const magnetic_chess::GetMovesRequest *request, magnetic_chess::GetMovesResponse *response) {
    coordinate_t buffer[MOVES_BUFFER_SIZE];
    const magnetic_chess::Coordinate tile = request->tile();
    coordinate_t from = {
        .x = tile.x(),
        .y = tile.y()
    };
    int count = get_moves(from, buffer, MOVES_BUFFER_SIZE);
    response->clear_destinations();
    for (int i = 0; i < count; ++i) {
        magnetic_chess::Coordinate *dest = response->add_destinations();
        dest->set_x(buffer[i].x);
        dest->set_y(buffer[i].y);
    }
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::Move(grpc::ServerContext *context, const magnetic_chess::MoveRequest *request, magnetic_chess::MoveResponse *response) {
    const magnetic_chess::Coordinate from = request->from();
    const magnetic_chess::Coordinate to = request->to();
    coordinate_t f = {
        .x = from.x(),
        .y = from.y()
    };
    coordinate_t t = {
        .x = to.x(),
        .y = to.y()
    };
    move_error_t err = move(f, t);
    response->set_error((magnetic_chess::MoveResponse_Error) err);
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::RestorePiece(grpc::ServerContext *context, const magnetic_chess::RestorePieceRequest *request, magnetic_chess::RestorePieceResponse *response) {
    restore_error_t err = restore((piece_type_t) request->type());
    response->set_error((magnetic_chess::RestorePieceResponse_Error) err);
    return grpc::Status::OK;
}

grpc::Status ChessServiceImpl::StreamBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, grpc::ServerWriter<magnetic_chess::GameState> *writer) {
    puts("StreamBoard");
    while (!context->IsCancelled()) {
        magnetic_chess::GameState state;
        state.set_state(magnetic_chess::GameState_State::GameState_State_UNKNOWN);
        state.set_board("abc123");
        writer->Write(state);
        sleep(1);
    }
    puts("Stream Closed");
    return grpc::Status::OK;
}

#endif
