//
// Created by itagi on 4/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <cinttypes>


class Player {
private:
    char id;
    int8_t position;
    bool direction; // true: forward, false: backwards

public:
    Player();
    ~Player();

};



#endif //PLAYER_H
