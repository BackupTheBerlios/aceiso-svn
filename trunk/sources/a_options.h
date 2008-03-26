/*Here is the function to read the options in ~/.acetoneiso/acetoneiso.conf file*/
#include"options.h"
//#include"../acetoneiso.h"
#include <QtGui> 
void optionsDiag::optionss()
{
QDir Home = QDir::home();
QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
if( file.exists() ) {
   file.open(QIODevice::ReadOnly);//lo apro in sola lettura
   QTextStream in(&file);
   QString str1 = in.readLine();
   QString str2 = in.readLine();
   QString str3 = in.readLine();

   if(str1.contains("standard", Qt::CaseInsensitive)) {
      radioButton_5->setChecked(true);
   }
   else {
      radioButton_6->setChecked(true);
   }

   if(str2.contains("kaffeine", Qt::CaseInsensitive)) {
      radioButton_7->setChecked(true);
   }
   else {
      if(str2.contains("vlc", Qt::CaseInsensitive)) {
         radioButton_8->setChecked(true); //Caso vlc
      }
      else {
         radioButton->setChecked(true); //caso SMPlayer
      }
   }

   if(str3.contains("kde", Qt::CaseInsensitive)) {
      radioButton_9->setChecked(true);
   }
   else {
      radioButton_10->setChecked(true);
   }
 }
else {
   file.open(QIODevice::WriteOnly | QIODevice::Text);
   QTextStream out(&file);
   out << ( "ISO_FROM_FOLDER = standard\n" );
   out << ( "PLAYER = kaffeine\n" );
   out << ( "FILE_BROWSER = kde\n" );
   file.close();
   optionss();/*funzione ricorsiva lol lol lol lol lol lol lol .....lol così le impostazioni vengono applicate appena create!!!*/
 }
} 

void optionsDiag::update_options()
{
QDir Home = QDir::home();
QFile file(Home.path() + "/.acetoneiso/acetoneiso.conf");
file.open(QIODevice::ReadWrite );

if( radioButton_5->isChecked() ) {
   QTextStream out(&file);
   out << ( "ISO_FROM_FOLDER = standard\n" );
   }
else {
   QTextStream out(&file);
   out << ( "ISO_FROM_FOLDER = user    \n" );
   }

if( radioButton_7->isChecked() ) {
   QTextStream out(&file);
   out << ( "PLAYER = kaffeine\n" );
   }
else {
      if( radioButton_8->isChecked() ) {
         QTextStream out(&file);
         out << ( "PLAYER = vlc     \n" );
         }
      else {
         QTextStream out(&file);
         out << ( "PLAYER = smplayer \n" );
         }
      }

if( radioButton_9->isChecked() ) {
   QTextStream out(&file);
   out << ( "FILE_BROWSER = kde  \n" );
   }
else {
   QTextStream out(&file);
   out << ( "FILE_BROWSER = other\n" );
   }

}

