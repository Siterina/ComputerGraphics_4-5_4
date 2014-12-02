#include "myglwidget.h"

#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>

#define pi 3.1415

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    R = 1, G = 1, B  = 1;
    radius = 1, count = 20;

}

QVector3D MyGLWidget::figurePoint(double phi, double psi) {
    QVector3D temp;
    temp.setX((double)(radius * sin(phi) * cos(psi)));
    temp.setY((double)(radius * sin(phi) * sin(psi)));
    temp.setZ((double)(radius * cos(phi)));
    return temp;
}

void MyGLWidget::addToMassive(QVector <QVector3D> tempPoint){
    for(int i = 0; i < 4; i++) {
        vertex.push_back(tempPoint[i].x());
        vertex.push_back(tempPoint[i].y());
        vertex.push_back(tempPoint[i].z());
        // normal
        index.push_back(index.size());
        qDebug() << tempPoint[i].x() << endl;
        qDebug() << tempPoint[i].y() << endl;
        qDebug() << tempPoint[i].z() << endl;
    }
}

void MyGLWidget::countFigurePoints() {
    double step_phi = pi / count / 2;
    double step_psi = pi / count * 2;
    double phi = pi/360;
    double psi = pi/360;
    QVector <QVector3D> tempPoint;
    for(int i = 0; i < count; phi += step_phi, i++) {
        psi = 0;
        for(int j = 0; j < count; psi += step_psi, j++) {

         tempPoint.push_back(figurePoint(phi, psi));
         tempPoint.push_back(figurePoint(phi + step_phi, psi));
         tempPoint.push_back(figurePoint(phi + step_phi, psi + step_psi));
         tempPoint.push_back(figurePoint(phi, psi + step_psi));

         addToMassive(tempPoint);
         tempPoint.clear();
        }

    }


}

void MyGLWidget::initializeGL() {

    //qglClearColor(Qt::black);
    glClearColor(R, G, B, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    countFigurePoints();
    qDebug() << "true" << endl;
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

   //static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL() {



    //glEnable(GL_NORMALIZE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();






    glClearColor(R, G, B, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertex.data());
    //glNormalPointer(GL_FLOAT,0,normal.data());
    qglColor(Qt::red);
    //glBegin(GL_QUADS);
    glDrawElements(GL_QUADS,index.size(),GL_UNSIGNED_INT,index.data());

}

void MyGLWidget::resizeGL(int width, int height){
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}


void MyGLWidget::setXRotation(int angle) {
    R = (double)angle / 255;
    updateGL();
}

void MyGLWidget::setYRotation(int angle) {
    G = (double)angle / 255;
    updateGL();
}

void MyGLWidget::setZRotation(int angle) {
    B = (double)angle / 255;
    updateGL();
}
