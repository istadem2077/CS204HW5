//
// Created by Ismayil Taghi-Zada on 4/26/2025.
//

#ifndef BOARD_H
#define BOARD_H
#include <cinttypes>


class Board {
private:
    char* board = nullptr;
    int16_t size = 0; // I used cinttypes type definitions because that's a better practice, as integer size can vary
                      // from platform to platform, and using integers of 32 bit when they are clearly unused is unnecessary
public:
    Board(const int16_t size) : board(new char[size]), size(size) {
        for (int16_t i = 0; i < size; i++) {
            board[i] = '-';
        }
    }
    ~Board();

    void display_board() const;
    bool is_full() const;

    bool cell_empty(int position) const;
    void place_cell(int position, char playerID);
    int16_t owned_cell(char playerID) const;

    int16_t getSize() const { return size; }
};



#endif //BOARD_H
