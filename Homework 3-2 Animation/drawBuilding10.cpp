#include "drawBuildings.h"
#include "Angel.h"
#define PI 3.14159
 //additional elements
static float brickMat[] = { 0.58823529411, 0.08623730939, 0.0431372549, 1};
	 static float white[] = { 0.95, 0.95, 0.95, 1};
	 static float blueWindows[] = {1,1,1,0.25};
 static void output() {
	 float shift = 25;
	 glPushMatrix();
  glRotatef(360, 0, 1, 0);
  glLineWidth(2.5);
  char string[6];
  string[0] = 'G'; 
  string[1] = 'A';
  string[2] = 'T';
  string[3] = 'H';
  string[4] = 'E'; 
  string[5] = 'R';
  glutStrokeCharacter(GLUT_STROKE_ROMAN, string[0]);
  glTranslatef(shift,0,0);
  glutStrokeCharacter(GLUT_STROKE_ROMAN, string[1]);
  glTranslatef(shift,0,0);
  glutStrokeCharacter(GLUT_STROKE_ROMAN, string[2]);
  glTranslatef(shift,0,0);
  glutStrokeCharacter(GLUT_STROKE_ROMAN, string[3]);
  glTranslatef(shift,0,0);
  glutStrokeCharacter(GLUT_STROKE_ROMAN, string[4]);
  glTranslatef(shift,0,0);
  glutStrokeCharacter(GLUT_STROKE_ROMAN, string[5]);
  glPopMatrix();
 }
 static void roofLedge() {
	 //4x1x2 solid
	 glPushMatrix();
	 glTranslatef(0, 0, 0);
	 glScalef(4,0.5,2.75);
	 glutSolidCube(1);	
	 glPopMatrix();
	 //


 }
 static void twoStepLedge() {
	 //eleven elements with gaps
	 glPushMatrix();
	 float xValue = 2.5;
	 float yValue = 2.5;
	 for(int i = 0; i < 11; i++) {
		 glPushMatrix();
		 glTranslatef(0+i*xValue, 0, 0);
		 glScalef(1,1,1);
		 glutSolidCube(1);
		 glPopMatrix();
		 
		 glPushMatrix();
		 glTranslatef(0+i*xValue,-1,-0.25);
		 glScalef(1,1,0.5);
		 glutSolidCube(1);
		 glPopMatrix();
	 }
	 glPopMatrix();

	 	 glPushMatrix();
		 glTranslatef(0,yValue,0);

	 for(int i = 0; i < 11; i++) {
		 glPushMatrix();
		 glTranslatef(0+i*xValue, 0, 0);
		 glScalef(1,1,1);
		 glutSolidCube(1);
		 glPopMatrix();
		 
		 glPushMatrix();
		 glTranslatef(0+i*xValue,-1,-0.25);
		 glScalef(1,1,0.5);
		 glutSolidCube(1);
		 glPopMatrix();
	 }
	 glPopMatrix();
	 	 glPushMatrix();
		 glTranslatef(0,yValue*2,0);
	 for(int i = 0; i < 11; i++) {
		 glPushMatrix();
		 glTranslatef(0+i*xValue, 0, 0);
		 glScalef(1,1,1);
		 glutSolidCube(1);
		 glPopMatrix();
		 
		 glPushMatrix();
		 glTranslatef(0+i*xValue,-1,-0.25);
		 glScalef(1,1,0.5);
		 glutSolidCube(1);
		 glPopMatrix();
	 }
	 glPopMatrix();
 }
 //bottom twoStepLedgeRoof 20x1x2
 static void twoStepLedgeRoof() {
	 //draw a 4x2x2 solid cube
	 glPushMatrix();
	 glScalef(4,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 //draw three rows of 11 twoStepLedge
	 glPushMatrix();
	 glTranslatef(-1.85,-0.275,1.1);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge();
	 glPopMatrix();
 }
  //bottom twoStepLedgeRoof 20x1x2
 static void twoStepLedgeRoofCenter() {
	 float val = 1.15;
	 //draw a 4x2x2 solid cube
	 glPushMatrix();
	 glScalef(20,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 //draw three rows of 11 twoStepLedge
	 //first
	 glPushMatrix();
	 glTranslatef(-9.95,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge();
	 glPopMatrix();
	 //second
	 	 glPushMatrix();
	 glTranslatef(-5.9,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge();
	 //third
	 glPopMatrix();
	 	 glPushMatrix();
	 glTranslatef(-1.9,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge();
	 glPopMatrix();//fourht
	 	 glPushMatrix();
	 glTranslatef(2,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge();
	 glPopMatrix();
	 //fifth
	 	 glPushMatrix();
	 glTranslatef(6.2,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge();
	 glPopMatrix();
 }
 static void topCubesLeft() {
	 glPushMatrix();
	 glTranslatef(0,0,0);
	 glScalef(1,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 //white 1x0.5x2.5 cube
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(0,0.75,0);
	 glScalef(1,0.5,2.5);
	 glutSolidCube(1);
	 glPopMatrix();
 
 }
 static void topCubesCenter() {
	 	 //brick 2x0.0.25x1 cube
	 glPushMatrix();
	 glTranslatef(1.5,0.5,0);
	 glScalef(2,0.25,1);
	 glutSolidCube(1);
	 glPopMatrix();
	 //white 1x0.5x1 cube
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(1.5,0.75,0);
	 glScalef(2,0.5,1.5);
	 glutSolidCube(1);
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 glPushMatrix();
	 glTranslatef(0,0,0);
	 for(int i = 0; i < 10; i++) {
		 glTranslatef(0.25,0,0);
		 glPushMatrix();
		 glScalef(0.15,1,1);
		 glutSolidCube(1);
		 glPopMatrix();
	 }
	 glPopMatrix();
 }
 static void topCubesRight() {
	 	 //brick 1x1x2 cube
	 glPushMatrix();
	 glTranslatef(3.0,0,0);
	 glScalef(1,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 //white 1x0.5x2.5 cube
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(3.0,0.75,0);
	 glScalef(1,0.5,2.5);
	 glutSolidCube(1);
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
 }
 static void topCubes() {
	 //left
	 //brick 1x1x2 cube
	 glPushMatrix();
	 topCubesLeft();
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

	 //center
	 glPushMatrix();
	 topCubesCenter();
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

	 //right
	 glPushMatrix();
	 topCubesRight();
	 glPopMatrix();
 }
 static void leftRightRoofTop() {
	 glPushMatrix();
	 glPushMatrix();
	 //top cubes 4x2x2
	 glTranslatef(0,-0.25,0);
	 glScalef(1,1.5,1);
	 topCubes();
	 glPopMatrix();
	 //middle roofLedge 4x12
	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(1.5,-1.3,0);
	 //NEEDS TO BE DEVELOPED
	 roofLedge();
	 glPopMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 //bottom twoStepLedgeRoof 4x1x2	
	 	 glPushMatrix();
	 glTranslatef(1.5,-1.9,0);
	 glScalef(1,0.65,1);
	 //NEEDS TO BE DEVELOPED
	 twoStepLedgeRoof();
	 glPopMatrix();
	 glPopMatrix();
 }
 static void centerSign() {
	 //FINISHED
	 glPushMatrix();
	 glTranslatef(12,-0.875,-1.0);
	 glScalef(20,2.25, 0.25);
	 glutSolidCube(1);
	 glPopMatrix();

	 //draws x number of 0.125x2xZ solidCube NEEDS A LOOP
	 glPushMatrix();
	 glTranslatef(2,-0.875,-1.0);
	 for(int i = 0; i < 20;i++) {
		 glPushMatrix();
		 glTranslatef(0+i*1,0,0);
		 glPushMatrix();
		 glScalef(0.125,2.25, 1.5);
		 glutSolidCube(1);
		 glPopMatrix();
		 glPopMatrix();
	 }
	 glPopMatrix();
	 //word FINISHED
	 glPushMatrix();
	 glTranslatef(4,-1.9,0.25);
	 glScalef(0.025,0.015752, 2);
	 output();
	 glPopMatrix();
 }
 static void centerRoofTop() {

	 glPushMatrix();
	 //top 20x2x2
	 //draws an ultra thin 20x2x0.25 solidcube
	 glPushMatrix();
	 //PARTIALLY FINISHED NEEDS SMALL ELEMENTS
	 centerSign();
	 glPopMatrix();
	 //middle roofLedge 20x1x2
	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(12,-2.3,0);
	 glScalef(5,1,0.5);
	 //NEEDS TO BE DEVELOPED
	 roofLedge();
	 glPopMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 //bottom twoStepLedgeRoof 20x1x2
	 glPushMatrix();
	 glTranslatef(12.0,-2.9,-1);
	 glScalef(1,0.65,1);
	 twoStepLedgeRoofCenter();
	 glPopMatrix();
	 glPushMatrix();
	 glTranslatef(1,-3.0,-0.25);
	 glScalef(1,0.65,0.125);
	 glRotatef(90,0,1,0);
	 twoStepLedgeRoofCenter();
	 glPopMatrix();

	 	 glPushMatrix();
	 glTranslatef(23,-3.0,-0.25);
	 glScalef(1,0.65,0.125);
	 glRotatef(-90,0,1,0);
	 twoStepLedgeRoofCenter();
	 glPopMatrix();
	 glPopMatrix();
 }
 static void threeStepLedge() {
	 //four long
	 //four long
	 glPushMatrix();
	 glScalef(1,1,1);
	 //top
	 glPushMatrix();
	 glScalef(1,1,1);
	 glutSolidCube(1);
	glPopMatrix();
	//middle
	glPushMatrix();
	glTranslatef(0,-1.0,-0.1666666666666667);
	glScalef(0.9,1,0.6666666666666667);
	glutSolidCube(1);
	glPopMatrix();
	//bottom
	glPushMatrix();
	glTranslatef(0,-2.0,-0.3333333333333333);
	glScalef(0.8,1,0.3333333333333333);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
 }
 static void fiveStepLedge() {
	 //2 long
	 glPushMatrix();
	 //first
	 glPushMatrix();
	 glScalef(2,0.12,0.65);
	 glutSolidCube(1);
	 glPopMatrix();
	 //second
	 glPushMatrix();
	 glTranslatef(0,-0.12,-0.065);
	 glScalef(2,0.12,0.52);
	 glutSolidCube(1);
	 glPopMatrix();
	 //third
	 glPushMatrix();
	 glTranslatef(0,-0.24,-0.13);
	 glScalef(2,0.12,0.39);
	 glutSolidCube(1);
	 glPopMatrix();
	 //fourth
	 glPushMatrix();
	 glTranslatef(0,-0.36,-0.195);
	 glScalef(2,0.12,0.25);
	 glutSolidCube(1);
	 glPopMatrix();
	 //fifth
	 glPushMatrix();
	 glTranslatef(0,-0.48,-0.26);
	 glScalef(2,0.12,0.13);
	 glutSolidCube(1);
	 glPopMatrix();
	 glPopMatrix();
 }
 static void windowLedge() {
	 //two long
	 glPushMatrix();
	 glScalef(2,  0.25, 0.125);
	 glutSolidCube(1);
	 glPopMatrix();
 }
static void pillar(double x, double y, double z) {
	/* Draw first pillar by Translating */
	int heighest = 1;
	if(x > y) {
		heighest = y;
	} else if(y > x){
		heighest = x;
	} else if (x == y) {
		heighest = x;
	}
   glPushMatrix() ;
   glScalef(y,x,1);
   glutSolidCylinder(0.125/heighest,1,20,20);
   glPopMatrix();
}
static void firstFloorLedge(double x, double y, double z) {
	float yValue = 0.15;
	float zValue = -0.5;
	//pillars
	//farthest left
	glPushMatrix();
	glTranslatef(-1.55, yValue, zValue);
	pillar(x,y,z);
	glPopMatrix();
	//middle left
	glPushMatrix();
	glTranslatef(-1, yValue, zValue);
	pillar(x,y,z);
	glPopMatrix();
	//innermost left
	glPushMatrix();
	glTranslatef(-0.2, yValue, zValue);
	pillar(x,y,z);
	glPopMatrix();
	//innermost right
	glPushMatrix();
	glTranslatef(0.2, yValue, zValue);
	pillar(x,y,z);
	glPopMatrix();
	//middle right
	glPushMatrix();
	glTranslatef(1, yValue, zValue);
	pillar(x,y,z);
	glPopMatrix();
	//farthest right
	glPushMatrix();
	glTranslatef(1.55, yValue, zValue);
	pillar(x,y,z);
	glPopMatrix();

	//top row
	glPushMatrix();
	glScalef(4.5,0.25,1);
	glutSolidCube(1);
	glPopMatrix();
	//middle row
	glPushMatrix();
	glTranslatef(0, -0.25,0);
	glScalef(4.1,0.25,0.95);
	glutSolidCube(1);
	glPopMatrix();
	//bottom row
	glPushMatrix();
	glTranslatef(0, -0.55,0);
	glScalef(3.7,0.50,0.9);
	glutSolidCube(1);
	glPopMatrix();
}
 //core elements
 static void arch() {

   int i, numSlices;
   double angle;
   double angInc;

   glPushMatrix();
   glTranslatef(0,0.5,0);
   glScalef(4,1,2);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-1.5,-1 ,0);
   glScalef(1,4,2);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(1.5, -1,0);
   glScalef(1,4,2);
   glutSolidCube(1);
   glPopMatrix();
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, blueWindows);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blueWindows);
	glTranslatef(0,-1.5,0);
	glScalef(2,3.25,0.125);
	glutSolidCube(1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-1.75,0);
	glScalef(3.0,0.25,0.25);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5,-2,0);
	glScalef(0.25,4,0.25);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5,-2,0);
	glScalef(0.25,4,0.25);
	glutSolidCube(1);
	glPopMatrix();

   numSlices = 20;
   angle = 0;
   angInc = 3.14159/(2 * numSlices);

   for (i = 0; i < numSlices; i++) {

	   glNormal3f(0,0,1);
       glBegin(GL_POLYGON);
       glVertex3f(1,0,1);  // corner
       glVertex3f( cos(angle) , sin(angle)-1, 1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, 1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f(-1,0,1);  // corner
       glVertex3f(- cos(angle) , sin(angle)-1, 1);
       glVertex3f(- cos(angle+angInc), sin(angle+angInc)-1, 1);
       glEnd();

	   //---
	   glNormal3f(0,0,-1);
       glBegin(GL_POLYGON);
       glVertex3f(1,0,-1);  // corner
       glVertex3f( cos(angle) , sin(angle)-1, -1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f(-1,0,-1);  // corner
       glVertex3f(- cos(angle) , sin(angle)-1, -1);
       glVertex3f(- cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

	   // vault

	   glNormal3f(-cos(angle+angInc/2),-sin(angle+angInc/2),0);


	   glColor3f(0,0,1);
       glBegin(GL_POLYGON);
       glVertex3f(  cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( cos(angle) ,       sin(angle)-1, -1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f(  cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( cos(angle+angInc) ,       sin(angle+angInc)-1, 1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

	   glNormal3f(cos(angle+angInc/2),-sin(angle+angInc/2),0);

       glBegin(GL_POLYGON);
       glVertex3f( - cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( -cos(angle) ,       sin(angle)-1, -1);
       glVertex3f( -cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f( - cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( -cos(angle+angInc) ,       sin(angle+angInc)-1, 1);
       glVertex3f( -cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();



	   angle += angInc;
   
   }
}
static void windowTop(bool recessed, bool isThirdFloor) {
	if(recessed) {
		if(isThirdFloor) {
			//nonrecessed
			glPushMatrix();
			glTranslatef(0.0,0.75,0.0);
			glScalef(4,0.5,2);
			glutSolidCube(1);
			glPopMatrix();
			//recessed
			glPushMatrix();
			glTranslatef(0,0.25,-0.25);
			glScalef(4,0.5,1.25);
			glutSolidCube(1);
			glPopMatrix();
			//fiveStepLedge
			glPushMatrix();
			glTranslatef(0,0.5,0.6);
			glScalef(1,1,1);
			fiveStepLedge();
			glPopMatrix();
		} else {
			glPushMatrix();
			glTranslatef(0,0.5,-0.25);
			glScalef(4,1,1.25);
			glutSolidCube(1);
			glPopMatrix();
			//window ledge
			glPushMatrix();
			glTranslatef(0,0.875,0.375);
			glScalef(1,1, 2);
			windowLedge();
			glPopMatrix();
		}
	} else {
		glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(4,1,2);
		glutSolidCube(1);
		glPopMatrix();
	}
}
static void windowLeftRight(float xValue) {
	   glPushMatrix();
   glTranslatef(xValue,-1 ,0);
   glScalef(1,4,2);
   glutSolidCube(1);
   glPopMatrix();
}
static void windowMiddle(bool recessed) {
		if(recessed) {
		glPushMatrix();
		glTranslatef(0,-1.0,-0.25);
		glScalef(0.25,4,1.25);
		glutSolidCube(1);
		glPopMatrix();
	} else {
		glPushMatrix();
		glTranslatef(0,-1.0,0);
		glScalef(0.25,4,2);
		glutSolidCube(1);
		glPopMatrix();
	}
}
static void window(bool recessed, bool isThirdFloor, bool isFirstFloor) {
	//top
	windowTop(recessed, isThirdFloor);
   //left
	windowLeftRight(-1.5);
   //right
	windowLeftRight(1.5);
   //middle
	windowMiddle(recessed);
	if(isFirstFloor) {
		glPushMatrix();
		glTranslatef(0,-3.1250,0.125);
		glScalef(1,1,2.25);
		firstFloorLedge(1,1,1);
		glPopMatrix();
	}
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, blueWindows);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blueWindows);
	glTranslatef(0,-1.5,0);
	glScalef(2,3.25,0.125);
	glutSolidCube(1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-1.75,0);
	glScalef(3.0,0.25,0.25);
	glutSolidCube(1);
	glPopMatrix();
}
 static void ArchFaceVault(float xValue, float resize) {
	 glPushMatrix();
	int i, numSlices;
	glTranslatef(xValue, 0, 0);
	glScalef(resize, 1, 1);
   double angle;
   double angInc;
   numSlices = 20;
   angle = 0;
   angInc = 3.14159/(2 * numSlices);

   for (i = 0; i < numSlices; i++) {

	   glNormal3f(0,0,1);
	      glColor3f(1,0,0);
       glBegin(GL_POLYGON);
       glVertex3f(1,0,1);  // corner
       glVertex3f( cos(angle) , sin(angle)-1, 1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, 1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f(-1,0,1);  // corner
       glVertex3f(- cos(angle) , sin(angle)-1, 1);
       glVertex3f(- cos(angle+angInc), sin(angle+angInc)-1, 1);
       glEnd();

	   //---
	   glNormal3f(0,0,-1);
       glBegin(GL_POLYGON);
       glVertex3f(1,0,-1);  // corner
       glVertex3f( cos(angle) , sin(angle)-1, -1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f(-1,0,-1);  // corner
       glVertex3f(- cos(angle) , sin(angle)-1, -1);
       glVertex3f(- cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

	   // vault

	   glNormal3f(-cos(angle+angInc/2),-sin(angle+angInc/2),0);


	   glColor3f(0,0,1);
       glBegin(GL_POLYGON);
       glVertex3f(  cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( cos(angle) ,       sin(angle)-1, -1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f(  cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( cos(angle+angInc) ,       sin(angle+angInc)-1, 1);
       glVertex3f( cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

	   glNormal3f(cos(angle+angInc/2),-sin(angle+angInc/2),0);

       glBegin(GL_POLYGON);
       glVertex3f( - cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( -cos(angle) ,       sin(angle)-1, -1);
       glVertex3f( -cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();

       glBegin(GL_POLYGON);
       glVertex3f( - cos(angle) ,    sin(angle)-1 ,1);  // corner
       glVertex3f( -cos(angle+angInc) ,       sin(angle+angInc)-1, 1);
       glVertex3f( -cos(angle+angInc), sin(angle+angInc)-1, -1);
       glEnd();



	   angle += angInc;
   
   }
   glPopMatrix();
}
 static void doubleArch() {
   glPushMatrix();
   glTranslatef(0,0.5,0);
   glScalef(2,1,2);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-1.5,-1 ,0);
   glScalef(1,4,2);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(1.5, -1,0);
   glScalef(1,4,2);
   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix();
   ArchFaceVault(-0.56, 0.44);
   glPopMatrix();
   glPushMatrix();
   ArchFaceVault(0.56, 0.44);
   glPopMatrix();

   	glPushMatrix();
   glTranslatef(0,-1.0,0);
   glScalef(0.25,4,2);
   glutSolidCube(1);
   glPopMatrix();
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, blueWindows);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blueWindows);
	glTranslatef(0,-1.5,0);
	glScalef(2,3.25,0.125);
	glutSolidCube(1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-1.75,0);
	glScalef(3.0,0.25,0.25);
	glutSolidCube(1);
	glPopMatrix();

}
//------------------------------------------------------------------------------------------------------------//
 static void roof() {
	 glPushMatrix();
	 glTranslatef(0, 0.1,0);
	 //lefts
	 glPushMatrix();
	 glTranslatef(-1.5,-1.0,0);
	 //glScalef(1,1,1);
	 leftRightRoofTop();
	 glPopMatrix();
	 	 //right
	 glPushMatrix();
	 glTranslatef(22.5,-1.0,0);
	 //glScalef(1,1,1);
	 leftRightRoofTop();
	 glPopMatrix();
	 //center
	 glPushMatrix();
	 centerRoofTop();
	 glPopMatrix();
	 glPopMatrix();
 }
 static void right() {
	 
	glPushMatrix();
	glTranslatef(24,0,0);
	//fourth floor
	glPushMatrix();
	glTranslatef(0,-4,0);
	doubleArch();
	glPopMatrix();
	//third floor
	glPushMatrix();
	glTranslatef(0,-8,0);
	window(true, true, false);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-7.125,1.5);
   glScalef(4.5,0.125,1);
   threeStepLedge();
	glPopMatrix();
	//second floor
	glPushMatrix();
	glTranslatef(0,-12,0);
	window(true, false, false);
	glPopMatrix();
	//first floor
	glPushMatrix();
	glTranslatef(0,-16,0);
	window(true, false, true);
	glPopMatrix();
	glPopMatrix();
}
static void center() {
	glPushMatrix();
	glTranslatef(4,0,-1);
	for(int i = 0; i < 5; i++) {
		//fourth floor
		glPushMatrix();
		glTranslatef(4*i,-4,0);
		window(false, false, false);
		glPopMatrix();
		//third floor
		glPushMatrix();
		glTranslatef(4*i,-8,0);
		arch();
		glPopMatrix();
		//back
		glPushMatrix();
		glTranslatef(8,-7.125,1.5);
		glScalef(24,0.125,1);
		threeStepLedge();
		glPopMatrix();
		//left
		glPushMatrix();
		glTranslatef(-1.5,-7.125,2.0);
		glScalef(1,0.125,2.0);
		glRotatef(90,0,1,0);
		threeStepLedge();
		glPopMatrix();
		//right
		glPushMatrix();
		glTranslatef(17.5,-7.125,2.0);
		glScalef(1,0.125,2.0);
		glRotatef(-90,0,1,0);
		threeStepLedge();
		glPopMatrix();
		//second floor
		glPushMatrix();
		glTranslatef(4*i,-12,0);
		window(true, false, false);
		glPopMatrix();
		//first floor
		glPushMatrix();
		glTranslatef(4*i,-16,0);
		window(true, false, true);
		glPopMatrix();
	}

	glPopMatrix();
}
static void left() {

	glPushMatrix();
	glTranslatef(0,0,0);
	//fourth floor
	glPushMatrix();
	glTranslatef(0,-4,0);
	doubleArch();
	glPopMatrix();
	//third floor
	glPushMatrix();
	glTranslatef(0,-8,0);
	window(true, true, false);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-7.125,1.5);
	glScalef(4.5,0.125,1);
	threeStepLedge();
	glPopMatrix();
	//second floor
	glPushMatrix();
	glTranslatef(0,-12,0);
	window(true, false, false);
	glPopMatrix();
	//first floor
	glPushMatrix();
	glTranslatef(0,-16,0);
	window(true, false, true);
	glPopMatrix();
	glPopMatrix();
}
static void wall() {
	//left column
	left();
	//center
	center();
	//right column
	right();
	//roof
	roof();
}
void drawBuilding10(int closeUp) {
	// the Harmon
	//glEnable(GL_BLEND);
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glDepthFunc(GL_EQUAL);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	if (closeUp) {
		glTranslatef(-6, 3, 2);
		glScalef(0.5,0.5,0.5);
	} else {
		glTranslatef(1.65,2,2.25);
		glScalef(0.1, 0.1, 0.08);
		glRotatef(-90,0,1,0);
	}
	//glScalef(2,2,2);
	//topCubes();
	wall();
	//fiveStepLedge();

	//glScalef(2,1,7);
		//pillar(7,50,5);
	//topFlair();
	//topLeftRight();
	//firstFloorWindowLedge(2, 1, 7);
}