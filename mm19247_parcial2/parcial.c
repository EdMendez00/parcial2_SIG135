/* 
 * File:   parcial.c
 * Author: MM19247 - Mendez Martinez Eduardo Vladimir
 *
 * Created on 22 de mayo de 2024, 10:55
 */
#include "./init.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <math.h>

void ecuacionGeneral(int x0, int y0, int x1, int y1);

void init(void) {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 700, 700, 0);
}

void dibujar_usoMultiples(){
    glClear(GL_COLOR_BUFFER_BIT);
    

    
    glFlush();
}

const char* get_carnet(void){
    return "mm19247";
}

void ecuacionGeneral(int x0, int y0, int x1, int y1) {
    float m = (float)(y1 - y0) / (x1 - x0);
    float b = y0 - m * x0;
    
    glColor3f(1, 1, 1);
    glPointSize(3);
    glBegin(GL_POINTS);
    
    if (m > 0) {
        //Pendiente Positiva
        for (int x = x0; x <= x1; x++) {
            float y = m * x + b;
            glVertex2f(x, round(y));
        }
    } else if (m < 0) {
        //Pendiente Negativa
        for (int y = y0; y >= y1; y--) {
            float x = (y - b) / m;
            glVertex2f(round(x), y);
        }
    } 
    if (x0 == x1) {
        for (int y = y0; y <= y1; y++) {
            glVertex2f(x0, y);
        }
    } else if (y0 == y1) {
        for (int x = x0; x <= x1; x++) {
            glVertex2f(x, y0);
        }
    }
    glEnd();
}