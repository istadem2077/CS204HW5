//
// Created by Ismayil Taghi-Zada on 4/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <cinttypes>
#include "board.h"
#define FORWARD true
#define BACKWARDS false


class Player {
private:
    char playerID;
    int16_t position;
    bool direction = FORWARD; // true: forward, false: backwards
    Board& board;
public:
    Player(Board& board,char playerID, int16_t position) : playerID(playerID), position(position), board(board) {}


    void move(int16_t steps);
    void claim_ownership();
    int16_t count_own_cells() const;
    int16_t get_position() const {
        return position;
    }
};



#endif //PLAYER_H
