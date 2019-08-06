#include "IRI.h"



IRIs::IRIs()
{
#if TCL
  iRIContent = new IRIsChoice;
#else
  iRIContent = NULL; // incomplete initialization of mandatory element!
#endif // TCL
}

//---------------------------------------------------------------------------------------------------------
IRIs::IRIs(IRIsChoice::ChoiceIdEnum choiceId)
{
    iRIContent =  new IRIsChoice(choiceId);// crea un iri en dependencia del tipo o sea un iri begin o end o content
    current_IRI_parameter = iRIContent->current_IRI_parameter;
}
//---------------------------------------------------------------------------------------------------------

IRIs::IRIs (const IRIs &)
{
  Asn1Error << "use of incompletely defined IRIs::IRIs (const IRIs &)" << std::endl;
  abort();
}

IRIs::~IRIs()
{
  delete iRIContent;
}

AsnType *IRIs::Clone() const
{
  return new IRIs;
}

#if SNACC_DEEP_COPY
IRIs &IRIs::operator = (const IRIs &that)
#else // SNACC_DEEP_COPY
IRIs &IRIs::operator = (const IRIs &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    if (that.iRIContent)
    {
      if (!iRIContent)
        iRIContent = new IRIsChoice;
      *iRIContent = *that.iRIContent;
    }
    else
    {
      delete iRIContent;
      iRIContent = NULL;
    }
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined IRIs &IRIs::operator = (const IRIs &)" << std::endl;
  abort();
  // if your compiler complains here, check the -novolat option
#endif // SNACC_DEEP_COPY
}

IRIs::IRIs(IRIsChoice &iRIsChoice)
{
   this->current_IRI_parameter = iRIsChoice.current_IRI_parameter;
   this->iRIContent = &iRIsChoice;
}

AsnLen IRIs::BEncContent (BUF_TYPE b)
{
  AsnLen totalLen = 0;
  AsnLen l;

    l = iRIContent->BEncContent (b);
    totalLen += l;

  return totalLen;
} // IRIs::BEncContent


void IRIs::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  tag1 = BDecTag (b, seqBytesDecoded, env);

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 1))
    || (tag1 == MAKE_TAG_ID (CNTX, CONS, 2))
    || (tag1 == MAKE_TAG_ID (CNTX, CONS, 3))
    || (tag1 == MAKE_TAG_ID (CNTX, CONS, 4)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    iRIContent = new IRIsChoice;
    iRIContent->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << std::endl;
    longjmp (env, -110);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded, env);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    Asn1Error << "ERROR - Length discrepancy on sequence." << std::endl;
    longjmp (env, -111);
  }
  else
    return;
} // IRIs::BDecContent

AsnLen IRIs::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  //l += BEncConsLen (b, l);
  l+=BEncIndefLen(b);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void IRIs::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    Asn1Error << "IRIs::BDec: ERROR - wrong tag" << std::endl;
    longjmp (env, -112);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int IRIs::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
//    BufPutByteRvsb(b,0x0);BufPutByteRvsb(b,0x0);
    return !b.WriteError();
}

int IRIs::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

void IRIs::Print (std::ostream &os) const
{
  os << "{ -- SEQUENCE --" << std::endl;
  indentG += stdIndentG;

  if (NOT_NULL (iRIContent))
  {
    Indent (os, indentG);
    os << "iRIContent ";
    os << *iRIContent;
  }
  else
  {
    Indent (os, indentG);
    os << "iRIContent ";
    os << "-- void --";
    os << std::endl;
  }

  os << std::endl;
  indentG -= stdIndentG;
  Indent (os, indentG);
  os << "}";
} // IRIs::Print

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Metodos para cambiar los datos de un IRI

void IRIs::CreateLawfulInterceptionIdentifier(char *lawfulInterceptionIdentifier, int len)
{
    current_IRI_parameter->lawfulInterceptionIdentifier.Set(lawfulInterceptionIdentifier,len);
}

//************Struct communicationIdentifier***************************
void IRIs::CreateCommunicationIdentifierIdentityNumber(const char *communicationIdentityNumber)
{
    current_IRI_parameter->communicationIdentifier->communication_Identity_Number = new AsnOcts(communicationIdentityNumber);
}
void IRIs::CreateCommunicationIdentifierNetworkIdentifierOperatorIdentifier(const char *networkOperatorIdentifier)
{
    current_IRI_parameter->communicationIdentifier->network_Identifier->operator_Identifier= networkOperatorIdentifier;//NO S
}
//enum ChoiceIdEnum{ e164_FormatCid, x25_FormatCid, iP_FormatCid, dNS_FormatCid, iP_AddressCid};
void IRIs::CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, const char *str)
{
    current_IRI_parameter->communicationIdentifier->network_Identifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement, str);
}
void IRIs::CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str )
{
    current_IRI_parameter->communicationIdentifier->network_Identifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement, ip_type, choiceIpTypeValue, str);
}
void IRIs::CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str, IPAddressEnum1 choiceIpAssignment )
{
    current_IRI_parameter->communicationIdentifier->network_Identifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement, ip_type, choiceIpTypeValue, str, choiceIpAssignment);
}


//***************Struct TimeStamp**********************
void IRIs::CreateTimeStampUtcTime(const char *utcTimeStr)
{
    current_IRI_parameter->timeStamp = new TimeStamp(utcTimeStr);
}
void IRIs::CreateTimeStampLocalTime(const char *generalizedTimeStr, LocalTimeStampEnum  winterSummerIndication)
{
    current_IRI_parameter->timeStamp = new TimeStamp(generalizedTimeStr, winterSummerIndication);
}


//************InterceptedCallDirect*****************
//IRI_ParametersEnum1 enum{not_Available, originating_Target, terminating_Target};
void IRIs::CreateInterceptedCallDirect( IRI_ParametersEnum1 intercepted_Call_Direct)
{
    current_IRI_parameter->intercepted_Call_Direct = new IRI_ParametersEnum1(intercepted_Call_Direct);
}

//************Intercepted_Call_State***************
void IRIs::CreateInterceptedCallState(Intercepted_Call_State intercepted_Call_State)
{
    current_IRI_parameter->intercepted_Call_State = new Intercepted_Call_State(intercepted_Call_State);
}

//************RingingDuration***************
void IRIs::CreateRingingDuration(const char *ringingDuration)
{
    current_IRI_parameter->ringingDuration = new AsnOcts;
    current_IRI_parameter->ringingDuration->Set(ringingDuration);
}

//ConversationDuration
void IRIs::CreateConversationDuration(const char*conversationDuration)
{
    current_IRI_parameter->conversationDuration = new AsnOcts;
    current_IRI_parameter->conversationDuration->Set(conversationDuration);
}

//***************Struct Location*************
void IRIs::CreateLocationE164_Number(const char *e164_Number)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->e164_Number = new AsnOcts;
    current_IRI_parameter->locationOfTheTarget->e164_Number->Set(e164_Number);
}
void IRIs::CreateLocationGlobalCellID(const char *globalCellID)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->globalCellID = new AsnOcts;
    current_IRI_parameter->locationOfTheTarget->globalCellID->Set(globalCellID);
}

//function of Struct TetraLocation of Location
void IRIs::CreateLocationTetraLocation(int pls_loc)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->tetraLocation = new TetraLocation(pls_loc);
}

void IRIs::CreateLocationTetraLocation(unsigned int mcc, unsigned int mnc, unsigned int lai)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->tetraLocation = new TetraLocation(mcc,mnc,lai);
}
void IRIs::CreateLocationTetraLocation(unsigned int mcc, unsigned int mnc, unsigned int lai, int ci)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->tetraLocation = new TetraLocation(mcc,mnc,lai, ci);
}

//function for  set RAI of Location
void IRIs::CreateLocationRAI(const char *rAI)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->rAI = new AsnOcts;
    current_IRI_parameter->locationOfTheTarget->rAI->Set(rAI);
}
//Struct GSMLocation of Location
void IRIs::CreateGSMLocationGeoCoordinates(const char *platitude,const char *plongitude, MapDatum  pmapDatum)
{
    CreateGSMLocation();
    current_IRI_parameter->locationOfTheTarget->gsmLocation->CreateGeoCoordinates(platitude,plongitude,pmapDatum);
}
void IRIs::CreateGSMLocationGeoCoordinates(const char *platitude,const char *plongitude,  unsigned int pazimuth, MapDatum  pmapDatum)
{
    CreateGSMLocation();
    current_IRI_parameter->locationOfTheTarget->gsmLocation->CreateGeoCoordinates(platitude,plongitude, pazimuth, pmapDatum);
}
void IRIs::CreateGSMLocationUtmCoordinates(const char *putm_East,const char *putm_North, MapDatum  pmapDatum)
{
    CreateGSMLocation();
    current_IRI_parameter->locationOfTheTarget->gsmLocation->CreateUtmCoordinates(putm_East, putm_North, pmapDatum);
}
void IRIs::CreateGSMLocationUtmCoordinates(const char *putm_East,const char *putm_North, unsigned int pazimuth, MapDatum  pmapDatum)
{
    CreateGSMLocation();
    current_IRI_parameter->locationOfTheTarget->gsmLocation->CreateUtmCoordinates(putm_East, putm_North, pazimuth, pmapDatum);
}
void IRIs::CreateGSMLocationUtmRefCoordinates(const char *putmref_string,MapDatum  pmapDatum)
{
    CreateGSMLocation();
    current_IRI_parameter->locationOfTheTarget->gsmLocation->CreateUtmRefCoordinates(putmref_string,pmapDatum);
}
void IRIs::CreateGSMLocationWGS84Coordinates( const char *pwGS84Coordinates)
{
    CreateGSMLocation();
    current_IRI_parameter->locationOfTheTarget->gsmLocation->CreateWGS84Coordinates(pwGS84Coordinates);
}


//Struct UMTSLocation of Location
void IRIs::CreateUMTSLocationPoint(GeographicalCoordinatesEnum platitudeSign,int platitude, int plongitude)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->umtsLocation = new UMTSLocation(platitudeSign, platitude, plongitude);
}
void IRIs::CreateUMTSLocationPointWithUnCertainty(GeographicalCoordinatesEnum platitudeSign,int platitude, int plongitude,unsigned int puncertaintyCode)
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->umtsLocation = new UMTSLocation(platitudeSign, platitude, plongitude, puncertaintyCode);
}
void IRIs::AddUMTSLocationPointToPolygon(GeographicalCoordinatesEnum platitudeSign,int platitude, int plongitude)
{
    CreateLocation();
    if (current_IRI_parameter->locationOfTheTarget->umtsLocation == NULL )
        current_IRI_parameter->locationOfTheTarget->umtsLocation = new UMTSLocation;
    current_IRI_parameter->locationOfTheTarget->umtsLocation->polygon->Append(platitudeSign, platitude, plongitude);
}


//Sai location
void IRIs::CreateLocationSAI(const char *sAI )
{
    CreateLocation();
    current_IRI_parameter->locationOfTheTarget->sAI = new AsnOcts;
    current_IRI_parameter->locationOfTheTarget->sAI->Set(sAI);
}

//*************Struct PartyInformation
PartyInformation*  IRIs::AddPartyInformation()
{
    if ( current_IRI_parameter->partyInformation == NULL )
        current_IRI_parameter->partyInformation = new IRI_ParametersSetOf;

    return current_IRI_parameter->partyInformation->Append();
}

//**************CallContentLinkInformation
void IRIs::CreateCallContentLinkInformation()
{
    if( current_IRI_parameter->callContentLinkInformation == NULL )
        current_IRI_parameter->callContentLinkInformation = new IRI_ParametersSeq;
}
void IRIs::CreateCallContentLinkInformationCCLink1Characteristics()
{
    CreateCallContentLinkInformation();
    if( current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics == NULL )
        current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics = new CallContentLinkCharacteristics;
}
void IRIs::CreateCallContentLinkInformationCCLink1CharacteristicsCCLinkState(CCLink_State pcCLink_State)
{
    CreateCallContentLinkInformationCCLink1Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics->cCLink_State = new CCLink_State(pcCLink_State);
}
void IRIs::CreateCallContentLinkInformationCCLink1CharacteristicsRelease_Time(const char *utcTimeStr)
{
    CreateCallContentLinkInformationCCLink1Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics->release_Time = new TimeStamp(utcTimeStr);
}
void IRIs::CreateCallContentLinkInformationCCLink1CharacteristicsRelease_Time(const char*generalizedTimeStr,LocalTimeStampEnum  pwinterSummerIndication)
{
    CreateCallContentLinkInformationCCLink1Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics->release_Time = new TimeStamp(generalizedTimeStr, pwinterSummerIndication);
}
void IRIs::CreateCallContentLinkInformationCCLink1CharacteristicsRelease_Reason(const char *release_Reason)
{
    CreateCallContentLinkInformationCCLink1Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics->release_Reason = new AsnOcts(release_Reason);
}
void IRIs::CreateCallContentLinkInformationCCLink1CharacteristicsLEMF_Address(CalledPartyNumber::ChoiceIdEnum pchoiceId, const char *number)
{
    CreateCallContentLinkInformationCCLink1Characteristics();
    int longitud=7;
    current_IRI_parameter->callContentLinkInformation->cCLink1Characteristics->lEMF_Address = new CalledPartyNumber(pchoiceId, number,longitud);
}

void IRIs::CreateCallContentLinkInformationCCLink2Characteristics()
{
    CreateCallContentLinkInformation();
    if( current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics == NULL )
        current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics = new CallContentLinkCharacteristics;
}
void IRIs::CreateCallContentLinkInformationCCLink2CharacteristicsCCLinkState(CCLink_State pcCLink_State)
{
    CreateCallContentLinkInformationCCLink2Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics->cCLink_State = new CCLink_State(pcCLink_State);
}
void IRIs::CreateCallContentLinkInformationCCLink2CharacteristicsRelease_Time(const char *utcTimeStr)
{
    CreateCallContentLinkInformationCCLink2Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics->release_Time = new TimeStamp(utcTimeStr);
}
void IRIs::CreateCallContentLinkInformationCCLink2CharacteristicsRelease_Time(const char*generalizedTimeStr,LocalTimeStampEnum  pwinterSummerIndication)
{
    CreateCallContentLinkInformationCCLink2Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics->release_Time = new TimeStamp(generalizedTimeStr, pwinterSummerIndication);
}
void IRIs::CreateCallContentLinkInformationCCLink2CharacteristicsRelease_Reason(const char *release_Reason)
{
    CreateCallContentLinkInformationCCLink2Characteristics();
    current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics->release_Reason = new AsnOcts(release_Reason);
}
void IRIs::CreateCallContentLinkInformationCCLink2CharacteristicsLEMF_Address(CalledPartyNumber::ChoiceIdEnum pchoiceId, const char *number)
{
    CreateCallContentLinkInformationCCLink2Characteristics();
    int longitud;
    current_IRI_parameter->callContentLinkInformation->cCLink2Characteristics->lEMF_Address = new CalledPartyNumber(pchoiceId, number,longitud);
}

//release_Reason_Of_Intercepted_Call
void IRIs::CreateReleaseReasonOfInterceptedCall(const char *releaseReason)
{
    current_IRI_parameter->release_Reason_Of_Intercepted_Call = new AsnOcts;
    current_IRI_parameter->release_Reason_Of_Intercepted_Call->Set(releaseReason);
}

//NatureOfTheInterceptedCall
/*enum IRI_ParametersEnum2 {
                            gSM_ISDN_PSTN_circuit_call, gSM_SMS_Message, uUS4_Messages,
                            tETRA_circuit_call, teTRA_Packet_Data, gPRS_Packet_Data,
                            uMTS_circuit_call
                            };
*/
void IRIs::CreateNatureOfTheInterceptedCall(IRI_ParametersEnum2 natureOfTheInterceptedCall)
{
    current_IRI_parameter->nature_Of_The_intercepted_call = new IRI_ParametersEnum2(natureOfTheInterceptedCall);
}

//ServerCenterAddress
PartyInformation* IRIs::CreateServerCenterAddress()
{
    current_IRI_parameter->serverCenterAddress = new PartyInformation;
    return current_IRI_parameter->serverCenterAddress;
}

//SMSReport
void IRIs::CreateSMSReport()
{
    if( current_IRI_parameter->sMS == NULL)
        current_IRI_parameter->sMS = new SMS_report;
}
    //Struct CommunicationIdentifier of SMSReport
void IRIs::CreateSMSReportCommunicationIdentityNumber(const char *identityNumber)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->communicationIdentifier->communication_Identity_Number = new AsnOcts;
    current_IRI_parameter->sMS->communicationIdentifier->communication_Identity_Number->Set(identityNumber);
}
void IRIs::SetSMSReportNetworkOperatorIdentifier(const char *operatorIdentifier)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->communicationIdentifier->network_Identifier->operator_Identifier.Set(operatorIdentifier);
}
void IRIs::CreateSMSReportNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, const char *str)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->communicationIdentifier->network_Identifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement,str);
}
void IRIs::CreateSMSReportNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type, IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str )
{
    CreateSMSReport();
    current_IRI_parameter->sMS->communicationIdentifier->network_Identifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement,ip_type, choiceIpTypeValue, str);
}
void IRIs::CreateSMSReportNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type, IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str, IPAddressEnum1 choiceIpAssignment )
{
    CreateSMSReport();
    current_IRI_parameter->sMS->communicationIdentifier->network_Identifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement,ip_type, choiceIpTypeValue, str, choiceIpAssignment);
}
    //Struct TimeStamp of SMSReport
void IRIs::SetSMSReportTimeStampUtcTime(const char *utcTimeStr)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->timeStamp->SetUTCTime(utcTimeStr);
}
void IRIs::SetSMSReportTimeStampLocalTime(const char *generalizedTimeStr, LocalTimeStampEnum  winterSummerIndication)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->timeStamp->SetLocalTimeStamp(generalizedTimeStr, winterSummerIndication);
}
    //Struct SMS_Contents
void IRIs::SetSMSReportSMSContentsInitiator(SMS_reportSeqEnum initiator)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->sMS_Contents->initiator = initiator;
}
void IRIs::CreateSMSReportSMSContentsTransferStatus(SMS_reportSeqEnum1 transfer_status)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->sMS_Contents->transfer_status =  new SMS_reportSeqEnum1(transfer_status);
}
void IRIs::CreateSMSReportSMSContentsOtherMessage (SMS_reportSeqEnum2	other_message)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->sMS_Contents->other_message =  new SMS_reportSeqEnum2(other_message);
}
void IRIs::CreateSMSReportSMSContentsContent(const char *content)
{
    CreateSMSReport();
    current_IRI_parameter->sMS->sMS_Contents->content =  new AsnOcts;
    current_IRI_parameter->sMS->sMS_Contents->content->Set(content);
}

//CCLinkIdentifier
void IRIs::CreateCCLinkIdentifier(const char *cCLinkIdentifier)
{
    current_IRI_parameter->cC_Link_Identifier = new CC_Link_Identifier;
    current_IRI_parameter->cC_Link_Identifier->Set(cCLinkIdentifier);
}

//NationalParameters
void IRIs::AddNationalParameters(const char *nationalParameter)
{
    if( current_IRI_parameter->national_Parameters == NULL )
        current_IRI_parameter->national_Parameters = new National_Parameters;

    AsnOcts *parameter = current_IRI_parameter->national_Parameters->Append();
    parameter->Set(nationalParameter);
}

//GPRSCorrelationNumber
void IRIs::CreateGPRSCorrelationNumber(const char *gPRSCorrelationNumber)
{
    current_IRI_parameter->gPRSCorrelationNumber = new GPRSCorrelationNumber;
    current_IRI_parameter->gPRSCorrelationNumber->Set(gPRSCorrelationNumber);
}

//GPRSEvent
/*
  enum GPRSEvent { pDPContextActivation, startOfInterceptionWithPDPContextActive, pDPContextDeactivation,
                   gPRSAttach, gPRSDetach, cellOrRAUpdate, sMS, pDPContextModification };
*/
void IRIs::CreateGPRSEvent(GPRSEvent gPRSEvent)
{
    current_IRI_parameter->gPRSevent = new GPRSEvent(gPRSEvent);
}

//SGSNDataNodeAddress
void IRIs::CreateSGSNDataNodeAddress(const char *px25Address)
{
    current_IRI_parameter->sgsnAddress = new DataNodeAddress(px25Address);
}
void IRIs::CreateSGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress )
{
    current_IRI_parameter->sgsnAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress);
}
void IRIs::CreateSGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment )
{
    current_IRI_parameter->sgsnAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress, choiceIpAssignment);
}
//GPRSOperationErrorCode
void IRIs::CreateGPRSOperationErrorCode(const char *gPRSOperationErrorCode)
{
    current_IRI_parameter->gPRSOperationErrorCode = new AsnOcts;
    current_IRI_parameter->gPRSOperationErrorCode->Set(gPRSOperationErrorCode);
}
//GGSNDataNodeAddress
void IRIs::CreateGGSNDataNodeAddress(const char *px25Address)
{
    current_IRI_parameter->ggsnAddress = new DataNodeAddress(px25Address);
}
void IRIs::CreateGGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress )
{
    current_IRI_parameter->ggsnAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress);
}
void IRIs::CreateGGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment )
{
    current_IRI_parameter->ggsnAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress, choiceIpAssignment);
}

//NetworkIdentifier
void IRIs::CreateNetworkIdentifier(const char *operatorIdentifier)
{
    current_IRI_parameter->networkIdentifier = new Network_Identifier;
    current_IRI_parameter->networkIdentifier->operator_Identifier.Set(operatorIdentifier);
}
void IRIs::SetNetworkIdentifierOperatorIdentifier(const char *operatorIdentifier)
{
    current_IRI_parameter->networkIdentifier->operator_Identifier.Set(operatorIdentifier);
}
void IRIs::CreateNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, const char *str)
{
    current_IRI_parameter->networkIdentifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement, str);
}
void IRIs::CreateNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str )
{
    current_IRI_parameter->networkIdentifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement, ip_type, choiceIpTypeValue, str);
}
void IRIs::CreateNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str, IPAddressEnum1 choiceIpAssignment )
{
    current_IRI_parameter->networkIdentifier->network_Element_Identifier = new Network_Element_Identifier(typeOfElement, ip_type, choiceIpTypeValue, str, choiceIpAssignment);
}

//SMSOriginatingAddress
void IRIs::CreateSMSOriginatingAddress(const char *px25Address)
{
    current_IRI_parameter->sMSOriginatingAddress = new DataNodeAddress(px25Address);
}
void IRIs::CreateSMSOriginatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress )
{
    current_IRI_parameter->sMSOriginatingAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress);
}
void IRIs::CreateSMSOriginatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment )
{
    current_IRI_parameter->sMSOriginatingAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress, choiceIpAssignment);
}

//SMSTerminatingAddress
void IRIs::CreateSMSTerminatingAddress(const char *px25Address)
{
    current_IRI_parameter->sMSTerminatingAddress = new DataNodeAddress(px25Address);
}
void IRIs::CreateSMSTerminatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress )
{
    current_IRI_parameter->sMSTerminatingAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress);
}
void IRIs::CreateSMSTerminatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment )
{
    current_IRI_parameter->sMSTerminatingAddress = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress, choiceIpAssignment);
}

//SIPMessage
void IRIs::CreateSIPMessage(const char *sIPMessage)
{
    current_IRI_parameter->sIPMessage = new AsnOcts;
    current_IRI_parameter->sIPMessage->Set(sIPMessage );
}
//ServingSGSNNumber
void IRIs::CreateServingSGSNNumber(const char *servingSGSNNumber)
{
    current_IRI_parameter->servingSGSN_number = new AsnOcts;
    current_IRI_parameter->servingSGSN_number->Set(servingSGSNNumber );
}
//ServingSGSNAddress
void IRIs::CreateServingSGSNAddress(const char *servingSGSNAddress)
{
    current_IRI_parameter->servingSGSN_address= new AsnOcts;
    current_IRI_parameter->servingSGSN_address->Set(servingSGSNAddress );
}
//NationalHI2ASN1parameters
void IRIs::CreateNationalHI2ASN1parametersCountryCode(const char *countryCode)
{
    current_IRI_parameter->national_HI2_ASN1parameters = new National_HI2_ASN1parameters;
    current_IRI_parameter->national_HI2_ASN1parameters->countryCode.Set( countryCode);
}





//Private
void  IRIs::CreateLocation()
{
    if( current_IRI_parameter->locationOfTheTarget == NULL)
        current_IRI_parameter->locationOfTheTarget = new Location;
}

void IRIs::CreateGSMLocation()
{
    CreateLocation();
    //if( current_IRI_parameter->locationOfTheTarget->gsmLocation == NULL )
    delete current_IRI_parameter->locationOfTheTarget->gsmLocation;
    current_IRI_parameter->locationOfTheTarget->gsmLocation = new GSMLocation;//choice
}

void IRIs::CreateUMTSLocation()
{
    CreateLocation();
    if( current_IRI_parameter->locationOfTheTarget->umtsLocation == NULL )
        current_IRI_parameter->locationOfTheTarget->umtsLocation = new UMTSLocation;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


/** **********************************************************************
 *                                                                       *
 *                              IRISEQUENCE                              *
 *                                                                       *
 ********************************************************************** **/


AsnType *IRISequence::Clone() const
{
  return new IRISequence;
}

AsnLen IRISequence::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void IRISequence::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    Asn1Error << "IRISequence::BDec: ERROR - wrong tag" << endl;
    longjmp (env, -110);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

IRISequence::IRISequence (const IRISequence &)
{
  Asn1Error << "use of incompletely defined IRISequence::IRISequence (const IRISequence &)" << endl;
  abort();
}

IRISequence::~IRISequence()
{
  SetCurrToFirst();
  for (; Curr() != NULL; RemoveCurrFromList())
    ;
} // end of destructor

#if SNACC_DEEP_COPY
IRISequence &IRISequence::operator = (const IRISequence &that)
#else // SNACC_DEEP_COPY
IRISequence &IRISequence::operator = (const IRISequence &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    SetCurrToFirst();
    for (; Curr(); RemoveCurrFromList())
      ;

    //that.SetCurrToFirst();
    //for (; that.Curr(); that.GoNext())
    //  AppendCopy (*that.Curr());
    for (const AsnListElmt *run=that.first; run; run=run->next)
      AppendCopy (*run->elmt);
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined IRISequence &IRISequence::operator = (const IRISequence &)" << endl;
  abort();
  // if your compiler complains here, check the -novolat option
#endif // SNACC_DEEP_COPY
}

void  IRISequence::SetCurrElmt (unsigned long int index)
{
  unsigned long int i;
  curr = first;
  if (count)
    for (i = 0; (i < (count-1)) && (i < index); i++)
      curr = curr->next;
} // IRISequence::SetCurrElmt


unsigned long int  IRISequence::GetCurrElmtIndex()
{
    unsigned long int i;
    AsnListElmt *tmp;
    if (curr != NULL)
    {
        for (i = 0, tmp = first; tmp != NULL; i++)
        {
            if (tmp == curr)
                return i;
            else
                tmp = tmp->next;
        }
    }
    return count;
} // IRISequence::GetCurrElmtIndex


// alloc new list elmt, put at end of list
//  and return the component type
IRIsChoice *IRISequence::Append()
{
    AsnListElmt *newElmt;
    newElmt  = new AsnListElmt;
    newElmt->elmt  = new IRIsChoice;
    newElmt->next = NULL;
    if (last == NULL)
    {
        newElmt->prev = NULL;
        first = last  = newElmt;
    }
    else
    {
        newElmt->prev = last;
        last->next    = newElmt;
        last          = newElmt;
    }
    count++;
    return (curr = newElmt)->elmt;
} // IRISequence::Append


// alloc new list elmt, put at begining of list
//  and return the component type
IRIsChoice  *IRISequence::Prepend()
{
    AsnListElmt *newElmt;
    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    newElmt->prev = NULL;
    if (first == NULL)
    {
        newElmt->next = NULL;
        first = last  = newElmt;
    }
    else
    {
        newElmt->next = first;
        first->prev   = newElmt;
        first         = newElmt;
    }
    count++;
    return (curr = newElmt)->elmt;
} // IRISequence::Prepend


// alloc new list elmt, insert it before the
// current element and return the component type
// if the current element is null, the new element
// is placed at the beginning of the list.
IRIsChoice  *IRISequence::InsertBefore()
{
    AsnListElmt *newElmt;
    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    if (curr == NULL)
    {
        newElmt->next = first;
        newElmt->prev = NULL;
        first = newElmt;
        if (last == NULL)
            last = newElmt;
    }
    else
    {
        newElmt->next = curr;
        newElmt->prev = curr->prev;
        curr->prev = newElmt;
        if (curr == first)
            first = newElmt;
        else
            newElmt->prev->next = newElmt;
    }
    count++;
    return (curr = newElmt)->elmt;
} // IRISequence::InsertBefore


// alloc new list elmt, insert it after the
// current element and return the component type
// if the current element is null, the new element
// is placed at the end of the list.
IRIsChoice *IRISequence::InsertAfter()
{
    AsnListElmt *newElmt;
    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    if (curr == NULL)
    {
        newElmt->prev = last;
        newElmt->next = NULL;
        last = newElmt;
        if (first == NULL)
            first = newElmt;
    }
    else
    {
        newElmt->prev = curr;
        newElmt->next = curr->next;
        curr->next = newElmt;
        if (curr == last)
            last = newElmt;
        else
            newElmt->next->prev = newElmt;
    }
    count++;
    return (curr = newElmt)->elmt;
} // IRISequence::InsertAfter

IRISequence  &IRISequence::AppendCopy (IRIsChoice &elmt)
{
    AsnListElmt *newElmt;
    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    *newElmt->elmt = elmt;
    newElmt->next = NULL;
    if (last == NULL)
    {
        newElmt->prev = NULL;
        first = last  = newElmt;
    }
    else
    {
        newElmt->prev = last;
        last->next    = newElmt;
        last          = newElmt;
    }
    count++;
    return *this;
} // AppendCopy


IRISequence  &IRISequence::PrependCopy (IRIsChoice &elmt)
{
    AsnListElmt *newElmt;
    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    *newElmt->elmt = elmt;
    newElmt->prev = NULL;
    if (first == NULL)
    {
        newElmt->next = NULL;
        first = last  = newElmt;
    }
    else
    {
        newElmt->next = first;
        first->prev   = newElmt;
        first         = newElmt;
    }
    count++;
    return *this;
} // IRISequence::PrependCopy


// alloc new list elmt, insert it before the
// current element, copy the given elmt into the new elmt
// and return the component type.
// if the current element is null, the new element
// is placed at the beginning of the list.
IRISequence &IRISequence::InsertBeforeAndCopy (IRIsChoice &elmt)
{
    AsnListElmt *newElmt;

    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    *newElmt->elmt = elmt;

    if (curr == NULL)
    {
        newElmt->next = first;
        newElmt->prev = NULL;
        first = newElmt;
        if (last == NULL)
            last = newElmt;
    }
    else
    {
        newElmt->next = curr;
        newElmt->prev = curr->prev;
        curr->prev = newElmt;
        if (curr == first)
            first = newElmt;
        else
            newElmt->prev->next = newElmt;
    }
    count++;
    return *this;
} // IRISequence::InsertBeforeAndCopy


// alloc new list elmt, insert it after the
// current element, copy given elmt in to new elmt
//  and return the component type
// if the current element is null, the new element
// is placed at the end of the list.
IRISequence  &IRISequence::InsertAfterAndCopy (IRIsChoice &elmt)
{
    AsnListElmt *newElmt;

    newElmt  = new AsnListElmt;
    newElmt->elmt = new IRIsChoice;
    *newElmt->elmt = elmt;
    if (curr == NULL)
    {
        newElmt->prev = last;
        newElmt->next = NULL;
        last = newElmt;
        if (first == NULL)
            first = newElmt;
    }
    else
    {
        newElmt->prev = curr;
        newElmt->next = curr->next;
        curr->next = newElmt;
        if (curr == last)
            last = newElmt;
        else
            newElmt->next->prev = newElmt;
    }
    count++;
    return *this;
} // IRISequence::InsertAfterAndCopy


// remove current element from list if current element is not NULL
// The new current element will be the next element.
// If the current element is the last element in the list
// the second but last element will become the new current element.
void IRISequence::RemoveCurrFromList()
{
    AsnListElmt *del_elmt;

    if (curr != NULL)
    {
        del_elmt = curr;
        count--;

        if (count == 0)
            first = last = curr = NULL;
        else if (curr == first)
        {
            curr = first= first->next;
            first->prev = NULL;
        }
        else if (curr == last)
        {
            curr = last = last->prev;
            last->next = NULL;
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete del_elmt->elmt;
        delete del_elmt;
    }
}


AsnLen IRISequence::BEncContent (BUF_TYPE b)
{
    AsnListElmt *currElmt;
    AsnLen elmtLen;
    AsnLen totalLen = 0;
    for (currElmt = last; currElmt != NULL; currElmt = currElmt->prev)
    {
        elmtLen = currElmt->elmt->BEncContent (b);
        totalLen += elmtLen;
    }
    return totalLen;
} // IRISequence::BEncContent


void  IRISequence::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0,
                                  AsnLen &bytesDecoded, ENV_TYPE env)
{
    IRIsChoice *listElmt;
    AsnTag tag1;
    AsnLen listBytesDecoded = 0;
    AsnLen elmtLen1;

    while ((listBytesDecoded < elmtLen0) || (elmtLen0 == INDEFINITE_LEN))
    {
        tag1 = BDecTag (b, listBytesDecoded, env);
        if ((tag1 == EOC_TAG_ID) && (elmtLen0 == INDEFINITE_LEN))
        {
            BDEC_2ND_EOC_OCTET (b, listBytesDecoded, env);
            break;
        }
        if (!((tag1 == MAKE_TAG_ID (CNTX, CONS, 1))
         || (tag1 == MAKE_TAG_ID (CNTX, CONS, 2))
         || (tag1 == MAKE_TAG_ID (CNTX, CONS, 3))
         || (tag1 == MAKE_TAG_ID (CNTX, CONS, 4))))
        {
            Asn1Error << "Unexpected Tag" << endl;
            longjmp (env, -111);
        }

        elmtLen1 = BDecLen (b, listBytesDecoded, env);
        listElmt = Append();
        listElmt->BDecContent (b, tag1, elmtLen1, listBytesDecoded, env);
    }

    bytesDecoded += listBytesDecoded;
} // IRISequence::BDecContent


