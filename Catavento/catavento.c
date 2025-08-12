#include <GL/glut.h>

float angle = 0.0f;

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0, 1.0, 0); 
    glBegin(GL_LINES);
        glVertex2i(250, 100);
        glVertex2i(250, 250);
    glEnd();

    glPushMatrix(); 
    glTranslatef(250.0f, 250.0f, 0.0f);
    glRotatef(-angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-250.0f, -250.0f, 0.0f);


     glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 290);
        glVertex2i(270, 290);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(290, 230);
        glVertex2i(290, 270);
    glEnd();

     glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 210);
        glVertex2i(270, 210);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(210, 230);
        glVertex2i(210, 270);
    glEnd();


    glPopMatrix();
    glFlush();
}

void rodar(unsigned char key, int x, int y){

    switch(key){
        case 'p':
            angle +=10.0f;

            if(angle >= 360){
                angle-=360;
            }

            glutPostRedisplay();
            break;

        case 27:
            exit(0);
            break;
    }
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Catavento");
    init();
    glutDisplayFunc(display);
     glutKeyboardFunc(rodar); 
    glutMainLoop();
    return 0;
}
