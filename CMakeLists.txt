cmake_minimum_required(VERSION 3.15)
project(snake)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Werror -g --std=c++17")

# output binary files to bin directory
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# need this to find header files
include_directories(include)

add_executable(snake
    ../src/snake/main.cc
    ../src/snake/core/apple.cc
    ../src/snake/core/board.cc
    ../src/snake/core/snake.cc
    ../src/snake/core/game_state.cc
    ../src/snake/util/kb_io.cc
    ../src/snake/util/movement.cc
    ../include/snake/core/apple.h
    ../include/snake/core/board.h
    ../include/snake/core/snake.h
    ../include/snake/core/game_state.h
    ../include/snake/util/kb_io.h
    ../include/snake/util/movement.h)
