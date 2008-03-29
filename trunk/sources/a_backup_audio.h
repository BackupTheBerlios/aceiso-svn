void MainWindow::backupaudio()
{
QDir bin("/usr/bin");
QFile cdrdao;
QDir::setCurrent( bin.path() );
cdrdao.setFileName("cdrdao");

if (cdrdao.exists())
	{
QMessageBox::warning(this, "A-ISO::Warning!",tr("Please note this utility will generate a BIN image which could not be mounted or read in any way . \nHowever You can burn it later with A-ISO using Burn TOC utility(to be implemented in a future release) ."));
 QDir Home = QDir::home();
		 	QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save BIN Audio file"),
										Home.path() + "/aiso_Audio",
										tr("Images (*.bin)"));

			
			if ( fileName.isNull() )
			{
			}
			else
			{
		QString	filebin = fileName.append(".bin");
		QString	filetoc = fileName.append(".toc");
UMountcdrom.start("umount",QStringList()  << "/dev/cdrom");		
BAckaudio.start("cdrdao",QStringList()  << "read-cd" << "--datafile" << filebin << "--device" << "/dev/cdrom" << "--buffers" << "64" << "--driver" << "generic-mmc-raw" << filetoc);
			progBarra();
			
			}	

	}
else
QMessageBox::warning(this, "A-ISO::Warning!",tr("no cdrdao found in /usr/bin"));
} 
