#include "appviewer.h"

AppViewer::AppViewer(QObject *parent): QQmlApplicationEngine(parent)
{

//  m_ViewEngine =  new QQmlApplicationEngine(this) ;
load(QUrl(QLatin1String("qrc:/main.qml")));
//  connect(m_ViewEngine,SIGNAL(quit() , this , )
}

void AppViewer::setDemension(QSize *demension)
{
  m_demension = demension;


}

bool AppViewer::addContext(QString a, QObject * b )
{
return true ;
}

QSize *AppViewer::demension() const
{
  return m_demension;
}
