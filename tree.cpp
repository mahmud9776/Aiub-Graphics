#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <time.h>
#include <iostream>
#include <MMSystem.h>
using namespace std;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;
static GLfloat spin = 0.0;
float spin_x=1.0;
float spin_y=0.0;
float spin_z=0.0;
int day=1;
bool rain=false;
bool carv=false;
bool planev=false;
bool top=false;
int flag=0;
bool help=false;


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768.0);
}




void ttprint(int x, int y,int z, char *string)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

    //loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
};



void otherCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius,int r,int g,int b)
{
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y,z); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount)),z
			);
		}
	glEnd();
}

void Tree(int x,int y,int z)
{
    //Timber
    glColor3ub(90,70,60);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+20,z);
    glVertex3i(x,y+20,z);
    glEnd();

    //Lower Leaf
    glColor3ub(14,120,14);
    glBegin(GL_TRIANGLES);
    glVertex3i(x-15,y+19,z);
    glVertex3i(x+22,y+19,z);
    glVertex3f(x+3.5,y+45,z);
    glEnd();

    //Upper Leaf
    glBegin(GL_TRIANGLES);
    glVertex3i(x-10,y+35,z);
    glVertex3i(x+17,y+35,z);
    glVertex3f(x+3.5,y+60,z);
    glEnd();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Tree(310,130,0);

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1920, 1080);
glutInitWindowPosition (0, 0);
glutCreateWindow ("AIUB");
myInit();
glutDisplayFunc(myDisplay);
//glutReshapeFunc(reshape);
//glutKeyboardFunc(keyboard);
//glutSpecialFunc(SpecialKeys);
glutMainLoop();
return 0;
}



