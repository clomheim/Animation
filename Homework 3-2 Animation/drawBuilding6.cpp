#include "drawBuildings.h"

#include "Angel.h"

#define BLDG6_X     -0.3
#define BLDG6_Y      1
#define BLDG6_ANGLE  -15

#define PILLAR_WIDTH (1.0/12)
#define PILLAR_CAP_WIDTH  PILLAR_WIDTH * 1.1
#define PILLAR_CAP_HEIGHT PILLAR_WIDTH * 1
#define WALL_CAP_WIDTH    PILLAR_WIDTH * 2
#define WALL_CAP_HEIGHT   PILLAR_WIDTH * 0.5

#define WALL_WIDTH        0.01
#define SILL_WIDTH        0.02
#define WINDOW_WIDTH      1/6.0
#define WINDOW_HEIGHT     0.25

#define BOTTOM_ACCENT_HEIGHT 0.05
#define BOTTOM_ACCENT_LEDGE_HEIGHT 0.01
#define BOTTOM_ACCENT_LEDGE_OVERHANG 0.02

#define ACCENT_BOX_HEIGHT 0.1
#define ACCENT_BOX_WIDTH  0.05
#define ACCENT_BOX_DOWN   0.02

void setMat(const GLfloat* mat);
void drawPillar(const GLfloat x);
void drawWall();
void drawWallCap();
void drawPillars();
void drawSquareWindow(const GLfloat x, const GLfloat y);
void drawBigWindowPanel();
void drawLittleWindowPanel();
void drawBottomAccent();
void doArch();
   
float B6brickMat[]        = { .5, .1, .12, 1};
float B6pillarMat[]       = { .5, .2, .12, 1};
float B6lightaccentMat[]  = { .8, .8, .8, 1};
float B6darkaccentMat[]   = { .1, .1, .1, 1};
float B6glassMat[]        = { .1, .1, .1, .5};

void drawBuilding6(int closeUp) {
  // the Harmon

  if (closeUp) {
    glScalef(10,10,10);
  } else {
    glRotatef(BLDG6_ANGLE,0,1,0);
    glTranslatef(BLDG6_X,0.5,BLDG6_Y);
  }

  drawWall();
  drawWallCap();

  drawPillars();

}

void drawWall() {
  //left
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(-1/3.0,0,0);
    glScalef(1/3.0,1,1);
    drawLittleWindowPanel();
  glPopMatrix();
  //right
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(1/3.0,0,0);
    glScalef(1/3.0,1,1);
    drawLittleWindowPanel();
  glPopMatrix();

  drawBigWindowPanel();
  drawBottomAccent();

  
  //glass
  glPushMatrix();
    setMat(B6glassMat);
    glScalef(1,1,WALL_WIDTH/2);
    glutSolidCube(1);
  glPopMatrix();



  //drawSquareWindow( 1/3.0,WINDOW_HEIGHT);
  //drawSquareWindow(-1/3.0,WINDOW_HEIGHT);
}

void drawSquareWindow(const GLfloat x, const GLfloat y) {
  glPushMatrix();
    setMat(B6darkaccentMat);
    glScalef(1,1,SILL_WIDTH);
    glTranslatef(x,y,0);
    //SILL
    glPushMatrix();
      glScalef(WINDOW_WIDTH,WINDOW_WIDTH,1);
      glutSolidCube(1);
    glPopMatrix();
  glPopMatrix();
}

void drawBigWindowPanel() {
  //center top
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(0,0.25+0.25/2,0);
    glScalef(1/3.0,0.25,WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //center left
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(-1/6.0 + WINDOW_WIDTH/4.0,0,0);
    glScalef(WINDOW_WIDTH/2.0,1,WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //center right
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(1/6.0 - WINDOW_WIDTH/4.0,0,0);
    glScalef(WINDOW_WIDTH/2.0,1,WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //bar high
  glPushMatrix();
    setMat(B6darkaccentMat);
    glScalef(WINDOW_WIDTH,WALL_WIDTH,WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //bar low
  glPushMatrix();
    setMat(B6darkaccentMat);
    glTranslatef(0,-WINDOW_WIDTH,0);
    glScalef(WINDOW_WIDTH,WALL_WIDTH,WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //accent
  glPushMatrix();
    setMat(B6lightaccentMat);
    glTranslatef(0,0.25+ACCENT_BOX_HEIGHT/2-ACCENT_BOX_DOWN,0);
    glScalef(ACCENT_BOX_WIDTH,ACCENT_BOX_HEIGHT,WALL_WIDTH+0.01);
    glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(0,0.25,0);
    glScalef(WINDOW_WIDTH,WINDOW_WIDTH,WALL_WIDTH);
    doArch();
  glPopMatrix();
}

void drawLittleWindowPanel() {
  //upper center
  glPushMatrix();
    setMat(B6brickMat);
    glScalef(0.5, ((1/3.0) * 0.5), WALL_WIDTH);
    glTranslatef(0,0.5,0);
    glutSolidCube(1);
    glTranslatef(0,2,0);
    glutSolidCube(1);
  glPopMatrix();
  //center left
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(3/8.0,0,0);
    glScalef(1/4.0 , 1 , WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //center right
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(-3/8.0,0,0);
    glScalef(1/4.0 , 1 , WALL_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
  //accent
  glPushMatrix();
    setMat(B6lightaccentMat);
    glTranslatef(0,ACCENT_BOX_HEIGHT/2-ACCENT_BOX_DOWN,0);
    glScalef(ACCENT_BOX_WIDTH*3,ACCENT_BOX_HEIGHT,WALL_WIDTH+0.01);
    glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(0,0,0);
    glScalef(1/2.0,WINDOW_WIDTH,WALL_WIDTH);
    doArch();
  glPopMatrix();
}

void drawWallCap() {
  glPushMatrix();
    setMat(B6lightaccentMat);
    glTranslatef(0,0.51-(WALL_CAP_HEIGHT/2),0);
    glScalef(1+WALL_CAP_WIDTH, WALL_CAP_HEIGHT, WALL_CAP_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
}

void drawPillars() {
  glPushMatrix();
    setMat(B6pillarMat);
    drawPillar(-.5);
    drawPillar(-1/6.);
    drawPillar( 1/6.);
    drawPillar( .5);
  glPopMatrix();
}

void drawPillar(const GLfloat x) {
  // PILLAR
  glPushMatrix();
    setMat(B6pillarMat);
    glTranslatef(x,0,0);
    glScalef(PILLAR_WIDTH,1,PILLAR_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
    
  // CAP
  glPushMatrix();
    setMat(B6lightaccentMat);
    glTranslatef(x,.51-(PILLAR_CAP_HEIGHT/2),0);
    glScalef(PILLAR_CAP_WIDTH, PILLAR_CAP_HEIGHT, PILLAR_CAP_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
    
  // BASE
  glPushMatrix();
    setMat(B6lightaccentMat);
    glTranslatef(x,-0.5+BOTTOM_ACCENT_HEIGHT/2.0,0);
    glScalef(PILLAR_CAP_WIDTH, BOTTOM_ACCENT_HEIGHT, PILLAR_CAP_WIDTH);
    glutSolidCube(1);
  glPopMatrix();
}

void setMat(const GLfloat* mat) {
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
}

void drawBottomAccent() {
  //wall
  glPushMatrix();
    setMat(B6brickMat);
    glTranslatef(0,-0.5+BOTTOM_ACCENT_HEIGHT/2.0,0);
    glScalef(1 + PILLAR_WIDTH - 0.01, BOTTOM_ACCENT_HEIGHT, PILLAR_WIDTH - 0.01);
    glutSolidCube(1);
  glPopMatrix();
  //ledge
  glPushMatrix();
    setMat(B6lightaccentMat);
    glTranslatef(0,-0.5+ (BOTTOM_ACCENT_HEIGHT) + BOTTOM_ACCENT_LEDGE_HEIGHT/2.0,BOTTOM_ACCENT_LEDGE_OVERHANG/2);
    glScalef(1 + PILLAR_WIDTH + 0.01 + BOTTOM_ACCENT_LEDGE_OVERHANG, BOTTOM_ACCENT_LEDGE_HEIGHT, PILLAR_WIDTH + 0.01 + BOTTOM_ACCENT_LEDGE_OVERHANG);
    glutSolidCube(1);
  glPopMatrix();
}

void doArch() {

   glPushMatrix();
     glScalef(0.5,0.5,0.5);

   int i, numSlices;
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