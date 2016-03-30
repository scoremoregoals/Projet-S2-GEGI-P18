#include <iostream>
#include <ctime> 
#include <QApplication>

#include "platform.h"
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

















