#pragma once
#include <bits/stdc++.h>
using namespace std;

float car_x = -.55, car_y = 4;
int car_speed = 45;

struct AABB {
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
};

GLuint sky_texture;

int totalMeter = 0;
string quote;
