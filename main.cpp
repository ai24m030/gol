#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <getopt.h>

#include "src/FileHandler.h"
#include "src/GameOfLife.h"


void printUsage() {
    std::cout << "Usage: gol --load <filename> --save <filename> --generations <n> [--measure]\n";
}

int main(int argc, char* argv[]) {
    std::string loadFile, saveFile;
    int generations = 0;
    bool measure = false;

    struct option longOptions[] = {
        {"load", required_argument, 0, 'l'},
        {"save", required_argument, 0, 's'},
        {"generations", required_argument, 0, 'g'},
        {"measure", no_argument, 0, 'm'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "l:s:g:m", longOptions, nullptr)) != -1) {
        switch (opt) {
            case 'l':
                loadFile = optarg;
                break;
            case 's':
                saveFile = optarg;
                break;
            case 'g':
                generations = std::stoi(optarg);
                break;
            case 'm':
                measure = true;
                break;
            default:
                printUsage();
                return 1;
        }
    }

    if (loadFile.empty() || saveFile.empty() || generations <= 0) {
        printUsage();
        return 1;
    }

    try {
        auto board = FileHandler::loadBoard(loadFile);
        std::cout << "File loaded" << std::endl;

        GameOfLife gol = GameOfLife();

        std::cout << "Start simulation" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        board = gol.simulate(board, generations);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Finished simulation" << std::endl;
        FileHandler::saveBoard(saveFile, board);

        // Compare with other board
        auto compareBoard = FileHandler::loadBoard("random10000_out.gol");
        bool isSame = board->compareBoard(compareBoard);
        if (!isSame) {
            std::cerr << "Board doesn't match" << std::endl;
        }
        if (measure) {
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Simulation time: " << elapsed.count() << " seconds\n";
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
