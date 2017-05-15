#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "app.h"

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);


int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
   new App("amadou" ,"doumbia" , &app  ) ;
  return app.exec();
}
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context);

    QString date = QDateTime::currentDateTime().toString("ddMMyy-hhmmss.zzz");
    QString qmlfilename(context.file );
    QRegExp qmlrx("[^\\\\\\\/]+\\.qml",Qt::CaseInsensitive);
    qmlrx.indexIn(qmlfilename);
    qmlfilename = (!qmlrx.capturedTexts().empty())?qmlrx.capturedTexts().last():"";
    QString function(context.function);
    function = ((qmlfilename!="")?qmlfilename + ((function!="")?":":""):"") + function.replace(QRegExp("\\s?(?:\\*|&)*__\\S+\\s")," ").replace(QRegExp("\\s?(?:enum|class)\\s"),"").trimmed();
    QString txt = QString("%1|%2").arg(date,function.leftJustified(85, ' ', true));

    QString parsedMsg(msg);
    if(qmlfilename != "") {
        QRegExp startrx("qrc:.*\\.qml:",Qt::CaseInsensitive);
        startrx.indexIn(parsedMsg);
        if((!startrx.capturedTexts().empty()) && (startrx.pos(0) == 0))
            parsedMsg.remove(startrx.pos(0),startrx.cap(0).size());
    }

    switch (type)
    {
        case QtDebugMsg:
            txt += QString("|Dbg|%1").arg(parsedMsg);
            break;
        case QtWarningMsg:
            txt += QString("|Wrg|%1").arg(parsedMsg);
            break;
        case QtCriticalMsg:
            txt += QString("|Cri|%1").arg(parsedMsg);
            break;
        case QtFatalMsg:
            txt += QString("|Ftl|%1").arg(parsedMsg);
            abort();
            break;
    }

    QFile outFile(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/" + logfile);

    if(outFile.size() > LOGSIZE) {
        QDir localdatapath(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
        QStringList logfilesfilter("*.log");
        QStringList logfileslist = localdatapath.entryList(logfilesfilter,QDir::Files,QDir::Time);

        logfile = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss.zzz") + ".log";
        outFile.setFileName(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/" + logfile);

        while(logfileslist.count() >= LOGFILENUM)
            QFile::remove(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/" + logfileslist.takeLast());
    }

    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream textStream(&outFile);
    if(type!=QtWarningMsg)
        textStream<<txt<< endl;

//    echo();
    QTextStream(stderr) << txt << endl;
}
