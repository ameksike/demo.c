#ifndef IRI_H_INCLUDED
#define IRI_H_INCLUDED

#include "src/include/iri/IRIaux.h"

class IRIs: public AsnType
{
  private:
    IRIsChoice		*iRIContent;
    IRI_Parameters      *current_IRI_parameter;

  public:
    IRIs();
    IRIs(IRIsChoice::ChoiceIdEnum );
    IRIs(IRIsChoice&);
    IRIs(const IRIs &);
    ~IRIs();
    AsnType *Clone() const;

    IRIs    &operator = (const IRIs &);
    AsnLen  BEncContent (BUF_TYPE b);
    void    BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

    AsnLen  BEnc (BUF_TYPE b);
    void    BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
    int	    BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
    int	    BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

    void    Print (std::ostream &os) const;

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

//----------------------------------------------------------------------

class IRISequence: public AsnType
{
protected:
  unsigned long int	count;
  struct AsnListElmt
  {
    AsnListElmt	*next;
    AsnListElmt	*prev;
    IRIsChoice	*elmt;
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
  IRIsChoice	*First() const	{ return count > 0 ? first->elmt : NULL; }
  IRIsChoice	*Last() const	{ return count > 0 ? last->elmt : NULL; }
  IRIsChoice	*Curr() const	{ return curr ? curr->elmt : NULL; }
  IRIsChoice	*Next() const	{ return curr && curr->next ? curr->next->elmt : NULL; }
  IRIsChoice	*Prev() const	{ return curr && curr->prev ? curr->prev->elmt : NULL; }

  // routines that move the curr elmt
  IRIsChoice	*GoNext() { if (curr) curr = curr->next; return Curr(); }
  IRIsChoice	*GoPrev() { if (curr) curr = curr->prev; return Curr(); }

  // write & alloc fcns - returns new elmt
  IRIsChoice	*Append();  // add elmt to end of list
  IRIsChoice	*Prepend(); // add elmt to beginning of list
  IRIsChoice	*InsertBefore(); //insert elmt before current elmt
  IRIsChoice	*InsertAfter(); //insert elmt after current elmt

  // write & alloc & copy - returns list after copying elmt
  IRISequence	&AppendCopy (IRIsChoice &elmt);  // add elmt to end of list
  IRISequence	&PrependCopy (IRIsChoice &elmt); // add elmt to beginning of list
  IRISequence	&InsertBeforeAndCopy (IRIsChoice &elmt); //insert elmt before current elmt
  IRISequence	&InsertAfterAndCopy (IRIsChoice &elmt); //insert elmt after current elmt

  // removing the current elmt from the list
  void		RemoveCurrFromList();

  // encode and decode routines
  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  PDU_MEMBER_MACROS
};

#endif // LIBIRI_H_INCLUDED
