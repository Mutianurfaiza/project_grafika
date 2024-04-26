#include <GL/glut.h>

int lastX = 0;
int lastY = 0;
GLfloat translate_x = 0.0;
GLfloat translate_y = 0.0;
GLfloat scale = 1.0;
GLfloat rotate_x = 0.0;
GLfloat rotate_y = 0.0;
bool right_button_pressed = false;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glTranslatef(translate_x, translate_y, 0.0);
    glScalef(scale, scale, scale);
    glRotatef(rotate_x, 1.0, 0.0, 0.0); // Rotasi berdasarkan sumbu X
    glRotatef(rotate_y, 0.0, 1.0, 0.0); // Rotasi berdasarkan sumbu Y

    glBegin(GL_QUADS);

    // Meja
    // Daun Meja (1)
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(-2.5, 0.5, -1); // Tepi kiri
    glVertex3f(-2.5, 0.5, 1); // Tepi kanan
    glVertex3f( 1.0, 0.5, 1); // Tepi kanan
    glVertex3f( 1.0, 0.5, -1); // Tepi kiri

    // Daun Meja (2)
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(-2.5, 0.65, -1); // Tepi kiri
    glVertex3f(-2.5, 0.65, 1); // Tepi kanan
    glVertex3f( 1.0, 0.65, 1); // Tepi kanan
    glVertex3f( 1.0, 0.65, -1); // Tepi kiri

    // Daun Meja (3)
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(-2.5, 0.5, -1); // Tepi kiri
    glVertex3f(-2.5, 0.65, -1); // Tepi kiri atas
    glVertex3f(-2.5, 0.65, 1); // Tepi kanan atas
    glVertex3f(-2.5, 0.5, 1); // Tepi kanan

    // Daun Meja (4)
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(1.0, 0.5, -1); // Tepi kiri
    glVertex3f(1.0, 0.65, -1); // Tepi kiri atas
    glVertex3f(1.0, 0.65, 1); // Tepi kanan atas
    glVertex3f(1.0, 0.5, 1); // Tepi kanan

    // Daun Meja (5)
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(-2.5, 0.5, -1); // Tepi kiri
    glVertex3f(-2.5, 0.65, -1); // Tepi kiri atas
    glVertex3f(1.0, 0.65, -1); // Tepi kanan atas
    glVertex3f(1.0, 0.5, -1); // Tepi kanan

    // Daun Meja (6)
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(-2.5, 0.5, 1); // Tepi kiri
    glVertex3f(-2.5, 0.65, 1); // Tepi kiri atas
    glVertex3f(1.0, 0.65, 1); // Tepi kanan atas
    glVertex3f(1.0, 0.5, 1); // Tepi kanan

    // Table legs
    // Kaki meja kiri belakang(1)
    glVertex3f(-2.4, 0.5, -0.8);
    glVertex3f(-2.4, -1.0, -0.8);
    glVertex3f(-2.2, -1.0, -0.8);
    glVertex3f(-2.2, 0.5, -0.8);

    // Kaki meja kiri belakang(2)
    glVertex3f(-2.4, 0.5, -0.6);
    glVertex3f(-2.4, -1.0, -0.6);
    glVertex3f(-2.2, -1.0, -0.6);
    glVertex3f(-2.2, 0.5, -0.6);

    // Kaki meja kiri belakang(3)
    glVertex3f(-2.4, 0.5, -0.8);
    glVertex3f(-2.4, 0.5, -0.6);
    glVertex3f(-2.4, -1.0, -0.6);
    glVertex3f(-2.4, -1.0, -0.8);

    // Kaki meja kiri belakang(4)
    glVertex3f(-2.2, 0.5, -0.8);
    glVertex3f(-2.2, 0.5, -0.6);
    glVertex3f(-2.2, -1.0, -0.6);
    glVertex3f(-2.2, -1.0, -0.8);

    // Kaki meja kiri depan (1)
    glVertex3f(-2.4, 0.5, 0.8);
    glVertex3f(-2.4, -1.0, 0.8);
    glVertex3f(-2.2, -1.0, 0.8);
    glVertex3f(-2.2, 0.5, 0.8);

    // Kaki meja kiri depan (2)
    glVertex3f(-2.4, 0.5, 0.6);
    glVertex3f(-2.4, -1.0, 0.6);
    glVertex3f(-2.2, -1.0, 0.6);
    glVertex3f(-2.2, 0.5, 0.6);

    // Kaki meja kiri depan (3)
    glVertex3f(-2.4, 0.5, 0.8);
    glVertex3f(-2.4, 0.5, 0.6);
    glVertex3f(-2.4, -1.0, 0.6);
    glVertex3f(-2.4, -1.0, 0.8);

    // Kaki meja kiri depan (4)
    glVertex3f(-2.2, 0.5, 0.8);
    glVertex3f(-2.2, 0.5, 0.6);
    glVertex3f(-2.2, -1.0, 0.6);
    glVertex3f(-2.2, -1.0, 0.8);

    // Kaki meja kanan belakang (1)
    glVertex3f(0.9, 0.5, -0.8);
    glVertex3f(0.9, -1.0, -0.8);
    glVertex3f(0.7, -1.0, -0.8);
    glVertex3f(0.7, 0.5, -0.8);

    // Kaki meja kanan belakang (2)
    glVertex3f(0.9, 0.5, -0.6);
    glVertex3f(0.9, -1.0, -0.6);
    glVertex3f(0.7, -1.0, -0.6);
    glVertex3f(0.7, 0.5, -0.6);

    // Kaki meja kanan belakang (3)
    glVertex3f(0.9, 0.5, -0.8);
    glVertex3f(0.9, 0.5, -0.6);
    glVertex3f(0.9, -1.0, -0.6);
    glVertex3f(0.9, -1.0, -0.8);

    // Kaki meja kanan belakang (4)
    glVertex3f(0.7, 0.5, -0.8);
    glVertex3f(0.7, 0.5, -0.6);
    glVertex3f(0.7, -1.0, -0.6);
    glVertex3f(0.7, -1.0, -0.8);

    // Kaki meja kanan depan (1)
    glVertex3f(0.9, 0.5, 0.8);
    glVertex3f(0.9, -1.0, 0.8);
    glVertex3f(0.7, -1.0, 0.8);
    glVertex3f(0.7, 0.5, 0.8);

    // Kaki meja kanan depan (2)
    glVertex3f(0.9, 0.5, 0.6);
    glVertex3f(0.9, -1.0, 0.6);
    glVertex3f(0.7, -1.0, 0.6);
    glVertex3f(0.7, 0.5, 0.6);

    // Kaki meja kanan depan (3)
    glVertex3f(0.9, 0.5, 0.8);
    glVertex3f(0.9, 0.5, 0.6);
    glVertex3f(0.9, -1.0, 0.6);
    glVertex3f(0.9, -1.0, 0.8);

    // Kaki meja kanan depan (4)
    glVertex3f(0.7, 0.5, 0.8);
    glVertex3f(0.7, 0.5, 0.6);
    glVertex3f(0.7, -1.0, 0.6);
    glVertex3f(0.7, -1.0, 0.8);

    // Kursi
    // Kaki kursi kiri belakang(1)
    glVertex3f(-0.2, 0.0, -1.6);
    glVertex3f(-0.2, -1.0, -1.6);
    glVertex3f(-0.1, -1.0, -1.6);
    glVertex3f(-0.1, 0.0, -1.6);

    // Kaki kursi kiri belakang(2)
    glVertex3f(-0.2, 0.0, -1.7);
    glVertex3f(-0.2, -1.0, -1.7);
    glVertex3f(-0.1, -1.0, -1.7);
    glVertex3f(-0.1, 0.0, -1.7);

    // Kaki kursi kiri belakang(3)
    glVertex3f(-0.2, 0.0, -1.7);
    glVertex3f(-0.2, 0.0, -1.6);
    glVertex3f(-0.2, -1.0, -1.6);
    glVertex3f(-0.2, -1.0, -1.7);

    // Kaki kursi kiri belakang(4)
    glVertex3f(-0.1, 0.0, -1.7);
    glVertex3f(-0.1, 0.0, -1.6);
    glVertex3f(-0.1, -1.0, -1.6);
    glVertex3f(-0.1, -1.0, -1.7);

    // Kaki kursi kiri belakang(1)
    glVertex3f(-1.2, 0.0, -1.6);
    glVertex3f(-1.2, -1.0, -1.6);
    glVertex3f(-1.1, -1.0, -1.6);
    glVertex3f(-1.1, 0.0, -1.6);

    // Kaki kursi kiri belakang(2)
    glVertex3f(-1.2, 0.0, -1.7);
    glVertex3f(-1.2, -1.0, -1.7);
    glVertex3f(-1.1, -1.0, -1.7);
    glVertex3f(-1.1, 0.0, -1.7);

    // Kaki kursi kiri belakang(3)
    glVertex3f(-1.2, 0.0, -1.7);
    glVertex3f(-1.2, 0.0, -1.6);
    glVertex3f(-1.2, -1.0, -1.6);
    glVertex3f(-1.2, -1.0, -1.7);

    // Kaki kursi kiri belakang(4)
    glVertex3f(-1.1, 0.0, -1.7);
    glVertex3f(-1.1, 0.0, -1.6);
    glVertex3f(-1.1, -1.0, -1.6);
    glVertex3f(-1.1, -1.0, -1.7);

    // Kaki kursi kiri belakang(1)
    glVertex3f(-1.2, 0.0, -2.6);
    glVertex3f(-1.2, -1.0, -2.6);
    glVertex3f(-1.1, -1.0, -2.6);
    glVertex3f(-1.1, 0.0, -2.6);

    // Kaki kursi kiri belakang(2)
    glVertex3f(-1.2, 0.0, -2.7);
    glVertex3f(-1.2, -1.0, -2.7);
    glVertex3f(-1.1, -1.0, -2.7);
    glVertex3f(-1.1, 0.0, -2.7);

    // Kaki kursi kiri belakang(3)
    glVertex3f(-1.2, 0.0, -2.7);
    glVertex3f(-1.2, 0.0, -2.6);
    glVertex3f(-1.2, -1.0, -2.6);
    glVertex3f(-1.2, -1.0, -2.7);

    // Kaki kursi kiri belakang(4)
    glVertex3f(-1.1, 0.0, -2.7);
    glVertex3f(-1.1, 0.0, -2.6);
    glVertex3f(-1.1, -1.0, -2.6);
    glVertex3f(-1.1, -1.0, -2.7);

    // Kaki kursi kiri belakang(1)
    glVertex3f(-0.2, 0.0, -2.6);
    glVertex3f(-0.2, -1.0, -2.6);
    glVertex3f(-0.1, -1.0, -2.6);
    glVertex3f(-0.1, 0.0, -2.6);

    // Kaki kursi kiri belakang(2)
    glVertex3f(-0.2, 0.0, -2.7);
    glVertex3f(-0.2, -1.0, -2.7);
    glVertex3f(-0.1, -1.0, -2.7);
    glVertex3f(-0.1, 0.0, -2.7);

    // Kaki kursi kiri belakang(3)
    glVertex3f(-0.2, 0.0, -2.7);
    glVertex3f(-0.2, 0.0, -2.6);
    glVertex3f(-0.2, -1.0, -2.6);
    glVertex3f(-0.2, -1.0, -2.7);

    // Kaki kursi kiri belakang(4)
    glVertex3f(-0.1, 0.0, -2.7);
    glVertex3f(-0.1, 0.0, -2.6);
    glVertex3f(-0.1, -1.0, -2.6);
    glVertex3f(-0.1, -1.0, -2.7);


    //Tempat Duduk Kursi (1)
    glVertex3f(-1.2, 0.0, -2.7); // Tepi kiri
    glVertex3f(-1.2, 0.0, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.0, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.0, -2.7); // Tepi kiri

    // Tempat Duduk Kursi (2)
    glVertex3f(-1.2, 0.05, -2.7); // Tepi kiri
    glVertex3f(-1.2, 0.05, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.05, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.05, -2.7); // Tepi kiri

    // Tempat Duduk Kursi (3)
    glVertex3f(-1.2, 0.0, -1.6); // Tepi kiri
    glVertex3f(-1.2, 0.05, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.05, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.0, -1.6); // Tepi kiri

    // Tempat Duduk Kursi (4)
    glVertex3f(-1.2, 0.0, -2.7); // Tepi kiri
    glVertex3f(-1.2, 0.05, -2.7); // Tepi kanan
    glVertex3f(-0.1, 0.05, -2.7); // Tepi kanan
    glVertex3f(-0.1, 0.0, -2.7); // Tepi kiri

    // Tempat Duduk Kursi (5)
    glVertex3f(-0.1, 0.0, -1.6); // Tepi kiri
    glVertex3f(-0.1, 0.05, -1.6); // Tepi kanan
    glVertex3f(-0.1, 0.05, -2.7); // Tepi kanan
    glVertex3f(-0.1, 0.0, -2.7); // Tepi kiri

    // Tempat Duduk Kursi (5)
    glVertex3f(-1.2, 0.0, -1.6); // Tepi kiri
    glVertex3f(-1.2, 0.05, -1.6); // Tepi kanan
    glVertex3f(-1.2, 0.05, -2.7); // Tepi kanan
    glVertex3f(-1.2, 0.0, -2.7); // Tepi kiri

    // Senderan Kursi (1)
    glVertex3f(-0.1, 0.0, -2.7);
    glVertex3f(-0.1, 0.0, -2.6);
    glVertex3f(-0.1, 1.5, -2.6);
    glVertex3f(-0.1, 1.5, -2.7);

    // Senderan Kursi (2)
    glVertex3f(-0.2, 0.0, -2.7);
    glVertex3f(-0.2, 0.0, -2.6);
    glVertex3f(-0.2, 1.5, -2.6);
    glVertex3f(-0.2, 1.5, -2.7);

    // Senderan Kursi (3)
    glVertex3f(-1.2, 0.0, -2.7);
    glVertex3f(-1.2, 0.0, -2.6);
    glVertex3f(-1.2, 1.5, -2.6);
    glVertex3f(-1.2, 1.5, -2.7);

    // Senderan Kursi (4)
    glVertex3f(-1.1, 0.0, -2.7);
    glVertex3f(-1.1, 0.0, -2.6);
    glVertex3f(-1.1, 1.5, -2.6);
    glVertex3f(-1.1, 1.5, -2.7);

    // Senderan Kursi (5)
    glVertex3f(-0.2, 0.0, -2.6);
    glVertex3f(-0.1, 0.0, -2.6);
    glVertex3f(-0.1, 1.5, -2.6);
    glVertex3f(-0.2, 1.5, -2.6);

    // Senderan Kursi (6)
    glVertex3f(-0.2, 0.0, -2.7);
    glVertex3f(-0.1, 0.0, -2.7);
    glVertex3f(-0.1, 1.5, -2.7);
    glVertex3f(-0.2, 1.5, -2.7);

    // Senderan Kursi (7)
    glVertex3f(-1.2, 0.0, -2.6);
    glVertex3f(-1.1, 0.0, -2.6);
    glVertex3f(-1.1, 1.5, -2.6);
    glVertex3f(-1.2, 1.5, -2.6);

    // Senderan Kursi (8)
    glVertex3f(-1.2, 0.0, -2.7);
    glVertex3f(-1.1, 0.0, -2.7);
    glVertex3f(-1.1, 1.5, -2.7);
    glVertex3f(-1.2, 1.5, -2.7);

    // Senderan Kursi (9)
    glVertex3f(-0.2, 1.0, -2.7);
    glVertex3f(-1.1, 1.0, -2.7);
    glVertex3f(-1.1, 1.5, -2.7);
    glVertex3f(-0.2, 1.5, -2.7);

    // Senderan Kursi (10)
    glVertex3f(-0.2, 1.0, -2.6);
    glVertex3f(-1.1, 1.0, -2.6);
    glVertex3f(-1.1, 1.5, -2.6);
    glVertex3f(-0.2, 1.5, -2.6);


    // Lantai (1)
    glColor3f(0.244,0.67,0.54);
    glVertex3f(7.7, -1.0, -7.5);
    glVertex3f(-7.7, -1.0, -7.5);
    glVertex3f(-7.7, -1.0, 7.5);
    glVertex3f(7.7, -1.0, 7.5);

    // Lantai (2)
    glVertex3f(7.7, -1.2, -7.5);
    glVertex3f(-7.7, -1.2, -7.5);
    glVertex3f(-7.7, -1.2, 7.5);
    glVertex3f(7.7, -1.2, 7.5);

    // Tembok Depan (1)
    glVertex3f(7.5, -1.2, 7.5);
    glVertex3f(-7.5, -1.2, 7.5);
    glVertex3f(-7.5, 8.0, 7.5);
    glVertex3f(7.5, 8.0, 7.5);

    // Tembok Depan (2)
    glVertex3f(7.5, -1.2, 7.7);
    glVertex3f(-7.5, -1.2, 7.7);
    glVertex3f(-7.5, 8.0, 7.7);
    glVertex3f(7.5, 8.0, 7.7);

    // Tembok Kanan (1)
    glVertex3f(-7.5, -1.0, -3.0);
    glVertex3f(-7.5, 8.0, -3.0);
    glVertex3f(-7.5, 8.0, 7.5);
    glVertex3f(-7.5, -1.0, 7.5);

    // Tembok Kanan (1) (Lapisan)
    glVertex3f(-7.7, -1.0, -3.0);
    glVertex3f(-7.7, 8.0, -3.0);
    glVertex3f(-7.7, 8.0, 7.5);
    glVertex3f(-7.7, -1.0, 7.5);

    // Tembok Kanan (1) (Penutup Tegak)
    glVertex3f(-7.5, -1.0, -3.0);
    glVertex3f(-7.5, 4.0, -3.0);
    glVertex3f(-7.7, 4.0, -3.0);
    glVertex3f(-7.7, -1.0, -3.0);

    // Tembok Kanan (1) (Penutup Datar)
    glVertex3f(-7.5, 4.0, 7.5);
    glVertex3f(-7.7, 4.0, 7.5);
    glVertex3f(-7.7, 4.0, 3.0);
    glVertex3f(-7.5, 4.0, 3.0);

    // Tembok Kanan (2)
    glVertex3f(-7.5, 4.0, -7.5);
    glVertex3f(-7.5, 8.0, -7.5);
    glVertex3f(-7.5, 8.0, -3.0);
    glVertex3f(-7.5, 4.0, -3.0);

    // Tembok Kanan (2) (Lapisan)
    glVertex3f(-7.7, 4.0, -7.5);
    glVertex3f(-7.7, 8.0, -7.5);
    glVertex3f(-7.7, 8.0, -3.0);
    glVertex3f(-7.7, 4.0, -3.0);

    // Tembok Kanan (3) (Bawah Ujung)
    glVertex3f(-7.5, -1.0, -7.5);
    glVertex3f(-7.5, 4.0, -7.5);
    glVertex3f(-7.5, 4.0, -5.5);
    glVertex3f(-7.5, -1.0, -5.5);

    // Tembok Kanan (3) (Bawah Ujung) (Lapisan)
    glVertex3f(-7.7, -1.0, -7.5);
    glVertex3f(-7.7, 4.0, -7.5);
    glVertex3f(-7.7, 4.0, -5.5);
    glVertex3f(-7.7, -1.0, -5.5);

    // Tembok Kanan (1) (Bawah Ujung) (Penutup Tegak)
    glVertex3f(-7.5, -1.0, -5.5);
    glVertex3f(-7.5, 4.0, -5.5);
    glVertex3f(-7.7, 4.0, -5.5);
    glVertex3f(-7.7, -1.0, -5.5);

    // Papan Tulis
    glColor3f(0.6, 0.66, 0.6);
    glVertex3f(4.4, 5.5, 7.4);
    glVertex3f(-5.4, 5.5, 7.4);
    glVertex3f(-5.4, 2.0, 7.4);
    glVertex3f(4.4, 2.0, 7.4);

    // Pintu
    glColor3f(0.5, 0.35, 0.05); // Brown
    glVertex3f(-7.6, 4.0, -3.0);
    glVertex3f(-7.6, 4.0, -5.5);
    glVertex3f(-7.6, -1.0, -5.5);
    glVertex3f(-7.6, -1.0, -3.0);

    glEnd();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lastX = x;
        lastY = y;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        right_button_pressed = true;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        right_button_pressed = false;
    }
    else if (button == 3) { // Scroll up
        scale *= 1.1;
        glutPostRedisplay();
    }
    else if (button == 4) { // Scroll down
        scale /= 1.1;
        glutPostRedisplay();
    }
}

void motion(int x, int y) {
    int deltaX = x - lastX;
    int deltaY = y - lastY;
    if (right_button_pressed) {
        rotate_x += deltaY * 0.1; // Rotasi berdasarkan sumbu X saat tombol kanan ditekan
        rotate_y += deltaX * 0.1; // Rotasi berdasarkan sumbu Y saat tombol kanan ditekan
    } else {
        translate_x += deltaX * 0.01;
        translate_y -= deltaY * 0.01;
    }
    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Table");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
