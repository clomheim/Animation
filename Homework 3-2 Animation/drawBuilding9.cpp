#include "drawBuildings.h"
#include "Angel.h"
#include <string>
#define PI 3.14159
static float brickMat[] = { 0.76078431, 0.411764705, 0.254901960, 1};
static float white[] = { 0.95, 0.95, 0.95, 1};
static float windowSurface[] = { .1, .27, .46 };
static float black[] = { 0.00, 0.00, 0.00, 1};
static float floorgraycolor [] = { 0.65882352941176470588235294117647, 0.65882352941176470588235294117647, 0.65882352941176470588235294117647, 1};
// Author: Daniel Henderson 
// University of Washington Winter 2014
// Computer Graphics 

//LEDGE CODE and PARTIAL Window code created BY: DAVID SWANSON 2014, and USED IN THIS CLASS SO THE BUILDINGS MATCH
 void twoStepLedge9() {
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

 void twoStepLedgeRoof9() {
	 //draw a 4x2x2 solid cube
	 glPushMatrix();
	 glScalef(4,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 //draw three rows of 11 twoStepLedge
	 glPushMatrix();
	 glTranslatef(-1.85,-0.275,1.1);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge9();
	 glPopMatrix();
 }
  //bottom twoStepLedgeRoof 20x1x2
 void twoStepLedgeRoofCenter9() {
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
	 twoStepLedge9();
	 glPopMatrix();
	 //second
	 	 glPushMatrix();
	 glTranslatef(-5.9,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge9();
	 //third
	 glPopMatrix();
	 	 glPushMatrix();
	 glTranslatef(-1.9,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge9();
	 glPopMatrix();//fourht
	 	 glPushMatrix();
	 glTranslatef(2,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge9();
	 glPopMatrix();
	 //fifth
	 glPushMatrix();
	 glTranslatef(6.2,-0.275,val);
	 glScalef(0.15,0.15,0.25);
	 twoStepLedge9();
	 glPopMatrix();
 }

 void fiveStepLedge9() {
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
 void windowLedge9() {
	 //two long
	 glPushMatrix();
	 glScalef(2,  0.25, 0.125);
	 glutSolidCube(1);
	 glPopMatrix();
 }
  //END LEDGE CODE CREATED BY DAVID
 //-------------------------------------------------------------------------------

 void buildTop9() {

	 //LEFT TOP OF BUILDING
	 glPushMatrix();
	 glPushMatrix();
	 glTranslatef(0,0,0);
	 glScalef(1,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(0,0.75,0);
	 glScalef(1,0.5,2.5);
	 glutSolidCube(1);
	 glPopMatrix();
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

	 //CENTER TOP OF BUILDING
	 glPushMatrix();
	 glPushMatrix();
	 glTranslatef(1.5,0.5,0);
	 glScalef(2,0.25,1);
	 glutSolidCube(1);
	 glPopMatrix();
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
	 for(int n = 0; n < 10; n++) {
		glTranslatef(0.25,0,0);
		glPushMatrix();
		glScalef(0.15,1,1);
		glutSolidCube(1);
		glPopMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 }
	 glTranslatef(-1,0,0);
	 glPushMatrix();
	 glScalef(2,1.75,0.1);
	 glutSolidCube(1);
	 glPopMatrix();
     glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 glPopMatrix();
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

	 //RIGHT TOP OF BUILDING
	 glPushMatrix();
	 glPushMatrix();
	 glTranslatef(3.0,0,0);
	 glScalef(1,1,2);
	 glutSolidCube(1);
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(3.0,0.75,0);
	 glScalef(1,0.5,2.5);
	 glutSolidCube(1);
	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 glPopMatrix();
 }
 void constructRoofSides9() {
	 glPushMatrix();
		glPushMatrix();
			glTranslatef(0,-0.25,0);
			glScalef(1,1.5,1);
			buildTop9();
		glPopMatrix();

			glMaterialfv(GL_FRONT, GL_AMBIENT, white);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 //glPushMatrix();
	 glTranslatef(1.5,-1.3,0);
	 
	 //BUILD THE LEDGE
	 glPushMatrix();
			glTranslatef(0, 0, 0);
			glScalef(4,0.5,2.75);
			glutSolidCube(1);	
	 glPopMatrix();

	 glPopMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);	
	 glPushMatrix();

		glTranslatef(1.5,-1.9,0);
		glScalef(1,0.65,1);
		twoStepLedgeRoof9();
	 glPopMatrix();
	glPopMatrix();
 }
 void coorigatedMiddleTop9() {
	 glPushMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glTranslatef(10,-0.875,0.6);
	 glScalef(17.5,2.25, 0.25);
	 glutSolidCube(1);
	 glPopMatrix();
	 glPushMatrix();
	 glTranslatef(2,-0.875,-1.0);

	 //17 vertical lines in coorigated TOP CENTER WHITE PART of building 
	 for(int n = 0; n < 17;n++) {
		 glPushMatrix();
		 glTranslatef(n * 1,0,1.6);
		 glPushMatrix();
		 glScalef(0.125,2.25, 0.5);
		 glutSolidCube(1);
		 glPopMatrix();
		 glPopMatrix();
	 }
	 glPopMatrix();
	 glPushMatrix();
	 glTranslatef(4,-1.9,0.25);
	 glScalef(0.025,0.015752, 2);
	 glPopMatrix();

	 //Top white roof of center covering the Cooragated part
	 glTranslatef(10,0.2,-0.2);
	 glPushMatrix();
	 glScalef(18,0.1,2.0);
     glutSolidCube(1);
	 glPopMatrix();
     glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
 }
 void centerRoofTop9() {
	 glPushMatrix();
	 glPushMatrix();

	 //DRAW Coorigated Top CENTER of building
	 coorigatedMiddleTop9();
	 glPopMatrix();

	 //White Roof Ledge below Coorigated Center Top of building
	 glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	 glPushMatrix();
	 glTranslatef(12,-2.3,0.685);
	 glScalef(5,1,0.5);

	 //Ledge
	 glPushMatrix();
	 glTranslatef(0, 0, 0);
	 glScalef(4,0.5,2.75);
	 glutSolidCube(1);	
	 glPopMatrix();

	 glPopMatrix();
	 glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	 glPushMatrix();
	 glTranslatef(12.0,-2.9,0);
	 glScalef(1,0.65,1);
	 twoStepLedgeRoofCenter9();
	 glPopMatrix();
	 glPopMatrix();
 }

 void arch9() {

   int i, numSlices;
   double angle;
   double angInc;

   

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


//WINDOWTOP METHOD CREATED BY DAVID SWANSON 2014
void windowTop9(bool recessed, bool isThirdFloor) {
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
			fiveStepLedge9();
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
			windowLedge9();
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

//Create Windows with black wooden bezels surrounding them
void window9(bool recessed, bool isThirdFloor, bool isFirstFloor, bool isFourthFloor) {
	windowTop9(recessed, isThirdFloor);
	glPushMatrix();
    glTranslatef(-1.5,-1 ,0);
    glScalef(1,4,2);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5,-1 ,0);
    glScalef(1,4,2);
    glutSolidCube(1);
    glPopMatrix();
	if(isFourthFloor) { //LEDGE BELOW WINDOW
		glPushMatrix();
		glTranslatef(0,-3.1 ,0.8);
		glScalef(3,0.2,1);
		glutSolidCube(1);
		glPopMatrix();
	}
	if(recessed) {
		glPushMatrix();
		glTranslatef(0,-1.0,-0.25);
		glScalef(0.50,4,1.25);
		glutSolidCube(1);
		glPopMatrix();
	} else {
		glPushMatrix();
		glTranslatef(0,-1.0,0);
		glScalef(0.50,4,2);
		glutSolidCube(1);
		glPopMatrix();
	}
	glPushMatrix();

	//Code for window provided by Derek Fleener 2014
glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
//enable blending for translucent effect
    glEnable(GL_BLEND); 
    glBlendFunc(GL_ONE, GL_ONE);
//------ create/transform window pane here ----------------
//disable blending 

	glTranslatef(0,-1.5,0);
	glScalef(2,3.25,0.125);
	glutSolidCube(1);
	
	glDisable(GL_BLEND);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	glPopMatrix();
	

	//Edges around windows

	//BEZEL MIDDLE WINDOWS
	glPushMatrix();
	glTranslatef(0,-1.75,0);
	glScalef(3.0,0.1,0.25);
	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glutSolidCube(1);
	glPopMatrix();

	//LEFT + RIGHT BEZEL
	glPushMatrix();
	glTranslatef(0.27,-1.75,0);
	glScalef(0.1,4,0.25);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.27,-1.75,0);
	glScalef(0.1,4,0.25);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,-1.75,0);
	glScalef(0.1,4,0.25);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,-1.75,0);
	glScalef(0.1,4,0.25);
	glutSolidCube(1);
	glPopMatrix();

	 //TOP + BOTTOM WINDOWS
	glPushMatrix();
	glTranslatef(0,-3,0);
	glScalef(3.0,0.1,0.25);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(3.0,0.1,0.25);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

}
 void ArchFaceVault9(float xValue, float resize) {
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
 void doubleArch9() {

	 //SURROUNDING BLOCK AROUND WINDOW
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

   glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

		//Ledge below window
glPushMatrix();
		glTranslatef(0,-3.1 ,0.8);
		glScalef(3,0.2,1);
		glutSolidCube(1);
glPopMatrix();

   //SMALL ARCHES for the dual  top windows left and right
glPushMatrix();
   glTranslatef(0,0,0);
   ArchFaceVault9(-0.62, 0.38);
glPopMatrix();

glPushMatrix();
   glTranslatef(0,0,0);
   ArchFaceVault9(0.62, 0.38);
glPopMatrix();


   //BRICK BETWEEN WINDOW
glPushMatrix();
   glTranslatef(0,-1.0,0);
   glScalef(0.50,4,2);
   glutSolidCube(1);
glPopMatrix();

    //BLUE WINDOW BEHIND BEZEL
glPushMatrix();

	//Code for window provided by Derek Fleener 2014

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
	//enable blending for translucent effect
    glEnable(GL_BLEND); 
    glBlendFunc(GL_ONE, GL_ONE);

	glTranslatef(0,-1.5,0);
	glScalef(2,3.25,0.125);
	glutSolidCube(1);
	
	glDisable(GL_BLEND);
glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);

	//CENTER BEZEL OF WINDOW

	
glPushMatrix();
	glTranslatef(0,-1.75,0);
	glScalef(3.0,0.1,0.25);
	glutSolidCube(1);
glPopMatrix();

	//LEFT + RIGHT BEZEL OF WINDOW
glPushMatrix();
	glTranslatef(0.27,-1.75,0);
	glScalef(0.1,3.5,0.25);
	glutSolidCube(1);
glPopMatrix();

glPushMatrix();
	glTranslatef(-0.27,-1.75,0);
	glScalef(0.1,3.5,0.25);
	glutSolidCube(1);
glPopMatrix();

glPushMatrix();
	glTranslatef(1,-1.75,0);
	glScalef(0.1,3.5,0.25);
	glutSolidCube(1);
glPopMatrix();

glPushMatrix();
	glTranslatef(-1,-1.75,0);
	glScalef(0.1,3.5,0.25);
	glutSolidCube(1);
glPopMatrix();

	//BOTTOM BEZEL OF WINDOW
glPushMatrix();
	glTranslatef(0,-3,0);
	glScalef(3.0,0.1,0.25);
	glutSolidCube(1);
glPopMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
}

 void buildroof9() {
	glPushMatrix();
	  glTranslatef(0, 0.1,0);
	 glPushMatrix();
		glTranslatef(-1.5,-1.0,0);
		constructRoofSides9();
	 glPopMatrix();

	 glPushMatrix();
		glTranslatef(18.5,-1.0,0);
		constructRoofSides9();
	 glPopMatrix();

	 glPushMatrix();
		centerRoofTop9();
	 glPopMatrix();

	glPopMatrix();
 }

 void buildDoubleDoors9() {
	 
	 //Top
	glPushMatrix();
			glTranslatef(0,-15.5005,0);
			glScalef(4,1,2);
			glutSolidCube(1);
	glPopMatrix();
			//window ledge

	//Left
	glPushMatrix();
		glTranslatef(-1.5,-18 ,0);
		glScalef(1,4,2);
		glutSolidCube(1);
    glPopMatrix();

   //Left Right
   glPushMatrix();
		glTranslatef(1.5,-18 ,0);
		glScalef(1,4,2);
		glutSolidCube(1);
   glPopMatrix();

		//Middle 

      	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		
	//small white middle vertical gap between doors
   glPushMatrix();
		glTranslatef(0,-18.5,0.3);
		glScalef(0.03,3,0.1);
		glutSolidCube(1);
	glPopMatrix();


   		glMaterialfv(GL_FRONT, GL_AMBIENT, black);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, black);

		//Large Black bezel center of doors
   glPushMatrix();
		glTranslatef(0,-18.5,0.2);
		glScalef(0.25,3,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//small black middle vertical divider for windows above door
	glPushMatrix();
		glTranslatef(0,-16.5,0.2);
		glScalef(0.1,1.5,0.1);
		glutSolidCube(1);
	glPopMatrix();

		//small black middle horizontal divider between windows and the door
	glPushMatrix();
		glTranslatef(0,-17.0,0.2);
		glScalef(2,0.2,0.1);
		glutSolidCube(1);
	glPopMatrix();

	//small black middle horizontal bezel under the doors
	glPushMatrix();
		glTranslatef(0,-19.9,0.2);
		glScalef(2,0.1,0.1);
		glutSolidCube(1);
	glPopMatrix();


	//Larger side bezels betweek doors and side windows
	glPushMatrix();
		glTranslatef(0.7,-18,0.2);
		glScalef(0.25,4,0.1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.7,-18,0.2);
		glScalef(0.25,4,0.1);
		glutSolidCube(1);
	glPopMatrix();


	//Draw Window
	glPushMatrix();
			//Code for window provided by Derek Fleener 2014
		glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
		glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
		//enable blending for translucent effect
		glEnable(GL_BLEND); 
		glBlendFunc(GL_ONE, GL_ONE);

		glTranslatef(0,-18,0);
		glScalef(2,4,0.125);
		glutSolidCube(1);	
		glDisable(GL_BLEND);
	glPopMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
}

void buildLargeWindow9() {
		glMaterialfv(GL_FRONT, GL_AMBIENT, white);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
				//bottom
	glPushMatrix();
		glTranslatef(0,-19.65,0);
		glScalef(2,0.75,2);
		glutSolidCube(1);
	glPopMatrix();

		glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
		 //Top
	glPushMatrix();
			glTranslatef(0,-15.5005,0);
			glScalef(4,1,2);
			glutSolidCube(1);
	glPopMatrix();




	//Left
	glPushMatrix();
		glTranslatef(-1.5,-18 ,0);
		glScalef(1,4,2);
		glutSolidCube(1);
    glPopMatrix();

   //Left Right
   glPushMatrix();
		glTranslatef(1.5,-18 ,0);
		glScalef(1,4,2);
		glutSolidCube(1);
   glPopMatrix();

   	//Edges around windows
   		glMaterialfv(GL_FRONT, GL_AMBIENT, black);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, black);

	//BEZEL MIDDLE WINDOWS
	glPushMatrix();
		glTranslatef(0,-19.75,0);
		glScalef(3.0,0.1,0.25);
		glutSolidCube(1);
	glPopMatrix();

	//LEFT + RIGHT BEZEL + Middle
	glPushMatrix();
		glTranslatef(0.75,-18,0);
		glScalef(0.2,4,0.25);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.75,-18,0);
		glScalef(0.2,4,0.25);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0,-18,0);
		glScalef(0.1,4,0.25);
		glutSolidCube(1);
	glPopMatrix();


	//LEFT EDGE + RIGHT EDGE BEZEL against brick for outline of window
	glPushMatrix();
		glTranslatef(1,-18,0);
		glScalef(0.1,4,0.25);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1,-18,0);
		glScalef(0.1,4,0.25);
		glutSolidCube(1);
	glPopMatrix();

	 //TOP + BOTTOM WINDOWS
	glPushMatrix();
		glTranslatef(0,-19.2,0);
		glScalef(3.0,0.1,0.25);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-18,0);
		glScalef(3.0,0.1,0.25);
		glutSolidCube(1);
	glPopMatrix();

	//MIDDLE HORIZONTAL
	glPushMatrix();
		glTranslatef(0,-17,0);
		glScalef(3,0.2,0.25);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-16,0);
		glScalef(3,0.2,0.25);
		glutSolidCube(1);
	glPopMatrix();

	//Build Window glass
	glPushMatrix();

	//Code for window provided by Derek Fleener 2014
		glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
		glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
	//enable blending for translucent effect
		glEnable(GL_BLEND); 
		glBlendFunc(GL_ONE, GL_ONE);

		glTranslatef(0,-18,0);
		glScalef(4,4,0.125);
		glutSolidCube(1);
	
		glDisable(GL_BLEND);
	glPopMatrix();



   		glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
}
void buildByLevel9(int type) {
	//1 = left, 2 = center, 3 = right
			
			//Build floors - These must be built before the windows, so the blending transparency happens
glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, floorgraycolor);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, floorgraycolor);
		
		glPushMatrix();
			glTranslatef(10,-7.5,-13.5);
			glScalef(23,0.1,28.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(9.8,-11.5,-13.9);
			glScalef(23,0.1,28.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(9.8,-15.5,-13.9);
			glScalef(23,0.1,28.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(9.8,-19.9,-13.9);
			glScalef(23,0.1,28.5);
			glutSolidCube(1);
		glPopMatrix();

			//Build White full roof
			glMaterialfv(GL_FRONT, GL_AMBIENT, white);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		glPushMatrix();
			glTranslatef(9.8,-2,-13.9);
			glScalef(23,0.1,28.5);
			glutSolidCube(1);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(9.7,0,-13.9);
			glScalef(22.5,0.1,28.5);
			glutSolidCube(1);
		glPopMatrix();

			glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

			//Build Left and Back wall

		glPushMatrix();
			glTranslatef(-1.5,-10,-13.9);
			glScalef(0.5,20,28.5);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(10,-10,-28.2);
			glScalef(24,20,0.5);
			glutSolidCube(1);
		glPopMatrix();




	if(type == 1) {
glPushMatrix();
			//glTranslatef(0,0,0);
		
		//FLOOR4
		glPushMatrix();
			glTranslatef(0,-4,0);
			doubleArch9();
		glPopMatrix();

		//FLOOR3
		glPushMatrix();
			glTranslatef(0,-8,0);
			window9(true, true, false, false);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,-7.125,0.75);
			glScalef(4.5,0.125,1);
		glPopMatrix();

		//FLOOR2
		glPushMatrix();
			glTranslatef(0,-12,0);
			window9(true, false, false, false);
		glPopMatrix();

		//LOBBY
		glPushMatrix();
			buildDoubleDoors9();
		glPopMatrix();	

	}
glPopMatrix();
	if(type == 2) {
glPushMatrix();
		glTranslatef(4,0,-1);
		for(int n = 0; n < 4; n++) { // N = # of columns of windows for center of building
			//FLOOR4
			glPushMatrix();
				glTranslatef(n * 4,-4,1);
				window9(false, false, false, true);
			glPopMatrix();

			//FLOOR3 - BUILD LARGE ARCH WINDOW FLOOR3
		glPushMatrix();
				glTranslatef(n * 4,-8,1);

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

				//Code for window provided by Derek Fleener 2014
				glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
				glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
				//enable blending for translucent effect
				glEnable(GL_BLEND); 
				glBlendFunc(GL_ONE, GL_ONE);

				glTranslatef(0,-1.5,0);
				glScalef(2,3.25,0.125);
				glutSolidCube(1);
	
				glDisable(GL_BLEND);
			glPopMatrix();

				glMaterialfv(GL_FRONT, GL_AMBIENT, black);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
			glPushMatrix();
				glTranslatef(0,-1.75,0);
				glScalef(3.0,0.1,0.25);
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

			glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);

			arch9();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(8,-7.125,0.75);
			glScalef(24,0.125,1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.5,-7.125,0.75);
			glScalef(1,0.125,2.0);
			glRotatef(90,0,1,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(17.5,-7.125,0.75);
			glScalef(1,0.125,2.0);
			glRotatef(-90,0,1,0);
		glPopMatrix();

			//FLOOR2
		glPushMatrix();
			glTranslatef(n * 4,-12,1);
			window9(true, false, false, false);
		glPopMatrix();

			//LOBBY
		glPushMatrix();
			glTranslatef(n * 4,0,1);
			buildLargeWindow9();
		glPopMatrix();
			
		}
	glPopMatrix();
	}

	if(type == 3) {
	glPushMatrix();
		glTranslatef(20,0,0);

		//FLOOR4
	glPushMatrix();
		glTranslatef(0,-4,0);
		doubleArch9();
	glPopMatrix();

		//FLOOR3
	glPushMatrix();
		glTranslatef(0,-8,0);
		window9(true, true, false, false);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,-7.125,0.75);
		glScalef(4.5,0.125,1);
	glPopMatrix();

		//FLOOR2
	glPushMatrix();
		glTranslatef(0,-12,0);
		window9(true, false, false, false);
	glPopMatrix();

		//LOBBY
	glPushMatrix();
		glTranslatef(0,0,0);
		buildDoubleDoors9();
	glPopMatrix();
glPopMatrix();
	}
}

void buildCompleteFaceBuilding9() {
	int left = 1;
	int center = 2;
	int right = 3;
	buildByLevel9(left);
	buildByLevel9(center);
	buildByLevel9(right);
	buildroof9();
}

void drawBuilding9(int closeUp) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
	if (closeUp) {
		glTranslatef(-6, 0, 1);
		glScalef(0.5,0.5,0.5);

		// TEST SETTINGS WITH BUILDING 10 90 degrees
		//glTranslatef(-7.5, 0, -11);
		//glScalef(0.5,0.5,0.5);
		//glRotatef(-90, 0, 1, 0);;
		
	} else {
		glTranslatef(3,2,2);
		glScalef(0.06, 0.1, 0.078);
		glRotatef(180, 0, 1, 0);;
	}

	buildCompleteFaceBuilding9();

}