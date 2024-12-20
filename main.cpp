#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <getopt.h>

#include "src/FileHandler.h"
#include "src/GameOfLife.h"
#include "src/Timing.h"


void printUsage() {
    std::cout << "Usage: gol --load <filename> --save <filename> --generations <n> [--measure]\n";
}

int main(int argc, char* argv[]) {
    Timing* timing = Timing::getInstance();
    timing->startSetup();

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

        timing->stopSetup();
        timing->startComputation();

        board = gol.simulate(board, generations);

        timing->stopComputation();
        timing->startFinalization();
        std::cout << "Finished simulation" << std::endl;
        FileHandler::saveBoard(saveFile, board);

        // Compare with other board
        auto compareBoard = FileHandler::loadBoard("random1000_out.gol");
        bool isSame = board->compareBoard(compareBoard);
        if (!isSame) {
            std::cerr << "Board doesn't match" << std::endl;
        }
        timing->stopFinalization();
        std::string output = timing->getResults();
        if (measure) {
            std::cout << output << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
