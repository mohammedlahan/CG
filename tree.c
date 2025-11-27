#include<stdlib.h>
#include<GL/glut.h>
float manX = 0.1f;
float manY = -1.0f;
float manZ = -1.0f;
float cocoX = 0.08f;
float cocoY = 0.0f;
static int flag=1;
static int flagger=1;
void drawTree(void) {
/*TRUNK*/
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.1,-0.9);
glVertex2f(0.4,-0.9);
glVertex2f(0.28,0.3);
glVertex2f(0.23,0.3);
glEnd();
glFlush();
/*LEAF*/
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.2,0.3);
glVertex2f(0.0,0.1);
glVertex2f(-0.3,0.2);
glVertex2f(-0.4,-0.1);
glEnd();
glFlush();
glBegin(GL_POLYGON);
glVertex2f(0.18,0.65);
glVertex2f(0.23,0.3);
glVertex2f(-0.15,0.8);
glVertex2f(-0.25,0.6);
glEnd();
glFlush();
glBegin(GL_POLYGON);
glVertex2f(0.28,0.3);
glVertex2f(0.48,0.1);
glVertex2f(0.78,0.2);
glVertex2f(0.88,-0.1);
glEnd();
glFlush();
glBegin(GL_POLYGON);
glVertex2f(0.3,0.65);
glVertex2f(0.25,0.3);
glVertex2f(0.63,0.8);
glVertex2f(0.73,0.6);
glEnd();
glFlush();/*leaf end*/
/*COCONUT*/
glColor3f(1.0, 1.0, 0.0);
glTranslatef(0.2,0.3,0);
glutSolidSphere(0.043,100,10);
glTranslatef(0.06,0.05,0);
glutSolidSphere(0.04,100,10);
glTranslatef(cocoX,cocoY,0);
glutSolidSphere(0.04,100,10);
}
void drawMan()
{
/*MAN HEAD*/
glColor3f(0.0, 1.0, 1.0);
glTranslatef(manX,manY-0.2,0);
glutSolidSphere(0.03,100,10);
/*MAN BODY*/
glBegin(GL_LINES);
glVertex2f(0.0,-0.0);
glVertex2f(-0.03,-0.15);
glEnd();
glFlush();
glBegin(GL_LINES);
glVertex2f(-0.03,-0.15);
glVertex2f(0.15,-0.15);
glEnd();
glFlush();
glBegin(GL_LINES);
glVertex2f(-0.015,-0.075);
glVertex2f(0.1,-0.075);
glEnd();
glFlush();
}
void initRendering()
{
glEnable(GL_DEPTH_TEST);
}
void drawScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();//Identity Matrix
drawMan();
//glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
drawTree();
glutSwapBuffers();
}
float rt=0.48;
void update(int value) {
if(flag==1)
{
manY += 0.002f;
if(manY>rt)
{
flag=0;
}
}
if(flag==0)
{
cocoY-= 0.005f;
if(cocoY<-1.2)
flag=2;
}
if (flag==2)
{
manY -= 0.002f;
if(manY<=-0.7)
{
flag=5;
}
}
glutPostRedisplay();
glutTimerFunc(1, update, 5000);
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("Coconut tree climbing");
initRendering();
glutDisplayFunc(drawScene);
glutTimerFunc(30, update, 5000);
glutMainLoop();
return(0);
}