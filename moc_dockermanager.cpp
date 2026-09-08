/****************************************************************************
** Meta object code from reading C++ file 'dockermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/dockermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dockermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DockerManager_t {
    QByteArrayData data[19];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DockerManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DockerManager_t qt_meta_stringdata_DockerManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DockerManager"
QT_MOC_LITERAL(1, 14, 8), // "logReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "log"
QT_MOC_LITERAL(4, 28, 20), // "chunkProgressUpdated"
QT_MOC_LITERAL(5, 49, 7), // "current"
QT_MOC_LITERAL(6, 57, 5), // "total"
QT_MOC_LITERAL(7, 63, 12), // "taskFinished"
QT_MOC_LITERAL(8, 76, 8), // "exitCode"
QT_MOC_LITERAL(9, 85, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(10, 106, 10), // "exitStatus"
QT_MOC_LITERAL(11, 117, 13), // "errorOccurred"
QT_MOC_LITERAL(12, 131, 8), // "errorMsg"
QT_MOC_LITERAL(13, 140, 25), // "onReadyReadStandardOutput"
QT_MOC_LITERAL(14, 166, 24), // "onReadyReadStandardError"
QT_MOC_LITERAL(15, 191, 17), // "onProcessFinished"
QT_MOC_LITERAL(16, 209, 14), // "onProcessError"
QT_MOC_LITERAL(17, 224, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(18, 247, 5) // "error"

    },
    "DockerManager\0logReady\0\0log\0"
    "chunkProgressUpdated\0current\0total\0"
    "taskFinished\0exitCode\0QProcess::ExitStatus\0"
    "exitStatus\0errorOccurred\0errorMsg\0"
    "onReadyReadStandardOutput\0"
    "onReadyReadStandardError\0onProcessFinished\0"
    "onProcessError\0QProcess::ProcessError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DockerManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    2,   57,    2, 0x06 /* Public */,
       7,    2,   62,    2, 0x06 /* Public */,
      11,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   70,    2, 0x08 /* Private */,
      14,    0,   71,    2, 0x08 /* Private */,
      15,    2,   72,    2, 0x08 /* Private */,
      16,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void DockerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DockerManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->chunkProgressUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->taskFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 3: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onReadyReadStandardOutput(); break;
        case 5: _t->onReadyReadStandardError(); break;
        case 6: _t->onProcessFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->onProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DockerManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DockerManager::logReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DockerManager::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DockerManager::chunkProgressUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DockerManager::*)(int , QProcess::ExitStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DockerManager::taskFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DockerManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DockerManager::errorOccurred)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DockerManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DockerManager.data,
    qt_meta_data_DockerManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DockerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DockerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DockerManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DockerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DockerManager::logReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DockerManager::chunkProgressUpdated(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DockerManager::taskFinished(int _t1, QProcess::ExitStatus _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DockerManager::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
