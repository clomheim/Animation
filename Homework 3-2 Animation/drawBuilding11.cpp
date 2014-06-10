#include "drawBuildings.h"

#include "Angel.h"

//Christopher Mun
//Cherry Parkes
void drawBuilding11(int closeUp) {

	if (closeUp) {
		glScalef(6, 6, 6);
	}
	else {
		glTranslatef(-4.75, 1.25, 4.75);
		glScalef(0.8, 0.8, 1);
		glRotatef(180, 0, 1, 0);
	}

	float brickMat[] = {0.69, 0.31, 0.31};
	float frameMat[] = {0.4, 0.4, 0.4};
	float glassMat[] = {0.88, 1, 1};
	float drainMat[] = {0.16, 0.16, 0.16};
	float purpleMat[] = {0.65, 0.21, 255};

		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);

		glPushMatrix();//column
			glScalef(0.2, 3, 0.2);
			glTranslatef(-8.5, 0, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();//column
			glScalef(0.2, 3, 0.2);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();//column
			glScalef(0.2, 3, 0.2);
			glTranslatef(8.5, 0, 0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();//top beam
			glScalef(3.5, 0.3, 0.2);
			glTranslatef(0, 4.5, 0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();//middle beam
			glScalef(3.5, 0.2, 0.2);
			glTranslatef(0, 2, 0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();//bottom beam
			glScalef(3.5, 0.2, 0.2);
			glTranslatef(0, -2.5, 0);
			glutSolidCube(1);
		glPopMatrix();

		//brick window border
		glPushMatrix();
			glScalef(0.1, 2, 0.2);
			glTranslatef(-4.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.1, 2, 0.2);
			glTranslatef(-8.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.1, 2, 0.2);
			glTranslatef(-12.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.1, 2, 0.2);
			glTranslatef(4.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.1, 2, 0.2);
			glTranslatef(8.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.1, 2, 0.2);
			glTranslatef(12.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();

		//window frames
		glMaterialfv(GL_FRONT, GL_DIFFUSE, frameMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, frameMat);
		//rows
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 14.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, -19.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 25.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 59.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 42.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, -2.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, -12, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 6, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 51, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, 33, 0);
			glutSolidCube(1);
		glPopMatrix();


		//columns
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-12.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-32.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-52.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-72.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(12.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(32.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(52.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(72.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		//border columns left
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-5.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-19.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-25.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-39.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-45.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-59.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-65.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-79.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-12.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-32.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-52.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(-72.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(12.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(32.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(52.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(72.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		//border columns right
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(5.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(19.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(25.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(39.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(45.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(59.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(65.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.02, 2, 0.15);
			glTranslatef(79.5, 0.25, 0);
			glutSolidCube(1);
		glPopMatrix();
		//door areas
		glPushMatrix();
			glScalef(3.5, 0.02, 0.15);
			glTranslatef(0, -40, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(1, 0.02, 0.15);
			glTranslatef(-1.2, -65, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.9, 0.02, 0.15);
			glTranslatef(1.3, -65, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.7, 0.04, 0.15);
			glTranslatef(-0.5, -20.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 1, 0.15);
			glTranslatef(-9, -1, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 1, 0.15);
			glTranslatef(-16, -1, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 1, 0.15);
			glTranslatef(-20, -1, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 1, 0.15);
			glTranslatef(2.5, -1, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.6, 0.04, 0.15);
			glTranslatef(0.8, -20.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 1, 0.15);
			glTranslatef(10, -1, 0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.075, 1, 0.15);
			glTranslatef(17, -1, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.6, 0.05, 0.15);
			glTranslatef(0.8, -29.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.6, 0.05, 0.15);
			glTranslatef(-0.65, -29.5, 0);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.08, 0.65, 0.15);
			glTranslatef(5.75, -1.8, 0);
			glutSolidCube(1);
		//glPopMatrix();  jm fix
		glPopMatrix();
		glPushMatrix();
			glScalef(0.08, 0.65, 0.15);
			glTranslatef(-5, -1.8, 0);
			glutSolidCube(1);
		glPopMatrix();
		//glPopMatrix();  jm fix 2
		glPushMatrix();
			glScalef(0.08, 0.65, 0.15);
			glTranslatef(-1.5, -1.8, 0);
			glutSolidCube(1);
		glPopMatrix();



		//GLASS
		glMaterialfv(GL_FRONT, GL_DIFFUSE, glassMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, glassMat);
		glPushMatrix();
			glScalef(3.5, 3, 0.075);
			glTranslatef(0, 0, 0);
			glutSolidCube(1);
		glPopMatrix();


        /*
		//DRAINS
		glMaterialfv(GL_FRONT, GL_DIFFUSE, drainMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, drainMat);
		glPushMatrix();
			glScalef(0.2, 0.1, 0.1);
			glTranslatef(0, 12.5, 1);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.15, 0.1, 0.07);
			glTranslatef(0, 12, 1.3);
			glutSolidCube(1);
		glPopMatrix();

		glPopMatrix();
			glPushMatrix();
			glScalef(0.2, 0.1, 0.1);
			glTranslatef(-8.5, 3.75, 1);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.15, 0.1, 0.07);
			glTranslatef(-11.375, 3.1, 1.3);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 2.75, 0.07);
			glTranslatef(0, -0.045, 1.3);
			glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
			glScalef(0.075, 1.8, 0.07);
			glTranslatef(-22.75, -0.335, 1.3);
			glutSolidCube(1);
		glPopMatrix();

		//SIGN
		glMaterialfv(GL_FRONT, GL_DIFFUSE, purpleMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, purpleMat);
		glPushMatrix();
			glScalef(0.2, 0.2, 0.07);
			glTranslatef(8.5, -6, 1.3);
			glutSolidCube(1);
		glPopMatrix();


        
		//Back of building
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
		glPushMatrix();
			glScalef(3.5, 3, 4);
			glTranslatef(0, 0, -0.5);
			glutSolidCube(1);
		glPopMatrix();
        */
}