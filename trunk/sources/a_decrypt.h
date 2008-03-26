 
void MainWindow::decrypt()
{
QDir Home = QDir::home();

QString immagine = QFileDialog::getOpenFileName(this,tr("A-ISO::Select Image to decrypt"), Home.path(), tr("Encrypted Image ( *.gpg)"));
	if (!immagine.isNull())
	{
GPg.start("gpg2", QStringList() << immagine );
progBarra();
	}
}
