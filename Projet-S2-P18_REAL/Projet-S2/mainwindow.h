#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include<QKeyEvent>
#include "platform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void set_platform(Platform* platform);


private slots:
    void on_pbStartGame_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *keyevent);
	Platform* _platform;
	
};

#endif // MAINWINDOW_H
