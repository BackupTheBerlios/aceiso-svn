void MainWindow::printOut(int, QProcess::ExitStatus)
	{
	int valore_uscita = MKisofs.exitCode();
	if(valore_uscita == 0)
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutpsx(int, QProcess::ExitStatus)
	{
	int valore_uscita = PSxrip.exitCode();
	if(valore_uscita == 0)
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutisofromcd(int, QProcess::ExitStatus)
	{
	int valore_uscita = DD.exitCode();
	if(valore_uscita == 0)
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutbackaudio(int, QProcess::ExitStatus)
	{
	int valore_uscita = BAckaudio.exitCode();
	if( valore_uscita == 0 )
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutcompress(int, QProcess::ExitStatus)
	{
	int valore_uscita = PZip.exitCode();
	if( valore_uscita == 0 )
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutuncompress(int, QProcess::ExitStatus)
	{
	int valore_uscita = PZipuncompress.exitCode();
	if( valore_uscita == 0 )
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}

/*
void MainWindow::printOutcue(int, QProcess::ExitStatus)
	{
	int valore_uscita = CUe.exitCode();
	if( valore_uscita == 0 )
	QMessageBox::information(this, "AcetoneISO2",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "AcetoneISO2","Process Error Code: " + QString::number(valore_uscita) );
	}
*/

void MainWindow::printOutsplit(int, QProcess::ExitStatus)
	{
	int valore_uscita = SPlit.exitCode();
	if( valore_uscita == 0 )
	QMessageBox::information(this, "AcetoneISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "AcetoneISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutgpg(int, QProcess::ExitStatus)
	{
	int valore_uscita = GPg.exitCode();
	if(valore_uscita == 0)
	QMessageBox::information(this, "A-ISO",tr("Operation succesfully finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::printOutfuseiso(int, QProcess::ExitStatus)
	{
	int valore_uscita = FUse.exitCode();
	if(!valore_uscita == 0)
	
	QMessageBox::critical (this, "A-ISO",tr("Error, could not mount image.\n\nSolution:\na) did you activate fuse? go here and read part c  http://www.acetoneiso.netsons.org/viewpage.php?page_id=4\nb) maybe the image is a multisector image. Try converting it under Convert tab of the main gui." ));
	}


void MainWindow::printOutMACIMG(int, QProcess::ExitStatus)
	{
	int valore_uscita = MAcimg.exitCode();
	if(valore_uscita == 0)
	QMessageBox::information(this, "A-ISO",tr("Operation succesfully finished!\n"
							"To mount the converted file, open a terminal and run as root:\n"
							"modprobe hfsplus\n"
							"mount -t hfsplus -o loop <converted-image.img> /folder_you_want"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) );
	}


void MainWindow::message_extract_finish()
	{
	int valore_uscita = POweriso.exitCode();
	if( valore_uscita == 0 )
	QMessageBox::information(this, "A-ISO",tr("Process Succesfully Finished!"));
	else
	QMessageBox::critical(this, "A-ISO","Process Error Code: " + QString::number(valore_uscita) + "\nIf you are trying to convert an image, maybe it is already ISO-9660.To check,open a terminal and type: file namefile.xxx"  );
	}

/*
void MainWindow::mergeMSG(int, QProcess::ExitStatus)
	{
	int valore_uscita = CAt.exitCode();
	if(valore_uscita == 0)
	QMessageBox::information(this, "AcetoneISO2",tr("Image succesfully merged"));
	else
	QMessageBox::critical(this, "AcetoneISO2","Process Error Code: " + QString::number(valore_uscita) );
	}*/
