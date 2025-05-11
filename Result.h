#pragma once

#include <bits/stdc++.h>
#include <gl/glut.h>

#include "Reshape.h"
#include "keyboard_mouse_control.h"
#include "Variables.h"
using namespace std;

void myDisplayFunction(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 30, 100, 0, 0, 0, 0, 1, 0);

    glRotatef(-20, 1, 0, 0);
    glScalef(0.05, 0.05, 0.05);

    glPushMatrix();
    glTranslatef(-296, 200, 0);
    for (auto c : quote) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, c); // Font
    }
    glPopMatrix();

    glutSwapBuffers();
}

void terminate(string _quote) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
    glutCreateWindow(_quote.c_str());
    glLineWidth(3);
    quote = _quote;

    glutDisplayFunc(myDisplayFunction);
    glutReshapeFunc(reshape2);
    glutKeyboardFunc(keyboard);
    glutFullScreen();
    glutMainLoop();
}

void str_print(float x, float y, string st) {
    glRasterPos2f(x, y); // location to start printing text
    for (auto c : st) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}