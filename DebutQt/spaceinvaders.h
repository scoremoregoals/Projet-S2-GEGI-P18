#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <QMainWindow>

namespace Ui {
class SpaceInvaders;
}

class SpaceInvaders : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpaceInvaders(QWidget *parent = 0);
    ~SpaceInvaders();

private:
    Ui::SpaceInvaders *ui;
};

#endif // SPACEINVADERS_H
