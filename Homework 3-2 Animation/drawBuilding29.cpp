#include "drawBuildings.h"

#include "Angel.h"

void drawBuilding29(int closeUp) {
       // the Tioga Library Building
	   //Author:  Craig Apfelbeck
	   //Very basic placeholder with proper orientation and translation
	   //I borrowed the 'brickBlock' color from drawBuilding30.building_color to ensure they would match
   
   float brickBlock[] = { 0.69803921568, 0.32156862745, 0 };
   float greyBlock[] = {.4,.4,.4};

   glMaterialfv(GL_FRONT, GL_DIFFUSE, brickBlock);
   glMaterialfv(GL_FRONT, GL_AMBIENT, brickBlock);

   if (closeUp) {
       glScalef(7.5,6,6.9);
   } else {
	   glScalef(1, .6, 1);
   }

   glTranslatef(-2.3, 1.4, -3.45);
   glRotated(255, 0, 1, 0);

   glutSolidCube(2);

   glMaterialfv(GL_FRONT, GL_DIFFUSE, greyBlock);
   glMaterialfv(GL_FRONT, GL_AMBIENT, greyBlock);

   glScalef(.99, .21, .99);
   glTranslatef(0, -5.8, 0);

   glutSolidCube(2);
}