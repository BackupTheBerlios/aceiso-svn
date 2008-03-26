void MainWindow::open_mounted(QListWidgetItem *item)
{
QDir Home = QDir::home();//entro nella home utente

QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString stra = in.readLine();
   QString strb = in.readLine();
   QString strc = in.readLine();

Home.cd("virtual-drives");//dalla home utente alla cartella virtual-drives
QString vd_number(item->text());//prendo il testo dell'item selezionato
QChar periferica (vd_number[4]);//dal testo dell'item prendo il quarto carattere che mi da il numero di periferica virtuale.
Home.cd(periferica);//da virtual-drives entro in "numero della periferica virtuale"...
QDir::setCurrent( Home.path() );//setto come cartella corrente /home/nomeutente/virtual-drives/n con n numero periferica.

if(strc.contains("kde", Qt::CaseInsensitive)) {
BRowser.start("kfmclient",QStringList() << "exec" << Home.path() );
}
else {
BRowser.start("nautilus",QStringList() << Home.path() );
}
}
