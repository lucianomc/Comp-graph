#include <GL/glut.h>
#include <math.h>

GLfloat angle, fAspect;

void init(void) {
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
  angle=0;
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0f, 0.0f, 1.0f);

  glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(0, 0);
    glVertex2i(10, 10);
    //glVertex2i(10, 30);
  glEnd();

  // Desenha o teapot com a cor corrente (wire-frame)
  glutWireCube(50.0f);

  // Executa os comandos OpenGL
  glutSwapBuffers();
}

void EspecificaParametrosVisualizacao(void)
{
  // Especifica sistema de coordenadas de projeção
  glMatrixMode(GL_PROJECTION);
  // Inicializa sistema de coordenadas de projeção
  glLoadIdentity();

  // Especifica a projeção perspectiva
  gluPerspective(angle,fAspect,0.1,500);

  // Especifica sistema de coordenadas do modelo
  glMatrixMode(GL_MODELVIEW);
  // Inicializa sistema de coordenadas do modelo
  glLoadIdentity();

  // Especifica posição do observador e do alvo
  gluLookAt(0, 80, 200, //posicao da camera
            0, 0, 0,    //para onde olhar
            0, 1, 0);   //lado de cima da cena
}

void GerenciaMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {  // Zoom-in
      if (angle >= 10) angle -= 5;
    }
  if (button == GLUT_RIGHT_BUTTON)
    if (state == GLUT_DOWN) {  // Zoom-out
      if (angle <= 130) angle += 5;
    }
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
  // Para previnir uma divisão por zero
  if ( h == 0 ) h = 1;

  // Especifica o tamanho da viewport
  glViewport(0, 0, w, h);
 
  // Calcula a correção de aspecto
  fAspect = (GLfloat)w/(GLfloat)h;

  EspecificaParametrosVisualizacao();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(100,50);
  glutInitWindowSize(800,600);
  glutCreateWindow("cbtu");
  glutReshapeFunc(AlteraTamanhoJanela);
  glutMouseFunc(GerenciaMouse);

  init();

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}

