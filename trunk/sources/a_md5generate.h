 void MainWindow::md5generate()
{
QDir Home = QDir::home();
QString immagine = QFileDialog::getOpenFileName(this,tr("AcetoneISO::Select Image"), Home.path(), tr("Image Files (*.iso *.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d)"));
	if (!immagine.isNull() ){
	 
	 QString fileName = QFileDialog::getSaveFileName(this, tr("AcetoneISO::Save Md5 text file"),Home.path() + "/md5.txt",
													tr("Md5 (*.md5)"));
	if (!fileName.isNull()){
	 MD5.setReadChannel(QProcess::StandardOutput);
	 MD5.start("md5sum", QStringList() << immagine );
	 //progBarra();
			if (!MD5.waitForFinished()){
        		qDebug() << "Make failed:" << MD5.errorString();
			}
    			else{
			QByteArray ba = MD5.readAll();
			QString s( ba );
			//QMessageBox::question(this, "AcetoneISO2::Warning!", s );
			QFile f1(fileName);
			f1.open(QIODevice::WriteOnly | QIODevice::Text);
			QTextStream out(&f1);
			out << (ba);
			}
	}
	}
}
