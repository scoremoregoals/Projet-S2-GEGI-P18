#include <iostream>
#include <ctime> 
#include <QApplication>

#include "platform.h"
#include "vector2.h"
#include "runner.h"
#include "obstacle.h"
#include "Hlaser.h"
#include "Vlaser.h"
#include "powerUp.h"
#include "id.h"
#include "mainwindow.h"


using namespace std;

int main(int argc, char *argv[])
{ 
	QApplication a(argc, argv);

	Platform* platform = new Platform();

	MainWindow w;
	w.set_platform(platform);
	w.show();

	srand(time(NULL));


	return a.exec();
}

















