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

file(COPY ${CMAKE_SOURCE_DIR}/files/random10000_in.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/files/random10000_out.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/files/random1000_in.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/files/random1000_out.gol DESTINATION ${CMAKE_BINARY_DIR})
