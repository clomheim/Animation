//Caleb DelVillar-Fox


#include "drawBuildings.h"

#include "Angel.h"

#define WINDOW_WIDTH        0.106
#define WINDOW_HEIGHT       0.18

void window(float wid);
void windowSet(int num);
void windowCross();
void windowHoriz();
void specialWindowSet(int num);

void drawBuilding14(int closeUp) {

	float yellowMat[] = { .75, .1, .1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, yellowMat);

	if (closeUp) {
		glScalef(6, 6, 6);
	}
	else {
		glRotatef(180, 0, 1, 0);
		glScalef(.7, .8, .7);
		glTranslatef(2.39, .5, -3.8);
	}

	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();


	float grayMat[] = { .75, .75, .75 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grayMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, grayMat);
	glBegin(GL_POLYGON);
	glVertex3f(-0.501f, -0.5f, 0.5f);
	glVertex3f(-0.501f, -0.1f, 0.5f);
	glVertex3f(-0.501f, -0.1f, -0.5f);
	glVertex3f(-0.501f, -0.5f, -0.5f);
	glVertex3f(-0.501f, -0.5f, 0.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.5f, -0.5f, 0.50001f);
	glVertex3f(0.501f, -0.5f, 0.50001f);
	glVertex3f(0.5f, -0.1f, 0.50001f);
	glVertex3f(-0.501f, -0.1f, 0.50001f);
	//glVertex3f(-0.501f, -0.5f, 0.50001f);
	glEnd();


	glPushMatrix();
	glTranslatef(-0.45, -0.05, 0.5001);
	specialWindowSet(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.045, -0.05, 0.5001);
	specialWindowSet(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.45, 0.2, 0.5001);
	specialWindowSet(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.045, 0.2, 0.5001);
	specialWindowSet(4);
	glPopMatrix();


	//awning
	glPushMatrix();
	float whiteMat[] = { 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, whiteMat);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5f, -0.17f, 0.7f);
	glVertex3f(0.5f, -0.17f, 0.7f);
	glVertex3f(0.5f, -0.1f, 0.51f);
	glVertex3f(-0.5f, -0.1f, 0.51f);
	//glVertex3f(-0.501f, -0.5f, 0.50001f);
	glEnd();
	glPopMatrix();

	//bottom floor windows
	glPushMatrix();
	glTranslatef(-.43f, -.46f, 0.511f);
	windowSet(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15f, -.46f, 0.511f);
	windowSet(2);
	glPopMatrix();
}

void window(float wid){
	glPushMatrix();
	float winMat[] = { .0, .9, .91 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, winMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, winMat);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(WINDOW_WIDTH, 0.0f, 0.0f);
	glVertex3f(WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f);
	glVertex3f(0.0f, WINDOW_HEIGHT, 0.0f);
	//glVertex3f(-0.501f, -0.5f, 0.5f);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	windowCross();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(WINDOW_WIDTH - WINDOW_WIDTH/8, 0, 0);
	windowCross();
	glPopMatrix();

	glPushMatrix();
	windowHoriz();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, WINDOW_HEIGHT, 0);
	windowHoriz();
	glPopMatrix();

}

void windowCross(){
	glPushMatrix();
	float barMat[] = { 0.0, .9, 0.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, barMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, barMat);
	glTranslatef(WINDOW_WIDTH/16, WINDOW_HEIGHT / 2, 0);
	glScalef(WINDOW_WIDTH / 8, WINDOW_HEIGHT, .07);
	glutSolidCube(1);
	glPopMatrix();
}

void windowHoriz(){
	glPushMatrix();
	float barMat[] = { 0.0, 0.9, 0.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, barMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, barMat);
	glTranslatef(WINDOW_WIDTH / 2, 0, 0);
	glScalef(WINDOW_WIDTH, WINDOW_HEIGHT/10, .07);
	glutSolidCube(1);
	glPopMatrix();
}

void windowSet(int num) {
	glPushMatrix();
	int i = 0;
	for (i = 0; i < num; i++){
		glPushMatrix();
		glTranslatef(i*WINDOW_WIDTH, 0, 0);
		window(WINDOW_WIDTH);
		glPopMatrix();
	}
	glPopMatrix();
}

void specialWindowSet(int num) {
	int i = 0;
	glPushMatrix();
	windowSet(num);
	glPopMatrix();
	for (i = 0; i < num; i++){
		glPushMatrix();
		glTranslatef(i*WINDOW_WIDTH, WINDOW_HEIGHT - 2*(WINDOW_HEIGHT/5), 0.018);
		glScalef(.25, .2, 0.0);
		windowSet(num);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(i*WINDOW_WIDTH, WINDOW_HEIGHT - WINDOW_HEIGHT / 5, 0.018);
		glScalef(.25, .2, 0.0);
		windowSet(num);
		glPopMatrix();
	}
}