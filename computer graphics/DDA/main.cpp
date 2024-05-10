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

int pntX1, pntY1, pntX2, pntY2;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawLineDDA(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = max(abs(dx), abs(dy));
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;
    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; ++i) {
        plot(static_cast<int>(x + 0.5), static_cast<int>(y + 0.5));
        x += xIncrement;
        y += yIncrement;
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    drawLineDDA(pntX1, pntY1, pntX2, pntY2);

    glFlush();
}

int main(int argc, char** argv) {
    cout << "Enter coordinates of the first point:" << endl;
    cout << "X-coordinate: ";
    cin >> pntX1;
    cout << "Y-coordinate: ";
    cin >> pntY1;

    cout << "Enter coordinates of the second point:" << endl;
    cout << "X-coordinate: ";
    cin >> pntX2;
    cout << "Y-coordinate: ";
    cin >> pntY2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("DDA Line Drawing Algorithm");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}
