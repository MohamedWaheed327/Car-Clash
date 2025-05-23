#pragma once

#include "Collision.h"
#include "Lighting.h"
#include "Result.h"
#include "Variables.h"
#include <bits/stdc++.h>
#include <gl/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;

GLuint loadTexture(const char *filename) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set wrapping/filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLenum format = GL_RGB;
    if (nrChannels == 4)
        format = GL_RGBA;

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
    return textureID;
}

void car() {
    glPushMatrix();
    glTranslatef(car_x, -1.0, 3.5);

    glPushMatrix();
    glRotatef(-10, -1.0, 0.0, 0.0);
    glScalef(1.3, 0.8, 2.0);
    glColor3f(0, 0.5, 1);
    glutSolidCube(.3); // car's body
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.15, 0.0);
    glRotatef(-10, -1.0, 0.0, 0.0);
    glScalef(1.0, .5, .5);
    glColor3f(0, 0, 0); // car's roof
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.21, -0.12, 0.10);
    glRotatef(80, 0.0, 1.2, 0.0);
    glScalef(.07, .14, .07);
    glColor3f(1, 0, 0);
    glutWireTorus(.2, .4, 20, 15); // lower right wheel
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.21, 0.0, -0.2);
    glRotatef(80, 0.0, 1.2, 0.0);
    glScalef(.07, .14, .07);
    glColor3f(1, 0, 0);
    glutWireTorus(.2, .4, 20, 15); // upper right wheel
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.21, -0.12, 0.10);
    glRotatef(80, 0.0, 1.2, 0.0);
    glScalef(.07, .14, .07);
    glColor3f(1, 0, 0);
    glutWireTorus(.2, .4, 20, 15); // lower left wheel
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.21, 0.0, -0.2);
    glRotatef(80, 0.0, 1.2, 0.0);
    glScalef(.07, .14, .07);
    glColor3f(1, 0, 0);
    glutWireTorus(.2, .4, 20, 15); // upper left wheel
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.10, -0.10, 0.30); // left backlight
    glRotatef(80, 0.0, 1.2, 0.0);
    glScalef(.07, .03, .07);
    glColor3f(1, .5, 0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.10, -0.10, 0.30); // right backlight
    glRotatef(80, 0.0, 1.2, 0.0);
    glScalef(.07, .03, .07);
    glColor3f(1, .5, 0);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
}

void sky() {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sky_texture);
    glColor3ub(255, 255, 255); // white

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-12.0 - 10, 2.0, -8.0); // Bottom left
    glTexCoord2f(1, 0);
    glVertex3f(12.0 + 10, 2.0, -8.0); // Bottom right
    glTexCoord2f(0, 1);
    glVertex3f(10.0 + 10, 4.0, 8.0); // Top right
    glTexCoord2f(1, 1);
    glVertex3f(-10.0 - 10, 4.0, 8.0); // Top left
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void roadside() {
    // light pool
    for (float y = -38 - 40; y < 400; y += 4) {
        glPushMatrix();
        glColor3ub(200, 200, 200);
        glTranslatef(-1.20, y, .40 + 0.07);
        glScalef(.2, .2, 3);
        glutSolidCube(.4); // vertical
        glPopMatrix();

        glPushMatrix();
        glColor3ub(200, 200, 200);
        glTranslatef(-.84, y, 1.0 + 0.07);
        glScalef(2, .2, .2);
        glutSolidCube(.4); // horizontal
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255, 255, 255);
        glTranslatef(-.44, y, 0.70 + 0.07);
        glutSolidCone(.2, .3, 15, 20); // light cone
        glPopMatrix();
    }

    // Widened road sides
    glBegin(GL_QUADS);
    glColor3ub(0, 155, 20); // left side road
    glVertex3f(-100.0, -10 - 10, 0);
    glVertex3f(-1.0, -10 - 10, 0);
    glVertex3f(-1.0, 400, 0);
    glVertex3f(-100.0, 400, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 155, 20); // right side road
    glVertex3f(1.0, -10 - 10, 0);
    glVertex3f(100.0, -10 - 10, 0);
    glVertex3f(100.0, 400, 0);
    glVertex3f(1.0, 400, 0);
    glEnd();
}

void cube() {
    // draw cubes with pattern -> R L L R
    for (float y = -20; y < 400; y += 40) {
        glPushMatrix();
        glColor3f(0, 0.5, 0);
        glTranslatef(-.50, y, -.1);
        glutSolidCube(.4);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0.5, 0);
        glTranslatef(.50, y + 10, -.1);
        glutSolidCube(.4);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0.5, 0);
        glTranslatef(.50, y + 20, -.1);
        glutSolidCube(.4);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0.5, 0);
        glTranslatef(-.50, y + 30, -.1);
        glutSolidCube(.4);
        glPopMatrix();
    }
}

void road() {
    for (float y = -100; y < 400; y += 1) {
        glPushMatrix();
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
            glVertex3f(-.03, y, 0);
            glVertex3f(.03, y, 0);
            glVertex3f(.03, y + .5, 0);
            glVertex3f(-.03, y + .5, 0);
        glEnd();
        glPopMatrix();
    }

    glPushMatrix();

    glColor3ub(0, 0, 0);

    glTranslatef(0.0, 0.0, -.50);
    glBegin(GL_QUADS);
    glVertex3f(-1.3, -10, 0);
    glVertex3f(1.3, -10, 0);
    glVertex3f(1.3, 400, 0);
    glVertex3f(-1.3, 400, 0);
    glEnd();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // glPushMatrix();

    // glTranslatef(0, -1, -5);
    // glColor3f(1.0, 0.0, 0.0); // Red color
    // glutSolidSphere(0.5, 50, 50);

    // glPopMatrix();
    float add = 0.9;
    gluLookAt(0, -1 + add, 3.501 - 0.50,
              0, -1 + add, 3.5 - 0.50,
              0, 1, 0);

    glRotatef(0, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -7.0);
    glColor3f(0.0, 0.0, 0.3);

    setupLighting();
    sky();
    car();

    glPushMatrix();
    glRotatef(80, -1.0, 0.0, 0.0);

    glPushMatrix();
        glTranslatef(0.0, car_y, 0.0);
        road();
        roadside();
        cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5, 0.0, 1.8);
    str_print(-4, -2.4, "Distance Travel: " + to_string(totalMeter));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5, 0.0, 1.6);
    str_print(-4, -2.4, "Speed: " + to_string(car_speed));
    glPopMatrix();

    glPopMatrix();

    totalMeter++;
    if (collision()) {
        terminate("GAME OVER");
    }

    glutSwapBuffers();
}