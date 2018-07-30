#ifndef PLAYER_H
#define PLAYER_H

#include "../blocks.h"

class Player    {
public:
    volatile int x;
    volatile int y;
    volatile int z;
    
    volatile int inHand;
};

#endif /* PLAYER_H */

