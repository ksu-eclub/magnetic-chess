cmake_minimum_required(VERSION 3.0)
project(magnetic-chess)
set(CMAKE_BUILD_TYPE Debug)

add_executable(magnetic-chess
    src/hardware/mock/leds.c
    src/hardware/mock/magnet.c
    src/hardware/mock/steppers.c
    src/logic/real/gantry.c
    src/logic/real/leds.c
    src/logic/real/logic-listener.c
    src/logic/real/logic.c
    src/ui/mock/board.c
    src/ui/mock/input.c
    src/ui/mock/log.c
    src/ui/mock/status.c
    src/ui/mock/title.c
    src/ui/mock/ui.c
    src/main.c
)

include_directories(
    include
)

target_link_libraries(magnetic-chess
    pthread
)
