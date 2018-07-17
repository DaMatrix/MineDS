#include <nds9.h>
#include <stdio.h>

volatile float x = 0.0;
volatile float y = 0.0;
volatile float z = 0.0;
volatile s16 rotateX = 0;

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

    gluLookAt(0.0, 0.0, 1.0, //camera position
            0.0, 0.0, 0.0, //look at
            0.0, 1.0, 0.0); //up

    while (1) {
        glPushMatrix();

        //move it away from the camera
        glTranslatef32(0, 0, floattof32(-1));

        //glRotateX(rotateX);
        //glRotateY(rotateY);

        gluLookAt(0.0, 0.0, 1.0, //camera position
                angleToDegrees(sinLerp(degreesToAngle(rotateX))) * 0.05, 0.0, 0.0, //look at
                0.0, 1.0, 0.0); //up

        glMatrixMode(GL_MODELVIEW);

        //not a real gl function and will likely change
        glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);

        rotateX += 1;

        {
            //draw the obj
            glBegin(GL_QUAD);

            glColor3b(255, 0, 0);
            glVertex3v16(inttov16(-1), inttov16(-1), 0);

            glColor3b(0, 255, 0);
            glVertex3v16(inttov16(1), inttov16(-1), 0);

            glColor3b(0, 0, 255);
            glVertex3v16(inttov16(1), inttov16(1), 0);

            glColor3b(255, 0, 255);
            glVertex3v16(inttov16(-1), inttov16(1), 0);
        }

        glEnd();

        glPopMatrix(1);

        glFlush(0);

        swiWaitForVBlank();
    }

    return 0;
}
