#include "TextureTool.h"
#include "MainWindow.h"
#include "Platform/IO.h"
#include "Platform/IntTypes.h"
#include "AssetUtils/AssetTypes.h"
#include "AssetUtils/AssetLoader.h"

#include <QtWidgets/QApplication>
#include <QtCore/QDirIterator>
#include <QtCore/QFileInfo>
#include <QtCore/QBuffer>
#include <QtCore/QFile>

TextureTool::TextureTool(QObject *parent)
    : QObject(parent)
{
    IdValidRegExp.setPattern("[0-9A-Z_]+");
}

TextureTool::~TextureTool()
{
    if (CurrentEntry != nullptr && CurrentEntry->texturePath.isEmpty())
    {
        delete CurrentEntry;
    }
}

int TextureTool::GetNumTextureEntries() const
{
    return TextureEntries.size();
}

const QImage &TextureTool::GetCurrentImage() const
{
    return CurrentImage;
}

const TextureEntry &TextureTool::GetTextureEntry(int _index) const
{
    static const TextureEntry invalid = { 0, 0, 0, 0, 0 };
    if (_index >= 0 && _index < TextureEntries.size())
    {
        return TextureEntries[_index];
    }
    return invalid;
}

const TextureEntry &TextureTool::GetCurrentEntry() const
{
    static const TextureEntry invalid = { 0, 0, 0, 0, 0 };
    if (CurrentEntry != nullptr)
    {
        return *CurrentEntry;
    }
    return invalid;
}

void TextureTool::SetBaseDir(const QString &_baseDirPath)
{
    BaseDir.setPath(_baseDirPath);
    BaseDir.mkdir("Textures");
    if (BaseDir.cd("Textures"))
    {
        QDir::setCurrent(BaseDir.absolutePath());
        UpdateEntries();
        emit(BaseDirSet(true));
    }
}

void TextureTool::ImportImageFile(const QString &_path)
{
    QImage loadedImage;
    QFileInfo fileInfo(_path);
    loadedImage.load(_path);

    switch (loadedImage.bitPlaneCount())
    {
    case 1:
    case 8:
    case 16:
    case 24:
        CurrentImage = loadedImage.convertToFormat(QImage::Format_RGB888);
        break;
    case 32:
        CurrentImage = loadedImage.convertToFormat(QImage::Format_ARGB32);
        break;
    };

    CurrentEntry = new TextureEntry();
    CurrentEntry->textureId = QString("TEX_%1").arg(fileInfo.baseName().toUpper().left(250));
    CurrentEntry->Height = CurrentImage.height();
    CurrentEntry->Width = CurrentImage.width();
    emit(ImageImported());
}

bool TextureTool::HasTextureWithId(const QString &_id)
{
    return TextureIds.contains(_id);
}

void TextureTool::SetCurrentEntryByIndex(int _index)
{
    TextureAsset asset;
    if (_index >= 0 && _index < GetNumTextureEntries())
    {
        CurrentEntry = &TextureEntries[_index];
        if (LoadAsset(CurrentEntry->texturePath.toLocal8Bit(), asset))
        {
            CurrentImage.loadFromData(asset.Buffer, asset.NumBytes, "PNG");
            emit(ImageLoaded());
        }
    }
}

void TextureTool::AssignCurrentEntryId(const QString &_id)
{
    CurrentEntry->textureId = _id;
}

bool TextureTool::IsValidId(const QString &_id) const
{
    return IdValidRegExp.exactMatch(_id);
}

void TextureTool::SaveCurrentEntry()
{
    QFile outFile;
    uint32 pngSize = 0;
    bool prevUnderscore = true;
    QByteArray imgOut, header;
    QBuffer imgBuffer(&imgOut);

    imgBuffer.open(QIODevice::WriteOnly);
    CurrentImage.save(&imgBuffer, "PNG");
    pngSize = imgBuffer.size() & 0xFFFFFFFFu;
    imgBuffer.close();

    uint8 len = CurrentEntry->textureId.length() & ((uint8)0xFF);
    QByteArray texId = CurrentEntry->textureId.toLatin1();
    header.append(37).append(99).append(51).append(len);
    for (int i = 0; i < texId.size(); i++)
    {
        header.append(texId.at(i) ^ len);
    }
    texId.remove(0, 4);
    for (int i = 0; i < texId.size(); i++)
    {
        QChar symbol(texId[i]);
        if (symbol.isLetter(texId[i]))
        {
            if (prevUnderscore)
            {
                prevUnderscore = false;
            }
            else
            {
                char chr = symbol.toLower().toLatin1();
                texId.replace(i, 1, &chr, 1);
            }
        }
        else if (texId[i] == '_')
        {
            prevUnderscore = true;
        }
    }
    header.append((const char *)&CurrentEntry->Width, 4);
    header.append((const char *)&CurrentEntry->Height, 4);
    header.append((const char *)&CurrentEntry->Flags, 4);
    header.append((const char *)&pngSize, 4);

    outFile.setFileName(QString("%1.tex").arg(QString(texId)));
    if (!outFile.exists())
    {
        outFile.open(QIODevice::WriteOnly);
        outFile.write(header);
        outFile.write(imgOut);
        outFile.close();
    }

    delete CurrentEntry;
    CurrentEntry = nullptr;
    UpdateEntries();
}

void TextureTool::UpdateEntries()
{
    TextureIds.clear();
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
                    TextureIds.append(entry.textureId);
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
