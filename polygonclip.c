#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


int i, n, xmin, xmax, ymin, ymax, side1[10], side2[10], ch;


int showClipped = 0;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void getdata()
{
    printf("Enter the no of vertices:");
    
    scanf("%d", &n);
    printf("Enter the sides:");
    
    for (i = 0; i < n; i++)
        scanf("%d%d", &side1[i], &side2[i]);
}

void polygon1()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!showClipped) {
       
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_LINE_LOOP);
            glVertex2i(0, 0);
            glVertex2i(100, 0);
            glVertex2i(100, 100);
            glVertex2i(0, 100);
        glEnd();
        glFlush();

        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_LINE_LOOP);
            for (i = 0; i < n; i++)
                glVertex2i(side1[i], side2[i]);
        glEnd();
        glFlush();
    } else {
        
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINE_LOOP);
            glVertex2i(0, 0);
            glVertex2i(100, 0);
            glVertex2i(100, 100);
            glVertex2i(0, 100);
        glEnd();
        glFlush();

        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_LINE_LOOP);
            for (i = 0; i < n; i++)
            {
                if (side1[i] <= 100 && side1[i] >= 0 && side2[i] <= 100 && side2[i] >= 0)
                {
                    glVertex2i(side1[i], side2[i]);
                }
                else if (side1[i] <= 100 && side1[i] >= 0 && side2[i] > 100 )
                {
                    glVertex2i(side1[i], 100);
                }
                else if (side1[i] <= 100 && side1[i] >= 0 && side2[i] < 0 )
                {
                    glVertex2i(side1[i], 0);
                }
                else if (side2[i] <= 100 && side2[i] >= 0 && side1[i] > 100 )
                {
                    glVertex2i(100, side2[i]);
                }
                else if (side2[i] <= 100 && side2[i] >= 0 && side1[i] < 0 )
                {
                    glVertex2i(0, side2[i]);
                }
                else if (side1[i] > 100 && side2[i] > 100)
                {
                    glVertex2i(100, 100);
                }
                else
                {
                    glVertex2i(0, 0);
                }
            }
        glEnd();
        glFlush();
    }
}


void keyboard(unsigned char key, int x, int y)
{
    (void)x; (void)y; 
    if (key == '1') {
        showClipped = 1;
        glutPostRedisplay(); 
    } else if (key == '2') {
        exit(0);
    }
}

int main(int argc, char** argv)
{
    getdata(); 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon Clipping");

    glClear(GL_COLOR_BUFFER_BIT);
    init();

    
    glutDisplayFunc(polygon1);

    
    glutKeyboardFunc(keyboard);

    printf("\nWindow opened with initial view.\n");
    printf("Now press '1' (in the window) to see the clipped (blue) view, or '2' to exit.\n");

    glutMainLoop();
    return 0;
}