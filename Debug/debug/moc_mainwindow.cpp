/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled4/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "sendToggleStream"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 25), // "sendEnableBinaryThreshold"
QT_MOC_LITERAL(4, 55, 5), // "state"
QT_MOC_LITERAL(5, 61, 18), // "sendThresholdValue"
QT_MOC_LITERAL(6, 80, 5), // "value"
QT_MOC_LITERAL(7, 86, 10), // "sendValues"
QT_MOC_LITERAL(8, 97, 7), // "AreaRef"
QT_MOC_LITERAL(9, 105, 10), // "OffsetArea"
QT_MOC_LITERAL(10, 116, 14), // "OfssetPosition"
QT_MOC_LITERAL(11, 131, 7), // "PointOK"
QT_MOC_LITERAL(12, 139, 21), // "receiveFrame_original"
QT_MOC_LITERAL(13, 161, 8), // "original"
QT_MOC_LITERAL(14, 170, 22), // "receiveFrame_processed"
QT_MOC_LITERAL(15, 193, 9), // "processed"
QT_MOC_LITERAL(16, 203, 19), // "receiveToggleStream"
QT_MOC_LITERAL(17, 223, 25), // "receiveToggleProcessImage"
QT_MOC_LITERAL(18, 249, 23), // "changelblThresholdValue"
QT_MOC_LITERAL(19, 273, 12), // "UDPReadyRead"
QT_MOC_LITERAL(20, 286, 7), // "UDPSend"
QT_MOC_LITERAL(21, 294, 8), // "uiValues"
QT_MOC_LITERAL(22, 303, 13), // "ReceiveStatus"
QT_MOC_LITERAL(23, 317, 6), // "result"
QT_MOC_LITERAL(24, 324, 8), // "N_points"
QT_MOC_LITERAL(25, 333, 10) // "NOK_points"

    },
    "MainWindow\0sendToggleStream\0\0"
    "sendEnableBinaryThreshold\0state\0"
    "sendThresholdValue\0value\0sendValues\0"
    "AreaRef\0OffsetArea\0OfssetPosition\0"
    "PointOK\0receiveFrame_original\0original\0"
    "receiveFrame_processed\0processed\0"
    "receiveToggleStream\0receiveToggleProcessImage\0"
    "changelblThresholdValue\0UDPReadyRead\0"
    "UDPSend\0uiValues\0ReceiveStatus\0result\0"
    "N_points\0NOK_points"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       5,    1,   83,    2, 0x06 /* Public */,
       7,    4,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,
      21,    0,  106,    2, 0x08 /* Private */,
      22,    3,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,   13,
    QMetaType::Void, QMetaType::QImage,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Int,   23,   24,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToggleStream(); break;
        case 1: _t->sendEnableBinaryThreshold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendThresholdValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->receiveFrame_original((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->receiveFrame_processed((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 6: _t->receiveToggleStream(); break;
        case 7: _t->receiveToggleProcessImage(); break;
        case 8: _t->changelblThresholdValue(); break;
        case 9: _t->UDPReadyRead(); break;
        case 10: _t->UDPSend(); break;
        case 11: _t->uiValues(); break;
        case 12: _t->ReceiveStatus((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendToggleStream)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendEnableBinaryThreshold)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendThresholdValue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendValues)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendToggleStream()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::sendEnableBinaryThreshold(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sendThresholdValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendValues(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
