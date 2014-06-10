#include "drawBuildings.h"

#include "Angel.h"

/*
My Anh Hoang
Project 3 Milestone 1
TCSS 458
Library number 4 both wall
*/

float color[] = { 0.7, 0.7, 0.7 };//silver base pole
float color2[] = { 0.51, 0.12, 0.15};//red brick wall
float color3[] = {0.51, 0.2, 0.15};//brick pole
float color4[] = {1, 0.6, 0};//orange
double PI = 3.14;

void squareWindowBrick()
{
	glPushMatrix();
	glTranslatef(2, .9, -0.4);
	glScalef(0.4, 0.1, 0.035);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutSolidCube(2);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(2, 1.4, -0.4);
	glScalef(0.4, 0.1, 0.035);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutSolidCube(2);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(1.75, 1.1, -0.4);
	glScalef(0.1, 0.2, 0.035);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutSolidCube(2);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(2.25, 1.1, -0.4);
	glScalef(0.1, 0.2, 0.035);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutSolidCube(2);
	glPopMatrix();
}

void windowframe1()
{
	// middle bar top down
	glPushMatrix();
	glTranslatef(0, -.2, 0);	
	glScalef(.01, .8, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// left bar top down 1
	glPushMatrix();
	glTranslatef(-.07, -.2, 0);	
	glScalef(.01, .8, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// left bar top down 2
	glPushMatrix();
	glTranslatef(-.14, -.2, 0);	
	glScalef(.01, .8, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar top down 1
	glPushMatrix();
	glTranslatef(.14, -.2, 0);	
	glScalef(.01, .8, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar top down 2
	glPushMatrix();
	glTranslatef(.07, -.2, 0);	
	glScalef(.01, .8, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// middle bar left right
	glPushMatrix();
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// left bar left right 1
	glPushMatrix();
	glTranslatef( 0,-.07, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// left bar left right 2
	glPushMatrix();
	glTranslatef(0,-.14, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 1
	glPushMatrix();
	glTranslatef( 0, .14,0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 2
	glPushMatrix();
	glTranslatef(0,.07, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 3
	glPushMatrix();
	glTranslatef(0,-0.21, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 4
	glPushMatrix();
	glTranslatef(0,-0.28, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 5
	glPushMatrix();
	glTranslatef(0,-0.35, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 5
	glPushMatrix();
	glTranslatef(0,-0.42, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
	// right bar left right 5
	glPushMatrix();
	glTranslatef(0,-0.49, 0);	
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(1);
	glPopMatrix();
}
void windowframe2()
{
	// middle bar top down
	glPushMatrix();
	glScalef(.01, 0.5, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	//
	glPushMatrix();
	glScalef(.8, 0.01, 0.01);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
}
void archVault(int numPieces, double r ) {
	 int i;
	 
	 vec4 normal;
	 double angle = 0, angInc = PI/numPieces;
	 angle = 0;
	 for (i = 0; i < numPieces; i++) {
	     //glNormal3f(-cos(angle+angInc/2),-sin(angle+angInc/2),0);
	     glBegin(GL_POLYGON);
         glNormal3f(-cos(angle),-sin(angle),0);
	     glVertex3f(r*cos(angle), r*sin(angle)-0.5, 0.5);
         glNormal3f(-cos(angle+angInc),-sin(angle+angInc),0);
	     glVertex3f(r*cos(angle+angInc), r*sin(angle+angInc)-0.5,  0.5);
	     glVertex3f(r*cos(angle+angInc), r*sin(angle+angInc)-0.5, -0.5);
	     glEnd();
	     glBegin(GL_POLYGON);
		 glVertex3f(r*cos(angle+angInc), r*sin(angle+angInc)-0.5, -0.5 );
         glNormal3f(-cos(angle),-sin(angle),0);
	     glVertex3f(r*cos(angle), r*sin(angle)-0.5, -0.5);
	     glVertex3f(r*cos(angle), r*sin(angle)-0.5, 0.5);
	     glEnd();
		  angle += angInc;
	 }

}

void archFace(int numPieces, double r, double z, vec4 normal) {
	 int i;
	 double angle = 0, angInc = PI/numPieces;
	 angle = 0;
	 glNormal3f(normal.x, normal.y, normal.z);
	 for (i = 0; i < numPieces/2; i++) {
	     glBegin(GL_POLYGON);
	     //glNormal3f(normal.x, normal.y, normal.z);
	     glVertex3f(r,0,z);
	     glVertex3f(r*cos(angle), r*sin(angle)-0.5, z);
	     glVertex3f(r*cos(angle+angInc), r*sin(angle+angInc)-0.5, z);
	     glEnd();
	     glBegin(GL_POLYGON);
	     //glNormal3f(normal.x, normal.y, normal.z);
	     glVertex3f(-r,0,z);
	     glVertex3f(r*cos(PI/2+angle), r*sin(PI/2+angle)-0.5, z);
	     glVertex3f(r*cos(PI/2+angle+angInc), r*sin(PI/2+angle+angInc)-0.5, z);
	     glEnd();
		  angle += angInc;
	 }
	 glBegin(GL_POLYGON);
	 glVertex3f(-r,0,z);
	 glVertex3f(0,0,z);
	 glVertex3f(r,0,z);
	 glBegin(GL_POLYGON);
	 glEnd();
}

void arch() {
	 double r = 0.5;
	 int numPieces = 100;
	 //vec4 v1 = vertices[b] - vertices[a];
	 //vec4 v2 = vertices[c] - vertices[a];
	 //vec4 normal = cross(v1,v2);
	 vec4 normForw(0,0,1,0);
	 vec4 normBackw(0,0,-1,0);

	 glTranslatef(0,0.5,0);
	 archFace(numPieces, r, r, normForw);
	 archFace(numPieces, r, -r, normBackw);
	 archVault(numPieces, r);

	 glPushMatrix();
	 glTranslatef(0,0.25,0);
	 glScalef(1,0.5,1);
	 glutSolidCube(1);
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(-0.75,-0.5,0);
	 glScalef(0.5,2,1);
	 glutSolidCube(1);
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(0.75,-0.5,0);
	 glScalef(0.5,2,1);
	 glutSolidCube(1);
	 glPopMatrix();
}

void building4Wall1()
{
	
	// top silver
	glPushMatrix();
	glTranslatef(0, 1.5, -0.4);
	glScalef(2.5, 0.10, 0.12);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// bottom silver
	glPushMatrix();
	glTranslatef(0, 0.08, -0.4);
	glScalef(2.5, 0.02, 0.12);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 1
	glPushMatrix();
	glTranslatef(-2.4, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 2
	glPushMatrix();
	glTranslatef(-1.6, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 3
	glPushMatrix();
	glTranslatef(-0.8, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 4
	glPushMatrix();
	glTranslatef(0, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 5
	glPushMatrix();
	glTranslatef(0.8, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 6
	glPushMatrix();
	glTranslatef(1.6, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side bottom silvers 7
	glPushMatrix();
	glTranslatef(2.4, 0, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// small silver block 1
	glPushMatrix();
	glTranslatef(-2.4, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix(); 
	// small silver block 2
	glPushMatrix();
	glTranslatef(-1.6, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// small silver block 3
	glPushMatrix();
	glTranslatef(-0.8, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// small silver block 4
	glPushMatrix();
	glTranslatef(0, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// small silver block 5
	glPushMatrix();
	glTranslatef(0.8, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// small silver block 6
	glPushMatrix();
	glTranslatef(1.6, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// small silver block 7
	glPushMatrix();
	glTranslatef(2.4, 0.2, -0.3);
	glScalef(0.02, 0.02, 0.02);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// left side brick pole 1
	glPushMatrix();
	glTranslatef(-2.4, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();

	// left side brick pole 2
	glPushMatrix();
	glTranslatef(-1.6, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();
	// left side brick pole 3
	glPushMatrix();
	glTranslatef(-0.8, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();
	// left side brick pole 4
	glPushMatrix();
	glTranslatef(0, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();
	// left side brick pole 5
	glPushMatrix();
	glTranslatef(0.8, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();
	// left side brick pole 6
	glPushMatrix();
	glTranslatef(1.6, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();
	// left side brick pole 7
	glPushMatrix();
	glTranslatef(2.4, .7, -0.4);
	glScalef(0.07, 0.7, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color3);
	glutSolidCube(2);
	glPopMatrix();
	// side top silvers 1
	glPushMatrix();
	glTranslatef(-2.4, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();

	// side top silvers 2
	glPushMatrix();
	glTranslatef(-1.6, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side top silvers 3
	glPushMatrix();
	glTranslatef(-.8, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side top silvers 4
	glPushMatrix();
	glTranslatef(0, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side top silvers 5
	glPushMatrix();
	glTranslatef(0.8, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side top silvers 6
	glPushMatrix();
	glTranslatef(1.6, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// side top silvers 7
	glPushMatrix();
	glTranslatef(2.4, 1.35, -0.4);
	glScalef(0.08, 0.08, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	//arch window 1
	glPushMatrix();
	glTranslatef(-2, .5, -0.4);
	glScalef(0.35, 0.55, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	arch();	
	glPopMatrix();    
	glPushMatrix();
	glTranslatef(-2, .6, -0.4);
	windowframe1();
	glPopMatrix();  
	glPushMatrix();
	glTranslatef(-4, 0, 0);
	squareWindowBrick();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2, 1.2, -0.4);
	glScalef(.5,.5,.5);
	windowframe2();
	glPopMatrix();
	// under windows silver brick
	glPushMatrix();
	glTranslatef(-2, 1.07, -0.3);
	glScalef(.2, 0.02, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// top windows long silver brick
	glPushMatrix();
	glTranslatef(-2, 0.9, -0.3);
	glScalef(.05, 0.1, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// arch windows 2
	glPushMatrix();
	glTranslatef(-1.2, .7, -0.4);
	glScalef(0.35, 0.7, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	arch();	
	glPopMatrix();    
	glPushMatrix();
	glTranslatef(-1.2, .6, -0.4);
	windowframe1();
	glPopMatrix(); 
	glPushMatrix();
	glTranslatef(-1.2, 1.1, -0.4);
	windowframe1();
	glPopMatrix();
	// top windows long silver brick
	glPushMatrix();
	glTranslatef(-1.2, 1.15, -0.3);
	glScalef(.05, 0.1, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// arch windows 3
	glPushMatrix();
	glTranslatef(-0.4, .7, -0.4);
	glScalef(0.35, 0.7, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	arch();	
	glPopMatrix();    
	glPushMatrix();
	glTranslatef(-0.4, .6, -0.4);
	windowframe1();
	glPopMatrix(); 
	glPushMatrix();
	glTranslatef(-0.4, 1.1, -0.4);
	windowframe1();
	glPopMatrix();
	// top windows long silver brick
	glPushMatrix();
	glTranslatef(-0.4, 1.15, -0.3);
	glScalef(.05, 0.1, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// arch windows 4
	glPushMatrix();
	glTranslatef(0.4, .7, -0.4);
	glScalef(0.35, 0.7, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	arch();	
	glPopMatrix();    
	glPushMatrix();
	glTranslatef(0.4, .6, -0.4);
	windowframe1();
	glPopMatrix(); 
	glPushMatrix();
	glTranslatef(0.4, 1.1, -0.4);
	windowframe1();
	glPopMatrix();
	// top windows long silver brick
	glPushMatrix();
	glTranslatef(0.4, 1.15, -0.3);
	glScalef(.05, 0.1, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// arch windows 5
	glPushMatrix();
	glTranslatef(1.2, .7, -0.4);
	glScalef(0.35, 0.7, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	arch();	
	glPopMatrix();    
	glPushMatrix();
	glTranslatef(1.2, .6, -0.4);
	windowframe1();
	glPopMatrix(); 
	glPushMatrix();
	glTranslatef(1.2, 1.1, -0.4);
	windowframe1();
	glPopMatrix();
	// top windows long silver brick
	glPushMatrix();
	glTranslatef(1.2, 1.15, -0.3);
	glScalef(.05, 0.1, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	//arch window 6
	glPushMatrix();
	glTranslatef(2, .5, -0.4);
	glScalef(0.35, 0.55, 0.08);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	arch();	
	glPopMatrix();    
	glPushMatrix();
	glTranslatef(2, .6, -0.4);
	windowframe1();
	glPopMatrix();  
	squareWindowBrick();
	glPushMatrix();
	glTranslatef(2, 1.2, -0.4);
	glScalef(.5,.5,.5);
	windowframe2();
	glPopMatrix();
	// under windows silver brick
	glPushMatrix();
	glTranslatef(2, 1.07, -0.3);
	glScalef(.2, 0.02, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// top windows long silver brick
	glPushMatrix();
	glTranslatef(2, 0.9, -0.3);
	glScalef(.05, 0.1, 0.05);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glutSolidCube(2);
	glPopMatrix();
	// bottom bricks
	glPushMatrix();
	glTranslatef(0, 0.01, -0.4);
	glScalef(2.45, 0.07, 0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutSolidCube(2);
	glPopMatrix();
	  
}

void building4Wall2()
{
	glPushMatrix();
	glTranslatef(0, 0, -3.6);
	glRotatef(180, 0, 1, 0);
	building4Wall1();
	glPopMatrix();
}
//place holder building
void buildingcube()
{
	//roof
	glPushMatrix();
	glScalef(4.8, .1, 2.6);
	glTranslatef(0, 15, -.7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color4);
	glutSolidCube(1);
	glPopMatrix();
	//wall #6
	glPushMatrix();
	glScalef(.1, 1.5, 2.7);
	glTranslatef(24, .5, -.66);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color4);
	glutSolidCube(1);
	glPopMatrix();
	//wall #6
	glPushMatrix();
	glScalef(.1, 1.5, 2.7);
	glTranslatef(-24, .5, -.66);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color4);
	glutSolidCube(1);
	glPopMatrix();
}
void drawBuilding4(int closeUp) {
	// the Harmon
	
	if (closeUp == 1 ) 
	{
		glScalef(4, 4, 4);
		glTranslatef(0, 0, 2.5);
	}
	else 
	{
		glTranslatef(.20,0,.4);

		glRotatef(73, 0,1,0);
		glScalef(.35,.30,.30);
		
	}
	building4Wall1();
	building4Wall2();
	buildingcube();
}


