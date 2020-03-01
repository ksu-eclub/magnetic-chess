cmake_minimum_required(VERSION 3.6)
project(magnetic-chess)
set(CMAKE_BUILD_TYPE Debug)

add_executable(magnetic-chess
    rpc/chess_service.grpc.pb.cc
    rpc/chess_service.pb.cc
    rpc/ChessServiceImpl.cpp
    rpc/norpc.c
    rpc/rpc.cpp
    logic-listener.c
    logic.c
    main.c
)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/rpc
    COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/rpc
)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.pb.cc ${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.pb.h
    COMMAND protoc -I ${CMAKE_CURRENT_SOURCE_DIR}/rpc --cpp_out=. ${CMAKE_CURRENT_SOURCE_DIR}/rpc/chess_service.proto || true
    MAIN_DEPENDENCY rpc/chess_service.proto
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/rpc
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rpc
)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.grpc.pb.cc ${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.grpc.pb.h
    COMMAND protoc -I ${CMAKE_CURRENT_SOURCE_DIR}/rpc --grpc_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ${CMAKE_CURRENT_SOURCE_DIR}/rpc/chess_service.proto || true
    MAIN_DEPENDENCY rpc/chess_service.proto
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/rpc
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rpc
)

set_source_files_properties(
    rpc/chess_service.pb.cc
    PROPERTIES
    OBJECT_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.pb.cc"
    COMPILE_FLAGS "-I${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}"
)
set_source_files_properties(
    rpc/chess_service.grpc.pb.cc
    PROPERTIES
    OBJECT_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.grpc.pb.cc"
    COMPILE_FLAGS "-I${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}"
)

set_source_files_properties(
    rpc/chess_service.pb.h
    PROPERTIES
    OBJECT_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.pb.h"
    COMPILE_FLAGS "-I${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}"
)
set_source_files_properties(
    rpc/chess_service.grpc.pb.h
    PROPERTIES
    OBJECT_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/rpc/chess_service.grpc.pb.h"
    COMPILE_FLAGS "-I${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}"
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PKG_PROTOBUF IMPORTED_TARGET protobuf)
pkg_check_modules(PKG_GRPC IMPORTED_TARGET grpc++)
if (PKG_PROTOBUF_FOUND AND PKG_GRPC_FOUND)
    target_link_libraries(
        magnetic-chess PUBLIC
        PkgConfig::PKG_PROTOBUF
        PkgConfig::PKG_GRPC
    )
endif()
