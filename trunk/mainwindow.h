

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

private slots:
   // void setCompleted();
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
    //QPixmap puzzleImage;
   // PiecesList *piecesList;
   // PuzzleWidget *puzzleWidget;
};

#endif