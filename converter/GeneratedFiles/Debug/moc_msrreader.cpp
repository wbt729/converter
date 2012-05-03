/****************************************************************************
** Meta object code from reading C++ file 'msrreader.h'
**
** Created: Thu 3. May 13:50:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../msrreader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'msrreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSRReader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      25,   10,   10,   10, 0x05,
      44,   10,   10,   10, 0x05,
      62,   10,   10,   10, 0x05,
      82,   10,   10,   10, 0x05,
     103,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     125,   10,   10,   10, 0x08,
     144,   10,   10,   10, 0x08,
     163,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MSRReader[] = {
    "MSRReader\0\0newFileInfo()\0newPreview(QImage)\0"
    "convertFrame(int)\0frameConverted(int)\0"
    "doneConvertingFile()\0conversionStatus(int)\0"
    "convertWholeFile()\0onFrameConverted()\0"
    "frameToTiff(int)\0"
};

void MSRReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSRReader *_t = static_cast<MSRReader *>(_o);
        switch (_id) {
        case 0: _t->newFileInfo(); break;
        case 1: _t->newPreview((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->convertFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->frameConverted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->doneConvertingFile(); break;
        case 5: _t->conversionStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->convertWholeFile(); break;
        case 7: _t->onFrameConverted(); break;
        case 8: _t->frameToTiff((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSRReader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSRReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MSRReader,
      qt_meta_data_MSRReader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSRReader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSRReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSRReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSRReader))
        return static_cast<void*>(const_cast< MSRReader*>(this));
    return QObject::qt_metacast(_clname);
}

int MSRReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MSRReader::newFileInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MSRReader::newPreview(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MSRReader::convertFrame(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MSRReader::frameConverted(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MSRReader::doneConvertingFile()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MSRReader::conversionStatus(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
