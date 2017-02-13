#include <iostream>
#include <GL/glut.h>

using namespace std;

float   a = 0.0f;


void init(void)
{
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);    //Paints the background
}

void displayMe(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT); 
    glRotatef(a, 1, 0, 0);

    //Square model
	// glVertex3f(0.0, 0.0, 0.0);
	// glVertex3f(0.0, 0.1, 0.0);
	// glVertex3f(0.1, 0.1, 0.0);
	// glVertex3f(0.1, 0.0, 0.0);

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-0.7, 0.7, 0.0);
		glVertex3f(-0.7, 0.5, 0.0);
		glVertex3f(-0.6, 0.5, 0.0);
		glVertex3f(-0.6, 0.7, 0.0);       
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.55, 0.7, 0.0);
		glVertex3f(-0.45, 0.7, 0.0);
		glVertex3f(-0.45, 0.5, 0.0);
		glVertex3f(-0.55, 0.5, 0.0);       
    glEnd();

    glutPostRedisplay();
    glFlush();
}

void mouse (int button, int state, int x, int y)
{   
    if (button == GLUT_LEFT_BUTTON){
    	if(button == GLUT_DOWN){
           	a += 3;
        	cout << a << " + \n";
        	glutPostRedisplay();
        }
    } 
    else if(button == GLUT_RIGHT_BUTTON){
    	if(button == GLUT_DOWN){
           	a -= 3;
           	cout << a << " - ";
           	glutPostRedisplay();
        }	
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //Que tipo de exibição deve ser usado quando a janela é criada
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   //Display mode
    //posição da janela
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 400);
    //tamanho em pixels
    //Cria a janela
    glutCreateWindow("Hola");  //Create a window
    glutMouseFunc(mouse);
    
    init();

    glutDisplayFunc(displayMe);         //Where everything is draw
 
    glutMainLoop();
    return 0;
}
