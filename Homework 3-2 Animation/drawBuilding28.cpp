#include "drawBuildings.h"

#include "Angel.h"


using namespace std;
#define PI 3.14159

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;

float glass_color[] = { .88, 1, 1 };
static float brick_color[] = { 0.508, 0.148, 0.098 };
static float trim_color[] = { 0.9, 0.95, 0.9 };
static float window_color[] = { 0.684, 0.914, 0.664 };
float roof_color[] = { 0.8, 0.8, 0.8 };

//float yRot = 0.0;
//float xRot = 0.0;

const int NumVertices = 36; //(6 faces)(2 triangles/face)(3 vertices/triangle)

point4 points[NumVertices];
color4 colors[NumVertices];
vec3   normals[NumVertices];

// Vertices of a unit cube centered at origin, sides aligned with axes
point4 vertices[8] = {
	point4(-0.5, -0.5, 0.5, 1.0),
	point4(-0.5, 0.5, 0.5, 1.0),
	point4(0.5, 0.5, 0.5, 1.0),
	point4(0.5, -0.5, 0.5, 1.0),
	point4(-0.5, -0.5, -0.5, 1.0),
	point4(-0.5, 0.5, -0.5, 1.0),
	point4(0.5, 0.5, -0.5, 1.0),
	point4(0.5, -0.5, -0.5, 1.0)
};

// RGBA colors
color4 vertex_colors[8] = {
	color4(0.0, 0.0, 0.0, 1.0),  // black
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 1.0, 0.0, 1.0),  // yellow
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 1.0, 1.0, 1.0),  // white
	color4(0.0, 1.0, 1.0, 1.0)   // cyan
};

//----------------------------------------------------------------------------

// quad generates two triangles for each face and assigns colors
//    to the vertices
int Index = 0;
void
quad(int a, int b, int c, int d)
{
	// triangle a b c
	vec4 v1 = vertices[b] - vertices[a];
	vec4 v2 = vertices[c] - vertices[a];
	vec4 normal = cross(v1, v2);
	cout << normal << endl;

	glBegin(GL_POLYGON);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glEnd();

	// triangle a c d
	// same normal as above, if the two triangles form a quad.
	glBegin(GL_POLYGON);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();

}

//----------------------------------------------------------------------------

// generate 12 triangles: 36 vertices and 36 colors
void
colorcube()
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(3, 0, 4, 7);
	quad(6, 5, 1, 2);
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);
}





//----------------------------------------------------------------------------

// OpenGL initialization











void stairs()
{

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	//side wall tops

	glPushMatrix();

	glTranslatef(1.5, -.25, -.3);
	glScalef(1.5, .2, .15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -.25, -.3);
	glScalef(1.5, .2, .15);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//side walls
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);
	glPushMatrix();
	glTranslatef(1.5, -.9, -.3);
	glScalef(1.5, 1.3, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -.9, -.3);
	glScalef(1.5, 1.3, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//walk to door
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	glPushMatrix();
	glTranslatef(0, -1.2, -.8);
	glScalef(4, .75, 1);
	glutSolidCube(1);
	glPopMatrix();

	//glColor3f(.5, .5, .5);
	glPushMatrix();
	glTranslatef(0, -1.2, -1.3);
	glScalef(2, .75, 1);
	glutSolidCube(1);
	glPopMatrix();

	//stairs top to bottom.
	glPushMatrix();
	glTranslatef(0, -.9, .15);
	glScalef(2, .15, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.05, .4);
	glScalef(2.5, .15, 1.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.2, .6);
	glScalef(3, .15, 1.8);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.35, .8);
	glScalef(3.5, .15, 2.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.5, 1);
	glScalef(4, .15, 2.6);
	glutSolidCube(1);
	glPopMatrix();
}
void topWindow()
{
	// top white bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	glPushMatrix();
	glTranslatef(0, .38, 0);
	glScalef(2.55, .1, .1);
	glutSolidCube(1);
	glPopMatrix();

	//green window
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window_color);
	glPushMatrix();
	glTranslatef(0, -.3, -.075);
	glScalef(2.5, 1.28, .1);
	glutSolidCube(1);
	glPopMatrix();

	//	glColor3f(0.07, .58, .41);
	glPushMatrix();
	glTranslatef(1.22, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.85, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.5, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.15, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.2, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.55, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.9, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.25, -.3, 0);
	glScalef(.075, 1.28, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .3, 0);
	glScalef(2.5, .075, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.9, 0);
	glScalef(2.5, .075, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.6, 0);
	glScalef(2.5, .075, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.3, 0);
	glScalef(2.5, .075, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(2.5, .075, .075);
	glutSolidCube(1);
	glPopMatrix();
}

void roofRightCorners()
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	//sides
	//right
	glBegin(GL_TRIANGLES);
	glColor3f(.5, .5, .5);
	glVertex3f(1.25, .05, -.8);
	glVertex3f(1.7, 0, -.8);
	glVertex3f(1.7, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(1.25, .05, -.8);
	glVertex3f(1.25, 0, 0);
	glVertex3f(1.7, 0, 0);
	glEnd();



}
void roofLeftCorner()
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	//left
	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-1.25, .05, -.8);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(-1.7, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-1.25, .05, -.8);
	glVertex3f(-1.7, 0, -.8);
	glVertex3f(-1.7, 0, 0);
	glEnd();
}



void roof()
{
	//bottom
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	//glColor3f(.5, .5, .5);
	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-1.25, 0, -2);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(1.25, 0, -2);
	glEnd();

	//glColor3f(0, 0, 0); //red
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(1.25, 0, 0);
	glVertex3f(1.25, 0, -2);
	glEnd();





	//popping triangles
	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-.42, 0, .1);
	glVertex3f(-.42, 1, -1.9);
	glVertex3f(-.42, 0, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-.84, 0, .1);
	glVertex3f(-.84, 1, -1.9);
	glVertex3f(-.84, 0, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(.42, 0, .1);
	glVertex3f(.42, 1, -1.9);
	glVertex3f(.42, 0, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(.84, 0, .1);
	glVertex3f(.84, 1, -1.9);
	glVertex3f(.84, 0, -2);
	glEnd();








	// main part
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	//glColor3f(.5, .5, .5);
	glBegin(GL_TRIANGLES);
	//glColor3f(0.1, 0.2, 0.3);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(-1.25, 1, -2);
	glVertex3f(-1.25, 0, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0.1, 0.2, 0.3);
	glVertex3f(1.25, 0, -2);
	glVertex3f(1.25, 0, 0);
	glVertex3f(1.25, 1, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0.1, 0.2, 0.3);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(-1.25, 1, -2);
	glVertex3f(1.25, 1, -2);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0.1, 0.2, 0.3);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(1.25, 0, 0);
	glVertex3f(1.25, 1, -2);
	glEnd();


}


void shed()
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	glPushMatrix();
	glTranslatef(0, 1.9, -2);
	//glScalef(0, 0, 0);
	topWindow();
	glPopMatrix();
	//shed corners
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	//glColor3f(.4, .4, .4);
	glPushMatrix();
	glTranslatef(0, 0, .1);
	glScalef(3.4, .08, .075);
	glutSolidCube(1);
	glPopMatrix();

	//glColor3f(.4, .4, .4);
	glPushMatrix();
	glTranslatef(1.7, 0, -.3);
	glScalef(.075, .075, 1);
	glutSolidCube(1);
	glPopMatrix();

	//glColor3f(.4, .4, .4);
	glPushMatrix();
	glTranslatef(-1.7, 0, -.3);
	glScalef(.075, .075, 1);
	glutSolidCube(1);
	glPopMatrix();

	//pipes
	//glColor3f(.5, .5, .5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	glPushMatrix();
	glTranslatef(1.72, .15, -.76);
	glScalef(.075, 4.35, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.72, .15, -.76);
	glScalef(.075, 4.35, .075);
	glutSolidCube(1);
	glPopMatrix();
	//side cube wall white lines
	glMaterialfv(GL_FRONT, GL_DIFFUSE, trim_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, trim_color);
	glPushMatrix();
	//glColor3f(1, 1, 1); //red
	glTranslatef(1.75, -1, -.8);
	glScalef(1, .2, .15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1, 1, 1); //red
	glTranslatef(-1.75, -1, -.8);
	glScalef(1, .2, .15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1, 1, 1); //red
	glTranslatef(-1.2, -1, -1.3);
	glScalef(.15, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1, 1, 1); //red
	glTranslatef(1.2, -1, -1.3);
	glScalef(.15, .2, 1);
	glutSolidCube(1);
	glPopMatrix();




	//side cube wall
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);
	glPushMatrix();
	glTranslatef(1.75, .16, -1.4);
	glScalef(1, 4.35, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.75, .16, -1.4);
	glScalef(1, 4.35, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	//sides
	glBegin(GL_TRIANGLES);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	//glColor3f(.5, .5, .5);
	glVertex3f(1.25, .4, -.8);
	glVertex3f(1.7, 0, -.8);
	glVertex3f(1.7, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(1.25, .4, -.8);
	glVertex3f(1.25, 0, 0);
	glVertex3f(1.7, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-1.25, .4, -.8);
	glVertex3f(-1.25, 0, 0);
	glVertex3f(-1.7, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 0);
	glVertex3f(-1.25, .4, -.8);
	glVertex3f(-1.7, 0, -.8);
	glVertex3f(-1.7, 0, 0);
	glEnd();




	roof();


}

void door()
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	///first door frame
	//glColor3f(.75, .75, .75); //red
	glPushMatrix();
	glTranslatef(-.5, 0, 0);
	glScalef(.05, 1, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.01, 0, 0);
	glScalef(.05, 1, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.25, .475, 0);
	glScalef(.5, .05, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.25, -.475, 0);
	glScalef(.5, .05, .075);
	glutSolidCube(1);
	glPopMatrix();

	//second door frame

	glPushMatrix();
	glTranslatef(.5, 0, 0);
	glScalef(.05, 1, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.01, 0, 0);
	glScalef(.05, 1, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.25, .475, 0);
	glScalef(.5, .05, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.25, -.475, 0);
	glScalef(.5, .05, .075);
	glutSolidCube(1);
	glPopMatrix();

	//door
	glMaterialfv(GL_FRONT, GL_DIFFUSE, glass_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, glass_color);
	//glColor3f(.8, .8, .8); //red
	glPushMatrix();
	glTranslatef(-.25, 0, -.05);
	glScalef(.5, 1, .075);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.25, 0, -.05);
	glScalef(.5, 1, .075);
	glutSolidCube(1);
	glPopMatrix();

	//door side wall
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);
	glPushMatrix();
	glTranslatef(.9, 0, 0);
	glScalef(.8, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.9, 0, 0);
	glScalef(.8, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roof_color);
	//door knob
	//glColor3f(.75, .75, .75); //red
	glPushMatrix();
	glTranslatef(-.04, 0, 0);
	glScalef(.08, .02, .02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.04, 0, 0);
	glScalef(.08, .02, .02);
	glutSolidCube(1);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brick_color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brick_color);
	glPushMatrix();
	glTranslatef(0, .75, 0);
	glScalef(2.6, .5, .2);
	glutSolidCube(1);
	glPopMatrix();
}


void complete()
{
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	glScalef(0.25, 0.25, 0.5);
	shed();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, .59, -1);
	glScalef(0.48, 0.25, 0.5);
	roof();
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(-.7, .59, -.4);
	glScalef(0.48, 0.25, 0.8);
	roof();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.7, .59, -.4);
	glScalef(0.48, 0.25, 0.8);
	roof();
	glPopMatrix();*/
	//roof();

	glPushMatrix();
	glTranslatef(0.5, -.1, .2);
	glScalef(0.25, 0.25, 0.5);
	stairs();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -.2, -.9);
	glScalef(0.25, 0.25, 0.5);
	door();
	glPopMatrix();

	glColor3f(.5, .5, .5);
	glPushMatrix();
	glTranslatef(2, .59, -.4);
	glScalef(0.7, 0.5, .8);
	roofLeftCorner();
	glPopMatrix();

	//glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-1, .59, -.4);
	glScalef(0.7, 0.5, .8);
	roofRightCorners();
	glPopMatrix();
}
void drawBuilding28(int closeUp) {
	

	float yellowMat[] = { .75, .75, 0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowMat);
	glMaterialfv(GL_FRONT, GL_AMBIENT, yellowMat);

	glPushMatrix();
	if (closeUp) {
		glScalef(8, 8, 8);
	}
	else {
		glScalef(.5, .5, .5);
		glRotatef(-18.0, 0.0, 1, 0.0);
		glTranslatef(-3.5, .5, 0.3);
	}
	complete();
	glPopMatrix();
	//display();

}
