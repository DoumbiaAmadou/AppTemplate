#ifndef APP_H
#define APP_H

#include <QObject>
#include "AppCore/appcore.h"
#include "appViewer/appviewer.h"

class AppCore ;
class AppViewer ;

class App : public QObject
{
  Q_OBJECT
public:
  explicit App(QString Organisation,QString ApplicationName,QObject *parent = 0);

  Q_INVOKABLE QString getApplicationName() const;

  Q_INVOKABLE QString getOrganisationName() const;

  void setOrganisationName(const QString &OrganisationName);

signals:

public slots:
  void Initializer() ;


private:

  QString m_ApplicationName ;
 QString m_OrganisationName ;
 AppViewer * m_Viewer ;
 AppCore * m_Core ;




};

#endif // APP_H
