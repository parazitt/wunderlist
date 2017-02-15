TEMPLATE = app

QT += qml quick network
CONFIG += c++11

SOURCES += main.cpp \
    wunderlist.cpp \
    __request.cpp \
    request.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    wunderlist.h \
    __request.h \
    request.h
