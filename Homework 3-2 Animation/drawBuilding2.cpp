#include "drawBuildings.h"

#include "Angel.h"

void
Octagon(float side, float height)
{
	char j;
	float x = sin(0.785398163) * side, y = side / 2.0, z = height / 2.0, c;

	c = x + y;
	for (j = 0; j < 8; j++) {
		glTranslatef(-c, 0.0, 0.0);
		glBegin(GL_QUADS);
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(0.0, -y, z);
		glVertex3f(0.0, y, z);
		glVertex3f(0.0, y, -z);
		glVertex3f(0.0, -y, -z);
		glEnd();
		glTranslatef(c, 0.0, 0.0);
		glBegin(GL_TRIANGLES);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, z);
		glVertex3f(-c, -y, z);
		glVertex3f(-c, y, z);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(0.0, 0.0, -z);
		glVertex3f(-c, y, -z);
		glVertex3f(-c, -y, -z);
		glEnd();
		glRotatef(45.0, 0.0, 0.0, 1.0);
	}
}

void drawRoofPillars() {
	glPushMatrix();
	glTranslatef(0.2, 2.12, 0.5);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 2.12, 0.5);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 2.12, 0.2);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 2.12, 0.2);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 2.12, -0.2);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 2.12, -0.2);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 2.12, -0.5);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 2.12, -0.5);
	glScalef(0.03, 0.22, 0.03);
	glutSolidCube(2);
	glPopMatrix();
}

void drawTopWindowBorders() {
	glPushMatrix();
	glTranslatef(0.13, 2.12, 0.27);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.13, 2.12, 0.27);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.13, 2.12, -0.27);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.13, 2.12, -0.27);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.27, 2.12, 0.1);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.27, 2.12, 0.1);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.27, 2.12, -0.1);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.27, 2.12, -0.1);
	glScalef(0.02, 0.22, 0.02);
	glutSolidCube(2);
	glPopMatrix();
}

void drawGreenWindowPillars() {
	// middle window ns
	glPushMatrix();
	glTranslatef(0.20, 0.71, 0.95);
	glScalef(0.03, 0.8, 0.04);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.20, 0.71, 0.95);
	glScalef(0.03, 0.8, 0.04);
	glutSolidCube(2);
	glPopMatrix();

	// corners
	glPushMatrix();
	glTranslatef(0.96, 0.70, 0.95);
	glScalef(0.03, 0.8, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.96, 0.70, 0.95);
	glScalef(0.03, 0.8, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(0, 1.15, 0.95);
	glScalef(0.98, 0.03, 0.03);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.32, 0.95);
	glScalef(0.98, 0.01, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.06, 1.33, 0.95);
	glScalef(0.01, 0.15, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.06, 1.33, 0.95);
	glScalef(0.01, 0.15, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 1.33, 0.95);
	glScalef(0.01, 0.15, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.78, 1.33, 0.95);
	glScalef(0.01, 0.15, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, 1.33, 0.95);
	glScalef(0.01, 0.15, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.78, 1.33, 0.95);
	glScalef(0.01, 0.15, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	// middle window side stripes
	float start = 0.94;
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-0.3, start - 0.22 * i , 0.96);
		glScalef(0.1, 0.01, 0.01);
		glutSolidCube(2);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.3, start - 0.22 * i, 0.96);
		glScalef(0.1, 0.01, 0.01);
		glutSolidCube(2);
		glPopMatrix();
	}
}

void drawSilverPillars() {
	glPushMatrix();
	glTranslatef(0.4, 0.70, 0.97);
	glScalef(0.05, 0.8, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 0.70, 0.97);
	glScalef(0.05, 0.8, 0.05);
	glutSolidCube(2);
	glPopMatrix();
}

void drawWindow() {
	glPushMatrix();
	glTranslatef(0, 0.78, 0.95);
	glScalef(0.95, 0.7, 0.005);
	glutSolidCube(2);
	glPopMatrix();
}

void drawBaseBlocks() {
	glPushMatrix();
	glScalef(1, 0.10, 1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(1, 0.01, 1);
	glutSolidCube(2);
	glPopMatrix();
}

void drawSideWall() {
	glPushMatrix();
	glTranslatef(-0.95, 0.80, -0.3);
	glRotatef(90, 0, 1, 0);
	glScalef(0.7, 0.7, 0.05);
	glutSolidCube(2);
	glPopMatrix();
}

void drawBackWall() {
	glPushMatrix();
	glTranslatef(0, 0.80, -0.95);
	glScalef(1, 0.7, 0.05);
	glutSolidCube(2);
	glPopMatrix();
}

void drawWindowOctagon() {
	glPushMatrix();
	glTranslatef(0, 1.55, 0);
	glRotatef(90, 1, 0, 0);
	Octagon(0.85, 0.15);
	glPopMatrix();
}

void drawTopWindowOctagon() {
	glPushMatrix();
	glTranslatef(0, 1.65, 0);
	glRotatef(90, 1, 0, 0);
	Octagon(0.90, 0.05);
	glPopMatrix();
}

void drawBottomWindowOctagon() {
	glPushMatrix();
	glTranslatef(0, 1.9, 0);
	glRotatef(90, 1, 0, 0);
	Octagon(0.45, 0.05);
	glPopMatrix();
}

void drawSmallTopOctagon() {
	glPushMatrix();
	glTranslatef(0, 2.35, 0);
	glRotatef(90, 1, 0, 0);
	Octagon(0.45, 0.02);
	glPopMatrix();
}

void drawTopRoof() {
	// the top roof
	glPushMatrix();
	glTranslatef(0, 2.35, 0.0);
	glRotatef(-90.0, 1, 0, 0);
	glRotatef(67.5, 0.0, 0.0, 1.0);
	glutSolidCone(0.61, 0.3, 8, 1);
	glPopMatrix();
}

void drawCylinder() {
	// cylinder
	glPushMatrix();
	glTranslatef(0, 1.67, 0);
	glRotatef(-90.0, 1, 0, 0);
	glRotatef(67.5, 0.0, 0.0, 1.0);
	GLUquadricObj *obj = gluNewQuadric();
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 1.19, 0.58, 0.22, 8, 8);
	glPopMatrix();
}

void drawTopOctagonWindows() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glLineWidth(1);
	glTranslatef(0, 2.1, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	Octagon(0.45, 1);
	glPopMatrix();
}

void drawChandelier() {
	glPushMatrix();
	glTranslatef(0, 1.8, 0.0);
	glRotatef(90.0, 1, 0, 0);
	glRotatef(67.5, 0.0, 0.0, 1.0);
	glutSolidCone(0.2, 1.2, 8, 1);
	glPopMatrix();
}

void drawBuilding2(int closeUp) {

	float silvercolor[] = { 0.7, 0.7, 0.7 };
	float blackcolor[] = { 0, 0, 0 };
	float darkgreencolor[] = { 0.5, 0.7, 0.6 };
	float windowSurface[] = { .1, .27, .46 };
	float redcolor[] = { 1, 0, 0 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, silvercolor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, silvercolor);

	
	if (closeUp) {
		glScalef(5, 5, 5);
		glTranslatef(0, -1.2, 0);
		glRotatef(-19, 0, 0.5, 0);
	}
	else {
		glPushMatrix();
		glScalef(0.25, 0.25, 0.25);
		glTranslatef(-12, 1.5, 0.6);
		glRotatef(-19, 0, 0.5, 0);
	}
	
	drawBaseBlocks();
	drawSideWall();
	drawBackWall();
	drawWindowOctagon();
	drawTopWindowOctagon();
	drawBottomWindowOctagon();
	drawSmallTopOctagon();
	drawTopRoof();
	drawCylinder();
	drawRoofPillars();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, redcolor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, redcolor);
	drawChandelier();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, darkgreencolor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, darkgreencolor);

	drawTopWindowBorders();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);

	drawTopOctagonWindows();

	// draw front, left and right windows, green and silver pillars
	for (int i = 0; i < 3; i++) {
		glPushMatrix();
		if (i == 1) {
			glRotatef(90, 0, 1, 0);
		}
		else if (i == 2) {
			glRotatef(-90, 0, 1, 0);
		}
		glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
		glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
		drawWindow();
		glDisable(GL_BLEND);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, darkgreencolor);
		glMaterialfv(GL_FRONT, GL_AMBIENT, darkgreencolor);
		drawGreenWindowPillars();
		if (i != 2) {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, silvercolor);
			glMaterialfv(GL_FRONT, GL_AMBIENT, silvercolor);
			drawSilverPillars();
		}
		glPopMatrix();
	}
	glPopMatrix();
}