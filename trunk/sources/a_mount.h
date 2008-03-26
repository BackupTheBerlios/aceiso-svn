#include "../mainwindow.h"

void MainWindow::mount()
{
QDir Temp = QDir::temp();
Temp.cd("acetoneiso");
QString percorsoTemp = Temp.path();
QFile Mtab("/etc/mtab");//dichiaro un file Mtab che sarebbe /etc/mtab
Mtab.open(QIODevice::ReadOnly);//lo apro in sola lettura
QString str1 = (Mtab.readAll());//leggo il contenuto del file mtab
QDir Home = QDir::home();// entro nella home dell'utente
QString isodamontare;
isodamontare = QFileDialog::getOpenFileName(this,tr("Open Image"), Home.path() , tr("Image Files (*.iso *.nrg *.bin *.img *.mdf)"));
if ( isodamontare.isNull() )  {
   }
else
{
QString percorsovirtuale;
QFileInfo fi(isodamontare);
QString onlyfile = fi.fileName();
QFile getfile;
getfile.setFileName(isodamontare);
qint64 bignum = getfile.size();

long int divide;
divide = (bignum / 1024) / 1024 ;
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
}

void MainWindow::Monta( QString &image, QString &destination )
{
FUse.start("fuseiso",QStringList()  << image << destination << "-o" << "nonempty"  );
}

void MainWindow::openBrowser( QString &destination, QString onlyfile, long int divide, QString &temporary )
{
QDir Home = QDir::home();
QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString stra = in.readLine();
   QString strb = in.readLine();
   QString strc = in.readLine();

QDir destDir( destination );

if( destDir.count() > 2 ) { //se il contenuto della cartella montata non è nullo
QIcon icona( ":/images/Aiso2.png");
	QDir Dest( destination ); 
	QString name = Dest.dirName(); // voglio il nome della periferica virtuale per sapere quale item inserire 
	mntWidget->insertItem(name.toInt(), " VD-" + name + " " + onlyfile + "  " + QString::number(divide, 10) + "MB");


	QFile f1(temporary + "/" + name);
	f1.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&f1);
	out << (" VD-" + name + " " + onlyfile + "  " + QString::number(divide, 10) + "MB");
        if(strc.contains("kde", Qt::CaseInsensitive)) { 	// se nelle impostazioni ho come browser kde 
	BRowser.startDetached("kfmclient",QStringList() << "exec" << destination );
	}
	else {
	BRowser.startDetached("nautilus",QStringList() << destination );
	}
   }
}
