 
void MainWindow::md5check()
{
QDir Home = QDir::home();
QString immagine = QFileDialog::getOpenFileName(this,tr("AcetoneISO::Select Image"), Home.path(), tr("Image Files (*.iso *.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d)"));
	if (!immagine.isEmpty() ){
	 MD5.setReadChannel(QProcess::StandardOutput);
	 MD5.start("md5sum", QStringList() << immagine );
	 //progBarra();
			if (!MD5.waitForFinished()){
        		qDebug() << "Make failed:" << MD5.errorString();
			}
    			else{
			QByteArray ba = MD5.readAll();
			QString s( ba );
			QMessageBox::information(this, "AcetoneISO::Md5 Check", s );
			}
	}
}
