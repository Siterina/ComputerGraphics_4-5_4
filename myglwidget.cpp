#include "myglwidget.h"

#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>

#define pi 3.1415

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //R = 1, G = 1, B  = 1;
    radius = 1, count = 20;
    xRot = 0, yRot = 0, zRot = 0;
    xMove = 0, yMove = 0, zMove = 0;
    xScale = 1, yScale = 1, zScale = 1;
    xLightPos = 0, yLightPos = 0, zLightPos = 10;
    xMaterialColor = 0.5, yMaterialColor = 0.5, zMaterialColor = 0.1;
    xLightColor = 1, yLightColor = 1, zLightColor = 1;
    materialShiness = 0;


}

QVector3D MyGLWidget::figurePoint(double phi, double psi) {
    QVector3D temp;
    temp.setX((double)(radius * sin(phi) * cos(psi)));
    temp.setY((double)(radius * sin(phi) * sin(psi)));
    temp.setZ((double)(radius * cos(phi)));
    return temp;
}

void MyGLWidget::addToMassive(QVector <QVector3D> tempPoint, QVector3D n){
    for(int i = 0; i < 4; i++) {
        vertex.push_back(tempPoint[i].x());
        vertex.push_back(tempPoint[i].y());
        vertex.push_back(tempPoint[i].z());
        // normal
        normal.push_back(n.x());
        normal.push_back(n.y());
        normal.push_back(n.z());

        index.push_back(index.size());
       // qDebug() << tempPoint[i].x() << endl;
       // qDebug() << tempPoint[i].y() << endl;
       // qDebug() << tempPoint[i].z() << endl;
    }
}

void MyGLWidget::countFigurePoints() {

    vertex.clear();
    normal.clear();
    index.clear();
    double step_phi = pi / count / 2;
    double step_psi = pi / count * 2;
    double phi = pi/360;
    double psi = 0;
    QVector <QVector3D> tempPoint;
    QVector3D n;
    for(int i = 0; i < count; phi += step_phi, i++) {
        psi = 0;
        for(int j = 0; j < count; psi += step_psi, j++) {

         tempPoint.push_back(figurePoint(phi, psi));
         tempPoint.push_back(figurePoint(phi + step_phi, psi));
         tempPoint.push_back(figurePoint(phi + step_phi, psi + step_psi));
         tempPoint.push_back(figurePoint(phi, psi + step_psi));

         n = QVector3D::normal(tempPoint[1] - tempPoint[0], tempPoint[3] - tempPoint[0]);

         addToMassive(tempPoint, n);
         tempPoint.clear();
        }

    }


}

void MyGLWidget::initializeGL() {

    //qglClearColor(Qt::black);
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    countFigurePoints();
    qDebug() << "true" << endl;



}

void MyGLWidget::paintGL() {

    countFigurePoints();
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    static GLfloat lightPosition[4] = { 2, 0, 10, 1.0 };
     glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

     glRotatef(-xRot,1,0,0);
     glRotatef(yRot,0,1,0);
     glRotatef(-zRot,0,0,1);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertex.data());
    glNormalPointer(GL_FLOAT,0,normal.data());
    qglColor(Qt::red);

    glDrawElements(GL_QUADS,index.size(),GL_UNSIGNED_INT,index.data());

}

void MyGLWidget::resizeGL(int width, int height){
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

/*******************************************/
/*                Slots                    */
/*******************************************/


void MyGLWidget::setXRotation(int angle) {
    xRot = (double)angle;
    updateGL();
}

void MyGLWidget::setYRotation(int angle) {
    yRot = (double)angle;
    updateGL();
}

void MyGLWidget::setZRotation(int angle) {
    zRot = (double)angle;
    updateGL();
}

void MyGLWidget::moveXDirection(int shift) {

}

void MyGLWidget::moveYDirection(int shift) {

}

void MyGLWidget::moveZDirection(int shift) {

}

void MyGLWidget::scaleXDirection(int scale) {

}

void MyGLWidget::scaleYDirection(int scale) {

}

void MyGLWidget::scaleZDirection(int scale) {

}

void MyGLWidget::setXLightPos(int position) {

}

void MyGLWidget::setYLightPos(int position) {

}

void MyGLWidget::setZLightPos(int position) {

}

void MyGLWidget::setXMaterialColor(int color) {

}

void MyGLWidget::setYMaterialColor(int color) {

}

void MyGLWidget::setZMaterialColor(int color) {

}

void MyGLWidget::setXLightColor(int color) {

}

void MyGLWidget::setYLightColor(int color) {

}

void MyGLWidget::setZLightColor(int color) {

}

void MyGLWidget::setMaterialShiness(int intence) {

}

void MyGLWidget::setApproximation(int aCount) {
    count = aCount;
    qDebug() << "tu" << endl;
    updateGL();
}
