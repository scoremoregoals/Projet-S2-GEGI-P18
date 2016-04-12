QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet-S2
TEMPLATE = vcapp
CONFIG      += warn_on qt debug_and_release windows console

SOURCES += Sources/main.cpp Sources/mainwindow.cpp Sources/obstacle.cpp Sources/platform.cpp Sources/Hlaser.cpp Sources/liste.cpp Sources/powerUp.cpp Sources/Vlaser.cpp Sources/rectangle.cpp Sources/runner.cpp Sources/global.cpp Sources/Text.cpp Sources/animation.cpp Sources/background.cpp Sources/explosion.cpp

HEADERS += Headers/mainwindow.h Headers/obstacle.h Headers/platform.h Headers/powerUp.h Headers/Hlaser.h Headers/liste.h Headers/Vlaser.h Headers/rectangle.h Headers/runner.h Headers/global.h Headers/Text.h Headers/animation.h Headers/background.h Headers/explosion.h

INCLUDEPATH += ../CommunicationFPGA
LIBS	    += ../CommunicationFPGA/CommunicationFPGA.lib