#include "options.h"
#include"a_options.h"
//
optionsDiag::optionsDiag( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{

	setupUi(this);
//connect( exit_button, SIGNAL( clicked() ), this, SLOT( quit() ) );

    connect( radioButton_5, SIGNAL( toggled(bool) ), this, SLOT( update_options() ));
    connect( radioButton_7, SIGNAL( toggled(bool) ), this, SLOT( update_options() ));
    connect( radioButton_9, SIGNAL( toggled(bool) ), this, SLOT( update_options() ));
    connect( radioButton, SIGNAL( toggled(bool) ), this, SLOT( update_options() ));
optionss();
}
//

