//
//  drawBuilding25.cpp
//  Project3,Milestone1
//
//  Created by Michael on 2/23/14.
//
//

#include "drawBuildings.h"

#include "Angel.h"

void drawBuilding25(int closeUp) {
    // the Harmon
    
    float yellowMat[] = { .75, .75, 0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowMat);
    glMaterialfv(GL_FRONT, GL_AMBIENT, yellowMat);
    
    if (closeUp) {
        glScalef(6,6,6);
    } else {
        glTranslatef(-6.85,1,2.3);
		glScalef(.5,1,.5);
        
        /*glTranslatef(-7,1,2.27);
        glScalef(1, 1, 0.6);*/
    }
    /*
    glScalef(.2,1,.30);
    glutSolidCube(2);
    
    glScalef(.2,1,.30);
    glutSolidCube(2);
    */
    glRotatef(90, 0, 1, 0);
    
    //Window
    glPushMatrix();
    float windowSurface[] = { .1, .27, .46 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, windowSurface);
    glMaterialfv(GL_FRONT, GL_AMBIENT, windowSurface);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTranslatef(0, 0, -.15);
    glScalef(.35, .55, .05);
    glutSolidCube(2);
    
    glDisable(GL_BLEND);
    glPopMatrix();
    
    //Window detail - Vertical
    glPushMatrix();
    float lgrey[4] ={0.8f,0.8f,0.8f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lgrey);
    glTranslatef(0.04, -0.2, 0);
    glScalef(0.025, .5, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lgrey);
    glTranslatef(0.16, -0.2, 0);
    glScalef(0.025, .5, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    //Window detail - Horizontal
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lgrey);
    glTranslatef(0.1, -0.05, 0);
    glScalef(0.38, 0.025, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lgrey);
    glTranslatef(0.1, -0.15, 0);
    glScalef(0.38, 0.025, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lgrey);
    glTranslatef(0.1, -0.25, 0);
    glScalef(0.38, 0.025, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lgrey);
    glTranslatef(0.1, -0.35, 0);
    glScalef(0.38, 0.025, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    float dark[4] ={0.2f,0.2f,0.2f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, dark);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dark);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, dark);
    glTranslatef(0.1, 0.09, 0);
    glScalef(0.38, 0.075, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    //Structure
    glPushMatrix();
    float red[4] ={0.34f,0.2f,0.15f,1.0f}; //132(.52),31(.12),39(.15)
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red);
    glTranslatef(0.1, 1, 0);
    glScalef(0.45, 0.5, .30);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red);
    glTranslatef(-.21,.25, 0);
    glScalef(.14,1.25,.30);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red);
    glTranslatef(.41,.25,0);
    glScalef(.14,1.25,.30);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    float dgrey[4] ={0.6f,0.6f,0.6f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, dgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dgrey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, dgrey);
    glTranslatef(0.1, -0.8, 0);
    glScalef(0.45, .35, .30);
    glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
    float grey[4] ={0.3f,0.3f,0.3f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.095, .475, .2275);
    glScalef(.50, 0.075, .15);
    glutSolidCube(1);
    glPopMatrix();
    
    //Balcony
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.095, -.475, .25);
    glScalef(.50, 0.075, .6);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(0, -.555, .235);
    glScalef(.05, 0.1, .575);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(0.185, -.555, .235);
    glScalef(.05, 0.1, .575);
    glutSolidCube(1);
    glPopMatrix();
    
    //Right railing posts
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.325, -.4, .320);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.325, -.4, .420);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.325, -.4, .520);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    //Left railing posts
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(-.130, -.4, .320);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(-.130, -.4, .420);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(-.130, -.4, .520);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    //Front railing posts
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(-.1, -.4, .525);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(0, -.4, .525);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.185, -.4, .525);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.295, -.4, .525);
    glScalef(0.025, .15, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    //Right railings
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.325, -.41, .425);
    glScalef(0.020, 0.025, 0.2);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.325, -.335, .425);
    glScalef(0.020, 0.025, 0.2);
    glutSolidCube(1);
    glPopMatrix();
    
    //Left railings
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(-.125, -.41, .425);
    glScalef(0.020, 0.025, 0.2);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(-.125, -.335, .425);
    glScalef(0.020, 0.025, 0.2);
    glutSolidCube(1);
    glPopMatrix();
    
    //Front railings
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.1, -.415, .525);
    glScalef(0.40, 0.020, 0.025);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grey);
    glTranslatef(.1, -.33, .525);
    glScalef(0.40, 0.020, 0.025);
    glutSolidCube(1);
    glPopMatrix();
}
