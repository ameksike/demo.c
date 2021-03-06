//   NOTE: this is a machine generated file--editing not recommended
//
// IRI.h - class definitions for ASN.1 module IRI
//
//   This file was generated by snacc on Thu Jun 10 13:42:06 2010
//   UBC snacc by Mike Sample
//   A couple of enhancements made by IBM European Networking Center

#ifndef _IRI_h_
#define _IRI_h_
#include <iostream>
using namespace std;

#include "ParametersFormat.h"
#include "asn-incl.h"

//------------------------------------------------------------------------------
// class declarations:

class IRI_ParametersEnum2;
class IRI_ParametersEnum1;
class IRI_ParametersEnum;
class IRI_ParametersSeq;
class IRI_ParametersSetOf;
class IRI_Parameters;
class IRIContent;
class IRISequence;
class IRIsContent;

//------------------------------------------------------------------------------
// class definitions:

/* ENUMERATED { gSM_ISDN_PSTN_circuit_call (0), gSM_SMS_Message (1), uUS4_Messages (2), tETRA_circuit_call (3), teTRA_Packet_Data (4), gPRS_Packet_Data (5), uMTS_circuit_call (6) }  */
class IRI_ParametersEnum2: public AsnEnum
{
public:
			IRI_ParametersEnum2(): AsnEnum() {}
			IRI_ParametersEnum2 (int i): AsnEnum (i) {}
  enum
  {
    gSM_ISDN_PSTN_circuit_call = 0,
    gSM_SMS_Message = 1,
    uUS4_Messages = 2,
    tETRA_circuit_call = 3,
    teTRA_Packet_Data = 4,
    gPRS_Packet_Data = 5,
    uMTS_circuit_call = 6
  };
};


/* ENUMERATED { not_Available (0), originating_Target (1), terminating_Target (2) }  */
class IRI_ParametersEnum1: public AsnEnum
{
public:
			IRI_ParametersEnum1(): AsnEnum() {}
			IRI_ParametersEnum1 (int i): AsnEnum (i) {}
  enum
  {
    not_Available = 0,
    originating_Target = 1,
    terminating_Target = 2
  };
};


/* ENUMERATED { version2 (2), version3 (3), version4 (4), version5 (5), version6 (6), version7 (7) }  */
class IRI_ParametersEnum: public AsnEnum
{
public:
			IRI_ParametersEnum(): AsnEnum() {}
			IRI_ParametersEnum (int i): AsnEnum (i) {}
  enum
  {
    version2 = 2,
    version3 = 3,
    version4 = 4,
    version5 = 5,
    version6 = 6,
    version7 = 7
  };
};


class IRI_ParametersSeq: public AsnType
{
public:
  CallContentLinkCharacteristics		*cCLink1Characteristics;
  CallContentLinkCharacteristics		*cCLink2Characteristics;

			IRI_ParametersSeq();
			IRI_ParametersSeq (const IRI_ParametersSeq &);
			~IRI_ParametersSeq();
  AsnType		*Clone() const;

  IRI_ParametersSeq		&operator = (const IRI_ParametersSeq &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

};


class IRI_ParametersSetOf: public AsnType
{
protected:
  unsigned long int	count;
  struct AsnListElmt
  {
    AsnListElmt	*next;
    AsnListElmt	*prev;
    PartyInformation	*elmt;
  }			*first, *curr, *last;

public:
			IRI_ParametersSetOf() { count = 0; first = curr = last = NULL; }
			IRI_ParametersSetOf (const IRI_ParametersSetOf &);
			~IRI_ParametersSetOf();
  AsnType		*Clone() const;

  IRI_ParametersSetOf		&operator = (const IRI_ParametersSetOf &);
  void		SetCurrElmt (unsigned long int index);
  unsigned long int	GetCurrElmtIndex();
  void		SetCurrToFirst() { curr = first; }
  void		SetCurrToLast()  { curr = last; }
  // reading member fcns
  int			Count() const	{ return count; }
  // NOTE: if your compiler complains about these NULLs, its definition of NULL is broken (and you better change it there!)
  PartyInformation	*First() const	{ return count > 0 ? first->elmt : NULL; }
  PartyInformation	*Last() const	{ return count > 0 ? last->elmt : NULL; }
  PartyInformation	*Curr() const	{ return curr ? curr->elmt : NULL; }
  PartyInformation	*Next() const	{ return curr && curr->next ? curr->next->elmt : NULL; }
  PartyInformation	*Prev() const	{ return curr && curr->prev ? curr->prev->elmt : NULL; }

  // routines that move the curr elmt
  PartyInformation	*GoNext() { if (curr) curr = curr->next; return Curr(); }
  PartyInformation	*GoPrev() { if (curr) curr = curr->prev; return Curr(); }

  // write & alloc fcns - returns new elmt
  PartyInformation	*Append();  // add elmt to end of list
  PartyInformation	*Prepend(); // add elmt to beginning of list
  PartyInformation	*InsertBefore(); //insert elmt before current elmt
  PartyInformation	*InsertAfter(); //insert elmt after current elmt

  // write & alloc & copy - returns list after copying elmt
  IRI_ParametersSetOf	&AppendCopy (PartyInformation &elmt);  // add elmt to end of list
  IRI_ParametersSetOf	&PrependCopy (PartyInformation &elmt); // add elmt to beginning of list
  IRI_ParametersSetOf	&InsertBeforeAndCopy (PartyInformation &elmt); //insert elmt before current elmt
  IRI_ParametersSetOf	&InsertAfterAndCopy (PartyInformation &elmt); //insert elmt after current elmt

  // removing the current elmt from the list
  void		RemoveCurrFromList();

  // encode and decode routines    
  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS
};


class IRI_Parameters: public AsnType
{
public:
  AsnOid		*domainID;
  IRI_ParametersEnum		*iRIversion;
  LawfulInterceptionIdentifier		lawfulInterceptionIdentifier;
  CommunicationIdentifier		*communicationIdentifier;
  TimeStamp		*timeStamp;
  IRI_ParametersEnum1		*intercepted_Call_Direct;
  Intercepted_Call_State		*intercepted_Call_State;
  AsnOcts		*ringingDuration;
  AsnOcts		*conversationDuration;
  Location		*locationOfTheTarget;
  IRI_ParametersSetOf		*partyInformation;
  IRI_ParametersSeq		*callContentLinkInformation;
  AsnOcts		*release_Reason_Of_Intercepted_Call;
  IRI_ParametersEnum2		*nature_Of_The_intercepted_call;
  PartyInformation		*serverCenterAddress;
  SMS_report		*sMS;
  CC_Link_Identifier		*cC_Link_Identifier;
  National_Parameters		*national_Parameters;
  GPRSCorrelationNumber		*gPRSCorrelationNumber;
  GPRSEvent		*gPRSevent;
  DataNodeAddress		*sgsnAddress;
  GPRSOperationErrorCode		*gPRSOperationErrorCode;
  DataNodeAddress		*ggsnAddress;
  Network_Identifier		*networkIdentifier;
  DataNodeAddress		*sMSOriginatingAddress;
  DataNodeAddress		*sMSTerminatingAddress;
  AsnOcts		*sIPMessage;
  AsnOcts		*servingSGSN_number;
  AsnOcts		*servingSGSN_address;
  National_HI2_ASN1parameters		*national_HI2_ASN1parameters;

			IRI_Parameters();
			IRI_Parameters (const IRI_Parameters &);
			~IRI_Parameters();
  AsnType		*Clone() const;

  IRI_Parameters		&operator = (const IRI_Parameters &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

};


class IRIContent: public AsnType
{
public:
  enum ChoiceIdEnum
  {
     iRI_Begin_recordCid = 0,
     iRI_End_recordCid = 1,
     iRI_Continue_recordCid = 2,
     iRI_Report_recordCid = 3
  };

  enum ChoiceIdEnum	choiceId;
  union
  {
     IRI_Parameters		*iRI_Begin_record;
     IRI_Parameters		*iRI_End_record;
     IRI_Parameters		*iRI_Continue_record;
     IRI_Parameters		*iRI_Report_record;
  };

  IRI_Parameters *current_IRI_parameter;


			IRIContent();
                        IRIContent(ChoiceIdEnum);
			IRIContent (const IRIContent &);
			~IRIContent();

  AsnType		*Clone() const;

  IRIContent		&operator = (const IRIContent &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

////////////////////////////////////////////////////////////////////////////////////////////
    //Metodos para cambiar los datos de un iri
    void CreateLawfulInterceptionIdentifier(char *lawfulInterceptionIdentifier, int len);
    //Struct CommunicationIdentifier
    void CreateCommunicationIdentifierIdentityNumber(const char *identityNumber);
    void CreateCommunicationIdentifierNetworkIdentifierOperatorIdentifier(const char *operatorIdentifier);
    void CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, const char *str);
    void CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str );
    void CreateCommunicationIdentifierNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str, IPAddressEnum1 choiceIpAssignment );
    //Struct TimeStamp
    void CreateTimeStampUtcTime(const char *utcTimeStr);
    void CreateTimeStampLocalTime(const char *generalizedTimeStr, LocalTimeStampEnum  winterSummerIndication);
    //InterceptedCallDirect
    void CreateInterceptedCallDirect( IRI_ParametersEnum1 intercepted_Call_Direct);
    //Intercepted_Call_State
    void CreateInterceptedCallState(Intercepted_Call_State intercepted_Call_State);
    //RingingDuration
    void CreateRingingDuration(const char *ringingDuration);
    //ConversationDuration
    void CreateConversationDuration(const char *conversationDuration);
    //Struct Location
    void CreateLocationE164_Number(const char *e164_Number);
    void CreateLocationGlobalCellID(const char *globalCellID);
    //Struct TetraLocation of Location
    void CreateLocationTetraLocation(int pls_loc);
    void CreateLocationTetraLocation(unsigned int mcc, unsigned int mnc, unsigned int lai);
    void CreateLocationTetraLocation(unsigned int mcc, unsigned int mnc, unsigned int lai, int ci);
    void CreateLocationRAI(const char *rAI);
    //Struct GSMLocation of Location
    void CreateGSMLocationGeoCoordinates(const char *platitude,const char *plongitude, MapDatum  pmapDatum= MapDatum::wGS84);
    void CreateGSMLocationGeoCoordinates(const char *platitude,const char *plongitude,  unsigned int pazimuth, MapDatum  pmapDatum= MapDatum::wGS84);
    void CreateGSMLocationUtmCoordinates(const char *putm_East,const char *putm_North, MapDatum  pmapDatum= MapDatum::wGS84);
    void CreateGSMLocationUtmCoordinates(const char *putm_East,const char *putm_North, unsigned int pazimuth, MapDatum  pmapDatum= MapDatum::wGS84);
    void CreateGSMLocationUtmRefCoordinates(const char *putmref_string,MapDatum  pmapDatum= MapDatum::wGS84);
    void CreateGSMLocationWGS84Coordinates( const char *pwGS84Coordinates);
    //Struct UMTSLocation of Location
    void CreateUMTSLocationPoint(GeographicalCoordinatesEnum platitudeSign,int platitude, int plongitude);
    void CreateUMTSLocationPointWithUnCertainty(GeographicalCoordinatesEnum platitudeSign,int platitude, int plongitude,unsigned int puncertaintyCode);
    void AddUMTSLocationPointToPolygon(GeographicalCoordinatesEnum platitudeSign,int platitude, int plongitude);
    void CreateLocationSAI(const char *sAI );
    //Struct PartyInformation
    PartyInformation*  AddPartyInformation();
    //CallContentLinkInformation
    void CreateCallContentLinkInformation();
    void CreateCallContentLinkInformationCCLink1Characteristics();
    void CreateCallContentLinkInformationCCLink1CharacteristicsCCLinkState(CCLink_State pcCLink_State);
    void CreateCallContentLinkInformationCCLink1CharacteristicsRelease_Time(const char *utcTimeStr);
    void CreateCallContentLinkInformationCCLink1CharacteristicsRelease_Time(const char*generalizedTimeStr,LocalTimeStampEnum  pwinterSummerIndication);
    void CreateCallContentLinkInformationCCLink1CharacteristicsRelease_Reason(const char *release_Reason);
    void CreateCallContentLinkInformationCCLink1CharacteristicsLEMF_Address(CalledPartyNumber::ChoiceIdEnum pchoiceId, const char *number);
    void CreateCallContentLinkInformationCCLink2Characteristics();
    void CreateCallContentLinkInformationCCLink2CharacteristicsCCLinkState(CCLink_State pcCLink_State);
    void CreateCallContentLinkInformationCCLink2CharacteristicsRelease_Time(const char *utcTimeStr);
    void CreateCallContentLinkInformationCCLink2CharacteristicsRelease_Time(const char*generalizedTimeStr,LocalTimeStampEnum  pwinterSummerIndication);
    void CreateCallContentLinkInformationCCLink2CharacteristicsRelease_Reason(const char *release_Reason);
    void CreateCallContentLinkInformationCCLink2CharacteristicsLEMF_Address(CalledPartyNumber::ChoiceIdEnum pchoiceId, const char *number);
    //release_Reason_Of_Intercepted_Call
    void CreateReleaseReasonOfInterceptedCall(const char *releaseReason);
    //NatureOfTheInterceptedCall
    void CreateNatureOfTheInterceptedCall(IRI_ParametersEnum2 natureOfTheInterceptedCall);
    //ServerCenterAddress
    PartyInformation* CreateServerCenterAddress();
    //SMSReport
    void CreateSMSReport();
    //Struct CommunicationIdentifier of SMSReport
    void CreateSMSReportCommunicationIdentityNumber(const char *identityNumber);
    void SetSMSReportNetworkOperatorIdentifier(const char *operatorIdentifier);
    void CreateSMSReportNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, const char *str);
    void CreateSMSReportNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str );
    void CreateSMSReportNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str, IPAddressEnum1 choiceIpAssignment );
    //Struct TimeStamp of SMSReport
    void SetSMSReportTimeStampUtcTime(const char *utcTimeStr);
    void SetSMSReportTimeStampLocalTime(const char *generalizedTimeStr, LocalTimeStampEnum  winterSummerIndication);
    //Struct SMS_Contents
    void SetSMSReportSMSContentsInitiator(SMS_reportSeqEnum initiator);
    void CreateSMSReportSMSContentsTransferStatus(SMS_reportSeqEnum1 transfer_status);
    void CreateSMSReportSMSContentsOtherMessage (SMS_reportSeqEnum2	other_message);
    void CreateSMSReportSMSContentsContent(const char *content);
    //CCLinkIdentifier
    void CreateCCLinkIdentifier(const char *cCLinkIdentifier);
    //NationalParameters
    void AddNationalParameters(const char *nationalParameter);
    //GPRSCorrelationNumber
    void CreateGPRSCorrelationNumber(const char *gPRSCorrelationNumber);
    //GPRSEvent
    void CreateGPRSEvent(GPRSEvent gPRSEvent);
    //SGSNDataNodeAddress
    void CreateSGSNDataNodeAddress(const char *px25Address);
    void CreateSGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress );
    void CreateSGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment );
    //GPRSOperationErrorCode
    void CreateGPRSOperationErrorCode(const char *gPRSOperationErrorCode);
    //GGSNDataNodeAddress
    void CreateGGSNDataNodeAddress(const char *px25Address);
    void CreateGGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress );
    void CreateGGSNDataNodeAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment );
    //NetworkIdentifier
    void CreateNetworkIdentifier(const char *operatorIdentifier);
    void SetNetworkIdentifierOperatorIdentifier(const char *operatorIdentifier);
    void CreateNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, const char *str);
    void CreateNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str );
    void CreateNetworkIdentifierNetworkElementIdentifier(Network_Element_Identifier::ChoiceIdEnum typeOfElement, IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *str, IPAddressEnum1 choiceIpAssignment );
    //SMSOriginatingAddress
    void CreateSMSOriginatingAddress(const char *px25Address);
    void CreateSMSOriginatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress );
    void CreateSMSOriginatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment );
    //SMSTerminatingAddress
    void CreateSMSTerminatingAddress(const char *px25Address);
    void CreateSMSTerminatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress );
    void CreateSMSTerminatingAddress(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment );
    //SIPMessage
    void CreateSIPMessage(const char *sIPMessage);
    //ServingSGSNNumber
    void CreateServingSGSNNumber(const char *servingSGSNNumber);
    //ServingSGSNAddress
    void CreateServingSGSNAddress(const char *servingSGSNAddress);
    //NationalHI2ASN1parameters
    void CreateNationalHI2ASN1parametersCountryCode(const char *countryCode);


private:
    void CreateLocation();
    void CreateGSMLocation();
    void CreateUMTSLocation();


};


class IRISequence: public AsnType
{
protected:
  unsigned long int	count;
  struct AsnListElmt
  {
    AsnListElmt	*next;
    AsnListElmt	*prev;
    IRIContent	*elmt;
  }			*first, *curr, *last;

public:
			IRISequence() { count = 0; first = curr = last = NULL; }
			IRISequence (const IRISequence &);
			~IRISequence();
  AsnType		*Clone() const;

  IRISequence		&operator = (const IRISequence &);
  void		SetCurrElmt (unsigned long int index);
  unsigned long int	GetCurrElmtIndex();
  void		SetCurrToFirst() { curr = first; }
  void		SetCurrToLast()  { curr = last; }
  // reading member fcns
  int			Count() const	{ return count; }
  // NOTE: if your compiler complains about these NULLs, its definition of NULL is broken (and you better change it there!)
  IRIContent	*First() const	{ return count > 0 ? first->elmt : NULL; }
  IRIContent	*Last() const	{ return count > 0 ? last->elmt : NULL; }
  IRIContent	*Curr() const	{ return curr ? curr->elmt : NULL; }
  IRIContent	*Next() const	{ return curr && curr->next ? curr->next->elmt : NULL; }
  IRIContent	*Prev() const	{ return curr && curr->prev ? curr->prev->elmt : NULL; }

  // routines that move the curr elmt
  IRIContent	*GoNext() { if (curr) curr = curr->next; return Curr(); }
  IRIContent	*GoPrev() { if (curr) curr = curr->prev; return Curr(); }

  // write & alloc fcns - returns new elmt
  IRIContent	*Append();  // add elmt to end of list
  IRIContent	*Prepend(); // add elmt to beginning of list
  IRIContent	*InsertBefore(); //insert elmt before current elmt
  IRIContent	*InsertAfter(); //insert elmt after current elmt

  // write & alloc & copy - returns list after copying elmt
  IRISequence	&AppendCopy (IRIContent &elmt);  // add elmt to end of list
  IRISequence	&PrependCopy (IRIContent &elmt); // add elmt to beginning of list
  IRISequence	&InsertBeforeAndCopy (IRIContent &elmt); //insert elmt before current elmt
  IRISequence	&InsertAfterAndCopy (IRIContent &elmt); //insert elmt after current elmt

  // removing the current elmt from the list
  void		RemoveCurrFromList();

  // encode and decode routines    
  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS
};


class IRIsContent: public AsnType
{
public:
  enum ChoiceIdEnum
  {
     iRIContentCid  = 0,
     iRISequenceCid = 1
  };

  enum ChoiceIdEnum	choiceId;
  union
  {
     IRIContent		*iRIContent;
     IRISequence	*iRISequence;
  };


			IRIsContent();
			IRIsContent (const IRIsContent &);
			~IRIsContent();

  AsnType		*Clone() const;

  IRIsContent		&operator = (const IRIsContent &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

};


//------------------------------------------------------------------------------

#endif /* conditional include of IRI.h */
