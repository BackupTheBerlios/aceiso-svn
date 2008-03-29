void MainWindow::eltorito()
{
QFile stage2_eltorito( "/usr/lib/grub/x86_64-pc/stage2_eltorito" );//TODO:vedi sto problema tra architetture...( "/usr/lib/grub/i386-pc/stage2_eltorito" );
QFile mkisofs_file( "/usr/bin/mkisofs");
	if(!mkisofs_file.exists())
	QMessageBox::warning(this, "A-ISO::Warning!",tr("Please be sure to have mkisofs installed in /usr/bin "));
	else
	{
		QString folder = QFileDialog::getExistingDirectory( this, tr("A-ISO::Select Folder to transform in a bootable ISO"), QDir::home().path() );
		if(!folder.isNull() )
		{
	 	 QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save ISO file"),
				QDir::home().path() + "/aiso_bootable" ,
				tr("Images (*.iso)"));
		 
		 if (!fileName.isNull() )
		 {
			fileName.append( ".iso" );
			QMessageBox msgBox;
			msgBox.setText(tr("Select Boot File Type:"));
			QPushButton *connectButton = msgBox.addButton(tr("GRUB"), QMessageBox::ActionRole);
			QPushButton *connectButton2 = msgBox.addButton(tr("Manual"), QMessageBox::ActionRole);
			//msgBox.setStandardButtons(QMessageBox::("ISO File") | QMessageBox::("CD/DVD"));
			msgBox.exec();
 				if (msgBox.clickedButton() == connectButton) {
				//funzione caso grub
				  QDir directoryToConvert( folder );
				  directoryToConvert.mkdir("boot");
				  directoryToConvert.cd( "boot" );
				  directoryToConvert.mkdir( "grub" );
				  directoryToConvert.cd( "grub" );
				  stage2_eltorito.copy( folder + "boot/grub/stage2_eltorito" );//inserisce stage2_eltorito in boot/grub
				  MKisofs.start( "mkisofs", QStringList() << "-R" << "-b" << "boot/grub/stage2_eltorito" << "-no-emul-boot" << "-boot-load-size 4" << "-boot-info-table" << "-o" << fileName << folder );
				   progBarra();
				 }
 				else if (msgBox.clickedButton() == connectButton2) {
				 //funzione caso manual
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
					 directoryToConvert.mkdir( "acetoneiso" );
					 directoryToConvert.cd( "acetoneiso" );
					 boot_file.copy( folder + "boot/acetoneiso/" + boot_file_info.fileName() );
					MKisofs.start("mkisofs", QStringList() << "-R" << "-b" << ( "boot/acetoneiso/" + boot_file_info.fileName() ) << "-no-emul-boot" << "-boot-load-size 4" << "-boot-info-table" << "-o" << fileName << folder );
					progBarra();
					}
 				 }

			}
	        }

        }
} 
