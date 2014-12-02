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
    void addToMassive(QVector <QVector3D> tempPoint, QVector3D n);
    void countFigurePoints();

private:

    double xRot;
    double yRot;
    double zRot;

    double xMove;
    double yMove;
    double zMove;

    double xScale;
    double yScale;
    double zScale;

    double xLightPos;
    double yLightPos;
    double zLightPos;

    double xMaterialColor;
    double yMaterialColor;
    double zMaterialColor;

    double xLightColor;
    double yLightColor;
    double zLightColor;

    double materialShiness;

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

    void moveXDirection(int shift);
    void moveYDirection(int shift);
    void moveZDirection(int shift);

    void scaleXDirection(int scale);
    void scaleYDirection(int scale);
    void scaleZDirection(int scale);

    void setXLightPos(int position);
    void setYLightPos(int position);
    void setZLightPos(int position);

    void setXMaterialColor(int color);
    void setYMaterialColor(int color);
    void setZMaterialColor(int color);

    void setXLightColor(int color);
    void setYLightColor(int color);
    void setZLightColor(int color);

    void setMaterialShiness(int intence);

    void setApproximation(int aCount);

};

#endif // MYGLWIDGET_H
