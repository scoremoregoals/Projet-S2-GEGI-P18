#ifndef GAMEWIDGETGL_H
#define GAMEWIDGETGL_H

#include <iostream>

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <QPainter>


class GamePainter
{
public:
    GamePainter();
    ~GamePainter();

    void paint(QPainter *painter, QPaintEvent *event);

private:
    void drawBackground(QPainter *p);
    void init();

    QRadialGradient gradient;
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};

class Widget : public QWidget, public GamePainter
 {
     Q_OBJECT

 public:
     Widget(GamePainter *helper, QWidget *parent);

 public slots:
     void animate();

 protected:
     void paintEvent(QPaintEvent *event);

 private:
     GamePainter *helper;
     int elapsed;
 };
#endif // GAMEWIDGETGL_H
