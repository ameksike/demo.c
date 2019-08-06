#ifndef QIRIEVENT_H
#define QIRIEVENT_H
#include <QEvent>
#include "servicio.h"

class QIRIEvent: public QEvent
{
  private:
    QString             fileName;
    QByteArray          fileContent;
    quint64             numTansferencia;
    QList<quint16>    servicios;
  public:

    enum { IRI_EVENT = QEvent::Type( QEvent::User + 120 ) };

    QIRIEvent(QByteArray _fileContent, QString _filename = ""):QEvent( QEvent::Type( QEvent::User + 120 ) ),
      fileName( _filename ), fileContent( _fileContent )
    {
    }

    QIRIEvent(QIRIEvent &other):QEvent( other.type() )
    {
        this->fileName             = other.fileName;
        this->fileContent          = other.fileContent;
        this->numTansferencia      = other.numTansferencia;
        this->servicios            = other.servicios;
    }

    ~QIRIEvent()
    {
        cout<<"QIRIEvent::~QIRIEvent()"<<endl;
    }

    QString getFileName()
    {
       return this->fileName;
    }

    void setFileName(QString fn )
    {
        this->fileName = fn;
    }

    QByteArray getFileContent()
    {
       return this->fileContent;
    }

    void setNumTransferencia(quint64 nt)
    {
       this->numTansferencia = nt;
    }

    quint64 getNumTransferencia()
    {
        return this->numTansferencia;
    }

    void addServicio( quint16 idServicio )
    {
        this->servicios.append( idServicio );
    }

    void addServicio( QList<quint16> ls )
    {
        this->servicios.append( ls );
    }

    QList<quint16> getServicios()
    {
        return this->servicios;
    }

};
#endif // QIRIEVENT_H
