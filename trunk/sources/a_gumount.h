void MainWindow::gumount()
{
QDir Home = QDir::home();
QFile Mtab("/etc/mtab");//dichiaro un file Mtab che sarebbe /etc/mtab
Mtab.open(QIODevice::ReadOnly);//lo apro in sola lettura
QString str1 = (Mtab.readAll());//leggo il contenuto del file mtab
QString folder = QFileDialog::getExistingDirectory( this, tr("AcetoneISO2::Select folder to unmount"), Home.path() );
folder.chop(1);
if(str1.contains( folder ) )
	{
	FUsermount.start("fusermount",QStringList() << "-u" << "-z" << folder );
	}
	else
	{
	QMessageBox::warning(this, "AcetoneISO2::Warning!",tr("The folder ") + folder + tr(" is not mounted!"));
	}
}
