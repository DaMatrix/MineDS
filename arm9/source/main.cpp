#include <nds9.h>
#include <stdio.h>
#include <porkmath.h>

static const int blockBits = 6;
static const int blockMask = (1 << blockBits) - 1;
static const int blockCount = 1 << blockBits;

volatile float x = 0.0;
volatile float y = 1.0;
volatile float z = 0.0;
volatile float rotateX = 0.0;
int textures[blockCount];

int main(void) {

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

    //any floating point gl call is being converted to fixed prior to being implemented
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 256.0 / 192.0, 0.1, 40);

    while (1) {
        glPushMatrix();

        //move it away from the camera
        //glTranslatef32(0, 0, floattof32(-1));

        //glRotateX(rotateX);
        //glRotateY(rotateY);

        gluLookAt(x, y, z, //camera position
                x + 1, y, z, //look at
                0.0, 1.0, 0.0); //up
        
        glRotateZ(sinF(rotateX * 3.0) * 10.0);
        glRotateY(rotateX);

        glMatrixMode(GL_MODELVIEW);

        //not a real gl function and will likely change
        glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);

        rotateX += 0.5;

        for (int x = -5; x < 5; x++) {
            for (int z = -5; z < 5; z++) {
                //draw the obj
                glBegin(GL_QUAD);

                glColor3b(255, 0, 0);
                glVertex3v16(inttov16(x), 0, inttov16(z));

                glColor3b(0, 255, 0);
                glVertex3v16(inttov16(x + 1), 0, inttov16(z));

                glColor3b(0, 0, 255);
                glVertex3v16(inttov16(x + 1), 0, inttov16(z + 1));

                glColor3b(255, 0, 255);
                glVertex3v16(inttov16(x), 0, inttov16(z + 1));
            }
        }

        glEnd();

        glPopMatrix(1);

        glFlush(0);

        swiWaitForVBlank();
    }

    return 0;
}
