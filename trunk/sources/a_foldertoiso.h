 
void MainWindow::foldertoiso()
{
QFile mkisofs;
mkisofs.setFileName("/usr/bin/mkisofs");

QDir Home = QDir::home();
QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString str1 = in.readLine();
   QString str2 = in.readLine();
   QString str3 = in.readLine();

if (mkisofs.exists())
	{
   
    QDir Home = QDir::home();
	 QString folder = QFileDialog::getExistingDirectory(this, tr("A-ISO::Select Folder to be Converted"),
                                                 Home.path());
		if (!folder.isEmpty() )
		{
		 	QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save ISO"),
										Home.path() + "/A_ISO",
										tr("Images (*.iso)"));
			
			if ( fileName.isNull() )
			{
			}
			else
			{
			fileName.append(".iso");
				
				if(str1.contains("standard", Qt::CaseInsensitive)) {
				MKisofs.start("mkisofs",QStringList() << "-R" << "-J" << "-o" << fileName << folder  );
				progBarra();
			
								}
				else {
			
			   	bool ok;
           			QString text = QInputDialog::getText(this, tr("ISO ID"),
                                tr("Please insert an ID for the ISO"), QLineEdit::Normal,
                                tr(""), &ok);

				if (!ok){
		  		}
				else{
	
		  		MKisofs.start("mkisofs",QStringList()  << "-R" << "-J" << "-V" << text << "-o" << fileName << folder  );
		   		progBarra();
		  		}

				}
			}
		}
	}
else
QMessageBox::warning(this, "A-ISO::Warning!",tr("no mkisofs found in /usr/bin"));

}

