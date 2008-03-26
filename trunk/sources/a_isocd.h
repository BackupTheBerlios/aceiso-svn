 void MainWindow::isocd()
{
QMessageBox::question(this, "A-ISO::Warning!",tr("Please note that this tool only works for normal DATA CD/DVD.\n It won't work with Audio CD and Game CopyProtected cd's"));
QDir Home = QDir::home();
QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save ISO"),
										Home.path() + "/A_ISO",
										tr("Images (*.iso)"));

if ( fileName.isNull() )
{
}
else
{
fileName.append(".iso");
 
fileName.prepend("of=");
DD.start("dd", QStringList() << "if=/dev/cdrom" << fileName << "bs=1024" );
progBarra();
}
}
