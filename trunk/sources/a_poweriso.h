void MainWindow::get_poweriso()
{
QMessageBox msgBox;
msgBox.setText(tr("Do you want to download Poweriso?\nIf you click yes you accept PowerISO's Freeware Licence."));
 msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
 switch (msgBox.exec()) {
 case QMessageBox::Yes:
    {
	QDir acetone_bin = QDir::home();
	acetone_bin.cd(".acetoneiso");
	QDir::setCurrent( acetone_bin.path() );
	WGet.start("wget", QStringList() << "http://www.poweriso.com/poweriso-1.2.tar.gz" );
	connect(&WGet, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( extract_poweriso() ));
	progBarra();
     }
     break;
 case QMessageBox::No:
     QMessageBox::warning(this, "A-ISO",tr("Without Poweriso some functions will be unavailable!"));
     break;
 default:
     // should never be reached
     break;
 }
}


void MainWindow::extract_poweriso()
{
QDir acetone_bin = QDir::home();
acetone_bin.cd(".acetoneiso");
QDir::setCurrent( acetone_bin.path() );
TAr.start("tar", QStringList() << "-xf" << "poweriso-1.2.tar.gz");
}


void MainWindow::messaggio_poweriso()
{
QDir acetone_bin = QDir::home();
acetone_bin.cd(".acetoneiso");
QDir::setCurrent( acetone_bin.path() );
QFile poweriso_tar("poweriso-1.2.tar.gz");
poweriso_tar.remove();
QMessageBox::information(this, "A-ISO",tr("Poweriso downloaded and extracted!\nYou can now convert to iso "));
} 
