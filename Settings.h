#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include <bits/stdc++.h>
#include <gl/glut.h>

#include "Display.h"
#include "Reshape.h"
#include "Time.h"
#include "Variables.h"
using namespace std;

bool GameScore() {
    if (0 > (car_y - obstacle_y) && -1 < (car_y - obstacle_y) && car_pos == 0) {
        score++;
    }
    else if (0 > (car_y - (obstacle_y - 10)) && -1 < (car_y - (obstacle_y - 10)) && car_pos == 1) {
        score++;
    }
    else if (0 > (car_y - (obstacle_y - 20)) && -1 < (car_y - (obstacle_y - 20)) && car_pos == 1) {

        score++;
    }
    else if (0 > (car_y - (obstacle_y - 30)) && -1 < (car_y - (obstacle_y - 30)) && car_pos == 0) {
        score += 1;
    }
    else if (0 > (car_y - (obstacle_y - 35)) && -1 < (car_y - (obstacle_y - 35)) && car_pos == 0) {
        score++;
        return true;
    }
    // else
    {
        totalMeter++;
        return false;
    }
    return true;
}

void terminate(string _quote) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
    glutCreateWindow(_quote.c_str());
    glLineWidth(3);
    quote = _quote;

    glutDisplayFunc(myDisplayFunction);
    glutReshapeFunc(reshape);
    glutMainLoop();
}

void sprint(float x, float y, string st) {
    glRasterPos2f(x, y); // location to start printing text
    for (int i = 0; i < st.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}