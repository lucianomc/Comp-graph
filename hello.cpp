#include <GL/glut.h>
//teste
void displayMe(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f,0.0f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glFlush();
}

//Inicializa parâmetros de rendering
void init(void){
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glClearColor(.0f,1.0f,.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);//Habilita cor do fundo
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("Hello world :D");
    glutDisplayFunc(displayMe);
    init();
    glutMainLoop();
    return 0;
}
