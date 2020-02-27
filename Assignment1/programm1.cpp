/* Athabasca University
   Comp390 - Introduction to Computer Graphics
    Assignment 1
    Program 1
    Draw 2 houses with different technique
   @author: Yunbing Weng
   @date: Jan 26, 2020
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <windows.h>


int xmax = 640;
int ymax = 480;

// initialize

void initialize() {
	// set background color
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


// first housr
void house1(){
    glColor3f(0,0,0);
    glEnable(GL_BLEND);
    glEnable( GL_LINE_SMOOTH );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //house body
    glBegin (GL_LINE_LOOP);
        glVertex2f (0, 0);
        glVertex2f (1.00, 0.30);
        glVertex2f (0.70, 1.30);
        glVertex2f (-0.30, 1.00);
    glEnd ();
    //house top
    glBegin (GL_LINE_LOOP);
        glVertex2f (0.10, 1.483333333333);
        glVertex2f (1.0333333333, 1.40);
        glVertex2f (-0.633333333, 0.90);
    glEnd ();
    glDisable(GL_BLEND);
    glDisable( GL_LINE_SMOOTH );
}

//second house rules
void house2(){
    glColor3f(0,0,0);
    //house body
    glBegin (GL_LINE_LOOP);
        glVertex2f (-2.00, 2.00);
        glVertex2f (-1.00, 2.30);
        glVertex2f (-1.30, 3.30);
        glVertex2f (-2.30, 3.00);
    glEnd ();
    //house top
    glBegin (GL_LINE_LOOP);
        glVertex2f (-1.90, 3.483333333333);
        glVertex2f (-0.96666666667, 3.40);
        glVertex2f (-2.6333333333, 2.90);
    glEnd ();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	house1();
	house2();
	glutSwapBuffers();
}



// reshape registry

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
	glMatrixMode(GL_MODELVIEW);
}

// main program

int main(int argc, char **argv){

	glutInit( &argc, argv );
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
	glutInitWindowSize(500, 500);
  	glutInitWindowPosition(100, 100);


	int windowHandle = glutCreateWindow("Athabasca University - Comp390 A1P1");
	glutSetWindow(windowHandle);

	glutDisplayFunc( display );
	glutReshapeFunc( reshape );

	initialize();
    glutMainLoop();
}
