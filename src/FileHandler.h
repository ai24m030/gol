//
// Created by Paul on 07/12/2024.
//

#ifndef FILELOADER_H
#define FILELOADER_H
#include <string>


class Board;

class FileHandler {
public:
    static Board* loadBoard(const std::string& filename);
    static void saveBoard(const std::string& filename, Board* board);
};



#endif //FILELOADER_H
