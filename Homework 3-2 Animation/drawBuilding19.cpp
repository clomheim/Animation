/* Jordan Matthews
/ TCSS343 - Project 3 - Milestone 1
*/
#include "drawBuildings.h"

#include "Angel.h"

float roofColor[] = { 0.184, 0.310, 0.310 };
float baseColor[] = { 0.827, 0.827, 0.827 };
float yellowMat[] = { .75, .75, 0 };
static float brickRedMat[] = { .58, .27, .06 };
float floorColor[] = {0.961, 0.871, 0.702};
float lightGray[] = { 0.827, 0.827, 0.827 };
static float windowSurface[] = { .1, .27, .46 };
float darkerGray[] = { 0.439, 0.502, 0.565 };






static void upperLevel() {
	for (int i = 0; i < 5; i++) {
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);
		//brick next to window
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(27.95 + (i *3), 3, -1.75);
		glScalef(.85, 1.00, .05);
		glutSolidCube(1);
		glPopMatrix();

		//windows
		glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
		glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(28.50 + (i * 3), 3, -1.75);
		glScalef(.25, 1.00, .05);
		glutSolidCube(1);
		glPopMatrix();
		glDisable(GL_BLEND);

		//vertical window bars
		glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray);
		glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray);
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(28.65 + (i * 3), 3, -1.75);
		glScalef(.05, 1.00, .05);
		glutSolidCube(1);
		glPopMatrix();

		//windows
		glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
		glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(28.80 + (i * 3), 3, -1.75);
		glScalef(.25, 1.00, .05);
		glutSolidCube(1);
		glPopMatrix();
		glDisable(GL_BLEND);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);
		//brick next to window
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(29.35 + (i * 3), 3, -1.75);
		glScalef(.85, 1.00, .05);
		glutSolidCube(1);
		glPopMatrix();
	}

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);
	//brick below windows
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(34.5, 2.2, -1.75);
	glScalef(15, 0.60, .05);
	glutSolidCube(1);
	glPopMatrix();

	//brick above windows
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(34.5, 3.85, -1.75);
	glScalef(15, 0.73, .05);
	glutSolidCube(1);
	glPopMatrix();
}

static void drawDetails() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, darkerGray);
	glMaterialfv(GL_FRONT, GL_AMBIENT, darkerGray);
	//awning
	glPushMatrix();
	glTranslatef(32.7, 2.15, 10.75);
	glRotatef(-22, 0, 1, 0);
	glScalef(15.0, .10, 2);
	glutSolidCube(1);
	glPopMatrix();
}

static void drawShell() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, baseColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, baseColor);
	//front concrete
	glPushMatrix();
	glTranslatef(33.0, -.40, 10.76);
	glRotatef(-22, 0 , 1, 0);
	glScalef(15.5, .80, 2);
	glutSolidCube(1);
	glPopMatrix();
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);
	//back side
	glPushMatrix();
	glTranslatef(32.7, 1.75, 18.7);
	glScalef(15.0, 5, 0);
	glutSolidCube(1);
	glPopMatrix();

	//leftside
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-13.6, 1.75, 25.35);
	glScalef(10.5, 5, 0);
	glutSolidCube(1);
	glPopMatrix();

	//rightside
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-16.2, 1.75, 40.00);
	glScalef(4.85, 5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, floorColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, floorColor);
	//first level
	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glRotatef(180, 0, 1, 0);
	glTranslatef(32.7, 0, -13.39);
	glScalef(14.60, 0, 9.85);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(0.5, 0.0, -0.05);
	glVertex3f(-0.5, 0.0, 0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glEnd();
	glPopMatrix();

	//second level
	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glRotatef(180, 0, 1, 0);
	glTranslatef(32.7, -2.0, -13.39);
	glScalef(14.60, 0, 9.85);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(0.5, 0.0, -0.05);
	glVertex3f(-0.5, 0.0, 0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glEnd();
	glPopMatrix();

	//roof level
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofColor);
	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glRotatef(180, 0, 1, 0);
	glTranslatef(32.7, -4.25, -13.39);
	glScalef(14.67, 0, 10.40);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(0.5, 0.0, -0.05);
	glVertex3f(-0.5, 0.0, 0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glEnd();
	glPopMatrix();
}

static void lowerLevelWindows() {
	
	for (int i = 0; i < 20; i++) {
		//lower level window bars
		glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray);
		glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray);
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(27.10 + (i * 0.75), .98, -1.8);
		glScalef(.05, 2, .05);
		glutSolidCube(1);
		glPopMatrix();

		//windows
		glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
		glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(27.5 + (i * 0.75), .98, -1.8);
		glScalef(.75, 2, .05);
		glutSolidCube(1);
		glPopMatrix();
		glDisable(GL_BLEND);

		//lower level window bars
		glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray);
		glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray);
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(27.90 + (i * 0.75), .98, -1.8);
		glScalef(.05, 2, .05);
		glutSolidCube(1);
		glPopMatrix();
	}
}

static void drawColumns() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);
	//front columns
	for (int i = 0; i < 6; i++) {
		glPushMatrix();
		glRotatef(-22, 0, 1, 0);
		glTranslatef(27.2 + (i * 2.95), 1.74, -1.90);
		glScalef(1, 5, .7);
		glutSolidCube(1);
		glPopMatrix();
	}
}

void drawBuilding19(int closeUp) {
	if (closeUp) {
		glRotatef(270, 0, 1, 0);
		glTranslatef(-20.0, 0, 0);
		glScalef(0.7, 0.7, 0.7);
	} else {
		glScalef(.2, .2, .2);
		glTranslatef(7.6, 1, 3);
	}
	drawShell();
	drawColumns();
	lowerLevelWindows();
	upperLevel();
	drawDetails();
}