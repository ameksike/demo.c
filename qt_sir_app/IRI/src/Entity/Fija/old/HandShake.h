#ifndef HANDSHAKE_H
#define HANDSHAKE_H

#include <QByteArray>
#include "fija_definitions.h"


class HandShake
{
  public:
    HandShake(QByteArray * byteArray)
    {
        this->rawData = new QByteArray( byteArray->left( byteArray->size() ) );
        this->LEAID    = new QByteArray( byteArray->left(2) );
        this->dwLength = new QByteArray( byteArray->left(4) );
        byteArray->remove(0, 6);
        this->ecoData  = new QByteArray( byteArray->left( byteArray->size() ) );
        byteArray->clear();
    }

    QString getLEAId()
    {
        return QString( *this->LEAID );
    }

    quint16 getDWLength()
    {
        return Utiles::QByteArrayToInteger(this->dwLength, QSysInfo::LittleEndian);
    }

    QByteArray getEcoData()
    {
        return *this->ecoData;
    }

    QByteArray* getRawData()
    {
        return this->rawData;
    }

    private:
        QByteArray *LEAID;
        QByteArray *dwLength;
        QByteArray *ecoData;
        QByteArray *rawData;
};

#endif // HANDSHAKE_H
