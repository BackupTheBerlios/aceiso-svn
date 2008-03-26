#ifndef ABOUT_H
#define ABOUT_H
//
#include <QDialog>
#include <QtGui>
//
class aboutDiag : public QDialog//, public Ui::about
{
Q_OBJECT
public:
	aboutDiag( QWidget * parent = 0, Qt::WFlags f = 0 );

private:
   void setupWidgets();

};
#endif


