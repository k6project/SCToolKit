#pragma once

#include <QtCore/QObject>
#include <QtCore/QDir>
#include <QtCore/QVector>

class QImage;

struct TextureEntry
{
    QString textureId;
    QString texturePath;
};

class TextureTool : public QObject
{
    Q_OBJECT

public:

    explicit TextureTool(QObject *parent = 0);

    ~TextureTool();

    int GetNumTextureEntries() const;

    const TextureEntry & GetTextureEntry(int _index) const;

    const TextureEntry & GetCurrentEntry() const;

    void SetBaseDir(const QString &_baseDirPath);

    void ImportImageFile(const QString &_path);

    void UpdateEntries();

signals:

    void BaseDirSet(bool);

    void EntriesUpdated();

    void ImageImported();

public slots:

private:

    QVector<TextureEntry> TextureEntries;

    TextureEntry *CurrentEntry = nullptr;

    QImage *CurrentImage = nullptr;

    QDir BaseDir;

};
