//
// Created by Paul on 07/12/2024.
//

#include "GameOfLife.h"

#include <iostream>

Board* GameOfLife::simulate(Board* board, int generations) {
    for (int gen = 0; gen < generations; ++gen) {
        Board* newBoard = new Board(board->rows, board->cols);

        for (int r = 0; r < board->rows; ++r) {
            for (int c = 0; c < board->cols; ++c) {
                int liveNeighbors = countLiveNeighbors(board, r, c);

                if (board->board[r][c]) {
                    newBoard->board[r][c] = (liveNeighbors == 2 || liveNeighbors == 3);
                } else {
                    newBoard->board[r][c] = (liveNeighbors == 3);
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
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int nr = (row + dr + board->rows) % board->rows;
            int nc = (col + dc + board->cols) % board->cols;
            if (board->board[nr][nc]) ++count;
        }
    }
    return count;
}
