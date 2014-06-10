#include "drawBuildings.h"
#include<stdio.h>
#include <iostream>
#include <string>
#include <Math.h>
#include "Angel.h"

//Name: Ricardo Goes de Meira
float gray13[] = { .60, .60, .60};
float lightGray13[] = { .8, .8, .8};
float white13[] = {1,1,1};
float black13[] = {0,0,0};
float windowSurface13[] = { .1, .27, .46 };
#define PI 3.14159265



void postOutside(){
	glPushMatrix();
	glScalef(0.008, 0.13, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);

	glPushMatrix();
	glScalef(0.008, 0.13, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.008, 0.13, 0.01);
	glutSolidCube(1);
	glPopMatrix();
}

void doorHandle(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);

	glPushMatrix();
	glScalef(0.046, 0.6, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(-0.09, 0.0, 0);
	glScalef(0.046, 0.6, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.046, 0.6, 0.01);
	glutSolidCube(1);
	glPopMatrix();*/
}

void glass13long(){
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, white13);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, white13);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface13);

//enable blending for translucent effect
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
	
	glPushMatrix();
	glScalef(0.046, 0.13, 0.01);
	glutSolidCube(1);
	glPopMatrix();

//disable blending
    glDisable(GL_BLEND);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);
}

void glass13long2(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface13);

//enable blending for translucent effect
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
	
	glPushMatrix();
	glScalef(0.087, 0.06, 0.01);
	glutSolidCube(1);
	glPopMatrix();

//disable blending
    glDisable(GL_BLEND);
}

void glass13long3(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface13);

//enable blending for translucent effect
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
	
	glPushMatrix();
	glScalef(0.046, 0.205, 0.01);
	glutSolidCube(1);
	glPopMatrix();

//disable blending
    glDisable(GL_BLEND);
}

void glass13big(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface13);

//enable blending for translucent effect
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
	
	glPushMatrix();
	glScalef(0.087, 0.205, 0.01);
	glutSolidCube(1);
	glPopMatrix();

//disable blending
    glDisable(GL_BLEND);
}

void glass13small(){
	//small glass windows
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, white13);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, white13);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface13);

//enable blending for translucent effect
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
	
	glPushMatrix();
	glScalef(0.046, 0.06, 0.01);
	glutSolidCube(1);
	glPopMatrix();

//disable blending
    glDisable(GL_BLEND);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);
}

void door13(){
	//top glass
	glPushMatrix();
	glTranslatef(0, 0.05, 0);
	glass13small();
	glPopMatrix();

	//bottom glass
	glPushMatrix();
	glTranslatef(0, 0.149, 0);
	glScalef(1,0.8,1);
	glass13long();
	glPopMatrix();
}

void clock13(){
	
	float x1,y1,x2,y2;
	float angle;
	double radius=0.1;
 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);

	x1 = 0.5,y1=0.6;
 
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
 
	for(angle=0.0f ; angle<3*PI ; angle+=0.2){
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}
 
	glEnd();
}

void connectionLongTop(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);

	glPushMatrix();
	glScalef(0.3, 0.02, 0.01);
	glutSolidCube(1);
	glPopMatrix();
}

void connectionTop(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightGray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, lightGray13);

	glPushMatrix();
	glScalef(0.006, 0.32, 0.01);
	glutSolidCube(1);
	glPopMatrix();
}

void topPart13(){
	//small glass bottom-left
	glPushMatrix();
	glTranslatef(-0.118, 0.32,  0.36);
	glass13small();
	glPopMatrix();

	//small glass bottom-right
	glPushMatrix();
	glTranslatef(0.118, 0.32,  0.36);
	glass13small();
	glPopMatrix();

	//long glass bottom-left
	glPushMatrix();
	glTranslatef(-0.046, 0.32,  0.36);
	glass13long2();
	glPopMatrix();

	//long glass bottom right
	glPushMatrix();
	glTranslatef(0.046, 0.32,  0.36);
	glass13long2();
	glPopMatrix();

	//big glass top right
	glPushMatrix();
	glTranslatef(-0.046, 0.47,  0.36);
	glass13big();
	glPopMatrix();

	//big glass top left	
	glPushMatrix();
	glTranslatef(0.046, 0.47,  0.36);
	glass13big();
	glPopMatrix();

	//long glass top left
	glPushMatrix();
	glTranslatef(-0.118, 0.47,  0.36);
	glass13long3();
	glPopMatrix();

	//long glass top right
	glPushMatrix();
	glTranslatef(0.118, 0.47,  0.36);
	glass13long3();
	glPopMatrix();

	//connectionTopOne
	glPushMatrix();
	glTranslatef(0, 0.58,  0.37);
	connectionLongTop();
	glPopMatrix();

	//connectionMidleOne
	glPushMatrix();
	glTranslatef(0, 0.36,  0.37);
	connectionLongTop();
	glPopMatrix();

	//connectionBottomOne
	glPushMatrix();
	glTranslatef(0, 0.286,  0.37);
	connectionLongTop();
	glPopMatrix();

	//connectionMidleOneVertical
	glPushMatrix();
	glTranslatef(0, 0.43,  0.37);
	connectionTop();
	glPopMatrix();

	//connectionLeftMidleOneVertical
	glPushMatrix();
	glTranslatef(-0.092, 0.43,  0.37);
	connectionTop();
	glPopMatrix();

	//connectionLeftVertical
	glPushMatrix();
	glTranslatef(-0.14, 0.43,  0.37);
	connectionTop();
	glPopMatrix();

	//connectionRightMidleOneVertical
	glPushMatrix();
	glTranslatef(0.092, 0.43,  0.37);
	connectionTop();
	glPopMatrix();

	//connectionRightVertical
	glPushMatrix();
	glTranslatef(0.14, 0.43,  0.37);
	connectionTop();
	glPopMatrix();

	//collumn in the midlle
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);

	glPushMatrix();
	glTranslatef(0.01, 0.43,  0.369);
	glScalef(0.014, 0.32, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	//connection to the clock
	glPushMatrix();
	glTranslatef(-0.02, 0.43,  0.369);
	glScalef(0.05, 0.014, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	//clock
	glPushMatrix();
	glTranslatef(-0.19, 0.25,  0.371);
	//0.3
	glScalef(0.3, 0.3, 2);
	clock13();
	glPopMatrix();
}

void midPart13(){
	char text[25]= "WILLIAM W. PHILIP HALL";
	//midle floor
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);
	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glScalef(0.3, 0.06, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.25, 0.33);
	glScalef(0.3, 0.06, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//letters WILLIAM W. PHILIP HALL

	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);
	glPushMatrix();
	glTranslatef(-0.145, 0.23, 0.381);
	glScalef(0.000182,0.0004, 0.00001);
	glLineWidth(1);
	for( char* p = text; *p; p++){
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	}
	glPopMatrix();
	
}

void bottomPart13(){	

	//left-bottom glass
	glPushMatrix();
	glTranslatef(-0.118, 0.04, 0.32);
	glass13small();
	glPopMatrix();
	
	//left-top glass
	glPushMatrix();
	glTranslatef(-0.118, 0.147, 0.32);
	glass13long();
	glPopMatrix();

	//right-bottom glass
	glPushMatrix();
	glTranslatef(0.118, 0.04, 0.32);
	glass13small();
	glPopMatrix();

	//right-top glass
	glPushMatrix();
	glTranslatef(0.118, 0.147, 0.32);
	glass13long();
	glPopMatrix();

	//left door
	glPushMatrix();
	glTranslatef(-0.068, 0.0, 0.32);
	door13();
	glPopMatrix();

	//left door second part
	glPushMatrix();
	glTranslatef(-0.016, 0.0, 0.32);
	door13();
	glPopMatrix();

	//right door
	glPushMatrix();
	glTranslatef(0.066, 0.0, 0.32);
	door13();
	glPopMatrix();

	//wall in the midlle
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);

	glTranslatef(0.027, 0.12, 0.331);
	glScalef(0.025, 0.238, 0.01);
	glutSolidCube(1);
	glPopMatrix();
	
	//connection left one
	glPushMatrix();

	glTranslatef(-0.14, 0.12,  0.33);
	glScalef(1, 0.75, 1);
	connectionTop();
	glPopMatrix();

	//connection bottom one
	glPushMatrix();

	glTranslatef(0, 0.01,  0.33);
	connectionLongTop();
	glPopMatrix();

	//connection top one
	glPushMatrix();

	glTranslatef(0, 0.21,  0.33);
	connectionLongTop();
	glPopMatrix();

	//connection right one
	glPushMatrix();

	glTranslatef(0.14, 0.12,  0.33);
	glScalef(1, 0.75, 1);
	connectionTop();
	glPopMatrix();

	//connection center-left one
	glPushMatrix();

	glTranslatef(-0.092, 0.12,  0.33);
	glScalef(1, 0.75, 1);
	connectionTop();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, black13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, black13);

	glPushMatrix();
	glTranslatef(-0.092, 0.12,  0.332);
	glScalef(0.006, 0.32, 0.01);
	glScalef(0.09, 0.75, 1);
	glutSolidCube(1);
	glPopMatrix();

	//connection center-right one
	glPushMatrix();

	glTranslatef(0.092, 0.12,  0.33);
	glScalef(1, 0.75, 1);
	connectionTop();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, black13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, black13);

	glPushMatrix();
	glTranslatef(0.092, 0.12,  0.332);
	glScalef(0.006, 0.32, 0.01);
	glScalef(0.09, 0.75, 1);
	glutSolidCube(1);
	glPopMatrix();


	//connection door one
	glPushMatrix();

	glTranslatef(-0.042, 0.12,  0.33);
	glScalef(1, 0.75, 1);
	connectionTop();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, black13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, black13);

	glPushMatrix();
	glTranslatef(-0.042, 0.12,  0.332);
	glScalef(0.006, 0.32, 0.01);
	glScalef(0.09, 0.75, 1);
	glutSolidCube(1);
	glPopMatrix();

	//connection midlle one
	glPushMatrix();

	glTranslatef(0.011, 0.12,  0.33);
	glScalef(1.3, 0.75, 1);
	connectionTop();
	glPopMatrix();

		glMaterialfv(GL_FRONT, GL_DIFFUSE, black13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, black13);

	glPushMatrix();
	glTranslatef(0.011, 0.12,  0.332);
	glScalef(0.006, 0.32, 0.01);
	glScalef(0.09, 0.75, 1);
	glutSolidCube(1);
	glPopMatrix();


	//connection right-midlle one
	glPushMatrix();

	glTranslatef(0.04, 0.12,  0.33);
	glScalef(1, 0.75, 1);
	connectionTop();
	glPopMatrix();
	//connection horizontal left midlle one
	glPushMatrix();
	glTranslatef(0,0.089,0.33);
	glScalef(0.63, 0.75, 1);
	connectionLongTop();
	glPopMatrix();

	//connection horizontal left bot
	glPushMatrix();
	glTranslatef(-0.06,0.076,0.33);
	glScalef(0.57, 0.75, 1);
	connectionLongTop();
	glPopMatrix();

	//connection horizontal right bot
	glPushMatrix();
	glTranslatef(0.06,0.076,0.33);
	glScalef(0.57, 0.75, 1);
	connectionLongTop();
	glPopMatrix();

	//post outside
	glPushMatrix();
	glTranslatef(0.12,0.068,0.37);
	postOutside();
	glPopMatrix();
}

void sideLeft13(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);
	glPushMatrix();
	glTranslatef(-0.148, 0.3, 0);
	glScalef(0.01, 0.6, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.148, 0.41, 0.33);
	glScalef(0.01, 0.38, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void sideRight13(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);
	glPushMatrix();
	glTranslatef(0.148, 0.3, 0);
	glScalef(0.01, 0.6, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.148, 0.41, 0.33);
	glScalef(0.01, 0.38, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void back13(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);
	glPushMatrix();
	glTranslatef(0, 0.3, -0.337);
	glScalef(0.306, 0.6, 0.03);
	glutSolidCube(1);
	glPopMatrix();
}

void ceiling13(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray13);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray13);

	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(0.306, 0.01, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.6, 0.33);
	glScalef(0.306, 0.01, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void building13(){
	sideLeft13();
	sideRight13();
	ceiling13();
	back13();
	midPart13();
	bottomPart13();
	topPart13();
}

void drawBuilding13(int closeUp) {
       // Philip Hall entry way 
   //closeUp=1;

   if (closeUp) {
	   glScalef(15, 15, 15);
	   //glTranslatef(-0.2, 0, 2);
	   glTranslatef(-0.2, 0, 0);
   } else {
	   glScalef(1, 1, 1);
	   glTranslatef(-3.1,0,2.8);
	   glRotatef(180, 0, 1, 0);
   }

   building13();
   //glutSolidCube(1);
}