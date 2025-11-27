#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float a[3][2], t[2][2], rmat[3][2];
float x00,y00,x01,y01,x02,y02;

void init() {
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300.0,300.0,-300.0,300.0);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x00,y00);
        glVertex2f(x01,y01);
        glVertex2f(x02,y02);
    glEnd();
    glFlush();
}

void mul() {
    int i,j,p;
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            rmat[i][j] = 0.0f;
            for(p=0;p<2;p++){
                rmat[i][j] += a[i][p] * t[p][j];
            }
        }
    }
    x00=rmat[0][0]; y00=rmat[0][1];
    x01=rmat[1][0]; y01=rmat[1][1];
    x02=rmat[2][0]; y02=rmat[2][1];
}

int main(int argc, char **argv) {
    int ch, ch1;
    float ang;
    int para;

  
    printf("Enter coordinates of the triangle (x1 y1): ");
    scanf("%f %f", &x00, &y00);
    printf("x2 y2: ");
    scanf("%f %f", &x01, &y01);
    printf("x3 y3: ");
    scanf("%f %f", &x02, &y02);

   
    a[0][0]=x00; a[0][1]=y00;
    a[1][0]=x01; a[1][1]=y01;
    a[2][0]=x02; a[2][1]=y02;

    
    printf("MENU\n1.Rotation\n2.Reflection\n3.Scaling\n4.Shearing (x-shear)\n5.Translation\nEnter choice: ");
    scanf("%d",&ch);

    switch(ch) {
        case 1:
            printf("Enter rotation degree: ");
            scanf("%f",&ang);
            {
                
                float d = ang * (3.14/180);
                t[0][0] = cosf(d); t[0][1] = -sinf(d);
                t[1][0] = sinf(d); t[1][1] = cosf(d);
            }
            mul();
            break;
        case 2:
            printf("Reflection about: 1.x-axis 2.y-axis : ");
            scanf("%d",&ch1);
            if(ch1==1){ t[0][0]=1; t[0][1]=0; t[1][0]=0; t[1][1]=-1; }
            else { t[0][0]=-1; t[0][1]=0; t[1][0]=0; t[1][1]=1; }
            mul();
            break;
        case 3:
            printf("Enter scaling factor (float): ");
            {
                float sf; scanf("%f",&sf);
                t[0][0]=sf; t[0][1]=0; t[1][0]=0; t[1][1]=sf;
            }
            mul();
            break;
        case 4:
            printf("Enter x-shear factor (float): ");
            {
                float sh; scanf("%f",&sh);
                t[0][0]=1; t[0][1]=sh; t[1][0]=0; t[1][1]=1;
            }
            mul();
            break;
        case 5:
            printf("Enter translation tx ty: ");
            {
                float tx, ty; scanf("%f %f", &tx, &ty);
               
                x00 += tx; y00 += ty;
                x01 += tx; y01 += ty;
                x02 += tx; y02 += ty;
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("2D Transformation - Result");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}