#pragma once

#include <QtGui/QImage>
#include <QtWidgets/QMainWindow>

class QLabel;
class TextureTool;
class AddTextureDlg;

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

public slots:

    void OnSetProjectDir();

    void OnImportImage();

    void OnListEntriesUpdate();

    void OnImageLoaded();

protected:

    virtual void showEvent(QShowEvent *) override;

private:

    TextureTool *AppModel;

    AddTextureDlg *AddTexDialog;

    Ui::MainWindow *UI;

    QLabel *TexCountLabel;

    QLabel *BaseDirLabel;

    QImage PreviewImage;

};
