#pragma once
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/gl.h>
#include <gl/glut.h>

void setupLighting() {
    float myLightPosition[4] = {3.0, 6.0, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
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