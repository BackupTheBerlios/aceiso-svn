#ifndef PROGRESS_H
#define PROGRESS_H
//
#include <QDialog>
#include <QProgressBar>
#include <QtGui>


//
class progressDiag : public QDialog//, public Ui::progress
{
Q_OBJECT
public:
	progressDiag( QWidget * parent = 0, Qt::WFlags f = 0 );

private:
   void setupWidgets();

};
#endif





