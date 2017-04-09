#ifndef APPCORE_H
#define APPCORE_H

#include <QSqlDatabase>
#include <QObject>
#include <QSettings>
#include <QDir>
#include <QFile>

#include "app.h"
#include "AppData/grpahicalcomponentdata.h"

class App ;

class GrpahicalComponentData ;
class AppCore : public QObject
{
  Q_OBJECT
public:
  explicit AppCore(App *app  ,  QObject *parent = 0);

  void initializer() ;
  QString read(QString Filename);
signals:

public slots:

  void createFolderInotExist(QString s) ;
  QString escape(QString s) ;

private :
  void initDb() ;
  void loadDatabase() ;
  QSqlDatabase  m_Sql ;
  QFile m_dbfile ;


  App * m_App  ;
  QDir m_appdbfolder  ;

  static GrpahicalComponentData *  m_GraphicalComponent ;

  static QSettings *                                                                               m_setting ;


};

#endif // APPCORE_H
