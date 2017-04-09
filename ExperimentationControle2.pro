QT += qml quick sql core

CONFIG += c++11

SOURCES += main.cpp \
    app.cpp \
    AppCore/appcore.cpp \
    appViewer/appviewer.cpp \
    AppData/grpahicalcomponentdata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    app.h \
    AppCore/appcore.h \
    appViewer/appviewer.h \
    AppData/grpahicalcomponentdata.h
