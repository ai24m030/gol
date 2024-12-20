#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "src/FileHandler.h"
#include "src/GameOfLife.h"
#include "src/Timing.h"


void printUsage() {
    std::cout << "Usage: gol --load <filename> --save <filename> --generations <n> [--measure]\n";
}

int main(int argc, char *argv[]) {
    Timing *timing = Timing::getInstance();
    timing->startSetup();

    std::string loadFile, saveFile;
    int generations = 0;
    bool measure = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-l" || arg == "--load") {
            if (i + 1 < argc) {
                loadFile = argv[++i];
            } else {
                std::cerr << "Error: Missing argument for " << arg << "\n";
                printUsage();
                return 1;
            }
        } else if (arg == "-s" || arg == "--save") {
            if (i + 1 < argc) {
                saveFile = argv[++i];
            } else {
                std::cerr << "Error: Missing argument for " << arg << "\n";
                printUsage();
                return 1;
            }
        } else if (arg == "-g" || arg == "--generations") {
            if (i + 1 < argc) {
                generations = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: Missing argument for " << arg << "\n";
                printUsage();
                return 1;
            }
        } else if (arg == "-m" || arg == "--measure") {
            measure = true;
        } else {
            std::cerr << "Unknown option: " << arg << "\n";
            printUsage();
            return 1;
        }
    }

    if (loadFile.empty() || saveFile.empty() || generations <= 0) {
        printUsage();
        return 1;
    }

    auto board = FileHandler::loadBoard(loadFile);
    //std::cout << "File loaded" << std::endl;

    GameOfLife gol = GameOfLife();
    timing->stopSetup();

    //std::cout << "Start simulation" << std::endl;
    timing->startComputation();
    board = gol.simulate_generations(board, generations);
    timing->stopComputation();

    timing->startFinalization();
    //std::cout << "Finished simulation" << std::endl;
    FileHandler::saveBoard(saveFile, board);
    timing->stopFinalization();

    std::string output = timing->getResults();
    if (measure) {
        std::cout << output << std::endl;
    }

    /**
     *  Simple Testing
     **/
    /*
    auto compareBoard = FileHandler::loadBoard("random250_out.gol");
    bool isSame = board->compareBoard(compareBoard);
    if (!isSame) {
        std::cerr << "Board doesn't match" << std::endl;
    }
    */

    return 0;
}
