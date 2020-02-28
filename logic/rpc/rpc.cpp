#include <iostream>
#include <string>
#include <rpc/chess_service.pb.h>
#include <rpc/chess_service.grpc.pb.h>
#include "ChessServiceImpl.hpp"
#include "rpc.h"
#ifndef NO_GRPC
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#endif

extern "C" void rpc_init(void) {
#ifdef NO_GRPC

    puts("Running without RPC!");

#else

    std::string server_addr("0.0.0.0:50051");
    ChessServiceImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "RPC server running on " << server_addr << std::endl;
    server->Wait();

#endif
}
