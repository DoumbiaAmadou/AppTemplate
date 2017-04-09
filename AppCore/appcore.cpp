#include "appcore.h"
#include <QSqlQuery>
#include <QStandardPaths>
#include <QString>



QSettings * AppCore::m_setting = NULL ;
GrpahicalComponentData * AppCore::m_GraphicalComponent= NULL ;


AppCore::AppCore(App *app, QObject *parent) : QObject(parent) ,m_App(app)
{
  m_Sql = QSqlDatabase::addDatabase("QSQLITE");
  initializer();
  m_GraphicalComponent = new GrpahicalComponentData(m_setting);




}

void AppCore::initializer()
{
  m_setting=  new QSettings(m_App->getOrganisationName(),
                            m_App->getApplicationName())  ;
  if(!m_setting->contains("APPFOLDER") ) {

      qDebug()<<"dezdez"<<QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"//"
                +m_App->getApplicationName()
                +"/database";
      m_setting->setValue("APPFOLDER" ,QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"
                          +m_App->getApplicationName());
      m_setting->setValue("DATABASEFOLDER" ,QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                          +"/"
                          +m_App->getApplicationName()
                          +"/database");

      m_setting->setValue("DBFILE" ,QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                          +"/"
                          +m_App->getApplicationName()
                          +"/database/db.db");

      createFolderInotExist(m_setting->value("DATABASEFOLDER").toString()) ;
      m_appdbfolder = QDir(m_setting->value("DATABASEFOLDER").toString()) ;


    }else
    {
      qDebug()<<"setting dbile" << m_setting->value("DATABASEFOLDER");
      m_Sql.setDatabaseName(m_setting->value("DATABASEFOLDER").toString());

    }

    m_dbfile.setFileName(m_setting->value("DBFILE").toString());
    m_Sql.setDatabaseName(m_setting->value("DBFILE").toString());

    if(!m_dbfile.exists())
      initDb();
    else
      loadDatabase();


}

void AppCore::initDb() {
  qDebug()<<"initDb"<<m_setting->value("DBFILE").toString();
//  qDebug()<<"initDb"<<m_setting->fileName();

//  qDebug()<<m_setting->;

  QFile  emptydb(":/resources/bin/emptyDb.sql") ;

  emptydb.copy(m_setting->value("DBFILE").toString());
  m_dbfile.setPermissions(QFile::ExeGroup | QFile::ExeOther | QFile::ExeOther |
                          QFile::ExeUser |QFile::WriteOwner|QFile::WriteGroup
                          |QFile::WriteOther);
  loadDatabase();
}

void AppCore::loadDatabase() {
  qDebug()<<"load";

  if(m_Sql.open())
    {
      QSqlQuery query;
       qDebug()<< "return :/databaaseInitfile.sql" ;
       qDebug()<<query.exec(read(":/databaaseInitfile.sql").simplified());
    }else
    qDebug()<<"coun't open data base";

}

void AppCore::createFolderInotExist(QString s){
  QDir directory(s);
  qDebug()<<"create folder "<<s<<directory.path();
  if(!directory.exists()){
      qDebug()<<QDir(QDir::root()).mkpath(s) ;
    }
}

QString AppCore::escape(QString s)
{
  return s.replace(QRegExp("[\\n\\t\\r]") , "" );
}

QString AppCore::read(QString Filename){
  QFile mFile(Filename);
 qDebug() << "read path "<<Filename;
  if(!mFile.open(QFile::ReadOnly | QFile::Text)){
      qDebug() << "could not open file for read";
      return "";
    }

  QTextStream in(&mFile);
  QString mText = in.readAll();

  qDebug() << mText.simplified();

  mFile.close();
  return mText.simplified() ;

}
