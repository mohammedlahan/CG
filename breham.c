#include<GL/glut.h>
void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,500.0,0.0,500.0);
}
void brescen()
{
float x1=150.0,y1=50.0,x2=200.0,y2=200.0;
float x=x1,y=y1,e,d1,d2;
float i;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
d1=x2-x1;
d2=y2-y1;
e=2*y-d1;

for(i=0.0;i<d1;i=i+0.1)
{
glVertex2f(x,y);
while(e>0)
{
y=y+1;
e=e-2*d1;
}
x=x+1;
e=e+2*d2;
}
glEnd();
glFlush();

}
void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(400,300);
glutCreateWindow("Line");
init();
glutDisplayFunc(brescen);
glutMainLoop();
}