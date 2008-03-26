

#include <QApplication>
#include <QDir>

#include "mainwindow.h"

int main(int argc, char *argv[])
{

QDir Temp = QDir::temp();
  Temp.mkdir("acetoneiso");

  QDir Home = QDir::home();
  Home.mkdir("virtual-drives");
  Home.cd("virtual-drives");
  Home.mkdir("1");
  Home.mkdir("2");
  Home.mkdir("3");
  Home.mkdir("4");
  Home.mkdir("5");
  Home.mkdir("6");
  Home.mkdir("7");
  Home.mkdir("dvd");
  Home.mkdir("../.acetoneiso");
  Home.cd(".acetoneiso");

    QApplication app(argc, argv);
    MainWindow window;
   // window.openImage(":/images/example.jpg");
    window.show();
    return app.exec();
}
