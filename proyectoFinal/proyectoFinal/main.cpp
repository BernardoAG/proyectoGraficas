//
//  main.cpp
//  proyectoFinal
//
//  Created by Bernardo Altamirano and Santiago Borobia on 05/12/19.
//  Copyright © 2019 Bernardo Altamirano. All rights reserved.
//

#include <iostream>
#include "GLUT/glut.h"
#include <math.h>
#include <OpenGL/gl.h>

GLsizei winWidth = 650, winHeight = 650; // Initial display-window size.
GLfloat x0 = 50, Y0 = 60, z0 = -50.0; // Viewing-coordinate origin.
GLfloat xref = 50.0, yref = 50.0, zref = 0.0; // Look-at point.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
/* Set coordinate limits for the clipping window: */
GLfloat xwMin = -60.0, ywMin = -60.0, xwMax = 60.0, ywMax = 60.0;
/* Set positions for near and far clipping planes: */
GLfloat dnear = 25.0, dfar = 125.0;

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
//    glMatrixMode (GL_MODELVIEW);
//    gluLookAt(x0, Y0, z0, xref, yref, zref, Vx, Vy, Vz);
//    glMatrixMode (GL_PROJECTION);
//    glFrustum (xwMin, xwMax, ywMin, ywMax, dnear, dfar);
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
    
    // Maniplación de luces
    glEnable(GL_LIGHTING);
    GLfloat light1PosType[] = {5,5,5,0};
    GLfloat light1AmbientType[] = {0,0.5,0.5,0.5};
    GLfloat light1DiffuseType[] = {1,1,1,1};
    GLfloat light1SpecularType[] = {1,1,1,1};
    GLfloat light1SpotType[] = {1,0,-5};
    glLightfv(GL_LIGHT1, GL_POSITION, light1PosType);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1AmbientType);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1DiffuseType);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1SpecularType);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1SpotType);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);
    glEnable(GL_LIGHT1);
}

void displayWirePolyhedra (void)
{
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
    glColor3f (0.0, 0.0, 1.0); // Set line color to blue.

    /* Set viewing transformation. */
    gluLookAt (5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    /* Scale cube and display as wire-frame parallelepiped. */
    glScalef (1.5, 2.0, 1.0);
    glutSolidCube (1.0);
    
    /* Scale, translate, and display wire-frame dodecahedron. */
    glScalef (0.8, 0.5, 0.8);
    glTranslatef (-6.0, -5.0, 0.0);
    glutSolidDodecahedron ( );

    /* Translate and display wire-frame tetrahedron. */
    glTranslatef (8.6, 8.6, 2.0);
    glutSolidTetrahedron ( );

    /* Translate and display wire-frame octahedron. */
    glTranslatef (-3.0, -1.0, 0.0);
    glutSolidOctahedron ( );

    /* Scale, translate, and display wire-frame icosahedron. */
    glScalef (0.8, 0.8, 1.0);
    glTranslatef (4.3, -2.0, 0.5);
    glutSolidIcosahedron ( );

    glFlush ( );
}

void paint(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    displayWirePolyhedra();
    glutSwapBuffers();
}

void reshapeFcn (GLint newWidth, GLint newHeight)
{
    glViewport (0, 0, newWidth, newHeight);
    glMatrixMode (GL_PROJECTION);
    glFrustum (-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
    glMatrixMode (GL_MODELVIEW);
    glClear (GL_COLOR_BUFFER_BIT);
}

int main (int argc, char** argv){
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (950, 150);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Proyecto Final");
    init();
    glutDisplayFunc (paint);
    glutReshapeFunc (reshapeFcn);
    glutMainLoop ();
}
