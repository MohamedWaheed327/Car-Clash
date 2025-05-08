#pragma once
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

void setupLighting() {
    float myLightPosition[4] = {3.0, 6.0f, 5.0f, 1.0};
    // float myLightPosition[4] = {car_x, -1.0+7, 3.5, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
}
