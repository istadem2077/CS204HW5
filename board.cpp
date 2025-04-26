//
// Created by Ismayil Taghi-Zada on 4/26/2025.
//


#include <iostream>
#include "board.h"


void Board::display_board() const {
    for (int16_t i = 0; i < size; i++) {
        std::cout << board[i] << " ";
    }
    std::cout << std::endl;
}

/*
 * if during iteration at least one dash is found, the return false.
 */
bool Board::is_full() const {
    for (int16_t i = 0; i < size; i++) {
        if (board[i] == '-') return false;
    }
    return true;
}


void Board::place_cell(int position, char playerID) {
    board[position] = playerID;
}

/*
 * the cell is not empty if it's not dash
 */
bool Board::cell_empty(int position) const {
    if (board[position] == '-') return true;
    return false;
}


/*
 * traverse through, check if the cell has a playerID in it, increment if yes.
 */
int16_t Board::owned_cell(char playerID) const {
    int16_t count = 0;
    for (int16_t i = 0; i < size; i++) {
        if (board[i] == playerID) {
            count++;
        }
    }
    return count;
}

Board::~Board() {
    delete[] board;
    board = nullptr;
    size = 0;
}


