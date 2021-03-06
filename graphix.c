/*  demo.c*/

#include "graphix.h"


/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);

		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void draw_figure(float x, float y)
{
  glLineWidth(2);
  glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f); // Blue
     glVertex2f(x+0.14, y+0.14);//galva
     glVertex2f(x+0.09, y+0.17);
     glVertex2f(x+0.09, y+0.14);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(x+0.11, y+0.14);//rumpis
  glVertex2f(x+0.11, y+0.07);

  glVertex2f(x+0.11, y+0.12);//roka
  glVertex2f(x+0.13, y+0.08);

  glVertex2f(x+0.11, y+0.12);//roka
  glVertex2f(x+0.09, y+0.08);

  glVertex2f(x+0.11, y+0.07);//kaaja
  glVertex2f(x+0.13, y+0.02);

  glVertex2f(x+0.11, y+0.07);//kaaja
  glVertex2f(x+0.09, y+0.02);
  glEnd();
}

void draw_bomb(float x, float y)
{
glLineWidth(2);
glColor3f(1.0f, 0.0f, 0.3f);
drawHollowCircle(x+0.1,y+0.15, 0.01);
drawHollowCircle(x+0.1,y+0.07, 0.03);
glColor3f(0.5f, 1.0f, 1.0f);
drawHollowCircle(x+0.1,y+0.07, 0.05);


glBegin(GL_LINES);
glVertex2f(x+0.1, y+0.1);
glVertex2f(x+0.1, y+0.15);
glEnd();

}

void draw_wall(float x, float y)
{
  glLineWidth(2);
  glBegin(GL_QUADS);
  glColor3f(0.5f, 0.5f, 0.5f); // Red
  glVertex2f(x+0.02, y+0.02);
  glVertex2f(x+0.18, y+0.02);
  glVertex2f(x+0.18, y+0.18);
  glVertex2f(x+0.02, y+0.18);

  glVertex2f(x, y);
  glVertex2f(x+0.2, y);
  glVertex2f(x+0.2, y+0.2);
  glVertex2f(x, y+0.2);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(x+0.02, y+0.02);
  glVertex2f(x+0.18, y+0.18);
  glVertex2f(x+0.18, y+0.02);
  glVertex2f(x+0.02, y+0.18);
  glEnd();

}

void draw_crate(float x, float y)
{
  glLineWidth(2);
  glBegin(GL_QUADS);
  glColor3f(0.5f, 0.5f, 0.0f);
  glVertex2f(x+0.02, y+0.02);
  glVertex2f(x+0.18, y+0.02);
  glVertex2f(x+0.18, y+0.18);
  glVertex2f(x+0.02, y+0.18);

  glVertex2f(x+0.06, y+0.02);
  glVertex2f(x+0.14, y+0.02);
  glVertex2f(x+0.14, y+0.18);
  glVertex2f(x+0.06, y+0.18);

  glVertex2f(x+0.02, y+0.06);
  glVertex2f(x+0.18, y+0.06);
  glVertex2f(x+0.18, y+0.14);
  glVertex2f(x+0.02, y+0.14);


  glEnd();
}


/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}
