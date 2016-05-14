#pragma once

#include <QObject>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>

class TextureTool : public QObject
{
    Q_OBJECT

public:

    explicit TextureTool(QObject *parent = 0);

signals:

    void BaseDirSet(bool);

public slots:

private:

    QDir BaseDir;

};
