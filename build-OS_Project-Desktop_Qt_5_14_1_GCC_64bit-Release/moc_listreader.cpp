/****************************************************************************
** Meta object code from reading C++ file 'listreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OS_Project/listreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
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
    QByteArrayData data[33];
    char stringdata0[394];
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
QT_MOC_LITERAL(3, 34, 18), // "allProcessfinished"
QT_MOC_LITERAL(4, 53, 20), // "readyToLoadSimulator"
QT_MOC_LITERAL(5, 74, 10), // "setGuiList"
QT_MOC_LITERAL(6, 85, 17), // "setSimulationList"
QT_MOC_LITERAL(7, 103, 6), // "setIDs"
QT_MOC_LITERAL(8, 110, 8), // "setTimes"
QT_MOC_LITERAL(9, 119, 9), // "idsLength"
QT_MOC_LITERAL(10, 129, 10), // "readIDitem"
QT_MOC_LITERAL(11, 140, 10), // "timeLength"
QT_MOC_LITERAL(12, 151, 12), // "readTimeitem"
QT_MOC_LITERAL(13, 164, 13), // "averageLength"
QT_MOC_LITERAL(14, 178, 15), // "readAverageitem"
QT_MOC_LITERAL(15, 194, 10), // "setArrival"
QT_MOC_LITERAL(16, 205, 11), // "readArrival"
QT_MOC_LITERAL(17, 217, 8), // "setBurst"
QT_MOC_LITERAL(18, 226, 9), // "readBurst"
QT_MOC_LITERAL(19, 236, 11), // "setPriority"
QT_MOC_LITERAL(20, 248, 12), // "readPriority"
QT_MOC_LITERAL(21, 261, 16), // "setConfigrations"
QT_MOC_LITERAL(22, 278, 11), // "processtype"
QT_MOC_LITERAL(23, 290, 7), // "numbers"
QT_MOC_LITERAL(24, 298, 6), // "rrTime"
QT_MOC_LITERAL(25, 305, 10), // "preemptive"
QT_MOC_LITERAL(26, 316, 9), // "ProcessID"
QT_MOC_LITERAL(27, 326, 11), // "ProcessTime"
QT_MOC_LITERAL(28, 338, 11), // "AverageTime"
QT_MOC_LITERAL(29, 350, 12), // "QList<qreal>"
QT_MOC_LITERAL(30, 363, 9), // "BurstTime"
QT_MOC_LITERAL(31, 373, 11), // "ArrivalTime"
QT_MOC_LITERAL(32, 385, 8) // "Priority"

    },
    "ListReader\0configrationGenerated\0\0"
    "allProcessfinished\0readyToLoadSimulator\0"
    "setGuiList\0setSimulationList\0setIDs\0"
    "setTimes\0idsLength\0readIDitem\0timeLength\0"
    "readTimeitem\0averageLength\0readAverageitem\0"
    "setArrival\0readArrival\0setBurst\0"
    "readBurst\0setPriority\0readPriority\0"
    "setConfigrations\0processtype\0numbers\0"
    "rrTime\0preemptive\0ProcessID\0ProcessTime\0"
    "AverageTime\0QList<qreal>\0BurstTime\0"
    "ArrivalTime\0Priority"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       6,  158, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,
       4,    0,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       7,    1,  119,    2, 0x02 /* Public */,
       8,    1,  122,    2, 0x02 /* Public */,
       9,    0,  125,    2, 0x02 /* Public */,
      10,    1,  126,    2, 0x02 /* Public */,
      11,    0,  129,    2, 0x02 /* Public */,
      12,    1,  130,    2, 0x02 /* Public */,
      13,    0,  133,    2, 0x02 /* Public */,
      14,    1,  134,    2, 0x02 /* Public */,
      15,    1,  137,    2, 0x02 /* Public */,
      16,    0,  140,    2, 0x02 /* Public */,
      17,    1,  141,    2, 0x02 /* Public */,
      18,    0,  144,    2, 0x02 /* Public */,
      19,    1,  145,    2, 0x02 /* Public */,
      20,    0,  148,    2, 0x02 /* Public */,
      21,    4,  149,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    2,
    QMetaType::Int,
    QMetaType::QReal, QMetaType::Int,    2,
    QMetaType::Int,
    QMetaType::QReal, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QVariantList,    2,
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   22,   23,   24,   25,

 // properties: name, type, flags
      26, QMetaType::QVariantList, 0x00095003,
      27, QMetaType::QVariantList, 0x00095003,
      28, 0x80000000 | 29, 0x0009500b,
      30, QMetaType::QVariantList, 0x00095003,
      31, QMetaType::QVariantList, 0x00095003,
      32, QMetaType::QVariantList, 0x00095103,

       0        // eod
};

void ListReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configrationGenerated(); break;
        case 1: _t->allProcessfinished(); break;
        case 2: _t->readyToLoadSimulator(); break;
        case 3: _t->setGuiList(); break;
        case 4: _t->setSimulationList(); break;
        case 5: _t->setIDs((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 6: _t->setTimes((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 7: { int _r = _t->idsLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->readIDitem((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->timeLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { qreal _r = _t->readTimeitem((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->averageLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { qreal _r = _t->readAverageitem((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setArrival((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 14: { QVariantList _r = _t->readArrival();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->setBurst((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 16: { QVariantList _r = _t->readBurst();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->setPriority((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 18: { QVariantList _r = _t->readPriority();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->setConfigrations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListReader::allProcessfinished)) {
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
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<qreal> >(); break;
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
        case 2: *reinterpret_cast< QList<qreal>*>(_v) = _t->readAverage(); break;
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
        case 2: _t->setAverage(*reinterpret_cast< QList<qreal>*>(_v)); break;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
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
void ListReader::allProcessfinished()
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
