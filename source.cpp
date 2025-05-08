#include <bits/stdc++.h>

#include <gl/glut.h>

#include "Controls.h"
#include "Display.h"
#include "Drawing.h"
#include "Reshape.h"
#include "Variables.h"

using namespace std;

void update(int value) {
    car_y -= 0.1f;

    // End the game
    if (totalMeter >= 4000) {
        terminate("YOU WON");
        return;
    }

    glutPostRedisplay();
    glutTimerFunc(105 - car_speed, update, 0);
}

void initRendering() {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Car Game");
    initRendering();

    sky_texture = loadTexture("sky.jpg");

    // Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardspecial);
    glutMouseFunc(mouseClick);

    glutFullScreen();
    glutMainLoop();
    return 0;
}