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

void ecuacionGeneral(int , int , int , int);
void relleno(int , int , float *, float *);

void init(void) {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 700, 700, 0);
}

void dibujar_usoMultiples(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    ecuacionGeneral(350, 232, 380, 232);
    ecuacionGeneral(380, 232, 380, 365);
    ecuacionGeneral(350, 232, 350, 365);
    ecuacionGeneral(350, 365, 380, 365);
    //Rellenar 
    float color[4] = {0.0, 1.0, 1.0, 1.0}; //celeste
    float nuevoColor[4] = {1.0, 1.0, 1.0, 1.0}; // Blanco
    relleno(360, 240, color, nuevoColor);
    
    glFlush();
}

const char* get_carnet(void){
    return "mm19247";
}

//Ecuacion General de la Linea Recta
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

//Relleno por Inundacion
void relleno(int x, int y, float interiorColor[4], float fillColor[4]) {
    float color[4];
    // Obtener el color del píxel actual
    glReadPixels(x, y, 1, 1, GL_RGBA, GL_FLOAT, color);

    // Imprimir el color del píxel actual
    printf("Color del pixel en (%d, %d): (%f, %f, %f, %f)\n", x, y, color[0], color[1], color[2], color[3]);
    printf("ColorInterior en (%d, %d): (%f, %f, %f, %f)\n", x, y, interiorColor[0], interiorColor[1], interiorColor[2], interiorColor[3]);


    float tolerance = 0.01; // Tolerancia para la comparación de colores
    if (fabs(color[0] - interiorColor[0]) < tolerance &&
        fabs(color[1] - interiorColor[1]) < tolerance &&
        fabs(color[2] - interiorColor[2]) < tolerance &&
        fabs(color[3] - interiorColor[3]) < tolerance) {
        
        printf("Rellenando pixel en (%d, %d) con el color blanco.\n", x, y);
        
        glColor4fv(fillColor);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        
        relleno(x + 1, y, interiorColor, fillColor);
        relleno(x - 1, y, interiorColor, fillColor);
        relleno(x, y + 1, interiorColor, fillColor);
        relleno(x, y - 1, interiorColor, fillColor);
        
    }
    // No es necesario llamar a glFlush() aquí ya que puede afectar el rendimiento
}
