 

void MainWindow::extract()
{
QDir acetone_bin = QDir::home();
acetone_bin.cd(".acetoneiso");
QFile poweriso_file( acetone_bin.path() + "/poweriso");
	if(!poweriso_file.exists())
	get_poweriso();
	else
	{
	//estrazione qui
	QDir Home = QDir::home();
	QString isodaestrarre;
	isodaestrarre = QFileDialog::getOpenFileName(this,tr("Open Image"), Home.path() ,  tr("Image Files (*.iso *.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d *.dmg)"));
		if ( isodaestrarre.isNull() )
		{
		}
		else
		{
		 QString folder = QFileDialog::getExistingDirectory(this, tr("A-ISO::Select where to extract image"),Home.path());
		if (folder.isNull() )
		{
		}
		else
		{
		 POweriso.start( poweriso_file.fileName(), QStringList() << "extract" << isodaestrarre << "/" << "-od" << folder );
		 progBarra();
		}
		}
	     }
}
