#ifndef MANUAL_H
#define MANUAL_H
//
#include <QDialog>
#include "../build/ui_manual.h"

//
class manualDiag : public QDialog, public Ui::manual
{
Q_OBJECT
public:
	manualDiag( QWidget * parent = 0, Qt::WFlags f = 0 );

};
#endif





