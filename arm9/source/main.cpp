#include <nds9.h>
#include <stdio.h>
#include <porkmath.h>

//textures
#include <diamond_ore.h>

static const int blockBits = 6;
static const int blockMask = (1 << blockBits) - 1;
static const int blockCount = 1 << blockBits;
//static int textures[blockCount];
static int texture;

volatile float x = 0.0;
volatile float y = 1.0;
volatile float z = 0.0;
volatile float rotateX = 0.0;

int main(void) {
    int textureID;

    consoleDemoInit();

    //set mode 0, enable BG0 and set it to 3D
    videoSetMode(MODE_0_3D);

    // initialize gl
    glInit();

    // enable antialiasing
    glEnable(GL_ANTIALIAS);

    // setup the rear plane
    glClearColor(0, 0, 0, 31); // BG must be opaque for AA to work
    glClearPolyID(63); // BG must have a unique polygon ID for AA to work
    glClearDepth(0x7FFF);

    //this should work the same as the normal gl call
    glViewport(0, 0, 255, 191);

    {
        iprintf("Loading textures...\n");
        swiWaitForVBlank();
        //init textures
        //TODO: useful code here
        
        //why not just set all the banks by default?
        //man i need to learn what the heck i'm doing
        vramSetBankA(VRAM_A_TEXTURE);
	//vramSetBankB(VRAM_B_TEXTURE);
	//vramSetBankC(VRAM_C_TEXTURE);
	//vramSetBankD(VRAM_D_TEXTURE);
	//vramSetBankE(VRAM_E_TEX_PALETTE);
	//vramSetBankF(VRAM_F_TEX_PALETTE_SLOT0);
	//vramSetBankG(VRAM_G_TEX_PALETTE_SLOT5);
        iprintf("Loading textures...\n");
        swiWaitForVBlank();
        glGenTextures(1, &textureID);
        glBindTexture(0, textureID);
        iprintf("Generating textures...\n");
        swiWaitForVBlank();
        glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, (u8*) diamond_oreBitmap);
        iprintf("Done!\n");
        swiWaitForVBlank();
    }

    //any floating point gl call is being converted to fixed prior to being implemented
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 256.0 / 192.0, 0.1, 40);

    while (1) {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        gluLookAt(x, cosF(rotateX), z, //camera position
                x + 1, cosF(rotateX), z, //look at
                0.0, 1.0, 0.0); //up

        //glRotateZ(sinF(rotateX) * 10.0);
        glRotateY(rotateX);

        //glMaterialf(GL_AMBIENT, RGB15(16, 16, 16));
        //glMaterialf(GL_DIFFUSE, RGB15(16, 16, 16));
        //glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8, 8, 8));
        glMaterialf(GL_EMISSION, RGB15(16, 16, 16));

        glMaterialShinyness();

        //not a real gl function and will likely change
        glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);

        rotateX += 0.5;

        for (int x = -5; x < 5; x++) {
            for (int z = -5; z < 5; z++) {
                glBindTexture(0, textureID);
                //draw the obj
                glBegin(GL_QUAD);
                glNormal(NORMAL_PACK(0, inttov10(-1), 0));

                GFX_TEX_COORD = (TEXTURE_PACK(0, inttot16(16)));
                glVertex3v16(inttov16(x), 0, inttov16(z));

                GFX_TEX_COORD = (TEXTURE_PACK(inttot16(16), inttot16(16)));
                glVertex3v16(inttov16(x + 1), 0, inttov16(z));

                GFX_TEX_COORD = (TEXTURE_PACK(inttot16(16), 0));
                glVertex3v16(inttov16(x + 1), 0, inttov16(z + 1));

                GFX_TEX_COORD = (TEXTURE_PACK(0, 0));
                glVertex3v16(inttov16(x), 0, inttov16(z + 1));

                glEnd();
            }
        }

        glPopMatrix(1);

        glFlush(0);

        swiWaitForVBlank();
    }

    return 0;
}
