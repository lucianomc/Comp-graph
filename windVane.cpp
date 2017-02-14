#include <iostream>
#include <GL/glut.h>

using namespace std;

GLsizei w = 400, h = 400;

float   r1 = 1.0,
        g1 = 0.0,
        b1 = 0.0;

float   r2 = 0.0,
        g2 = 1.0,
        b2 = 0.0;

float   r3 = 0.0,
        g3 = 0.0,
        b3 = 2.0;

float   r4 = 1.0,
        g4 = 1.0,
        b4 = 0.0;    

void changeColor(int color){
    float a1, a2, a3;
    switch(color){
            case 1:

                a1 = r4;
                a2 = g4;
                a3 = b4;

                r4 = r3;
                g4 = g3;
                b4 = b3;

                r3 = r2;
                g3 = g2;
                b3 = b2;

                r2 = r1;
                g2 = g1;
                b2 = b1;

                r1 = a1;
                g1 = a2;
                b1 = a3;

                glutPostRedisplay();
                break;
            case 2:
                a1 = r3;
                a2 = g3;
                a3 = b3;

                r3 = r2;
                g3 = g2;
                b3 = b2;

                r2 = r1;
                g2 = g1;
                b2 = b1;

                r1 = r4;
                g1 = g4;
                b1 = b4;

                r4 = a1;
                g4 = a2;
                b4 = a3;    

                glutPostRedisplay();
                break;
            case 3:
                a1 = r2;
                a2 = g2;
                a3 = b2;

                r2 = r1;
                g2 = g1;
                b2 = b1;

                r1 = r4;
                g1 = g4;
                b1 = b4;

                r4 = r3;
                g4 = g3;
                b4 = b3;

                r3= a1;
                g3 = a2;
                b3 = a3;

                glutPostRedisplay();
                break;
            default:
                color = 0;
                r1 = 1.0,
                g1 = 0.0,
                b1 = 0.0;

                r2 = 0.0,
                g2 = 1.0,
                b2 = 0.0;

                r3 = 0.0,
                g3 = 0.0,
                b3 = 2.0;

                r4 = 1.0,
                g4 = 1.0,
                b4 = 0.0; 
                glutPostRedisplay();
                break;        
        }
}

//parametros de redering
void init(void)
{
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);    //Paints the background
}

// call to draw
void displayMe(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT); 

    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r1, g1, b1);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, -0.2, 0.0);
        glVertex3f(0.5, 0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r2, g2, b2); 
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.2, 0.5, 0.0);
        glVertex3f(-0.2, 0.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r3, g3, b3);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-0.5, 0.2, 0.0);
        glVertex3f(-0.5, -0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r4, g4, b4); 
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.2, -0.5, 0.0);
        glVertex3f(-0.2, -0.5, 0.0);
    glEnd();

    glFlush();
}

//Initiate parameters to rendering

void changeWindowSize( GLsizei w, GLsizei h){
    if (h == 0) h = 1;
    //define a área dentro da janela
    glViewport( 0, 0, w, h);

    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        gluOrtho2D(.0f, 250.0f, .0f, 250.0f*h/w);
    else
        gluOrtho2D(.0f, 250.0f*w/h, .0f, 250.0f);
}

void mouse (int button, int state, int x, int y)
{   
    int color = 0;
    
    if (button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            color++;
            changeColor(color);
        }
    }
    else if(button == GLUT_RIGHT_BUTTON){
        if (state == GLUT_DOWN){
            color--;
            changeColor(color);
        }
    }


}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //Que tipo de exibição deve ser usado quando a janela é criada
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   //Display mode
    //posição da janela
    glutInitWindowPosition(350, 150);
    //glutInitWindowSize(300, 300);
    //tamanho em pixels
    glutInitWindowSize(w, h);
    //Cria a janela
    glutCreateWindow("Flor de Abril");  //Create a window
    glutMouseFunc(mouse);

    init();

    glutDisplayFunc(displayMe);         //Where everything is draw
    glutReshapeFunc(changeWindowSize);
    //glutMouseFunc(mousePtPlot);

    glutMainLoop();
    return 0;
}
