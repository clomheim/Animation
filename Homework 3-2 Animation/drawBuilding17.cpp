

/////////////////////////////////////////////////////////////////////////////////////////

//      BUILDING 17
//      BY JORGE MENESES
//
//      THE Z BUFFER ISSUE IS STILL NOT RESOLVED FOR THE MAC SO TESTING HAS BEEN DIFFICULT,
//      BUT I BELIEVE EVERYTHING SHOULD BE IN THE CORRECT POSITION.

//////////////////////////////////////////////////////////////////////////////////////////


#include "drawBuildings.h"
#include "Angel.h"

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;

void drawBuilding17(int closeUp)
{
   float windowMat[] = { .7, .7, 1};
    float brickMat[] = { .55, .1, .1};
    float metalMat[] = { 0, 0, .7};
    float roofMat[] = { .7, .7, .7};
    float panelMat[] = { .6, .6, .6};

   if (closeUp)
   {
       glTranslatef(0, 0, -5);
       glScalef(.85, .85, .85);
   } else
   {
       glTranslatef(7.8 ,0.75, 0.3);
       glRotatef(90, 0, 1, 0);
       glScalef(.25, .25, .12);
   }
    
    glTranslatef(-2, 0, 0);
    
    ////////////// SIDE THREE ////////////////////////////////////////////////////////
    // side wall
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
    glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
    glPushMatrix();
    glTranslatef(.9, -.62 , -1.63);
    glScalef(3.8, 5.025, 0.25);
    glutSolidCube(1);
    glPopMatrix();

    double side1ShiftAmt = 0;
    double side2ShiftAmt = 0;
    double roofShiftAmt = 0;
    //glRotatef(-90, 0, 1, 0);
    for (int i = 0; i < 4; i++)
    {
        /////////////// ROOF ////////////////////////////////////////////////////////////
        glPushMatrix();
        glTranslatef(0, 0, roofShiftAmt);
        // bottom brick piece
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(.9, 2.475 , 0);
        glRotatef(-16.5, 1, 0, 0);
        glScalef(3.8, 0.05, 3.93);
        glutSolidCube(1);
        glPopMatrix();
        roofShiftAmt = roofShiftAmt + 3.75;
        glPopMatrix();
    
        //////////// SIDE TWO ////////////////////////////////////////////////////////////
        glPushMatrix();
        glTranslatef(0, 0, side2ShiftAmt);
        // windows
        glMaterialfv(GL_FRONT, GL_DIFFUSE, windowMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, windowMat);
        glPushMatrix();
        glTranslatef(.9, 0 , 1.8);
        glScalef(3, 5.3, .075);
        glutSolidCube(1);
        glPopMatrix();
        
        // roof, top
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(.9, 2.75 , 1.82);
        glScalef(3.75, 0.5, .1);
        glutSolidCube(1);
        glPopMatrix();
    
        // roof, bottom
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(.9, 1.5 , 1.82);
        glScalef(3.75, 0.75, .1);
        glutSolidCube(1);
        glPopMatrix();
        
        // roof, left side
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(-0.75, 2.07 , 1.82);
        glScalef(0.5, 1.85, .1);
        glutSolidCube(1);
        glPopMatrix();
        
        // roof, right side
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(2.52, 2.07 , 1.82);
        glScalef(0.5, 1.85, .1);
        glutSolidCube(1);
        glPopMatrix();
        
        // roof panels
        double panelZ = 1.9;
        glMaterialfv(GL_FRONT, GL_DIFFUSE, panelMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, panelMat);
        glPushMatrix();
        glNormal3f(0,0,1);
        glLineWidth(1.5);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES); // left side window
        glVertex3f(-.5, 1.87, panelZ);
        glVertex3f(-.5, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // right side window
        glVertex3f(2.25, 1.87, panelZ);
        glVertex3f(2.25, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // top side window
        glVertex3f(-.5, 2.5, panelZ);
        glVertex3f(2.25, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // bottom side window
        glVertex3f(-.5, 1.87, panelZ);
        glVertex3f(2.25, 1.87, panelZ);
        glEnd();
        glBegin(GL_LINES); // inner window 1
        glVertex3f(.15, 1.87, panelZ);
        glVertex3f(.15, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // inner window 2
        glVertex3f(.9, 1.87, panelZ);
        glVertex3f(.9, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // inner window 3
        glVertex3f(1.55, 1.87, panelZ);
        glVertex3f(1.55, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // diagnol 1
        glVertex3f(-.5, 2.5, panelZ);
        glVertex3f(.15, 1.87, panelZ);
        glEnd();
        glBegin(GL_LINES); // diagnol 2
        glVertex3f(.15, 1.87, panelZ);
        glVertex3f(.9, 2.5, panelZ);
        glEnd();
        glBegin(GL_LINES); // diagnol 3
        glVertex3f(.9, 2.5, panelZ);
        glVertex3f(1.55, 1.87, panelZ);
        glEnd();
        glBegin(GL_LINES); // diagnol 4
        glVertex3f(1.55, 1.87, panelZ);
        glVertex3f(2.25, 2.5, panelZ);
        glEnd();
        glPopMatrix();
        
        // left medal rod
        glMaterialfv(GL_FRONT, GL_DIFFUSE, metalMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, metalMat);
        glPushMatrix();
        glTranslatef(-0.12, -1 , 1.65);
        glScalef(.1, 4.275, 0.3);
        glutSolidCube(1);
        glPopMatrix();
        
        // right medal rod
        glMaterialfv(GL_FRONT, GL_DIFFUSE, metalMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, metalMat);
        glPushMatrix();
        glTranslatef(1.9, -1 , 1.65);
        glScalef(.1, 4.275, 0.3);
        glutSolidCube(1);
        glPopMatrix();
        
        // top medal rod
        glMaterialfv(GL_FRONT, GL_DIFFUSE, metalMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, metalMat);
        glPushMatrix();
        glTranslatef(.9, -0.15 , 1.65);
        glScalef(3.7, 0.1, 0.3);
        glutSolidCube(1);
        glPopMatrix();
        
        // bottom medal rod
        glMaterialfv(GL_FRONT, GL_DIFFUSE, metalMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, metalMat);
        glPushMatrix();
        glTranslatef(.9, -2.1 , 1.65);
        glScalef(3.7, 0.1, 0.3);
        glutSolidCube(1);
        glPopMatrix();
        
        
        // top window trim left
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(-.1, .5 , 1.7);
        glScalef(1, 0.3, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // bottom window trim left
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(-.1, -1.4 , 1.7);
        glScalef(1, 0.3, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // top window trim right
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(1.9, .5 , 1.7);
        glScalef(1, 0.3, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // bottom window trim right
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(1.9, -1.4 , 1.7);
        glScalef(1, 0.3, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // left side pole
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(-.75, -1 , 1.65);
        glScalef(0.5, 4.275, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // right side pole
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(2.5, -1 , 1.65);
        glScalef(0.5, 4.275, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // middle piece
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(.9, -1 , 1.65);
        glScalef(1.25, 4.275, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // top brick piece
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(.9, .9 , 1.65);
        glScalef(3.7, 0.5, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // middle brick piece
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(.9, -1 , 1.65);
        glScalef(3.7, 0.5, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        
        // bottom brick piece
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(.9, -2.89 , 1.65);
        glScalef(3.7, 0.5, 0.5);
        glutSolidCube(1);
        glPopMatrix();
        side2ShiftAmt = side2ShiftAmt + 3.75;
        glPopMatrix();
    
        ////////////// SIDE ONE ////////////////////////////////////////////////////////////
        glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glTranslatef(side1ShiftAmt, 0, 0);
        glPushMatrix();
    
        // top piece, rectangle
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glTranslatef(0, 1.52, 0);
        glScalef(3.75, 0.75, 2);
        glutSolidCube(1);
        glPopMatrix();
        
        // top piece, triangle
        glMaterialfv(GL_FRONT, GL_DIFFUSE, roofMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, roofMat);
        glPushMatrix();
        glNormal3f(0,0,1);
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(1.88, 1.89, 1);  // corner
        glVertex3f(1.88, 3, 1);
        glVertex3f(-1.91, 1.89, 1);
        glEnd();
        glPopMatrix();
    
        // top piece triangle panels
        glMaterialfv(GL_FRONT, GL_DIFFUSE, panelMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, panelMat);
        glPushMatrix();
        glNormal3f(0,0,1);
        glLineWidth(1.5);
        glColor3f(1.0, 0.0, 0.0);
        double panelHorInc = -1.85;
        double panelVerInc = 1.9;
        for (int i = 0; i < 16; i++)
        {
            glBegin(GL_LINES);
            glVertex3f(panelHorInc, 1.15, 1);
            glVertex3f(panelHorInc, panelVerInc, 1);
            glEnd();
            
            panelHorInc = panelHorInc + 0.247;
            panelVerInc = panelVerInc + 0.073;
        }
        glBegin(GL_LINES);
        glVertex3f(-1.85, 1.15, 1);
        glVertex3f(1.85, 1.15, 1);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(-1.85, 1.9, 1);
        glVertex3f(1.85, 3, 1);
        glEnd();
        glPopMatrix();
    
        // left side pole
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(-1.625, -1 , 0);
        glScalef(0.5, 4.275, 2);
        glutSolidCube(1);
        glPopMatrix();
        
        // right side pole
        glMaterialfv(GL_FRONT, GL_DIFFUSE, brickMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, brickMat);
        glPushMatrix();
        glTranslatef(1.625, -1, 0);
        glScalef(.5, 4.275, 2);
        glutSolidCube(1);
        glPopMatrix();
        
        // windows
        glMaterialfv(GL_FRONT, GL_DIFFUSE, windowMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, windowMat);
        glPushMatrix();
        glTranslatef(0, -1, 0);
        glScalef(2.65, 4.275, 0);
        glutSolidCube(1);
        glPopMatrix();
        
        // inner horizontal poles
        glMaterialfv(GL_FRONT, GL_DIFFUSE, metalMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, metalMat);
        double shiftAmount = -1.35;
        for (int i = 0; i < 7; i++)
        {
            glPushMatrix();
            glTranslatef(shiftAmount, -1, 0);
            glScalef(.075, 4.275, 1.75);
            glutSolidCube(1);
            glPopMatrix();
            
            shiftAmount = shiftAmount + 0.45;
        }
        
        // inner vertical poles
        glMaterialfv(GL_FRONT, GL_DIFFUSE, metalMat);
        glMaterialfv(GL_FRONT, GL_AMBIENT, metalMat);
        shiftAmount = 1.1;
        for (int i = 0; i < 9; i++)
        {
            glPushMatrix();
            glTranslatef(0, shiftAmount, 0);
            glScalef(2.7, .075, 1.75);
            glutSolidCube(1);
            glPopMatrix();
            
            shiftAmount = shiftAmount - .525;
        }
        
        side1ShiftAmt = side1ShiftAmt + 3.75;
        glPopMatrix();
        glPopMatrix();
    }
}
