/*  demo.c*/
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <SOIL/SOIL.h> //var ielaadeet bildes!!!! zajebiss
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#define PI 3.14159265359;
#define screenWidth 800
#define screenHeight 600

/* Initialize OpenGL Graphics */
void initGL();

void drawHollowCircle(GLfloat, GLfloat, GLfloat);

void draw_figure(float,float);

void draw_bomb(float , float );

void draw_wall(float , float );

void draw_crate(float , float );

void display();

void reshape(GLsizei, GLsizei);

void initBomberDisplay();
