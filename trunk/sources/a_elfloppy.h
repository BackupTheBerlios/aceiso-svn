void MainWindow::elfloppy()
{
QFile mkisofs_file( "/usr/bin/mkisofs");
	if(!mkisofs_file.exists())
	QMessageBox::warning(this, "A-ISO::Warning!",tr("Please be sure to have mkisofs installed in /usr/bin "));
	else
	{
	  QString folder = QFileDialog::getExistingDirectory( this, tr("A-ISO::Select Folder to transform in a bootable ISO"), QDir::home().path() );
		if(!folder.isEmpty() )
		{
		 QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save ISO file"),
				QDir::home().path() + "/a_bootable" ,
				tr("Images (*.iso)"));
		 
		 if (!fileName.isNull() )
		 {
			fileName.append( ".iso" );
		   QString bootfile = QFileDialog::getOpenFileName(this,tr("Select Boot File"), QDir::home().path() );
					if ( bootfile.isNull() )
					{
					}
					else
					{
					 QFile boot_file( bootfile );
					 QFileInfo boot_file_info( boot_file );
					 QDir directoryToConvert( folder );
					 directoryToConvert.mkdir("boot");
					 directoryToConvert.cd( "boot" );
					 boot_file.copy( folder + "boot/" + boot_file_info.fileName() );
					 MKisofs.startDetached("mkisofs", QStringList() << "-r" << "-b" << ( "boot/" + boot_file_info.fileName() ) << "-c" << "boot/boot.catalog" << "-o" << fileName << folder );
					progBarra();
					}
		  
		 }
	  	}
	  
	}
}
