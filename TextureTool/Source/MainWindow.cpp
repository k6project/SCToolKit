#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TextureTool.h"

MainWindow::MainWindow(TextureTool *_model, QWidget *_parent)
    : QMainWindow(_parent)
    , AppModel(_model)
    , UI(new Ui::MainWindow)
{
    UI->setupUi(this);
    connect(AppModel, &TextureTool::BaseDirSet, UI->ActionImportImage, &QAction::setEnabled);
    UI->ActionImportImage->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete UI;
}
