# -------------------------------------------------
# Project created by QtCreator 2012-02-20T11:56:40
# -------------------------------------------------
QT += sql \
    network
QT -= gui
DESTDIR = release
MOC_DIR = release/moc
OBJECTS_DIR = release/obj
TARGET = IRI
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    src/tcpserver.cpp \
    src/ngn_fija_controller.cpp \
    src/controllerfactory.cpp \
    src/SERVICE/DataAcces/Query.cpp \
    src/SERVICE/DataAcces/nom_xptu.cpp \
    src/SERVICE/DataAcces/nom_mc.cpp \
    src/SERVICE/DataAcces/Connection.cpp \
    src/Entity/irirecord.cpp \
    src/qx2event.cpp \
    src/servicio.cpp \
    src/controllertcp.cpp \
    src/controllerNgn.cpp \
    src/clienteservicioftp.cpp \
    src/lig.cpp \
    src/include/iri/PartyInformation.cpp \
    src/include/iri/IRIaux.C \
    src/include/iri/IRI.cpp \
    src/Controler.cpp \
    src/include/iri/ParametersFormat.C \
    src/deliveryfunction.cpp \
    src/ftpmanager.cpp
HEADERS += src/tcpserver.h \
    src/ngn_fija_controller.h \
    src/controllerfactory.h \
    src/Entity/Fija/SuplementaryServiceEvent.h \
    src/Entity/Fija/HandShake.h \
    src/Entity/Fija/fija_definitions.h \
    src/Entity/Fija/ChannelControlEvent.h \
    src/Entity/Fija/CallRelatedEvent.h \
    src/SERVICE/DataAcces/Query.h \
    src/SERVICE/DataAcces/nom_xptu.h \
    src/SERVICE/DataAcces/nom_mc.h \
    src/SERVICE/DataAcces/Connection.h \
    src/Entity/Utils.h \
    src/Entity/structs.h \
    src/qx2event.h \
    src/qirievent.h \
    src/servicio.h \
    src/controllertcp.h \
    src/controllerNgn.cpp.h \
    src/clienteservicioftp.h \
    src/lig.h \
    src/include/iri/PartyInformation.h \
    src/include/iri/ParametersFormat.h \
    src/include/iri/IRIaux.h \
    src/include/iri/IRI.h \
    src/Controler.h \
    src/deliveryfunction.h \
    src/ftpmanager.h
INCLUDEPATH = /usr/include/snacc/c++ \
    src/include/iri
LIBS += -lasn1c++
