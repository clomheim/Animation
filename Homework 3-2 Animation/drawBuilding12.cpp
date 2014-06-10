/**
* Author: Thiago Henrique Deicke
* Course: Computer Graphics
* Date: 03/03/2014
* Professor: John Mayer
*
* PROJECT 3 MILESTONE 1 - BUILDING #12
**/

#include "drawBuildings.h"

#include "Angel.h"


//material colors to be used in the building

float GrayMat[] = { 0.7, 0.7, 0.7 };
float GrayMat2[] = { 0.6, 0.6, 0.6 };
float GrayMat3[] = { 0.8, 0.8, 0.8 };
float GrayMat4[] = { 0.9, 0.9, 0.9 };
float windowSurface[] = { 0.17, 0.27, 0.40 }; 
float windowSurface2[] = { 0.4, 0.4, 0.4 };


void drawCasca(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat);

	//top-small-details

	glPushMatrix();
	glTranslatef(1.15, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.15, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.82142, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.49285, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.16428, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.82142, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.49285, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.16428, 0.36, -0.45);
	glScalef(0.005, 0.02, 0.125);
	glutSolidCube(2);
	glPopMatrix();
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat2);

	//top-detail
	glPushMatrix();
	glTranslatef(0, .425, -2.2);
	glScalef(1.33, .01, 1.91);
	glutSolidCube(2);
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslatef(0, .4, -2.2);
	glScalef(1.32, .01, 1.9);
	glutSolidCube(2);
	glPopMatrix();	


	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat);

	//top-base
	glPushMatrix();
	glTranslatef(0, 0.37, -2.3);
	glScalef(1.2, .03, 1.74);
	glutSolidCube(2);
	glPopMatrix();

	//2nd floor
	glPushMatrix();
	glTranslatef(0, -.61, -2.3);
	glScalef(1.2, .04, 1.74);
	glutSolidCube(2);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat2);
	//2nd floor - detail
	glPushMatrix();
	glTranslatef(0, -.67, -2.3);
	glScalef(1.12, .02, 1.66);
	glutSolidCube(2);
	glPopMatrix();

	//1st floor
	glPushMatrix();
	glTranslatef(0, -1.23, -2.6);
	glScalef(1.2, .02, 1.5);
	glutSolidCube(2);
	glPopMatrix();

	//left wall
	glPushMatrix();
	glTranslatef(-1.2, -0.43, -2.6);
	glScalef(.05, 0.82, 1.5);
	glutSolidCube(2);
	glPopMatrix();

	//right wall
	glPushMatrix();
	glTranslatef(1.2, -0.43, -2.6);
	glScalef(.05, 0.82, 1.5);
	glutSolidCube(2);
	glPopMatrix();

	//back wall
	glPushMatrix();
	glTranslatef(0, -0.42, -4.05);
	glScalef(1.2, 0.82, 0.05);
	glutSolidCube(2);
	glPopMatrix();
	
	//middle-down-wall left

	glPushMatrix();
	glTranslatef(1, -0.95, -1.14);
	glScalef(0.25, 0.28, 0.04);
	glutSolidCube(2);
	glPopMatrix();

	//middle-down-wall right
	glPushMatrix();
	glTranslatef(-1, -0.95, -1.14);
	glScalef(0.25, 0.28, 0.04);
	glutSolidCube(2);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat4);

	//door

	glPushMatrix();
	glTranslatef(-1.03, -1.02, -1.13);
	glScalef(0.1, 0.185, 0.04);
	glutSolidCube(2);
	glPopMatrix();

}

void drawGridingUp(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat3);

	//vertical

	glPushMatrix();
	glTranslatef(1.19, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.19, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, -0.12, -0.57);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	//vertical-lateral

	glPushMatrix();
	glTranslatef(1.19, -0.12, -1.09);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.19, -0.12, -1.09);
	glScalef(0.008, 0.45, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	//horizontal

	glPushMatrix();
	glTranslatef(0, 0.065, -0.57);
	glScalef(1.2, 0.008, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.35, -0.57);
	glScalef(1.2, 0.008, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	//horizontal-lateral

	glPushMatrix();
	glTranslatef(1.19, 0.065, -0.87);
	glScalef(0.008, 0.008, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.19, 0.065, -0.87);
	glScalef(0.008, 0.008, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.19, -0.35, -0.87);
	glScalef(0.008, 0.008, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.19, -0.35, -0.87);
	glScalef(0.008, 0.008, 0.3);
	glutSolidCube(2);
	glPopMatrix();

}

void drawGridingDown(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, GrayMat3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, GrayMat3);

	//vertical

	glPushMatrix();
	glTranslatef(0.008, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.008, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.744, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.744, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.186, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.186, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.372, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.372, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.558, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.558, -0.95, -1.11);
	glScalef(0.008, 0.3, 0.008);
	glutSolidCube(2);
	glPopMatrix();

	//horizontal

	glPushMatrix();
	glTranslatef(0, -1.05, -1.11);
	glScalef(0.8, 0.008, 0.008);
	glutSolidCube(2);
	glPopMatrix();

}

void drawWndw(){
	
		//enable blending for translucent effect
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	//BLUE WINDOW

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);

	glPushMatrix();
	glTranslatef(0, -0.95, -1.11);
	glScalef(0.8, 0.3, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.1, -0.57);
	glScalef(0.6, 0.5, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.045, -0.14, -0.57);
	glScalef(0.15, 0.2, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.045, -0.14, -0.57);
	glScalef(0.15, 0.2, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	//LATERAL BLUE WINDOWS

	glPushMatrix();
	glTranslatef(-1.19, -0.14, -0.83);
	glScalef(0.0008, 0.2, 0.26);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.19, -0.14, -0.83);
	glScalef(0.0008, 0.2, 0.26);
	glutSolidCube(2);
	glPopMatrix();

	//GRAY WINDOW

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface2);

	glPushMatrix();
	glTranslatef(0.75, -0.1, -0.57);
	glScalef(0.16, 0.5, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, -0.1, -0.57);
	glScalef(0.16, 0.5, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.045, 0.205, -0.57);
	glScalef(0.15, 0.135, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.045, 0.205, -0.57);
	glScalef(0.15, 0.135, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.045, -0.47, -0.57);
	glScalef(0.15, 0.12, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.045, -0.47, -0.57);
	glScalef(0.15, 0.12, 0.0008);
	glutSolidCube(2);
	glPopMatrix();

	//LATERAL-GRAY WINDOWS

	glPushMatrix();
	glTranslatef(-1.19, 0.1935, -0.83);
	glScalef(0.0008, 0.14, 0.26);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.19, 0.1935, -0.83);
	glScalef(0.0008, 0.14, 0.26);
	glutSolidCube(2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-1.19, -0.47, -0.83);
	glScalef(0.0008, 0.12, 0.26);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.19, -0.47, -0.83);
	glScalef(0.0008, 0.12, 0.26);
	glutSolidCube(2);
	glPopMatrix();


	//disable blending
	glDisable(GL_BLEND);

}

void drawBuilding12(int closeUp) {
     if (closeUp) {
	   glScalef(6, 6, 6);
	   glTranslatef(+0.5, 0.5, -0.8);
   }
   else {
	   glScalef(0.3, 0.36, 0.38);
	   glTranslatef(-7.5, 1.3, 9.8);
	   glRotatef(180, 0, 1, 0);
	   glTranslatef(0.9, 0, 4.6);
   }
   drawCasca();
   drawGridingUp();
   drawGridingDown();
   drawWndw();
}