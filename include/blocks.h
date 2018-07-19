#ifndef BLOCKS_H
#define BLOCKS_H

void initBlocks();
void bindTex(int blockId);

#define BLOCK_COUNT 49

enum BLOCKS {
    AIR             = 0,
    BEDROCK         = 1,
    BRICK           = 2,
    COAL_BLOCK      = 3,
    COAL_ORE        = 4,
    COBBLESTONE     = 5,
    MOSS_COBBLESTONE= 6,
    DIAMOND_BLOCK   = 7,
    DIAMOND_ORE     = 8,
    DIRT            = 9,
    EMERALD_BLOCK   = 10,
    EMERALD_ORE     = 11,
    GLASS           = 12,
    GOLD_BLOCK      = 13,
    GOLD_ORE        = 14,
    GRASS           = 15,
    IRON_BLOCK      = 16,
    IRON_ORE        = 17,
    LAPIS_BLOCK     = 18,
    LAPIS_ORE       = 19,
    LAVA            = 20,
    LEAVES          = 21,
    LOG             = 22,
    PLANKS          = 23,
    REDSTONE_BLOCK  = 24,
    REDSTONE_ORE    = 25,
    SAND            = 26,
    SPONGE          = 27,
    SPONGE_WET      = 28,
    STONE           = 29,
    STONEBRICK      = 30,
    MOSS_STONEBRICK = 31,
    WATER           = 32,
    WOOL_BLACK      = 33,
    WOOL_BLUE       = 34,
    WOOL_BROWN      = 35,
    WOOL_CYAN       = 36,
    WOOL_GRAY       = 37,
    WOOL_GREEN      = 38,
    WOOL_LIGHTBLUE  = 39,
    WOOL_LIME       = 40,
    WOOL_MAGENTA    = 41,
    WOOL_ORANGE     = 42,
    WOOL_PINK       = 43,
    WOOL_PURPLE    = 44,
    WOOL_RED        = 45,
    WOOL_SILVER     = 46,
    WOOL_WHITE      = 47,
    WOOL_YELLOW     = 48
};

#endif /* BLOCKS_H */
