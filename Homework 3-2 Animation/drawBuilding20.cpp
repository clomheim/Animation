/**
 * Staircase of JOY
 *
 * @author Tim Mikeladze
 */

#include "drawBuildings.h"

#include "Angel.h"

void drawWireFrame20() {
	float color[] = { 0.75, 0.75, 0.75 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	glPushMatrix();

	glScalef(2, 3, 1);
	glutWireCube(1);
	glPopMatrix();
}

void drawFrontWall20() {

	float wallColor[] = { 0.6, 0.6, 0.6 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, wallColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, wallColor);

	glPushMatrix();

	glBegin(GL_QUADS);
	glVertex3f(-0.8f, 1.5f, 0.5f);
	glVertex3f(1.0f, 1.5f, 0.5f);
	glVertex3f(1.0f, -1.5f, 0.5f);
	glVertex3f(-0.8f, -1.5f, 0.5f);
	glEnd();

	glPopMatrix();

	float textureColor[] = { 0.55, 0.55, 0.55 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, textureColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, textureColor);

	glPushMatrix();

	glBegin(GL_QUADS);

	for (int i = 0; i <= 29; i++) {
		float j = 1.45 - (i * 0.10);
		glVertex3f(-0.78f, j, 0.51f);
		glVertex3f(0.9f, j, 0.51f);
		glVertex3f(0.9f, j - 0.015, 0.51f);
		glVertex3f(-0.78f, j - 0.015, 0.51f);
	}

	glEnd();

	glPopMatrix();
}

void drawBackWall20() {
	glLineWidth(2.0);

	float color[] = { 0.6, 0.6, 0.6 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	glPushMatrix();

	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 1.5f, -0.5f);
	glVertex3f(1.0f, 1.5f, -0.5f);
	glVertex3f(1.0f, -1.5f, -0.5f);
	glVertex3f(-1.0f, -1.5f, -0.5f);
	glEnd();

	glPopMatrix();
}

void drawTop20() {
	float color[] = { 0.8, 0.8, 0.8 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	glPushMatrix();

	glBegin(GL_QUADS);

	glVertex3f(-1.0f, 1.5f, -0.5f);
	glVertex3f(1.0f, 1.5f, -0.5f);
	glVertex3f(1.0f, 1.5f, 0.5f);
	glVertex3f(-1.0f, 1.5f, 0.5f);

	glEnd();
	glPopMatrix();

}

void drawBottom20() {
	float color[] = { 0.8, 0.8, 0.8 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	glPushMatrix();

	glBegin(GL_QUADS);

	glVertex3f(-1.0f, -1.5f, -0.5f);
	glVertex3f(1.0f, -1.5f, -0.5f);
	glVertex3f(1.0f, -1.5f, 0.5f);
	glVertex3f(-1.0f, -1.5f, 0.5f);

	glEnd();
	glPopMatrix();
}

void drawThinWindow20() {

	float windowColor[] = { 0.36, 0.70, 1.0, 0.3 };

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowColor);

	glPushMatrix();
	glBegin(GL_QUADS);

	glVertex3f(-0.8f, 1.5f, 0.5f);
	glVertex3f(-1.0f, 1.5f, 0.5f);
	glVertex3f(-1.0f, -1.5f, 0.5f);
	glVertex3f(-0.8f, -1.5f, 0.5f);

	glEnd();

	glDisable(GL_BLEND);

	glPopMatrix();

	float frameColor[] = { 0.75, 0.75, 0.75 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, frameColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frameColor);

	glPushMatrix();
	glBegin(GL_QUADS);

	for (int i = 0; i <= 8; i++) {
		float j = 1.2 - (i * 0.3);

		glVertex3f(-0.8f, j, 0.51f);
		glVertex3f(-1.0f, j, 0.51f);
		glVertex3f(-1.0f, j - 0.025, 0.51f);
		glVertex3f(-0.8f, j - 0.025, 0.51f);

		glVertex3f(-0.8f, j, 0.49f);
		glVertex3f(-1.0f, j, 0.49f);
		glVertex3f(-1.0f, j - 0.025, 0.49f);
		glVertex3f(-0.8f, j - 0.025, 0.49f);
	}

	glEnd();

	glPopMatrix();

}

void drawWindowRight20() {
	float color[] = { 0.36, 0.70, 1.0, 0.3 };

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	glPushMatrix();

	glBegin(GL_QUADS);

	glVertex3f(1.0f, 1.5f, 0.5f);
	glVertex3f(1.0f, 1.5f, -0.5f);
	glVertex3f(1.0f, -1.5f, -0.5f);
	glVertex3f(1.0f, -1.5f, 0.5f);

	glEnd();

	glDisable(GL_BLEND);

	glPopMatrix();

	float frameColor[] = { 0.75, 0.75, 0.75 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, frameColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frameColor);

	glPushMatrix();
	glBegin(GL_QUADS);

	for (int i = 0; i <= 5; i++) {
		float j = 1.2 - (i * 0.5);

		glVertex3f(1.01f, j, 0.5f);
		glVertex3f(1.01f, j, -0.5f);
		glVertex3f(1.01f, j - 0.025, -0.5f);
		glVertex3f(1.01f, j - 0.025, 0.5f);

		glVertex3f(0.99f, j, 0.5f);
		glVertex3f(0.99f, j, -0.5f);
		glVertex3f(0.99f, j - 0.025, -0.5f);
		glVertex3f(0.99f, j - 0.025, 0.5f);

	}

	glVertex3f(1.01f, 1.5f, 0.3f);
	glVertex3f(1.01f, 1.5f, 0.325f);
	glVertex3f(1.01f, -1.5f, 0.325f);
	glVertex3f(1.01f, -1.5f, 0.3f);

	glVertex3f(1.01f, 1.5f, -0.3f);
	glVertex3f(1.01f, 1.5f, -0.325f);
	glVertex3f(1.01f, -1.5f, -0.325f);
	glVertex3f(1.01f, -1.5f, -0.3f);

	glEnd();

	glPopMatrix();
}

void drawWindowLeft20() {
	float color[] = { 0.36, 0.70, 1.0, 0.3 };

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	glPushMatrix();

	glBegin(GL_QUADS);

	glVertex3f(-1.0f, 1.5f, 0.5f);
	glVertex3f(-1.0f, 1.5f, -0.5f);
	glVertex3f(-1.0f, -1.5f, -0.5f);
	glVertex3f(-1.0f, -1.5f, 0.5f);

	glEnd();

	glDisable(GL_BLEND);

	glPopMatrix();

	//glPopMatrix();  // extra!!?

	float frameColor[] = { 0.75, 0.75, 0.75 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, frameColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frameColor);

	glPushMatrix();
	glBegin(GL_QUADS);

	for (int i = 0; i <= 5; i++) {
		float j = 1.2 - (i * 0.5);

		glVertex3f(-1.01f, j, 0.5f);
		glVertex3f(-1.01f, j, -0.5f);
		glVertex3f(-1.01f, j - 0.025, -0.5f);
		glVertex3f(-1.01f, j - 0.025, 0.5f);

		glVertex3f(-0.99f, j, 0.5f);
		glVertex3f(-0.99f, j, -0.5f);
		glVertex3f(-0.99f, j - 0.025, -0.5f);
		glVertex3f(-0.99f, j - 0.025, 0.5f);

	}

	glVertex3f(-1.01f, 1.5f, 0.3f);
	glVertex3f(-1.01f, 1.5f, 0.325f);
	glVertex3f(-1.01f, -1.5f, 0.325f);
	glVertex3f(-1.01f, -1.5f, 0.3f);

	glVertex3f(-1.01f, 1.5f, -0.3f);
	glVertex3f(-1.01f, 1.5f, -0.325f);
	glVertex3f(-1.01f, -1.5f, -0.325f);
	glVertex3f(-1.01f, -1.5f, -0.3f);

	glEnd();

	glPopMatrix();
}

void drawStairCase20() {
	float color[] = { 0.5, 0.5, 0.5 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);

	for (int i = 0; i < 14; i++) {
		glPushMatrix();

		glScalef(0.125, 0.075, .5);

		glTranslatef(6.0f - i, -19.5f + i, 0.49f);

		glutSolidCube(1);

		glPopMatrix();
	}

	glPushMatrix();
	glScalef(0.125, 0.075, .5);
	glTranslatef(-7.5f, -6.5f, 0.49f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.125, 0.075, .5);
	glTranslatef(-7.5f, -6.5f, -0.49f);
	glutSolidCube(1);
	glPopMatrix();

	for (int i = 0; i < 14; i++) {
		glPushMatrix();

		glScalef(0.125, 0.075, .5);

		glTranslatef(-7.0f + i, -6.5f + i, -0.49f);

		glutSolidCube(1);

		glPopMatrix();
	}

	glPushMatrix();
	glScalef(0.125, 0.075, .5);
	glTranslatef(-7.0f + 14, -6.5f + 13, -0.49f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.125, 0.075, .5);
	glTranslatef(-7.0f + 14.3f, -6.5f + 13, -0.49f);
	glutSolidCube(1);
	glPopMatrix();

}

/**
 * Draws the staircase of JOY
 */
void drawBuilding20(int closeUp) {

	if (closeUp) {
		glScalef(6, 6, 6);
	} else {
		glTranslatef(9.3, 1, 7.2);
		glRotatef(140, 0, 1, 0);
		glScalef(.75f, .5f, 1);
	}

	drawBottom20();
	drawStairCase20();
	drawTop20();
	drawBackWall20();
	drawFrontWall20();
	drawThinWindow20();
	drawWindowRight20();
	drawWindowLeft20();
	drawWireFrame20();

}
