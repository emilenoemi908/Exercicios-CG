#include <windows.h>
#include <GL/glut.h>

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0); 
    glBegin(GL_LINES);
        glVertex2i(250, 100);
        glVertex2i(250, 230);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(290, 230);
        glVertex2i(290, 270);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 290);
        glVertex2i(270, 290);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(210, 230);
        glVertex2i(210, 270);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 210);
        glVertex2i(270, 210);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Catavento Colorido");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
