/* Author: Alex Yuly (alexyuly) */

#include "drawBuildings.h"
#include "Angel.h"


/* Building 1: South side of Snoqualmie library */
void drawBuilding1(int closeUp) {

	// Color constants
	float brick_color[] = {0.508, 0.148, 0.098};
	float trim_color[] = {0.9, 0.95, 0.9};
	float window_color[] = {0.684, 0.914, 0.664};
	float roof_color[] = {0.8, 0.8, 0.8};

	// If close-up, then zoom in to building.
	if (closeUp) {
		glScalef(10, 10, 10);
	}
	// Otherwise, position building on campus map.
	else {
		glScalef(1.2, 1.2, 1.2);
		glRotatef(-12.0, 0.0, 1.0, 0.0);
		glTranslatef(-2.4, 0.0, 0.6);
	}


	/* Draw base of tower. */

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);

	// Middle layer of bricks
	glPushMatrix();
		glScalef(0.5, 0.25, 0.5);
		glutSolidCube(1);
	glPopMatrix();

	// Bottom layer of bricks
	glPushMatrix();
		glScalef(0.52, 0.125, 0.52);
		glTranslatef(0.0, -1.5, 0.0);
		glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);

	// Trim between top and middle brick layers
	glPushMatrix();
		glScalef(0.5, 0.02, 0.5);
		glTranslatef(0.0, 6.5, 0.0);
		glutSolidCube(1);
	glPopMatrix();

	// Trim between middle and bottom brick layers
	glPushMatrix();
		glScalef(0.52, 0.02, 0.52);
		glTranslatef(0.0, -6.0, 0.0);
		glutSolidCube(1);
	glPopMatrix();

	// Trim above windows
	glPushMatrix();
		glScalef(0.17, 0.02, 0.1);
		glTranslatef(0.0, 3.5, 2.1);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glScalef(0.1, 0.02, 0.17);
		glTranslatef(2.1, 3.5, 0.0);
		glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);

	// Windows
	glPushMatrix();
		glScalef(0.17, 0.18, 0.1);
		glTranslatef(0.0, -0.1, 2.1);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glScalef(0.1, 0.18, 0.17);
		glTranslatef(2.1, -0.1, 0.0);
		glutSolidCube(1);
	glPopMatrix();


	/* Draw south wing, east side */

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);

	// Top layer of bricks
	glPushMatrix();
		glScalef(0.6, 0.3, 0.9);
		glTranslatef(-0.9, 0.97, -0.32);
		glutSolidCube(1);
	glPopMatrix();

	// Middle layer of bricks
	glPushMatrix();
		glScalef(0.6, 0.25, 0.9);
		glTranslatef(-0.9, 0.0, -0.32);
		glutSolidCube(1);
	glPopMatrix();

	// Bottom layer of bricks
	glPushMatrix();
		glScalef(0.61, 0.125, 0.9);
		glTranslatef(-0.9, -1.5, -0.3);
		glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);

	// Trim between top and middle brick layers
	glPushMatrix();
		glScalef(0.6, 0.02, 0.9);
		glTranslatef(-0.9, 6.5, -0.32);
		glutSolidCube(1);
	glPopMatrix();

	// Trim between middle and bottom brick layers
	glPushMatrix();
		glScalef(0.61, 0.02, 0.9);
		glTranslatef(-0.9, -6.0, -0.3);
		glutSolidCube(1);
	glPopMatrix();

	// Trim above windows
	glPushMatrix();
		glScalef(0.17, 0.02, 0.1);
		glTranslatef(-4.2, 3.5, 1.25);
		glutSolidCube(1);
		glTranslatef(1.2, 0.0, 0.0);
		glutSolidCube(1);
		glTranslatef(-1.2, 15.5, 0.0);
		glutSolidCube(1);
		glTranslatef(1.2, 0.0, 0.0);
		glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);

	// Windows
	glPushMatrix();
		glScalef(0.17, 0.18, 0.1);
		glTranslatef(-4.2, -0.1, 1.25);
		glutSolidCube(1);
		glTranslatef(1.2, 0.0, 0.0);
		glutSolidCube(1);
		glTranslatef(-1.2, 1.7, 0.0);
		glutSolidCube(1);
		glTranslatef(1.2, 0.0, 0.0);
		glutSolidCube(1);
	glPopMatrix();


	/* Draw roof area */

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);

	glPushMatrix();
		glScalef(0.3, 0.3, 0.3);
		glTranslatef(-1.8, 2.45, 0.54);
		glBegin(GL_POLYGON);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(1.0, -1.0, 0.0);
			glVertex3f(-1.0, -1.0, 0.0);
		glEnd();
		glTranslatef(0.0, 0.0, -3.0);
		glBegin(GL_POLYGON);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(1.0, -1.0, 0.0);
			glVertex3f(-1.0, -1.0, 0.0);
		glEnd();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);

	glPushMatrix();
		glRotatef(45.0, 0.0, 0.0, 1.0);
		glScalef(0.2, 0.22, 0.45);
		glTranslatef(0.68, 3.1, -0.64);
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0, 1.0, 1.0);
			glVertex3f(0.0, 1.0, -1.0);
			glVertex3f(0.0, -1.0, 1.0);
			glVertex3f(0.0, 1.0, -1.0);
			glVertex3f(0.0, -1.0, 1.0);
			glVertex3f(0.0, -1.0, -1.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-45.0, 0.0, 0.0, 1.0);
		glScalef(0.2, 0.22, 0.45);
		glTranslatef(-4.5, -0.4, -0.64);
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0, 1.0, 1.0);
			glVertex3f(0.0, 1.0, -1.0);
			glVertex3f(0.0, -1.0, 1.0);
			glVertex3f(0.0, 1.0, -1.0);
			glVertex3f(0.0, -1.0, 1.0);
			glVertex3f(0.0, -1.0, -1.0);
		glEnd();
	glPopMatrix();
}