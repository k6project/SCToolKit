#include "TextureTool.h"
#include "MainWindow.h"
#include "Platform/IO.h"
#include "Platform/IntTypes.h"

#include <QtWidgets/QApplication>
#include <QtCore/QDirIterator>
#include <QtCore/QFileInfo>

TextureTool::TextureTool(QObject *parent)
    : QObject(parent)
{
}

TextureTool::~TextureTool()
{
    if (CurrentImage != nullptr)
    {
        delete CurrentImage;
    }
    if (CurrentEntry != nullptr && CurrentEntry->texturePath.isEmpty())
    {
        delete CurrentEntry;
    }
}

int TextureTool::GetNumTextureEntries() const
{
    return TextureEntries.size();
}

const TextureEntry &TextureTool::GetTextureEntry(int _index) const
{
    static const TextureEntry invalid = { 0, 0 };
    if (_index >= 0 && _index < TextureEntries.size())
    {
        return TextureEntries[_index];
    }
    return invalid;
}

const TextureEntry &TextureTool::GetCurrentEntry() const
{
    static const TextureEntry invalid = { 0, 0 };
    if (CurrentEntry != nullptr)
    {
        return *CurrentEntry;
    }
    return invalid;
}

void TextureTool::SetBaseDir(const QString &_baseDirPath)
{
    BaseDir.setPath(_baseDirPath);
    UpdateEntries();
    emit(BaseDirSet(true));
}

void TextureTool::ImportImageFile(const QString &_path)
{
    QFileInfo fileInfo(_path);
    if (CurrentImage == nullptr)
    {
        CurrentImage = new QImage();
    }
    CurrentImage->load(_path);
    CurrentEntry = new TextureEntry();
    CurrentEntry->textureId = QString("TEX_%1").arg(fileInfo.baseName().toUpper());
    emit(ImageImported());
}

void TextureTool::UpdateEntries()
{
    TextureEntries.clear();
    TextureEntries.reserve(64);
    QDirIterator dirIt(BaseDir, QDirIterator::Subdirectories);
    while (dirIt.hasNext())
    {
        uint8 buffer[256];
        QString fileName = dirIt.next();
        if (fileName.endsWith(".tex", Qt::CaseInsensitive))
        {
            IO::File texFile;
            if (texFile.Open(fileName.toUtf8().data()))
            {
                TextureEntry entry;
                uint8 length = 0;
                texFile.Read(buffer, 4);
                if (buffer[0] == 37 && buffer[1] == 99 && buffer[2] == 51)
                {
                    length = buffer[3];
                    texFile.Read(buffer, length);
                    for (uint8 i = 0; i < length; i++ )
                    {
                        buffer[i] ^= length;
                    }
                    entry.textureId = QString::fromUtf8((const char *)buffer, length);
                    entry.texturePath = fileName;
                    TextureEntries.append(entry);
                }
                texFile.Close();
            }
        }
    }
    emit(EntriesUpdated());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextureTool app;
    MainWindow w(&app);
    w.showMaximized();
    return a.exec();
}
