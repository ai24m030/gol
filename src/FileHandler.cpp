//
// Created by Paul on 07/12/2024.
//

#include "FileHandler.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <stdexcept>
#include "Board.h"

Board* FileHandler::loadBoard(const std::string &filename) {

    std::ifstream infile(filename);
    if (!infile.is_open()) {
        throw std::runtime_error("Failed to open file " + filename);
    }

    std::string line;
    // Read the first line for rows and columns
    std::getline(infile, line);
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos) {
        throw std::runtime_error("Invalid format in the first line: missing ','");
    }

    int cols = std::stoi(line.substr(0, commaPos));
    int rows = std::stoi(line.substr(commaPos + 1));

    auto board = new Board(rows, cols);

    // Read the rest of the file for the board state
    for (int i = 0; i < rows; ++i) {
        std::getline(infile, line);
        if (line.length() != static_cast<size_t>(cols)) {
            std::cout << line.length() << std::endl;
            std::cout << cols << std::endl;
            std::cout << static_cast<size_t>(cols) << std::endl;
            throw std::runtime_error("Invalid row length in line " + std::to_string(i + 2));
        }
        for (int j = 0; j < cols; ++j) {
            board->board[i][j] = (line[j] == 'x');
        }
    }

    infile.close();
    return board;
}

void FileHandler::saveBoard(const std::string &filename, Board* board) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        throw std::runtime_error("Failed to open file " + filename);
    }
    std::cout << "writing output" << std::endl;
    outfile << board->cols << "," << board->rows << "\n";
    for (const auto& row : board->board) {
        for (bool cell : row) {
            outfile << (cell ? 'x' : '.');
        }
        outfile << '\n';
    }

    outfile.close();
}

