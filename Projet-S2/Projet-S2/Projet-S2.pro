#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T14:43:54
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet-S2
TEMPLATE = vcapp
CONFIG      += warn_on qt debug_and_release windows console
SOURCES += main.cpp mainwindow.cpp obstacle.cpp platform.cpp Hlaser.cpp id.cpp liste.cpp powerUp.cpp Vlaser.cpp rectangle.cpp runner.cpp player.cpp global.cpp Text.cpp animation.cpp
HEADERS += mainwindow.h obstacle.h platform.h powerUp.h Hlaser.h id.h liste.h Vlaser.h rectangle.h runner.h player.h global.h Text.h animation.h

FORMS    += mainwindow.ui