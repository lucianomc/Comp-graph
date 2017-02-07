#include <GL/glut.h>
//Finished
void displayMe(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
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
void init(void){
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);    //Paints the background
    glClear(GL_COLOR_BUFFER_BIT);       //Enable background color
}

// void changeWindowSize( GLsizei w, GLsizei h){
//     if (h == 0) h = 1;

//     glViewport( 0, 0, w, h);

//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();

//     if (w <= h)
//         gluOrtho2D(.0f, 250.0f, .0f, 250.0f*h/w);
//     else
//         gluOrtho2D(.0f, 250.0f*w/h, .0f, 250.0f);
// }

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);   //Display mode
    glutCreateWindow("Flor de Abril");  //Create a window
    glutDisplayFunc(displayMe);         //Where everything is draw
    //glutReshapeFunc(changeWindowSize);
    init();
    glutMainLoop();
    return 0;
}
