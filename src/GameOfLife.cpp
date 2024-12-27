//
// Created by Paul on 07/12/2024.
//

#include "GameOfLife.h"
#include <omp.h>

Board* GameOfLife::simulate_generations(Board* board, int generations) {
    for (int gen = 0; gen < generations; ++gen) {
        Board* newBoard = new Board(board->rows, board->cols);

        for (int x = 0; x < board->rows; ++x) {
            for (int y = 0; y < board->cols; ++y) {
                int liveNeighbors = countLiveNeighbors(board, x, y);

                if (board->board[x][y]) {
                    newBoard->board[x][y] = (liveNeighbors == 2 || liveNeighbors == 3);
                } else {
                    newBoard->board[x][y] = (liveNeighbors == 3);
                }
            }
        }
        delete board;
        board = newBoard;
    }
    return board;
}

Board * GameOfLife::simulate_generations_omp(Board *board, int generations) {
    for (int gen = 0; gen < generations; ++gen) {
        Board* newBoard = new Board(board->rows, board->cols);

        #pragma omp parallel for
        for (int x = 0; x < board->rows; ++x) {
            for (int y = 0; y < board->cols; ++y) {
                int liveNeighbors = countLiveNeighbors(board, x, y);

                if (board->board[x][y]) {
                    newBoard->board[x][y] = (liveNeighbors == 2 || liveNeighbors == 3);
                } else {
                    newBoard->board[x][y] = (liveNeighbors == 3);
                }
            }
        }
        delete board;
        board = newBoard;
    }
    return board;
}

int GameOfLife::countLiveNeighbors(Board* board, int row, int col) const {
    int count = 0;
    for (int x_comp = -1; x_comp <= 1; ++x_comp) {
        for (int y_comp = -1; y_comp <= 1; ++y_comp) {
            if (x_comp == 0 && y_comp == 0) continue;
            int x_neighbour = (row + x_comp + board->rows) % board->rows;
            int y_neighbour = (col + y_comp + board->cols) % board->cols;
            if (board->board[x_neighbour][y_neighbour]) ++count;
        }
    }
    return count;
}
