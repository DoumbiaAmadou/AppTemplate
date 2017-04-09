#include "app.h"

App::App(QString Organisation, QString ApplicationName, QObject *parent) : QObject(parent)
{
  m_OrganisationName= Organisation;
  m_ApplicationName= ApplicationName;


  Initializer();

}

QString App::getApplicationName() const
{
  return m_ApplicationName ;

}

QString App::getOrganisationName() const
{
  return m_OrganisationName ;
}

void App::Initializer(){

  m_Core = new AppCore(this, this);
  m_Viewer = new AppViewer (this);

}

