#pragma once

#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

void RenderToDisplay() {
    glRotatef(-20, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.05, 0.05);

    glPushMatrix();
    glTranslatef(-296, 200, 0.0);
    for (auto c : quote) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, c); // Font
    }
    glPopMatrix();
}

void myDisplayFunction(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    RenderToDisplay();
    glutSwapBuffers();
}
