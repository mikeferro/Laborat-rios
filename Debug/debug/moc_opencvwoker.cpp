/****************************************************************************
** Meta object code from reading C++ file 'opencvwoker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled4/opencvwoker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'opencvwoker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OpenCVWoker_t {
    QByteArrayData data[21];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenCVWoker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenCVWoker_t qt_meta_stringdata_OpenCVWoker = {
    {
QT_MOC_LITERAL(0, 0, 11), // "OpenCVWoker"
QT_MOC_LITERAL(1, 12, 18), // "sendFrame_original"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "original"
QT_MOC_LITERAL(4, 41, 19), // "sendFrame_processed"
QT_MOC_LITERAL(5, 61, 9), // "processed"
QT_MOC_LITERAL(6, 71, 10), // "SendStatus"
QT_MOC_LITERAL(7, 82, 6), // "result"
QT_MOC_LITERAL(8, 89, 7), // "Npoints"
QT_MOC_LITERAL(9, 97, 9), // "NOKpoints"
QT_MOC_LITERAL(10, 107, 16), // "receiveGrabFrame"
QT_MOC_LITERAL(11, 124, 19), // "receiveToggleStream"
QT_MOC_LITERAL(12, 144, 28), // "receiveEnableBinaryThreshold"
QT_MOC_LITERAL(13, 173, 5), // "state"
QT_MOC_LITERAL(14, 179, 21), // "receiveThresholdValue"
QT_MOC_LITERAL(15, 201, 5), // "value"
QT_MOC_LITERAL(16, 207, 13), // "ReceiveValues"
QT_MOC_LITERAL(17, 221, 7), // "AreaRef"
QT_MOC_LITERAL(18, 229, 10), // "OffsetArea"
QT_MOC_LITERAL(19, 240, 14), // "OfssetPosition"
QT_MOC_LITERAL(20, 255, 7) // "PointOK"

    },
    "OpenCVWoker\0sendFrame_original\0\0"
    "original\0sendFrame_processed\0processed\0"
    "SendStatus\0result\0Npoints\0NOKpoints\0"
    "receiveGrabFrame\0receiveToggleStream\0"
    "receiveEnableBinaryThreshold\0state\0"
    "receiveThresholdValue\0value\0ReceiveValues\0"
    "AreaRef\0OffsetArea\0OfssetPosition\0"
    "PointOK"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenCVWoker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    3,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   67,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,
      14,    1,   72,    2, 0x0a /* Public */,
      16,    4,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Int,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,   20,

       0        // eod
};

void OpenCVWoker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenCVWoker *_t = static_cast<OpenCVWoker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFrame_original((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sendFrame_processed((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->SendStatus((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->receiveGrabFrame(); break;
        case 4: _t->receiveToggleStream(); break;
        case 5: _t->receiveEnableBinaryThreshold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->receiveThresholdValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ReceiveValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OpenCVWoker::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OpenCVWoker::sendFrame_original)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (OpenCVWoker::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OpenCVWoker::sendFrame_processed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (OpenCVWoker::*_t)(bool , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OpenCVWoker::SendStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject OpenCVWoker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OpenCVWoker.data,
      qt_meta_data_OpenCVWoker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OpenCVWoker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenCVWoker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OpenCVWoker.stringdata0))
        return static_cast<void*>(const_cast< OpenCVWoker*>(this));
    return QObject::qt_metacast(_clname);
}

int OpenCVWoker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void OpenCVWoker::sendFrame_original(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OpenCVWoker::sendFrame_processed(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OpenCVWoker::SendStatus(bool _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
