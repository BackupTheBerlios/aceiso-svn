 
void MainWindow::compress()
{
QDir bin("/usr/bin");
QFile pzip;
QDir::setCurrent( bin.path() );
pzip.setFileName("7z");

if (pzip.exists())
{
 QDir Home = QDir::home();
QString dacomprimere = QFileDialog::getOpenFileName(this,tr("A-ISO::Select Image to compress"), Home.path(), tr("Image Files (*.iso *.daa *.bin *.mdf *.ashdisc *.bwi *.b5i *.lcd *.img *.cdi *.cif *.p01 *.pdi *.nrg *.ncd *.pxi *.gi *.fcd *.vcd *.c2d)"));
	if (!dacomprimere.isEmpty() )
		{
		 QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save Compressed Image"),
										Home.path() + "/compressed_image",
										tr("Images (*.7z)"));
		if ( fileName.isNull() )
			{
			}
			else
			{
		 fileName.append(".7z");
			QMessageBox msgBox;
			msgBox.setText(tr("Do You want to compress in Ultra High mode? (very slow)"));
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		switch (msgBox.exec()) {
				case QMessageBox::Yes:
					{
					 PZip.start("7z",QStringList() <<  "a" << "-t7z" << "-m0=lzma" << "-mx=9" << "-mfb=64" << "-md=32m" << "-ms=on" << fileName << dacomprimere );
					 progBarra();
					}
					break;
				case QMessageBox::No:
					{
					 PZip.start("7z",QStringList() <<  "a" << "-t7z" << "-m0=lzma" << "-mx=4" << "-mfb=32" << "-md=4m" << "-ms=on" << fileName << dacomprimere );
					 progBarra();
					}
				break;
				default:
				// should never be reached
				break;
					}
			
			}
		}

}
else
QMessageBox::warning(this, "A-ISO::Warning!",tr("no 7z found in /usr/bin"));

}

void MainWindow::uncompress()
{
QDir bin("/usr/bin");
QFile pzip;
QDir::setCurrent( bin.path() );
pzip.setFileName("7z");
if (pzip.exists()){
 QDir Home = QDir::home();
 QString fileName = QFileDialog::getOpenFileName(this,tr("Open Compressed Image"), Home.path() , tr("Image Files (*.7z)"));
 if ( fileName.isNull() ){
 }
 else{
  QDir Home = QDir::home();
  QString uncompress_folder = QFileDialog::getExistingDirectory(this, tr("A-ISO::Select Folder where the uncompressed Image will be saved"),Home.path() );
	if ( uncompress_folder.isNull() ){
	}
	else{
		uncompress_folder = uncompress_folder.prepend("-o");
		PZipuncompress.start("7z",QStringList()  << "e" << fileName << uncompress_folder);
		progBarra();
	    }
      }
   }
else
QMessageBox::warning(this, "A-ISO::Warning!",tr("no 7z found in /usr/bin, please install p7zip-full package"));
}


