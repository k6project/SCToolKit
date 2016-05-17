#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TextureTool.h"
#include "AddTextureDlg.h"
#include "Platform/IO.h"
#include "Platform/IntTypes.h"

#include <QtCore/QDirIterator>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFileDialog>

MainWindow::MainWindow(TextureTool *_model, QWidget *_parent)
    : QMainWindow(_parent)
    , AppModel(_model)
    , UI(new Ui::MainWindow)
{
    UI->setupUi(this);
    AddTexDialog = new AddTextureDlg(AppModel, this);
    TexCountLabel = new QLabel("Textures in project: 0");
    BaseDirLabel = new QLabel("No project selected");
    BaseDirLabel->setAlignment(Qt::AlignRight);
    UI->StatusBar->addPermanentWidget(TexCountLabel, 1);
    UI->StatusBar->addPermanentWidget(BaseDirLabel, 1);
    connect(AppModel, &TextureTool::BaseDirSet, UI->ActionImportImage, &QAction::setEnabled);
    connect(AppModel, &TextureTool::EntriesUpdated, this, &MainWindow::OnListEntriesUpdate);
    connect(UI->ActionSetCurrentProject, &QAction::triggered, this, &MainWindow::OnSetProjectDir);
    connect(UI->ActionImportImage, &QAction::triggered, this, &MainWindow::OnImportImage);
    connect(AppModel, &TextureTool::ImageImported, AddTexDialog, &AddTextureDlg::Show);
    connect(AddTexDialog, &AddTextureDlg::accepted, AppModel, &TextureTool::SaveCurrentEntry);
    UI->ActionImportImage->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete AddTexDialog;
    delete UI;
}

void MainWindow::OnSetProjectDir()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select project folder", QDir::homePath());
    AppModel->SetBaseDir(dir);
    BaseDirLabel->setText(QString("Project folder: %1").arg(dir));
}

void MainWindow::OnImportImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));
    AppModel->ImportImageFile(fileName);
}

void MainWindow::OnListEntriesUpdate()
{
    UI->ListWidget->clear();
    for (int i = 0; i < AppModel->GetNumTextureEntries(); i++)
    {
        UI->ListWidget->addItem(AppModel->GetTextureEntry(i).textureId);
    }
    TexCountLabel->setText(QString("Textures in project: %1").arg(AppModel->GetNumTextureEntries()));
}

void MainWindow::showEvent(QShowEvent *)
{
    QString dir = "/Users/Eugen/Work/GLInfo";
    AppModel->SetBaseDir(dir);
    BaseDirLabel->setText(QString("Project folder: %1").arg(dir));
}
