///////////////////////////////////////////////////////////////////////////////
// cameraSimple.h
// ==============
// A simple camera model (192 triangles)
// Use "drawCube()" to draw this model.
//
// 3D model is converted by the PolyTrans from Okino Computer Graphics, Inc.
// Bounding box of geometry = (-0.5,-0.35,-0.3) to (0.5,0.37,0.3).
//
//  AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// CREATED: 2008-09-18
// UPDATED: 2018-03-02
// cube ///////////////////////////////////////////////////////////////////////
//    v6----- v5
//   /|      /|
//  v1------v0|
//  | |     | |
//  | |v7---|-|v4
//  |/      |/
//  v2------v3
///////////////////////////////////////////////////////////////////////////////

#ifndef CUBE_SIMPLE_H
#define CUBE_SIMPLE_H
// vertices for camera
static GLfloat cubeVertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,   1,-1, 1,   // v0,v1,v2,v3 (front)
 1, 1, 1,   1,-1, 1,   1,-1,-1,   1, 1,-1,   // v0,v3,v4,v5 (right)
 1, 1, 1,   1, 1,-1,  -1, 1,-1,  -1, 1, 1,   // v0,v5,v6,v1 (top)
-1, 1, 1,  -1, 1,-1,  -1,-1,-1,  -1,-1, 1,   // v1,v6,v7,v2 (left)
-1,-1,-1,   1,-1,-1,   1,-1, 1,  -1,-1, 1,   // v7,v4,v3,v2 (bottom)
 1,-1,-1,  -1,-1,-1,  -1, 1,-1,   1, 1,-1 }; // v4,v7,v6,v5 (back)
static GLfloat cubeNormals[] = { 0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,   // v0,v1,v2,v3 (front)
 1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,   // v0,v3,v4,v5 (right)
 0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,   // v0,v5,v6,v1 (top)
-1, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,   // v1,v6,v7,v2 (left)
 0,-1, 0,   0,-1, 0,   0,-1, 0,   0,-1, 0,   // v7,v4,v3,v2 (bottom)
 0, 0,-1,   0, 0,-1,   0, 0,-1,   0, 0,-1 }; // v4,v7,v6,v5 (back)


static GLint cubeIndices[] = { 0, 1, 2,   2, 3, 0,      // front
 4, 5, 6,   6, 7, 4,      // right
 8, 9,10,  10,11, 8,      // top
12,13,14,  14,15,12,      // left
16,17,18,  18,19,16,      // bottom
20,21,22,  22,23,20 };    // back

void drawCube()
{
    
    
    float shininess = 15.0f;
    float diffuseColor[4] = {0.929524f, 0.796542f, 0.178823f, 1.0f};
    float specularColor[4] = {1.00000f, 0.980392f, 0.549020f, 1.0f};

    // set color using glMaterial (gold-yellow)
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess); // range 0 ~ 128
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, diffuseColor);


    // set ambient and diffuse color using glColorMaterial (gold-yellow)
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3fv(diffuseColor);

    // start to render polygons
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);


    glNormalPointer(GL_FLOAT, 0, cubeNormals);
    glVertexPointer(3, GL_FLOAT, 0, cubeVertices);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &cubeIndices[0]);

    glDisableClientState(GL_VERTEX_ARRAY);    // disable vertex arrays
    glDisableClientState(GL_NORMAL_ARRAY);    // disable normal arrays
}

#endif

