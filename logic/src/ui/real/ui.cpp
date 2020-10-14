#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <google/protobuf/empty.pb.h>
#include <grpc++/grpc++.h>
#include <magchess/ui/chess_service.grpc.pb.h>
#include <magchess/ui/chess_service.pb.h>
#include <magchess/ui/real.hpp>
extern "C" {
#include <magchess/logic/logic.h>
#include <magchess/ui/ui.h>
}

using namespace std;
using namespace std::chrono;
using namespace google::protobuf;
using namespace grpc;
using namespace magnetic_chess;

static inline coordinate_t c(const magnetic_chess::Coordinate &coord);

static unique_ptr<ChessServiceImpl> service;
static ServerBuilder builder;

ChessServiceImpl::ChessServiceImpl() {
    void *tmp;
    add_listener(listener_proxy, this, &tmp);
}

Status ChessServiceImpl::ResetBoard(ServerContext *ctx, const Empty *req, Empty *res) {
    reset_board();
    return Status::OK;
}

Status ChessServiceImpl::GetMoves(ServerContext *ctx, const GetMovesRequest *req, GetMovesResponse *res) {
    coordinate_t buffer[16];
    int count = get_moves(c(req->tile()), buffer, sizeof(buffer) / sizeof(buffer[0]));
    res->clear_destinations();
    for (int i = 0; i < count; ++i) {
        Coordinate *dest = res->add_destinations();
        dest->set_x(buffer[i].x);
        dest->set_y(buffer[i].y);
    }
    return Status::OK;
}

Status ChessServiceImpl::Move(ServerContext *ctx, const MoveRequest *req, MoveResponse *res) {
    res->set_error((MoveResponse_Error) move(c(req->from()), c(req->to())));
    return Status::OK;
}

Status ChessServiceImpl::RestorePiece(ServerContext *ctx, const RestorePieceRequest *req, RestorePieceResponse *res) {
    res->set_error((RestorePieceResponse_Error) restore((piece_type_t) req->type()));
    return Status::OK;
}

Status ChessServiceImpl::StreamBoard(ServerContext *ctx, const Empty *req, ServerWriter<GameState> *writer) {
    cout << "Starting board streaming." << endl;
    unique_lock<mutex> lck(mtx);
    writer->Write(gameState);
    lck.unlock();
    system_clock::time_point deadline = ctx->deadline();
    while (!ctx->IsCancelled()) {
        lck.lock();
        if (cond.wait_until(lck, deadline) == cv_status::timeout) {
            break;
        }
        writer->Write(gameState);
    }
    cout << "Board stream closed" << endl;
    return Status::OK;
}

static void listener_proxy(color_t turn, state_t state, char board[64], void *context) {
    ChessServiceImpl *service = (ChessServiceImpl *) context;
    std::unique_lock<mutex> lck(service->mtx);
    if (turn != cr_none && state != st_unknown) {
        service->gameState.set_state((GameState_State) (state + turn - 1));
    } else {
        service->gameState.set_state(GameState_State::GameState_State_UNKNOWN);
    }
    service->gameState.set_board(string(board, 64));
    service->cond.notify_all();
}

static inline coordinate_t c(const magnetic_chess::Coordinate &coord) {
    return coordinate_t {
        .x = coord.x(),
        .y = coord.y()
    };
}

void ui_init() {
    service.reset(new ChessServiceImpl());
    builder.AddListeningPort("0.0.0.0:50051", InsecureServerCredentials())
        .RegisterService(service.get());
}

void ui_run() {
    unique_ptr<Server> server(builder.BuildAndStart());
    cout << "RPC server running on 0.0.0.0:50051" << endl;
    server->Wait();
}
