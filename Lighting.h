#pragma once
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

void setupLighting() {
    GLfloat light_pos[] = {0, 6.0, -car_y + 15, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}