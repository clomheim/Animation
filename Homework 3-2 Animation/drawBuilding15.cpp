/* Filename: drawBuilding15.cpp
 / Author: John Mayer, Derek Fleener
 / Last Modified: 3/2/2014 by Derek Fleener
 / Description: 3D Model of Walsh Gardner Building on UWT campus using OpenGL.
*/
#include "drawBuildings.h"

#include "Angel.h"

//material colors to be used in WG building
float roofMaterial[] = { .7, .7, .7 };
float windowSill[] = { .7, .7, .7 };
float windowStruts[] = { .7, .7, .7 };

float windowBars[] = { .57, .57, .66 };

float shinyWindowSurface[] = { .1, .27, .46 };

float YellowBrickMat[] = { 1, .9, .6 };

float brickRedMat[] = { .58, .27, .06 };

static void drawWindow() {

	glMaterialfv(GL_FRONT, GL_DIFFUSE, shinyWindowSurface);
	glMaterialfv(GL_FRONT, GL_AMBIENT, shinyWindowSurface);

	//enable blending for translucent effect
	glEnable(GL_BLEND); 
	glBlendFunc(GL_ONE, GL_ONE);
	
	//window pane
	glPushMatrix();
	glScalef(.2, .3, .0005);
	glutSolidCube(2);
	glPopMatrix();

	//disable blending 
	glDisable(GL_BLEND);
	

	//set material for making bars
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowBars);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowBars);

	glPushMatrix();
	glTranslatef(-.067, .2, 0);
	glScalef(.005, .1, .012);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.067, .2, 0);
	glScalef(.005, .1, .012);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .1, 0);
	glScalef(.2, .005, .012);
	glutSolidCube(2);
	glPopMatrix();

	//set material for making window sill
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSill);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSill);

	glPushMatrix();
	glTranslatef(0, -.3, 0);
	glScalef(.2, .02, .04);
	glutSolidCube(2);
	glPopMatrix();

}

void draw4Windows(){

	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowStruts);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowStruts);

	//center strut
	glPushMatrix();
	glScalef(.01, .3, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left inner strut
	glPushMatrix();
	glTranslatef(-.4, 0 ,0 );
	glScalef(.01, .3, .02);
	glutSolidCube(2);
	glPopMatrix();

	//right inner strut
	glPushMatrix();
	glTranslatef(.4, 0, 0);
	glScalef(.01, .3, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left outer strut
	glPushMatrix();
	glTranslatef(-.79, 0, 0);
	glScalef(.01, .3, .02);
	glutSolidCube(2);
	glPopMatrix();

	//right outer strut
	glPushMatrix();
	glTranslatef(.79, 0, 0);
	glScalef(.01, .3, .02);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.6, 0, 0);
	drawWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.2, 0, 0);
	drawWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.6, 0, 0);
	drawWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.2, 0, 0);
	drawWindow();
	glPopMatrix();

}

void drawShell(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, YellowBrickMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, YellowBrickMat);

	//4th floor
	glPushMatrix();
	glTranslatef(.25, 1.23, -1.98);
	glScalef(1.775, .02, 2.005);
	glutSolidCube(2);
	glPopMatrix();

	//3rd floor
	glPushMatrix();
	glTranslatef(.25, .41, -1.98);
	glScalef(1.775, .02, 2.005);
	glutSolidCube(2);
	glPopMatrix();

	//2nd floor
	glPushMatrix();
	glTranslatef(.25, -.41, -1.98);
	glScalef(1.775, .02, 2.005);
	glutSolidCube(2);
	glPopMatrix();

	//1st floor
	glPushMatrix();
	glTranslatef(.25, -1.23, -1.98);
	glScalef(1.775, .02, 2.005);
	glutSolidCube(2);
	glPopMatrix();

	//set material to brick red

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//back wall (right)
	glPushMatrix();
	glTranslatef(.25, 0, -4);
	glScalef(1.75, 1.65, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left wall (back)
	glPushMatrix();
	glTranslatef(-1.5, 0, -2);
	glScalef(.02, 1.65, 2.02);
	glutSolidCube(2);
	glPopMatrix();

	//right wall (front)
	glPushMatrix();
	glTranslatef(2, 0, -2);
	glScalef(.02, 1.65, 2.02);
	glutSolidCube(2);
	glPopMatrix();

	//put roof caps on walls
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial);

	//left wall roof lip
	glPushMatrix();
	glTranslatef(-1.5, 1.65, -2);
	glScalef(.04, .025, 2.04);
	glutSolidCube(2);
	glPopMatrix();

	//right wall roof lip
	glPushMatrix();
	glTranslatef(2, 1.65, -2);
	glScalef(.04, .025, 2.04);
	glutSolidCube(2);
	glPopMatrix();

	//back wall roof lip
	glPushMatrix();
	glTranslatef(.25, 1.65, -4);
	glScalef(1.79, .025, .04);
	glutSolidCube(2);
	glPopMatrix();

	//main roof cap
	glPushMatrix();
	glTranslatef(.25, 1.65, -2);
	glScalef(1.79, .025, 1.96);
	glutSolidCube(2);
	glPopMatrix();

	//roof cap angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, 1.655, -.35);
	glScalef(1.06, .02, .42);
	glutSolidCube(2);
	glPopMatrix();
}

void drawCornerPillar(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//top pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, 1.45, -.2);
	glScalef(.2, .20, .2);
	glutSolidCube(2);
	glPopMatrix();

	//top middle pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, .82, -.2);
	glScalef(.2, .4, .2);
	glutSolidCube(2);
	glPopMatrix();

	//middle pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, 0, -.2);
	glScalef(.2, .4, .2);
	glutSolidCube(2);
	glPopMatrix();

	//bottom middle pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, -.82, -.2);
	glScalef(.2, .4, .2);
	glutSolidCube(2);
	glPopMatrix();

	//bottom pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, -1.45, -.2);
	glScalef(.2, .2, .2);
	glutSolidCube(2);
	glPopMatrix();
}

void drawPillar() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//top pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, 1.55, -.2);
	glScalef(.2, .3, .2);
	glutSolidCube(2);
	glPopMatrix();

	//top middle pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, .82, -.2);
	glScalef(.2, .4, .2);
	glutSolidCube(2);
	glPopMatrix();

	//middle pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, 0, -.2);
	glScalef(.2, .4, .2);
	glutSolidCube(2);
	glPopMatrix();

	//bottom middle pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, -.82, -.2);
	glScalef(.2, .4, .2);
	glutSolidCube(2);
	glPopMatrix();

	//bottom pillar section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, -1.45, -.2);
	glScalef(.2, .2, .2);
	glutSolidCube(2);
	glPopMatrix();

	//put roof on pillar
	//set material for roofing 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial);

	//top pillar roof cap
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(0, 1.87, -.2);
	glScalef(.21, .03, .21);
	glutSolidCube(2);
	glPopMatrix();
}

void drawLeftWall() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//left window wall top section
	glPushMatrix();
	glTranslatef(-.85, 1.45, 0);
	glScalef(.65, .20, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left window wall top middle section
	glPushMatrix();
	glTranslatef(-.85, .525, 0);
	glScalef(.65, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left window wall middle section
	glPushMatrix();
	glTranslatef(-.85, -0.3, 0);
	glScalef(.65, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left window wall bottom middle section
	glPushMatrix();
	glTranslatef(-.85, -1.12, 0);
	glScalef(.65, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//left window wall bottom section
	glPushMatrix();
	glTranslatef(-.85, -1.45, 0);
	glScalef(.65, .2, .02);
	glutSolidCube(2);
	glPopMatrix();

	//top windows
	glPushMatrix();
	glTranslatef(-.85, .93, 0);
	glScalef(.81, 1, 1);
	draw4Windows();
	glPopMatrix();

	//middle windows
	glPushMatrix();
	glTranslatef(-.85, .1, 0);
	glScalef(.81, 1, 1);
	draw4Windows();
	glPopMatrix();

	//bottom windows
	glPushMatrix();
	glTranslatef(-.85, -.71, 0);
	glScalef(.81, 1, 1);
	draw4Windows();
	glPopMatrix();

	//set material for roofing 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial);

	//left wall roof lip
	glPushMatrix();
	glTranslatef(-.85, 1.65, 0);
	glScalef(.65, .025, .04);
	glutSolidCube(2);
	glPopMatrix();
}

void drawAngledFloors(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, YellowBrickMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, YellowBrickMat);

	//4th floor angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, 1.23, -.32);
	glScalef(1.05, .02, .42);
	glutSolidCube(2);
	glPopMatrix();

	//3rd floor angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, .41, -.32);
	glScalef(1.05, .02, .42);
	glutSolidCube(2);
	glPopMatrix();

	//2nd floor angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, -.41, -.32);
	glScalef(1.05, .02, .42);
	glutSolidCube(2);
	glPopMatrix();

	//1st floor angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, -1.23, -.32);
	glScalef(1.05, .02, .41);
	glutSolidCube(2);
	glPopMatrix();

}

void drawAngledWall() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//top angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, 1.45, .075);
	glScalef(.65, .20, .02);
	glutSolidCube(2);
	glPopMatrix();

	//top middle angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, .525, .075);
	glScalef(.65, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//middle angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, -0.3, .075);
	glScalef(.65, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//bottom middle angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, -1.12, .075);
	glScalef(.65, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//bottom angled section
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, -1.45, .075);
	glScalef(.65, .2, .02);
	glutSolidCube(2);
	glPopMatrix();

	//draw center pillar
	glPushMatrix();
	glTranslatef(-.02, 0, .09);
	drawPillar();
	glPopMatrix();

	//draw right pillar
	glPushMatrix();
	glTranslatef(1.53, 0, .72);
	drawCornerPillar();
	glPopMatrix();

	//draw angled floors
	glPushMatrix();
	drawAngledFloors();
	glPopMatrix();

	//top windows
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, .93, .08);
	glScalef(.81, 1, 1);
	draw4Windows();
	glPopMatrix();

	//bottom windows
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, -.71, .08);
	glScalef(.81, 1, 1);
	draw4Windows();
	glPopMatrix();

	//middle windows
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(.85, .1, .08);
	glScalef(.81, 1, 1);
	draw4Windows();
	glPopMatrix();

	//set material for roofing 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial);

	//left wall roof lip
	glPushMatrix();
	glRotatef(-22, 0, 1, 0);
	glTranslatef(1.06, 1.65, .095);
	glScalef(.85, .025, .04);
	glutSolidCube(2);
	glPopMatrix();
	
}

void drawEdgeSingleWindow(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//brick section
	glPushMatrix();
	glTranslatef(.05, -.41, -.01);
	glScalef(.23, .1, .02);
	glutSolidCube(2);
	glPopMatrix();

	//window brick filler place
	glPushMatrix();
	glTranslatef(.22, -.01, -.01);
	glScalef(.06, .3, .02);
	glutSolidCube(2);
	glPopMatrix();

	//window
	glPushMatrix();
	glScalef(.82, 1, 1);
	drawWindow();
	glPopMatrix();
}

void drawEdgeWall(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat);

	//top brick section
	glPushMatrix();
	glRotatef(68, 0, 1, 0);
	glTranslatef(.5, 1.45, 1.87);
	glScalef(.24, .2, .02);
	glutSolidCube(2);
	glPopMatrix();

	//draw bottom brick section
	glPushMatrix();
	glRotatef(68, 0, 1, 0);
	glTranslatef(.5, -1.45, 1.87);
	glScalef(.24, .2, .02);
	glutSolidCube(2);
	glPopMatrix();

	//draw top window section
	glPushMatrix();
	glRotatef(68, 0, 1, 0);
	glTranslatef(.46, .93, 1.88);
	drawEdgeSingleWindow();
	glPopMatrix();

	//draw middle window section
	glPushMatrix();
	glRotatef(68, 0, 1, 0);
	glTranslatef(.46, .1, 1.88);
	drawEdgeSingleWindow();
	glPopMatrix();

	//draw bottom window section
	glPushMatrix();
	glRotatef(68, 0, 1, 0);
	glTranslatef(.46, -.71, 1.88);
	drawEdgeSingleWindow();
	glPopMatrix();
}

void drawBuilding15(int closeUp) {
       // the WG building
   if (closeUp) {
	   glScalef(4, 4, 4);
	   glTranslatef(-0.2, 0, 2);
   }
   else {
	   glScalef(.22, .3, .31);
       glTranslatef(-7.5, 1.26, 9.8);
	   glRotatef(90, 0, 1, 0);
	   glTranslatef(-0.2, 0, 2);
   }
   drawShell();
   drawLeftWall();
   drawAngledWall();
   drawEdgeWall();
}


