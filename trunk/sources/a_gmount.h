void MainWindow::gmount()
{
QDir Home = QDir::home();
QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString stra = in.readLine();
   QString strb = in.readLine();
   QString strc = in.readLine();

   QFile Mtab("/etc/mtab");//dichiaro un file Mtab che sarebbe /etc/mtab
   Mtab.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QString str1 = (Mtab.readAll());//leggo il contenuto del file mtab
QString isodamontare;

isodamontare = QFileDialog::getOpenFileName(this,tr("Open Image"), Home.path() , tr("Image Files (*.iso *.nrg *.bin *.img *.mdf)"));

 if ( !isodamontare.isNull() )
{

  QString folder = QFileDialog::getExistingDirectory( this, tr("AcetoneISO2::Select where to mount image"), Home.path() );
if (!folder.isNull())
{
folder.chop(1);//casini del qt...il chop serve per togliere l'ultimo slash (/) dal percorso altrimenti in mtab non troverà mai il percorso con lo slash finale..
  if(!str1.contains( folder ) )
  {
  FUse.start("fuseiso",QStringList()  << isodamontare << folder << "-o" << "nonempty"  );
		if(strc.contains("kde", Qt::CaseInsensitive)) {
		BRowser.startDetached("kfmclient",QStringList() << "exec" << folder );
		}
		else {
		BRowser.startDetached("nautilus",QStringList() << folder );
		}
  }
  else
	QMessageBox::warning(this, "AcetoneISO2::Warning!",tr("The folder ") + folder + tr(" can't be mounted"));
}
} 
}
