void MainWindow::mdatabase(QListWidgetItem *item)
{
QDir Home = QDir::home();


QFile database_file( Home.path() + "/.acetoneiso/database");
database_file.open(QIODevice::ReadOnly);
QString strr = (database_file.readAll());
QString isodamontare = ((strr) + (item->text()));//da ora ho in isodamontare il file con tutto il suo percorso.

QDir Temp = QDir::temp();
Temp.cd("acetoneiso");
QString percorsoTemp = Temp.path();
QFile Mtab("/etc/mtab");//dichiaro un file Mtab che sarebbe /etc/mtab
Mtab.open(QIODevice::ReadOnly);//lo apro in sola lettura
QString str1 = (Mtab.readAll());//leggo il contenuto del file mtab

QFileInfo fi(isodamontare);
QString onlyfile = fi.fileName();
QFile getfile;
getfile.setFileName(isodamontare);
qint64 bignum = getfile.size();

long int divide;
divide = (bignum / 1024) / 1024 ;

QString percorsovirtuale;
int x = 1;
while( x < 8 ) {
   if( !str1.contains( Home.path() + "/virtual-drives/" + QString::number( x ) ) ) {
      percorsovirtuale = ( Home.path() + "/virtual-drives/" + QString::number( x ) );
      Monta( isodamontare, percorsovirtuale );
         while( FUse.waitForFinished() ) { //aspetto che finisca il processo fuse per controllare se è stata montata
         }
         openBrowser( percorsovirtuale, onlyfile, divide, percorsoTemp );
      break;
   }
   else {
      x++;
   }
}
if( x == 8 ) {
      QMessageBox::warning(this, "A-ISO::Warning",tr("All Virtual Drives are busy,\n"
							"Unmount some Virtual Drive first!"));
   }
}
