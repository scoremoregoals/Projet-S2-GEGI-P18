#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Menu buttons
    connect(ui->menuAbout, SIGNAL(triggered()), this, SLOT(menuAbout()));
    connect(ui->menuStartGame, SIGNAL(triggered()), this, SLOT(menuStartGame()));
    connect(ui->menuSettings, SIGNAL(triggered()), this, SLOT(menuSettings()));
    connect(ui->menuClose, SIGNAL(triggered()), this, SLOT(menuClose()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::menuAbout()
{
    std::cout << "Entering in menuAbout button" << std::endl;
    QMessageBox::about(this, "About Game", "This is our game, it's a 2D base game. The player controler the runner by using phonemes.........");
}

void MainWindow::menuStartGame()
{
    std::cout << "Entering in menuStartGame button" << std::endl;
    std::cout << "Game is starting" << std::endl;
    // Go to game tab before starting the game
    ui->tabApps->setCurrentIndex(0);
}

void MainWindow::menuSettings()
{
    std::cout << "Entering in menuSettings button" << std::endl;
    // Go to the settings tab index 1
    ui->tabApps->setCurrentIndex(1);
}

void MainWindow::menuClose()
{
    std::cout << "Entering in menuClose button" << std::endl;
    close();
}


// Keypress Event
void MainWindow::keyPressEvent(QKeyEvent *keyevent)
{
    // Normal application settings
    if(keyevent->key() == Qt::Key_Escape){
        std::cout << "Application is closing" << std::endl;
        close();
    }
    else if(keyevent->key() == Qt::Key_S && QApplication::keyboardModifiers() && Qt::ControlModifier)
    {
        std::cout << "Game is starting" << std::endl;
        ui->tabApps->setCurrentIndex(0);
    }

    // In-game controls
   else  if(keyevent->key() == Qt::Key_W)
        std::cout << "Key Up pressed" << std::endl;
    else if(keyevent->key() == Qt::Key_S)
        std::cout << "Key Down pressed" << std::endl;
    else if(keyevent->key() == Qt::Key_A)
        std::cout << "Key Left pressed" << std::endl;
    else if(keyevent->key() == Qt::Key_D)
        std::cout << "Key Right pressed" << std::endl;
}

