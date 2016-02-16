#include "spaceinvaders.h"
#include "ui_spaceinvaders.h"

SpaceInvaders::SpaceInvaders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpaceInvaders)
{
    ui->setupUi(this);
}

SpaceInvaders::~SpaceInvaders()
{
    delete ui;
}
