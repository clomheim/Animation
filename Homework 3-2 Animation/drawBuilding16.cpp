#include "drawBuildings.h"

#include "Angel.h"

#include <math.h>



//material colors to be used in WG building
float roofMaterial2[] = { .7, .7, .7 };
float windowSill2[] = { .7, .7, .7 };
float windowStruts2[] = { .7, .7, .7 };

float windowBars2[] = { .57, .57, .66 };

float shinyWindowSurface2[] = { .1, .27, .46 };

float YellowBrickMat2[] = { 1, .9, .6 };

float brickRedMat2[] = { .58, .27, .06 };

float windowPaneBorderWidth = 0.05;
float windowBorderWidth = 0.08;
float windowBorderHeightRatio = 1.1;


void drawWall16(GLfloat xOffs, GLfloat yOffs, GLfloat zOffs, GLfloat thickness, GLfloat width, GLfloat height, vec3 frontFace)
{
	float cubeCenterDist = Angel::length(frontFace) - (thickness / 2.0);
	//printf("cubeCenterDist = %3.2f\n", cubeCenterDist);
	vec4 cubeCenter = vec4((frontFace * cubeCenterDist).x, (frontFace * cubeCenterDist).y, (frontFace * cubeCenterDist).z, 1.0);
	vec3 finalRotation = vec3(0, 0, Angel::length(frontFace));
	vec3 rotateAxis = (Angel::cross(frontFace, finalRotation)); 

	//	cos(angle) = dot product divided by the product of the magnitude of the vectors 
	//Use inverse cosine to find the angle. 
	GLfloat angle = GLfloat(acos(Angel::dot(frontFace, finalRotation) / Angel::length(frontFace)) * 180 / M_PI);
	//printf("degree = %3.2f\n", angle);
	//GLfloat angle = GLfloat(Angel::dot(frontFace, finalRotation) / Angel::length(frontFace) * Angel::length(finalRotation));

	glPushMatrix(); //TRANSLATE

	glTranslatef(xOffs + cubeCenter.x, yOffs + cubeCenter.y, zOffs + cubeCenter.z);

	glRotatef(angle, rotateAxis.x, rotateAxis.y, rotateAxis.z);

	glScalef(width, height, thickness);
	glutSolidCube(1);
	glPopMatrix();  //FIN TRANSLATE
}






void drawWindow16(GLfloat xOffs, GLfloat yOffs, GLfloat zOffs, GLfloat thickness, GLfloat width, GLfloat height, vec3 frontFace)
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, shinyWindowSurface2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, shinyWindowSurface2);
	//enable blending for translucent effect
	glEnable(GL_BLEND); 
	glBlendFunc(GL_ONE, GL_ONE);


	float cubeCenterDist = Angel::length(frontFace) - (thickness / 2.0);
	//printf("cubeCenterDist = %3.2f\n", cubeCenterDist);
	vec4 cubeCenter = vec4((frontFace * cubeCenterDist).x, (frontFace * cubeCenterDist).y, (frontFace * cubeCenterDist).z, 1.0);
	vec3 finalRotation = vec3(0, 0, Angel::length(frontFace));
	vec3 rotateAxis = (Angel::cross(frontFace, finalRotation)); 

	//	cos(angle) = dot product divided by the product of the magnitude of the vectors 
	//Use inverse cosine to find the angle. 
	GLfloat angle = GLfloat(acos(Angel::dot(frontFace, finalRotation) / Angel::length(frontFace)) * 180 / M_PI);
	//printf("degree = %3.2f\n", angle);
	//GLfloat angle = GLfloat(Angel::dot(frontFace, finalRotation) / Angel::length(frontFace) * Angel::length(finalRotation));

	glPushMatrix(); //TRANSLATE

	glTranslatef(xOffs + cubeCenter.x, yOffs + cubeCenter.y, zOffs + cubeCenter.z);
	glRotatef(angle, rotateAxis.x, rotateAxis.y, rotateAxis.z);

	glPushMatrix(); //SCALE

	glScalef(width, height, thickness);
	glutSolidCube(1);
	
	glDisable(GL_BLEND);
		
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSill2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSill2);
	glPushMatrix(); //TRANSLATE EDGE RIGHT
	glTranslatef(0.5, 0, 0);
	glScalef(windowBorderWidth, 1.0, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE EDGE LEFT
	glTranslatef(-0.5, 0, 0);
	glScalef(windowBorderWidth, 1.0, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	//glPushMatrix(); //TRANSLATE EDGE TOP
	//glTranslatef(0, 0.5, 0);
	//glScalef(1.0 + windowBorderWidth, windowBorderWidth, windowBorderHeightRatio);
	//glutSolidCube(1);
	//glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE EDGE BOTTOM
	glTranslatef(0, -0.5, 0);
	glScalef(1.0 + windowBorderWidth, windowBorderWidth, windowBorderHeightRatio * 1.1);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE


	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowBars2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowBars2);

	glPushMatrix(); //TRANSLATE EDGE PANE HORIZ
	glTranslatef(0, 0.5 * 0.333333333f, 0);
	glScalef(1.0 + windowPaneBorderWidth, windowPaneBorderWidth / 3, 1.1);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	

	glPushMatrix(); //TRANSLATE PANE LEFT
	glTranslatef(-0.5 * 0.3333333333333f, 0.333333333333f, 0);
	glScalef(windowPaneBorderWidth, 0.3333333333333f, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE PANE RIGHT
	glTranslatef(0.5 * 0.333333333f, 0.333333333333f, 0);
	glScalef(windowPaneBorderWidth, 0.3333333333333f, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE


	glPopMatrix();  //FIN SCALE


	

	glPushMatrix(); //TRANSLATE EDGE
	glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE EDGE
	glPopMatrix(); // FIN TRANSLATE EDGE


	glPopMatrix();  //FIN TRANSLATE
}





void drawWindowDoubleBar16(GLfloat xOffs, GLfloat yOffs, GLfloat zOffs, GLfloat thickness, GLfloat width, GLfloat height, vec3 frontFace)
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, shinyWindowSurface2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, shinyWindowSurface2);
	//enable blending for translucent effect
	glEnable(GL_BLEND); 
	glBlendFunc(GL_ONE, GL_ONE);


	float cubeCenterDist = Angel::length(frontFace) - (thickness / 2.0);
	//printf("cubeCenterDist = %3.2f\n", cubeCenterDist);
	vec4 cubeCenter = vec4((frontFace * cubeCenterDist).x, (frontFace * cubeCenterDist).y, (frontFace * cubeCenterDist).z, 1.0);
	vec3 finalRotation = vec3(0, 0, Angel::length(frontFace));
	vec3 rotateAxis = (Angel::cross(frontFace, finalRotation)); 

	//	cos(angle) = dot product divided by the product of the magnitude of the vectors 
	//Use inverse cosine to find the angle. 
	GLfloat angle = GLfloat(acos(Angel::dot(frontFace, finalRotation) / Angel::length(frontFace)) * 180 / M_PI);
	//printf("degree = %3.2f\n", angle);
	//GLfloat angle = GLfloat(Angel::dot(frontFace, finalRotation) / Angel::length(frontFace) * Angel::length(finalRotation));

	glPushMatrix(); //TRANSLATE

	glTranslatef(xOffs + cubeCenter.x, yOffs + cubeCenter.y, zOffs + cubeCenter.z);
	glRotatef(angle, rotateAxis.x, rotateAxis.y, rotateAxis.z);

	glPushMatrix(); //SCALE

	glScalef(width, height, thickness);
	glutSolidCube(1);
	
	glDisable(GL_BLEND);
	
		
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSill2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowSill2);

	glPushMatrix(); //TRANSLATE EDGE RIGHT
	glTranslatef(0.5, 0, 0);
	glScalef(windowBorderWidth, 1.0, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE EDGE LEFT
	glTranslatef(-0.5, 0, 0);
	glScalef(windowBorderWidth, 1.0, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	//glPushMatrix(); //TRANSLATE EDGE TOP
	//glTranslatef(0, 0.5, 0);
	//glScalef(1.0 + windowBorderWidth, windowBorderWidth, windowBorderHeightRatio);
	//glutSolidCube(1);
	//glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE EDGE BOTTOM
	glTranslatef(0, -0.5, 0);
	glScalef(1.0 + windowBorderWidth, windowBorderWidth, windowBorderHeightRatio * 1.1);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE


	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, windowBars2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, windowBars2);

	glPushMatrix(); //TRANSLATE EDGE PANE HORIZ TOP
	glTranslatef(0, 0.5 * 0.333333333f, 0);
	glScalef(1.0 + windowPaneBorderWidth, windowPaneBorderWidth / 3, 1.1);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE



	glPushMatrix(); //TRANSLATE EDGE PANE HORIZ BOTTOM
	glTranslatef(0, -0.5 * 0.333333333f, 0);
	glScalef(1.0 + windowPaneBorderWidth, windowPaneBorderWidth / 3, 1.1);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	

	glPushMatrix(); //TRANSLATE PANE LEFT
	glTranslatef(-0.5 * 0.3333333333333f, 0, 0);
	glScalef(windowPaneBorderWidth, 1.0f, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE PANE RIGHT
	glTranslatef(0.5 * 0.333333333f, 0, 0);
	glScalef(windowPaneBorderWidth, 1.0f, windowBorderHeightRatio);
	glutSolidCube(1);
	glPopMatrix(); // FIN TRANSLATE EDGE


	glPopMatrix();  //FIN SCALE


	

	glPushMatrix(); //TRANSLATE EDGE
	glPopMatrix(); // FIN TRANSLATE EDGE

	glPushMatrix(); //TRANSLATE EDGE
	glPopMatrix(); // FIN TRANSLATE EDGE


	glPopMatrix();  //FIN TRANSLATE
}




void drawTower16()
{
	//40 foot pillar, 36 at corner, 
	//42 to roof of 16, then roof starts
	//25 deg rotation (22?)
	/*
	glScalef(1.2,3.55,1.2);*/


	glMaterialfv(GL_FRONT, GL_DIFFUSE, YellowBrickMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, YellowBrickMat2);
	float bottom = -1.0;
	float floorThickness = 0.026;
	float floorInc = 0.5;
	float floorHeight = floorInc - floorThickness;
	//glutSolidCube(2);
	glPushMatrix();  //FLOOR SCALE
	float increment = floorInc;
	float base = bottom + floorInc / 2;

	for (int i = 0; i < 4; i++) //DRAW FLOORS
	{

		glPushMatrix();
		glTranslatef(0, base + i * increment, 0);
		glScalef(1.0, floorThickness / 2, 1.0);
		glutSolidCube(2);
		glPopMatrix();
	}
	glPopMatrix(); //FIN FLOOR SCALE


	glPushMatrix(); //WALLS
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);
	glPushMatrix();

	GLfloat windowWidth = GLfloat(2.5 * 2.0 / 11.5);
	GLfloat windowHeight = GLfloat(floorHeight * 3 / 4);

	GLfloat tweenWallWidth = GLfloat(2.0 / 11.5);

	glTranslatef(0, bottom + floorInc / 4.0 - floorThickness / 2.0, 0);	//BASE WALL MIDDLE
	float height = floorInc / 2.0;
	float wallThickness = 0.07;
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(0), GLfloat(0), GLfloat(-1.0))); 
	//glScalef(1.0, floorInc / 4, 1.0);
	//glutSolidCube(2);
	glPopMatrix();
	for (int i = 0; i < 2; i++) //FLOOR 1 AND 2
	{

		glPushMatrix();
		GLfloat currentCenter = GLfloat(base + i * increment + floorInc *  .5);
		glTranslatef(0, currentCenter, 0);

		drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0))); //left
		drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0))); //right

		//drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // FRONT
		drawWall16(-1.0 + windowWidth + 1.5 * tweenWallWidth,		0,									0, wallThickness,   3 * tweenWallWidth +  2 * windowWidth, floorHeight,		 vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // LEFT WINDOWLESS

		drawWall16(1.0 - (windowWidth + tweenWallWidth) / 2.0, -(3.0/8.0 * floorHeight),	0, wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // RIGHT BELOW WINDOW
		drawWall16(1.0 - (tweenWallWidth) / 2.0, 0,	0, wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // RIGHT TWEEN WALL

		drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(0), GLfloat(0), GLfloat(-1.0))); //back
		drawWindow16(1.0 - (windowWidth / 2.0 + tweenWallWidth), 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW 
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);
		glPopMatrix();
	}

	glPushMatrix();//FLOOR 3
	GLfloat currentCenter = GLfloat(base + 2 * increment + floorInc *  .5);
	glTranslatef(0, currentCenter, 0);

	drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0))); //left
	drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0))); //right

	//drawWall16(-1.0 + windowWidth + 1.5 * tweenWallWidth,		0,									0, wallThickness,   3 * tweenWallWidth +  2 * windowWidth, floorHeight,		 vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // LEFT WINDOWLESS
	//drawWall16(1.0 - (windowWidth + tweenWallWidth) / 2.0, -(3.0/8.0 * floorHeight),	0, wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // RIGHT BELOW WINDOW

	for (int i = 0; i < 3; i++)									//WALL LOOP
	{
		drawWall16(-1.0 + tweenWallWidth / 2.0 + i * (tweenWallWidth + windowWidth), 0,	0, wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // TWEEN WALL

		drawWall16(-1.0 + tweenWallWidth + windowWidth / 2.0 + i * (tweenWallWidth + windowWidth), -(3.0/8.0 * floorHeight),	0, wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0))); //BELOW WINDOW
	}
	drawWall16(0.0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW FILL

	drawWall16(-1.0 + tweenWallWidth / 2.0 + 3.0 * (tweenWallWidth + windowWidth), 0,	0, wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // TWEEN WALL 4

	drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(0), GLfloat(0), GLfloat(-1.0))); //back

	drawWindow16(1.0 - (windowWidth / 2.0 + tweenWallWidth), 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW 
	drawWindow16(-1.0 + tweenWallWidth + windowWidth / 2.0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);
	glPopMatrix();

		

	glPushMatrix();//TOWER ROOF

	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial2);

	float towerRoofBaseThickness = 0.014f;
	currentCenter = GLfloat(base + 3.0f * increment + floorInc );
	glTranslatef(0.0f, currentCenter, 0.0f);
	glScalef(1.05f, 1.0, 1.05f);

	glPushMatrix(); // TOWER ROOF BASE SCALE
	glScalef(1.0f, towerRoofBaseThickness, 1.0f);
	glutSolidCube(2.0f);
	glPopMatrix(); // FIN TOWER ROOF BASE SCALE

	vec4 towerPoint = vec4(0.0f, 0.1f + towerRoofBaseThickness / 2.0, 0.0f, 1.0f);
	vec4 corners[] =   {vec4( 1.0f, 0.0f + towerRoofBaseThickness / 2.0, -1.0f, 1.0f),
		vec4( 1.0f, 0.0f + towerRoofBaseThickness / 2.0,  1.0f, 1.0f),
		vec4(-1.0f, 0.0f + towerRoofBaseThickness / 2.0,  1.0f, 1.0f),
		vec4(-1.0f, 0.0f + towerRoofBaseThickness / 2.0, -1.0f, 1.0f)};

	for(int i = 0; i < 4; i++)
	{
		glBegin(GL_TRIANGLES); //Begin triangle coordinates
		//Triangle
		vec4 normal = Angel::normalize(Angel::cross(towerPoint - corners[(i + 1) % 4], towerPoint - corners[i])); 
		glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(towerPoint.x, towerPoint.y, towerPoint.z);
		glVertex3f(corners[(i + 1) % 4].x, corners[(i + 1) % 4].y, corners[(i + 1) % 4].z);
		glVertex3f(corners[i].x, corners[i].y, corners[i].z);
		glEnd(); //End triangle coordinates
	}

	glPopMatrix(); //FIN TOWER ROOF
	



	//FLOOR 4 beige
	glMaterialfv(GL_FRONT, GL_DIFFUSE, YellowBrickMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, YellowBrickMat2);
	glPushMatrix();//FLOOR 3
	currentCenter = GLfloat(base + 3 * increment + floorInc *  .5);
	glTranslatef(0, currentCenter, 0);


	//drawWall16(-1.0 + windowWidth + 1.5 * tweenWallWidth,		0,									0, wallThickness,   3 * tweenWallWidth +  2 * windowWidth, floorHeight,		 vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // LEFT WINDOWLESS
	//drawWall16(1.0 - (windowWidth + tweenWallWidth) / 2.0, -(3.0/8.0 * floorHeight),	0, wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // RIGHT BELOW WINDOW

	drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(0), GLfloat(0), GLfloat(-1.0))); //back
	for (int i = 0; i < 3; i++)									//WALL LOOP FRONT
	{
		drawWall16(-1.0 + tweenWallWidth / 2.0 + i * (tweenWallWidth + windowWidth), 0,	0, wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // TWEEN WALL

		drawWall16(-1.0 + tweenWallWidth + windowWidth / 2.0 + i * (tweenWallWidth + windowWidth), -(3.0/8.0 * floorHeight),	0, wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0))); //BELOW WINDOW
	}

	drawWall16(-1.0 + tweenWallWidth / 2.0 + 3.0 * (tweenWallWidth + windowWidth), 0,	0, wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // TWEEN WALL 4

	

	
	for (int i = 0; i < 3; i++)									//WALL LOOP RIGHT
	{
		drawWall16(0, 0,	-1.0 + tweenWallWidth / 2.0 + i * (tweenWallWidth + windowWidth), wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0)));  // TWEEN WALL

		drawWall16(0, -(3.0/8.0 * floorHeight),	-1.0 + tweenWallWidth + windowWidth / 2.0 + i * (tweenWallWidth + windowWidth), wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0.0))); //BELOW WINDOW
	}

	drawWall16(0, 0,	-1.0 + tweenWallWidth / 2.0 + 3.0 * (tweenWallWidth + windowWidth), wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0)));  // TWEEN WALL 4

	


	for (int i = 0; i < 3; i++)									//WALL LOOP LEFT
	{
		drawWall16(0, 0,	-1.0 + tweenWallWidth / 2.0 + i * (tweenWallWidth + windowWidth), wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0)));  // TWEEN WALL

		drawWall16(0, -(3.0/8.0 * floorHeight),	-1.0 + tweenWallWidth + windowWidth / 2.0 + i * (tweenWallWidth + windowWidth), wallThickness,   windowWidth + tweenWallWidth,			floorHeight / 4, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0.0))); //BELOW WINDOW
	}

	drawWall16(0, 0,	-1.0 + tweenWallWidth / 2.0 + 3.0 * (tweenWallWidth + windowWidth), wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0)));  // TWEEN WALL 4


	

	drawWindowDoubleBar16(1.0 - (windowWidth / 2.0 + tweenWallWidth), 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW FRONT
	drawWindowDoubleBar16(-1.0 + tweenWallWidth + windowWidth / 2.0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW 
	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW 


	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, 1.0 - (windowWidth / 2.0 + tweenWallWidth), wallThickness, windowWidth, windowHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0)));	//WINDOW RIGHT
	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, -1.0 + tweenWallWidth + windowWidth / 2.0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0)));	//WINDOW 
	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0)));	//WINDOW 


	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, 1.0 - (windowWidth / 2.0 + tweenWallWidth), wallThickness, windowWidth, windowHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0)));	//WINDOW LEFT
	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, -1.0 + tweenWallWidth + windowWidth / 2.0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0)));	//WINDOW 
	drawWindowDoubleBar16(0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0)));	//WINDOW 
	
	
	glPopMatrix(); // FIN FLOOR 4







	glPopMatrix();  //FIN WALLS
	

}



void drawSideBuilding16()
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, YellowBrickMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, YellowBrickMat2);
	float bottom = -0.5;
	float floorThickness = 0.013;
	float floorInc = 0.25;
	float floorHeight = floorInc - floorThickness;

	glPushMatrix();  //FLOOR SCALE
	float increment = floorInc;
	float base = bottom + floorInc / 2;

	for (int i = 0; i < 4; i++) //DRAW FLOORS
	{

		glPushMatrix();
		glTranslatef(0, base + i * increment, 0);
		glScalef(1.0, floorThickness / 2, 1.0);
		glutSolidCube(2);
		glPopMatrix();
	}
	glPopMatrix(); //FIN FLOOR SCALE


	glPushMatrix(); //WALLS
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);
	glPushMatrix();

	GLfloat windowWidth = GLfloat(2.5 * 2.0 / 4.5);
	GLfloat windowHeight = GLfloat(floorHeight * 3 / 4);

	GLfloat tweenWallWidth = GLfloat(2.0 / 4.5);

	glTranslatef(0, bottom + floorInc / 4.0 - floorThickness / 2.0, 0);	//BASE WALL MIDDLE
	float height = floorInc / 2.0;
	float wallThickness = 0.07;
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(-1), GLfloat(0), GLfloat(0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(1), GLfloat(0), GLfloat(0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(0), GLfloat(0), GLfloat(-1))); 
	//glScalef(1.0, floorInc / 4, 1.0);
	//glutSolidCube(2);
	glPopMatrix();
	for (int i = 0; i < 3; i++) //FLOOR 1 - 4
	{

		glPushMatrix();
		GLfloat currentCenter = GLfloat(base + i * increment + floorInc *  .5);
		glTranslatef(0, currentCenter, 0);

		drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(-1.0), GLfloat(0), GLfloat(0))); //left
		drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(1.0), GLfloat(0), GLfloat(0))); //right

		//drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // FRONT
		//drawWall16(-1.0 + windowWidth + 1.5 * tweenWallWidth,		0,									0, wallThickness,   3 * tweenWallWidth +  2 * windowWidth, floorHeight,		 vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // LEFT WINDOWLESS

		drawWall16(-1.0 + (tweenWallWidth) / 2.0, 0,	0, wallThickness,  tweenWallWidth,			floorHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // LEFT TWEEN WALL
		drawWall16(0, -(3.0/8.0 * floorHeight),	0, wallThickness,   windowWidth + tweenWallWidth * 2.0,			floorHeight / 4, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));  // RIGHT BELOW WINDOW

		drawWall16(0, 0, 0, wallThickness, 2, floorHeight, vec3(GLfloat(0), GLfloat(0), GLfloat(-1.0))); //back
		drawWindow16(0, 1.0 / 8.0 * floorHeight, 0, wallThickness, windowWidth, windowHeight, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1.0)));	//WINDOW 
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
		glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);
		glPopMatrix();
	}

	glPushMatrix();	//TOP
	GLfloat currentCenter = GLfloat(base + 3 * increment + floorInc *  .275);
	glTranslatef(0, currentCenter, 0);
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(-1), GLfloat(0), GLfloat(0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(1), GLfloat(0), GLfloat(0))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(0.0), GLfloat(0), GLfloat(1))); 
	drawWall16(0, 0, 0, wallThickness, 2, height, vec3(GLfloat(0), GLfloat(0), GLfloat(-1))); 

	currentCenter = GLfloat(base + 3 * increment + floorInc *0.25);
	glTranslatef(0, -currentCenter / 3 + wallThickness / 8, 0);
	drawWall16(0, 0, 0, wallThickness / 4, 2, 2, vec3(GLfloat(0), GLfloat(currentCenter), GLfloat(0)));
	glPopMatrix(); // FIN TOP

	glPopMatrix();  //FIN WALLS
}


void drawBigSideBuilding16()
{

	float brickRedLight[] = { .58, .33, .16 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedLight);
	glPushMatrix(); // TOP
	glTranslatef(0, 0.25, 0);
	glScalef(1.0, 0.5, 1.0);
	glutSolidCube(1);
	glPopMatrix(); // FIN TOP

	float yellowBrickDark[] = { 0.75, .65, .4 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowBrickDark);
	glMaterialfv(GL_FRONT, GL_AMBIENT, yellowBrickDark);
	glPushMatrix(); // BOTTOM
	glTranslatef(0, -0.25, 0);
	glScalef(1.0, 0.5, 1.0);
	glutSolidCube(1);
	glPopMatrix(); // FIN BOTTOM

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);
}




void drawBuilding16(int closeUp) {
	float scale = 1.0;
	float roofThickness = 0.014;

	glPushMatrix();  //START METHOD

	if (closeUp) {      //OFF LIMITS
		glScalef(4, 4, 4);
		glTranslatef(3.5, 0, 0);
	}
	else {              //OFF LIMITS
		glScalef(.22, 0.3, .31);
		glTranslatef(-7.5, 1.26, 9.8);
		glRotatef(90, 0, 1, 0);
	}
	glTranslatef(-2.075, 0, 1.9);




	glPushMatrix(); //ROTATED SECTION
	glRotatef(-22, 0, 1, 0);


	glPushMatrix();	//TOWER SECTION
	glScalef(0.6, 1.640, 0.6);
	glTranslatef(-0.34, -0.00, 0.3);
	drawTower16();


	glPopMatrix();	//FIN TOWER SECTION


	glPopMatrix();  //FIN ROTATED

	glPushMatrix(); // BACK SIDE BUILDING
	glTranslatef(-0.23, 0, -1.98);
	glScalef(1.3, 3.3, 3.9);
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);


	glutSolidCube(1.0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial2);

	drawWall16(0, -0.5 + roofThickness / 2.0, 0, roofThickness, 1.01, 1.01, vec3(0, 1.0, 0));

	glPopMatrix(); // FIN BACK SIDE BUILDING

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);


	glPushMatrix(); // SIDE BUILDING
	glTranslatef(-1.15, 0, -1.9);
	glScalef(0.3, 3.28, 2.05);



	drawSideBuilding16();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial2);

	drawWall16(0, -0.5 + roofThickness / 2.0 + 0.003, 0, roofThickness, 2.02, 2.02, vec3(0, 1.0, 0));

	glPopMatrix(); // FIN Side BUILDING

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brickRedMat2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brickRedMat2);


	glPushMatrix(); // SIDE SIDE BULDING
	glTranslatef(-2.45, 0, -1.8);
	glScalef(2, 3.28, 4.29);



	drawBigSideBuilding16();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMaterial2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, roofMaterial2);

	drawWall16(0, -0.5 + roofThickness / 2.0 + 0.003, 0, roofThickness, 1.01, 1.01, vec3(0, 1.0, 0));

	glPopMatrix(); // FIN SIDE SIDE BUILDING

	glPopMatrix();	//FIN METHOD
}