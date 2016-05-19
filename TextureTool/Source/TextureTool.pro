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
    AddTextureDlg.cpp \
    ../../Shared/AssetUtils/AssetLoader.cpp \
    ../../Shared/AssetUtils/AssetTypes.cpp \
    ../../Shared/Platform/Memory.cpp

HEADERS  += MainWindow.h \
    TextureTool.h \
    ../../Shared/Platform/IntTypes.h \
    ../../Shared/Platform/IO.h \
    AddTextureDlg.h \
    ../../Shared/AssetUtils/AssetFlags.h \
    ../../Shared/AssetUtils/AssetLoader.h \
    ../../Shared/AssetUtils/AssetTypes.h \
    ../../Shared/Platform/Memory.h

INCLUDEPATH += ../../Shared

DEFINES += WITH_EDITOR

FORMS    += MainWindow.ui \
    AddTextureDlg.ui
