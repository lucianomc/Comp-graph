#include <GL/glut.h>
#include <math.h>

double x = -0.8, y = -0.5, dy = 0.01, dx = 0.75;

void init(void) {
  glClearColor(0,0,0,0);
  glMatrixMode(GL_PROJECTION);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_LINE_LOOP);
    glColor3d(1,0,0); // cor
    glVertex3f(x, y, 0);
    glVertex3f(x, y+1, 0);
    glVertex3f(x+1.6, y+1, 0);
    glVertex3f(x+1.6, y, 0);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex3f(0, y, 0);
    glVertex3f(0, -y, 0);
  glEnd();

  // garrafao lado direito
  glBegin(GL_LINE_LOOP);
    glVertex3f(0.6, 0.085, 0);
    glVertex3f(0.6, -0.085, 0);
    glVertex3f(0.8, -0.12, 0);
    glVertex3f(0.8, 0.12, 0);
  glEnd();

  // garrafao lado esquerdo
  glBegin(GL_LINE_LOOP);
    glVertex3f(-0.6, 0.085, 0);
    glVertex3f(-0.6, -0.085, 0);
    glVertex3f(-0.8, -0.12, 0);
    glVertex3f(-0.8, 0.12, 0);
  glEnd();

  glColor3d(1,0,0); // cor
  double angle = 0.0;
  int points = 360;
  double  PI = 3;

  for(int i =0; i < points;i++){
    glBegin(GL_POINTS);
      angle = PI * i / points;
      double angCircle = 2 * PI * i / points;

      glVertex2f((sin(angle)/3)-0.8,cos(angle)/3); // semi-circulo lado esquerdo
      glVertex2f((-sin(angle)/3)+0.8,cos(angle)/3); // semi-circulo lado esquerdo
      glVertex2f((sin(angCircle)/12),cos(angCircle)/12); // circulo central
      glVertex2f((sin(angCircle)/12)-0.6,cos(angCircle)/12); // circulo lado esquerdo
      glVertex2f((sin(angCircle)/12)+0.6,cos(angCircle)/12); // circulo lado direito
      glEnd();
    }

  glutSwapBuffers();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("basquete");
  init();

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}

