#pragma once

#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>

AABB getCarAABB() {
    float centerX = car_x;
    float centerY = -1.0;
    float centerZ = -0.1;

    float halfX = 0.195f;
    float halfY = 0.12f;
    float halfZ = 0.3f * 100;

    AABB box;
    box.minX = centerX - halfX;
    box.maxX = centerX + halfX;
    box.minY = centerY - halfY;
    box.maxY = centerY + halfY;
    box.minZ = centerZ - halfZ;
    box.maxZ = centerZ + halfZ;
    return box;
}

AABB getCubeAABB(float x, float y, float z) {
    float half = 0.2f;
    AABB box;
    box.minX = x - half;
    box.maxX = x + half;
    box.minY = y - half + 2.3;
    box.maxY = y + 10*half+2.5;
    box.minZ = z - 10 * half;
    box.maxZ = z + 10 * half;
    return box;
}

bool intersectAABB(const AABB &a, const AABB &b) {
    return (a.minX <= b.maxX && a.maxX >= b.minX) &&
           (a.minY <= b.maxY && a.maxY >= b.minY) &&
           (a.minZ <= b.maxZ && a.maxZ >= b.minZ);
}

bool collision() {
    AABB carBox = getCarAABB();
    for (float y = -20; y < 400; y += 40) {
        vector<pair<float, float>> cubes = {
            {-0.50f, y},
            {+0.50f, y + 10},
            {+0.50f, y + 20},
            {-0.50f, y + 30}};
        for (auto &pos : cubes) {
            AABB box = getCubeAABB(pos.first, pos.second + car_y, -0.1f); // <--- ADD car_y
            if (intersectAABB(carBox, box)) return true;
        }
    }
    return false;
}
