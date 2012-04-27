/****************************************************************************
** Meta object code from reading C++ file 'converter.h'
**
** Created: Fri 27. Apr 15:30:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../converter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'converter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_converter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      41,   10,   10,   10, 0x08,
      72,   10,   10,   10, 0x08,
      90,   10,   10,   10, 0x08,
     103,   10,   10,   10, 0x08,
     121,   10,   10,   10, 0x08,
     135,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_converter[] = {
    "converter\0\0onNewDirSelected(QModelIndex)\0"
    "onNewFileSelected(QModelIndex)\0"
    "onConvertButton()\0onFileInfo()\0"
    "onPreview(QImage)\0onSlider(int)\0"
    "onFrameConverted(int)\0"
};

void converter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        converter *_t = static_cast<converter *>(_o);
        switch (_id) {
        case 0: _t->onNewDirSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onNewFileSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onConvertButton(); break;
        case 3: _t->onFileInfo(); break;
        case 4: _t->onPreview((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->onSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onFrameConverted((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData converter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject converter::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_converter,
      qt_meta_data_converter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &converter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *converter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *converter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_converter))
        return static_cast<void*>(const_cast< converter*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int converter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
