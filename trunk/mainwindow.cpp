

#include <QtGui>
#include <stdlib.h>
#include <QtXml>

#include "mainwindow.h"
#include "sources/a_donate.h"
#include "sources/a_mount.h"
#include "sources/a_gmount.h"
#include "sources/a_gumount.h"
#include "sources/a_umount.h"
#include "sources/a_open_mounted.h"
#include "sources/a_md5check.h"
#include "sources/a_md5generate.h"
#include "sources/a_split.h"	//has merge function too
#include "sources/a_messages.h"
#include "sources/a_database.h"
#include "sources/a_foldertoiso.h"
#include "sources/about.h"
#include "sources/a_converter.h"
#include "sources/a_macimg.h"
#include "sources/a_extract.h"
#include "sources/a_mdatabase.h"
#include "sources/a_encrypt.h"
#include "sources/a_decrypt.h"
#include "sources/a_compress.h"
#include "sources/a_gencue.h"
#include "sources/a_isocd.h"
#include "sources/options.h"
#include "sources/manual.h"
#include "sources/a_psxrip.h"
#include "sources/a_backup_audio.h"
#include "sources/a_eltorito.h"
#include "sources/a_getboot.h"
#include "sources/a_elfloppy.h"
#include "sources/a_play.h"
#include "sources/a_unplay.h"
#include "sources/a_dvd_cover.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupMenus();
    setupWidgets();
    //createStatusBar();
    QIcon windowico(":/images/Acetino2.png");
    setWindowIcon(windowico);
    setMinimumSize(400,280);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setWindowTitle(tr("A-ISO"));

    connect( &MKisofs, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );
    connect( &MKisofs, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOut(int, QProcess::ExitStatus)));

    connect( &SPlit, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( closeProg() ));
    connect( &SPlit, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutsplit(int, QProcess::ExitStatus)));

    connect( &TAr, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );
    connect( &TAr, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(messaggio_poweriso()));

    connect( &MAcimg, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( closeProg() ));
    connect( &MAcimg, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( printOutMACIMG(int, QProcess::ExitStatus) ) );

    connect( &POweriso, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );
    connect( &POweriso, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( message_extract_finish() ) );

    connect( &GPg, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );
    connect( &GPg, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutgpg(int, QProcess::ExitStatus)));

    connect( &PZipuncompress, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( closeProg() ));
    connect( &PZipuncompress, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutuncompress(int, QProcess::ExitStatus)));

    connect( &PZip, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( closeProg() ));
    connect( &PZip, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutcompress(int, QProcess::ExitStatus)));

    connect( &DD, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( closeProg() ));
    connect( &DD, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutisofromcd(int, QProcess::ExitStatus)));

    connect( &PSxrip, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );
    connect( &PSxrip, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutpsx(int, QProcess::ExitStatus)));

    connect( &BAckaudio, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT( closeProg() ));
    connect( &BAckaudio, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutbackaudio(int, QProcess::ExitStatus)));

    connect( &ELtorito, SIGNAL( finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );

    connect( &FUse, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(printOutfuseiso(int, QProcess::ExitStatus)));

    connect( &WGet2, SIGNAL( finished(int, QProcess::ExitStatus)), this,SLOT( closeProg() ) );

    initial_get_database();
}

void MainWindow::openImage(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "", "Image Files (*.png *.jpg *.bmp)");

    if (!fileName.isEmpty()) {
        QPixmap newImage;
        if (!newImage.load(fileName)) {
            QMessageBox::warning(this, tr("Open Image"),
                                  tr("The image file could not be loaded."),
                                  QMessageBox::Cancel);
            return;
        }

    }
}


void MainWindow::setupMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

       QAction *optionsAction = fileMenu->addAction(tr("&Options"));
       optionsAction->setShortcut(QKeySequence(tr("Ctrl+O")));

       QMenu *recentMenu = fileMenu->addMenu(tr("&Recently mounted images"));
       fileMenu->addSeparator();
       QAction *exitAction = fileMenu->addAction(tr("E&xit"));
       exitAction->setShortcut(QKeySequence(tr("Ctrl+Q")));

    QMenu *utilitiesMenu = menuBar()->addMenu(tr("&Utilities"));

       QMenu *genericMntMenu = utilitiesMenu->addMenu(tr("U&ser Mount"));
          QAction *mountAction = genericMntMenu->addAction(tr("Mount"));
          QAction *umountAction = genericMntMenu->addAction(tr("Umount"));
       //genericMntAction->setShortcut(QKeySequence(tr("Ctrl+S")));
       QMenu *md5Menu = utilitiesMenu->addMenu(tr("Md5 Sum"));
          QAction *md5Action = md5Menu->addAction(tr("Generate to file"));
          QAction *md5CheckAction = md5Menu->addAction(tr("Check"));
       QMenu *splitMenu = utilitiesMenu->addMenu(tr("Split Image"));
          QAction *splitAction = splitMenu->addAction(tr("Split"));
          QAction *mergeAction = splitMenu->addAction(tr("Merge Splitted Image"));
       QMenu *encryptMenu = utilitiesMenu->addMenu(tr( "Encrypt Image" ));
          QAction *encryptAction = encryptMenu->addAction(tr("Encrypt"));
          QAction *decryptAction = encryptMenu->addAction(tr("Decrypt"));
       QMenu *compressMenu = utilitiesMenu->addMenu(tr("Compress Image"));
          QAction *compressAction = compressMenu->addAction(tr("Compress"));
          QAction *uncompressAction = compressMenu->addAction(tr("Uncompress"));
       QAction *gencueAction = utilitiesMenu->addAction(tr("Generate Cue for BIN/IMG images"));

    QMenu *conversionMenu = menuBar()->addMenu(tr("&Conversion"));
       QAction *imgtoisoAction = conversionMenu->addAction(tr("Convert &Image to ISO"));
       QAction *macosAction = conversionMenu->addAction(tr("Convert MacOs Image"));
       QAction *extractAction = conversionMenu->addAction(tr("Extract Image Content to a folder"));
       QAction *gencdAction = conversionMenu->addAction(tr("Generate ISO from CD/DVD"));
       QAction *isofromfolderAction = conversionMenu->addAction(tr("Generate ISO from folder"));
       QAction *psxripAction = conversionMenu->addAction(tr("Rip a PSX1 game for epsxe/psx emulators"));
       QAction *bkaudioAction = conversionMenu->addAction(tr("Backup CD-Audio"));

    QMenu *eltoritoMenu = menuBar()->addMenu(tr("&Boot"));
       QAction *extractbootAction = eltoritoMenu->addAction(tr("Extract Boot Image"));
       QAction *floppyemuAction = eltoritoMenu->addAction(tr("Generic Floppy-Emulation"));
       QAction *noemuAction = eltoritoMenu->addAction(tr("Generic No-Emulation"));

    QMenu *pluginsMenu = menuBar()->addMenu(tr("&Plugins"));
       QAction *managePluginAction = pluginsMenu->addAction(tr("Manage Plugins"));
       pluginsMenu->addSeparator();
       pluginsRead(pluginsMenu);//TODO: add some function here to add menu items if a plugin is installed.

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
       QAction *manualAction = helpMenu->addAction(tr("Manual"));
       QAction *aboutAction = helpMenu->addAction(tr("About"));


    connect( exitAction,   SIGNAL(triggered()), qApp, SLOT(quit()));
    connect( mountAction,  SIGNAL( triggered() ), this, SLOT( gmount() ) );
    connect( umountAction, SIGNAL( triggered() ), this, SLOT( gumount() ));
    connect( md5Action,    SIGNAL( triggered() ), this, SLOT( md5generate() ));
    connect( md5CheckAction, SIGNAL( triggered() ), this, SLOT( md5check() ));
    connect( splitAction,   SIGNAL( triggered() ), this, SLOT( split() ));
    connect( mergeAction,   SIGNAL( triggered() ), this, SLOT( merge() ));
    connect( isofromfolderAction, SIGNAL( triggered() ), this, SLOT( foldertoiso() ) );
    connect( aboutAction,   SIGNAL( triggered() ), this, SLOT( about() ) );
    connect( imgtoisoAction, SIGNAL( triggered() ), this, SLOT( converter() ) );
    connect( macosAction,   SIGNAL( triggered() ), this, SLOT( macimg() ) );
    connect( extractAction, SIGNAL( triggered() ), this, SLOT( extract() ) );
    connect( encryptAction, SIGNAL( triggered() ), this, SLOT( encrypt() ) );
    connect( decryptAction, SIGNAL( triggered() ), this, SLOT( decrypt() ) );
    connect( compressAction,   SIGNAL( triggered() ), this, SLOT( compress() ) );
    connect( uncompressAction, SIGNAL( triggered() ), this, SLOT( uncompress() ) );
    connect( gencueAction,     SIGNAL( triggered() ), this, SLOT( gencue() ) );
    connect( gencdAction,      SIGNAL( triggered() ), this, SLOT( isocd() ) );
    connect( optionsAction,    SIGNAL( triggered() ), this, SLOT( options() ) );
    connect( manualAction,     SIGNAL( triggered() ), this, SLOT( manual() ) );
    connect( psxripAction,     SIGNAL( triggered() ), this, SLOT( psxrip() ) );
    connect( bkaudioAction,     SIGNAL( triggered() ), this, SLOT( backupaudio() ) );
    connect( noemuAction, SIGNAL( triggered() ), this, SLOT( eltorito() ) );
    connect( extractbootAction, SIGNAL( triggered() ), this, SLOT( getboot() ) );
    connect( floppyemuAction,   SIGNAL( triggered() ), this, SLOT( elfloppy() ) );

}



void MainWindow::setupWidgets()
{
QIcon mountIcon( ":/images/mount.png" );
QIcon databaseIcon( ":/images/db.png" );
QIcon playIcon( ":/images/play.png" );
QPixmap dvdPixmap( ":/images/play.png" );

 QToolBar *fileTools = addToolBar(tr("File Tool Bar"));
  fileTools->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QAction *mountAction = fileTools->addAction( mountIcon, tr("Mount") );
    QAction *databaseAction = fileTools->addAction( databaseIcon, tr("Database") );
    QAction *PlayAction = fileTools->addAction( playIcon, tr("Play") );


QPushButton *mountF = new QPushButton(tr("Mount") );		//funzioni
QPushButton *umountF = new QPushButton(tr("Umount") );
QPushButton *donate = new QPushButton(tr("Donate") );

QPushButton *setdb = new QPushButton(tr("Set database") );
QPushButton *delImage = new QPushButton(tr("Delete image") );
QPushButton *updb = new QPushButton(tr("Update DB") );

QPushButton *playdvd = new QPushButton(tr("Play DVD-Movie ISO") );
QPushButton *umountdvd = new QPushButton(tr("Umount DVD-Movie") );

mntWidget = new QListWidget;	//display del mount
dbWidget = new QListWidget;	//display del database
dvdLabel = new QLabel;
dvdLabel->setPixmap( dvdPixmap );

QFrame *frame = new QFrame;	//frame principale(sfondo)
QFrame *frame3 = new QFrame;	//frame dei bottoni funzione del mount
QFrame *frame4 = new QFrame;	//frame dei bottoni funzione del database
QFrame *frame5 = new QFrame;	//frame dei bottoni funzione del play

QVBoxLayout *verticalLayout = new QVBoxLayout;		//layout generale della finestra
QHBoxLayout *hLayout = new QHBoxLayout;			//layout dei bottoni del mount
QHBoxLayout *dbLayout = new QHBoxLayout;		//layout dei bottoni del database
QHBoxLayout *playLayout = new QHBoxLayout;		//layout dei bottoni del play


//***BOTTONI FUNZIONE DEL MOUNT***//
hLayout->addWidget(mountF);
hLayout->addWidget(umountF);
hLayout->addStretch(2);
hLayout->addWidget(donate);
frame3->setLayout( hLayout );

//***BOTTONI FUNZIONE DEL DATABASE***//
dbLayout->addWidget(setdb);
dbLayout->addWidget(delImage);
//dbLayout->addStretch(1);
dbLayout->addWidget(updb);
frame4->setLayout( dbLayout );

//***BOTTONI FUNZIONE DEL PLAY***//
playLayout->addWidget(playdvd);
playLayout->addWidget(umountdvd);
//dbLayout->addStretch(1);
frame5->setLayout( playLayout );

//***GRAFICA GENERALE DELLA FINESTRA***//
verticalLayout->addWidget( mntWidget );
verticalLayout->addWidget(frame3);

verticalLayout->addWidget( dbWidget );
verticalLayout->addWidget(frame4);

verticalLayout->addWidget( dvdLabel );
verticalLayout->addWidget(frame5);

frame4->setVisible(false);
dbWidget->setVisible(false);

dvdLabel->setVisible( false );
frame5->setVisible(false);

frame -> setLayout( verticalLayout );

   setCentralWidget(frame);



   connect( mountAction, SIGNAL ( triggered() ), mntWidget, SLOT (show()));
   connect( mountAction, SIGNAL ( triggered() ), frame3, SLOT (show()));
   connect( mountAction, SIGNAL ( triggered() ), frame4, SLOT (hide()));
   connect( mountAction, SIGNAL ( triggered() ), dbWidget, SLOT (hide()));
   connect( mountAction, SIGNAL ( triggered() ), frame5, SLOT (hide()));
   connect( mountAction, SIGNAL ( triggered() ), dvdLabel, SLOT (hide()));

   connect( databaseAction, SIGNAL ( triggered() ), frame3, SLOT (hide()));
   connect( databaseAction, SIGNAL ( triggered() ), mntWidget, SLOT (hide()));
   connect( databaseAction, SIGNAL ( triggered() ), dbWidget, SLOT (show()));
   connect( databaseAction, SIGNAL ( triggered() ), frame4, SLOT (show()));
   connect( databaseAction, SIGNAL ( triggered() ), frame5, SLOT (hide()));
   connect( databaseAction, SIGNAL ( triggered() ), dvdLabel, SLOT (hide()));
   connect( databaseAction, SIGNAL ( triggered() ), this, SLOT (initial_get_database()));//UPDATE DATABASE WHEN CLICK THE DB TOOLBUTTON

   connect( PlayAction, SIGNAL ( triggered() ), mntWidget, SLOT (hide()));
   connect( PlayAction, SIGNAL ( triggered() ), frame3, SLOT (hide()));
   connect( PlayAction, SIGNAL ( triggered() ), frame4, SLOT (hide()));
   connect( PlayAction, SIGNAL ( triggered() ), dbWidget, SLOT (hide()));
   connect( PlayAction, SIGNAL ( triggered() ), frame5, SLOT (show()));
   connect( PlayAction, SIGNAL ( triggered() ), dvdLabel, SLOT (show()));

   connect( donate, SIGNAL ( clicked() ), this, SLOT ( a_donate() ) );
   connect( mountF, SIGNAL ( clicked() ), this, SLOT ( mount() ) );
   connect( umountF, SIGNAL ( clicked() ), this, SLOT ( umount() ) );
   connect( mntWidget, SIGNAL( itemDoubleClicked (QListWidgetItem *) ), this, SLOT(open_mounted(QListWidgetItem *) ) );

   connect( setdb, SIGNAL( clicked() ), this, SLOT( database() ));

   connect( dbWidget, SIGNAL( itemDoubleClicked (QListWidgetItem *) ), this, SLOT(mdatabase(QListWidgetItem *) ) );
   connect( updb, SIGNAL( clicked() ), this, SLOT( initial_get_database() ) );
   connect( delImage, SIGNAL( clicked() ), this, SLOT( remove_fromDatabase() ) );

   connect( playdvd, SIGNAL( clicked() ), this, SLOT( play() ) );
   connect( umountdvd, SIGNAL( clicked() ), this, SLOT( unplay() ) );
}


 void MainWindow::createStatusBar()
 {
QPushButton *button =new QPushButton(tr("ciao"));
   QLabel *dvdStatus = new QLabel;
   dvdStatus->setText(tr("DVD-ISO Movie not mounted"));

   statusBar()->addWidget(dvdStatus);
   statusBar()->addWidget(button);
    // statusBar()->showMessage(tr("Ready"));
 }

void MainWindow::progBarra()
{
 //     prog.show();
	//prog = new progressDiag;
	prog.show();
}


void MainWindow::closeProg()
{
prog.close();
}

void MainWindow::pluginsRead(QMenu *pluginsMenu)
{

//QAction *plgAction;
QDir Home = QDir::home();
Home.cd(".acetoneiso/plugins");
QStringList pluginList = Home.entryList(QDir::Files); //dopo metto QDir::Executable
int s = pluginList.size();
int n;
for( n = 0; n < s ; ++n) {
     pluginsMenu->addAction(pluginList[n], this, SLOT(zzofiga()));
   }


}

void MainWindow::zzofiga()
{
system("/home/hotbird/.acetoneiso/plugins/Amount");
}

void MainWindow::about()
{
	aboutDiag *abt=new aboutDiag;
	abt->exec();
}

void MainWindow::options()
{
	optionsDiag *opt=new optionsDiag;
	opt->exec();
}


void MainWindow::manual()
{
	manualDiag *man=new manualDiag;
	man->exec();
}


