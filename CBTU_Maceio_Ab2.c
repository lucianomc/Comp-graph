#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>
#include "SOIL.h"

char title[] = "3D Shapes";

int abc = 1;
int porta = 0;
int t = 0, u = 0, v = 0;

double size = 0.5;

float 	zoom = 0;
float 	lx = 0, ly = 0, lz = 0, angle = 2 * 1.8,
		up = 0, left = 0,
		solx = 0, soly = 0,
		solr = 1, solg = 1, solb = 0.2,
		skyG = 0.8, skyB = 0.8 ;

GLuint texture_id[2];
GLfloat textPosix[4][2]={ {0,0}, {-1,0}, {-1,-1}, {0,-1} };
GLfloat rep[4][2]={ {-1,-2},{1,-2},{1,2},{-1,2} };

/* Initialize OpenGL Graphics */
void initGL() {

	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   		// "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};	// "brilho"
	GLfloat posicaoLuz[4]={0, 50, 50, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

	glShadeModel(GL_SMOOTH);   	// Enable smooth shading
	// Define a refletância do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS, especMaterial);

	//glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	// glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	// glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	// glDisable(GL_LIGHTING);
	// glDisable(GL_LIGHT0);

	glClearColor(0, skyG, skyB, 1); // Set background color
	glClearDepth(1.0f);

	glEnable(GL_DEPTH_TEST);   	// Enable depth testing for z-culling
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections

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

void cubo(double x, double y, double z, double b ) {

	glBegin(GL_QUADS);

	if(b==3){
		//baixo
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, z);
		glVertex3f(x, 0, z);
		glVertex3f(x, 0, 0);

		//cima
		glVertex3f(0, y, 0);
		glVertex3f(0, y, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, 0);
	}

		if(b == 0 || b==3){
		//atras
		 glVertex3f(0, 0, 0);
		 glVertex3f(x, 0, 0);
		 glVertex3f(x, y, 0);
		 glVertex3f(0, y, 0);

		//frente
		 glVertex3f( 0, 0, z);
		 glVertex3f( x, 0, z);
		 glVertex3f( x, y, z);
		 glVertex3f( 0, y, z);
		}

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
}

void plataforma(double x, double y, double z) {
	glColor3f(1, 1, 1);

	// textura telhado
	glEnable(GL_TEXTURE_2D);
	glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
	glBegin(GL_QUADS);
		glTexCoord2fv(rep[0]); glVertex3f(x-1, y, z-6);
		glTexCoord2fv(rep[1]); glVertex3f(x, y, z-6);
		glTexCoord2fv(rep[2]); glVertex3f(x, y, z+1);
		glTexCoord2fv(rep[3]); glVertex3f(x-1, y, z+1);
	glEnd();

	//textura piso
	glBindTexture ( GL_TEXTURE_2D, texture_id[8] );
	glBegin(GL_QUADS);
		glTexCoord2fv(rep[0]); glVertex3f(x-1, 0, z-6);
		glTexCoord2fv(rep[1]); glVertex3f(x, 0, z-6);
		glTexCoord2fv(rep[2]); glVertex3f(x, 0, z);
		glTexCoord2fv(rep[3]); glVertex3f(x-1, 0, z);
	glEnd();


	//placas saida
	for (int i = 0; i < 6; i++) {
		glBindTexture ( GL_TEXTURE_2D, texture_id[10] );
		glBegin(GL_QUADS);
			glTexCoord2fv(textPosix[0]);  glVertex3f(0.44,.7,0.0+i);
			glTexCoord2fv(textPosix[1]);  glVertex3f(0.44,.7,0.1+i);
			glTexCoord2fv(textPosix[2]);  glVertex3f(0.44,.75,0.1+i);
			glTexCoord2fv(textPosix[3]);  glVertex3f(0.44,.75,0.0+i);
		glEnd();


		glBindTexture ( GL_TEXTURE_2D, texture_id[10] );
		glBegin(GL_QUADS);
			glTexCoord2fv(textPosix[0]);  glVertex3f(0.56,.7,0.0+i);
			glTexCoord2fv(textPosix[1]);  glVertex3f(0.56,.7,0.1+i);
			glTexCoord2fv(textPosix[2]);  glVertex3f(0.56,.75,0.1+i);
			glTexCoord2fv(textPosix[3]);  glVertex3f(0.56,.75,0.0+i);
		glEnd();
	}




	glDisable(GL_TEXTURE_2D);





	//Pilares
	glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslated(0.45, 0, 0);
		int i;
		for (i = 0; i < 6; i++) {
			cubo(0.1, 1, 0.1, 0);
			glTranslated(0, 0, 1);
		}

		glTranslated(-0.45, 0, -6);
	glPopMatrix();
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
}

void escada(){

	//escada da parte inferior
	for (int i = 0; i < 5; i++) {
		cubo(0.25, 0.1, 0.1,3);
		glTranslatef(0, 0.1, 0.1);
	}
	plano(0, 0, 0, 0.5, 0.1, 0.5); // subpiso inferior da escada
	glTranslatef(0.25, 0, 0);

	//escada da parte superior
	for (int i = 0; i < 5; i++) {
		cubo(0.25, 0.1, 0.1, 3);
		glTranslatef(0, 0.1, -0.1);
	}

	// ultimo degrau
	glTranslatef(0, -0.1, 0);
	cubo(0.25, 0.1, 0.1, 0);

	//retorno da tranlaçao
	glTranslatef(-0.25, -0.9, 0);

} // end escada

void trilho(){
	int i = 0;

	glColor3f(0.75,0.3,0.1);
	glTranslated(1.3,0,0);

	for (i = 0; i < 12; i++) {
		cubo(0.4, 0.05, 0.05, 3);
		glTranslated(0, 0, 0.5);
	}

	glTranslated(0.05, 0.05, 0);
	glColor3f(0.1,0.1,0.1);
	cubo(0.02, 0.02, -8, 3);

	glTranslated(0.3, 0, 0);
	cubo(0.02, 0.02, -8, 3);

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

void janela(double x0, double y, double z, int vezes){//0.25,1.25,1.0

	for(int i = 0; i < vezes ; i++){
		double x = x0+(i*0.25);
	glBegin(GL_QUADS);
		glTexCoord2fv(textPosix[0]); glVertex3f(x, y, z+0.01);
		glTexCoord2fv(textPosix[1]); glVertex3f(x + 0.25, y, z+0.01);
		glTexCoord2fv(textPosix[2]); glVertex3f(x + 0.25, y+0.5, z+0.01);
		glTexCoord2fv(textPosix[3]); glVertex3f(x, y+0.5, z+0.01);
	glEnd();

	}

}

void lamp(double x, double y, double z){

    glPushMatrix();
        glTranslated(x, y, z);
        glBegin(GL_QUAD_STRIP);
            glVertex3f(0, 0.5, 0.2);
            glVertex3f(0, 0.5, 0.8);
            glVertex3f(0.2, 0.5, 0.2);
            glVertex3f(0.2, 0.5, 0.8);
        glEnd();
    glPopMatrix();
}

/* Handler for window-repaint event. Called back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	glClearColor(0, skyG, skyB, 1); // Set background color

	// Render a color-cube consisting of 6 quads with different colors
	glLoadIdentity(); // Reset the model-view matrix
	gluLookAt(left, 1, zoom + 11, left, 0, zoom, 0, 1, 0);
	glRotatef(angle, t, u, v);
	glTranslatef(0, up-3, 0);

	glEnable(GL_TEXTURE_2D);

	glBindTexture ( GL_TEXTURE_2D, texture_id[5] );
	glBegin(GL_QUADS);//grama na entrada
		glColor3f(0.0, 1, 0.0);
		glTexCoord2fv(rep[0]); glVertex3f( 4, -0.02,  3);
		glTexCoord2fv(rep[1]);glVertex3f(-4, -0.02,  3);
		glTexCoord2fv(rep[2]);glVertex3f(-4, -0.02, -1);
		glTexCoord2fv(rep[3]);glVertex3f( 4, -0.02, -1);
		glEnd();  // fim do chao

	glBindTexture ( GL_TEXTURE_2D, texture_id[6] );
	glBegin(GL_QUADS);//brita no final
		glColor3f(1, 1, 1);
		glTexCoord2fv(rep[0]); glVertex3f(-4, -0.02, -1);
		glTexCoord2fv(rep[1]); glVertex3f( 4, -0.02, -1);
		glTexCoord2fv(rep[2]); glVertex3f( 4, -0.02, -9);
		glTexCoord2fv(rep[3]); glVertex3f(-4, -0.02, -9);
	glEnd();  // fim do chao

	glBindTexture ( GL_TEXTURE_2D, texture_id[9] );
	glBegin(GL_QUADS); //caminho da porta
		glTexCoord2fv(rep[0]); glVertex3f(-0.3, -0.019, 1);
		glTexCoord2fv(rep[1]); glVertex3f( 0.3, -0.019, 1);
		glTexCoord2fv(rep[2]); glVertex3f( 0.3, -0.019, 3);
		glTexCoord2fv(rep[3]); glVertex3f(-0.3, -0.019, 3);
	glEnd();  // fim do chao

	glDisable(GL_TEXTURE_2D);

	glColor3f(1, 0.8, 0.2);
	glTranslated(-1.5, 0, 0);
	cubo(3, 2, 1,-1);

	glEnable(GL_TEXTURE_2D);

		glBindTexture ( GL_TEXTURE_2D, texture_id[7] );

		janela(0.25,1.25,1,3); //1 andar esquerda
		janela(1.25,1.25,1,2); //1 andar meio
		janela(2,1.25,1,3); //1 andar direita

		janela(-0.75,0.1,1,2); //terreo esquerda
		janela(0.25,0.1,1,3); //terreo esquerda-meio
		janela(2,0.1,1,3); //terreo direita-meio
		janela(3.25,0.1,1,2); //terreo direita

		glColor3f(1,1,1);
		glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
		glBegin(GL_QUADS); // piso terreo parte dentro
			glTexCoord2fv(rep[0]); glVertex3f(-1, 0, 1);
			glTexCoord2fv(rep[1]); glVertex3f(4,0,1);
			glTexCoord2fv(rep[2]); glVertex3f(4,0,0);
			glTexCoord2fv(rep[3]); glVertex3f(-1,0,0);
		glEnd();

		glBegin(GL_QUADS); // piso 1 andar parte dentro
			glTexCoord2fv(rep[0]); glVertex3f(0.5, 1, 1);
			glTexCoord2fv(rep[1]); glVertex3f(3,1,1);
			glTexCoord2fv(rep[2]); glVertex3f(3,1,0);
			glTexCoord2fv(rep[3]); glVertex3f(0.5,1,0);
		glEnd();

		glBegin(GL_QUADS); // piso 1 andar parte dentro escada
			glTexCoord2fv(rep[0]); glVertex3f(0.5, 1, 0.5);
			glTexCoord2fv(rep[1]); glVertex3f(0,1,0.5);
			glTexCoord2fv(rep[2]); glVertex3f(0,1,1);
			glTexCoord2fv(rep[3]); glVertex3f(0.5,1,1);
		glEnd();

		glBindTexture ( GL_TEXTURE_2D, texture_id[8] );
		glBegin(GL_QUADS); // piso terreo parte plataforma
			glTexCoord2fv(rep[0]); glVertex3f(-1, 0, 0);
			glTexCoord2fv(rep[1]); glVertex3f(-1,0,-1);
			glTexCoord2fv(rep[2]); glVertex3f(4,0,-1);
			glTexCoord2fv(rep[3]); glVertex3f(4,0,0);
		glEnd();

		glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
		glBegin(GL_QUADS); // teto 1 andar
					glTexCoord2fv(rep[0]); glVertex3f(3, 2, 0);
					glTexCoord2fv(rep[1]); glVertex3f(0,2,0);
					glTexCoord2fv(rep[2]); glVertex3f(0,2,1);
					glTexCoord2fv(rep[3]); glVertex3f(3,2,1);
				glEnd();

		glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
		glBegin(GL_QUADS); // teto 1 andar parte meio
			glTexCoord2fv(rep[0]); glVertex3f(4, 1,-1);
			glTexCoord2fv(rep[1]); glVertex3f(-1,1,-1);
			glTexCoord2fv(rep[2]); glVertex3f(-1,1,0);
			glTexCoord2fv(rep[3]); glVertex3f(4,1,0);
		glEnd();

		glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
		glBegin(GL_QUADS); // teto 1 andar parte esquerda
			glTexCoord2fv(rep[0]); glVertex3f(0, 1,1);
			glTexCoord2fv(rep[1]); glVertex3f(-1,1,1);
			glTexCoord2fv(rep[2]); glVertex3f(-1,1,0);
			glTexCoord2fv(rep[3]); glVertex3f(0,1,0);
		glEnd();

		glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
		glBegin(GL_QUADS); // teto 1 andar parte direita
			glTexCoord2fv(rep[0]); glVertex3f(3, 1,1);
			glTexCoord2fv(rep[1]); glVertex3f(4,1,1);
			glTexCoord2fv(rep[2]); glVertex3f(4,1,0);
			glTexCoord2fv(rep[3]); glVertex3f(3,1,0);
		glEnd();

	glDisable(GL_TEXTURE_2D);

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
	plano(0,0,0,0.5,0,1);//entre portas atrás

	glTranslatef(0.5,0,0);
	plano(0,0,0,0.5,0,0.5);// 2 porta

	glTranslatef(0.5,0,0);
	plano(0,0,0,0.75,0,1);//dir

	glTranslatef(-2.25,0,1);
	glRotatef(-90,1,0,0);

	glColor3f(1, 0.8, 0.2);
	// salao interior
	glTranslated(-1, 0, -1);
	glColor3f(.5, 0.5, 0.5);
	cubo(5, 1, 2, -1);

	// plataformas
	glTranslated(0, 0, -6);

	glPushMatrix();
		plataforma(1, 1, 6);
		trilho();
			glTranslated(2, 0, 0);
		plataforma(1, 1, 6);
		trilho();
			glTranslated(2, 0, 0);
		plataforma(1, 1, 6);
	glPopMatrix();

	bancos(0.1, 0.1, 0.1);

	extintor(0.4, 0.4, 5.05);

	catraca (4, 0, 0);

	catraca (0, 0, 0);

	placa (4.6, 0.7, 5);

    lamp(0.435, 0.48, 0);
    lamp(0.435, 0.48, 1);
    lamp(0.435, 0.48, 2);
    lamp(0.435, 0.48, 3);
    lamp(0.435, 0.48, 4);

	lixeiros(2.83, 0, 6);

	glTranslated(4,0,0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture ( GL_TEXTURE_2D, texture_id[4] );
		glColor3f(0.5,0.3,0.0);
		glRotatef(90,1,0,0);
		glTranslatef(-1.75,8,-2);
		glRotatef(porta, 0, 0, 1);

		glBegin(GL_QUADS);
			glTexCoord2fv(textPosix[0]);  glVertex3f(0,0,2);
			glTexCoord2fv(textPosix[1]);  glVertex3f(.25,0,2);
			glTexCoord2fv(textPosix[2]);  glVertex3f(.25,0,1.5);
			glTexCoord2fv(textPosix[3]);  glVertex3f(0,0,1.5);
		glEnd();

			glRotatef(-porta, 0, 0, 1);
			glTranslatef(0.5,0,0);
			glRotatef(180-porta, 0, 0, 1);

		glBegin(GL_QUADS);
			glTexCoord2fv(textPosix[0]);  glVertex3f(0,0,2);
			glTexCoord2fv(textPosix[1]);  glVertex3f(.25,0,2);
			glTexCoord2fv(textPosix[2]);  glVertex3f(.25,0,1.5);
			glTexCoord2fv(textPosix[3]);  glVertex3f(0,0,1.5);
		glEnd();

	glDisable(GL_TEXTURE_2D);
	//glBindTexture ( GL_TEXTURE_2D, 0 );

	glRotatef(porta, 0, 0, 1);

	//sol
	glRotatef(solx,0,soly,1);
	glColor3f(solr,solg,solb);
	glTranslated(0,6,-5);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
		glBindTexture (GL_TEXTURE_2D, texture_id[0] );
		glPushMatrix();
			glutSolidSphere(1,40,30);
		glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glBindTexture ( GL_TEXTURE_2D, 0 );

	glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
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
	case 'z':
		up += 0.5;
		glutPostRedisplay();
		break;
	case 'x':
		up -= 0.5;
		glutPostRedisplay();
		break;
	case 'a':
		left -= 0.25;
		glutPostRedisplay();
		break;
	case 'd':
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

	case 'l':
		solx+= 10;
		soly+= 10;

		//dia para noite
		if(soly==130){
			soly=230;
			solx=230;
			solr = 0.9;
			solg = 0.9;
			solb = 0.9;
			skyG = 0.1, skyB = 0.2;
		}
		//noite para dia
		else if(soly==490){
			soly=590;
			solx=590;
			solr = 1;
			solg = 1;
			solb = 0;
			skyG = 0.8, skyB = 0.8;
		}
		else if(soly>=720){
			soly=0;
			solx=0;
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

void loadTextureFromFile(char *filename,int index)
{

    int width, height;
  unsigned char* image =
      SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

            //printf("%d %d\n", width, height);

  glGenTextures(1, &texture_id[index]);
  glBindTexture(GL_TEXTURE_2D, texture_id[index]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

  glBindTexture(GL_TEXTURE_2D, 0);
}

void textures(){
    // Habilitar o uso de texturas

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    loadTextureFromFile("/home/familia1/Imagens/escada.jpg", 0);
    loadTextureFromFile("/home/familia1/Imagens/piso.jpg", 1);
    loadTextureFromFile("/home/familia1/Imagens/calib.jpg", 2);
    loadTextureFromFile("/home/familia1/Imagens/telhado.jpg", 3);
    loadTextureFromFile("/home/familia1/Imagens/porta.jpg", 4);
    loadTextureFromFile("/home/familia1/Imagens/grama.jpg", 5);
    loadTextureFromFile("/home/familia1/Imagens/brita.jpg", 6);
    loadTextureFromFile("/home/familia1/Imagens/janela.jpg", 7);
    loadTextureFromFile("/home/familia1/Imagens/pisoPlataforma.jpg", 8);
    loadTextureFromFile("/home/familia1/Imagens/entrada.jpg", 9);
    loadTextureFromFile("/home/familia1/Imagens/exitL.jpg", 10);


}


/* Main function: GLUT runs as a console application starting at main() */
int mainX(int argc, char** argv) {
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
	textures();

	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
