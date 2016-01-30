#include "spaceinvaders.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpaceInvaders w;
    w.show();

    return a.exec();
}
