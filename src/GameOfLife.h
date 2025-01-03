﻿//
// Created by Paul on 07/12/2024.
//

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Board.h"

class GameOfLife {
public:
    Board* simulate_generations(Board* board, int generations);
    Board* simulate_generations_omp(Board* board, int generations);

private:
    int countLiveNeighbors(Board* board, int row, int col) const;
};


#endif //GAMEOFLIFE_H
