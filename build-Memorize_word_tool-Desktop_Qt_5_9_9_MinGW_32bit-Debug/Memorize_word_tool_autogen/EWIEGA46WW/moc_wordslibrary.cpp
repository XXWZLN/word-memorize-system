/****************************************************************************
** Meta object code from reading C++ file 'wordslibrary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Memorize_word_tool/wordslibrary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wordslibrary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wordslibrary_t {
    QByteArrayData data[8];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wordslibrary_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wordslibrary_t qt_meta_stringdata_wordslibrary = {
    {
QT_MOC_LITERAL(0, 0, 12), // "wordslibrary"
QT_MOC_LITERAL(1, 13, 18), // "on_signOut_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "on_add_clicked"
QT_MOC_LITERAL(4, 48, 17), // "on_Delete_clicked"
QT_MOC_LITERAL(5, 66, 26), // "on_search_word_textChanged"
QT_MOC_LITERAL(6, 93, 4), // "arg1"
QT_MOC_LITERAL(7, 98, 31) // "on_comboBox_currentIndexChanged"

    },
    "wordslibrary\0on_signOut_clicked\0\0"
    "on_add_clicked\0on_Delete_clicked\0"
    "on_search_word_textChanged\0arg1\0"
    "on_comboBox_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wordslibrary[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void wordslibrary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        wordslibrary *_t = static_cast<wordslibrary *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_signOut_clicked(); break;
        case 1: _t->on_add_clicked(); break;
        case 2: _t->on_Delete_clicked(); break;
        case 3: _t->on_search_word_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject wordslibrary::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_wordslibrary.data,
      qt_meta_data_wordslibrary,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *wordslibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wordslibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wordslibrary.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int wordslibrary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
