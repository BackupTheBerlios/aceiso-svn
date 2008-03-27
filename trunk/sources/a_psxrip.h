 
void MainWindow::psxrip()
{
QDir bin("/usr/bin");
QFile cdrdao;
QDir::setCurrent( bin.path() );
cdrdao.setFileName("cdrdao");

if (cdrdao.exists())
	{
 QDir Home = QDir::home();
		 	QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save BIN file"),
										Home.path() + "/aiso_PSX",
										tr("Images (*.bin)"));

			
			if ( fileName.isNull() )
			{
			}
			else
			{
		QString	filebin = fileName.append(".bin");
		QString	filetoc = fileName.append(".toc");
UMountcdrom.start("umount",QStringList()  << "/dev/cdrom");		
PSxrip.start("cdrdao",QStringList()  << "read-cd" << "--read-raw" << "--datafile" << filebin << "--device" << "/dev/cdrom" << "--driver" << "generic-mmc-raw" << filetoc);
			progBarra();
			
			}
			
			
		

	}
else
QMessageBox::warning(this, "A-ISO::Warning!",tr("no cdrdao found in /usr/bin"));
}
