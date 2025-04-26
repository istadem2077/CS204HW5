cmake_minimum_required(VERSION 3.31)
project(HW5)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(HW5
        hw5main.cpp
        player.cpp
        player.h
        board.cpp
        board.h
)
