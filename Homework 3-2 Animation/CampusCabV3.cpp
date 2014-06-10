#include "Angel.h"
#include <stdio.h>
#include <math.h>
#include "textureFileReader.h"

#include "drawBuildings.h"
using namespace std;

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;

#define CAB_SPEED 0.01
#define CAB_ROTATE 1
#define NECK_LIFT 0.1
#define NEAR_SPEED 0.1
#define ZOOM_SPEED 0.1

class wcPt3D {
   public:
      GLfloat x, y, z;
};

float frustumXY = 0.167;
float frustumNear = 0.25;

float  eyeX = 0, eyeY = 0.25, eyeZ = 5,
       atX = 0, atY = 0.25, atZ = 0;

int perspective = 1;
      

GLuint texture[1];



void binomialCoeffs (GLint n, GLint * C)
{
   GLint k, j;

   for (k = 0;  k <= n;  k++) {
      /*  Compute n!/(k!(n - k)!).  */
      C [k] = 1;
      for (j = n;  j >= k + 1;  j--)
         C [k] *= j;
      for (j = n - k;  j >= 2;  j--)
         C [k] /= j;

	  printf("%d ",C[k]);
   }
   printf("\n");
}



void computeBezPt (GLfloat u, wcPt3D * bezPt, GLint nCtrlPts,
                    wcPt3D * ctrlPts, GLint * C)
{
   GLint k, n = nCtrlPts - 1;
   GLfloat bezBlendFcn;

   bezPt->x = bezPt->y = bezPt->z = 0.0;

   /*  Compute blending functions and blend control points. */
   for (k = 0; k < nCtrlPts; k++) {
      bezBlendFcn = C [k] * pow (u, k) * pow (1 - u, n - k);
      bezPt->x += ctrlPts [k].x * bezBlendFcn;
      bezPt->y += ctrlPts [k].y * bezBlendFcn;
      bezPt->z += ctrlPts [k].z * bezBlendFcn;
   }
}


float posx = 0, posy = 0, posz = 0;
float roll = 0, tilt = 0, height = 0;
bool first = 1;
GLint nCtrlPts = 5;
wcPt3D ctrlPts [] = {
	  {0.0, 5.0, 12.0},
	  {0.0, 4.0, 9},
	  {0.0, 3.0, 7.0},
	  {0.0, 1.1, 5.5},
	  {0.0, 0.0, 4.0}
	  //{0.0, 0, 3.0},
	  //{1.0, 0.5, 2.0},
	  //{1.0, 1, 2.0},
	  //{2.0, 1, 1.0},
	  //{3.0, 1, 0.0},
	  //{2.0, 1, -1.0},
	  //{1.0,  1, -2.0},
	  //{0.0,  1, -3.0},
	  //{0.0,  2, -3.0},
	  //{0.0,  3, -3.0},
	  //{0.0,  4, -3.0},
};

GLint nCtrlPts2 = 3;
wcPt3D ctrlPts2 [] = {
	{0, .183, 4.24},
	{1.5, .183, -4},
	{1.5, .183,-2}
};

GLint *C;
GLint *C2;


GLfloat u = 0, uSize = .04;
float rotX = 0, rotY = 0, rotZ=0, objRot = 0, move1 = 0;
int angle = 0, objectID = 0, time = 0;




void buildBot2(void) {
   float redMat[] = { 1, 0, 0};
   float blueMat[] = {0, 0, 1};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, blueMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, blueMat);

   glPushMatrix();
   glScalef(1,1.5,.5);
   glutSolidCube(2);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0,2.5,0);
   glScalef(.5, .5, .5);
   glutSolidCube(2);
   glPopMatrix();
   
   glMaterialfv(GL_FRONT, GL_DIFFUSE, redMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, redMat);

   glPushMatrix();
   glTranslatef(0,1.75,0);
   glScalef(.25, .25, .25);
   glutSolidCube(2);
   glPopMatrix();

   
	   if (time < 150){
	   glPushMatrix();
	   glTranslatef(.5,-3,0);
	   glScalef(.45, 1.5, .5);
	   glutSolidCube(2);
	   glPopMatrix();

	   glPushMatrix();
	   glTranslatef(-.5,-3,0);
	   glScalef(.45, 1.5, .5);
	   glutSolidCube(2);
	   glPopMatrix();
   }else {
	   if(angle%180 < 90) {
		   glPushMatrix();
		   glTranslatef(.5,-1.5,0);
		   glRotatef(-45 + angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();

		   glPushMatrix();
		   glTranslatef(-.5,-1.5,0);
		   glRotatef(45-angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);;
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();
	   } else {
		   glPushMatrix();
		   glTranslatef(.5,-1.5,0);
		   glRotatef(45 - angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();

		   glPushMatrix();
		   glTranslatef(-.5,-1.5,0);
		   glRotatef(-45+angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);;
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();
	   }
   }
   

   if(angle%180 > 90){

	   glPushMatrix();
	   glTranslatef(1.3,1,0);
	   glRotatef(-angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();

	   glPushMatrix();
	   glTranslatef(-1.3,1,0);
	   glRotatef(-90+angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();
   } else {
	   glPushMatrix();
	   glTranslatef(1.3,1,0);
	   glRotatef(-90+angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();

	   glPushMatrix();
	   glTranslatef(-1.3,1,0);
	   glRotatef(-angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();
   }


}





void buildBot(void) {
   float redMat[] = { 1, 0, 0};
   float blueMat[] = {0, 0, 1};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, redMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, redMat);

   glPushMatrix();
   glScalef(1,1.5,.5);
   glutSolidCube(2);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0,2.5,0);
   glScalef(.5, .5, .5);
   glutSolidCube(2);
   glPopMatrix();
   
   glMaterialfv(GL_FRONT, GL_DIFFUSE, blueMat);
   glMaterialfv(GL_FRONT, GL_AMBIENT, blueMat);

   glPushMatrix();
   glTranslatef(0,1.75,0);
   glScalef(.25, .25, .25);
   glutSolidCube(2);
   glPopMatrix();

	if (time < 150){
	   glPushMatrix();
	   glTranslatef(.5,-3,0);
	   glScalef(.45, 1.5, .5);
	   glutSolidCube(2);
	   glPopMatrix();

	   glPushMatrix();
	   glTranslatef(-.5,-3,0);
	   glScalef(.45, 1.5, .5);
	   glutSolidCube(2);
	   glPopMatrix();
   }else {
	   if(angle%180 < 90) {
		   glPushMatrix();
		   glTranslatef(.5,-1.5,0);
		   glRotatef(-45 + angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();

		   glPushMatrix();
		   glTranslatef(-.5,-1.5,0);
		   glRotatef(45-angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);;
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();
	   } else {
		   glPushMatrix();
		   glTranslatef(.5,-1.5,0);
		   glRotatef(45 - angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();

		   glPushMatrix();
		   glTranslatef(-.5,-1.5,0);
		   glRotatef(-45+angle%90,1,0,0);
		   glTranslatef(0,-1.5,0);;
		   glScalef(.45, 1.5, .5);
		   glutSolidCube(2);
		   glPopMatrix();
	   }
   }

   if(angle%180 > 90){

	   glPushMatrix();
	   glTranslatef(1.3,1,0);
	   glRotatef(-angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();

	   glPushMatrix();
	   glTranslatef(-1.3,1,0);
	   glRotatef(-90+angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();
   } else {
	   glPushMatrix();
	   glTranslatef(1.3,1,0);
	   glRotatef(-90+angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();

	   glPushMatrix();
	   glTranslatef(-1.3,1,0);
	   glRotatef(-angle%90,1,0,0);
	   glTranslatef(0,-.5,0);
	   glScalef(.3, 1, .5);
	   glutSolidCube(2);
	   glPopMatrix();
   }


}




void initParams(void)
{
	posx = 0;
	posy = 0;
	posz = 0;
	roll = 0;
	tilt = 0;
	first = 1;
	angle = 0;
	time = 0;
	u = 0;
	uSize = .04;
	height = 0;
	move1 = 0;
}



void init(void) 
{

    glClearColor (1.0, 1.0, 1.0 , 0.0);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    // Initialize shader lighting parameters
    point4 light_position( 0.0, 0.0, 5.0, 0.0 );
    color4 light_ambient( 0.3, 0.3, 0.3, 1.0 );
    color4 light_diffuse( 0.7, 0.7, 0.7, 1.0 );
    color4 light_specular( 0.0, 0.0, 0.0, 1.0 );
	color4 light_global_ambient( 0, 0, 0, 1);

    color4 material_ambient( 1,1,1, 1.0 );
    color4 material_diffuse(  1,1,1, 1.0 );
    color4 material_specular( 0.0, 0.0, 0.0, 1.0 );
    float  material_shininess = 5.0;

	// setting material properties
	//  will be used to set color of the cube
	//  if you want to use more than one color,
	//  then you have to SWITCH FROM ONE COLOR TO THE NEXT
	//  BY EXECUTING THIS CODE IN DISPLAY.
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);


    //////////////////////////////////////

    Image *image1 = loadTexture( "CampusMap.bmp");  
	    // jm  note:   these bit map files work a lot better if the width and height 
	    //               are multiples of 4.  

    if(image1 == NULL){
        printf("Image was not returned from loadTexture\n");
        exit(1);
    }
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // Create Texture
    glGenTextures(1, texture);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);



	

	// setting light properties
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_global_ambient);

    glEnable(GL_NORMALIZE);

	C = new GLint [nCtrlPts];
	C2 = new GLint [nCtrlPts2];
   binomialCoeffs (nCtrlPts - 1, C);
   binomialCoeffs (nCtrlPts2 -1, C2);

}

void drawMap() {
   
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glNormal3f(0,1,0);

   glBegin(GL_POLYGON);
   glTexCoord2f(0.0, 0.0);
   glVertex3f(-10,0,5);

   glTexCoord2f(0.0, 1.0);
   glVertex3f(-10,0,-5);

   glTexCoord2f(1.0, 1.0);
   glVertex3f(10,0,-5);

   glTexCoord2f(1.0, 0.0);
   glVertex3f(10,0,5);
   glEnd();

   glDisable(GL_TEXTURE_2D);
}
void resetU(void) {
	u = 0;
	uSize = .04;
}



void display(void)
{
   int i;
   int r;
   int closeUp = 0;
   
   wcPt3D bezCurvePt;
   GLint k;

   glClear (GL_COLOR_BUFFER_BIT);
   glClear(GL_DEPTH_BUFFER_BIT);
	
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
	computeBezPt (u, &bezCurvePt, nCtrlPts, ctrlPts, C);
	if (time < 25) { // Jump
		posx = bezCurvePt.x;
		posy = bezCurvePt.y;
		posz = bezCurvePt.z;
		gluLookAt (bezCurvePt.x, bezCurvePt.y, bezCurvePt.z, 
              0.0, 0.0, 4.0, 
              0.0, 1.0, 0.0);
	} else if(4 + roll <= posz && time < 30){ //Do a summersault part 1
		gluLookAt (posx, posy+.1, posz,
			0.0, 0-(roll*1.5), 4+roll,
			0.0, 1.0, 0.0);
		roll += .05;
	} else if(-.36+(roll*1.5) <= posy+.1 && time < 34) { //Do a summersault part 2
		gluLookAt (posx, posy+.1, posz,
			0.0, -.36+(roll*1.5), 4+roll,
			0.0, -1, 0.0);
		roll+= .05;
	} else if (4+roll >= posz && time < 40){ //Do a sumersault part 3
		gluLookAt (posx, posy+.1, posz,
			0.0, 0+(roll*1.5), 4+roll,
			0.0, -1, 0.0);
		roll -= .05;
	} else if((roll*1.5) > 0 && time < 59) { //Do a summersault part 4
		gluLookAt (posx, posy+.1, posz,
			0.0, .36+(roll*1.5), 4+roll,
			0.0, 1, 0.0);
		roll-= .05;
	} else if(time<59){ //run back
		if(first){
			resetU();
			first = 0;
		}
		computeBezPt (u, &bezCurvePt, nCtrlPts2, ctrlPts2, C2);
		posx = bezCurvePt.x;
		posy = bezCurvePt.y;
		posz = bezCurvePt.z;
		gluLookAt (bezCurvePt.x, bezCurvePt.y, bezCurvePt.z, 
              0.0, 0.183, -8.0, 
              0.0, 1, 0.0);

	} else if( tilt < 5 && time < 100){//look up
		gluLookAt(posx, posy, posz,
			1.0,0.183+tilt, -8,
			0,1,0);
		tilt += .5;
	} else if(time < 100){ //pause
		gluLookAt(posx,posy,posz,
			1,.183+tilt,-8, 
			0,1,0);
	} else if(tilt > 0 && time < 106){ //look down
		gluLookAt(posx, posy, posz,
			1.0,0.183+tilt, -8,
			0,1,0);
		tilt -= 1;
		
	} else if (tilt < 4 && time < 110){ //turn 1
		tilt += 1;
		gluLookAt(posx, posy, posz,
			1.0 + (tilt*2),0.183, -8 +(tilt*2),
			0,1,0);
	} else if (tilt > 0 && time < 114){  //turn 2
		tilt -= 1;
		gluLookAt(posx, posy, posz,
			1.0 + (tilt*2),0.183, 0 +(tilt*2),
			0,1,0);
	} else if (tilt < 1 && time < 118){
		gluLookAt(posx, posy, posz,
			1.0,0.183 + tilt, 0,
			0,1,0);
		tilt += .5;
	} else if (time < 121){
		gluLookAt(posx, posy, posz,
			1.0,0.183 + tilt, 0,
			0,1,0);
	} else if (tilt > 0 && time > 120 ) {
		gluLookAt(posx, posy, posz,
			1.0,0.183 + tilt, 0,
			0,1,0);
		tilt -= .5;
	} else if (time < 125){
		gluLookAt(posx, posy, posz,
			1.0,0.183, 0,
			0,1,0);
	} else if(height < 30){
		gluLookAt(posx, posy + height, posz,
			1.0,0.183, 0,
			0,1,0);
		height += .5;
	} else {
		gluLookAt(posx, posy + height, posz,
			1.0,0.183, 0,
			0,1,0);
	}
	

   if (!closeUp) {
       drawMap();
   }

	glPushMatrix();
	if (time > 150) {
		glTranslatef(0,0, move1);
	}
	if( time > 40){
		glTranslatef(1,4,-6);
	} else {
		glTranslatef(1,4,-14);
	}
	buildBot();
    glPopMatrix();

	glPushMatrix();	
	if (time > 150) {
		glTranslatef(0,0, -move1);
		move1+= .1;
	}
	if( time > 100) {
	   glTranslatef(1,4,6);
	} else {
		glTranslatef(1,4,14);
	}
	glRotatef(180,0,1,0);
	buildBot2();
	glPopMatrix();
   
   glPushMatrix();
   drawBuilding0(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding1(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding2(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding3(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding4(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding5(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding6(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding7(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding9(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding10(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding11(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding12(closeUp);
   glPopMatrix();
   
   glPushMatrix();
   drawBuilding13(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding14(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding15(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding16(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding17(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding18(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding19(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding20(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding21(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding22(closeUp);
   glPopMatrix();
   
   glPushMatrix();
   drawBuilding23(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding24(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding25(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding26(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding28(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding29(closeUp);
   glPopMatrix();

   glPushMatrix();
   drawBuilding30(closeUp);
   glPopMatrix();
   
   glutSwapBuffers();

}

float slowFactor = 1;
float angInc = 4;


void idle(void)
{
	angle += angInc*slowFactor;
	if (time > 198) {
        initParams();
	} else {
		//x += 0.005*slowFactor;
		//y += 0.0005*slowFactor;
		u += uSize;
		time++;
	}


    glutPostRedisplay();
}



void myspecialkey(int key, int x, int y)
{

    
    switch (key) {

            case 100:
                rotY -= 3;
                break;
            case 102:
                rotY += 3;
                break;
            case 101:
                rotX -= 3;
                break;
            case 103:
                rotX += 3;
                break;
            case 104:
                rotZ += 3;
                break;
            case 105:
                rotZ -= 3;
                break;                                                  
     }
	 glutPostRedisplay();
}

void setProjection() {
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   if (perspective) {
       glFrustum (-frustumXY,  frustumXY, -frustumXY , frustumXY, frustumNear, 32.0);
   } else {
       float orthoXY = 32 * frustumXY / frustumNear; 
       glOrtho (-orthoXY, orthoXY, -orthoXY, orthoXY,             frustumNear, 32.0);
   }
   glMatrixMode (GL_MODELVIEW);
}

void reshape (int width, int height)
{
   glViewport (0, 0, (GLsizei) width, (GLsizei) height); 
   setProjection();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'f':
		 slowFactor *= 1.10;
	     break;
      case 's':
		 slowFactor *=0.9;
	     break;
      case 27:
         exit(0);
         break;
	  case '0':
		 objectID = 0;
		 break;
	  case '1':
		 objectID = 1;
		 break;
	  case '2':
		 objectID = 2;
		 break;
	  case '3':
		 objectID = 3;
		 break;
	  case '4':
		 objectID = 4;
		 break;
	  case '+':
		 objRot += 3;
		 break;
	  case '-':
		 objRot -= 3;
		 break;
   }
   glutPostRedisplay();
      
}


int main(int argc, char** argv)
{

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (700, 700); 
   glutInitWindowPosition (100, 25);
   glutCreateWindow ("Debugging");
   init ();
   glutDisplayFunc(display); 
   glutIdleFunc(idle);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(myspecialkey);
   glutMainLoop();
   return 0;
}