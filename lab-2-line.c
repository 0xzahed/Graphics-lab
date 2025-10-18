#include<Gl\glut.h>
#include<iostream>
using namespace std;

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
int x0, y0, x1, y1;
void line(int x0, int y0, int x1, int y1){
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int twoDY = 2* dy;
    int twoDX = 2*(dy - dx);
    int x, y;

    if(x0 > x1){
        x = x1;
        y = y1;
        x1 = x0;
        y0 = y;
    }
    else{
        x = x0;
        y = y0;
    }
    int p = 2*dy - dx;
    glBegin(GL_POINTS);
    glVertex2i( x, y);

    while(x < x1){
        x++;
        if(p < 0){
            p = p + twoDY;
        }
        else{
            y++;
            p = p + twoDX;
        }
        glVertex2i( x, y);
    }
    glEnd();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    line(x0, y0, x1, y1);
    glFlush();

}



int main(int argc, char** argv){

    cout << "Enter x0 y0 x1 y1: ";
    cin >> x0 >> y0 >> x1 >> y1;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(300,00);
    glutCreateWindow("Point");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


