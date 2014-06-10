#include "drawBuildings.h"

#include "Angel.h"

void drawBuilding7(int closeUp) 
{
       // Keystone Glass part
   float colMat[] = { 0.47, 1, 1};
   //float blueMat[] = { 0.5, 0.5, 0.5};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);

   if (closeUp) 
   {
       glScalef(6,6,6);
   } 
   else 
   {
       glTranslatef(1.75,0.15,1);
	   glScalef(0.25,0.25,0.25);
	   glRotatef(-90,0,1,0);
   }

   //Draw the Glass
   glEnable(GL_BLEND);
   glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);
   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
   glVertex3f(1, 0.5, 0);
   glVertex3f(1,-0.5, 0);
   glVertex3f(-1, -0.5, 0);
   glVertex3f(-1,0.5,0);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
   glVertex3f(1, 0.5, 0);
   glVertex3f(1, 0.5, -1);
   glVertex3f(1,-0.5, -1);
   glVertex3f(1,-0.5, 0);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(-1,0,-1);
   glVertex3f(-1, 0.5, 0);
   glVertex3f(-1, -0.5, 0);
   glVertex3f(-0.75,-0.5, -0.33);
   glVertex3f(-0.75, 0.5, -0.33);
   glEnd();
   glDisable(GL_BLEND);
   
   //Back Wall and floor, to close up the building
   colMat[0]=0.5;
   colMat[1]=0.5;
   colMat[2]=0.5;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
   glVertex3f(1, 0.5, -1);
   glVertex3f(1,-0.5, -1);
   glVertex3f(-0.75, -0.5, -0.33);
   glVertex3f(-0.75,0.5,-0.33);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
   glVertex3f(1, -0.5, -1);
   glVertex3f(1,-0.5, 0);
   glVertex3f(-1, -0.5, 0);
   glVertex3f(-0.75, -0.5,-0.33);
   glEnd();


   //Add details to the glass
   colMat[0]=0.5;
   colMat[1]=0.5;
   colMat[2]=1;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glLineWidth(1.5);
   glNormal3f(0,0,1);
   for(int i = 0; i < 5; i++)
   {
	   glBegin(GL_LINES);
	   glVertex3f(-0.8 + (0.4 * i),0.5,0.01);
	   glVertex3f(-0.8 + (0.4 * i),-0.5,0.01);
	   glEnd();
   }
   for(int i = 0; i < 6; i++)
   {
	   if(i != 3)
	   {
	      glBegin(GL_LINES);
	      glVertex3f(-1,-0.5 + (0.2 * i),0.01);
	      glVertex3f(1,-0.5 + (0.2 * i),0.01);
	      glEnd();
	   }
	   else
	   {
		  glBegin(GL_LINES);
	      glVertex3f(0.2,-0.5 + (0.2 * i),0.01);
	      glVertex3f(1,-0.5 + (0.2 * i),0.01);
	      glEnd();
	   }
   }
   colMat[0]=0.8;
   colMat[1]=0.8;
   colMat[2]=0.8;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex3f(-1,0.1,0.01);
   glVertex3f(0.2,0.1,0.01);
   glEnd();
   for(int i = 0; i < 6; i++)
   {
	   glBegin(GL_LINES);
	   glVertex3f(-1 + (0.4 * i),0.5,0.01);
	   glVertex3f(-1 + (0.4 * i),-0.5,0.01);
	   glEnd();
   }

   // Second glass pane
   colMat[0]=0.5;
   colMat[1]=0.5;
   colMat[2]=1;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glLineWidth(1.5);
   glNormal3f(1,0,0);
   glBegin(GL_LINES);
   glVertex3f(1.01,0.5,0);
   glVertex3f(1.01,-0.5,0);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(1.01,0.5,-0.2);
   glVertex3f(1.01,-0.5,-0.2);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(1.01,0.5,-0.6);
   glVertex3f(1.01,-0.1,-0.6);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(1.01,0.5,-0.8);
   glVertex3f(1.01,-0.1,-0.8);
   glEnd();
   for(int i = 0; i < 6; i++)
   {
	   if(i < 4)
	   {
	      glBegin(GL_LINES);
	      glVertex3f(1.01,0.5 - (0.2*i),0);
	      glVertex3f(1.01,0.5 - (0.2*i),-1);
	      glEnd();
	   }
	   else
	   {
		  glBegin(GL_LINES);
	      glVertex3f(1.01,0.5 - (0.2*i),0);
	      glVertex3f(1.01,0.5 - (0.2*i),-0.4);
	      glEnd();
	   }
   }
   glBegin(GL_LINES);
   glVertex3f(1.01, -0.5,-0.5);
   glVertex3f(1.01,-0.15,-0.5);
   glVertex3f(1.01,-0.15,-0.9);
   glVertex3f(1.01,-0.5,-0.9);
   glVertex3f(1.01,-0.15,-0.5);
   glVertex3f(1.01,-0.15,-0.9);
   glVertex3f(1.01,-0.5,-0.7);
   glVertex3f(1.01,-0.15,-0.7);
   glEnd();
   colMat[0]=0.8;
   colMat[1]=0.8;
   colMat[2]=0.8;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex3f(1.01, 0.5,-0.4);
   glVertex3f(1.01,-0.5,-0.4);
   glEnd();

   // Third glass pane
   colMat[0]=0.5;
   colMat[1]=0.5;
   colMat[2]=1;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glLineWidth(1.5);
   glNormal3f(-1,0,-1);
   glBegin(GL_LINES);
   glVertex3f(-1.01,0.5,0);
   glVertex3f(-1.01,-0.1,0);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(-0.93,0.5,-0.11);
   glVertex3f(-0.93,-0.1,-0.11);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(-0.85,0.5,-0.22);
   glVertex3f(-0.85,-0.1,-0.22);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(-0.76,0.5,-0.33);
   glVertex3f(-0.76,-0.1,-0.33);
   glEnd();
   for(int i = 0; i < 4; i++)
   {
	   glBegin(GL_LINES);
	   glVertex3f(-1.01,0.5 - (0.2*i),0);
	   glVertex3f(-0.76,0.5 - (0.2*i),-0.33);
	   glEnd();
   }
   glBegin(GL_LINES);
   glVertex3f(-0.96, -0.5,-0.055);
   glVertex3f(-0.96,-0.15,-0.055);
   glVertex3f(-0.89,-0.15,-0.165);
   glVertex3f(-0.89,-0.5,-0.165);
   glVertex3f(-0.8,-0.15,-0.275);
   glVertex3f(-0.8,-0.5,-0.275);
   glVertex3f(-0.96,-0.15,-0.055);
   glVertex3f(-0.8,-0.15,-0.275);
   glEnd();

   //Front door roof
   colMat[0]=0.8;
   colMat[1]=0.8;
   colMat[2]=0.8;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, colMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, colMat);
   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
   glVertex3f(1.01,-0.1,-0.4);
   glVertex3f(1.01,-0.1,-1);
   glVertex3f(1.375,-0.1,-1);
   glVertex3f(1.375,-0.1,-0.4);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);
   glVertex3f(1.01,-0.05,-0.4);
   glVertex3f(1.01,-0.05,-1);
   glVertex3f(1.375,-0.05,-1);
   glVertex3f(1.375,-0.05,-0.4);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
   glVertex3f(1.01,-0.1,-0.4);
   glVertex3f(1.375,-0.1,-0.4);
   glVertex3f(1.375,-0.05,-0.4);
   glVertex3f(1.01,-0.05,-0.4);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
   glVertex3f(1.01,-0.1,-1);
   glVertex3f(1.375,-0.1,-1);
   glVertex3f(1.375,-0.05,-1);
   glVertex3f(1.01,-0.05,-1);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
   glVertex3f(1.375,-0.1,-0.4);
   glVertex3f(1.375,-0.05,-0.4);
   glVertex3f(1.375,-0.05,-1);
   glVertex3f(1.375,-0.1,-1);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(1.375,-0.05,-0.4);
   glVertex3f(1.01,0.1,-0.4);
   glEnd();
   glBegin(GL_LINES);
   glVertex3f(1.375,-0.05,-1);
   glVertex3f(1.01,0.1,-1);
   glEnd();

   //Roof
   glBegin(GL_POLYGON);
   glNormal3f(0,-1,0);
   glVertex3f(1.1,0.5,0.1);
   glVertex3f(1.1,0.5,-1);
   glVertex3f(-1.25,0.5,-0.33);
   glVertex3f(-1.5,0.5,0.1);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,0,1);
   glVertex3f(1.1,0.5,0.1);
   glVertex3f(1.1,0.6,0.1);
   glVertex3f(-1.5,0.6,0.1);
   glVertex3f(-1.5,0.5,0.1);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(-1,0,-1);
   glVertex3f(-1.5,0.5,0.1);
   glVertex3f(-1.5,0.6,0.1);
   glVertex3f(-1.25,0.6,-0.33);
   glVertex3f(-1.25,0.5,-0.33);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,0,-1);
   glVertex3f(1.1,0.5,-1);
   glVertex3f(1.1,0.6,-1);
   glVertex3f(-1.25,0.6,-0.33);
   glVertex3f(-1.25,0.5,-0.33);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(1,0,0);
   glVertex3f(1.1,0.5,0.1);
   glVertex3f(1.1,0.5,-1);
   glVertex3f(1.1,0.6,-1);
   glVertex3f(1.1,0.6,0.1);
   glEnd();
   glBegin(GL_POLYGON);
   glNormal3f(0,1,0);
   glVertex3f(1.1,0.6,0.1);
   glVertex3f(1.1,0.6,-1);
   glVertex3f(-1.25,0.6,-0.33);
   glVertex3f(-1.5,0.6,0.1);
   glEnd();
   glLineWidth(7);
   glBegin(GL_LINES);
   glNormal3f(0,0,1);
   glVertex3f(-1.47,0.5,0.07);
   glVertex3f(-1.47,-0.5,0.07);
   glEnd();



   //Pillar
   glRotatef(90,1,0,0);
   glTranslatef(1.05,0.05,-0.5);
   glutSolidCylinder(0.05,1,100,100);
}