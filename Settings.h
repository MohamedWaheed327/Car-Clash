#pragma once

#include <bits/stdc++.h>
#include <gl/glut.h>

#include "Display.h"
#include "Reshape.h"
#include "Variables.h"
using namespace std;

// void GameScore() {
//     if (0 > (car_y - obstacle_y) && -1 < (car_y - obstacle_y) && car_pos == 0) // right collision
//     {
//         score++;
//     }

//     if (0 > (car_y - (obstacle_y - 10)) && -1 < (car_y - (obstacle_y - 10)) && car_pos == 1) // left collision
//     {
//         score++;
//     }

//     if (0 > (car_y - (obstacle_y - 20)) && -1 < (car_y - (obstacle_y - 20)) && car_pos == 1) // left collision
//     {
//         score++;
//     }

//     if (0 > (car_y - (obstacle_y - 30)) && -1 < (car_y - (obstacle_y - 30)) && car_pos == 0) // right collision
//     {
//         score+=10;
//     }

//     totalMeter++;
// }

void terminate(string _quote) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 500);
    glutCreateWindow(_quote.c_str());
    glLineWidth(3);
    quote = _quote;

    glutDisplayFunc(myDisplayFunction);
    glutReshapeFunc(reshape);
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