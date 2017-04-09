#ifndef GRPAHICALCOMPONENTDATA_H
#define GRPAHICALCOMPONENTDATA_H
#include <QObject>
#include <QSettings>
#include <QSqlDatabase>


class GrpahicalComponentData: public QObject
{
public:

  GrpahicalComponentData(QSettings *setting , QObject* parent =0);


  QSettings * m_setting;

};

#endif // GRPAHICALCOMPONENTDATA_H
