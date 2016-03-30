#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
	delete _platform;
}


void MainWindow::on_pbStartGame_clicked()
{
    std::cout << "The game is starting - from the push button" << std::endl;
	this->hide();
	_platform->set_inputMode(ui->comboBox->currentIndex());
	_platform->initialize();
	//set options to platform (game)
}

void MainWindow::keyPressEvent(QKeyEvent *keyevent)
{
    if(keyevent->key() == Qt::Key_W)
        std::cout << "Key Up pressed" << std::endl;
    else if(keyevent->key() == Qt::Key_S)
        std::cout << "Key Down pressed" << std::endl;
    else if(keyevent->key() == Qt::Key_A)
        std::cout << "Key Left pressed" << std::endl;
    else if(keyevent->key() == Qt::Key_D)
        std::cout << "Key Right pressed" << std::endl;
}

void MainWindow::set_platform(Platform* platform)
{
	_platform = platform;
}
