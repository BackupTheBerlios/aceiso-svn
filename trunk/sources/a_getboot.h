void MainWindow::getboot()
{
QDir Home = QDir::home();
QMessageBox msgBox;
msgBox.setText(tr("Select from where to extract Boot Image:"));
QPushButton *connectButton = msgBox.addButton(tr("ISO File"), QMessageBox::ActionRole);
QPushButton *connectButton2 = msgBox.addButton(tr("CD/DVD"), QMessageBox::ActionRole);
//msgBox.setStandardButtons(QMessageBox::("ISO File") | QMessageBox::("CD/DVD"));
msgBox.exec();
 if (msgBox.clickedButton() == connectButton) {
	QString iso = QFileDialog::getOpenFileName(this,tr("Open Image"), Home.path() , tr("Image Files (*.iso)"));
	if ( iso.isNull() ){
	}
	else{
		QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save boot image"),Home.path() + "/A-iso_extractedBoot" );
		if (!fileName.isNull() ){
			fileName.append(".boot");
			ELtorito.start("geteltorito", QStringList() << "-o" << fileName << iso );
			progBarra();
		}		
	    } 
	}
 else if (msgBox.clickedButton() == connectButton2) {
		QDir iso("/dev/cdrom");
		QString fileName = QFileDialog::getSaveFileName(this, tr("A-ISO::Save boot image"),Home.path() + "/A-iso_extractedBoot" );
		if (!fileName.isNull() ){
		 fileName.append(".boot");
		 ELtorito.start("geteltorito", QStringList() << "-o" << fileName << iso.path() );
		 progBarra();
		}
 }

} 
