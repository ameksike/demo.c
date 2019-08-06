//---------------------------------------------------------------------------
/**
 * @package    SIR
 * @subpackage util
 * @author     ing. Antonio Membrides Espinosa
 * @date       21/02/2021
 * @version    1.0
 */
//---------------------------------------------------------------------------
#ifndef IRIRECORD_H
#define IRIRECORD_H
#include "src/include/iri/IRI.h"
#include <string>
#include <QString>
#include <QDateTime>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "src/Entity/Fija/CallRelatedEvent.h"
#include "src/Entity/Fija/SuplementaryServiceEvent.h"
#include "src/Entity/Fija/ChannelControlEvent.h"
#include <QQueue>
#include "src/qx2event.h"

class IRIUtil
{
  public:
    static string create(QQueue<QX2Event*>);

    static IRIsChoice* getRecord( int recordType,
                                  QString &neid,
                                  QString &liid,
                                  QString &time,
                                  QString &cin,
                                  QString &operatorId,
                                  QString &callDirect,
                                  QString &calling,
                                  QString &called,
                                  QString &callState                 ,
                                  QString &natureOfTheInterceptedCall,
                                  QString &originalCalled            ,
                                  QString &redirectingNumber         ,
                                  QString &redirectionNumber         ,
                                  QString &genericNumber             ,
                                  QString &connectedNumber           ,
                                  QByteArray &redirectionInfo        ,
                                  QByteArray &diversionInfo
                               );

    static string encode(IRIs&);
};

#endif // IRIRECORD_H
