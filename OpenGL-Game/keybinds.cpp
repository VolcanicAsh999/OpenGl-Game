#include "OpenGL.h"
#include "rng.h"
#include "keybinds.h"
#include "render.h"
#include "playsound.h"

// Definitions
float angle=0.0;
float lx=0.f,lz=-1.f;
float x=0.f,z=5.f;
float deltaAngle=0.f;
float deltaMove=0.f;

float deltaMove2 = 0.f;
float lx2=0.f, lz2=-1.f;
//int xOrigin=-1;

float y = 2.f;
float yspeed = 0.0f;
float gravity = 0.0001f;
float jumpspeed = -0.05f;

bool mouseIsLocked = true;

bool mouseIsMoving = false;
int xOrigin = 320;
int yOrigin = 240;

float deltaAngle2 = 0.f;
float angle2 = 0.0;
float ly=0.f;

void mouseMove(int x, int y)
{
    /*if (xOrigin >= 0) {
        deltaAngle = (x - xOrigin) * 0.0005f;

        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
    }*/
    if (mouseIsLocked) {
        deltaAngle = (x - xOrigin) * 0.0005f; // Update the x rotation

        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);

        lx2 = sin(angle + deltaAngle + 90);
        lz2 = -cos(angle + deltaAngle + 90);

        if (!mouseIsMoving) {
            mouseIsMoving = true;
        }

        deltaAngle2 = (y - yOrigin) * 0.0005f; // Update the y rotation
        ly = -(angle2 + deltaAngle2);
    }
}

void mousePress(int button, int state, int x, int y)
{
    /*if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_UP) {
            angle += deltaAngle;
            xOrigin = -1;
        }
        else {
            xOrigin = x;
        }
        if (!mouseIsLocked)
        {
            mouseIsLocked = true;
            xOrigin = -1;
            glutSetCursor(GLUT_CURSOR_CROSSHAIR);
        }
    }*/
    if (!mouseIsLocked) // Lock the mouse when clicked and reset cursor to crosshair
    {
        mouseIsLocked = true;
        glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    }
}

void pressKey(unsigned char key, int xx, int yy)
{
    if (key == 'w') // Walk forwards
        deltaMove=0.5f;
    if (key == 's') // Walk backwards
        deltaMove = -0.5f;
    if (key == 'a') // Strafe left
        deltaMove2 = -0.5f;
    if (key == 'd') // Strafe right
        deltaMove2 = 0.5f;
    if (key == 27) // Unlock the mouse
    {
        mouseIsLocked = false;
        glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
    }
    if (key == ' ') { // Jump (if you are on the ground)
        if (playerIsTouching(x, y-.1, z))
            yspeed += jumpspeed;
    }
}

void releaseKey(unsigned char key, int xx, int yy)
{
    if (key == 'w' || key == 's') // Stop moving
        deltaMove = 0;
    if (key == 'a' || key == 'd') // Stop strafing
        deltaMove2 = 0;
}

void initKeys()
{
    glutKeyboardFunc(pressKey); // Register keys
    glutKeyboardUpFunc(releaseKey);
    //glutSpecialFunc(specialKey);
    //glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mouseMove); // Register mouse events
    glutMouseFunc(mousePress);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR); // Change the mouse image to a crosshair
}

void computePos(float deltaMove, float deltaMove2) {
    x += deltaMove * lx * 0.1f; // Forwards and backwards
    if (playerIsTouching(x, y, z)) { // Don't let us run into a wall, but...
        if (playerIsTouching(x, y+.1, z)) { // If it is a small slope, just go up the slope
            x -= deltaMove * lx * 0.1f;
        }
        else {
            y += .1;
        }
    }
    z += deltaMove * lz * 0.1f; // Forwards and backwards
    if (playerIsTouching(x, y, z)) { // Don't let us run into a wall, but...
        if (playerIsTouching(x, y+.1, z)) { // If it is a small slope, just go up the slope
            z -= deltaMove * lz * 0.1f;
        }
        else {
            y += .1;
        }
    }

    x += deltaMove2 * lx2 * 0.1f; // Strafe
    if (playerIsTouching(x, y, z)) { // Don't let us run into a wall, but...
        if (playerIsTouching(x, y+.1, z)) { // If it is a small slope, just go up the slope
            x -= deltaMove2 * lx2 * 0.1f;
        }
        else {
            y += .1;
        }
    }
    z += deltaMove2 * lz2 * 0.1f; // Strafe
    if (playerIsTouching(x, y, z)) { // Don't let us run into a wall, but...
        if (playerIsTouching(x, y+.1, z)) { // If it is a small slope, just go up the slope
            z -= deltaMove2 * lz2 * 0.1f;
        }
        else {
            y += .1;
        }
    }


    if (deltaMove != 0 || deltaMove2 != 0) {
        if (genRandNum(1, 50) == 1) {
            #ifdef USE_SOUND
            playStep();
            #endif // Play sounds if USE_SOUND is on and we are moving
        }
    }
}

void computeDir(float deltaAngle) {
    angle += deltaAngle; // Fix the angle
    lx = sin(angle); // Looking side to side
    lz = -cos(angle);

    lx2 = sin(angle + 90); // Looking side to side (to help with strafing)
    lz2 = -cos(angle + 90);
}

void computeDir2(float deltaAngle2) {
    angle2 += deltaAngle2; // Adjust the up-down angle
    ly = -angle2;
}

void computeY() {
    yspeed += gravity; // Gravity
    y -= yspeed;
    if (playerIsTouching(x, y, z)) { // If on the ground...
        y += yspeed;
        if (yspeed > 0.0f) // Reset speed so we don't fall through the floor
            yspeed = 0.0f;
    }
    if (playerIsTouching(x, y, z))
        y += 0.1;
    if (y < -30) { // Fell off, go back to beginning
        x = 0;
        y = 0;
        z = 0;
        yspeed = 0.0f; // Reset speed so we don't fall through the floor
    }
}

void updatePosDir()
{
    /*glLoadIdentity();
    glRotatef(ya, 1.0f, 0.0f, 0.0f);
    glRotatef(xa, 0.0f, 1.0f, 0.0f);

    computePos(speedx);

    //glTranslatef(-posx / 10.f, -1.0f, -posy / 10.f);

    //gluLookAt(posx, 1.0f, posy, posx, 1.0f, posy, 0.0f, 1.0f, 0.0f);

    gluLookAt(posx, 1.0f, posz,
              posx+lx, 1.0f, posz+lz,
              0.f, 1.f, 0.f);*/
    if (deltaMove || deltaMove2)
        computePos(deltaMove, deltaMove2);
    if (deltaAngle)
        computeDir(deltaAngle);
    if (deltaAngle2)
        computeDir2(deltaAngle2);

    if (mouseIsLocked) {
        xOrigin = glutGet(GLUT_WINDOW_WIDTH)/2;
        yOrigin = glutGet(GLUT_WINDOW_HEIGHT)/2;
        glutWarpPointer(xOrigin, yOrigin);
    }

    /*y -= yspeed;
    if (!playerIsTouching(x, -y + 1, z)) {
        yspeed += gravity;
    }
    else {
        y += yspeed;
        yspeed = 0.f;
    }*/
    /*//std::cout << yspeed;
    if (playerIsTouching(x, -y + 1, z) && yspeed > 0.f) {//if (collidey(-y + 1) && yspeed > 0.0) {
        y += yspeed;
        yspeed = 0.f;
    }*/
    computeY();

    if (mouseIsMoving)
        mouseIsMoving = false;
}

void fixPosDir()
{
    gluLookAt(x, y+5.5, z,
              x+lx, y+5.5+ly, z+lz,
              0.f, 1.f, 0.f);
}

void translateRight()
{
    glTranslatef(x, y, z);
}
