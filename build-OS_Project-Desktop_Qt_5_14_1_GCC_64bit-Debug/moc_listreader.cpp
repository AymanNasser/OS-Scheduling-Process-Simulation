/****************************************************************************
** Meta object code from reading C++ file 'listreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../OS_Project/listreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListReader_t {
    QByteArrayData data[19];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListReader_t qt_meta_stringdata_ListReader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ListReader"
QT_MOC_LITERAL(1, 11, 21), // "configrationGenerated"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "readyToLoadSimulator"
QT_MOC_LITERAL(4, 55, 10), // "setGuiList"
QT_MOC_LITERAL(5, 66, 10), // "setArrival"
QT_MOC_LITERAL(6, 77, 11), // "readArrival"
QT_MOC_LITERAL(7, 89, 8), // "setBurst"
QT_MOC_LITERAL(8, 98, 9), // "readBurst"
QT_MOC_LITERAL(9, 108, 11), // "setPriority"
QT_MOC_LITERAL(10, 120, 12), // "readPriority"
QT_MOC_LITERAL(11, 133, 16), // "setConfigrations"
QT_MOC_LITERAL(12, 150, 11), // "processtype"
QT_MOC_LITERAL(13, 162, 7), // "numbers"
QT_MOC_LITERAL(14, 170, 6), // "rrTime"
QT_MOC_LITERAL(15, 177, 10), // "preemptive"
QT_MOC_LITERAL(16, 188, 9), // "BurstTime"
QT_MOC_LITERAL(17, 198, 11), // "ArrivalTime"
QT_MOC_LITERAL(18, 210, 8) // "Priority"

    },
    "ListReader\0configrationGenerated\0\0"
    "readyToLoadSimulator\0setGuiList\0"
    "setArrival\0readArrival\0setBurst\0"
    "readBurst\0setPriority\0readPriority\0"
    "setConfigrations\0processtype\0numbers\0"
    "rrTime\0preemptive\0BurstTime\0ArrivalTime\0"
    "Priority"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       3,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   67,    2, 0x02 /* Public */,
       6,    0,   70,    2, 0x02 /* Public */,
       7,    1,   71,    2, 0x02 /* Public */,
       8,    0,   74,    2, 0x02 /* Public */,
       9,    1,   75,    2, 0x02 /* Public */,
      10,    0,   78,    2, 0x02 /* Public */,
      11,    4,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   12,   13,   14,   15,

 // properties: name, type, flags
      16, QMetaType::QVariantList, 0x00095003,
      17, QMetaType::QVariantList, 0x00095003,
      18, QMetaType::QVariantList, 0x00095103,

       0        // eod
};

void ListReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configrationGenerated(); break;
        case 1: _t->readyToLoadSimulator(); break;
        case 2: _t->setGuiList(); break;
        case 3: _t->setArrival((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 4: { QVariantList _r = _t->readArrival();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setBurst((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 6: { QVariantList _r = _t->readBurst();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setPriority((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 8: { QVariantList _r = _t->readPriority();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setConfigrations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListReader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReader::configrationGenerated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ListReader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReader::readyToLoadSimulator)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ListReader *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->readBurst(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->readArrival(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->readPriority(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ListReader *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBurst(*reinterpret_cast< QVariantList*>(_v)); break;
        case 1: _t->setArrival(*reinterpret_cast< QVariantList*>(_v)); break;
        case 2: _t->setPriority(*reinterpret_cast< QVariantList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ListReader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ListReader.data,
    qt_meta_data_ListReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ListReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListReader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ListReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ListReader::configrationGenerated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ListReader::readyToLoadSimulator()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
