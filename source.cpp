#include <bits/stdc++.h>

#include <gl/glut.h>

#include "Display.h"
#include "Reshape.h"
#include "Variables.h"
#include "keyboard_mouse_control.h"

using namespace std;

void update(int value) {
    car_y -= 0.1;

    // End the game
    if (totalMeter >= 4000) {
        terminate("YOU WON");
        return;
    }

    glutPostRedisplay();
    glutTimerFunc(105 - car_speed, update, 0);
}

void init() {
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Car Game");
    init();

    sky_texture = loadTexture("sky.jpg");

    // Set handler functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape1);
    glutTimerFunc(25, update, 0);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardspecial);
    glutMouseFunc(mouseClick);

    glutFullScreen();
    glutMainLoop();
    return 0;
}