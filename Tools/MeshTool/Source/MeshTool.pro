#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T20:03:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MeshTool
TEMPLATE = app


SOURCES +=\
        MeshToolView.cpp \
    MeshTool.cpp

HEADERS  += MeshToolView.h \
    MeshTool.h

INCLUDEPATH += ../../../Engine

FORMS    += MeshToolView.ui
