

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>

/* Global variables */
char title[] = "3D Shapes";

int abc = 1;
int porta = 0;
int t = 0, u = 0, v = 0;

double size = 0.5;

float 	zoom = 0;
float 	lx = 0, ly = 0, lz = 0, angle = 2 * 1.8, 
		up = 0, left = 0;


/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f); 
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);                  // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   	// Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    	// Set the type of depth-test
	glShadeModel(GL_SMOOTH);   	// Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void bancos(double x, double y, double z){
	glColor3f(1, 0, 0);
	glBegin(GL_QUAD_STRIP);			
		glVertex3f(x + 0.2,y,z + 0.1);			
		glVertex3f(x + 0.2,y,z + 0.7);
		glVertex3f(x + 0.5,y,z + 0.1);
		glVertex3f(x + 0.5,y,z + 0.7);

		glVertex3f(x + 0.5,y + 0.4,z + 0.1);			
		glVertex3f(x + 0.5,y + 0.4,z + 0.7);

		glVertex3f(x + 0.4,y + 0.4,z + 0.1);
		glVertex3f(x + 0.4,y + 0.4,z + 0.7);

		glVertex3f(x + 0.4,y + 0.1,z + 0.1);
		glVertex3f(x + 0.4,y + 0.1,z + 0.7);

		glVertex3f(x + 0.2,y + 0.1,z + 0.1);
		glVertex3f(x + 0.2,y + 0.1,z + 0.7);

		glVertex3f(x + 0.2,y,z + 0.1);
		glVertex3f(x + 0.2,y,z + 0.7);
	glEnd();

	glLineWidth(20);
	glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex3f(0.32,0,0.21);
		glVertex3f(0.32,0.1,0.21);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex3f(0.32,0,0.79);
		glVertex3f(0.32,0.1,0.79);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex3f(0.6,0,0.21);
		glVertex3f(0.52,0.1,0.21);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex3f(0.6,0,0.79);
		glVertex3f(0.52,0.1,0.79);
	glEnd();
	//glPopMatrix();
}

void cubo(double x, double y, double z) {

	glBegin(GL_QUADS);
		//glColor3f(1, 0.8, 0.2);

		//baixo
		//glColor3f(tam,0,tam);     // up face
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, z);
		glVertex3f(x, 0, z);
		glVertex3f(x, 0, 0);

		//cima
		glVertex3f(0, y, 0);
		glVertex3f(0, y, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, 0);

		//atras
		// glVertex3f(0, 0, 0);
		// glVertex3f(x, 0, 0);
		// glVertex3f(x, y, 0);
		// glVertex3f(0, y, 0);

		//frente
		// glVertex3f( 0, 0, z);
		// glVertex3f( x, 0, z);
		// glVertex3f( x, y, z);
		// glVertex3f( 0, y, z);

		//esq
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, z);
		glVertex3f(0, y, z);
		glVertex3f(0, y, 0);

		//dir
		glVertex3f(x, 0, 0);
		glVertex3f(x, 0, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, 0);

	glEnd();
/*
	// coloca uma linha pra destacar junçao das paredes
	glColor3f(0, 0, 0);
	glScaled(x, y, z);
	glTranslated(0.5,0.5,0.5);
	glutWireCube(1);
	glTranslated(-0.5,-0.5,-0.5);
	glScaled(1 / x, 1 / y, 1 / z);
*/
	// frente com porta
//	glBegin(GL_QUADS);
//	glVertex3f( 0, 0, z);
//	glVertex3f( x/3., 0, z);
//	glVertex3f( x/3., y, z);
//	glVertex3f( 0, y, z);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glVertex3f( x/3., y/3., z);
//	glVertex3f( 2*x/3., y/3., z);
//	glVertex3f( 2*x/3., y, z);
//	glVertex3f( x/3., y, z);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glVertex3f( x/1.5, 0, z);
//	glVertex3f( x, 0, z);
//	glVertex3f( x, y, z);
//	glVertex3f( x/1.5, y, z);
//	glEnd();

}

void plataforma(double x, double y, double z) {

	glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		// up face
		glVertex3f(0, y, 0);
		glVertex3f(x, y, 0);
		glVertex3f(x, y, z);
		glVertex3f(0, y, z);

		// Bottom face
		glVertex3f(x, 0, z);
		glVertex3f(0, 0, z);
		glVertex3f(0, 0, 0);
		glVertex3f(x, 0, 0);
	glEnd();

	//Pilares
	glColor3f(1, 1, 1);
	glTranslated(0.45, 0, 0);
	int i;
	for (i = 0; i < 6; i++) {
		cubo(0.1, 1, 0.1);
		glTranslated(0, 0, 1);
	}
	glTranslated(-0.45, 0, -6);

	glutPostRedisplay();
}

void plano(double x1, double y1, double z1, double x2, double y2, double z2) {
	glBegin(GL_QUADS);
		//glColor3f(1, 0.9, 0.2);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y1, z2);
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glEnd();

	// glColor3f(0,0,0);
	// glBegin(GL_LINE_LOOP);
	// glVertex3f(x1,y1,z1);
	// glVertex3f(x2,y1,z1);
	// glVertex3f(x2,y1,z2);
	// glVertex3f(x1,y1,z2);
	// glEnd();

}

void escada(){

	//escada da parte inferior
	for (int i = 0; i < 5; i++) {
		cubo(0.25, 0.1, 0.1);
		glTranslatef(0, 0.1, 0.1);
	}
	plano(0, 0, 0, 0.5, 0.1, 0.5); // subpiso inferior da escada
	plano(0, 0.5, 0, 0.5, 1, 0.5); // subpiso superior da escada
	glTranslatef(0.25, 0, 0);

	//escada da parte superior
	for (int i = 0; i < 5; i++) {
		cubo(0.25, 0.1, 0.1);
		glTranslatef(0, 0.1, -0.1);
	}

	// ultimo degrau
	glTranslatef(0, -0.1, 0);
	cubo(0.25, 0.1, 0.1);

	//retorno da tranlaçao
	glTranslatef(-0.25, -0.9, 0);

} // end escada

void trilho(){
	int i = 0;

	glColor3f(0.75,0.3,0.1);
	glTranslated(1.3,0,0);

	for (i = 0; i < 12; i++) {
		cubo(0.4, 0.05, 0.05);
		glTranslated(0, 0, 0.5);
	}

	glTranslated(0.05, 0.05, 0);
	glColor3f(0.1,0.1,0.1);
	cubo(0.02, 0.02, -8);

	glTranslated(0.3, 0, 0);
	cubo(0.02, 0.02, -8);

	glTranslated(-1.65, -0.05, -6);
	glColor3f(1, 0.8, 0.2);
}

void extintor(double x, double y, double z){
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(-90, 1, 0 ,0);
		glLineWidth(4);
		glBegin(GL_LINES);
			glColor3f(0,0,1);
			glVertex3f(-0.055, 0 ,0.05);
			glVertex3f(-0.055, 0, 0.3);
		glEnd();
		glColor3f(1, 0, 0);
		GLUquadricObj *obj = gluNewQuadric();
		gluCylinder(obj, 0.05f, 0.05f, 0.3f, 32, 32);
	glPopMatrix();
}

void catraca (double x, double y, double z){
		glPushMatrix();
		glTranslatef(x, y, z);
		glColor3f(0.5,0.8,0.8);
		glTranslated(0.6,0,6.5);
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.2,0.1,0.1);			
			glVertex3f(0.2,0.1,0.5);
			glVertex3f(0.3,0.1,0.1);
			glVertex3f(0.3,0.1,0.5);

			glVertex3f(0.3,0.4,0.1);			
			glVertex3f(0.3,0.4,0.5);

			glVertex3f(0.2,0.4,0.1);			
			glVertex3f(0.2,0.4,0.5);

			glVertex3f(0.2,0.1,0.1);			
			glVertex3f(0.2,0.1,0.5);
		glEnd();

		//palhetas da catraca
		glLineWidth(3);
		glBegin(GL_LINES);
			glVertex3f(0.0,0.35,0.4);			
			glVertex3f(0.2,0.35,0.4);

			glVertex3f(0.0,0.15,0.4);			
			glVertex3f(0.2,0.35,0.4);

			glVertex3f(0.0,0.25,0.2);			
			glVertex3f(0.2,0.35,0.4);
		glEnd();

		//protecao da catraca
		glLineWidth(5);
		glBegin(GL_LINE_STRIP);
			glVertex3f(-0.04, 0.0, 0.2);			
			glVertex3f(-0.04, 0.4, 0.2);
			glVertex3f( -0.5, 0.4, 0.2);
			glVertex3f( -0.5, 0.0, 0.2);

			glVertex3f(-0.5, 0.1, 0.2);
			glVertex3f(-0.04, 0.1, 0.2);

			glVertex3f(-0.5, 0.3, 0.2);
			glVertex3f(-0.03, 0.3, 0.2);
		glEnd();
	glPopMatrix();
}

void placa (double x, double y, double z){
	
	glPushMatrix();		
		glTranslatef(x, y, z);
		glBegin(GL_QUADS);
			glColor3f(0, 0, 0.2);
			glVertex3f(-0.045, 0, 0);
			glVertex3f(-0.045, 0.09, 0);
			glVertex3f( 0.15, 0.09, 0);
			glVertex3f( 0.15, 0, 0);
		glEnd();
	glPopMatrix();
}

void lixeiros(double x, double y, double z){
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(-90, 1, 0 ,0);	
		glColor3f(0,1,0);
		GLUquadricObj *lix1 = gluNewQuadric();
			gluCylinder(lix1, 0.08f, 0.1f, 0.3f, 32, 32);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.22, y, z);
		glRotatef(-90, 1, 0 ,0);	
		glColor3f(0,0,1);
		GLUquadricObj *lix2 = gluNewQuadric();
			gluCylinder(lix2, 0.08f, 0.1f, 0.3f, 32, 32);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.44, y, z);
		glRotatef(-90, 1, 0 ,0);	
		glColor3f(1,0,0);
		GLUquadricObj *lix3 = gluNewQuadric();
			gluCylinder(lix3, 0.08f, 0.1f, 0.3f, 32, 32);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 0.66, y, z);
		glRotatef(-90, 1, 0 ,0);	
		glColor3f(1,1,0);
		GLUquadricObj *lix4 = gluNewQuadric();
			gluCylinder(lix4, 0.08f, 0.1f, 0.3f, 32, 32);
	glPopMatrix();

}

/* Handler for window-repaint event. Called back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

	// Render a color-cube consisting of 6 quads with different colors
	glLoadIdentity();                 // Reset the model-view matrix
	gluLookAt(left, 1, zoom + 8, left, 0, zoom, 0, 1, 0);

	glRotatef(angle, t, u, v);
	glTranslatef(0, up, 0);

	glBegin(GL_QUADS);	// Begin drawing the color cube with 6 quads
						// Top face (y = 1.0f)
						// Define vertices in counter-clockwise (CCW) order with normal pointing out
		glColor3f(0.0, 0.6, 0.0); //grama na entrada
		glVertex3f( 8 * size, -size + 0.45,  4 * size);
		glVertex3f(-8 * size, -size + 0.45,  4 * size);
		glVertex3f(-8 * size, -size + 0.45, -4 * size);
		glVertex3f( 8 * size, -size + 0.45, -4 * size);

		glColor3f(0.8f, 0.8, 0.8f); //brita no final
		glVertex3f(-4 * size, -size + 0.45, -4 * size);
		glVertex3f( 4 * size, -size + 0.45, -4 * size);
		glVertex3f( 4 * size, -size + 0.45, -5 * 4 * size);
		glVertex3f(-4 * size, -size + 0.45, -5 * 4 * size);
	glEnd();  // fim do chao

//============================================
	/* fachada de 2 andares */

	glColor3f(1, 0.8, 0.2);
	// fachada 2 andares
	glTranslated(-1.5, 0, 0);
	cubo(3, 2, 1);

	plano(0.5, 1, 0, 3, 5, 1); // 2 andar

	glPushMatrix();
		glColor3f(0.8, 1, 1);
		escada();
	glPopMatrix();

	//fachada com porta
	glColor3f(1, 0.8, 0.2);

	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 1, -2);

	plano(-1, 0, 1, 1.25, 0, 2); //fachada esquerda
	glTranslatef(1.25, 0, 0);
	plano(0, 0, 1, 0.5, 4, 1.5); //acima da porta

	plano(-1.25, 0, 0, 1.75, 0, 1); //fachada acima da porta

	glTranslatef(0.5, 0, 0);
	plano(0, 0, 1, 2.25, 0, 2); //fachada direita

	glTranslatef(-1.75,-1,2); 	// voltando a posiçao normal

	/* parte de tras com 2 portas */
	// primeiro andar
	glTranslatef(0,-1,-2);
	plano(0,1,0,3,2,1);
	glColor3f(0, 0.8, 0.2);
	glTranslatef(0,1,1);
	plano(0,0,0,0.75,0,1);//dir

	glTranslatef(0.75,0,0);
	plano(0,0,0,0.5,0,0.5);// 1 porta

	glTranslatef(0.5,0,0);
	plano(0,0,0,0.5,0,1);//entre portas

	glTranslatef(0.5,0,0);
	plano(0,0,0,0.5,0,0.5);// 2 porta

	glTranslatef(0.5,0,0);
	plano(0,0,0,0.75,0,1);//dir

	glTranslatef(-2.25,0,1);
	glRotatef(-90,1,0,0);

  // glColor3f(0,0,0);
  // glScaled(1.5,1,0.5);
  // glTranslatef(1,1,1);
  // glutWireCube(2);
  // glScaled(1/1.5,1,2);
  // glTranslatef(-1,-1,0);

	glColor3f(1, 0.8, 0.2);

	// salao interior
	glTranslated(-1, 0, -1);
	glColor3f(.5, 0.5, 0.5);
	cubo(5, 1, 2);

	// plataformas
	glTranslated(0, 0, -6);
	plataforma(1, 1, 6);

	bancos(0.1, 0.1, 0.1);

	extintor(0.4, 0.4, 5.05);

	catraca (4, 0, 0);

	catraca (0, 0, 0);

	placa (4.6, 0.7, 5);

	lixeiros(2.83, 0, 6);

	trilho();
		glTranslated(2, 0, 0);
		plataforma(1, 1, 6);
	trilho();
		glTranslated(2, 0, 0);
		plataforma(1, 1, 6);

	//porta
	glColor3f(0.5,0.3,0.0);
	glRotatef(90,1,0,0);
	glTranslatef(-1.75,8,-2);
	glRotatef(porta, 0, 0, 1);
	plano(0,0,1.5,0.25,0,2);
	glRotatef(-porta, 0, 0, 1);

	glTranslatef(0.5,0,0);
	glRotatef(180-porta, 0, 0, 1);
	plano(0.25,0,1.5,0,0,2);
	glRotatef(-porta, 0, 0, 1);

	glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
}
void GerenciaMouse(int button, int state, int x, int y) {
	//cout << "mouse" << endl;

	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			abc += 5;
			//glutIdleFunc(spinDisplay);
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			abc -= 5;
		}
	glutPostRedisplay();
}

/* Handler for window re-size event. Called back when the window first appears and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) { // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0)
		height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat) width / (GLfloat) height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);

}

void keyboard(unsigned char key, int a, int c) {
	float fraction = 0.1f;

	switch (key) {
	case 'w':
		zoom -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		zoom += 0.5;
		glutPostRedisplay();
		break;
	// case 'a':
	// 	//left +=1;
	// 	angle -= 0.2f;
	// 	lx = sin(angle);
	// 	lz = -cos(angle);
	// 	glutPostRedisplay();
	// 	break;
	// case 'd':
	// 	//left -=1;
	// 	angle += 0.2f;
	// 	lx = sin(angle);
	// 	lz = -cos(angle);
	// 	glutPostRedisplay();
	// 	break;
	case 'z':
		up += 0.5;
		glutPostRedisplay();
		break;
	case 'x':
		up -= 0.5;
		glutPostRedisplay();
		break;
	case 'a':
		// angle+=15;
		// if(angle >= 360)
		// 	angle = 0;
		// u=1;
		left -= 0.25;
		glutPostRedisplay();
		break;
	case 'd':
		// angle-=15;
		// if(angle <= 0)
		// 	angle = 360;
		// u=1;
		left += 0.25;
		glutPostRedisplay();
		break;

	case 'u':
		angle += 7.5;
		if (angle >= 360)
			angle = 0;
		u = 1;
		glutPostRedisplay();
		break;

	case 'i':
		angle -= 7.5;
		if (angle <= 0)
			angle = 360;
		u = 1;
		glutPostRedisplay();
		break;

	case 'p': //Open main door
		if(porta >= 0 && porta < 150){
			porta += 10;
		}
		glutPostRedisplay();
		break;

	case 'o': //Close main door
		if(porta > 0 && porta <=150){
			porta -= 10;
		}
		glutPostRedisplay();
		break;

	case 27:
		exit(8);
		break;
	default:
		break;
	}
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            	// Initialize GLUT
	//glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   	// Set the window's initial width & height
	glutInitWindowPosition(50, 50); 	// Position the window's initial top-left corner
	glutCreateWindow(title);         	 // Create window with the given title

	glutDisplayFunc(display); 	// Register callback handler for window re-paint event
	glutReshapeFunc(reshape); 	// Register callback handler for window re-size event
	//glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(keyboard);

	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}

