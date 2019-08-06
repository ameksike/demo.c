#ifndef FIJA_DEFINITIONS_H
#define FIJA_DEFINITIONS_H

#include <QByteArray>
#include <QDataStream>
#include "Utils.h"
#include "qx2event.h"

#include <iostream>

using namespace std;

namespace nsFija
{

    enum { PreambuloX2 =   0xAA };

    typedef enum
    {
        nCmdCode_HandShake                = 0xF0,
        nCmdCode_CallRelatedEvent         = 0x20,
        nCmdCode_ChannelEvent             = 0x30,
        nCmdCode_SuplementaryServiceEvent = 0x50,
        nCmdCode_Desconocido              = 0x60
    } X2CmdCodes;

    /**
      encabezamiento, estos bytes siempre estan presentes
      indican inicio de trama y evento generado
     **/
    class X2PreHeader
    {
        public:
            X2PreHeader()//:nCmdCode(0x00), nPreAmbulo(0x00)
            {
            }

            X2PreHeader(QByteArray * /*byteArray*/)
            {
                //this->nPreAmbulo = (quint8)byteArray->at(0);
                //this->nCmdCode   = (quint8)byteArray->at(1);
                //byteArray->remove(0, 2);
            }

            static quint8 getPreAmbulo(QByteArray &byteArray)
            {
                quint8 nPreAmbulo = (quint8)byteArray.at(0);
                byteArray.remove(0,1);
                return nPreAmbulo;
            }

            static quint8 getCmdCode(QByteArray &byteArray)
            {
                quint8 nCmdCode   = (quint8)byteArray.at(0);
                byteArray.remove(0,1);
                return nCmdCode;
            }

        /*protected:
            quint8 nCmdCode;
            quint8 nPreAmbulo;*/
    };

};


#endif // FIJA_DEFINITIONS_H
