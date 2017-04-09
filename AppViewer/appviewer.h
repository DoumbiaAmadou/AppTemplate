#ifndef APPVIEWER_H
#define APPVIEWER_H

#include <QObject>
#include <QQuickView>
#include <QSize>

#include <QQmlApplicationEngine>

class AppViewer : public QQmlApplicationEngine
{
  Q_OBJECT

public:

  /*!
   * \brief Construct  AppViewer
   * \param parent
   */
  explicit AppViewer(QObject *parent = 0);


  /*!
   * Vars
  */

  QQmlApplicationEngine * m_ViewEngine;
  QSize * m_demension ;

signals:



public slots:

  QSize *demension() const;
  void setDemension(QSize *demension);

  bool addContext(QString  a, QObject *b ) ;



};

#endif // APPVIEWER_H
