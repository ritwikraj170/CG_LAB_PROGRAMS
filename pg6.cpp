#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
void obj(double tx, double ty, double tz, double sx, double sy, double sz)
{
	glRotated(50, 0, 1, 0);
	glRotated(10, -1, 0, 0);
	glRotated(12, 0, 0, -1);
	glTranslated(tx, ty, tz);
	glScaled(sx, sy, sz);
	glutSolidCube(1);
	glLoadIdentity();
}
void display()
{
	glViewport(0, 0, 700, 700);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	obj(0, 0, 0.5, 1, 1, 0.01);//to Draw walls 
	obj(0, -0.5, 0, 1, 0.04, 1);
	obj(-0.5, 0, 0, 0.04, 1, 1);
	obj(0, -0.3, 0, 0.02, 0.2, 0.02);//to draw legs of table
	obj(0, -0.3, -0.4, 0.02, 0.2, 0.02);
	obj(0.4, -0.3, 0, 0.02, 0.2, 0.02);
	obj(0.4, -0.3, -0.4, 0.02, 0.2, 0.02);
	obj(0.2, -0.18, -0.2, 0.6, 0.02, 0.6);//To draw table surface
	glRotated(50, 0, 1, 0);
	glRotated(10, -1, 0, 0);
	glRotated(11.7, 0, 0, -1);
	glTranslated(0.3, -0.1, -0.3);
	glutSolidTeapot(0.09);
	glFlush();
	glLoadIdentity();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
int main(int argc, char **argv)
{
	float ambient[] = { 1, 1, 1, 1 };
	float light_pos[] = { 27, 80, 2, 3 };
	glutInit(&argc, argv);
	glutCreateWindow("simple shaded scene consisting of tea pot on a table");
	glutInitWindowSize(700, 700);
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
