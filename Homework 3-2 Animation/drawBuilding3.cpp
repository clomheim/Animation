#include "drawBuildings.h"


void window();
void roof();
void Wall();
void roof3();
void sideWall();
void drawbuilding();

#include "Angel.h"

void drawBuilding3(int closeUp) {
       // the Harmon
	//roof3();
	
   if (closeUp) {
	   //glTranslatef(-2,0,-.25);
		//glTranslatef(0,0,0);
		glScaled(.3,1.5,.3);
	   //glScaled(5,5,5);
	   //Wall();

	   //window();
   }else {
	   // Place them into the block
	   //One Side Building
		///sideWall();
		//printf("CloseUp 1");
		//glTranslatef(-1.75,0,-.15);

		printf("CloseUp 1");
		glTranslatef(-1.9,0,-.25);
		glScaled(.1,.3,.1);
		//glScaled(1,1,1);
		
	}	
   drawbuilding();
}
 void drawbuilding()
 {
	 glPushMatrix();
		//top right roof
			glRotatef (0, 1.0,0.0,0.0);
			glRotatef (90-17, 0.0,1.0,0.0);
			glRotatef (0, 0.0,0.0,1.0);
		//glTranslatef(5,3.75,2);
			glTranslatef(5,3.65,3);
		glPushMatrix();
		glScaled(4.5,1,20);
		roof3();
	glPopMatrix();
glPopMatrix();

	 glPushMatrix();
		//top left roof
		glRotatef (0, 1.0,0.0,0.0);
		glRotatef (-18, 0.0,1.0,0.0);
		glRotatef (0, 0.0,0.0,1.0);
		//glTranslatef(5,3.65,3);
		glTranslatef(-12,3.6,8);
		glPushMatrix();
		glScaled(5.2,1,17);
		roof3();
	glPopMatrix();
glPopMatrix();

	 glPushMatrix();
			//glTranslatef(-9.5,0,2);
			glTranslatef(-16,0,-5.5);
			//glScalef(1,1,.3);
			glRotatef (0, 1.0,0.0,0.0);
			glRotatef (90-17, 0.0,1.0,0.0);
			glRotatef (0, 0.0,0.0,1.0);

	 glPushMatrix();
		//back wall done
		glScaled(7,.4,.3);
		Wall();
		glPopMatrix();
	glPopMatrix();	
	 	glPushMatrix();
		glPushMatrix();
		glPushMatrix();
		glRotatef (0, 1.0,0.0,0.0);
		glRotatef (-18, 0.0,1.0,0.0);
		glRotatef (0, 0.0,0.0,1.0);
					glPushMatrix();
					//back wall done
					glTranslatef(-6.0,0,-9);
					//glScaled(7,.425,.3);
					glScaled(8.5,.4,.3);
					Wall();
					glPopMatrix();
			glTranslatef(-2,0,-1);
			glScalef(.3,.3,.3);
			//glScaled(1,1,1);
			//First Window
			glPushMatrix();
				glTranslatef(9.5,2.5,0);
				window();
			glPopMatrix();
			glPushMatrix();
				//done
				glTranslatef(15.5,2.5,0);
				glScaled(2,1,1.5);
				Wall();
			glPopMatrix();

			//Second Window
			glPushMatrix();
				glTranslatef(0,2.5,0);
				window();//done
			glPopMatrix();
				glPushMatrix();
				//done
				glTranslatef(4.75,2.5,0);
				glScaled(1,1,1.5);
				Wall();
			glPopMatrix();
			
			//Third Window
			glPushMatrix();
				glTranslatef(-9.5,2.5,0);
				window();//dome
			glPopMatrix();
			//Wall
			glPushMatrix();
				//done
				glTranslatef(-4.75,2.5,0);
				glScaled(1,1,1.5);
				Wall();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-15.5,2.5,0);
				glScaled(2,1,1.5);
				Wall();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0,0,-.20);
				glScaled(18,2.5,1.5);
				sideWall();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0,11.5,-.20);
				glScaled(18,1,1.5);
				sideWall();
			glPopMatrix();
		glPopMatrix();
		//glMaterialfv(5);
	glPopMatrix();
	//2nd building
	 glPushMatrix();
			glTranslatef(-8.75,0,2.25);
			glScalef(.3,.27,.3);
			glRotatef (0, 1.0,0.0,0.0);
			glRotatef (90-17, 0.0,1.0,0.0);
			glRotatef (0, 0.0,0.0,1.0);


			//glScaled(1,1,1);
			//First Window

			glPushMatrix();
				glTranslatef(9.5,2.5,0);
				window();
			glPopMatrix();
			glPushMatrix();
				//done
				glTranslatef(15.5,2.5,0);
				glScaled(2,1,1.5);
				Wall();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(3.5,2.5,0);
				glScaled(2,1,1.5);
				Wall();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(9.5,0,-.20);
				glScaled(8.5,2.5,1.5);
				sideWall();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(9.5,11.5,-.20);
				//glScaled(18,1,1.5);
				glScaled(8.5,2.5,1.5);
				sideWall();
			glPopMatrix();

				glPopMatrix();

		glPopMatrix();


		glPopMatrix();
	glPopMatrix();
 }
// roof
void roof3()
{
	glPushMatrix();	

	float CollorMat128[] = { 1, 0, 0};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, CollorMat128);
	glMaterialfv(GL_FRONT, GL_AMBIENT, CollorMat128);
		glPushMatrix();
			glBegin(GL_TRIANGLES);
				glVertex3f(-1, 0, 0);
				glVertex3f(0, 1, 0);
				glVertex3f(1, 0, 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();	
			glBegin(GL_TRIANGLES);
				glVertex3f(-1, 0, -1);
				glVertex3f(0, 1, -1);
				glVertex3f(1, 0, -1);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			float CollorMat138[] = { .9, .9, .9};
			glMaterialfv(GL_FRONT, GL_DIFFUSE, CollorMat138);
			glMaterialfv(GL_FRONT, GL_AMBIENT, CollorMat138);
			glTranslated(0.02,.08,-.5);
			glRotatef (0, 1.0,0.0,0.0);
			glRotatef (0, 0.0,1.0,0.0);
			glRotatef (45, 0.0,0.0,1.0);
			glScaled(1.2,1.4,1);
			glBegin(GL_QUADS);
				glPushMatrix();
					glVertex3f(0.5f, 0.5f, -0.5f);
					glVertex3f(0.5f, 0.5f, 0.5f);
					glVertex3f(0.5f, -0.5f, 0.5f);
					glVertex3f(0.5f, -0.5f, -0.5f);
				glPopMatrix();
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glTranslated(0.02,.08,-.5);
			glRotatef (0, 1.0,0.0,0.0);
			glRotatef (0, 0.0,1.0,0.0);
			glRotatef (180-45, 0.0,0.0,1.0);
			glScaled(1.2,1.4,1);
			glBegin(GL_QUADS);
				glPushMatrix();
					glVertex3f(0.5f, 0.5f, -0.5f);
					glVertex3f(0.5f, 0.5f, 0.5f);
					glVertex3f(0.5f, -0.5f, 0.5f);
					glVertex3f(0.5f, -0.5f, -0.5f);
				glPopMatrix();
			glEnd();
		glPopMatrix();
	glPopMatrix();
}
void Wall()
{
	glPushMatrix();
		float CollorMat118[] = { 1, 0, 0};
		glMaterialfv(GL_FRONT, GL_DIFFUSE, CollorMat118);
		glMaterialfv(GL_FRONT, GL_AMBIENT, CollorMat118);
		glPushMatrix();
			glTranslatef(0,4.5 ,.5);
			glScalef(2.5,9,1);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
}
void sideWall(){
	// left window walls 
	glPushMatrix();
		float CollorMat107[] = { 1, 0, 0};
		glMaterialfv(GL_FRONT, GL_DIFFUSE, CollorMat107);
		glMaterialfv(GL_FRONT, GL_AMBIENT, CollorMat107);
		glPushMatrix();
			glTranslatef(0,.5,.642);
			glScalef(2,1,1);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
}
void window()
{
	// Windows
	glPushMatrix();
		float CollorMat1[] = { 1, 1, 1};
		glMaterialfv(GL_FRONT, GL_DIFFUSE, CollorMat1);
		glMaterialfv(GL_FRONT, GL_AMBIENT, CollorMat1);

		glPushMatrix();
			glTranslatef(0,4.5,.5);
			glScalef(7,9,1);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	
	// left window walls 
	glPushMatrix();
	float CollorMat104[] = { .8, .8, .8};
		glMaterialfv(GL_FRONT, GL_DIFFUSE, CollorMat104);
		glMaterialfv(GL_FRONT, GL_AMBIENT, CollorMat104);
			glPushMatrix();
				glTranslatef(0,9,.642);
				glScalef(7,.142,1.284);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();
		// left window 2nd wall 2nd
	glPushMatrix();
				
	glPushMatrix();
	
	glTranslatef(0,8,.642);
	glScalef(7,.142,1.284);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	// left window wall 3rd
	glPushMatrix();
		glPushMatrix();
		glTranslatef(0,7,.642);
		glScalef(7,.142,1.284);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
		glPushMatrix();

		glPushMatrix();
		glTranslatef(0,6,.642);
		glScalef(7,.342,1.284);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	//  first Window Walls
		glPushMatrix();

		glPushMatrix();
		glTranslatef(-3.5,4.5 ,.642);
		glScalef(.1,9,1);
		glutSolidCube(1);
		glPopMatrix();
		glPopMatrix();
		//  Last Window Walls
		glPushMatrix();

		glPushMatrix();
		glTranslatef(3.5,4.5 ,.642);
		glScalef(.1,9,1);
		glutSolidCube(1);
		glPopMatrix();
		glPopMatrix();

	
		glPushMatrix();
		glTranslatef(-2.5,4.5 ,.642);
		glScalef(.1,9,1);
		glutSolidCube(1);
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(-1.5,4.5 ,.642);
		glScalef(.15,9,1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.5,4.5 ,.642);
		glScalef(.1,9,1);
		glutSolidCube(1);
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(1.5,4.5 ,.642);
		glScalef(.15,9,1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.5,7.5 ,.642);
		glScalef(.15,3,1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.5,7.5 ,.642);
		glScalef(.15,3,1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0,7.5 ,.642);
		glScalef(.15,3,1);
		glutSolidCube(1);
		glPopMatrix();
}