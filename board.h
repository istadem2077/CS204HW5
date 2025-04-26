//
// Created by itagi on 4/26/2025.
//

#ifndef BOARD_H
#define BOARD_H
#include <cinttypes>


class Board {
private:
    char* board = nullptr;
    int16_t size = 0;
public:
    Board();
    ~Board();

    void display_board();
    bool is_full();

    bool cell_empty(int position);
    bool place_cell(int position, char playerID);
    int16_t owned_cell(char playerID);

    int16_t getSize() const { return size; }
};



#endif //BOARD_H
