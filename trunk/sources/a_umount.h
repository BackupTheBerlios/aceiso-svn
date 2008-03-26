void MainWindow::umount()
{
if (!mntWidget->currentItem() == 0)

{
QString oggetto(mntWidget->currentItem()->text());
QChar periferica(oggetto[4]);
QString f1_string(periferica);//
QDir percorso = ( (QDir::home()).path() + "/virtual-drives/" + periferica );
QDir Temp = QDir::temp();

QFile f1;
f1.setFileName( Temp.path() + "/acetoneiso/" + f1_string );

FUsermount.start("fusermount",QStringList() << "-u" << "-z" << percorso.path() );

int riga = mntWidget->currentRow() ;
mntWidget->takeItem( riga  );
f1.remove();
}
else
QMessageBox::warning(this, "A-ISO::Warning",tr( "select an image to unmount from the virtual-drives display" ));
}
