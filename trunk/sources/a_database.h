void MainWindow::database()
{
 QDir Home = QDir::home();
 QString database_folder = QFileDialog::getExistingDirectory(this, tr("AcetoneISO2::Select Database Folder"),
                                                 Home.path() );
if ( database_folder.isNull() )
	{
	}
	else
	{
	 Home.cd(".acetoneiso");
	 QDir::setCurrent( Home.path() );
	 QFile database_file;
	 database_file.setFileName("database");
	
		if (!database_file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
		QTextStream out(&database_file);//apro il file database_file e ci scrivo dentro la stringa contenuta in database_folder
		out << (database_folder);

		QDir datfolder(database_folder);//dichiaro una cartella datfolder che ha il percorso di database_folder.mi servirà per l'entryList.
 

		dbWidget->clear();
		QStringList filters;
		filters << "*.iso" << "*.nrg" << "*.bin" << "*.img" << "*.mdf";
		datfolder.setNameFilters(filters);
		QString listaa;
		int position = 1;
		foreach (listaa, datfolder.entryList( QStringList(filters), QDir::Files ))
			{
			 dbWidget->insertItem(position, listaa);
			 position = position + 1 ;
			}

	}
}



void MainWindow::initial_get_database()
{
		QDir Home = QDir::home();
		Home.cd(".acetoneiso");
		QDir::setCurrent( Home.path() );
		QFile database_folder("database");
		database_folder.open(QIODevice::ReadOnly);//lo apro in sola lettura
		QString str1 = (database_folder.readAll());
		QDir datfolder(str1);
		dbWidget->clear();
		QStringList filters;
		filters << "*.iso" << "*.nrg" << "*.bin" << "*.mdf" << "*.img";
		datfolder.setNameFilters(filters);
		QString listaa;
		int position = 1;
		foreach (listaa, datfolder.entryList( QStringList(filters), QDir::Files ))
			{
			 dbWidget->insertItem(position, listaa);
			 position = position + 1 ;
			}
}

void MainWindow::remove_fromDatabase()
{
if ( !dbWidget->currentItem() == 0 )
	{
	QDir Home = QDir::home();
	Home.cd(".acetoneiso");
	QDir::setCurrent( Home.path() );
	QFile db_file("database");
	db_file.open( QIODevice::ReadOnly );
	QString str1 = ( db_file.readAll() );
	QDir datfolder( str1 );//dichiaro la directory del database
	QString oggetto( dbWidget->currentItem()->text() );//immagine selezionata 
	QFile immagine_corrente( str1 + oggetto );

	int riga = dbWidget->currentRow() ;
	dbWidget->takeItem( riga  );

	immagine_corrente.remove();
	}
else
QMessageBox::warning(this, "A-ISO::Warning",tr( "select an image to delete" ));
}


