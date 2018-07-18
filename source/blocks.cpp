#include <nds9.h>

#include "../include/blocks.h"

//textures
//#include "stone.h"
#include <cobblestone.h>
#include <dirt.h>

static int blocks[BLOCK_COUNT];

void initBlocks() {
    vramSetBankA(VRAM_A_TEXTURE);
    
    glGenTextures(BLOCK_COUNT, blocks);
    
    for (int i = 0; i < BLOCK_COUNT; i++)   {
        glBindTexture(0, blocks[i]);
        const unsigned int* bitmap;
        switch (i)  {
            case AIR:
                continue;
            case STONE:
                continue;
            case COBBLESTONE:
                bitmap = cobblestoneBitmap;
                break;
            default:
                bitmap = dirtBitmap;
                break;
        }
        glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD | GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T, (u8*) bitmap);
    }
}

void bindTex(int blockId)   {
        glBindTexture(0, blocks[blockId]);
}
