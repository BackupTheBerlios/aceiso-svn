#include "progress.h"

//
progressDiag::progressDiag( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
setMinimumSize(400,50);
	setupWidgets();
        setWindowTitle(tr("A-ISO"));
}

void progressDiag::setupWidgets()
{
QProgressBar *progBar = new QProgressBar;
progBar->setMaximum( 0 );
QLabel *label = new QLabel(tr("Plese wait.......work in progress"));
QVBoxLayout *layout = new QVBoxLayout;
layout->addWidget( label );
layout->addWidget( progBar );
this->setLayout( layout );
}
//

