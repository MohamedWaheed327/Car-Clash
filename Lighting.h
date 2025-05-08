#pragma once
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/gl.h>
#include <gl/glut.h>

void setupLighting() {
    float myLightPosition[4] = {3.0, 6.0, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
}
