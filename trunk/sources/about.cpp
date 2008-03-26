#include "about.h"

//
aboutDiag::aboutDiag( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
setMinimumSize(400,100);
	setupWidgets();
        setWindowTitle(tr("About A-ISO"));
}

void aboutDiag::setupWidgets()
{
   QPushButton *exitButton = new QPushButton(tr("Ok") );
   QLabel *author = new QLabel;
   author->setText(tr("A_ISO by Fabrizio Di Marco"));
   
   QVBoxLayout *verticalLayout = new QVBoxLayout;		//layout generale della finestra
   QHBoxLayout *hlt = new QHBoxLayout;

   QFrame *frame = new QFrame;

  // verticalLayout->addWidget(author );
   hlt->addStretch(1);
   hlt->addWidget( exitButton );
   frame->setLayout( hlt );

   verticalLayout->addWidget( author );
   verticalLayout->addWidget( frame );

   this->setLayout( verticalLayout );


   connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}
//




/*#include "progress.h"

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
//*/
