void MainWindow::a_donate()
{
QDir Home = QDir::home();
QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");

   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString str1 = in.readLine();
   QString str2 = in.readLine();
   QString str3 = in.readLine();

if(str3.contains("kde", Qt::CaseInsensitive)) {
BRowser.startDetached( "kfmclient", QStringList() << "openURL" << "http://a-iso.helloweb.eu/" );
}
else{
QMessageBox::information(this, "AcetoneISO2", tr("missing...") );
}
}
