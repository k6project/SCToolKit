#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T22:01:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextureTool
TEMPLATE = app


SOURCES +=\
        MainWindow.cpp \
    TextureTool.cpp \
    ../../Shared/Platform/IO.cpp \
    AddTextureDlg.cpp

HEADERS  += MainWindow.h \
    TextureTool.h \
    ../../Shared/Platform/IntTypes.h \
    ../../Shared/Platform/IO.h \
    AddTextureDlg.h

INCLUDEPATH += ../../Shared

FORMS    += MainWindow.ui \
    AddTextureDlg.ui
