//Credits: 	//https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
			//https://pt.wikipedia.org/wiki/Algoritmo_de_Bresenham

#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0 );
}

void setPixel(int x,int y){
	glColor3f(0,255,255);
	glPointSize(5);

	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();

	glFlush();
}

void bresenham1(int x1, int y1, int x2, int y2){        
	int slope;
	int dx, dy, incE, incNE, d, x, y;
	// Onde inverte a linha x1 > x2       
	if (x1 > x2){
		bresenham1(x2, y2, x1, y1);
		return;
	}        
	dx = x2 - x1;
	dy = y2 - y1;

	if (dy < 0){            
		slope = -1;
		dy = -dy;
	}else{            
		slope = 1;
	}
	// Constante de Bresenham
	incE = 2 * dy;
	incNE = 2 * dy - 2 * dx;
	d = 2 * dy - dx;
	y = y1;       
	for (x = x1; x <= x2; x++){
		setPixel(x, y);
		if (d <= 0){
			d += incE;
		}else{
			d += incNE;
			y += slope;
		}
	}
	//glFlush();
}

void drawcircle(int x0, int y0, int radius, int choice)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
    	if(choice == 1){
	        setPixel(x0 + x, y0 + y);
	        setPixel(x0 + y, y0 + x);
	        setPixel(x0 - y, y0 + x);
	        setPixel(x0 - x, y0 + y);
	        setPixel(x0 - x, y0 - y);
	        setPixel(x0 - y, y0 - x);
	        setPixel(x0 + y, y0 - x);
	        setPixel(x0 + x, y0 - y);
    	} else if(choice == 2){
    		setPixel(x0 + x, y0 + y);
	        setPixel(x0 + y, y0 + x);
	        setPixel(x0 + y, y0 - x);
	        setPixel(x0 + x, y0 - y);
	    }else if(choice == 3){
	    	setPixel(x0 - y, y0 + x);
	        setPixel(x0 - x, y0 + y);
	        setPixel(x0 - x, y0 - y);
	        setPixel(x0 - y, y0 - x);
	    }

        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void mouse(GLint button, GLint act,
			int xMouse, int yMouse){
	int xM, yM, xM2, yM2, count = 0;
	if(button == GLUT_LEFT_BUTTON && act == GLUT_DOWN && count == 0){
		xM = xM2  = xMouse;
		yM = yM2 = 500 - yMouse;
		setPixel(xM, yM);
		cout << xM << " " << yM << " " << xM2 << " " << yM2 << "\n";
		count = 1;
		
		//bresenham1(xM, yM, xM2, yM2);

	}else{
		//cout << "entrou";
		xM2 = xMouse;
		yM2 = 500 - yMouse;
		setPixel(xM2, yM2);
		cout << "else " << xM2 << " " << yM2 << "\n";
		count = 0;
		bresenham1(xM, yM, xM2, yM2);

	}
		//cout << "x = " << xM << " y = " << yM << "\n";
	//bresenham1(xM, yM, xM2, yM2);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	// glPointSize(5);
	// glBegin(GL_POINTS);
	// 	glVertex2f(250,250);
	// glEnd();

	bresenham1(70, 150, 350, 150);
	bresenham1(70, 300, 350, 300);

	//left side
	glBegin(GL_LINES);
		glPointSize(4);

		glColor3f(0,255,255);
		glVertex2f(70,150);
		glVertex2f(70,300);
	glEnd();

	//right side
	glBegin(GL_LINES);
		glPointSize(4);

		glColor3f(0,255,255);
		glVertex2f(350,150);
		glVertex2f(350,300);
	glEnd();

	//line central
	glBegin(GL_LINES);
		glPointSize(4);

		glColor3f(255,0,255);
		glVertex2f(215,150);
		glVertex2f(215,300);
	glEnd();

	//middle circle
	drawcircle(215, 225, 15, 1);

	//left side
	bresenham1(70, 200, 115, 210);

	bresenham1(70, 250, 115, 240);

	drawcircle(115, 225, 15, 1);

	//right side
	bresenham1(350, 200, 305, 210);

	bresenham1(350, 250, 305, 240);

	drawcircle(305, 225, 15, 1);

	//Right half left
	drawcircle(70, 225, 65, 2);

	//Left half left
	drawcircle(350, 225, 65, 3);

	glFlush();
}

int main (int argc,char **argv)
{
  glutInit(&argc,argv); 
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,25);
  glutInitWindowSize(500,500);
  glutCreateWindow("Bresenham Line");

  init();
  
  glutDisplayFunc(display);
  glutMouseFunc(mouse);

  glutMainLoop();
  return 0;
}