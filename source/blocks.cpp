#include <nds9.h>

#include "../include/blocks.h"

//textures
#include <iron_ore.h>
#include <water.h>
#include <bedrock.h>
#include <bookshelf.h>
#include <brick.h>
#include <coal_block.h>
#include <coal_ore.h>
#include <cobblestone.h>
#include <cobblestone_mossy.h>
#include <diamond_block.h>
#include <diamond_ore.h>
#include <dirt.h>
#include <emerald_block.h>
#include <emerald_ore.h>
#include <glass.h>
#include <gold_block.h>
#include <gold_ore.h>
#include <grass_top.h>
#include <iron_block.h>
#include <wool_black.h>
#include <wool_blue.h>
#include <wool_brown.h>
#include <wool_cyan.h>
#include <wool_gray.h>
#include <wool_green.h>
#include <wool_light_blue.h>
#include <wool_lime.h>
#include <wool_magenta.h>
#include <wool_orange.h>
#include <wool_pink.h>
#include <wool_purple.h>
#include <wool_red.h>
#include <wool_silver.h>
#include <wool_white.h>
#include <wool_yellow.h>
#include <lapis_block.h>
#include <lapis_ore.h>
#include <lava.h>
#include <leaves.h>
#include <log.h>
#include <log_top.h>
#include <planks.h>
#include <redstone_block.h>
#include <redstone_ore.h>
#include <sand.h>
#include <sponge.h>
#include <sponge_wet.h>
#include <stone.h>
#include <stonebrick.h>
#include <stonebrick_mossy.h>

static int blocks[BLOCK_COUNT];

void initBlocks() {
    vramSetBankA(VRAM_A_TEXTURE);
    
    glGenTextures(BLOCK_COUNT, blocks);
    
    for (int i = 0; i < BLOCK_COUNT; i++)   {
        glBindTexture(0, blocks[i]);
        const unsigned int* bitmap;
        switch (i)  {
            case AIR: continue;
            case BEDROCK: bitmap = bedrockBitmap; break;
            case BRICK: bitmap = brickBitmap; break;
            case COAL_BLOCK: bitmap = coal_blockBitmap; break;
            case COAL_ORE: bitmap = coal_oreBitmap; break;
            case COBBLESTONE: bitmap = cobblestoneBitmap; break;
            case MOSS_COBBLESTONE: bitmap = cobblestone_mossyBitmap; break;
            case DIAMOND_BLOCK: bitmap = diamond_blockBitmap; break;
            case DIAMOND_ORE: bitmap = diamond_oreBitmap; break;
            case DIRT: bitmap = dirtBitmap; break;
            case EMERALD_BLOCK: bitmap = emerald_blockBitmap; break;
            case EMERALD_ORE: bitmap = emerald_oreBitmap; break;
            case GLASS: bitmap = glassBitmap; break;
            case GOLD_BLOCK: bitmap = gold_blockBitmap; break;
            case GOLD_ORE: bitmap = gold_oreBitmap; break;
            case GRASS: bitmap = grass_topBitmap; break;
            case IRON_BLOCK: bitmap = iron_blockBitmap; break;
            case IRON_ORE: bitmap = iron_oreBitmap; break;
            case LAPIS_BLOCK: bitmap = lapis_blockBitmap; break;
            case LAPIS_ORE: bitmap = lapis_oreBitmap; break;
            case LAVA: bitmap = lavaBitmap; break;
            case LEAVES: bitmap = leavesBitmap; break;
            case LOG: bitmap = logBitmap; break;
            case PLANKS: bitmap = planksBitmap; break;
            case REDSTONE_BLOCK: bitmap = redstone_blockBitmap; break;
            case REDSTONE_ORE: bitmap = redstone_oreBitmap; break;
            case SAND: bitmap = sandBitmap; break;
            case SPONGE: bitmap = spongeBitmap; break;
            case SPONGE_WET: bitmap = sponge_wetBitmap; break;
            case STONE: bitmap = stoneBitmap; break;
            case STONEBRICK: bitmap = stonebrickBitmap; break;
            case MOSS_STONEBRICK: bitmap = stonebrick_mossyBitmap; break;
            case WATER: bitmap = waterBitmap; break;
            case WOOL_BLACK: bitmap = wool_blackBitmap; break;
            case WOOL_BLUE: bitmap = wool_blueBitmap; break;
            case WOOL_BROWN: bitmap = wool_brownBitmap; break;
            case WOOL_CYAN: bitmap = wool_cyanBitmap; break;
            case WOOL_GRAY: bitmap = wool_grayBitmap; break;
            case WOOL_GREEN: bitmap = wool_greenBitmap; break;
            case WOOL_LIGHTBLUE: bitmap = wool_light_blueBitmap; break;
            case WOOL_LIME: bitmap = wool_limeBitmap; break;
            case WOOL_MAGENTA: bitmap = wool_magentaBitmap; break;
            case WOOL_ORANGE: bitmap = wool_orangeBitmap; break;
            case WOOL_PINK: bitmap = wool_pinkBitmap; break;
            case WOOL_PURPLE: bitmap = wool_purpleBitmap; break;
            case WOOL_RED: bitmap = wool_redBitmap; break;
            case WOOL_SILVER: bitmap = wool_silverBitmap; break;
            case WOOL_WHITE: bitmap = wool_whiteBitmap; break;
            case WOOL_YELLOW: bitmap = wool_yellowBitmap; break;
        }
        glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD | GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T, (u8*) bitmap);
    }
}

void bindTex(int blockId)   {
        glBindTexture(0, blocks[blockId]);
}
