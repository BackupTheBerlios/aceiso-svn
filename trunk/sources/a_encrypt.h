void MainWindow::encrypt()
{
QDir Home = QDir::home();
QString immagine = QFileDialog::getOpenFileName(this,tr("A-ISO::Select Image to encrypt"), Home.path(), tr("Image Files (*.iso *.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d *.dmg)"));
	if (!immagine.isNull())
	{
GPg.start("gpg2", QStringList() << "-c" << immagine );
progBarra();
	}
}
