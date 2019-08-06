#-------------------------------------------------
#
# Project created by QtCreator 2012-04-26T10:01:11
#
#-------------------------------------------------

QT       += core, xml

QT       -= gui

TARGET = hilos
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/control/IfaceCMD.cpp \
    src/control/ControlCMD.cpp \
    src/control/MainCLIApp.cpp \
    src/lib/xml/QXmlMetaReader.cpp \
    src/control/SIRControl.cpp \
    src/lib/resource/Message.cpp \
    src/lib/resource/Log.cpp \
    src/control/IfaceCMDIO.cpp \
    src/control/IfaceCMDNET.cpp

HEADERS += \
    src/control/IfaceCMD.h \
    src/control/ControlCMD.h \
    src/control/MainCLIApp.h \
    src/lib/iface/IfaceReceptor.h \
    src/lib/xml/QXmlMetaReader.h \
    src/control/SIRControl.h \
    src/lib/resource/Message.h \
    src/lib/resource/Log.h \
    src/control/IfaceCMDIO.h \
    src/control/IfaceCMDNET.h
