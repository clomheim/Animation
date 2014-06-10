#include "drawBuildings.h"

#include "Angel.h"
#include <math.h>

const double PI = 3.141592653589793238463;
void archFace(int numPieces, double r, double z, vec4 normal);

//Matt Cookman
void drawBuilding5(int closeUp) {
	

	float yellowMat[] = { .75, .75, .75 };
	float redMat[] = { .58, .08, .04 };
	float glassMat[] = { .65, .86, .85 };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowMat);
	glPushMatrix();

	if (closeUp) {
		glScalef(6, 6, 6);
	}
	else {
		glTranslatef(.5, 3, 3.5);
	glRotatef(160.0, 0.0, 1.0, 0.0);
	glScalef(1.5, 2.0, 2.0);
	}

	
	
	
	glBegin(GL_TRIANGLES);


	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, yellowMat);
	glVertex3f(.5f, .5f, 0.0f);
	glVertex3f(1.0f, 1.5f, 0.0f);
	glVertex3f(1.5f, .5f, 0.0f);

	glVertex3f(.5f, .5f, 2.0f);
	glVertex3f(1.0f, 1.5f, 2.0f);
	glVertex3f(1.5f, .5f, 2.0f);

	glVertex3f(.5f, 1.4f, .80f);
	glVertex3f(.5f, 1.15f, .55f);
	glVertex3f(.5f, 1.15f, .95f);

	glVertex3f(.5f, 1.4f, 1.20f);
	glVertex3f(.5f, 1.15f, .95f);
	glVertex3f(.5f, 1.15f, 1.35f);



	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(.5f, .5f, 0.0f);
	glVertex3f(1.0f, 1.5f, 0.0f);
	glVertex3f(1.0f, 1.5f, 2.0f);
	glVertex3f(.5f, .5f, 2.0f);

	glVertex3f(1.5f, .5f, 0.0f);
	glVertex3f(1.0f, 1.5f, 0.0f);
	glVertex3f(1.0f, 1.5f, 2.0f);
	glVertex3f(1.5f, .5f, 2.0f);

	glVertex3f(.5f, 1.4f, .80f);
	glVertex3f(.5f, 1.15f, .55f);
	glVertex3f(1.0f, 1.15f, .55f);
	glVertex3f(1.0f, 1.4f, .80f);

	glVertex3f(.5f, 1.4f, .80f);
	glVertex3f(.5f, 1.15f, .95f);
	glVertex3f(1.0f, 1.15f, .80f);
	glVertex3f(1.0f, 1.4f, .95f);


	glVertex3f(.5f, 1.4f, 1.20f);
	glVertex3f(.5f, 1.15f, .95f);
	glVertex3f(1.0f, 1.15f, .95f);
	glVertex3f(1.0f, 1.4f, 1.20f);

	glVertex3f(.5f, 1.4f, 1.20f);
	glVertex3f(.5f, 1.15f, 1.35f);
	glVertex3f(1.0f, 1.15f, 1.35f);
	glVertex3f(1.0f, 1.4f, 1.20f);

	glVertex3f(.5f, .5f, 1.35f);
	glVertex3f(1.0f, .5f, 1.35f);
	glVertex3f(1.0f, 1.15f, 1.35f);
	glVertex3f(.5f, 1.15f, 1.35f);

	glVertex3f(.5f, .5f, .55f);
	glVertex3f(1.0f, .5f, .55f);
	glVertex3f(1.0f, 1.15f, .55f);
	glVertex3f(.5f, 1.15f, .55f);


	glVertex3f(.5f, .5f, .55f);
	glVertex3f(.5f, 1.15f, .55f);
	glVertex3f(.5f, 1.15f, 1.35f);
	glVertex3f(.5f, .5f, 1.35f);
	glEnd();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, redMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, redMat);
	glBegin(GL_TRIANGLES);
	glVertex3f(.60f, .60f, -0.005f);
	glVertex3f(1.0f, 1.30f, -0.005f);
	glVertex3f(1.4f, .60f, -0.005f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(.4995f, .60f, .65f);
	glVertex3f(.4995f, 1.05f, .65f);
	glVertex3f(.4995f, 1.05f, 1.25f);
	glVertex3f(.4995f, .6f, 1.25f);
	glEnd();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, glassMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, glassMat);
	float radius = .05;
	
	//glPushMatrix();
	//glTranslatef(0, 0, 0);
	glBegin(GL_POLYGON);
	
	for (double i = 0; i < 2 * PI; i += PI / 10) {
	glVertex3f(1.0+ cos(i) * radius,1.1 + sin(i) * (1.5*radius), -0.010);
	}
	glEnd();

	radius = .02;

	for (float j = .8; j <= 1.22; j += .07){
		glBegin(GL_POLYGON);

		for (double i = 0; i < 2 * PI; i += PI / 10) {
			glVertex3f( j+ cos(i) * radius, .8+sin(i) * (1.5*radius), -0.010);



		}
		glEnd();

		glBegin(GL_QUADS);

		glVertex3f(j + .02, .7, -0.010);
		glVertex3f(j - .02, .7, -0.010);
		glVertex3f(j - .02, .8, -0.010);
		glVertex3f(j + .02, .8, -0.010);








		glEnd();
	}
	
glEnd();

radius = .03;
glBegin(GL_POLYGON);
for (double i = 0; i < 2 * PI; i += PI / 10) {
	glVertex3f(.499, .9 + sin(i) * (1.5*radius), 1.2 + cos(i) * radius);
}
glEnd();

glBegin(GL_POLYGON);
for (double i = 0; i < 2 * PI; i += PI / 10) {
	glVertex3f(.499, .9 + sin(i) * (1.5*radius), .7 + cos(i) * radius);
}
glEnd();

glBegin(GL_QUADS);

glVertex3f(.499, .88, 1.23);
glVertex3f(.499, .88, 1.17);
glVertex3f(.499, .7, 1.17);
glVertex3f(.499, .7, 1.23);

glVertex3f(.499, .88, 0.73);
glVertex3f(.499, .88, 0.67);
glVertex3f(.499, .7, 0.67);
glVertex3f(.499, .7, 0.73);

glVertex3f(.499, .88, 0.85);
glVertex3f(.499, .88, 0.77);
glVertex3f(.499, .7, 0.77);
glVertex3f(.499, .7, 0.85);

glVertex3f(.499, .88, 1.0);
glVertex3f(.499, .88, 0.92);
glVertex3f(.499, .7, 0.92);
glVertex3f(.499, .7, 1.0);

glVertex3f(.499, .88, 1.14);
glVertex3f(.499, .88, 1.06);
glVertex3f(.499, .7, 1.06);
glVertex3f(.499, .7, 1.14);






glEnd();


//glPopMatrix();
 glPopMatrix();

}

static  void archFace(int numPieces, double r, double z, vec4 normal) {
	int i;
	double angle = 0, angInc = PI / numPieces;
	angle = 0;
	glNormal3f(normal.x, normal.y, normal.z);
	for (i = 0; i < numPieces / 2; i++) {
		glBegin(GL_POLYGON);
		//glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(r, 0, z);
		glVertex3f(r*cos(angle), r*sin(angle) - 0.5, z);
		glVertex3f(r*cos(angle + angInc), r*sin(angle + angInc) - 0.5, z);
		glEnd();
		glBegin(GL_POLYGON);
		//glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(-r, 0, z);
		glVertex3f(r*cos(PI / 2 + angle), r*sin(PI / 2 + angle) - 0.5, z);
		glVertex3f(r*cos(PI / 2 + angle + angInc), r*sin(PI / 2 + angle + angInc) - 0.5, z);
		glEnd();
		angle += angInc;
	}
	glBegin(GL_POLYGON);
	glVertex3f(-r, 0, z);
	glVertex3f(0, 0, z);
	glVertex3f(r, 0, z);
	glBegin(GL_POLYGON);
	glEnd();
}
