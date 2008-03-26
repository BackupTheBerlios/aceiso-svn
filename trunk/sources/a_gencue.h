void MainWindow::gencue()
{
QDir Home = QDir::home();
QString image = QFileDialog::getOpenFileName(this,tr("A-ISO::Select *bin or *img"), Home.path() , tr("Image Files (*.bin *.img)"));
 if ( image.isNull() )
{
}
else
{
QFileInfo image_file( image );
QString pathtoimage = ( image_file.absolutePath() );//percorso assoluto al file senza nome del file.
QString image_name( image_file.baseName() );//nome del file senza percorso nè estensione.
QFile f_cue( pathtoimage + "/" + image_name + ".cue" );
//qDebug() << f_cue.fileName();
QString contenutocue( "FILE " + image_file.fileName() + " BINARY\n"
			"TRACK 01 MODE1/2352\n"
			"INDEX 01 00:00:00\n");
//qDebug() << contenutocue;
f_cue.open(QIODevice::WriteOnly | QIODevice::Text);
QTextStream out(&f_cue);
out << contenutocue;
}
}
