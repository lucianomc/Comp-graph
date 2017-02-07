#include <iostream>
#include <GL/glut.h>

using namespace std;

GLsizei w = 400, h = 400;

void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);    //Paints the background
    glClear(GL_COLOR_BUFFER_BIT);           //Enable background color
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 200.0, 0.0, 150.0, -1.0, 1.0);
}

void displayMe(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);

    //glMatrixMode(GL_PROJECTION);

    glLoadIdentity();  

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -0.7, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, -0.2, 0.0);
        glVertex3f(0.5, 0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.2, 0.5, 0.0);
        glVertex3f(-0.2, 0.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-0.5, 0.2, 0.0);
        glVertex3f(-0.5, -0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.5f, 1.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.2, -0.5, 0.0);
        glVertex3f(-0.2, -0.5, 0.0);
    glEnd();

    glFlush();
}

//Initiate parameters to rendering


void changeWindowSize( GLsizei w, GLsizei h){
    if (h == 0) h = 1;

    glViewport( 0, 0, w, h);

    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        gluOrtho2D(.0f, 250.0f, .0f, 250.0f*h/w);
    else
        gluOrtho2D(.0f, 250.0f*w/h, .0f, 250.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   //Display mode
    glutInitWindowPosition(350, 150);
    //glutInitWindowSize(300, 300);
    glutInitWindowSize(w, h);
    glutCreateWindow("Flor de Abril");  //Create a window

    init();

    glutDisplayFunc(displayMe);         //Where everything is draw
    glutReshapeFunc(changeWindowSize);
    //glutMouseFunc(mousePtPlot);

    glutMainLoop();
    return 0;
}
