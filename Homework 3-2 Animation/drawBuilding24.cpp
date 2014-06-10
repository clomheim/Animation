#include <math.h>

#include "drawBuildings.h"

#include "Angel.h"


/* Tarl Hahn  Milestone 3 checking 1
    
   I have tried my best on the small building.  I could not adequate test if it looks complete and accurate.
*/

void drawSolidCube(float transX, float transY, float transZ,
				   float scaleX, float scaleY, float scaleZ, float color[]) 
{

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	// build outside pillar
	glPushMatrix();
	glTranslatef(transX, transY, transZ);
	glScalef(scaleX, scaleY, scaleZ);
	glutSolidCube(2);
	glPopMatrix();
}

void drawSolidCubeRotateZ(float transX, float transY, float transZ,
	float scaleX, float scaleY, float scaleZ, float angle, float color[])
{

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	// build outside pillar
	glPushMatrix();
	glTranslatef(transX, transY, transZ);
	glScalef(scaleX, scaleY, scaleZ);
	glRotatef(angle, 0, 0, 1);
	glutSolidCube(2);
	glPopMatrix();
}

void drawMatLanding(float x, float y, float z, float width, float length, float thickness, 
	                float framecolor[], float underColor[], float concrete[])
{
	// draws the frame
	drawSolidCube(x, y, z - length + thickness, width, thickness, thickness, framecolor); // width 1
	drawSolidCube(x, y, z + length - thickness, width, thickness, thickness, framecolor); // width 2
	drawSolidCube(x - width + thickness, y, z, thickness, thickness, length, framecolor); // length 1
	drawSolidCube(x + width - thickness, y, z, thickness, thickness, length, framecolor); // length 2

	// white underside
	drawSolidCube(x, y, z, width - thickness, thickness / 10, length - thickness, underColor); //  top inside end

	// landing fill color
	drawSolidCube(x, y + thickness - thickness / 10, z, width - thickness, thickness / 10, length - thickness, concrete);

}

void matPanelWithHole(float x, float y, float z, float height, float width,
		       		  float thickness, float radius, float color[])
{
	float i;
	float sinMod;
	float cosMod;
	for (i = 0; i < 360; i += .1) {
		sinMod = radius * sin(i);
		cosMod = radius * cos(i);
		drawSolidCubeRotateZ(x + sinMod, y + cosMod, z, thickness, thickness, thickness, i, color);
	}
	
	// outside section
	float boundsMod = radius - thickness;

	drawSolidCube(x, y + (height / 2), z, width, (height / 2) - boundsMod, thickness, color); // top
	drawSolidCube(x, y - (height / 2), z, width, (height / 2) - boundsMod, thickness, color); // bottom
	
	drawSolidCube(x - (width / 2) - thickness * 2.5, y, z, (width / 2) - thickness * 2.5, radius, thickness, color); // middle left 
	drawSolidCube(x + (width / 2) + thickness * 2.5, y, z, (width / 2) - thickness * 2.5, radius, thickness, color);  // middle right
	
}

void matStairs(float x, float y, float z, float width, float height,
			   float depth, float thickness, float color[])
{
	////////////  the actual stairs people walk on.
	// top stair to bottom stair
	float j;
	float i;
	float stairwidth = depth * .36;
	// stairs outside
	for (i = thickness * .7; i <= height * .2; i += thickness * 1.25) {
		j = i * .85;
		drawSolidCube(x + width * .4 - j, y + height * .415 - i, z + depth / 1.75, thickness, thickness, stairwidth, color);
		drawSolidCube(x + width * .4 - j, y - i + height * .035, z + depth / 1.75, thickness, thickness, stairwidth, color);
		drawSolidCube(x + width * .4 - j, y - height * .335 - i, z + depth / 1.75, thickness, thickness, stairwidth, color);
	}

	// stairs inside
	for (i = thickness * .7; i <= height * .2; i += thickness * 1.25) {
		j = i * .85;
		drawSolidCube(x + width * .4 - j, y + height * .422 + i, z - depth / 7, thickness, thickness, stairwidth, color);
		drawSolidCube(x + width * .4 - j, y + height * .03 + i, z - depth / 7, thickness, thickness, stairwidth, color);
		drawSolidCube(x + width * .4 - j, y - height * .357 + i, z - depth / 7, thickness, thickness, stairwidth, color);
		drawSolidCube(x + width * .4 - j, y - height * .73 + i, z - depth / 7, thickness, thickness, stairwidth, color);
	}
}

void matStairLanding(float x, float y, float z, float width, float height,
					 float depth, float thickness, float stair_frame[], float roof[])
{
	////////////////////  inside platform
	float platwidth = width * .5;
	float landingWidth = width * .2;
	float length = depth * .72;
	float z_local = z + depth * .22;

	drawMatLanding(x - width / 2 - thickness, y + height * .6, z_local, width * .25, length, thickness, stair_frame, roof, stair_frame); // builds the top inside landing (main)
	drawMatLanding(x - width * .25, y + height * .6, z - thickness * 1.65, width / 4, depth * .4, thickness, stair_frame, roof, stair_frame); // builds the top inside landing (fill)
	drawMatLanding(x - width / 2, y + height / 4 - thickness, z_local, platwidth, length, thickness, stair_frame, roof, stair_frame); // builds the top inside landing (middle)
	drawMatLanding(x - width / 2, y - height / 6, z_local, platwidth, length, thickness, stair_frame, roof, stair_frame); // builds the top inside landing (middle)
	drawMatLanding(x - width / 2, y - height / 2 - thickness, z_local, platwidth, length, thickness, stair_frame, roof, stair_frame); // builds the top inside landing (bottom)

	drawMatLanding(x + width * .6, y + height * .4, z_local, landingWidth, length, thickness, stair_frame, roof, stair_frame); // builds the top outside landing (top)
	drawMatLanding(x + width * .6, y + thickness, z_local, landingWidth, length, thickness, stair_frame, roof, stair_frame); // builds the top outside landing (top middle)
	drawMatLanding(x + width * .6, y - height * .35, z_local, landingWidth, length, thickness, stair_frame, roof, stair_frame); // builds the top outside landing (bottom middle)
	drawMatLanding(x + width * .6, y - height * .75, z_local, landingWidth, length, thickness, stair_frame, roof, stair_frame); // builds the top outside landing (bottom)
	
}

void matStairWellFrame(float x, float y, float z, float width, float height, 
					   float depth, float metal_frame[], float roof[])
{
	int thick_div = 32; // thickness divisor to generate thickness from width/height.
	float thick_w = width / thick_div;
	float thick_d = depth / thick_div;

	float crossBarLen = width * .75;
	float crossBarLoc = x - width / 2 + crossBarLen / 2;
	float near_pillar_x = x - width / 3;
	float far_pillar_x = x + width * .65;
	
	float topCross = y + height - thick_d * 1.75 - .001;
	// frame for stairwell
	drawSolidCube(near_pillar_x, y, z - depth / 2 - thick_d, thick_w, height, thick_d, metal_frame); // near tower pillar
	drawSolidCube(near_pillar_x, y, z + depth - thick_d, thick_w, height, thick_d, metal_frame); // near tower pillar

	drawSolidCube(far_pillar_x, y, z - depth / 2 - thick_d, thick_w, height, thick_d, metal_frame); // far pillar
	drawSolidCube(far_pillar_x, y, z + depth - thick_d, thick_w, height, thick_d, metal_frame); // far pillar

	// inside bars
	drawSolidCube(x, topCross, z - depth / 2 - thick_d, width, (thick_d * 1.75), thick_d, metal_frame); // top cross near
	drawSolidCube(crossBarLoc, topCross - (height * .75), z - depth / 2 - thick_d, crossBarLen, thick_d, thick_d, metal_frame); // middle cross near
	drawSolidCube(crossBarLoc, topCross - (height * 1.5), z - depth / 2 - thick_d, crossBarLen, thick_d, thick_d, metal_frame); // bottom cross near

	// outside bars
	drawSolidCube(x, topCross, z + depth - thick_d - .001, width, (thick_d * 1.75), thick_d, metal_frame); // top cross far
	drawSolidCube(crossBarLoc, topCross - (height * .75), z + depth - thick_d - .001, crossBarLen, thick_d, thick_d, metal_frame); // middle cross far
	drawSolidCube(crossBarLoc, topCross - (height * 1.5), z + depth - thick_d - .001, crossBarLen, thick_d, thick_d, metal_frame); //  bottom cross far

	// off white ceiling/roof
	drawSolidCube(x, topCross, z + depth / 5, width - width / 1000, thick_d / 4, depth * .75, roof);
}



void drawBuilding24(int closeUp) {
	// colors
	float metal_frame[] = { .45, .45, .45 };
	float stair_frame[] = { .65, .65, .6 };
	float tower[] = { .75, .75, 1 };
	float roof[] = { 1, 1, .9 };
	float black[] = { 0, 0, 0 };
	float mesh[] = { .4, .4, .4 };
	// translation modifiers
	float transX;
	float transY;
	float transZ;

	// scale modifier
	float scale;

	if (closeUp) {
		// tower behind stairwell
		drawSolidCube(-4.75, 0, 0, 2.75, 7, 2.75, tower);

		matStairWellFrame(0, 0, 0, 2.75, 7, 2.75, metal_frame, roof);
		
		matStairLanding(0, 0, 0, 2.75, 7, 2.75, .15, stair_frame, roof);
		
		matStairs(0, 0, 0, 2.75, 7, 2.75, .15, stair_frame);
		
		matPanelWithHole(.45, -5.32, 2.65, 2.23, 1.3, .1, .65, mesh);
		matPanelWithHole(.45, -5.32, -1.45, 2.23, 1.3, .1, .65, mesh);
		
		// mesh panels
		drawSolidCube(-1, 0, -2, .15, 7, .8, mesh); // tall mesh panel
		drawSolidCube(1.7, -6.2, .6, .1, .8, 2, mesh);
		drawSolidCube(-1.4, -5.3, 2.55, .7, 1.7, .15, mesh);
		drawSolidCube(-2, -5.3, .5, .15, 1.7, 2, mesh);
	
	}
	else {
		// tower behind stairwell
		drawSolidCube(-7.75, .75, 1.45, .25, .75, .25, tower);

		matStairWellFrame(- 7.35, .75, 1.45, .25, .75, .25, metal_frame, roof);

		matStairLanding(-7.35, .75, 1.45, .25, .75, .25, .01, stair_frame, roof);

		matStairs(-7.35, .75, 1.45, .25, .75, .25, .01, stair_frame);

		matPanelWithHole(-7.33, .2, 1.7, .205, .12, .01, .015, mesh);
		matPanelWithHole(-7.33, .2, 1.29, .205, .12, .01, .015, mesh);

		// mesh panels
		drawSolidCube(-7.45, .75, 1.25, .01, .75, .1, mesh); // tall mesh panel
		drawSolidCube(-7.25, .2, 1.4, .05, .2, .2, mesh); // front
		drawSolidCube(-7.45, .2, 1.649, .1, .2, .05, mesh); // side door
		drawSolidCube(-7.5, .2, 1.4, .05, .2, .2, mesh); // backing
	}
}
