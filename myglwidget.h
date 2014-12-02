#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    QVector3D figurePoint(double phi, double psi);
    void addToMassive(QVector <QVector3D> tempPoint);
    void countFigurePoints();

private:

    int xRot;
    int yRot;
    int zRot;

    double R;
    double G;
    double B;

    double radius;
    double count;

    QVector <GLfloat> vertex;
    QVector <GLfloat> normal;
    QVector <GLuint> index;


signals:

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

};

#endif // MYGLWIDGET_H
