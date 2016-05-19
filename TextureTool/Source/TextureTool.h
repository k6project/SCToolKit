#pragma once

#include "Platform/IntTypes.h"

#include <QtCore/QObject>
#include <QtCore/QDir>
#include <QtCore/QRegExp>
#include <QtCore/QVector>
#include <QtCore/QStringList>

class QImage;

struct TextureEntry
{
    QString textureId;
    QString texturePath;
    uint32 Width, Height, Flags;
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

    bool HasTextureWithId(const QString &_id);

    void SetCurrentEntryByIndex(int _index);

    void AssignCurrentEntryId(const QString &_id);

    bool IsValidId(const QString &_id) const;

    void UpdateEntries();

signals:

    void BaseDirSet(bool);

    void EntriesUpdated();

    void ImageImported();

public slots:

    void SaveCurrentEntry();

private:

    QVector<TextureEntry> TextureEntries;

    TextureEntry *CurrentEntry = nullptr;

    QImage *CurrentImage = nullptr;

    QStringList TextureIds;

    QRegExp IdValidRegExp;

    QDir BaseDir;

};
