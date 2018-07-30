#include <nds9.h>

#include "../include/render.h"
#include "../include/blocks.h"

void renderBlock(int id, int x, int y, int z) {
    switch (id) {
        case AIR:
            return;
        default:
            bindTex(id);
            renderQuad(0, 0, 0, 16);
    }
}

void renderQuad(int x, int y, int z, int texW) {
    glBegin(GL_QUAD);
    glNormal(NORMAL_PACK(0, inttov10(-1), 0));
    
    t16 max = inttot16(texW);

    GFX_TEX_COORD = TEXTURE_PACK(0, max);
    glVertex3v16(0, 0, 1);
    GFX_TEX_COORD = TEXTURE_PACK(max, max);
    glVertex3v16(1, 0, 1);
    GFX_TEX_COORD = TEXTURE_PACK(max, 0);
    glVertex3v16(1, 1, 1);
    GFX_TEX_COORD = TEXTURE_PACK(0, 0);
    glVertex3v16(0, 1, 1);

    glEnd();
}
