/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


#include <iostream>
using namespace std;

int x1, y1, x2, y2;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLineAlgo() {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope = dy > dx ? 1 : 0;

    if (slope) {
        swap(dx, dy);
    }

    int inc1 = 2 * dy;
    int inc2 = 2 * (dy - dx);
    int d = 2 * dy - dx;
    int x = x1, y = y1;

    plot(x, y);

    while (x < x2) {
        x++;

        if (d < 0) {
            d += inc1;
        } else {
            y++;
            d += inc2;
        }

        if (slope) {
            plot(y, x);
        } else {
            plot(x, y);
        }
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    bresenhamLineAlgo();
    glFlush();
}

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Bresenham's Line Algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
