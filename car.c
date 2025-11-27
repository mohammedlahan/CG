#include<stdlib.h>
#include<GL/glut.h>
float carX = -0.8f;
float carY = -0.5f;
float carZ = -1.0f;
float wheel1X=-0.7,wheel1Y=-0.3,wheel2X=-0.3,wheel2Y=-0.3;
static int flag=1;
static int flagger=1;
void drawCar(void) {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 1.0, 1.0);
glTranslatef(carX,carY,carZ);
glBegin(GL_POLYGON);
glVertex2f(-0.5,0);
glVertex2f(-0.5,0.2);
glVertex2f(-0.3,0.2);
glVertex2f(-0.1,0.5);
glVertex2f(0.1,0.5);
glVertex2f(0.3,0.2);
glVertex2f(0.5,0.2);
glVertex2f(0.5,0);
glEnd();
glFlush();
glColor3f(1.0, 0.0, 0.0);
glTranslatef(0.3,0,0);
glutSolidSphere(0.1,100,10);
glColor3f(1.0, 1.0, 0.0);
glTranslatef(-0.6,0,0);
glutSolidSphere(0.1,100,10);
}
void keyPress(int key, int x, int y)
{
if(key==GLUT_KEY_UP)
carY += 0.05f;
if(key==GLUT_KEY_DOWN)
carY -= 0.05f;
if(key==GLUT_KEY_LEFT)
carX -= 0.05f;
if(key==GLUT_KEY_RIGHT)
carX += 0.05f;
glutPostRedisplay();}
void initRendering()
{
glEnable(GL_DEPTH_TEST);
}
void drawScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();//Identity Matrix
drawCar();
glutSwapBuffers();
}
float rt=0.5;
void updater(int value){
if(flag==1)
{
carX += 0.0004f;
if(carX>1.5)
{
flag=0;
}
}
glutPostRedisplay();
glutTimerFunc(1, updater, 5000);
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowPosition(0,0);
glutInitWindowSize(400,400);
glutCreateWindow("car Bounce");
initRendering();
glutDisplayFunc(drawScene);
glutSpecialFunc(keyPress);
glutTimerFunc(30, updater, 5000);
glutMainLoop();
return(0);
}