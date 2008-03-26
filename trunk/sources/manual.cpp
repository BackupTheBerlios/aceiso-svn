#include "manual.h"

//
manualDiag::manualDiag( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);


textBrowser->setSource( QUrl("qrc:/manual/manual.html") );
}
//

