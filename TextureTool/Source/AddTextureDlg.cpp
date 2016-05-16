#include "AddTextureDlg.h"
#include "ui_AddTextureDlg.h"
#include "TextureTool.h"

AddTextureDlg::AddTextureDlg(TextureTool *_appModel, QWidget *_parent)
    : QDialog(_parent)
    , UI(new Ui::AddTextureDlg)
    , AppModel(_appModel)
{
    UI->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

AddTextureDlg::~AddTextureDlg()
{
    delete UI;
}

void AddTextureDlg::Show()
{
    const TextureEntry &entry = AppModel->GetCurrentEntry();
    UI->TextureId->setText(entry.textureId.mid(4));
    show();
}
