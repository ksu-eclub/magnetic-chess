#ifndef MAGCHESS_UI_REAL_HPP
#define MAGCHESS_UI_REAL_HPP

#include <condition_variable>
#include <mutex>
#include <magchess/ui/chess_service.grpc.pb.h>
#include <magchess/ui/chess_service.pb.h>
extern "C" {
#include <magchess/logic/logic.h>
}

static void listener_proxy(color_t turn, state_t state, char board[64], void *context);

class ChessServiceImpl : public magnetic_chess::ChessService::Service {
    friend void listener_proxy(color_t turn, state_t state, char board[64], void *context);

    public:
        ChessServiceImpl();

        virtual grpc::Status ResetBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, google::protobuf::Empty *response);
        virtual grpc::Status GetMoves(grpc::ServerContext *context, const magnetic_chess::GetMovesRequest *request, magnetic_chess::GetMovesResponse *response);
        virtual grpc::Status Move(grpc::ServerContext *context, const magnetic_chess::MoveRequest *request, magnetic_chess::MoveResponse *response);
        virtual grpc::Status RestorePiece(grpc::ServerContext *context, const magnetic_chess::RestorePieceRequest *request, magnetic_chess::RestorePieceResponse *response);
        virtual grpc::Status StreamBoard(grpc::ServerContext *context, const google::protobuf::Empty *request, grpc::ServerWriter<magnetic_chess::GameState> *writer);

    private:
        std::mutex mtx;
        std::condition_variable cond;
        magnetic_chess::GameState gameState;
};

#endif
