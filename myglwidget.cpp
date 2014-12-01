#include "myglwidget.h"


#include <QtWidgets>
#include <QtOpenGL>

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
}

void MyGLWidget::initializeGL() {

}

void MyGLWidget::paintGL() {

}

void MyGLWidget::resizeGL(int width, int height){

}


void MyGLWidget::setXRotation(int angle) {

}

void MyGLWidget::setYRotation(int angle) {

}

void MyGLWidget::setZRotation(int angle) {

}
