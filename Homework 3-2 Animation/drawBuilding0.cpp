#include "drawBuildings.h"

#include "Angel.h"

void drawBuilding0(int closeUp) {
       // the Harmon
   
   float yellowMat[] = { .75, .75, 0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, yellowMat);

   if (closeUp) {
       glScalef(6,6,6);
   } else {
       glTranslatef(-8.5,1,3);
   }

   glutSolidCube(2);
}