cmake_minimum_required(VERSION 3.0)
project(magnetic-chess)
set(CMAKE_BUILD_TYPE Debug)

set(HARDWARE_IMPL mock)
set(LOGIC_IMPL real)
set(UI_IMPL mock)

find_package(Protobuf)

find_program(gRPC grpc_cpp_plugin)
find_package(PackageMessage)
if (gRPC)
    find_package_message(gRPC "Found gRPC: ${gRPC}" "${gRPC}")
else()
    find_package_message(gRPC "Could NOT find gRPC (missing: gRPC)" "")
endif()

find_package(PkgConfig)
if (PkgConfig_FOUND)
    pkg_check_modules(PKG_GRPC IMPORTED_TARGET grpc++)
endif()

if (Protobuf_FOUND AND gRPC AND PKG_GRPC_FOUND)
    set(PROTOBUF_SRCS
        ${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui/chess_service.pb.cc
        ${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui/chess_service.grpc.pb.cc
    )
    set(PROTOBUF_HDRS
        ${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui/chess_service.pb.h
        ${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui/chess_service.grpc.pb.h
    )
    add_custom_command(
        OUTPUT ${PROTOBUF_SRCS} ${PROTOBUF_HDRS}
        COMMAND mkdir
        ARGS -p ${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui
        COMMAND protobuf::protoc
        ARGS -I ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/real --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui --grpc_out=${CMAKE_CURRENT_BINARY_DIR}/include/magchess/ui --plugin=protoc-gen-grpc=${gRPC} chess_service.proto
        MAIN_DEPENDENCY src/ui/real/chess_service.proto
    )
    list(APPEND Protobuf_LIBRARIES PkgConfig::PKG_GRPC)
endif()

set(SRCS
    src/main.c
)

if (HARDWARE_IMPL STREQUAL "mock")
    list(APPEND SRCS
        src/hardware/mock/leds.c
        src/hardware/mock/magnet.c
        src/hardware/mock/steppers.c
    )
endif()
if (HARDWARE_IMPL STREQUAL "real")
    list(APPEND SRCS
        src/hardware/real/i2c.c
        src/hardware/real/leds.c
        src/hardware/real/magnet.c
        src/hardware/real/steppers.c
    )
endif()

if (LOGIC_IMPL STREQUAL "real")
    list(APPEND SRCS
        src/logic/real/gantry.c
        src/logic/real/leds.c
        src/logic/real/logic-listener.c
        src/logic/real/logic.c
    )
endif()

if (UI_IMPL STREQUAL "mock")
    list(APPEND SRCS
        src/ui/mock/board.c
        src/ui/mock/input.c
        src/ui/mock/log.c
        src/ui/mock/status.c
        src/ui/mock/title.c
        src/ui/mock/ui.c
    )
endif()
if (UI_IMPL STREQUAL "real")
    list(APPEND SRCS
        src/ui/real/ui.cpp
        ${PROTOBUF_SRCS}
    )
endif()

add_executable(magnetic-chess ${SRCS})

include_directories(
    include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

target_link_libraries(magnetic-chess
    pthread
    ${Protobuf_LIBRARIES}
)
