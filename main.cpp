#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "app.h"
int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
   new App("amadou" ,"doumbia" , &app  ) ;
  return app.exec();
}
