void MainWindow::unplay()
{
QDir Home = QDir::home();
QDir Temp = QDir::temp();
Temp.cd("acetoneiso");
QFile dvd_temp( Temp.path() + "/dvd" );
QFile cover( Temp.path() + "/cov.jpg" );
QDir virtual_dvd_drive( Home.path() + "/virtual-drives" + "/dvd" );
FUsermount.start("fusermount", QStringList() << "-u" << "-z" << virtual_dvd_drive.path() );
//label_dvd2->clear();
dvd_temp.remove();
cover.remove();
dvdLabel->setPixmap(QPixmap(":/images/play.png"));
//button_saveCover->setVisible(false);
QFile file_xml( Temp.path() + "/xml.xml" );
file_xml.remove();
}
