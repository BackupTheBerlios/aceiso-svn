

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QListWidget>
#include <QLabel>
#include "sources/progress.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
   QListWidget *mntWidget;
   QListWidget *dbWidget;
   QLabel *dvdLabel;
   progressDiag prog;


public slots:
    void openImage(const QString &path = QString());
   void a_donate();
   void mount();
   void Monta( QString &image, QString &destination );
   void openBrowser( QString &destination, QString onlyfile, long int divide, QString &temporary );
   void gmount();
   void gumount();
   void umount();
   void open_mounted(QListWidgetItem *item);
   void md5check();
   void md5generate();
   void split();
   void merge();
   void progBarra();
   void closeProg();
   void printOutsplit(int,QProcess::ExitStatus);
   void printOutMACIMG(int, QProcess::ExitStatus);
   void message_extract_finish();
void zzofiga();
   void initial_get_database();
   void database();
   void foldertoiso();
   void about();
   void get_poweriso();
   void converter();
   void extract_poweriso();
   void messaggio_poweriso();
   void macimg();
   void extract();
   void mdatabase(QListWidgetItem *item);
   void printOut(int, QProcess::ExitStatus);
   void remove_fromDatabase();
   void encrypt();
   void decrypt();
   void printOutgpg(int, QProcess::ExitStatus);
   void compress();
   void uncompress();
   void printOutuncompress(int, QProcess::ExitStatus);
   void printOutcompress(int, QProcess::ExitStatus);
   void gencue();
   void isocd();
   void printOutisofromcd(int, QProcess::ExitStatus);
   void options();
   void manual();
   void psxrip();
   void backupaudio();
   void eltorito();
   void printOutpsx(int, QProcess::ExitStatus);
   void printOutbackaudio(int, QProcess::ExitStatus);
   void getboot();
   void elfloppy();
   void printOutfuseiso(int, QProcess::ExitStatus);
   void play();
   void dvdGui(QString &string);
   void unplay();
   void get_cover();
   void readXML();
   void display_cover();

private slots:

void pluginsRead(QMenu *pluginsMenu);

private:
   void setupMenus();
   void setupWidgets();
   void createStatusBar();

   QProcess BRowser;
   QProcess FUse;
   QProcess FUsermount;
   QProcess MD5;
   QProcess CAt;
   QProcess SPlit;
   QProcess MKisofs;
   QProcess POweriso;
   QProcess WGet;
   QProcess TAr;
   QProcess MAcimg;
   QProcess GPg;
   QProcess PZipuncompress;
   QProcess PZip;
   QProcess DD;
   QProcess UMountcdrom;
   QProcess PSxrip;
   QProcess BAckaudio;
   QProcess ELtorito;
   QProcess SMplayer;
   QProcess VLc;
   QProcess KAffeine;
   QProcess WGet1;
   QProcess WGet2;

};

#endif
