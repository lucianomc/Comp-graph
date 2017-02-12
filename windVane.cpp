#include <iostream>
#include <GL/glut.h>

using namespace std;

GLsizei w = 400, h = 400;

int color = 0;

float   r = 0.0,
        g = 0.0,
        b = 0.0;

// GLfloat c1 = 0.03,
//         c2 = 0.05,
//         c3 = 0.07;

void mouse (int button, int state, int x, int y);

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
        glColor3f(r, g, b);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, -0.2, 0.0);
        glVertex3f(0.5, 0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.2, 0.5, 0.0);
        glVertex3f(-0.2, 0.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-0.5, 0.2, 0.0);
        glVertex3f(-0.5, -0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r, g, b);
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
        if (button == GLUT_LEFT_BUTTON){
            if(state == GLUT_DOWN){
                color++;
                switch(color){
                    case 1:
                        r = 0.0f;
                        g = 0.0f;
                        b = 0.0f;
                        glutPostRedisplay();
                        break;
                    case 2:
                        r = 0.0f;
                        g = 1.0f;
                        b = 0.0f;
                        glutPostRedisplay();
                        break;
                    case 3:
                        r = 0.0f;
                        g = 0.0f;
                        b = 1.0f;
                        glutPostRedisplay();
                        break;
                    case 4:
                        r = 1.0f;
                        g = 1.0f;
                        b = 1.0f;
                        glutPostRedisplay();
                        break;
                    default:
                        color = 0;
                        r = 0.0f;
                        g = 0.0f;
                        b = 0.0f;
                        glutPostRedisplay();
                        break;        
            }
        }
    }
        // glutPostRedisplay();
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
