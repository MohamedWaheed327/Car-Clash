#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

// Function to handle mouse click events
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Left mouse click, decrease speed
        if (car_speed < 100) {
            car_speed += 5;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Right mouse click, increase speed
        if (car_speed > 40) {
            car_speed -= 5;
        }
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
#define ESC 27
    if (key == ESC) {
        exit(0);
    }
#undef ESC
}

void keyboardspecial(int key, int x, int y) {
    switch (key) {

    case GLUT_KEY_RIGHT:
        xp = .55;
        car_pos = 1;
        break;

    case GLUT_KEY_LEFT:
        xp = -.55;
        car_pos = 0;
        break;

    case GLUT_KEY_UP:
        if (car_speed <= 95) {
            car_speed += 5;
        }
        break;

    case GLUT_KEY_DOWN:
        if (car_speed >= 45) {
            car_speed -= 5;
        }
        break;

    default:
        break;
    }
}
