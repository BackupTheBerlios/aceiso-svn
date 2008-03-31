void MainWindow::play()
{
QFile Mtab("/etc/mtab");//dichiaro un file Mtab che sarebbe /etc/mtab
Mtab.open(QIODevice::ReadOnly);//lo apro in sola lettura
QString str1 = (Mtab.readAll());//leggo il contenuto del file mtab

   QDir Home = QDir::home();
   QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString stra = in.readLine();
   QString strb = in.readLine();
   QString strc = in.readLine();

QDir Temp = QDir::temp();
Temp.cd("acetoneiso");
//QDir Home = QDir::home();
QDir virtual_dvd_drive( Home.path() + "/virtual-drives" + "/dvd" );
if(str1.contains( virtual_dvd_drive.path() ) )//Caso che il dvd è già montato.
{
	if(strb.contains("kaffeine", Qt::CaseInsensitive)) {//Se nel radio button è selezionato kaffeine.
	   QString kaf_input(virtual_dvd_drive.path() );
	   kaf_input.prepend("dvd:/");
	   KAffeine.start("kaffeine", QStringList() << kaf_input );
	}
	else{				//Se nel radio button è selezionato vlc.
	   if(strb.contains("vlc", Qt::CaseInsensitive)) {
	      VLc.start("vlc", QStringList() << virtual_dvd_drive.path() );
	      }
	   else {
	      SMplayer.start( "smplayer", QStringList() << virtual_dvd_drive.path() );
	   }
	}
}
else{	//Caso che il dvd non è montato.
QString isodamontare = QFileDialog::getOpenFileName(this,tr("Select DVD-Movie to Play"), Home.path() , tr("DVD-Movie Image (*.iso *.bin *.img *.mdf *.nrg)"));
if ( !isodamontare.isNull() )
	{
	QFileInfo fi( isodamontare );
	QString onlyfile = fi.fileName();
	onlyfile.chop(4);
	QString percorsovirtuale = virtual_dvd_drive.path();
	Monta( isodamontare, percorsovirtuale ); //function defined in a_mount.h
	
	 if(strb.contains("kaffeine", Qt::CaseInsensitive)) {	//Se nel radio button è selezionato kaffeine.
	    QString kaf_input(virtual_dvd_drive.path());
	    kaf_input.prepend("dvd:/");
	    KAffeine.start("kaffeine", QStringList() << kaf_input );
            dvdGui( onlyfile);
	    }
	 else{					
	   if(strb.contains("vlc", Qt::CaseInsensitive)) { //Se nel radio button è selezionato vlc.
	      VLc.start("vlc", QStringList() << virtual_dvd_drive.path() );
	      dvdGui( onlyfile);
	   }
	   else {
	      	SMplayer.start("smplayer", QStringList() << virtual_dvd_drive.path() );
		dvdGui( onlyfile);
	   	}
	    }
	}
     }
}
 
void MainWindow::dvdGui( QString &string ) //questa funzione pulisce la label e ci riscrive il titolo del dvd.Infine richiama get_cover 
{
   QDir Temp = QDir::temp();
   Temp.cd("acetoneiso");
   //label->clear();
   //label->setText("DVD-Movie " + string + tr(" mounted"));
   QFile f1(Temp.path() + "/dvd");
   f1.open(QIODevice::WriteOnly | QIODevice::Text);
   QTextStream out(&f1);
   out << ( string );
   QTimer::singleShot(2000, this, SLOT(get_cover())); //QUI DEVO ASPETTARE CHE CREA IL FILE /TMP/ACETONEISO/DVD E POI FA COVER
}
