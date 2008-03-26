#include "a_poweriso.h" 

void MainWindow::converter()
{
QDir acetone_bin = QDir::home();
acetone_bin.cd(".acetoneiso");
QFile poweriso_file( acetone_bin.path() + "/poweriso");
	if(!poweriso_file.exists())
	get_poweriso();
	else{
	//estrazione qui
	QDir Home = QDir::home();
	QString isodaconvertire;
	isodaconvertire = QFileDialog::getOpenFileName(this,tr("Open Image"), Home.path() ,  tr("Image Files (*.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d)"));
		if ( !isodaconvertire.isNull() ){

		 	QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save ISO file"),
				Home.path() ,
				tr("Images (*.iso)"));
		if (!fileName.isNull() )
		{
		fileName = fileName.append(".iso");
		 POweriso.start( poweriso_file.fileName(), QStringList() << "convert" << isodaconvertire << "-o" << fileName );
		 progBarra();
		}
		}
	     }
}
