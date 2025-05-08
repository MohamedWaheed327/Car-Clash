#pragma once
#include "Settings.h"
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

bool collision() {
    if (0 > (car_y - obstacle_y) && -1 < (car_y - obstacle_y) && car_pos == 1) // right collision
    {
        return true;
    }
    
    if (0 > (car_y - (obstacle_y - 10)) && -1 < (car_y - (obstacle_y - 10)) && car_pos == 0) // left collision
    {
        return true;
    }
    
    if (0 > (car_y - (obstacle_y - 20)) && -1 < (car_y - (obstacle_y - 20)) && car_pos == 0) // left collision
    {
        return true;
    }
    
    if (0 > (car_y - (obstacle_y - 30)) && -1 < (car_y - (obstacle_y - 30)) && car_pos == 1) // right collision
    {
        return true;
    }
    
    if (0 > (car_y - (obstacle_y - 30)) && -1 < (car_y - (obstacle_y - 30))) {
        obstacle_y -= 40;
    }

    return false;
}