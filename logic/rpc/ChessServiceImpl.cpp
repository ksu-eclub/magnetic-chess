#include <cstring>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <rpc/chess_service.pb.h>
#include <rpc/chess_service.grpc.pb.h>
#include "../logic.h"
#include "ChessServiceImpl.hpp"
#ifndef NO_GRPC

#define MOVES_BUFFER_SIZE 16

extern "C" void chess_service_impl_listener_proxy(color_t turn, state_t state, char board[64], void *context);

ChessServiceImpl::ChessServiceImpl() {
    memset(boardBuf, 0, 65);
    gameState.set_board(boardBuf);
    gameState.set_state(magnetic_chess::GameState_State::GameState_State_UNKNOWN);
    void *tmp;
    add_listener(chess_service_impl_listener_proxy, this, &tmp);
}

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
    std::cout << "Starting board streaming" << std::endl;
    {
        std::unique_lock<std::mutex> lck(mtx);
        writer->Write(gameState);
    }
    std::chrono::system_clock::time_point deadline = context->deadline();
    while (!context->IsCancelled()) {
        std::unique_lock<std::mutex> lck(mtx);
        if (cv.wait_until(lck, deadline) == std::cv_status::timeout) {
            break;
        }
        writer->Write(gameState);
    }
    std::cout << "Board stream closed" << std::endl;
    return grpc::Status::OK;
}

void ChessServiceImpl::OnBoardChange(color_t turn, state_t state, char board[64]) {
    std::unique_lock<std::mutex> lck(mtx);
    gameState.set_state(magnetic_chess::GameState_State::GameState_State_UNKNOWN);
    if (turn != cr_none && state != st_unknown) {
        gameState.set_state((magnetic_chess::GameState_State) (state + turn - 1));
    }
    memcpy(boardBuf, board, 64);
    gameState.set_board(boardBuf);
    cv.notify_all();
}

void chess_service_impl_listener_proxy(color_t turn, state_t state, char board[64], void *context) {
    ChessServiceImpl *service = (ChessServiceImpl *) context;
    service->OnBoardChange(turn, state, board);
}

#endif
