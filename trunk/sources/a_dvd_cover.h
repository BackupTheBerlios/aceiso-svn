void MainWindow::get_cover()
	{
	QDir Temp = QDir::temp();
	Temp.cd("acetoneiso");
	QFile f1(Temp.path() + "/dvd");
	f1.open(QIODevice::ReadOnly);//lo apro in sola lettura
	QString strg = (f1.readAll());//leggo il contenuto di f1 ossia di /tmp/acetoneiso/dvd e va in una stringa strg.
	
	QString url = ("http://xml.amazon.com/onca/xml3?t=webservices-20&dev-t=D1URM11J3F2CEH&KeywordSearch=" + strg + "&mode=dvd-uk&type=lite&locale=uk&page=1&f=xml");
	
	progBarra();
	WGet1.start("wget", QStringList() << url << "-O" << (Temp.path() + "/xml.xml") );
	connect(&WGet1, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( readXML() ) );
	}


void MainWindow::readXML()
	{
	QDir Temp = QDir::temp();
	Temp.cd("acetoneiso");
	QFile file;
	file.setFileName(Temp.path() + "/xml.xml");
	
	QDomDocument doc;
	doc.setContent( &file );
	const QDomNode details = doc.documentElement().namedItem( "Details" );
	QDomNode node = doc.documentElement().namedItem( "Details" );
	QString coverUrl = node.namedItem( "ImageUrlLarge" ).firstChild().toText().nodeValue(); //link alla copertina
	if(!coverUrl.isNull()){
	WGet2.start("wget", QStringList() << coverUrl << "-O" << (Temp.path() + "/cov.jpg") );
	connect(&WGet2, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( display_cover() ) );
	}
	else {
	      closeProg();
	   }
	}


void MainWindow::display_cover()
	{
	QDir Temp = QDir::temp();
	Temp.cd("acetoneiso");
	QFile file( Temp.path() + "/cov.jpg" );    //dichiaro  file di tipo QFile per poter gestire l'esistenza
	QPixmap cover( Temp.path() + "/cov.jpg" ); //stabilisco la pixmap e la chiamo cover per poterla ridimensionare dopo
	if (file.exists())             //se file esiste, significa che la foderina è stata trovata
	{
	dvdLabel->setPixmap( cover.scaled( 160, 193 ) );//scalo la pixmap per farla entrare nella label
	//button_saveCover->setVisible(true);
	}
	else
	{
	dvdLabel->setPixmap(QPixmap(":/images/default.png"));//caso che la foderina non è stata trovata, inserisce immagine di default
	}
	}
 
