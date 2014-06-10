#include "drawBuildings.h"
#include "Angel.h"

// The WCG building
// Auth: Sean Gray
float brickMat18[] = { .65, .05, .05 };
float bannerMat18[] = { .3, .3, .2 };
float windowMat18[] = { .15, .15, .65 };

// Frame works.
void frame18() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowMat18);

	glScalef(.696, .49, .99);
	glutSolidCube(2);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat18);

	glPopMatrix();
}

// Shell works.
void shell18() {
	glPushMatrix();
	glScalef(.698, .5, .99);
	glTranslatef(0, 0, .1);
	glutSolidCube(2);
	glPopMatrix();
}

// platform done
void platformLayer18() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bannerMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bannerMat18);

	glScalef(.233, .08, .1);
	glTranslatef(0, -5.2, -9.7);
	glutSolidCube(2);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat18);

	glPopMatrix();
}

//Reuse the colums and splitters for top floors.
void firstFloor18() {
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, -7.88, -9.7);
	glutSolidCube(2); //under window
	glPopMatrix();
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, -1, -9.7);
	glutSolidCube(2); //over window
	glPopMatrix();
	glPushMatrix();
	glScalef(.025, .05, .1);
	glTranslatef(0, -1.75, -9.7);
	glutSolidCube(2); //center column
	glPopMatrix();
	glPushMatrix();
	glScalef(.025, .05, .1);
	glTranslatef(-8.27, -1.75, -9.7);
	glutSolidCube(2); //left column
	glPopMatrix();
	glPushMatrix();
	glScalef(.025, .05, .1);
	glTranslatef(8.27, -1.75, -9.7);
	glutSolidCube(2); //right column
	glPopMatrix();
	glPushMatrix(); //splitters
	glScalef(.015, .05, .1);
	glTranslatef(6.8, -1.75, -9.7);
	glutSolidCube(2);
	glTranslatef(-13.6, 0, 0);
	glutSolidCube(2);
	glPopMatrix();
}

// Banner done
void bannerLayer18() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bannerMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bannerMat18);
	glScalef(.233, .03, .1);
	glTranslatef(0, 1, -9.7);
	glutSolidCube(2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat18);
	glPopMatrix();
}

// class code, white space reduced for page length
void drawArch18() {

	int i, numSlices;
	double angle;
	double angInc;

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glScalef(2, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1, 0);
	glScalef(1, 4, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -1, 0);
	glScalef(1, 4, 2);
	glutSolidCube(1);
	glPopMatrix();


	numSlices = 20;
	angle = 0;
	angInc = 3.14159 / (2 * numSlices);

	for (i = 0; i < numSlices; i++) {

		glNormal3f(0, 0, 1);
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex3f(1, 0, 1);  // corner
		glVertex3f(cos(angle), sin(angle) - 1, 1);
		glVertex3f(cos(angle + angInc), sin(angle + angInc) - 1, 1);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-1, 0, 1);  // corner
		glVertex3f(-cos(angle), sin(angle) - 1, 1);
		glVertex3f(-cos(angle + angInc), sin(angle + angInc) - 1, 1);
		glEnd();

		//---
		glBegin(GL_POLYGON);
		glVertex3f(1, 0, -1);  // corner
		glVertex3f(cos(angle), sin(angle) - 1, -1);
		glVertex3f(cos(angle + angInc), sin(angle + angInc) - 1, -1);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-1, 0, -1);  // corner
		glVertex3f(-cos(angle), sin(angle) - 1, -1);
		glVertex3f(-cos(angle + angInc), sin(angle + angInc) - 1, -1);
		glEnd();
		// vault
		glNormal3f(-cos(angle + angInc / 2), -sin(angle + angInc / 2), 0);


		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex3f(cos(angle), sin(angle) - 1, 1);  // corner
		glVertex3f(cos(angle), sin(angle) - 1, -1);
		glVertex3f(cos(angle + angInc), sin(angle + angInc) - 1, -1);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(cos(angle), sin(angle) - 1, 1);  // corner
		glVertex3f(cos(angle + angInc), sin(angle + angInc) - 1, 1);
		glVertex3f(cos(angle + angInc), sin(angle + angInc) - 1, -1);
		glEnd();

		glNormal3f(cos(angle + angInc / 2), -sin(angle + angInc / 2), 0);

		glBegin(GL_POLYGON);
		glVertex3f(-cos(angle), sin(angle) - 1, 1);  // corner
		glVertex3f(-cos(angle), sin(angle) - 1, -1);
		glVertex3f(-cos(angle + angInc), sin(angle + angInc) - 1, -1);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-cos(angle), sin(angle) - 1, 1);  // corner
		glVertex3f(-cos(angle + angInc), sin(angle + angInc) - 1, 1);
		glVertex3f(-cos(angle + angInc), sin(angle + angInc) - 1, -1);
		glEnd();
		angle += angInc;
	}
}

void topFloors18() {
	glPushMatrix();
	glScalef(.025, .17, .1);
	glTranslatef(0, 1.35, -9.7);
	glutSolidCube(2); //center column
	glTranslatef(-8.27, 0, 0);
	glutSolidCube(2); //left column
	glTranslatef(16.54, 0, 0);
	glutSolidCube(2); //right column
	glPopMatrix();
	glPushMatrix(); //splitters
	glScalef(.015, .17, .1);
	glTranslatef(6.8, 1.35, -9.7);
	glutSolidCube(2);
	glTranslatef(-13.6, 0, 0);
	glutSolidCube(2);
	glPopMatrix();
	glPushMatrix();
	glScalef(.233, .03, .1);
	glTranslatef(0, 7, -9.2);
	glutSolidCube(2); //inset sill
	glPopMatrix();
	//Begin arches:
	glPushMatrix();
	glScalef(.0315, .035, .1);
	glTranslatef(-4.65, 10.5, -9.7);
	drawArch18();
	int i;
	for (i = 0; i < 3; i++) {
		if (i == 1) glTranslatef(.95, 0, 0);
		glTranslatef(2.8, 0, 0);
		drawArch18();
	}
	glPopMatrix();
	//end arches
}

void roofLayer18() {
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, 24, -9.7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bannerMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bannerMat18);
	glutSolidCube(2); // roof edge
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat18);
	glScalef(1, 1.5, 1);
	glTranslatef(0, -1.7, 0);
	glutSolidCube(2);
	glPopMatrix();
}
void leftFace18() {
	glPushMatrix();
	glTranslatef(-.465, 0, 0);
	platformLayer18();
	// begin ground floor:
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, -15.6, -9.7);
	glutSolidCube(2); //under window
	glPopMatrix();
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, -10, -9.7);
	glutSolidCube(2); //over window
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .05, .1);
	glTranslatef(0, -5, -9.7);
	glutSolidCube(2); //center column
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .05, .1);
	glTranslatef(-5.62, -5, -9.7);
	glutSolidCube(2); //left column
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .05, .1);
	glTranslatef(5.62, -5, -9.7);
	glutSolidCube(2); //right column
	glPopMatrix();
	// end ground floor
	firstFloor18();
	bannerLayer18();
	topFloors18();
	roofLayer18();
	glPopMatrix();
}

void centerFace18() {
	glPushMatrix();
	platformLayer18();
	// Begin ground floor:
	glPushMatrix();
	glPopMatrix();
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, -10, -9.7);
	glutSolidCube(2); //over door/window
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .055, .1);
	glTranslatef(0, -5.05, -9.7);
	glutSolidCube(2); //center column
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .055, .1);
	glTranslatef(-5.82, -5.05, -9.7);
	glutSolidCube(2); //left column
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .055, .1);
	glTranslatef(5.82, -5.05, -9.7);
	glutSolidCube(2); //right column
	glPopMatrix();
	glPushMatrix();
	glScalef(.1, .02, .1);
	glTranslatef(-.68, -15.6, -9.7);
	glutSolidCube(2); //under window
	glPopMatrix();
	// end ground floor
	firstFloor18();
	bannerLayer18();
	topFloors18();
	roofLayer18();
	glPopMatrix();
}

void rightFace18() {
	glTranslatef(.465, 0, 0);
	glPushMatrix();
	platformLayer18();
	// Begin ground floor:
	glPushMatrix();
	glPopMatrix();
	glPushMatrix();
	glScalef(.233, .02, .1);
	glTranslatef(0, -10, -9.7);
	glutSolidCube(2); //over door/window
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .055, .1);
	glTranslatef(0, -5.05, -9.7);
	glutSolidCube(2); //center column
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .055, .1);
	glTranslatef(-5.82, -5.05, -9.7);
	glutSolidCube(2); //left column
	glPopMatrix();
	glPushMatrix();
	glScalef(.035, .055, .1);
	glTranslatef(5.62, -5.05, -9.7);
	glutSolidCube(2); //right column
	glPopMatrix();
	glPushMatrix();
	glScalef(.1, .02, .1);
	glTranslatef(-.68, -15.6, -9.7);
	glutSolidCube(2); //under window
	glPopMatrix();
	// end ground floor
	firstFloor18();
	bannerLayer18();
	topFloors18();
	roofLayer18();
	glPopMatrix();
}

void face18() {
	glPushMatrix();
	leftFace18();
	centerFace18();
	rightFace18();
	glPopMatrix();
}

void drawBuilding18(int closeUp) {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat18);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat18);
	if (closeUp) {
		glScalef(6, 6, 6);
	}
	else {
		glTranslatef(14.33, -.6, .285);
	}
	frame18();
	face18();
	shell18();
	
}
