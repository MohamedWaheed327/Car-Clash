#pragma once
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

void RenderToDisplay() {
    glRotatef(-20, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.05, 0.05);

    int lenghOfQuote = quote.size();
    glPushMatrix();
    glTranslatef(-(lenghOfQuote * 37), 200, 0.0);
    for (int i = 0; i < lenghOfQuote; i++) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, quote[i]); // Font
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
