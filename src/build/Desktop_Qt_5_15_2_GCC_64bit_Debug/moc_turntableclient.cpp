/****************************************************************************
** Meta object code from reading C++ file 'turntableclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../turntableclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'turntableclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TurntableClient_t {
    QByteArrayData data[49];
    char stringdata0[566];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TurntableClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TurntableClient_t qt_meta_stringdata_TurntableClient = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TurntableClient"
QT_MOC_LITERAL(1, 16, 14), // "baseUrlChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "baseUrl"
QT_MOC_LITERAL(4, 40, 13), // "stateReceived"
QT_MOC_LITERAL(5, 54, 22), // "TurntableClient::State"
QT_MOC_LITERAL(6, 77, 5), // "state"
QT_MOC_LITERAL(7, 83, 23), // "logicalPositionReceived"
QT_MOC_LITERAL(8, 107, 8), // "position"
QT_MOC_LITERAL(9, 116, 17), // "constantsReceived"
QT_MOC_LITERAL(10, 134, 26), // "TurntableClient::Constants"
QT_MOC_LITERAL(11, 161, 9), // "constants"
QT_MOC_LITERAL(12, 171, 20), // "homingOffsetReceived"
QT_MOC_LITERAL(13, 192, 12), // "homingOffset"
QT_MOC_LITERAL(14, 205, 13), // "requestFailed"
QT_MOC_LITERAL(15, 219, 3), // "url"
QT_MOC_LITERAL(16, 223, 10), // "httpStatus"
QT_MOC_LITERAL(17, 234, 5), // "error"
QT_MOC_LITERAL(18, 240, 12), // "refreshState"
QT_MOC_LITERAL(19, 253, 19), // "readLogicalPosition"
QT_MOC_LITERAL(20, 273, 20), // "readLogicalConstants"
QT_MOC_LITERAL(21, 294, 16), // "readHomingOffset"
QT_MOC_LITERAL(22, 311, 4), // "init"
QT_MOC_LITERAL(23, 316, 4), // "lock"
QT_MOC_LITERAL(24, 321, 6), // "unlock"
QT_MOC_LITERAL(25, 328, 13), // "turnClockwise"
QT_MOC_LITERAL(26, 342, 5), // "count"
QT_MOC_LITERAL(27, 348, 20), // "turnCounterClockwise"
QT_MOC_LITERAL(28, 369, 9), // "turnTenth"
QT_MOC_LITERAL(29, 379, 11), // "logicalInit"
QT_MOC_LITERAL(30, 391, 7), // "powerOn"
QT_MOC_LITERAL(31, 399, 21), // "TurntableClient::Side"
QT_MOC_LITERAL(32, 421, 4), // "side"
QT_MOC_LITERAL(33, 426, 8), // "powerOff"
QT_MOC_LITERAL(34, 435, 6), // "turnTo"
QT_MOC_LITERAL(35, 442, 7), // "turn180"
QT_MOC_LITERAL(36, 450, 12), // "turnRelative"
QT_MOC_LITERAL(37, 463, 8), // "distance"
QT_MOC_LITERAL(38, 472, 9), // "setOffset"
QT_MOC_LITERAL(39, 482, 5), // "value"
QT_MOC_LITERAL(40, 488, 10), // "saveOffset"
QT_MOC_LITERAL(41, 499, 9), // "setRelais"
QT_MOC_LITERAL(42, 509, 5), // "index"
QT_MOC_LITERAL(43, 515, 14), // "handleFinished"
QT_MOC_LITERAL(44, 530, 14), // "QNetworkReply*"
QT_MOC_LITERAL(45, 545, 5), // "reply"
QT_MOC_LITERAL(46, 551, 4), // "Side"
QT_MOC_LITERAL(47, 556, 3), // "Dot"
QT_MOC_LITERAL(48, 560, 5) // "NoDot"

    },
    "TurntableClient\0baseUrlChanged\0\0baseUrl\0"
    "stateReceived\0TurntableClient::State\0"
    "state\0logicalPositionReceived\0position\0"
    "constantsReceived\0TurntableClient::Constants\0"
    "constants\0homingOffsetReceived\0"
    "homingOffset\0requestFailed\0url\0"
    "httpStatus\0error\0refreshState\0"
    "readLogicalPosition\0readLogicalConstants\0"
    "readHomingOffset\0init\0lock\0unlock\0"
    "turnClockwise\0count\0turnCounterClockwise\0"
    "turnTenth\0logicalInit\0powerOn\0"
    "TurntableClient::Side\0side\0powerOff\0"
    "turnTo\0turn180\0turnRelative\0distance\0"
    "setOffset\0value\0saveOffset\0setRelais\0"
    "index\0handleFinished\0QNetworkReply*\0"
    "reply\0Side\0Dot\0NoDot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TurntableClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       1,  218, // properties
       1,  222, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       4,    1,  157,    2, 0x06 /* Public */,
       7,    1,  160,    2, 0x06 /* Public */,
       9,    1,  163,    2, 0x06 /* Public */,
      12,    1,  166,    2, 0x06 /* Public */,
      14,    3,  169,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  176,    2, 0x0a /* Public */,
      19,    0,  177,    2, 0x0a /* Public */,
      20,    0,  178,    2, 0x0a /* Public */,
      21,    0,  179,    2, 0x0a /* Public */,
      22,    0,  180,    2, 0x0a /* Public */,
      23,    0,  181,    2, 0x0a /* Public */,
      24,    0,  182,    2, 0x0a /* Public */,
      25,    1,  183,    2, 0x0a /* Public */,
      25,    0,  186,    2, 0x2a /* Public | MethodCloned */,
      27,    1,  187,    2, 0x0a /* Public */,
      27,    0,  190,    2, 0x2a /* Public | MethodCloned */,
      28,    1,  191,    2, 0x0a /* Public */,
      29,    0,  194,    2, 0x0a /* Public */,
      30,    1,  195,    2, 0x0a /* Public */,
      33,    0,  198,    2, 0x0a /* Public */,
      34,    1,  199,    2, 0x0a /* Public */,
      35,    0,  202,    2, 0x0a /* Public */,
      36,    1,  203,    2, 0x0a /* Public */,
      38,    1,  206,    2, 0x0a /* Public */,
      40,    0,  209,    2, 0x0a /* Public */,
      41,    2,  210,    2, 0x0a /* Public */,
      43,    1,  215,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QUrl, QMetaType::Int, QMetaType::QString,   15,   16,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   42,   39,
    QMetaType::Void, 0x80000000 | 44,   45,

 // properties: name, type, flags
       3, QMetaType::QUrl, 0x00495103,

 // properties: notify_signal_id
       0,

 // enums: name, alias, flags, count, data
      46,   46, 0x2,    2,  227,

 // enum data: key, value
      47, uint(TurntableClient::Side::Dot),
      48, uint(TurntableClient::Side::NoDot),

       0        // eod
};

void TurntableClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TurntableClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->baseUrlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: _t->stateReceived((*reinterpret_cast< const TurntableClient::State(*)>(_a[1]))); break;
        case 2: _t->logicalPositionReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->constantsReceived((*reinterpret_cast< const TurntableClient::Constants(*)>(_a[1]))); break;
        case 4: _t->homingOffsetReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->requestFailed((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->refreshState(); break;
        case 7: _t->readLogicalPosition(); break;
        case 8: _t->readLogicalConstants(); break;
        case 9: _t->readHomingOffset(); break;
        case 10: _t->init(); break;
        case 11: _t->lock(); break;
        case 12: _t->unlock(); break;
        case 13: _t->turnClockwise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->turnClockwise(); break;
        case 15: _t->turnCounterClockwise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->turnCounterClockwise(); break;
        case 17: _t->turnTenth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->logicalInit(); break;
        case 19: _t->powerOn((*reinterpret_cast< TurntableClient::Side(*)>(_a[1]))); break;
        case 20: _t->powerOff(); break;
        case 21: _t->turnTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->turn180(); break;
        case 23: _t->turnRelative((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->saveOffset(); break;
        case 26: _t->setRelais((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: _t->handleFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TurntableClient::State >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TurntableClient::Constants >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TurntableClient::*)(const QUrl & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TurntableClient::baseUrlChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TurntableClient::*)(const TurntableClient::State & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TurntableClient::stateReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TurntableClient::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TurntableClient::logicalPositionReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TurntableClient::*)(const TurntableClient::Constants & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TurntableClient::constantsReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TurntableClient::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TurntableClient::homingOffsetReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TurntableClient::*)(const QUrl & , int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TurntableClient::requestFailed)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TurntableClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QUrl*>(_v) = _t->baseUrl(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TurntableClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBaseUrl(*reinterpret_cast< QUrl*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TurntableClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TurntableClient.data,
    qt_meta_data_TurntableClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TurntableClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TurntableClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TurntableClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TurntableClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TurntableClient::baseUrlChanged(const QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TurntableClient::stateReceived(const TurntableClient::State & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TurntableClient::logicalPositionReceived(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TurntableClient::constantsReceived(const TurntableClient::Constants & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TurntableClient::homingOffsetReceived(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TurntableClient::requestFailed(const QUrl & _t1, int _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
