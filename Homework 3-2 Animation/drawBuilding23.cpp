/*
* Building 23
* Dustin Striplin
*
*/


#include <stdio.h>
#include <math.h>

#include "drawBuildings.h"

#include "Angel.h"

//prototypes
void constructBuilding();
void constructLeftSide();
void constructRightSide();
void constructSquatWindow();
void constructThinWindow();
void constructDoubleWindow();
void constructLeftDoor();
void constructRightDoor();
void constructGutter(int);
void constructStairs();
void constructCar();
void constructGenericWindow();
void constructLeftWindows();
float calculateRadius(float, float);

float imageSizeInPixels = 4509.1;
float leftSideWidth = 3363.1;
float leftSideHeight = 697;
float rightSideWidth = 1146;
float rightSideHeight = 543;

float numColors = 256;
float brick_color[] = {87/numColors, 51/numColors, 39/numColors};
float stone_color[] = {139/numColors, 140/numColors, 122/numColors};
float window_color[] = {135/numColors,206/numColors,250/numColors};
float trim_color[] = {50/numColors,45/numColors,42/numColors};
float concrete_color[] = {200/numColors,200/numColors,200/numColors};
float car_colors[] = {0/numColors,100/numColors,0/numColors};
float tire_color[] = {.1,.1,.1};

void drawBuilding23(int closeUp) {
       // the Harmon

	//glEnable(GL_BLEND); // Enable the OpenGL Blending functionality  


	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);

	glPushMatrix();
	if (closeUp) {

		glScalef(40,40,40);
	} else {
		glTranslatef(-8.8,1.1,.85);
		glRotatef(150, 0,1,0);
		glScalef(2.45,8.2,1);
	}
		

	constructBuilding();

	glPushMatrix();
	glTranslatef(-.4,-.125,.13);
	glScalef(.1,.1,.1);
	glRotatef(90,0,1,0);
	constructCar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-.125,.13);
	glScalef(.1,.1,.1);
	glRotatef(90,0,1,0);
	constructCar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.4,-.125,.13);
	glScalef(.1,.1,.1);
	glRotatef(90,0,1,0);
	constructCar();
	glPopMatrix();


	glPopMatrix();
	//glPushAttrib(GL_COLOR_MATERIAL);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
	//glutSolidCube(1);
	//glPopAttrib();
}

void constructBuilding() {
	float leftScaleWidth = leftSideWidth/imageSizeInPixels;
	float leftScaleHeight = leftSideHeight/imageSizeInPixels;
	float rightScaleWidth = rightSideWidth/imageSizeInPixels;
	float rightScaleHeight = rightSideHeight/imageSizeInPixels;

	glPushMatrix();
	glTranslatef(.5-leftScaleWidth,0,0);
	glScalef(leftScaleWidth,leftScaleHeight,1);
	constructLeftSide();
	glPopMatrix();

	//glPushMatrix();
	//glTranslatef(.5+rightScaleWidth,-(leftScaleHeight-rightScaleHeight),0); //move in line with the left side
	//glScalef(rightScaleWidth,rightScaleHeight,1);
	//constructRightSide();
	//glPopMatrix();

}



void constructLeftSide() {


	//trim on top of building
	glPushAttrib(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	glPushMatrix();
	glTranslatef(0,1,0);
	glScalef(2,.1,.01);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();

	//concrete foundation
	glPushAttrib(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, concrete_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, concrete_color);
	glNormal3f(0,0,1);
	glPushMatrix();
	glTranslatef(0,-1+.1,0.001);
	glScalef(1,.1,.1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();
	glPopMatrix();
	glPopAttrib();

	//draw brick above windows
	glNormal3f(0,0,1);
	glPushMatrix();
	glTranslatef(0,.95,0);
	glScalef(1,.1,1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();
	glPopMatrix();
	glPopAttrib();

	//draw brick below windows
	glPushMatrix();
	glTranslatef(0,-.62,0);
	glScalef(1,.2,1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();
	glPopMatrix();
	glPopAttrib();

	//draw brick on left side
	glPushMatrix();
	glTranslatef(-1+.07,0,0);
	glScalef(.07,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();
	glPopMatrix();
	glPopAttrib();

	//draw brick on right side
	glPushMatrix();
	glTranslatef(1-.02,0,0);
	glScalef(.02,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();
	glPopMatrix();
	glPopAttrib();

	//draw windows & area between windows
	int i = 0;
	for(; i < 19; i++) {
		glPushMatrix();
		glTranslatef(-.85+i/10.0,.7,0);
		glScalef(.1, .1, .1);
		constructThinWindow();

		//brick between top and middle row
		glNormal3f(0,0,1);
		glPushMatrix();
		glTranslatef(0,-2.3,0);
		glScalef(.1,1.2,1);
		glBegin(GL_POLYGON);
		glVertex3f(-1,-1,0);  // corner
		glVertex3f(1 ,-1,0);
		glVertex3f(1,1,0);
		glVertex3f(-1,1,0);
		glEnd();
		glPopMatrix();



		glTranslatef(0,-5,0);
		constructThinWindow();
		//brick between top and middle row
		glNormal3f(0,0,1);
		glPushMatrix();
		glTranslatef(0,-2.3,0);
		glScalef(.1,1.2,1);
		glBegin(GL_POLYGON);
		glVertex3f(-1,-1,0);  // corner
		glVertex3f(1 ,-1,0);
		glVertex3f(1,1,0);
		glVertex3f(-1,1,0);
		glEnd();
		glPopMatrix();
		glTranslatef(0,-5,0);
		constructThinWindow();

		glPopMatrix();

		if(i < 18) {
			glNormal3f(0,0,1);
			glPushMatrix();
			glTranslatef(-.8+i/10.0,0,0);
			glScalef(.04,1,1);
			glBegin(GL_POLYGON);
			glVertex3f(-1,-1,0);  // corner
			glVertex3f(1 ,-1,0);
			glVertex3f(1,1,0);
			glVertex3f(-1,1,0);
			glEnd();
			glPopMatrix();
		}
	}
}



void constructRightSide() {
	glNormal3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();

	//trim on top of building
	glPushAttrib(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	glPushMatrix();
	glTranslatef(0,1,0);
	glScalef(2,.1,.01);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();

		//concrete foundation
	glPushAttrib(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, concrete_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, concrete_color);
	glPushMatrix();
	glTranslatef(0,-1+.1,0.001);
	glScalef(1,.1,.1);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-1,0);  // corner
	glVertex3f(1 ,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(-1,1,0);
	glEnd();
	glPopMatrix();
	glPopAttrib();


}

void constructSquatWindow() {
	glPushMatrix();
	glScalef(.3,.9,1);
	constructGenericWindow();
	glPopMatrix();
}

void constructThinWindow() {
	glPushMatrix();
	glScalef(.3,1,1);
	constructGenericWindow();
	glPopMatrix();
}

void constructDoubleWindow() {
	glPushMatrix();
	glScalef(.6,1,1);
	constructGenericWindow();
	glPopMatrix();
}

void constructLeftDoor() {
	//TODO
}

void constructRightDoor() {
	//TODO
}

void constructGutter(int height) {
	//TODO
}

void constructStairs() {
	//TODO
}


void constructCar() {
	glPushAttrib(GL_COLOR_MATERIAL);

	//main body of car
	glMaterialfv(GL_FRONT, GL_DIFFUSE, car_colors);
	glMaterialfv(GL_FRONT, GL_AMBIENT, car_colors);
	glPushMatrix();
	glScalef(1,.3,.5);
	glutSolidCube(1);
	glPopMatrix();


	//cab
	glPushMatrix();
	glTranslatef(0,.25,0);
	glScalef(.5,.25,.3);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();

	//windows
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
	glPushMatrix();
	glTranslatef(0,.25,.15);
	glScalef(.45,.2,.01);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,.25,-.15);
	glScalef(.45,.2,.01);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.25,.25,0);
	glScalef(.01,.2,.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.25,.25,0);
	glScalef(.01,.2,.2);
	glutSolidCube(1);
	glPopMatrix();

	//tires
	glMaterialfv(GL_FRONT, GL_DIFFUSE, tire_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, tire_color);
	glPushMatrix();
	glTranslatef(-.35,-.1,-.6/2);
	glScalef(.1,.1,.6);
	glutSolidCylinder(1,1,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.35,-.1,-.6/2);
	glScalef(.1,.1,.6);
	glutSolidCylinder(1,1,20,20);
	glPopMatrix();



	glPopAttrib();

}

/*
* Calculate the radius of the circumcircle created by the triangle formed from the arc in the top of a window.
*/
float calculateRadius(float width, float height) {
	float a = width;
	float b = sqrt(pow(a/2,2) + pow(height,2)); //the length of the hypotenuse formed by half the width and the full height
	float c = b;

	float radius = (a*b*c)/(sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));//equation for the circumcircle of a triangle
	return radius;
}



/*
*	This code is an adapted version of the inclass lecture code "15arches"
*/
void constructGenericWindow() {
	float width = 60;
	float height = 144;
	float archHeight = 5;
	float depth = 15;
	float windowBoarder = .2;
	float radius = calculateRadius(width, archHeight);
	float startTheta = acos((width/2.0)/radius); //the starting theta value for the beginning of the arch, in radians.

	int numSlices = 20;
	double angle = startTheta;
	double angInc = 3.14159/2 -startTheta;
	angInc = angInc/numSlices;
	double cornerX = (width/2)/radius;
	depth = depth/(height+archHeight); //normalize to the height of the object
	float sideHeight = windowBoarder+(height+archHeight)/width;


	glPushMatrix();
	glTranslatef(0,sideHeight/2,-depth/2);

	//glass window
	glPushAttrib(GL_COLOR_MATERIAL);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
	glPushMatrix();
	glTranslatef(0,-sideHeight/2,-depth/2+depth/8);
	glScalef(cornerX*2,sideHeight,depth/4);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();
	glPopAttrib();
	//glDisable(GL_BLEND);

	//////above the arch
	glPushMatrix();
	glTranslatef(0,windowBoarder/2,0);
	glScalef(cornerX*2,windowBoarder,depth);
	glutSolidCube(1);
	glPopMatrix();

	//left side of window

	glPushMatrix();
	glTranslatef(-cornerX-depth/2,-sideHeight/2 + windowBoarder,0);
	glScalef(depth,sideHeight,depth);
	glutSolidCube(1);
	glPopMatrix();

	//right side of window
	glPushMatrix();
	glTranslatef(cornerX+depth/2,-sideHeight/2 + windowBoarder,0);
	glScalef(depth,sideHeight,depth);
	glutSolidCube(1);
	glPopMatrix();

	//bottom ledge
	glPushAttrib(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, stone_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, stone_color);

	glPushMatrix();
	glTranslatef(0,windowBoarder/2-sideHeight,depth/4);
	glScalef(cornerX*2+depth*2,windowBoarder,depth*1.5);
	glutSolidCube(1);
	glPopMatrix();
	glPopAttrib();
	

	int i = 0;
	for (i = 0; i < numSlices; i++) {
		//draw the arch
		glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
		glVertex3f(cornerX,0,depth/2);  // corner
		glVertex3f( cos(angle) , sin(angle)-1, depth/2);
		glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, depth/2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-cornerX,0,depth/2);  // corner
		glVertex3f(- cos(angle) , sin(angle)-1, depth/2);
		glVertex3f(- cos(angle+angInc), sin(angle+angInc)-1, depth/2);
		glEnd();



		// vault

		glNormal3f(-cos(angle+angInc/2),-sin(angle+angInc/2),0);

		glColor3f(0,0,1);
		glBegin(GL_POLYGON);
		glVertex3f(  cos(angle) ,    sin(angle)-1 ,depth/2);  // corner
		glVertex3f( cos(angle) ,       sin(angle)-1, -depth/2);
		glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -depth/2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(  cos(angle) ,    sin(angle)-1 ,depth/2);  // corner
		glVertex3f( cos(angle+angInc) ,       sin(angle+angInc)-1, depth/2);
		glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -depth/2);
		glEnd();

		glNormal3f(cos(angle+angInc/2),-sin(angle+angInc/2),0);

		glBegin(GL_POLYGON);
		glVertex3f( - cos(angle) ,    sin(angle)-1 ,depth/2);  // corner
		glVertex3f( -cos(angle) ,       sin(angle)-1, -depth/2);
		glVertex3f( -cos(angle+angInc), sin(angle+angInc)-1, -depth/2);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f( - cos(angle) ,    sin(angle)-1 ,depth/2);  // corner
		glVertex3f( -cos(angle+angInc) ,       sin(angle+angInc)-1, depth/2);
		glVertex3f( -cos(angle+angInc), sin(angle+angInc)-1, -depth/2);
		glEnd();

		angle += angInc;
   
	}
	glPopMatrix();
}

void constructLeftWindows() {


}