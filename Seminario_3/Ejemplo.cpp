/*ESTRELLA DE DAVID*/

#include <iostream>
#include <gl\freeglut.h>
#include <cstdlib>
#define PI 3.1415926
using namespace std;
GLuint petalo, corola, flor;
void init() {
	//petalo
	petalo = glGenLists(1);
	glNewList(petalo, GL_COMPILE);

	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);

	glColor3f(1, 1, 1);
	glPushMatrix();
	glScaled(0.15, 0.5, 0.15);
	glutSolidSphere(1,20,20);
	glPopMatrix();

	glEndList();

	//corola
	corola = glGenLists(1);
	glNewList(corola, GL_COMPILE);

	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
	glColor3f(1, 1, 1);
	for (auto i = 0; i < 12; i++) {
		glPushMatrix();
		glRotatef(i*30.0,0,0,1);
		glTranslatef(0,0.25,0);
		glScalef(0.5, 0.5, 0.5);
		glCallList(petalo);
		glPopMatrix();
	}
	glColor3f(1,1,0);
	glPushMatrix();
	glScalef(0.2,0.2,0.2);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	glEndList();

	//flor
	flor = glGenLists(1);
	glNewList(flor, GL_COMPILE);
	
	glPushMatrix();
	glColor3f(0, 1, 0);
	glScalef(0.05, 0.75, 0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	//glRotatef(10, 1, 0, 0);
	glTranslatef(0, 0.25, 0);
	glScalef(0.5, 0.5, 0.5);
	glCallList(corola);
	glPopMatrix(); 
	glEndList();
}


void display() {

	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	for (int i = 0; i < 100; i++) {
		glPushMatrix();
		glTranslatef(
		(rand()%200-100)/100.0,
		(rand()%100-50)/100.0,
		0.0
		);
		glScalef(0.5, 0.5, 0.5);
		glCallList(flor);
		glPopMatrix();

	}
	

	

	glFlush();

}

void reshape(int ancho, int largo) {


}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ejemplo");

	init();

	std::cout << "Seminario 3" << std::endl;

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

}