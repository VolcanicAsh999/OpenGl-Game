#include "OpenGL.h"
#include "render.h"
#include "keybinds.h"
#include "rng.h"
#include "playsound.h"
//#include "color.h"

void changeSize(int w, int h) {
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
        h = 1;
    float ratio = 1.0* w/h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45,ratio,1,1000);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

    // initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Space Game");
    glewInit();

    #ifdef USE_SOUND
    initAL();
    #endif // USE_SOUND
    //initColors();
    initRand();
    initD();
    initKeys();

    // register callbacks
    glutDisplayFunc(render);
    glutReshapeFunc(changeSize);
    glutIdleFunc(render);
    glutReshapeFunc(changeSize);

    glutMainLoop();

    #ifdef USE_SOUND
    quitAL();
    #endif // USE_SOUND

    return 0;
}
