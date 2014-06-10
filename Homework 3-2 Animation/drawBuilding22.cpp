/*
Ching-Ting Huang
UWT Computer Graphics 
Feb-March 2014
*/

#include "drawBuildings.h"

#include "Angel.h"

void top22() {
	float top_material_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	float top_material_diffuse[] = { 0.72, 0.84, 1, 1.0 };
	float top_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float top_material_shininess = 5.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, top_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, top_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, top_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, top_material_shininess);

	//top
	glPushMatrix();
	glTranslatef(0, 0, -1.85);
	glScalef(7, 1, 3.57);
	glutSolidCube(2);
	glPopMatrix();

	//bar
	glPushMatrix();
	glTranslatef(0, 1.3, -1.8);
	glScalef(7, 0.3, 3.6);
	glutSolidCube(2);
	glPopMatrix();

}

void bottom22() {
	float bottom_material_ambient[] = { 0, 0, 0, 1.0 };
	float bottom_material_diffuse[] = { 1, 0.55, 0.35, 1.0 };
	float bottom_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float bottom_material_shininess = 5.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, bottom_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bottom_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bottom_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bottom_material_shininess);

	glPushMatrix();
	glTranslatef(0, 0, -1.9);
	glScalef(7, 1, 3.5);
	glutSolidCube(2);
	glPopMatrix();
}

void behind22() {
	float wall_material_ambient[] = { 0, 0, 0, 1.0 };
	float wall_material_diffuse[] = { 1, 0.55, 0.35, 1.0 };
	float wall_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float wall_material_shininess = 1.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, wall_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, wall_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, wall_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, wall_material_shininess);
	
	glPushMatrix();
	glTranslatef(0, 0, -7);
	glScalef(7, 6, 1);
	glutSolidCube(2);
	glPopMatrix();
}

void light22() {
	glScalef(1, 0.8, 1);

	//cap
	float cap_material_ambient[] = { 0, 0, 0, 1.0 };
	float cap_material_diffuse[] = { 0.1, 0.1, 0.1, 1.0 };
	float cap_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float cap_material_shininess = 22;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, cap_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, cap_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, cap_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, cap_material_shininess);

	glPushMatrix();
	glRotatef(15, 1, 0, 0);
	glScalef(1, 1.3, 1);
	glutSolidCube(2);
	glPopMatrix();

	//bulb
	float bulb_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float bulb_material_diffuse[] = { 1, 1, 1, 1.0 };
	float bulb_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float bulb_material_shininess = 22;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, bulb_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bulb_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bulb_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bulb_material_shininess);

	glPushMatrix();
	glTranslatef(0, -0.1, 0.2);
	glScalef(0.9, 0.7, 1);
	glutSolidCube(2);
	glPopMatrix();

}

void pipe22() {
	float pipe_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float pipe_material_diffuse[] = { 0.15, 0.40, 0.95, 1.0 };
	float pipe_material_specular[] = { 0.5, 0.5, 0.5, 1.0 };
	float pipe_material_shininess = 22;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, pipe_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, pipe_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, pipe_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, pipe_material_shininess);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(0.1, 6, 1);
	glutSolidCube(2);
	glPopMatrix();
}

void whiteStrip22() {
	//white strip
	float plate_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float plate_material_diffuse[] = { 0.85, 0.85, 0.85, 1.0 };
	float plate_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float plate_material_shininess = 10.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

	glPushMatrix();
	glTranslatef(0, 0, -0.1);
	glScalef(2, 1, 0.5);
	glutSolidCube(2);
	glPopMatrix();

	//bar
	float bar_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float bar_material_diffuse[] = { 0.85, 0.85, 1, 1.0 };
	float bar_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float bar_material_shininess = 10.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glScalef(2, 0.1, 0.5);
	glutSolidCube(2);
	glPopMatrix();
}

void blueVent22() {
	int i; float y = 0;

	float frame_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float frame_material_diffuse[] = { 0.15, 0.40, 0.95, 1.0 };
	float frame_material_specular[] = { 0, 0, 0, 1.0 };
	float frame_material_shininess = 1.0;

	float plate_material_ambient[] = { 0, 0, 0, 1.0 };
	float plate_material_diffuse[] = { 0.6, 0.75, 0.95, 1.0 };
	float plate_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float plate_material_shininess = 21;

	for (i = 0; i < 10; i++) {
		//plates
		glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

		glPushMatrix();
		glTranslatef(0, y, 0);
		glRotatef(50, 1, 0, 0);
		glScalef(2, 0.1, 0.5);
		glutSolidCube(2);
		glPopMatrix();
		y -= 0.5;
	}

	//small top frame 1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

	glPushMatrix();
	glTranslatef(0, 0.44, 0);
	glScalef(2.1, 0.05, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	//big top frame 2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, frame_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, frame_material_shininess);

	glPushMatrix();
	glTranslatef(0, 0.65, 0);
	glScalef(2.37, 0.1, 0.4);
	glutSolidCube(2);
	glPopMatrix();

	//small right frame 1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

	glPushMatrix();
	glTranslatef(2.08, -2.28, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(2.69, 0.05, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	//big right frame 2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, frame_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, frame_material_shininess);

	glPushMatrix();
	glTranslatef(2.26, -2.28, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(2.85, 0.1, 0.4);
	glutSolidCube(2);
	glPopMatrix();

	//small left frame 1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

	glPushMatrix();
	glTranslatef(-2.08, -2.28, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(2.69, 0.05, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	//big left frame 2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, frame_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, frame_material_shininess);

	glPushMatrix();
	glTranslatef(-2.26, -2.28, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(2.85, 0.1, 0.4);
	glutSolidCube(2);
	glPopMatrix();

	//small bottom frame 1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

	glPushMatrix();
	glTranslatef(0, -4.94, 0);
	glScalef(2.05, 0.05, 0.3);
	glutSolidCube(2);
	glPopMatrix();

	//big bottom frame 2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, frame_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, frame_material_shininess);

	glPushMatrix();
	glTranslatef(0, -5.1, 0);
	glScalef(2.37, 0.1, 0.4);
	glutSolidCube(2);
	glPopMatrix();

}

void bluePlate22() {
	int i;  float y = 0.0;

	float plate_material_ambient[] = { 0, 0, 0, 1.0 };
	float plate_material_diffuse[] = { 0.65, 0.8, 1, 1.0 };
	float plate_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float plate_material_shininess = 1.0;

	float concave_material_ambient[] = { 0, 0, 0, 1.0 };
	float concave_material_diffuse[] = { 0.6, 0.8, 1, 1.0 };
	float concave_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float concave_material_shininess = 10.0;

	//plate
	glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

	glPushMatrix();
	glTranslatef(0, y, 0);
	glScalef(1.14, 0.2, 1);
	glutSolidCube(2);
	glPopMatrix();

	y = -0.25;

	for (i = 0; i < 6; i++) {
		//concave
		glMaterialfv(GL_FRONT, GL_DIFFUSE, concave_material_diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, concave_material_ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, concave_material_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, concave_material_shininess);

		glPushMatrix();
		glTranslatef(0, y, -0.000001);
		glScalef(1.14, 0.05, 0.8);
		glutSolidCube(2);
		glPopMatrix();

		//plate
		glMaterialfv(GL_FRONT, GL_DIFFUSE, plate_material_diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, plate_material_ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, plate_material_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, plate_material_shininess);

		glPushMatrix();
		glTranslatef(0, y - 0.25, 0);
		glScalef(1.14, 0.2, 1);
		glutSolidCube(2);
		glPopMatrix();

		y -= 0.5;

	}
}

void specialWindow22() {
	glNormal3f(0, 0, 1);

	float window[] = { 0.1, 0.27, 0.46 };
	float bar_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float bar_material_diffuse[] = { 0.15, 0.40, 0.95, 1.0 };
	float bar_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float bar_material_shininess = 22;

	//top bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, 2.1, 1);
	glScalef(1, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//left bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(-1.08, -0.43, 1);
	glScalef(0.08, 2.62, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//right bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(1.08, -0.43, 1);
	glScalef(0.08, 2.62, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//window 1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glTranslatef(0, 1.15, 0.95);
	glScalef(1, 0.95, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glDisable(GL_BLEND);

	//middle bar1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, 0.2, 1);
	glScalef(1, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//window2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glTranslatef(0, -0.1, 0.95);
	glScalef(1, 0.45, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glDisable(GL_BLEND);

	//middle bar2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, -0.5, 1);
	glScalef(1, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//window3
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glTranslatef(0, -1.82, 0.95);
	glScalef(1, 1.3, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glDisable(GL_BLEND);

	// bottom bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, -3.15, 1);
	glScalef(1.14, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

}

void normalWindow22() {
	glNormal3f(0, 0, 1);

	float window[] = { 0.1, 0.27, 0.46 };
	float bar_material_ambient[] = { 0.55, 0.45, 0.35, 1.0 };
	float bar_material_diffuse[] = { 0.05, 0.40, 0.85, 1.0 };
	float bar_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float bar_material_shininess = 22;
	

	//top bar

	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, 2.1, 1);
	glScalef(1.1, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//left bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(-1.08, -0.437, 1);
	glScalef(0.08, 2.63, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//right bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(1.08, -0.437, 1);
	glScalef(0.08, 2.63, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//window 1
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glTranslatef(0, 1, 0.95);
	glScalef(1, 1.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glDisable(GL_BLEND);

	//bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, -0.11, 1);
	glScalef(1, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//window2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glTranslatef(0, -1.23, 0.95);
	glScalef(1, 1.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glDisable(GL_BLEND);

	//bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, -2.35, 1);
	glScalef(1, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	//window3
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window);
	glMaterialfv(GL_FRONT, GL_AMBIENT, window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glPushMatrix();
	glTranslatef(0, -2.75, 0.95);
	glScalef(1, 0.3, 0.05);
	glutSolidCube(2);
	glPopMatrix();

	glDisable(GL_BLEND);

	// bottom bar
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, bar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, bar_material_shininess);

	glPushMatrix();
	glTranslatef(0, -3.15, 1);
	glScalef(1.16, 0.1, 0.05);
	glutSolidCube(2);
	glPopMatrix();
}

void specialWindowStrip22(int pos) {
	int i; float y;

	glScalef(0.7, 0.6, 1);

	//vent
	glPushMatrix();
	glTranslatef(0, 10.5, 1);
	glScalef(1.4, 0.6, 1);
	blueVent22();
	glPopMatrix();

	//white plate
	glPushMatrix();
	glTranslatef(0, 7, 1);
	glScalef(1.67, 0.4, 1);
	whiteStrip22();
	glPopMatrix();

	y = 4.4;

	for (i = 1; i < 6; i++) {
		if (i % 2 == 1) {
			//special window @ left
			if (pos == 0) {
				//special window
				glPushMatrix();
				glTranslatef(-2.2, y, 0);
				specialWindow22();
				glPopMatrix();

				//window 1
				glPushMatrix();
				glTranslatef(0, y, 0);
				normalWindow22();
				glPopMatrix();

				//window 2
				glPushMatrix();
				glTranslatef(2.2, y, 0);
				normalWindow22();
				glPopMatrix();

				//special window @ right
			}
			else if (pos == 1) {
				//window 1
				glPushMatrix();
				glTranslatef(-2.2, y, 0);
				normalWindow22();
				glPopMatrix();

				//window 2
				glPushMatrix();
				glTranslatef(0, y, 0);
				normalWindow22();
				glPopMatrix();

				//special window
				glPushMatrix();
				glTranslatef(2.2, y, 0);
				specialWindow22();
				glPopMatrix();
			}
			y -= 3.35;

		}
		else if (i % 2 == 0) {
			//plates
			glPushMatrix();
			glTranslatef(0, y, 0.3);
			glScalef(2.9, 1, 1);
			bluePlate22();
			glPopMatrix();
			y -= 5.4;
		}
	}

}

void normalWindowStrip22() {
	int i; float y;

	glScalef(0.7, 0.6, 1);

	//vent
	glPushMatrix();
	glTranslatef(0, 10.5, 1);
	glScalef(1, 0.6, 1);
	blueVent22();
	glPopMatrix();

	//white plate
	glPushMatrix();
	glTranslatef(0, 7, 1);
	glScalef(1.17, 0.4, 1);
	whiteStrip22();
	glPopMatrix();

	y = 4.4;

	for (i = 1; i < 6; i++) {
		if (i % 2 == 1) {
			//window 1
			glPushMatrix();
			glTranslatef(-1.15, y, 0);
			normalWindow22();
			glPopMatrix();

			//window 2
			glPushMatrix();
			glTranslatef(1.15, y, 0);
			normalWindow22();
			glPopMatrix();
			y -= 3.35;

		}
		else if (i % 2 == 0) {
			//plates
			glPushMatrix();
			glTranslatef(0, y, 0.3);
			glScalef(2.05, 1, 1);
			bluePlate22();
			glPopMatrix();
			y -= 5.4;
		}
	}
}

void pillar22() {
	float pillar_material_ambient[] = { 0, 0, 0, 1.0 };
	float pillar_material_diffuse[] = { 1, 0.55, 0.35, 1.0 };
	float pillar_material_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float pillar_material_shininess = 1.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, pillar_material_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, pillar_material_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, pillar_material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, pillar_material_shininess);

	//pillar
	glPushMatrix();
	glTranslatef(0, 0, -1.8);
	glScalef(1, 7, 3.5);
	glutSolidCube(2);
	glPopMatrix();

	//light bulb
	glPushMatrix();
	glTranslatef(0, -5, 1.3);
	glScalef(0.3, 0.3, 0.5);
	light22();
	glPopMatrix();
}

void build22() {
	int i; float x;

	glTranslatef(-0.33, 0.2, 0);
	glScalef(0.1, 0.15, 0.1);

	//top bars
	glPushMatrix();
	glTranslatef(3.46, 6.65, 0);
	glScalef(2.02, 0.15, 1);
	top22();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslatef(3.49, -10.1, -0.15);
	glScalef(1.99, 0.3, 1);
	bottom22();
	glPopMatrix();

	//behind
	glPushMatrix();
	glTranslatef(3.48, -1.8, -4.8);
	glScalef(1.995, 1.43, 0.1);
	behind22();
	glPopMatrix();

	//first pillar (left)
	glPushMatrix();
	glTranslatef(-10, -1.85, -0.1);
	glScalef(0.5, 1.22, 1);
	pillar22();
	glPopMatrix();

	//last pillar (right)
	glPushMatrix();
	glTranslatef(16.98, -1.85, -0.1);
	glScalef(0.5, 1.22, 1);
	pillar22();
	glPopMatrix();

	x = -8.75;

	for (i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			//normal window strip
			glPushMatrix();
			glTranslatef(x, 0, 0);
			glScalef(0.5, 1, 1);
			normalWindowStrip22();
			glPopMatrix();

			x += 1.9;

			//pipe
			glPushMatrix();
			glTranslatef(x-1.1, -1.87, 0.6);
			glScalef(1, 1.42, 1);
			pipe22();
			glPopMatrix();

			//special window strip
			glPushMatrix();
			glTranslatef(x, 0, 0);
			glScalef(0.5, 1, 1);
			specialWindowStrip22(1);
			glPopMatrix();

			x += 1.25;

		}
		else if (i % 2 == 1) {
			//special window strip
			glPushMatrix();
			glTranslatef(x, 0, 0);
			glScalef(0.5, 1, 1);
			specialWindowStrip22(0);
			glPopMatrix();

			x += 1.9;

			//pipe
			glPushMatrix();
			glTranslatef(x - 0.81, -1.87, 0.6);
			glScalef(1, 1.42, 1);
			pipe22();
			glPopMatrix();

			//normal window strip
			glPushMatrix();
			glTranslatef(x, 0, 0);
			glScalef(0.5, 1, 1);
			normalWindowStrip22();
			glPopMatrix();

			x += 1.25;
		}

		x += 0.05;

		if (i < 5) {
			//pillar
			glPushMatrix();
			glTranslatef(x, -1.85, -0.1);
			glScalef(0.5, 1.22, 1);
			pillar22();
			glPopMatrix();
		}

		x += 1.3;
	}
}

//Main program starts here 
void drawBuilding22(int closeUp) {
	//Science building : wall section

	if (closeUp) {
		glScalef(6, 6, 6);
	}
	else {
		glTranslatef(3.5, 1.1, -0.6);
		glScalef(0.8, 0.8, 1);
		glRotatef(-18, 0, 1, 0);
	}

	//normalWindow();
	build22();
}