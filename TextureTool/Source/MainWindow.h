#pragma once

#include <QMainWindow>

class TextureTool;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:

    MainWindow(TextureTool *_model, QWidget *_parent = 0);

    ~MainWindow();

private:

    TextureTool *AppModel;

    Ui::MainWindow *UI;

};
