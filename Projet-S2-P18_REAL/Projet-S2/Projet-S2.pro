QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet-S2
TEMPLATE = vcapp
CONFIG      += warn_on qt debug_and_release windows console

SOURCES += main.cpp mainwindow.cpp obstacle.cpp platform.cpp Hlaser.cpp liste.cpp powerUp.cpp Vlaser.cpp rectangle.cpp runner.cpp global.cpp Text.cpp animation.cpp background.cpp

HEADERS += mainwindow.h obstacle.h platform.h powerUp.h Hlaser.h liste.h Vlaser.h rectangle.h runner.h global.h Text.h animation.h background.h

INCLUDEPATH += ../CommunicationFPGA
LIBS	    += ../CommunicationFPGA/CommunicationFPGA.lib
FORMS    += mainwindow.ui