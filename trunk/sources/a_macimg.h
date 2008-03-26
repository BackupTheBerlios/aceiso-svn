 
void MainWindow::macimg()
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
	isodaconvertire = QFileDialog::getOpenFileName(this,tr("Open Image"), Home.path() ,  tr("Image Files (*.dmg)"));
		if ( !isodaconvertire.isNull() ){

		 	QString fileName = QFileDialog::getSaveFileName(this, tr("AcetoneISO2::Save ISO file"),
				Home.path() ,
				tr("Images (*.iso)"));
		if (!fileName.isNull() )
		{
		fileName = fileName.append(".iso");
		 MAcimg.start( poweriso_file.fileName(), QStringList() << "convert" << isodaconvertire << "-o" << fileName );
		 progBarra();
		}
		}
	     }
}
