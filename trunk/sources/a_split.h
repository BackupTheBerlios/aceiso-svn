void MainWindow::split()
{
QDir bin("/usr/bin");
QFile split;
QDir::setCurrent( bin.path() );
split.setFileName("split");
if (split.exists()){
 QDir Home = QDir::home();
 QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image to be splitted"),Home.path() , tr("Image Files (*.iso *.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d *.dmg)"));
 if ( fileName.isNull() ){
 }
 else{
 QDir Home = QDir::home();
 QString split_folder = QFileDialog::getExistingDirectory(this, tr("AcetoneISO2::Select Folder where the image will be splitted"), Home.path() );
	if ( split_folder.isNull() ){
	}
	else{
	bool ok;
	int i = QInputDialog::getInteger(this, tr("AcetoneISO2::Split number"),tr("Please insert the split number in MegaByte:"), 649, 0, 100000, 1, &ok);
		if (!ok){
		}
		else{
		 QString file;
		 file = QString::number(i).append("m");
		 bin = split_folder;
		 QDir::setCurrent( bin.path() );
		 SPlit.start("split",QStringList()  << "-b" << file << fileName);
			progBarra();
		    }
			
	     }
      }
    }
else
QMessageBox::warning(this, "AcetoneISO2::Warning!",tr("no split file found in /usr/bin"));
}

void MainWindow::merge()
{
QDir Home = QDir::home();
 QFileDialog dialog(this, tr("AcetoneISO2::Select Parts"), Home.path());
 dialog.setFileMode(QFileDialog::ExistingFiles);
 dialog.setViewMode(QFileDialog::Detail); 
 QStringList fileNames;


 if (dialog.exec())
{

     fileNames = dialog.selectedFiles();
if (!fileNames.isEmpty())
{
QString merged = QFileDialog::getSaveFileName(this, tr("AcetoneISO2::Save merged image"),Home.path() + "/Acetone_merged");
		if (merged.isNull() ){
		}
		else{
			CAt.setReadChannel(QProcess::StandardOutput);//imposto il canale di lettura del processo
			CAt.setStandardOutputFile( merged,   QIODevice::Truncate );//l'output di cat va nel file merged.
			CAt.start("cat", QStringList() <<  fileNames );//faccio partire il processo cat.
			progBarra();

		    }
}
}
}
