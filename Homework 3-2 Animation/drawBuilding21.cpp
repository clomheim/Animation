//Doug Lomehim
#include "drawBuildings.h"

#include "Angel.h"

void createBeam21() {

	float pane_color[] = {0.333, 0.412, 0.604};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, pane_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, pane_color);
	glPushMatrix();
	glScalef(.1,1,.01);
	glutSolidCube(2);
	glPopMatrix();


}

void createWindowPanel21_1() {
	//single window
	float pane_color[] = {0.333, 0.412, 0.604};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, pane_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, pane_color);
	
	glPushMatrix();
	glTranslatef(.5,0,0);
	glScalef(0.01, 1, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5,0,0);
	glScalef(0.01, 1, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,.99,0);
	glScalef(.5, .01, .01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-.99,0);
	glScalef(.5, .01, .01);
	glutSolidCube(2);
	glPopMatrix();

}

void createWindowPanel21_2() {
	//triple windows
	float pane_color[] = {0.333, 0.412, 0.604};

	glMaterialfv(GL_FRONT, GL_DIFFUSE, pane_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, pane_color);

	glPushMatrix();
	glTranslatef(.5,0,0);
	glScalef(0.01, 1, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5,0,0);
	glScalef(0.01, 1, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,0);
	glScalef(0.01, 1, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	glScalef(0.01, 1, 0.01);
	glutSolidCube(2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,.99,0);
	glScalef(1, 0.01, 0.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-.99,0);
	glScalef(1, 0.01, 0.01);
	glutSolidCube(2);
	glPopMatrix();
}

void createSinglePane21() {

	glPushMatrix();
	glTranslatef(-1.4,0,0);
	createWindowPanel21_1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,0,0);
	createWindowPanel21_1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.6,0,0);
	createWindowPanel21_1();
	glPopMatrix();

	createWindowPanel21_2();

	glPushMatrix();
	glTranslatef(.6,0,0);
	createWindowPanel21_1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0,0);
	createWindowPanel21_1();
	glPopMatrix();
}

void createArch21() {
	int i;
	for(i=0; i<5;i++) {
		glPushMatrix();
		glTranslatef(0,-2*i,0);
		createWindowPanel21_2();
		glPopMatrix();
	
		if(i < 3) {
			glPushMatrix();
			glTranslatef(1.5,-2*i,0);
			createWindowPanel21_1();
			glPopMatrix();
	
			glPushMatrix();
			glTranslatef(2.5,-2*i,0);
			createWindowPanel21_1();
			glPopMatrix();	

			glPushMatrix();
			glTranslatef(3.1,-2*i,0);
			createBeam21();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(3.6,-2*i,0);
			createWindowPanel21_1();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(4.6,-2*i,0);
			createWindowPanel21_1();
			glPopMatrix();
	
			glPushMatrix();
			glTranslatef(5.6,-2*i,0);
			createWindowPanel21_1();
			glPopMatrix();
		}
	}

}

void createPanel21_2(int x) {

	float pane_color[] = {0.333, 0.412, 0.604};

	int i;
	for(i=0; i<x;i++) {
		glPushMatrix();
		glTranslatef(0,-2*i,0);
		createWindowPanel21_2();
		glPopMatrix();
	
		
		glPushMatrix();
		glTranslatef(1.5,-2*i,0);
		createWindowPanel21_1();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(2.5,-2*i,0);
		createWindowPanel21_1();
		glPopMatrix();	

		glPushMatrix();
		glTranslatef(3.1,-2*i,0);
		createBeam21();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(3.6,-2*i,0);
		createWindowPanel21_1();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(4.6,-2*i,0);
		createWindowPanel21_1();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(5.6,-2*i,0);
		createWindowPanel21_1();
		glPopMatrix();

		if(i%3 == 2) {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, pane_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, pane_color);

			glPushMatrix();
			glTranslatef(3.5,-2*i - .5,0);
			glScalef(2.505,.01,.01);
			glutSolidCube(2);
			glPopMatrix();
		}
	}
}

void createPanel21_3() {
	int i;
	for(i=0; i < 8; i++) {
		glPushMatrix();
		glTranslatef(0,-2*i,0);
		createWindowPanel21_2();
		glPopMatrix();
	}
}

void createPanel21_4() {
	int i;

	float pane_color[] = {0.333, 0.412, 0.604};

	for(i=0; i < 8; i++) {
		glPushMatrix();
		glTranslatef(0,-2*i,0);
		createWindowPanel21_1();
		glPopMatrix();
		if(i%3 == 2) {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, pane_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, pane_color);

			glPushMatrix();
			glTranslatef(0,-2*i - .5,0);
			glScalef(.5,.01,.01);
			glutSolidCube(2);
			glPopMatrix();
		}
	}

	glPushMatrix();
	glTranslatef(0,-15.5,0);
	glScalef(1,.5,1);
	createWindowPanel21_1();
	glPopMatrix();
}

void createPanel21_5(){
	int i, j;

	float pane_color[] = {0.333, 0.412, 0.604};

	for(i=0; i<4;i++){
		for(j=0; j < 9; j++) {
			if(j ==8 ) {
				glPushMatrix();
				glTranslatef(i,-15.5,0);
				glScalef(1,.5,1);
				createWindowPanel21_1();
				glPopMatrix();
			} else {
				glPushMatrix();
				glTranslatef(i,-2*j,0);
				createWindowPanel21_1();
				glPopMatrix();
				
				if(j%3 == 2) {
					glMaterialfv(GL_FRONT, GL_DIFFUSE, pane_color);
					glMaterialfv(GL_FRONT, GL_AMBIENT, pane_color);

					glPushMatrix();
					glTranslatef(i,-2*j - .5,0);
					glScalef(.5,.01,.01);
					glutSolidCube(2);
					glPopMatrix();
				}
			}
		}
	}

	
}

void createPanes21() {
	int i;
	
	glPushMatrix();
	glTranslatef(-1.15,.35,0);
	glScalef(.047,.047,1);
	createArch21();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.81875,0.35,0);
	glScalef(.047,.047,1);
	createArch21();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.4875,.35,0);
	glScalef(.047,.047,1);
	createPanel21_2(6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.156,.35,0);
	glScalef(.047,.047,1);
	createPanel21_2(7);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.1775,.35,0);
	glScalef(.047,.047,1);
	createPanel21_3();
	glPopMatrix();

	//beginnning of offset
	glPushMatrix();
	glTranslatef(.23,.35,.03);
	glRotatef(-90, 0,1,0);
	glScalef(.047,.047,1);
	createPanel21_4();
	glPopMatrix();
	
	//Front of offset
	glPushMatrix();
	glTranslatef(.25,.35,.05);
	glScalef(.047,.047,1);
	createPanel21_5();
	glPopMatrix();

	//Side of offset
	glPushMatrix();
	glTranslatef(.41,.35,.03);
	glRotatef(90, 0,1,0);
	glScalef(.047,.047,1);
	createPanel21_5();
	glPopMatrix();

	//back of offset
	glPushMatrix();
	glTranslatef(.39,.35,-.13);
	glScalef(.047,.047,1);
	createPanel21_4();
	glPopMatrix();

	//back to building
	//back of offset
	glPushMatrix();
	glTranslatef(.37,.35,-.15);
	glRotatef(90,0,1,0);
	glScalef(.047,.047,1);
	createPanel21_4();
	glPopMatrix();
}

void build21() {
	float window_color[] = {.1, .1, .2};
	float brick_color[] = {1, 0.55, 0.35};
	float cement_color[] = {.655,.675,.749};

	//Brick Back wall
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);

	glPushMatrix();
	glTranslatef(-.41,0,-.07);
	glScalef(.79,.4,.01);
	glutSolidCube(2);
	glPopMatrix();

	//WindowPanes
	glPushMatrix();
	glTranslatef(0,0,.11);
	createPanes21();
	glPopMatrix();

	

	//Cement
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cement_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, cement_color);
	
	glPushMatrix();
	glTranslatef(-.865,-.24,0);
	glScalef(.335,.17,.12);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.37,-.29,0);
	glScalef(.1675,.12,.12);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.035,-.335,0);
	glScalef(.1675,.075,.12);
	glutSolidCube(2);
	glPopMatrix();

	//Roof
	glPushMatrix();
	glTranslatef(-.41,.4,0);
	glRotatef(90,1,0,0);
	glScalef(.79,.11,.01);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.32,.4,.07);
	glRotatef(90,1,0,0);
	glScalef(.085,.085,.01);
	glutSolidCube(2);
	glPopMatrix();

	//Glass Walkway
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glPushMatrix();
	glTranslatef(-.42,0,0);
	glScalef(.78,.4, .11);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.32,0,.07);
	glScalef(.085,.4,.085);
	glutSolidCube(2);
	glPopMatrix();
	glDisable(GL_BLEND);

}

void drawBuilding21(int closeUp) {
   // Science SouthSide
   if (closeUp) {
       //glScalef(20,20,20);
	   glScalef(10,10,10);
   } else {
       glTranslatef(2.5,.5,-2);
	   glRotatef(-98,0,1,0);
   }
	
   //Put building back at orgin
   glTranslatef(.485,0,0);
   build21();
}