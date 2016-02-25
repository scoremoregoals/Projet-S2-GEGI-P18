#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pbStartGame_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *keyevent);
};

#endif // MAINWINDOW_H
