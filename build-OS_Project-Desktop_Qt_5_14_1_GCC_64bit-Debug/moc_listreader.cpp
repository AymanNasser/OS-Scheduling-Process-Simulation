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
    QByteArrayData data[25];
    char stringdata0[284];
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
QT_MOC_LITERAL(3, 34, 12), // "listNotifier"
QT_MOC_LITERAL(4, 47, 20), // "readyToLoadSimulator"
QT_MOC_LITERAL(5, 68, 10), // "setGuiList"
QT_MOC_LITERAL(6, 79, 17), // "setSimulationList"
QT_MOC_LITERAL(7, 97, 6), // "setIDs"
QT_MOC_LITERAL(8, 104, 7), // "readIDs"
QT_MOC_LITERAL(9, 112, 8), // "setTimes"
QT_MOC_LITERAL(10, 121, 10), // "setAverage"
QT_MOC_LITERAL(11, 132, 10), // "setArrival"
QT_MOC_LITERAL(12, 143, 8), // "setBurst"
QT_MOC_LITERAL(13, 152, 11), // "setPriority"
QT_MOC_LITERAL(14, 164, 16), // "setConfigrations"
QT_MOC_LITERAL(15, 181, 11), // "processtype"
QT_MOC_LITERAL(16, 193, 7), // "numbers"
QT_MOC_LITERAL(17, 201, 6), // "rrTime"
QT_MOC_LITERAL(18, 208, 10), // "preemptive"
QT_MOC_LITERAL(19, 219, 9), // "ProcessID"
QT_MOC_LITERAL(20, 229, 11), // "ProcessTime"
QT_MOC_LITERAL(21, 241, 11), // "AverageTime"
QT_MOC_LITERAL(22, 253, 9), // "BurstTime"
QT_MOC_LITERAL(23, 263, 11), // "ArrivalTime"
QT_MOC_LITERAL(24, 275, 8) // "Priority"

    },
    "ListReader\0configrationGenerated\0\0"
    "listNotifier\0readyToLoadSimulator\0"
    "setGuiList\0setSimulationList\0setIDs\0"
    "readIDs\0setTimes\0setAverage\0setArrival\0"
    "setBurst\0setPriority\0setConfigrations\0"
    "processtype\0numbers\0rrTime\0preemptive\0"
    "ProcessID\0ProcessTime\0AverageTime\0"
    "BurstTime\0ArrivalTime\0Priority"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       6,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   84,    2, 0x02 /* Public */,
       8,    0,   87,    2, 0x02 /* Public */,
       9,    1,   88,    2, 0x02 /* Public */,
      10,    1,   91,    2, 0x02 /* Public */,
      11,    1,   94,    2, 0x02 /* Public */,
      12,    1,   97,    2, 0x02 /* Public */,
      13,    1,  100,    2, 0x02 /* Public */,
      14,    4,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   15,   16,   17,   18,

 // properties: name, type, flags
      19, QMetaType::QVariantList, 0x00495003,
      20, QMetaType::QVariantList, 0x00495003,
      21, QMetaType::QVariantList, 0x00095003,
      22, QMetaType::QVariantList, 0x00095003,
      23, QMetaType::QVariantList, 0x00095003,
      24, QMetaType::QVariantList, 0x00095103,

 // properties: notify_signal_id
       1,
       1,
       0,
       0,
       0,
       0,

       0        // eod
};

void ListReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configrationGenerated(); break;
        case 1: _t->listNotifier(); break;
        case 2: _t->readyToLoadSimulator(); break;
        case 3: _t->setGuiList(); break;
        case 4: _t->setSimulationList(); break;
        case 5: _t->setIDs((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 6: { QVariantList _r = _t->readIDs();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setTimes((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 8: _t->setAverage((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 9: _t->setArrival((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 10: _t->setBurst((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 11: _t->setPriority((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 12: _t->setConfigrations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReader::listNotifier)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ListReader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReader::readyToLoadSimulator)) {
                *result = 2;
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
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->readIDs(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->readTimes(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->readAverage(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = _t->readBurst(); break;
        case 4: *reinterpret_cast< QVariantList*>(_v) = _t->readArrival(); break;
        case 5: *reinterpret_cast< QVariantList*>(_v) = _t->readPriority(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ListReader *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIDs(*reinterpret_cast< QVariantList*>(_v)); break;
        case 1: _t->setTimes(*reinterpret_cast< QVariantList*>(_v)); break;
        case 2: _t->setAverage(*reinterpret_cast< QVariantList*>(_v)); break;
        case 3: _t->setBurst(*reinterpret_cast< QVariantList*>(_v)); break;
        case 4: _t->setArrival(*reinterpret_cast< QVariantList*>(_v)); break;
        case 5: _t->setPriority(*reinterpret_cast< QVariantList*>(_v)); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
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
void ListReader::listNotifier()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ListReader::readyToLoadSimulator()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
