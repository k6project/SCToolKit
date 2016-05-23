#include "AddTextureDlg.h"
#include "ui_AddTextureDlg.h"
#include "TextureTool.h"

#include <QtGui/QFont>
#include <QtCore/QRegExp>
#include <QtWidgets/QPushButton>

AddTextureDlg::AddTextureDlg(TextureTool *_appModel, QWidget *_parent)
    : QDialog(_parent)
    , UI(new Ui::AddTextureDlg)
    , AppModel(_appModel)
{
    UI->setupUi(this);
    connect(UI->TextureId, &QLineEdit::textChanged, this, &AddTextureDlg::OnTextureIdChange);
    QFont font = UI->TextureId->font();
    font.setCapitalization(QFont::AllUppercase);
    UI->TextureId->setFont(font);
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
    UI->Height->setText(QString("%1px").arg(entry.Height));
    UI->Width->setText(QString("%1px").arg(entry.Width));
    show();
}

void AddTextureDlg::OnTextureIdChange(const QString &_id)
{
    QString errorMsg;
    bool enable = true;
    QPushButton *okButton = UI->buttonBox->button(QDialogButtonBox::Ok);
    if (_id.isEmpty())
    {
        enable = false;
        errorMsg = "Texture ID can't be empty";
    }
    else
    {
        QString id = "TEX_" + _id.toUpper();
        if (AppModel->HasTextureWithId(id))
        {
            enable = false;
            errorMsg = "Texture ID must be unique";
        }
        else if (!AppModel->IsValidId(id))
        {
            enable = false;
            errorMsg = "Texture ID must contain only letters, numbers and underscores";
        }
        else
        {
            AppModel->AssignCurrentEntryId(id);
        }
    }
    UI->TextureId->setStyleSheet((enable) ? "" : "color: #ff0000");
    UI->ErrorMsg->setText(errorMsg);
    okButton->setEnabled(enable);
}
