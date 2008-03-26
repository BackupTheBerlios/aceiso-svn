/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Mar 26 00:16:44 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x0a,
      36,   11,   11,   11, 0x2a,
      48,   11,   11,   11, 0x0a,
      59,   11,   11,   11, 0x0a,
      85,   67,   11,   11, 0x0a,
     148,  110,   11,   11, 0x0a,
     196,   11,   11,   11, 0x0a,
     205,   11,   11,   11, 0x0a,
     215,   11,   11,   11, 0x0a,
     229,  224,   11,   11, 0x0a,
     260,   11,   11,   11, 0x0a,
     271,   11,   11,   11, 0x0a,
     285,   11,   11,   11, 0x0a,
     293,   11,   11,   11, 0x0a,
     301,   11,   11,   11, 0x0a,
     313,   11,   11,   11, 0x0a,
     327,  325,   11,   11, 0x0a,
     367,   11,   11,   11, 0x0a,
     377,   11,   11,   11, 0x0a,
     400,   11,   11,   11, 0x0a,
     411,   11,   11,   11, 0x0a,
     437,  425,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0path\0openImage(QString)\0"
    "openImage()\0a_donate()\0mount()\0"
    "image,destination\0Monta(QString&,QString&)\0"
    "destination,onlyfile,divide,temporary\0"
    "openBrowser(QString&,QString,long int,QString&)\0"
    "gmount()\0gumount()\0umount()\0item\0"
    "open_mounted(QListWidgetItem*)\0"
    "md5check()\0md5generate()\0split()\0"
    "merge()\0progBarra()\0closeProg()\0,\0"
    "printOutsplit(int,QProcess::ExitStatus)\0"
    "zzofiga()\0initial_get_database()\0"
    "database()\0foldertoiso()\0pluginsMenu\0"
    "pluginsRead(QMenu*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
	return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: openImage(); break;
        case 2: a_donate(); break;
        case 3: mount(); break;
        case 4: Monta((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: openBrowser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< long int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 6: gmount(); break;
        case 7: gumount(); break;
        case 8: umount(); break;
        case 9: open_mounted((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: md5check(); break;
        case 11: md5generate(); break;
        case 12: split(); break;
        case 13: merge(); break;
        case 14: progBarra(); break;
        case 15: closeProg(); break;
        case 16: printOutsplit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 17: zzofiga(); break;
        case 18: initial_get_database(); break;
        case 19: database(); break;
        case 20: foldertoiso(); break;
        case 21: pluginsRead((*reinterpret_cast< QMenu*(*)>(_a[1]))); break;
        }
        _id -= 22;
    }
    return _id;
}
