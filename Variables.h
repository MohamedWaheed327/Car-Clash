#pragma once
#include <bits/stdc++.h>
using namespace std;

float car_x = -.55, car_y = 4;
int car_pos = 0;
int car_speed = 45;

struct AABB {
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
};

GLuint sky_texture;

float obstacle_y = -3.3;

int /*score = 0,*/ totalMeter = 0;
string quote;
