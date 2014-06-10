#include "drawBuildings.h"

#include "Angel.h"
#define _USE_MATH_DEFINES

// Minkwan Choi.
// 3/01/2013
// TCSS 458
// Project3 - 1
// building 30, coffee shop and train cross.

double degree_90 =  M_PI / 2;
int cut_num = 10;
float frame_color[] = { 0.62745098039, 0.32156862745, 0.17647058823};
float building_color[] = { 0.69803921568, 0.32156862745, 0};
float orange_color[]={1,0.27058823529,0};
float gray_color[]={0.46666666666,0.46666666666,0.46666666666};
float white_color[]={.88888,.88888,.88888};
float black_color[]={.11111,.11111,.11111};
float yellow_color[]={1,0.8431372549,0};
float window_frame_y = 4.5;


static void arch(int the_cut_num, double the_starting_degree, double the_degree_increase_ratio,double the_x, double the_y){
	glPushMatrix();
	double current_degree = the_starting_degree;
	for(int i = 0; i < the_cut_num; i++){

		glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
		glVertex3d(the_x, the_y, 1);
		glVertex3d(cos(current_degree), sin(current_degree), 1);
		glVertex3d(cos(current_degree + the_degree_increase_ratio), sin(current_degree + the_degree_increase_ratio), 1);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3d(the_x, the_y, -1);
		glVertex3d(cos(current_degree), sin(current_degree), -1);
		glVertex3d(cos(current_degree + the_degree_increase_ratio), sin(current_degree + the_degree_increase_ratio), -1);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3d(-the_x, the_y, 1);
		glVertex3d(-cos(current_degree), sin(current_degree), 1);
		glVertex3d(-cos(current_degree + the_degree_increase_ratio), sin(current_degree + the_degree_increase_ratio), 1);
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex3d(-the_x, the_y, -1);
		glVertex3d(-cos(current_degree), sin(current_degree), -1);
		glVertex3d(-cos(current_degree + the_degree_increase_ratio), sin(current_degree + the_degree_increase_ratio), -1);
		glEnd();
		current_degree += the_degree_increase_ratio;
	}

	current_degree = the_starting_degree;

	for(int i = 0; i< the_cut_num * 2; i++){
		glNormal3f(-cos( current_degree +the_degree_increase_ratio/2),-sin( current_degree +the_degree_increase_ratio/2),0);

		glBegin(GL_POLYGON);
		glVertex3d(cos(current_degree), sin(current_degree), 1);
		glVertex3d(cos(current_degree), sin(current_degree), -1);
		glVertex3d(cos(current_degree + the_degree_increase_ratio), sin(current_degree + the_degree_increase_ratio), -1);
		glVertex3d(cos(current_degree + the_degree_increase_ratio), sin(current_degree + the_degree_increase_ratio),1);


		glEnd();
		current_degree += the_degree_increase_ratio;

	}
	glPopMatrix();
}

static void windowFrame(){
	glPushMatrix();
	//bottom block
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, gray_color);
	glPushMatrix();
	glTranslatef(0, -1.9, 0);
	glScalef(2, .2, 2);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	//top block
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(2, 1, 2);
	glutSolidCube(1);
	glPopMatrix();

	//bottom block
	glPushMatrix();
	glTranslatef(0, -2.25, 0);
	glScalef(2, .5, 2);
	glutSolidCube(1);
	glPopMatrix();

	//right block
	glPushMatrix();
	glTranslatef(1.25, -.25, 0);
	glScalef(.5, window_frame_y, 2);
	glutSolidCube(1);
	glPopMatrix();

	//left block
	glPushMatrix();
	glTranslatef(-1.25, -.25, 0);
	glScalef(.5, window_frame_y, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

}

static void windowFrame2(){
	glPushMatrix();
	//bottom block
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, gray_color);
	glPushMatrix();
	glTranslatef(0, -1.9, 0);
	glScalef(2, .2, 2);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	//top block
	glPushMatrix();
	glTranslatef(0, 1.375, 0);
	glScalef(2, 1.25, 2);
	glutSolidCube(1);
	glPopMatrix();

	//bottom block
	glPushMatrix();
	glTranslatef(0, -2.25, 0);
	glScalef(2, .5, 2);
	glutSolidCube(1);
	glPopMatrix();

	//right block
	glPushMatrix();
	glTranslatef(1.25, -.25, 0);
	glScalef(.5, window_frame_y, 2);
	glutSolidCube(1);
	glPopMatrix();

	//left block
	glPushMatrix();
	glTranslatef(-1.25, -.25, 0);
	glScalef(.5, window_frame_y, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

}

static void windowArchType1(){
	glPushMatrix();


	windowFrame();

	double start_degree = 0;
	double degee_increase_ratio = degree_90 / cut_num;
	arch(cut_num, start_degree, degee_increase_ratio, 1, 1);

	glPopMatrix();
}

static void windowArchType2(){
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	windowFrame();

	double start_degree =  degree_90 / 2;
	double degee_increase_ratio = (degree_90 - start_degree)/ cut_num;
	glTranslatef(0, -1/sin(start_degree) + 1, 0);
	glScalef(1/cos(start_degree),1/ sin(start_degree),1);
	arch(cut_num, start_degree, degee_increase_ratio,cos(start_degree), 1);
	
	glPopMatrix();
}

static void windowArchType3(){
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	windowFrame();
	
	double start_degree =  degree_90 / 3 * 2;
	double degee_increase_ratio = (degree_90 - start_degree)/ cut_num;
	glTranslatef(0, -1/sin(start_degree) + 1, 0);
	glScalef(1/cos(start_degree),1/ sin(start_degree),1);
	arch(cut_num, start_degree, degee_increase_ratio,cos(start_degree), 1);
	
	glPopMatrix();
}

static void smallWindowArchType2(){
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	windowFrame2();

	double start_degree =  degree_90 / 2;
	double degee_increase_ratio = (degree_90 - start_degree)/ cut_num;
	glTranslatef(0, -1/sin(start_degree) + .75, 0);
	glScalef(1/cos(start_degree),1/ sin(start_degree),1);
	arch(cut_num, start_degree, degee_increase_ratio,cos(start_degree), 1);
	
	glPopMatrix();
}

static void smallWindowArchType3(){
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	windowFrame2();
	
	double start_degree =  degree_90 / 3 * 2;
	double degee_increase_ratio = (degree_90 - start_degree)/ cut_num;
	glTranslatef(0, -1/sin(start_degree) + .75 , 0);
	glScalef(1/cos(start_degree),1/ sin(start_degree),1);
	arch(cut_num, start_degree, degee_increase_ratio,cos(start_degree), 1);
	
	glPopMatrix();
}

static void mirroType1(){
	glPushMatrix();
	glTranslatef(0,0,-.5);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);

	glPushMatrix();
	glTranslatef(0, -.5, 0);

	glScalef(.3, 3, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.1, 0);
	glScalef(2, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.9, 0);
	glScalef(2, .125, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

static void mirroType2(){	
	glPushMatrix();
	
	glTranslatef(0,0,-.5);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);

	glPushMatrix();
	glTranslatef(0, -.5, 0);

	glScalef(.3, 3, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.5, 0);
	glScalef(2, .125, 1);
	glutSolidCube(1);
	glPopMatrix();
	
	glPopMatrix();
}

static void mirroArch(){


	int frame_num = 5;
	double angle = degree_90 / 3;
	double current_degree = angle;


	for (int i = 0; i < frame_num; i ++){
		glPushMatrix();

		glTranslatef(cos(current_degree), sin(current_degree), 0);
		glRotatef(30 * (i+1), 0,0,1);
		glScalef(2, .2, 1);
		glutSolidCube(1);
		glPopMatrix();
		current_degree += angle;
	}

	glPushMatrix();
	glScalef(4, .25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.75, -2.5, 0);
	glScalef(.20, 5, 1);
	glutSolidCube(1);
	glPopMatrix();

}

static void mirroType3(){
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);
	
	glPushMatrix();
	glTranslatef(0,0,-.5);
	glScalef(.5,.5,1);

	mirroArch();
	
	glPushMatrix();
	glTranslatef(.75, -2.5, 0);
	glScalef(.25, 5, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glScalef(4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

static void mirroType4(){
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);
	
	glPushMatrix();
	glTranslatef(0,0,-.5);
	glScalef(.5,.5,1);

	mirroArch();
	glPushMatrix();
	glTranslatef(-1.5, -1, 0);
	glScalef(1.3, .2, 1);
	glutSolidCube(1);
	glPopMatrix();


	///



	glPushMatrix();
	glTranslatef(-.1, -2.5, 0);
	glScalef(.175, 5, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.6, -2.5, 0);
	glScalef(.2, 5, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.3, -2.5, 0);
	glScalef(.175, 5, 1);
	glutSolidCube(1);
	glPopMatrix();

	//


	glPushMatrix();
	glTranslatef(.75, -.8, 0);
	glScalef(2.75, .175, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.75, -1.5, 0);
	glScalef(2.75, .175, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.75, -2.3, 0);
	glScalef(2.75, .175, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.75, -3.0, 0);
	glScalef(2.75, .175, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

static void mirroType5(){	
	glPushMatrix();
	
	glTranslatef(0,.75,-.5);
	glScalef(.5,.5,1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);


	glPushMatrix();
	glTranslatef(0, -2.5, 0);
	glScalef(.25, 6.2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.8, 0);
	glScalef(4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glScalef(4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

static void mirroType6(){	
	glPushMatrix();
	
	glTranslatef(0,.75,-.5);
	glScalef(.5,.5,1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);

	
	glPushMatrix();
	glTranslatef(0, -.8, 0);
	glScalef(4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glScalef(4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

static void mirroType7(){	
	glPushMatrix();
	
	glTranslatef(0,0.15,-.5);
	glScalef(.5,.5,1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);

	

	glPushMatrix();
	glScalef(4, .25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.75, -2.5, 0);
	glScalef(.20, 5, 1);
	glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(.75, -2.5, 0);
	glScalef(.25, 5, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glScalef(4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
}

static void windowFrame3(){
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
    glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	//top block
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(2, 1, 2);
	glutSolidCube(1);
	glPopMatrix();


	//right block
	glPushMatrix();
	glTranslatef(1.25, -.25, 0);
	glScalef(.5, window_frame_y, 2);
	glutSolidCube(1);
	glPopMatrix();

	//left block
	glPushMatrix();
	glTranslatef(-1.25, -.25, 0);
	glScalef(.5, window_frame_y, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

}

static void doorArch(){
	glPushMatrix();


	windowFrame3();

	double start_degree = 0;
	double degee_increase_ratio = degree_90 / cut_num;
	arch(cut_num, start_degree, degee_increase_ratio, 1, 1);

	glPopMatrix();
}

// left door
static void door1(){
	glPushMatrix();
	glScalef(.5, .5, .2);
	glPushMatrix();
	glTranslatef(0,0,-.5);
	glScalef(.5,.5,1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray_color);
	mirroArch();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);
	doorArch();
	glPopMatrix();
}

// 4-1 window
static void window4to1(){
	
	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType3();
	windowArchType1();
	glPopMatrix();
}

static void window4to2(){
	
	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType4();
	windowArchType1();
	glPopMatrix();
}

//2-1 window
static void window2to1(){
	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType1();
	windowArchType2();
	glPopMatrix();
}

static void window1to4(){

	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType2();
	windowArchType3();
	glPopMatrix();
}

//4-2window
static void window4to3(){

	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType1();
	smallWindowArchType2();
	glPopMatrix();
}

//4-2window
static void window3to1(){

	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType2();
	smallWindowArchType3();
	glPopMatrix();
}

static void backWindow2(){
	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType5();
	windowFrame();
	glPopMatrix();

}

static void backWindow1(){
	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType6();
	windowFrame();
	glPopMatrix();

}

static void backWindow3(){
	glPushMatrix();
	glScalef(.5, .5, .2);
	mirroType7();
	windowArchType3();
	glPopMatrix();

}

static void frontFace(){
	for(int floor = 0; floor < 4; floor++){
		for(int win_num = 0; win_num < 6; win_num++){
				
			glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);
			glPushMatrix();
			glTranslatef(win_num*1.4, floor * 2.25, 0);
			if(win_num > 1 && win_num <4){
				glTranslatef(-.2, 0, 0);
			} else if(win_num > 3){
				glTranslatef(-.365, 0, 0);
			}
			if(win_num == 2 || win_num == 3){
				glScalef(0.65,1,1);
			}

			window2to1();
			glPopMatrix();
		}

	}
	glPushMatrix();
	glNormal3f(0,0,1);

	glBegin(GL_POLYGON);
	glVertex3d(-1, 7.75,.2);
	glVertex3d(-.75, 7.75,.2);
	glVertex3d(-.75, -1.25,.2);
	glVertex3d(-1, -1.25,.2);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3d(3, 7.75,.2);
	glVertex3d(3.6, 7.75,.2);
	glVertex3d(3.6, -1.25,.2);
	glVertex3d(3, -1.25,.2);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3d(7.35, 7.75,.2);
	glVertex3d(8, 7.75,.2);
	glVertex3d(8, -1.25,.2);
	glVertex3d(7.35, -1.25,.2);
	glEnd();

	glPopMatrix();


}

static void rightFace(){
	for(int floor = 0; floor < 4; floor++){
		for(int win_num = 0; win_num < 9; win_num++){
				
			glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);
			glPushMatrix();
			glTranslatef(win_num*1.4, floor * 2.25, 0);

			if(win_num > 1){
				glTranslatef(-.2, 0, 0);
			}
			if(win_num >2){
				glTranslatef(.5 *(win_num -2), 0, 0);
			}

			if(win_num > 6){
				glTranslatef(-.4*(win_num -6), 0, 0);
				if(win_num == 8){
					glTranslatef(-.55, 0, 0);
				}
			
			}
	

			if(win_num >6){
				glScalef(0.65,1,1);
			}

			if(floor == 3){
				if(win_num == 0){
					window4to1();
				} else if(win_num < 3 || win_num >6){
					window4to2();
				} else {
					window4to3();
				}

			} else if(floor == 2){
				window3to1();

			} else if(floor == 1){
				if(win_num > 6){
					window4to1();
				} else {
					window2to1();
				}

			} else {
				if(win_num <3){
					if(win_num == 1){
						door1();
					}else {
					
						window4to1();
					}
				}else {
					window1to4();
				}
			}

			glPopMatrix();
		}

	}
	glPushMatrix();
	glNormal3f(0,0,1);

	glBegin(GL_POLYGON);
	glVertex3d(-1, 7.75,.2);
	glVertex3d(-.75, 7.75,.2);
	glVertex3d(-.75, -1.25,.2);
	glVertex3d(-1, -1.25,.2);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3d(3.2, 7.75,.2);
	glVertex3d(3.8, 7.75,.2);
	glVertex3d(3.8, -1.25,.2);
	glVertex3d(3.2, -1.25,.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(5.2, 7.75,.2);
	glVertex3d(5.8, 7.75,.2);
	glVertex3d(5.8, -1.25,.2);
	glVertex3d(5.2, -1.25,.2);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(7, 7.75,.2);
	glVertex3d(7.7, 7.75,.2);
	glVertex3d(7.7, -1.25,.2);
	glVertex3d(7, -1.25,.2);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(9, 7.75,.2);
	glVertex3d(9.5, 7.75,.2);
	glVertex3d(9.5, -1.25,.2);
	glVertex3d(9, -1.25,.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(10.8, 7.75,.2);
	glVertex3d(11.3, 7.75,.2);
	glVertex3d(11.3, -1.25,.2);
	glVertex3d(10.8, -1.25,.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(13, 7.75,.2);
	glVertex3d(13.5, 7.75,.2);
	glVertex3d(13.5, -1.25,.2);
	glVertex3d(13, -1.25,.2);
	glEnd();

	//for right roof

	glBegin(GL_POLYGON);
	glVertex3d(-1, 7.75, .2);
	glVertex3d(13.5, 7.75, .2);
	glVertex3d(13.5, 8.75, .2);
	glEnd();
	glPopMatrix();
	
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
//	glMaterialfv(GL_FRONT, GL_AMBIENT,frame_color);
	glPushMatrix();
	glTranslatef(3.5, 3.25, .3);
	glScalef(.25, 9, .2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(7.375, 3.25, .3);
	glScalef(.25, 9, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11, 3.25, .3);
	glScalef(.25, 9, .2);
	glutSolidCube(1);
	glPopMatrix();
}

static void backFace(){
	for(int floor = 0; floor < 4; floor++){
		for(int win_num = 0; win_num < 5; win_num++){
				
			glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, frame_color);
			glPushMatrix();
			glTranslatef(win_num*1.4, floor * 2.25, 0);

			if(win_num == 4){
				glTranslatef(-.4, 0, 0);
			} else if(win_num > 0){
				glTranslatef(-.2, 0, 0);
			}

			if(win_num == 0 || win_num ==4){
				glScalef(0.65,1,1);
			}

			if(win_num == 0 || win_num == 4){
				backWindow1();
			} else if(win_num == 1 ||win_num == 3){
					backWindow2();
			} else {
				if (floor == 0){
					door1();
				} else {
					backWindow3();
				}	
			}
			glPopMatrix();
		}

	}
	glPushMatrix();
	glNormal3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3d(-.75, 7.75,.2);
	glVertex3d(-.4, 7.75,.2);
	glVertex3d(-.4, -1.25,.2);
	glVertex3d(-.75, -1.25,.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(5.6, 7.75,.2);
	glVertex3d(5.89, 7.75,.2);
	glVertex3d(5.89, -1.25,.2);
	glVertex3d(5.6, -1.25,.2);
	glEnd();


	glPopMatrix();
}

static void leftFace(){
	glPushMatrix();
	glNormal3f(-1,0,0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	glBegin(GL_POLYGON);
	glVertex3d(-1, 7.75,-6.75);
	glVertex3d(-1, 7.75,7.2);
	glVertex3d(-1, -1.25,7.2);
	glVertex3d(-1, -1.25,-6.75);
	glEnd();
	glPopMatrix();
}

static void base(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);

	double floor_height = (7.75 + 1.25)/4;

	for(int i = 0; i < 5; i++){
		glPushMatrix();
		glNormal3f(0,1,0);
		glBegin(GL_POLYGON);
		glVertex3d(-1, (i*floor_height) - 1.25, -6.75);
		glVertex3d(-1, (i*floor_height) - 1.25, 7.2);
		glVertex3d(9.05, (i*floor_height) - 1.25, 7.2);
		glVertex3d(5.3, (i*floor_height) - 1.25, -6.75);
		glEnd();
		glPopMatrix();
	}


}

static void roof(){
	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, building_color);
	//for top
	glNormal3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3d(-1, 8.75, -6.75);
	glVertex3d(-1, 7.75, 7.2);
	glVertex3d(9.05, 7.75, 7.2);
	glVertex3d(5.3, 8.75, -6.75);
	glEnd();

	//for back
	glNormal3f(0,0,-1);
	glBegin(GL_POLYGON);
	glVertex3d(-1, 8.75, -6.75);
	glVertex3d(-1, 7.75, -6.75);
	glVertex3d(5.3, 7.75, -6.75);
	glVertex3d(5.3, 8.75, -6.75);
	glEnd();

	//for left
	glNormal3f(-1,0,0);
	glBegin(GL_POLYGON);
	glVertex3d(-1, 7.75, 7.2);
	glVertex3d(-1, 8.75, -6.75);
	glVertex3d(-1, 7.75, -6.75);
	glEnd();

}

static void building(){
	//front face
	glPushMatrix();
	glTranslatef(.12,0,7);
	glScaled(1.12,1,1);
	frontFace();
	glPopMatrix();
	//right face
	glPushMatrix();
	glTranslatef(8.6,0,6.30);
	glRotatef(105,0,1,0);
	rightFace();
	glPopMatrix();

	//backface
	glPushMatrix();
	glTranslatef(4.6,0,-6.5);
	glRotatef(180,0,1,0);
	glScalef(.95,1,1);
	backFace();
	glPopMatrix();
	//left face
	glPushMatrix();
	leftFace();
	glPopMatrix();
	//base...
	glPushMatrix();
	base();
	glPopMatrix();

	glPushMatrix();
	roof();
	glPopMatrix();

	//mirrow
	glPushMatrix();
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.22222, 0.22222, 0.22222, 0.40);
	glDisable(GL_LIGHTING);

	glPushMatrix();
	//front mirrow
	glTranslatef(.12,0,7);
	glScaled(1.12,1,1);
	glBegin(GL_POLYGON);
	glVertex3d(-.75, 7.75,-.2);
	glVertex3d(7.35, 7.75,-.2);
	glVertex3d(7.35, -1.25,-.2);
	glVertex3d(-.75, -1.25,-.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//right mirrow
		glTranslatef(8.6,0,6.30);
	glRotatef(105,0,1,0);
	glBegin(GL_POLYGON);
	glVertex3d(-.75, 7.75,-.2);
	glVertex3d(13, 7.75,-.2);
	glVertex3d(13, -1.25,-.2);
	glVertex3d(-.75, -1.25,-.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//back mirrow
	glTranslatef(4.6,0,-6.5);
	glRotatef(180,0,1,0);
	glScalef(.95,1,1);
	glBegin(GL_POLYGON);
	glVertex3d(-.4, 7.75,-.2);	
	glVertex3d(5.6, 7.75,-.2);
	glVertex3d(5.6, -1.25,-.2);
	glVertex3d(-.4, -1.25,-.2);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glPopMatrix();



}

static void circle(){
	int cut_num = 9;
	double start_angle = 0;
	double angle_ratio = degree_90 / cut_num;
	double current_degree = start_angle;

	for(int i = 0; i <  cut_num*4; i++){
		glPushMatrix();

		glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
		glVertex3d(0, 0, .5);
		glVertex3d(cos(current_degree), sin(current_degree), .5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio), .5);
		glEnd();

		glNormal3f(0,0,-1);
		glBegin(GL_POLYGON);
		glVertex3d(0, 0, -.5);
		glVertex3d(cos(current_degree), sin(current_degree), -.5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio), -.5);
		glEnd();


		glNormal3f(cos( current_degree +angle_ratio/2),sin( current_degree +angle_ratio/2),0);
		 glBegin(GL_POLYGON);
		glVertex3d(cos(current_degree), sin(current_degree), .5);
		glVertex3d(cos(current_degree), sin(current_degree), -.5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio), -.5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio),.5);


		glEnd();
		current_degree += angle_ratio;
			glPopMatrix();
	}

	


}

static void corn(){
	int cut_num = 9;
	double start_angle = 0;
	double angle_ratio = degree_90 / cut_num;
	double current_degree = start_angle;

	for(int i = 0; i <  cut_num*4; i++){
		glPushMatrix();
		if(i%2 == 1){
			glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
		} else {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, yellow_color);
		}
		glNormal3f(cos( current_degree +angle_ratio/2), sin( current_degree +angle_ratio/2),1);
		glBegin(GL_POLYGON);
		glVertex3d(0, 0, 1);
		glVertex3d(cos(current_degree), sin(current_degree), .5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio), .5);
		glEnd();

		glNormal3f(0,0,-1);
		glBegin(GL_POLYGON);
		glVertex3d(0, 0, -.5);
		glVertex3d(cos(current_degree), sin(current_degree), -.5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio), -.5);
		glEnd();

		if(i%2 == 1){
			glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, yellow_color);
		} else {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
			glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
		}
		glNormal3f(cos( current_degree +angle_ratio/2),sin( current_degree +angle_ratio/2),0);
		 glBegin(GL_POLYGON);
		glVertex3d(cos(current_degree), sin(current_degree), .5);
		glVertex3d(cos(current_degree), sin(current_degree), -.5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio), -.5);
		glVertex3d(cos(current_degree + angle_ratio), sin(current_degree + angle_ratio),.5);


		glEnd();
		current_degree += angle_ratio;
			glPopMatrix();
	}

	


}

static void crossSign(){
	glPushMatrix();
	glScalef(.3,.3, .3);

	glPushMatrix();
	glTranslatef(0, -4, 0);
	glRotatef(-90,1,0,0);
	glScalef(2,2, 1);
	corn();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange_color);

	glPushMatrix();
	glTranslatef(-1.5, 0, .8);
	glScalef(.3,.3,.3);
	circle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5, 0, .8);
	glScalef(.3,.3,.3);
	circle();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, black_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, black_color);
	glPushMatrix();
	glTranslatef(1.5, 0, .25);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0, .25);
	glutSolidCube(1);
	glPopMatrix();
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT,yellow_color);

	glPushMatrix();
	glScalef(.5,8, .5);
	glutSolidCube(1);
	glPopMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT,gray_color);
	glPushMatrix();
	glTranslatef(0,0,.1);
	glScalef(3,.5, .55);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, white_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT,white_color);
	glPushMatrix();
	glTranslatef(0,3.5,.25);
	glPushMatrix();
	glRotatef(60,0,0,1);
	glScalef(.7,4.5, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-60,0,0,1);
	glScalef(.7,4.5, .2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

		glPopMatrix();

}

void drawBuilding30(int closeUp) {
	if(closeUp == 0){
		glTranslatef(-.7,.19,-2.85);

		glRotatef(-15, 0,1,0);
		glScalef(.125,.15,.125);
	} else {
		glTranslatef(-5,-3,1);
		glScalef(.7,.7,.7);
	}

	building();


	glPushMatrix();
	glTranslatef(12.25, .125, 9);
	glRotatef(15, 0,1,0);
	crossSign();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11, .125, 5);

	glRotatef(195, 0,1,0);
	crossSign();
	glPopMatrix();
}



