#include "appviewer.h"
#include <qqmlengine.h>
#include <qqmlcontext.h>

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

void AppViewer::addContext(QString a, QObject * b )
{
    rootContext()->setContextProperty(a , b ) ;

}

QSize *AppViewer::demension() const
{
  return m_demension;
}
