// Naheed Rayhan B180305041


#include <GL/glut.h>

// Car position
float carX = -1.0f;
float carY = 0.0f;

// Car dimensions
float carWidth = 0.2f;
float carHeight = 0.1f;

void drawCar() {
    glColor3f(1.0, 0.5, 0.5); // Red color
    glBegin(GL_QUADS);
    glVertex2f(carX, carY);
    glVertex2f(carX + carWidth, carY);
    glVertex2f(carX + carWidth, carY + carHeight);
    glVertex2f(carX, carY + carHeight);
    glEnd();
}

GLfloat angle = 0.0f;  // Rotation angle of the windmill

void drawWindmill() {
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);  // Set color to gray

    // Draw the windmill base
    glBegin(GL_POLYGON);
    glVertex2f(0.01f, 0.40f);
    glVertex2f(-0.01f, 0.40f);
    glVertex2f(-0.01f, 1.00f);
    glVertex2f(0.01f, 1.00f);
    glEnd();



    // Draw the windmill blades
    glTranslatef(0.0f, 1.0f, 0.0f);  // Move to the top of the windmill base
    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotate around the Z-axis
    

    for (int i = 0; i < 3; i++) {
        glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.05f, 0.04f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.05f, -0.04f);
        glEnd();
        glRotatef(120.0f, 0.0f, 0.0f, 1.0f);  // Rotate each blade by 120 degrees
    }

    glPopMatrix();
}




void drawHouse() {
    glColor3f(0.52, 0.37, 0.26); // Brown color
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.60f);
    glVertex2f(0.3f, 0.60f);
    glVertex2f(0.15f, 0.80f);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.40f);
    glVertex2f(0.25f, 0.40f);
    glVertex2f(0.25f, 0.60f);
    glVertex2f(0.05f, 0.60f);
    glEnd();

    glColor3f(0.52, 0.37, 0.26); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(0.09f, 0.40f);
    glVertex2f(0.2f, 0.40f);
    glVertex2f(0.2f, 0.56f);
    glVertex2f(0.09f, 0.56f);
    glEnd();
}

void drawTree() {

    glColor3f(0.184314, 0.309804 , 0.184314); 
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.80f);
    glVertex2f(0.2f, 0.80f);
    glVertex2f(0.1f, 1.1f);
    glEnd();

 
    glColor3f(0.184314, 0.309804 , 0.184314); 
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.70f);
    glVertex2f(0.2f, 0.70f);
    glVertex2f(0.1f, 0.90f);
    glEnd();


    glColor3f(0.184314, 0.309804 , 0.184314); 
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.60f);
    glVertex2f(0.2f, 0.60f);
    glVertex2f(0.1f, 0.80f);
    glEnd();



    glColor3f(0.5f, 0.3f, 0.0f); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(0.08f, 0.40f);
    glVertex2f(0.13f, 0.40f);
    glVertex2f(0.13f, 0.60f);
    glVertex2f(0.08f, 0.60f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw Sky
    glColor3f(0.74902f, 0.847059, 0.887059); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    // Draw background
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();




    
    // Draw house
    glPushMatrix();
    glTranslatef(-0.6f, -0.4f, 0.0f); // Move the house to the left
    drawHouse();
    glPopMatrix();

        // Draw house
    glPushMatrix();
    glTranslatef(-1.0f, -0.4f, 0.0f); // Move the house to the left
    drawHouse();
    glPopMatrix();

        // Draw house
    glPushMatrix();
    glTranslatef(0.5f, -0.4f, 0.0f); // Move the house to the left
    drawHouse();
    glPopMatrix();
    
    // Draw tree
    glPushMatrix();
    glTranslatef(0.0f, -0.4f, 0.0f); // Move the tree to the right
    drawTree();
    glPopMatrix();

        // Draw tree
    glPushMatrix();
    glTranslatef(-0.4f, -0.4f, 0.0f); // Move the tree to the right
    drawTree();
    glPopMatrix();

    //windmill
    glPushMatrix();
    glTranslatef(0.4f, -0.4f, 0.0f); // Move the tree to the right
    drawWindmill();
    glPopMatrix();

    
    // Draw car
    glPushMatrix();
    glTranslatef(carX, carY, 0.0f);
    drawCar();
    glPopMatrix();
    
    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0); // 60 FPS
    carX += 0.01f; // Move the car to the right
    
    // Check if the car reaches the right edge of the screen
    if (carX > 1.0f) {
        carX = -1.0f; // Reset the car position to the left edge
    }

    angle += 1.0f;  // Increment the rotation angle
    if (angle > 360.0f) {
        angle -= 360.0f;
    }

    // glutPostRedisplay();  // Notify GLUT that the display has changed
    // glutTimerFunc(25, update, 0);  // Call the update function after 25 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Moving Car");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    
    return 0;
}
