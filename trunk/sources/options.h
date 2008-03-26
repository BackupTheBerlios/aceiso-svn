#ifndef OPTIONS_H
#define OPTIONS_H
//
#include <QDialog>
#include "../build/ui_options.h"
//
class optionsDiag : public QDialog, public Ui::options
{
Q_OBJECT
public:
	optionsDiag( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
   void optionss();
   void update_options();


};
#endif





