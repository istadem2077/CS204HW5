//
// Created by Ismayil Taghi-Zada on 4/26/2025.
//

#include "player.h"

void Player::claim_ownership() {
    if (board.cell_empty(position)) { // check for the vacancy of the cell
        board.place_cell(position, playerID);
    }
}

int16_t Player::count_own_cells() const {
    return board.owned_cell(playerID);
}


void Player::move(int16_t steps) {
    for (int16_t i = 0; i < steps; i++) {
        /*
         * With each move check for the change of direction
         * if direction is forward, rotate back if the position is the last on the board
         * if direction is backwards, rotate if the position is the first on the board (0)
         */
        if (direction == FORWARD) {
            if (position == board.getSize()-1) {
                direction = BACKWARDS;
            }
        }
        if (direction == BACKWARDS) {
            if (position == 0) {
                direction = FORWARD;
            }
        }

        /*
         * increase the position moving forward, decrease if backwards
         */
        if (direction == FORWARD) {
            position++;
        }
        else if (direction == BACKWARDS) { position--; }
    }
}

