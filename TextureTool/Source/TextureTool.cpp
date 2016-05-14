#include "TextureTool.h"
#include "MainWindow.h"

#include <QApplication>

TextureTool::TextureTool(QObject *parent)
    : QObject(parent)
{
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextureTool app;
    MainWindow w(&app);
    w.show();
    return a.exec();
}
