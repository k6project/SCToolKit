/****************************************************************************
** Meta object code from reading C++ file 'TextureTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/TextureTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextureTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TextureTool_t {
    QByteArrayData data[6];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextureTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextureTool_t qt_meta_stringdata_TextureTool = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TextureTool"
QT_MOC_LITERAL(1, 12, 10), // "BaseDirSet"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "EntriesUpdated"
QT_MOC_LITERAL(4, 39, 13), // "ImageImported"
QT_MOC_LITERAL(5, 53, 16) // "SaveCurrentEntry"

    },
    "TextureTool\0BaseDirSet\0\0EntriesUpdated\0"
    "ImageImported\0SaveCurrentEntry"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextureTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,
       4,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void TextureTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextureTool *_t = static_cast<TextureTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->BaseDirSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->EntriesUpdated(); break;
        case 2: _t->ImageImported(); break;
        case 3: _t->SaveCurrentEntry(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TextureTool::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextureTool::BaseDirSet)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TextureTool::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextureTool::EntriesUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TextureTool::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextureTool::ImageImported)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TextureTool::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TextureTool.data,
      qt_meta_data_TextureTool,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TextureTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextureTool::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TextureTool.stringdata0))
        return static_cast<void*>(const_cast< TextureTool*>(this));
    return QObject::qt_metacast(_clname);
}

int TextureTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TextureTool::BaseDirSet(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TextureTool::EntriesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TextureTool::ImageImported()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
