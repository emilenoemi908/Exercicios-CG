#include <GL/glut.h>
#include <GL/glu.h>


float angle = 0.0f;
float lua = 0.0f;
float d1 = 3.0f;
float d2 = 6.0f;
float dZ= 18.0f; 


void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat luzAmbiente[]  = {0.2, 0.2, 0.2, 1.0};
    GLfloat luzDifusa[]    = {1.0, 1.0, 1.0, 1.0};
    GLfloat luzEspecular[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT,  luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);

    glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w, int h) {
    if (h == 0) h = 1; 
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      
    glLoadIdentity();
    gluLookAt(0.0, 0.0, dZ,  
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0); 

    
    GLfloat light_pos[] = {1.0f, 1.0f, 1.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    // Sol
    glPushMatrix();
        glColor3f(1.0, 0.8, 0.0);
        glutSolidSphere(2.0, 50, 50);
    glPopMatrix();

    // Planeta 1
    glPushMatrix();
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(d1, 0.0f, 0.0f);
        glColor3f(0.0, 0.0, 1.0);
        glutSolidSphere(0.7, 30, 20);
    glPopMatrix();

    // Planeta 2 com luas
    glPushMatrix();
        glRotatef(-angle, 0.0f, 1.0f, 0.0f);
        glTranslatef(d2, 0.0f, 0.0f);
        glColor3f(1.0, 0.0, 0.0);
        glutSolidSphere(0.7, 30, 20);

        // Lua 1
        glPushMatrix();
            glRotatef(lua, 1.0f, 0.0f, 0.0f);
            glTranslatef(1.5f, 0.0f, 0.0f);
            glColor3f(1.0, 0.0, 1.0);
            glutSolidSphere(0.2, 20, 15);
        glPopMatrix();

        // Lua 2
        glPushMatrix();
            glRotatef(lua, 1.0f, 1.0f, 0.0f);
            glTranslatef(1.5f, 0.0f, 0.0f);
            glColor3f(1.0, 0.0, 1.0);
            glutSolidSphere(0.25, 20, 15);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers(); 
}


void keyboard(unsigned char key, int x, int y) {

    if (key == 'y' || key == 'y') {
        angle += 3.0f;
        if(angle > 360) angle -= 360;

        lua += 2.0f;
        if(lua > 360) lua -= 360;

        glutPostRedisplay();
    }


    else if(key == '+'){
        dZ -= 1.0f;

        if(dZ < 8.0f) dZ= 8.0f;

        glutPostRedisplay();
    }

    else if(key == '-'){

        if(dZ < 90){
            dZ+=1.0f;
        }

        glutPostRedisplay();
    }
    else if (key == 27) exit(0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Rotacao de Planetas");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
