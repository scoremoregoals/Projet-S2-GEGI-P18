#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewidgetgl.h"

#include <iostream>
#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include<QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void menuAbout();
    void menuStartGame();
    void menuSettings();
    void menuClose();

private:
    Ui::MainWindow *ui;

    // Keypress event
    void keyPressEvent(QKeyEvent *keyevent);



protected:
    //Opengl protected functions
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

};

#endif // MAINWINDOW_H
