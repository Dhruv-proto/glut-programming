#include <GL/glut.h>

// Function to initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
}

// Function to display/render content
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(0.0, 0.0, 0.0); // Set line color to black

    // Draw a straight line
    glBegin(GL_LINES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glEnd();

    glFlush(); // Flush the buffer
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode

    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("OpenGL Line"); // Create a window with the given title

    init(); // Initialize OpenGL

    // Set the display callback function
    glutDisplayFunc(display);

    glutMainLoop(); // Enter the event processing loop

    return 0;
}
