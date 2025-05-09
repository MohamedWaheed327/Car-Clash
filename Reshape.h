#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

void reshape1(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void reshape2(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 3200);
    glMatrixMode(GL_MODELVIEW);
}
