#include <nds9.h>
#include <stdlib.h>
#include <stdio.h>

//own classes
#include "../include/util/porkmath.h"

//textures
#include <diamond_ore.h>

volatile float pitch = 0.0;
volatile float yaw = 0.0;

int main() {
    int textureID;

    //set mode 0, enable BG0 and set it to 3D
    videoSetMode(MODE_0_3D);

    // initialize gl
    glInit();

    //enable textures
    glEnable(GL_TEXTURE_2D);

    // enable antialiasing
    glEnable(GL_ANTIALIAS);

    // setup the rear plane
    glClearColor(0, 0, 0, 31); // BG must be opaque for AA to work
    glClearPolyID(63); // BG must have a unique polygon ID for AA to work
    glClearDepth(0x7FFF);

    //this should work the same as the normal gl call
    glViewport(0, 0, 255, 191);

    vramSetBankA(VRAM_A_TEXTURE);

    glGenTextures(1, &textureID);
    glBindTexture(0, textureID);
    glTexImage2D(0, 0, GL_RGBA, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD | GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T, (u8*) diamond_oreBitmap);

    //any floating point gl call is being converted to fixed prior to being implemented
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 256.0 / 192.0, 0.1, 40);

    while (1) {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        gluLookAt(0.0, 0.0, 0.0, //camera position 
                1.0, 0.0, 0.0, //look at
                0.0, 1.0, 0.0); //up
        glRotateZ(-pitch);
        glRotateY(-yaw);

        glMaterialf(GL_AMBIENT, RGB15(16, 16, 16));
        glMaterialf(GL_DIFFUSE, RGB15(16, 16, 16));
        glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8, 8, 8));
        glMaterialf(GL_EMISSION, RGB15(16, 16, 16));

        glMaterialShinyness();
        glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK);

        scanKeys();

        u16 keys = keysHeld();

        if ((keys & KEY_UP)) pitch += 3;
        if ((keys & KEY_DOWN)) pitch -= 3;
        if ((keys & KEY_LEFT)) yaw += 3;
        if ((keys & KEY_RIGHT)) yaw -= 3;

        glBindTexture(0, textureID);

        //draw the obj
        glBegin(GL_QUAD);
        glNormal(NORMAL_PACK(0, inttov10(-1), 0));

        GFX_TEX_COORD = (TEXTURE_PACK(inttot16(0), inttot16(32)));
        glVertex3v16(floattov16(-0.5), floattov16(-0.5), floattov16(-0.5));
        GFX_TEX_COORD = (TEXTURE_PACK(inttot16(32), inttot16(32)));
        glVertex3v16(floattov16(0.5), floattov16(-0.5), floattov16(-0.5));
        GFX_TEX_COORD = (TEXTURE_PACK(inttot16(32), inttot16(0)));
        glVertex3v16(floattov16(0.5), floattov16(0.5), floattov16(-0.5));
        GFX_TEX_COORD = (TEXTURE_PACK(inttot16(0), inttot16(0)));
        glVertex3v16(floattov16(-0.5), floattov16(0.5), floattov16(-0.5));

        glEnd();

        glPopMatrix(1);

        glFlush(0);

        swiWaitForVBlank();

        if (keys & KEY_START) break;
    }

    return 0;
}//end main 
