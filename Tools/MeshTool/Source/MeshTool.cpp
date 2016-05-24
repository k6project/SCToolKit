#include "MeshTool.h"
#include "MeshToolView.h"

#include "QtWidgets/QApplication"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MeshToolView w;
    w.show();
    return a.exec();
}
