cmake_minimum_required(VERSION 3.29)
project(gol)

set(CMAKE_CXX_STANDARD 20)

add_executable(gol main.cpp
        src/FileHandler.cpp
        src/FileHandler.h
        src/Board.h
        src/GameOfLife.cpp
        src/GameOfLife.h
)

file(COPY ${CMAKE_SOURCE_DIR}/files/0_1000_500_300.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/files/0_1000_500_0.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/files/random10000_in.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/files/random10000_out.gol DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/4_4_0.gol DESTINATION ${CMAKE_BINARY_DIR})
