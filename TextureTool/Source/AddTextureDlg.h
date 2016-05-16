#pragma once

#include <QDialog>

class TextureTool;

namespace Ui
{
    class AddTextureDlg;
}

class AddTextureDlg : public QDialog
{

    Q_OBJECT

public:

    explicit AddTextureDlg(TextureTool *_appModel, QWidget *_parent = 0);

    ~AddTextureDlg();

public slots:

    void Show();

private:

    Ui::AddTextureDlg *UI = nullptr;

    TextureTool *AppModel = nullptr;

};
