#include "drawBuildings.h"

#include "Angel.h"

void drawBuilding26(int closeUp) {
       // the Harmon
   
   float grayMat[] = {.75, .75, .75};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, grayMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, grayMat);

    //Back
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1.5,-1.7,-18.5);
       glScalef(17,17.5,1);
   } else {
	   glTranslatef(-3.5/25.0 + 9,10.3/25.0,-16.5/25.0 + 1);
       glScalef(17.0/25.0,17.5/25.0,1.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   //Floor
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(2,-9,-2);
       glScalef(24,3,34);
   } else {
	   glTranslatef(0 + 9,3.0/50.0,0 + 1);
	   glScalef(24.0/25.0,3.0/25.0,34.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   //RightWall
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.45,-1.7,.5);
       glScalef(1.1,17.5,19);
   } else {
	   glTranslatef(7.45/25.0 + 9,10.3/25.0,2.5/25 + 1);
	   glScalef(1.1/25.0,17.5/25.0,19.0/25.0);
   }

    glBegin(GL_QUADS);

      // Right face (x = 1.0f)
      glVertex3f(-2,  .5f, -.5f);
      glVertex3f(.5f,  .5f,  .5f);
      glVertex3f(.5f, -.5f,  .5f);
      glVertex3f(-2, -.5f, -.5f);

	  // Left face (x = -1.0f)
      glVertex3f(-.5f,  .5f,  .5f);
      glVertex3f(-3,  .5f, -.5f);
      glVertex3f(-3, -.5f, -.5f);
      glVertex3f(-.5f, -.5f,  .5f);

	  // Back face (z = -1.0f)
      glVertex3f( -2, -.5f, -.5f);
      glVertex3f(-3, -.5f, -.5f);
      glVertex3f(-3,  .5f, -.5f);
      glVertex3f( -2,  .5f, -.5f);

	  // Front face  (z = 1.0f)
      glVertex3f( .5f,  .5f, .5f);
      glVertex3f(-.5f,  .5f, .5f);
      glVertex3f(-.5f, -.5f, .5f);
      glVertex3f( .5f, -.5f, .5f);

	  // Bottom face (y = -1.0f)
      glVertex3f( .5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f,  .5f);
      glVertex3f(-3, -.5f, -.5f);
      glVertex3f( -2, -.5f, -.5f);

	  // Top face (y = 1.0f)
	  glVertex3f(-2, .5f, -.5f);
      glVertex3f(-3, .5f, -.5f);
      glVertex3f(-.5f, .5f,  .5f);
      glVertex3f( .5f, .5f,  .5f);
   glEnd();
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(6.7,-1.7,-14);
       glScalef(1.1,17.5,10);
   } else {
	   glTranslatef(4.7/25.0 + 9,10.3/25.0,-12.0/25.0 + 1);
       glScalef(1.1/25.0,17.5/25.0,10/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   //Ceiling
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(0,3.5,.5);
       glScalef(20,2,19);
   } else {
	   glTranslatef(-2.0/25.0 + 9,15.5/25.0,2.5/25.0 + 1);
       glScalef(20.0/25.0,2.0/25.0,19.0/25.0);
   }

   glBegin(GL_QUADS);

      // Right face (x = 1.0f)
      glVertex3f(0.35f,  .5f, -.5f);
      glVertex3f(.5f,  .5f,  .5f);
      glVertex3f(.5f, -.5f,  .5f);
      glVertex3f(0.35f, -.5f, -.5f);

	  // Left face (x = -1.0f)
      glVertex3f(-.5f,  .5f,  .5f);
      glVertex3f(-.5f,  .5f, -.5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f(-.5f, -.5f,  .5f);

	  // Back face (z = -1.0f)
      glVertex3f( 0.35f, -.5f, -.5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f(-.5f,  .5f, -.5f);
      glVertex3f( 0.35f,  .5f, -.5f);

	  // Front face  (z = 1.0f)
      glVertex3f( .5f,  .5f, .5f);
      glVertex3f(-.5f,  .5f, .5f);
      glVertex3f(-.5f, -.5f, .5f);
      glVertex3f( .5f, -.5f, .5f);

	  // Bottom face (y = -1.0f)
      glVertex3f( .5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f( 0.35f, -.5f, -.5f);

	  // Top face (y = 1.0f)
	  glVertex3f(0.35f, .5f, -.5f);
      glVertex3f(-.5f, .5f, -.5f);
      glVertex3f(-.5f, .5f,  .5f);
      glVertex3f( .5f, .5f,  .5f);
   glEnd(); 
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1.5,3.5,-14);
       glScalef(17,2,10);
   } else {
	   glTranslatef(-3.5/25.0 + 9,15.5/25.0,-12/25.0 + 1);
       glScalef(17.0/25.0,2.0/25.0,10.0/25.0);
   }
   glutSolidCube(1);
   glPopMatrix();
   //Roof Rails
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-9.5,6.7,9);
	   glRotatef(90,0,1,0);
   } else {
	   glTranslatef(-11.5/25.0 + 9,18.7/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,0,1,0);
   }

   glutSolidCylinder(.06, 18.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-9.5,6.3,9);
	   glRotatef(90,0,1,0);
   } else {
	   glTranslatef(-11.5/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,0,1,0);
   }

   glutSolidCylinder(.06, 18.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-9.5,4.8,9);
	   glRotatef(90,0,1,0);
   } else {
	   glTranslatef(-11.5/25.0 + 9,16.8/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,0,1,0);
   }

   glutSolidCylinder(.06, 18.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-9.4,6.8,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-11.4/25.0 + 9,18.8/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.12, 2.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-8.77,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-10.77/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-8.14,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-10.14/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-7.51,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-9.51/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-6.88,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-8.88/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-6.25,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-8.25/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-5.6,6.8,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-7.6/25.0 + 9,18.8/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.12, 2.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-4.97,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-6.97/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-4.34,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-6.34/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-3.71,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-5.71/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-3.08,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-5.08/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-2.45,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-4.45/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1.8,6.8,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-3.8/25.0 + 9,18.8/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.12, 2.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1.17,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-3.17/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-0.54,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-2.54/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(0.09,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-1.91/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(0.72,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-1.28/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(1.35,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(-.65/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(2,6.8,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(0/25.0 + 9,18.8/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.12, 2.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(2.63,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(.63/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(3.26,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(1.26/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(3.89,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(1.89/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(4.52,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(2.52/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(5.15,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(3.15/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(5.8,6.8,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(3.8/25.0 + 9,18.8/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }
  
   glutSolidCylinder(.12, 2.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(6.43,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(4.43/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(7.06,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(5.06/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(7.69,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(5.69/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(8.32,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(6.32/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(8.99,6.3,9);
	   glRotatef(90,1,0,0);
   } else {
	   glTranslatef(6.99/25.0 + 9,18.3/25.0,11.0/25.0 + 1);
       glScalef(1.0/25.0,1.0/25.0,1.0/25.0);
	   glRotatef(90,1,0,0);
   }

   glutSolidCylinder(.04, 1.5, 50, 50);
   glPopMatrix();

   //Bottom Stairs
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.45,-7.3,-3.5);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,12);
   } else {
	   glTranslatef(8.45/25.0 + 9,3.3/25.0,-1.5/25.0 + 1);
	   glRotatef(9,0,1,0);
       glScalef(5.0/25.0,.6/25.0,12.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.39,-6.7,-4);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,11);
   } else {
	   glTranslatef(8.39/25.0 + 9,3.9/25.0,-2/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,11.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.33,-6.1,-4.5);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,10);
   } else {
	   glTranslatef(8.33/25.0 + 9,4.5/25.0,-2.5/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,10.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.27,-5.5,-5);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,9);
   } else {
	   glTranslatef(8.27/25.0 + 9,5.1/25.0,-3/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,9.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.21,-4.9,-5.5);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,8);
   } else {
	   glTranslatef(8.21/25.0 + 9,5.7/25.0,-3.5/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,8.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.15,-4.3,-6);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,7);
   } else {
	   glTranslatef(8.15/25.0 + 9,6.3/25.0,-4/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,7.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.09,-3.7,-6.5);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,6);
   } else {
	   glTranslatef(8.09/25.0 + 9,6.9/25.0,-4.5/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,6.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(10.03,-3.1,-7);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,5);
   } else {
	   glTranslatef(8.03/25.0 + 9,7.5/25.0,-5/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,5.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.97,-2.5,-7.5);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,4);
   } else {
	   glTranslatef(7.97/25.0 + 9,8.1/25.0,-5.5/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,4.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.91,-1.9,-8);
	   glRotatef(9,0,1,0);
	   glScalef(5,.6,3);
   } else {
	   glTranslatef(7.91/25.0 + 9,8.7/25.0,-6/25.0 + 1);
	   glRotatef(9,0,1,0);
	   glScalef(5.0/25.0,.6/25.0,3.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,-4.6,-14);
	   glScalef(5,6,10);
   } else {
	   glTranslatef(7.6/25.0 + 9,6.0/25.0,-12/25.0 + 1);
	   glScalef(5.0/25.0,6.0/25.0,10.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,-1.3,-15);
	   glScalef(5,.6,8);
   } else {
	   glTranslatef(7.6/25.0 + 9,9.3/25.0,-13.0/25.0 + 1);
	   glScalef(5.0/25.0,.6/25.0,8.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,-.7,-15.5);
	   glScalef(5,.6,7);
   } else {
	   glTranslatef(7.6/25.0 + 9,9.9/25.0,-13.5/25.0 + 1);
	   glScalef(5.0/25.0,.6/25.0,7.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,-.1,-16);
	   glScalef(5,.6,6);
   } else {
	   glTranslatef(7.6/25.0 + 9,10.5/25.0,-14.0/25.0 + 1);
	   glScalef(5.0/25.0,.6/25.0,6.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,.5,-16.5);
	   glScalef(5,.6,5);
   } else {
	   glTranslatef(7.6/25.0 + 9,11.1/25.0,-14.5/25.0 + 1);
	   glScalef(5.0/25.0,.6/25.0,5.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,1.1,-17);
	   glScalef(5,.6,4);
   } else {
	   glTranslatef(7.6/25.0 + 9,11.7/25.0,-15.0/25.0 + 1);
	   glScalef(5.0/25.0,.6/25.0,4.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(9.6,1.7,-17.5);
	   glScalef(5,.6,3);
   } else {
	   glTranslatef(7.6/25.0 + 9,12.3/25.0,-15.5/25.0 + 1);
	   glScalef(5.0/25.0,.6/25.0,3.0/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   //Top Stairs

   //Front
   float blueMat[] = {0, .3, .4};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, blueMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, blueMat);

   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-9.6,-3,4);
	   glScalef(.8,10,.2);
   } else {
	   glTranslatef(-11.6/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.8/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-7.3,-3,4);
	   glScalef(.3,10,.2);
   } else {
	   glTranslatef(-9.3/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.3/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-5,-3,4);
	   glScalef(.8,10,.2);
   } else {
	   glTranslatef(-7.0/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.8/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-2.7,-3,4);
	   glScalef(.3,10,.2);
   } else {
	   glTranslatef(-4.7/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.3/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(1,-3,4);
	   glScalef(.8,10,.2);
   } else {
	   glTranslatef(-1/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.8/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(3.3,-3,4);
	   glScalef(.3,10,.2);
   } else {
	   glTranslatef(1.3/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.3/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(5.6,-3,4);
	   glScalef(.8,10,.2);
   } else {
	   glTranslatef(3.6/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.8/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(8.1,-3,4);
	   glScalef(.8,10,.2);
   } else {
	   glTranslatef(6.1/25.0 + 9,7.6/25.0,6.0/25.0 + 1);
	   glScalef(.8/25.0,10.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-0.75,1.5,4);
	   glScalef(18.5,2,.2);
   } else {
	   glTranslatef(-2.75/25.0 + 9,13.5/25.0,6.0/25.0 + 1);
	   glScalef(18.5/25.0,2.0/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-0.75,-2,4);
	   glScalef(18.5,.4,.2);
   } else {
	   glTranslatef(-2.75/25.0 + 9,9.9/25.0,6.0/25.0 + 1);
	   glScalef(18.5/25.0,.4/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-6.2,-4.5,4);
	   glScalef(7,.4,.2);
   } else {
	   glTranslatef(-8.2/25.0 + 9,6.5/25.0,6.0/25.0 + 1);
	   glScalef(7.0/25.0,.4/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(4.5,-4.5,4);
	   glScalef(7,.4,.2);
   } else {
	   glTranslatef(2.5/25.0 + 9,6.5/25.0,6.0/25.0 + 1);
	   glScalef(7.0/25.0,.4/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-6.2,-7.1,4);
	   glScalef(7,.8,.2);
   } else {
	   glTranslatef(-8.2/25.0 + 9,3.4/25.0,6.0/25.0 + 1);
	   glScalef(7.0/25.0,.8/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(4.5,-7.1,4);
	   glScalef(7,.8,.2);
   } else {
	   glTranslatef(2.5/25.0 + 9,3.4/25.0,6.0/25.0 + 1);
	   glScalef(7.0/25.0,.8/25.0,.2/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   //door frame
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1,-7.3,4.05);
	   glScalef(3.1,.4,.3);
   } else {
	   glTranslatef(-3.0/25.0 + 9,3.2/25.0,6.05/25.0 + 1);
	   glScalef(3.1/25.0,.4/25.0,.3/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1,-2.5,4.05);
	   glScalef(3,.8,.3);
   } else {
	   glTranslatef(-3.0/25.0 + 9,9.4/25.0,6.05/25.0 + 1);
	   glScalef(3.0/25.0,1/25.0,.3/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(-2.2,-5,4.05);
	   glScalef(.7,5.8,.3);
   } else {
	   glTranslatef(-4.2/25.0 + 9,6.6/25.0,6.05/25.0 + 1);
	   glScalef(.7/25.0,6.5/25.0,.3/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();

   if (closeUp) {
	   glTranslatef(0.5,-5,4.05);
	   glScalef(.7,5.8,.3);
   } else {
	   glTranslatef(-1.7/25.0 + 9,6.6/25.0,6.05/25.0 + 1);
	   glScalef(.7/25.0,6.5/25.0,.3/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();
   //windows

   float windowSurface[] = { .1, .27, .46 };

   glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
   glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);

  //enable blending for translucent effect
  glEnable(GL_BLEND); 
  glBlendFunc(GL_ONE, GL_ONE);
  glPushMatrix();

   if (closeUp) {
	   glTranslatef(-1,-3.5,4);
	   glScalef(18,10,.1);
   } else {
	   glTranslatef(-3.0/25.0 + 9,8.5/25.0,6.0/25.0 + 1);
	   glScalef(18.0/25.0,10.0/25.0,.1/25.0);
   }

   glutSolidCube(1);
   glPopMatrix();

   glDisable(GL_BLEND);
   
}