//---------------------------------------------------------------------------
/**
 * @package    SIR
 * @subpackage util
 * @author     ing. Antonio Membrides Espinosa
 * @date       21/02/2021
 * @version    1.0
 */
//---------------------------------------------------------------------------
#include "irirecord.h"
#include  <fstream>

string IRIUtil::create(QQueue<QX2Event*> colaX2E)
{
   //IRISequence *iriSequence   = new IRISequence;
   IRIsChoice *iriRecord      = NULL;
   IRIs  *iris                = NULL;
   QEvent::Type X2EventType   = QEvent::None;
   QX2Event *e                = NULL;
   string iriContent("");
   while( !colaX2E.empty() )
   {
       cout<<"Creando IRIRecord"<<endl;
       iriRecord = NULL;
       e = colaX2E.dequeue();
       X2EventType = e->type();

       cout<<"Creando IRIRecord event type: "<<X2EventType<<endl;

       if( X2EventType == QEvent::Type( QX2Event::CALL_RELATED_EVENT ) )
       {
           CallRelatedEvent *x2e  = (CallRelatedEvent *)e;

           QString NEId              = x2e->getNEID();
           QString liId              = x2e->getLIID();
           QString time              = x2e->getTime( "yyMMddhhmmssZ" );
           QString cin               = x2e->getCallIdentityNumber();
           QString operatorId        = x2e->getOperatorID();
           QString callOrCalledFlag  = x2e->getCallOrCalledFlag();
           QString callingNumber     = x2e->getCallingNumber();
           QString calledNumber      = x2e->getCalledNumber();
           QString callState         = x2e->getCallState();
           QString natureOfCall      = x2e->getNatureCall();
           QString origCalledNumber  = x2e->getOriginalCalledNumber();
           QString redirectingNumber = x2e->getRedirectingNumber();
           QString redirectionNumber = x2e->getRedirectionNumber();
           QString genericNumber     = x2e->getGenericNumber();
           QString connectedNumber   = x2e->getConnectedNumber();
           QByteArray redirectionInfo;
           QByteArray diversionInfo;

           cout<<"Creando CALL_RELATED_EVENT"<<endl;           
           iriRecord = IRIUtil::getRecord(  x2e->getRecordType().toInt(),
                                            NEId, liId, time, cin, operatorId,
                                            callOrCalledFlag, callingNumber,
                                            calledNumber, callState, natureOfCall,
                                            origCalledNumber, redirectingNumber,
                                            redirectionNumber, genericNumber,
                                            connectedNumber, redirectionInfo,
                                            diversionInfo
                                         );
           //delete x2e;
           cout<<"Creado CALL_RELATED_EVENT"<<endl;
       }

       if( X2EventType == QEvent::Type( QX2Event::CHANNEL_CONTROL_EVENT ) )
       {
           ChannelControlEvent *x2e  =(ChannelControlEvent *)e;
           if( x2e->getEventType() == "2" )
           {
               /*iriRecord = IRIUtil::getRecord( IRIsChoice::iRI_Continue_recordCid,
                                                 x2e->getNEID(),
                                                 x2e->getLIID(),
                                                 x2e->getTime( "yyMMddhhmmssZ" ),
                                                 x2e->getCallIdentityNumber(),
                                                 x2e->getOperatorID(),
                                                 x2e->getCallOrCalledFlag(),
                                                 x2e->getCallingNumber(),
                                                 x2e->getCalledNumber(),
                                               );*/
            }
       }

       if( X2EventType == QEvent::Type( QX2Event::SUPLEMENTARY_SERVICE_EVENT ) )
       {
            SuplementaryServiceEvent *x2e = (SuplementaryServiceEvent *)e;

            QString NEId              = x2e->getNEID();
            QString liId              = x2e->getLIID();
            QString time              = x2e->getTime( "yyMMddhhmmssZ" );
            QString cin               = x2e->getCallIdentityNumber();
            QString operatorId        = x2e->getOperatorID();
            QString callOrCalledFlag  = x2e->getCallOrCalledFlag();
            QString callingNumber     = x2e->getCallingNumber();
            QString calledNumber      = x2e->getCalledNumber();
            QString callState;
            QString natureOfCall;
            QString origCalledNumber;
            QString redirectingNumber;
            QString redirectionNumber;
            QString genericNumber     = x2e->getGenericNumber();
            QString connectedNumber;
            QByteArray redirectionInfo;
            QByteArray diversionInfo;

            iriRecord = IRIUtil::getRecord(  x2e->getRecordType().toInt(),
                                             NEId, liId, time, cin, operatorId,
                                             callOrCalledFlag, callingNumber,
                                             calledNumber, callState, natureOfCall,
                                             origCalledNumber, redirectingNumber,
                                             redirectionNumber, genericNumber,
                                             connectedNumber, redirectionInfo,
                                             diversionInfo
                                          );
       }

       if( iriRecord )
       {
            cout<<"creando record"<<endl;
            iris = new IRIs( *iriRecord );
            iriContent += IRIUtil::encode( *iris );
            //iriSequence->AppendCopy( *iriRecord );
            delete iris;
            cout<<"creado record"<<endl;
       }  
  } 

   /*if ( iriSequence->Count() == 0 )
       //return "";
   stringstream outputFile;

   AsnBuf outputBuf;
   size_t encodedLen;

   const size_t dataSize = 5020;
   char data[dataSize];

   // set up buffer for writing to
   outputBuf.Init (data, dataSize);
   outputBuf.ResetInWriteRvsMode();

   // encode the internal value we just build into the buffer
   if (!iriSequence->BEncPdu (outputBuf, encodedLen))
       cout << "failed encoding AnyTestType value" << endl;

    //copy the BER value from the buffer to the file
   outputBuf.ResetInReadMode();
   for (; encodedLen > 0; encodedLen--)
   {
       outputFile.put (outputBuf.GetByte());
   }

   outputFile.put(0x00);
   outputFile.put(0x00);
   */
   return iriContent;//outputFile.rdbuf()->str();
}
//

IRIsChoice* IRIUtil::getRecord(    int        recordType,
                                   QString    &neid,
                                   QString    &liid,
                                   QString    &time,
                                   QString    &cin,
                                   QString    &operatorId,
                                   QString    &callDirect,
                                   QString    &calling,
                                   QString    &called,
                                   QString    &callState                 ,
                                   QString    &natureOfTheInterceptedCall,
                                   QString    &originalCalled            ,
                                   QString    &redirectingNumber         ,
                                   QString    &redirectionNumber         ,
                                   QString    &genericNumber             ,
                                   QString    &connectedNumber           ,
                                   QByteArray &redirectionInfo        ,
                                   QByteArray &diversionInfo
                             )
{
    IRIsChoice *iri = NULL;
    if(  recordType == IRIsChoice::iRI_Begin_recordCid )
    {
        iri  = new IRIsChoice( IRIsChoice::iRI_Begin_recordCid );
        cout<<"[CREANDO IRI-BEGIN]"<<endl;
    }

    if( recordType == IRIsChoice::iRI_End_recordCid )
    {
        iri  = new IRIsChoice( IRIsChoice::iRI_End_recordCid );
        cout<<"[CREANDO IRI-END]"<<endl;
    }

    if( recordType == IRIsChoice::iRI_Continue_recordCid )
    {
        iri  = new IRIsChoice( IRIsChoice::iRI_Continue_recordCid );
        cout<<"[CREANDO IRI-CONTINUE]"<<endl;
    }

    if( recordType == IRIsChoice::iRI_Report_recordCid )
    {
        iri  = new IRIsChoice( IRIsChoice::iRI_Report_recordCid );
        cout<<"[CREANDO IRI-REPORT]"<<endl;
    }

    /**   LAWFUL INTERCEPTION IDENTIFIER    **/
    if( liid.length() )
        iri->CreateLawfulInterceptionIdentifier( (char *)liid.toStdString().data() , liid.length() );

    /**    COMMNICATION IDENTITY NUMBER       **/
    //  CIN
    if( cin.length() )
    {
        iri->CreateCommunicationIdentifierIdentityNumber( (char *)cin.toStdString().c_str()  );
    }

    /**   OPERATOR ID  **/
    if( operatorId.length() )
        iri->CreateCommunicationIdentifierNetworkIdentifierOperatorIdentifier( (char *)operatorId.toStdString().c_str() );

    /**     NETWORK ELEMENT ID      **/
    if( neid.length() )
        iri->CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::dNS_FormatCid, (char *)neid.toStdString().c_str() );

    /**    TIMESTAMP                  **/
    if( time.length() )
        iri->CreateTimeStampUtcTime( (char *)time.toStdString().c_str() );

    /**     INTERCEPTED-CALL-DIRECT  **/
    if( callDirect.length() )
    {
        if( callDirect == "0" )
          iri->CreateInterceptedCallDirect( IRI_ParametersEnum1::originating_Target );
        if( callDirect == "1" )
          iri->CreateInterceptedCallDirect( IRI_ParametersEnum1::terminating_Target );
    }

    /**     INTERCEPTED-CALL-STATE   **/
    if( callState.length() )
    {
        if( callState == "2" )
          iri->CreateInterceptedCallState( Intercepted_Call_State::setUpInProcess );

        if( callState == "3" )
          iri->CreateInterceptedCallState( Intercepted_Call_State::connected );

        if( callState == "1" )
          iri->CreateInterceptedCallState( Intercepted_Call_State::idle );
    }

    /**   CALLING PARTY  **/
    if( calling.length() )
    {
        //calling->remove(0, 2);
        PartyInformation * callingParty = iri->AddPartyInformation();
        callingParty->SetPartyQualifier(PartyInformationEnum::originating_Party);
        QByteArray callingPartyBA = Utiles::QStringtoBCD( calling );

        /**  formato isup **/
        //primer byte del calling party
        quint8 parImpar               = (quint8)(calling.length() % 2) << 7 ;
        quint8 indNaturalezaDireccion = 0x04; /**  ver esto  **/
        callingPartyBA.insert(0, (parImpar | indNaturalezaDireccion) );

        //segundo byte del calling party
        quint8 indNumeroIncompleto        = 0x00;//INN
        quint8 indPlanNumeracion          = 0x10;//RDSI UIT-T E.164
        quint8 indPresentacionRestringida = 0x00;//presentacion permitida
        quint8 indCribado                 = 0x03;//suministrado por la red
        callingPartyBA.insert(1, (indNumeroIncompleto | indPlanNumeracion | indPresentacionRestringida | indCribado) );

        callingParty->CreatePartyIdentityCallingPartyNumber(CallingPartyNumber::iSUP_FormatCid, (char*)callingPartyBA.constData() , callingPartyBA.length() );

        /**
          SI ES UN IRIBEGIN Y HAY UN NUMERO REDIRGIENDO LA LLAMADA A UN OBJETIVO
          SE LE INCORPORA LA INFORMACION DE LA REDIRECCION
          **/
        if( recordType == IRIsChoice::iRI_Begin_recordCid )
        {
           /*Supplementary_Services *ss = callingParty->CreateSupplementaryServicesInformation();
           if( connectedNumber )
                ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           if( redirectingNumber )
                ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           if( originalCalled )
                ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           if( redirectionInfo )
                ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           if( redirectionNumber )
                ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           if( diversionInfo )
               ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           if( genericNumber )
               ss->standard_Supplementary_Services->iSUP_SS_parameters->Append()
           */
        }
    }


    /**   CALLED PARTY  **/
    if( called.length() )
    {
        //called->remove(0, 2);
        PartyInformation * calledParty = iri->AddPartyInformation();
        calledParty->SetPartyQualifier(PartyInformationEnum::terminating_Party);
        QByteArray calledPartyBA = Utiles::QStringtoBCD( called );


        /**  formato isup **/
        //primer byte del called party
        quint8 parImpar = (quint8)(called.length() % 2) << 7 ;
        quint8 indNaturalezaDireccion = 0x04;//**** /
        calledPartyBA.insert(0, (parImpar | indNaturalezaDireccion) );

        //segundo byte del called party
        quint8 indNumeroRedInterno = 0x00;//INN
        quint8 indPlanNumeracion   = 0x10;//RDSI UIT-T E.164
        calledPartyBA.insert(1, (indNumeroRedInterno | indPlanNumeracion) );

        calledParty->CreatePartyIdentityCalledPartyNumber(CalledPartyNumber::iSUP_FormatCid, (char*)calledPartyBA.constData() , calledPartyBA.length() );
    }

    /**   NATURE OF THE INTERCEPTED CALL   **/
    if( natureOfTheInterceptedCall.length() )
    {
        if( natureOfTheInterceptedCall == "0" )
            iri->CreateNatureOfTheInterceptedCall( IRI_ParametersEnum2::gSM_ISDN_PSTN_circuit_call );
    }

    return iri;
}

string IRIUtil::encode(IRIs &iri)
{
    stringstream outputFile;

    AsnBuf outputBuf;
    size_t encodedLen;

    const size_t dataSize = 5020;
    char data[dataSize];

    // set up buffer for writing to
    outputBuf.Init (data, dataSize);
    outputBuf.ResetInWriteRvsMode();

    // encode the internal value we just build into the buffer
    if (&iri && !iri.BEncPdu (outputBuf, encodedLen))
        cout << "failed encoding AnyTestType value" << endl;

    // copy the BER value from the buffer to the file
    outputBuf.ResetInReadMode();
    for (; encodedLen > 0; encodedLen--)
    {
        outputFile.put (outputBuf.GetByte());
    }

    outputFile.put(0x00);
    outputFile.put(0x00);

    return outputFile.rdbuf()->str();
}
