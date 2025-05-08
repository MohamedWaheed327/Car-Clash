#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include "Variables.h"
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // reset the current matrix to the identity matrix

    gluPerspective(60, 1.0, 1.0, 3200);

    glMatrixMode(GL_MODELVIEW);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}