#ifndef BLOCKS_H
#define BLOCKS_H

void initBlocks();
void bindTex(int blockId);

#define BLOCK_COUNT 5

enum BLOCKS {
    AIR             = 0,
    STONE           = 1,
    COBBLESTONE     = 2,
    GRASS           = 3,
    DIRT            = 4
};

#endif /* BLOCKS_H */
