#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T15:51:50
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ObjLoader
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ObjLoader.cpp \
    Scene.cpp

HEADERS  += MainWindow.h \
    ObjLoader.h \
    Scene.h

FORMS    += MainWindow.ui
