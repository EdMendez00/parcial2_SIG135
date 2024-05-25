/* 
 * File:   parcial.c
 * Author: MM19247 - Mendez Martinez Eduardo Vladimir
 *
 * Created on 22 de mayo de 2024, 10:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <math.h>

void init(void) {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void dibujar(){
    
}

const char* get_carnet(void){
    return "mm19247";
}