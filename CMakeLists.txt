cmake_minimum_required(VERSION 3.29)
project(gol)

set(CMAKE_CXX_STANDARD 20)

add_executable(gol main.cpp
        src/FileHandler.cpp
        src/FileHandler.h
        src/Board.h
        src/GameOfLife.cpp
        src/GameOfLife.h
        src/Timing.cpp
        src/Timing.h
)

find_package(OpenMP REQUIRED)
target_link_libraries(gol PRIVATE OpenMP::OpenMP_CXX)
