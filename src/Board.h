//
// Created by Paul on 07/12/2024.
//

#ifndef BOAD_H
#define BOARD_H
#include <vector>
#include <iostream>

class Board {
    public:
    int rows;
    int cols;
    std::vector<std::vector<bool>> board;

    Board(int rows, int cols) : rows(rows), cols(cols) {
        board.resize(rows, std::vector<bool>(cols, false));
    }

    bool compareBoard(Board* other) {
        if (rows != other->rows || cols != other->cols) {
            std::cout << "ERROR: [compareBoards] Board sizes don't match" << std::endl;
            std::cout << rows << ", " << cols << "\n" << other->rows << ", " << other->cols << std::endl;
            return false;
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] != other->board[r][c]) {
                    std::cout << "ERROR: [compareBoards] Boards don't match at " <<
                        r << ", " << c << std::endl;
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //BOARD_H
