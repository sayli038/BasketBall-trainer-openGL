#include "Board.h"

Board::Board(double level) {
    courtImage = gltxReadRGB("fullcourt.rgb");

    glGenTextures(1, &courtTexture);
    glBindTexture(GL_TEXTURE_2D, courtTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, courtImage->width, courtImage->height,
            0, GL_RGB, GL_UNSIGNED_BYTE, courtImage->data);

    crowdImage = gltxReadRGB("1.rgb");

    glGenTextures(1, &crowdTexture);
    glBindTexture(GL_TEXTURE_2D, crowdTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, crowdImage->width, crowdImage->height,
            0, GL_RGB, GL_UNSIGNED_BYTE, crowdImage->data);

    newRing = new Ring(0.6, level, 100);
}

Board::~Board(void) {
}

void Board::displayBoard() {
    //Board
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glTranslated(2, 1.5, 0.1);
    drawboard();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    //Ring
	newRing->drawRing();
    //Pole
    glPushMatrix();
    glColor4d(0.6, 0.6, 0.6,0.9);
    glRotated(90, 0, 1, 0);  glRotated(90, 1, 0, 0);
    glTranslated(-1.0, 0, -2.0);
    glutSolidCone(0.5, 5.5, 10, 10);
    glPopMatrix();
    drawCourt();
}
//From 3DArtist
void Board::drawboard(void) {
    double mat[16];
    if (firstCall) {
        glGenTextures(3, texId);
        glBindTexture(GL_TEXTURE_2D, texId[0]);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, p0);
        glBindTexture(GL_TEXTURE_2D, texId[1]);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, 512, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, p1);
        glBindTexture(GL_TEXTURE_2D, texId[2]);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, p2);
        firstCall = 0;
    }
    mat[0] = 1.215741e-002;   mat[1] = 0.000000e+000;
    mat[2] = -9.999261e-001;  mat[3] = 0.000000e+000;
    mat[4] = 0.000000e+000;   mat[5] = 1.000000e+000;
    mat[6] = 0.000000e+000;   mat[7] = 0.000000e+000;
    mat[8] = 9.999261e-001;   mat[9] = 0.000000e+000;
    mat[10] = 1.215741e-002;  mat[11] = 0.000000e+000;
    mat[12] = 1.693735e-001;  mat[13] = 6.382283e-003;
    mat[14] = -1.073481e-001; mat[15] = 1.000000e+000;
    glPushMatrix();
    glMultMatrixd(mat);
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    glBegin(GL_POLYGON);
    glNormal3d(0.000000e+000, -1.000000e+000, 0.000000e+000);
    glTexCoord2d(0.000000e+000, 0.000000e+000);
    glVertex3d(-1.229293e+000, 0.000000e+000, -7.619444e-001);
    glTexCoord2d(0.000000e+000, 1.000000e+000);
    glVertex3d(-1.229293e+000, 0.000000e+000, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 1.000000e+000);
    glVertex3d(1.229293e+000, 0.000000e+000, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 0.000000e+000);
    glVertex3d(1.229293e+000, 0.000000e+000, -7.619444e-001);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texId[1]);
    glBegin(GL_POLYGON);
    glNormal3d(0.000000e+000, 1.000000e+000, 0.000000e+000);
    glTexCoord2d(0.000000e+000, 0.000000e+000);
    glVertex3d(1.229293e+000, 9.411067e-002, -7.619444e-001);
    glTexCoord2d(0.000000e+000, 1.000000e+000);
    glVertex3d(1.229293e+000, 9.411067e-002, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 1.000000e+000);
    glVertex3d(-1.229293e+000, 9.411067e-002, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 0.000000e+000);
    glVertex3d(-1.229293e+000, 9.411067e-002, -7.619444e-001);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    glBegin(GL_POLYGON);
    glNormal3d(-1.000000e+000, 0.000000e+000, 0.000000e+000);
    glTexCoord2d(0.000000e+000, 0.000000e+000);
    glVertex3d(-1.229293e+000, 0.000000e+000, -7.619444e-001);
    glTexCoord2d(0.000000e+000, 1.000000e+000);
    glVertex3d(-1.229293e+000, 9.411067e-002, -7.619444e-001);
    glTexCoord2d(1.000000e+000, 1.000000e+000);
    glVertex3d(-1.229293e+000, 9.411067e-002, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 0.000000e+000);
    glVertex3d(-1.229293e+000, 0.000000e+000, 7.619444e-001);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    glBegin(GL_POLYGON);
    glNormal3d(-0.000000e+000, 0.000000e+000, 1.000000e+000);
    glTexCoord2d(0.000000e+000, 0.000000e+000);
    glVertex3d(-1.229293e+000, 0.000000e+000, 7.619444e-001);
    glTexCoord2d(0.000000e+000, 1.000000e+000);
    glVertex3d(-1.229293e+000, 9.411067e-002, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 1.000000e+000);
    glVertex3d(1.229293e+000, 9.411067e-002, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 0.000000e+000);
    glVertex3d(1.229293e+000, 0.000000e+000, 7.619444e-001);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    glBegin(GL_POLYGON);
    glNormal3d(1.000000e+000, 0.000000e+000, 0.000000e+000);
    glTexCoord2d(0.000000e+000, 0.000000e+000);
    glVertex3d(1.229293e+000, 0.000000e+000, 7.619444e-001);
    glTexCoord2d(0.000000e+000, 1.000000e+000);
    glVertex3d(1.229293e+000, 9.411067e-002, 7.619444e-001);
    glTexCoord2d(1.000000e+000, 1.000000e+000);
    glVertex3d(1.229293e+000, 9.411067e-002, -7.619444e-001);
    glTexCoord2d(1.000000e+000, 0.000000e+000);
    glVertex3d(1.229293e+000, 0.000000e+000, -7.619444e-001);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texId[2]);
    glBegin(GL_POLYGON);
    glNormal3d(-0.000000e+000, -0.000000e+000, -1.000000e+000);
    glTexCoord2d(0.000000e+000, 0.000000e+000);
    glVertex3d(1.229293e+000, 0.000000e+000, -7.619444e-001);
    glTexCoord2d(0.000000e+000, 1.000000e+000);
    glVertex3d(1.229293e+000, 9.411067e-002, -7.619444e-001);
    glTexCoord2d(1.000000e+000, 1.000000e+000);
    glVertex3d(-1.229293e+000, 9.411067e-002, -7.619444e-001);
    glTexCoord2d(1.000000e+000, 0.000000e+000);
    glVertex3d(-1.229293e+000, 0.000000e+000, -7.619444e-001);
    glEnd();
    glPopMatrix();
}

void Board::drawWall(double x, double y, int parts, bool withTexture, GLuint texture,
        double textureFactor, bool inverseTexture,Vector3d normal) {

    double textureChange = 0;

    double xChange = x / parts;
    double yChange = y / parts;

    if (withTexture) {
        textureChange = textureFactor / parts;
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    glPushMatrix();
    {
        glNormal3d(normal.getValueAt(X),normal.getValueAt(Y),normal.getValueAt(Z));
        glBegin(GL_QUADS);
        {
            for (int j = 0; j < parts; j++) {
                for (int i = 0; i < parts; i++) {
                    if (withTexture) {
                        if (inverseTexture) glTexCoord2f((j) * textureChange, i * textureChange);
                        else glTexCoord2f((i) * textureChange, j * textureChange);
                    }
                    glVertex3f((i) * xChange, 0.0, j * yChange);
                    if (withTexture) {
                        if (inverseTexture) glTexCoord2f((j + 1) * textureChange, (i) * textureChange);
                        else glTexCoord2f((i) * textureChange, (j + 1) * textureChange);
                    }
                    glVertex3f((i) * xChange, 0.0, (j + 1) * yChange);
                    if (withTexture) {
                        if (inverseTexture) glTexCoord2f((j + 1) * textureChange, (i + 1) * textureChange);
                        else glTexCoord2f((i + 1) * textureChange, (j + 1) * textureChange);
                    }
                    glVertex3f((i + 1) * xChange, 0.0, (j + 1) * yChange);
                    if (withTexture) {
                        if (inverseTexture) glTexCoord2f((j) * textureChange, (i + 1) * textureChange);
                        else glTexCoord2f((i + 1) * textureChange, (j) * textureChange);
                    }
                    glVertex3f((i + 1) * xChange, 0.0, (j) * yChange);
                }
            }
        }
        glEnd();
    }
    glPopMatrix();

    if (withTexture) glDisable(GL_TEXTURE_2D);
}

void Board::drawCourt() {

    Vector3d normal(0.0,1.0,0.0);
    //floor
    glPushMatrix();
    glTranslated(-8.0, -2.0, 0.0);
    drawWall(16, 22, 100, true, courtTexture, 1, true, normal);
    glPopMatrix();

    //Roof
    glPushMatrix();
    glTranslated(8.0, 6.0, 0.0);
    glRotated(180.0, 0, 0, 1);
    drawWall(16, 22, 100, true, crowdTexture, 2, false, normal);
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslated(-8.0, 6.0, 0.0);
    glRotated(-90.0, 0, 0, 1);
    drawWall(8, 22, 64, true, crowdTexture, 2, false, normal);
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslated(8.0, -2.0, 0.0);
    glRotated(90.0, 0, 0, 1);
    drawWall(8, 22, 64, true, crowdTexture, 2, false, normal);
    glPopMatrix();

    //Back
    glPushMatrix();
    glTranslated(-8.0, 6.0, 0.0);
    glRotated(90.0, 1, 0, 0);
    drawWall(16, 8, 64, true, crowdTexture, 2, false, normal);
    glPopMatrix();
}
