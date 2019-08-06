#include "PartyInformation.h"

PartyInformation::PartyInformation()
{
//#if TCL
  partyIdentity = new PartyInformationSeq;
//#else
//  partyIdentity = NULL; // incomplete initialization of mandatory element!
//#endif // TCL
  services_Information = NULL;
  supplementary_Services_Information = NULL;
  services_Data_Information = NULL;
}

PartyInformation::PartyInformation (const PartyInformation &)
{
  Asn1Error << "use of incompletely defined PartyInformation::PartyInformation (const PartyInformation &)" << std::endl;
  abort();
}

PartyInformation::~PartyInformation()
{
  delete partyIdentity;
  delete services_Information;
  delete supplementary_Services_Information;
  delete services_Data_Information;
}

AsnType *PartyInformation::Clone() const
{
  return new PartyInformation;
}

#if SNACC_DEEP_COPY
PartyInformation &PartyInformation::operator = (const PartyInformation &that)
#else // SNACC_DEEP_COPY
PartyInformation &PartyInformation::operator = (const PartyInformation &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    party_Qualifier = that.party_Qualifier;
    if (that.partyIdentity)
    {
      if (!partyIdentity)
        partyIdentity = new PartyInformationSeq;
      *partyIdentity = *that.partyIdentity;
    }
    else
    {
      delete partyIdentity;
      partyIdentity = NULL;
    }
    if (that.services_Information)
    {
      if (!services_Information)
        services_Information = new Services_Information;
      *services_Information = *that.services_Information;
    }
    else
    {
      delete services_Information;
      services_Information = NULL;
    }
    if (that.supplementary_Services_Information)
    {
      if (!supplementary_Services_Information)
        supplementary_Services_Information = new Supplementary_Services;
      *supplementary_Services_Information = *that.supplementary_Services_Information;
    }
    else
    {
      delete supplementary_Services_Information;
      supplementary_Services_Information = NULL;
    }
    if (that.services_Data_Information)
    {
      if (!services_Data_Information)
        services_Data_Information = new Services_Data_Information;
      *services_Data_Information = *that.services_Data_Information;
    }
    else
    {
      delete services_Data_Information;
      services_Data_Information = NULL;
    }
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined PartyInformation &PartyInformation::operator = (const PartyInformation &)" << std::endl;
  abort();
  // if your compiler complains here, check the -novolat option
#endif // SNACC_DEEP_COPY
}

AsnLen
PartyInformation::BEncContent (BUF_TYPE b)
{
  AsnLen totalLen = 0;
  AsnLen l;

  if (NOT_NULL (services_Data_Information))
  {
      BEncEocIfNec (b);
    l = services_Data_Information->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 4);
    totalLen += l;
  }

  if (NOT_NULL (supplementary_Services_Information))
  {
      BEncEocIfNec (b);
    l = supplementary_Services_Information->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 3);
    totalLen += l;
  }

  if (NOT_NULL (services_Information))
  {
      BEncEocIfNec (b);
    l = services_Information->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 2);
    totalLen += l;
  }

      BEncEocIfNec (b);
    l = partyIdentity->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 1);
    totalLen += l;

    l = party_Qualifier.BEncContent (b);
    BEncDefLenTo127 (b, l);
    l++;

    l += BEncTag1 (b, CNTX, PRIM, 0);
    totalLen += l;

  return totalLen;
} // PartyInformation::BEncContent


void PartyInformation::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  tag1 = BDecTag (b, seqBytesDecoded, env);

  if ((tag1 == MAKE_TAG_ID (CNTX, PRIM, 0)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    party_Qualifier.BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << std::endl;
    longjmp (env, -200);
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 1)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    partyIdentity = new PartyInformationSeq;
    partyIdentity->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    if (seqBytesDecoded == elmtLen0)
    {
      bytesDecoded += seqBytesDecoded;
      return;
    }
    else
    {
      tag1 = BDecTag (b, seqBytesDecoded, env);

      if ((elmtLen0 == INDEFINITE_LEN) && (tag1 == EOC_TAG_ID))
      {
        BDEC_2ND_EOC_OCTET (b, seqBytesDecoded, env)
        bytesDecoded += seqBytesDecoded;
        return;
      }
    }
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << std::endl;
    longjmp (env, -201);
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 2)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    services_Information = new Services_Information;
    services_Information->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    if (seqBytesDecoded == elmtLen0)
    {
      bytesDecoded += seqBytesDecoded;
      return;
    }
    else
    {
      tag1 = BDecTag (b, seqBytesDecoded, env);

      if ((elmtLen0 == INDEFINITE_LEN) && (tag1 == EOC_TAG_ID))
      {
        BDEC_2ND_EOC_OCTET (b, seqBytesDecoded, env)
        bytesDecoded += seqBytesDecoded;
        return;
      }
    }
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 3)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    supplementary_Services_Information = new Supplementary_Services;
    supplementary_Services_Information->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    if (seqBytesDecoded == elmtLen0)
    {
      bytesDecoded += seqBytesDecoded;
      return;
    }
    else
    {
      tag1 = BDecTag (b, seqBytesDecoded, env);

      if ((elmtLen0 == INDEFINITE_LEN) && (tag1 == EOC_TAG_ID))
      {
        BDEC_2ND_EOC_OCTET (b, seqBytesDecoded, env)
        bytesDecoded += seqBytesDecoded;
        return;
      }
    }
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 4)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    services_Data_Information = new Services_Data_Information;
    services_Data_Information->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
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
    longjmp (env, -202);
  }
  else
    return;
} // PartyInformation::BDecContent

AsnLen PartyInformation::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void PartyInformation::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    Asn1Error << "PartyInformation::BDec: ERROR - wrong tag" << std::endl;
    longjmp (env, -203);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int PartyInformation::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int PartyInformation::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
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

void PartyInformation::Print (std::ostream &os) const
{
  os << "{ -- SEQUENCE --" << std::endl;
  indentG += stdIndentG;

  {
    Indent (os, indentG);
    os << "party-Qualifier ";
    os << party_Qualifier;
    os << "," << std::endl;
  }

  if (NOT_NULL (partyIdentity))
  {
    Indent (os, indentG);
    os << "partyIdentity ";
    os << *partyIdentity;
  }
  else
  {
    Indent (os, indentG);
    os << "partyIdentity ";
    os << "-- void --";
    os << "," << std::endl;
  }

  if (NOT_NULL (services_Information))
  {
    os << ","<< std::endl;
    Indent (os, indentG);
    os << "services-Information ";
    os << *services_Information;
  }
  else
  {
    Indent (os, indentG);
    os << "services-Information ";
    os << "-- void --";
    os << "," << std::endl;
  }

  if (NOT_NULL (supplementary_Services_Information))
  {
    os << ","<< std::endl;
    Indent (os, indentG);
    os << "supplementary-Services-Information ";
    os << *supplementary_Services_Information;
  }
  else
  {
    Indent (os, indentG);
    os << "supplementary-Services-Information ";
    os << "-- void --";
    os << "," << std::endl;
  }

  if (NOT_NULL (services_Data_Information))
  {
    os << ","<< std::endl;
    Indent (os, indentG);
    os << "services-Data-Information ";
    os << *services_Data_Information;
  }
  else
  {
    Indent (os, indentG);
    os << "services-Data-Information ";
    os << "-- void --";
    os << std::endl;
  }

  os << std::endl;
  indentG -= stdIndentG;
  Indent (os, indentG);
  os << "}";
} // PartyInformation::Print

//---------------------------------------------------------------------------------------------------
//Begin of this was not generated by snacc

void PartyInformation::SetPartyQualifier(PartyInformationEnum partyQualifier)
{
    party_Qualifier = partyQualifier;
}
//Struct Party Identity
void PartyInformation::CreatePartyIdentityImei(const char* imei)
{
    partyIdentity->imei = new AsnOcts;
    partyIdentity->imei->Set(imei);
}
void PartyInformation::CreatePartyIdentityTei(const char* tei)
{
    partyIdentity->tei = new AsnOcts;
    partyIdentity->tei->Set(tei);
}
void PartyInformation::CreatePartyIdentityImsi(const char* imsi)
{
    partyIdentity->imsi = new AsnOcts;
    partyIdentity->imsi->Set(imsi);
}
//enum ChoiceIdEnum{iSUP_FormatCid, mAP_FormatCid, dSS1_FormatCid};
void PartyInformation::CreatePartyIdentityCallingPartyNumber(CallingPartyNumber::ChoiceIdEnum type, const char* str,int longitud)
{
    partyIdentity->callingPartyNumber = new CallingPartyNumber(type, str,longitud);
}
void PartyInformation::CreatePartyIdentityCalledPartyNumber(CalledPartyNumber::ChoiceIdEnum type, const char* str,int longitud)
{
    partyIdentity->calledPartyNumber= new CalledPartyNumber(type, str,longitud);
}
void PartyInformation::CreatePartyIdentityMsISDN(const char* msISDN)
{
    partyIdentity->msISDN = new AsnOcts;
    partyIdentity->msISDN->Set(msISDN);
}
void PartyInformation::CreatePartyIdentityE164_Format(const char* e164_Format)
{
    partyIdentity->e164_Format = new AsnOcts;
    partyIdentity->e164_Format->Set(e164_Format);
}
void PartyInformation::CreatePartyIdentitySip_uri(const char* sip_uri)
{
    partyIdentity->sip_uri = new AsnOcts;
    partyIdentity->sip_uri->Set(sip_uri);
}
void PartyInformation::CreatePartyIdentityTel_url(const char* tel_url)
{
    partyIdentity->tel_url = new AsnOcts;
    partyIdentity->tel_url->Set(tel_url);
}

//Struct Services Information
void PartyInformation::AddServicesInformationISUP_Parameters(const char *str)
{
    if( services_Information->iSUP_parameters == NULL )
        services_Information->iSUP_parameters = new ISUP_parameters;

    AsnOcts *parameter = services_Information->iSUP_parameters->Append();
    parameter->Set(str);
}
void PartyInformation::AddServicesInformationDSS1_Parameters_Codeset_0(const char *str)
{
    if( services_Information->dSS1_parameters_codeset_0 == NULL )
        services_Information->dSS1_parameters_codeset_0 = new DSS1_parameters_codeset_0;

    AsnOcts *parameter = services_Information->dSS1_parameters_codeset_0->Append();
    parameter->Set(str);
}
void PartyInformation::AddServicesInformationMAP_Parameters(const char *str)
{
    if( services_Information->mAP_parameters == NULL )
        services_Information->mAP_parameters = new MAP_parameters;

    AsnOcts *parameter = services_Information->mAP_parameters->Append();
    parameter->Set(str);
}

//Struct Supplementary Services
void PartyInformation::CreateSupplementaryServicesInformation()
{
    if( supplementary_Services_Information == NULL )
        supplementary_Services_Information = new Supplementary_Services;
}
    //Struct StandardSupplementaryServices of SupplementaryServices
void PartyInformation::CreateStandardSupplementaryServices()
{
    CreateSupplementaryServicesInformation();
    if( supplementary_Services_Information->standard_Supplementary_Services  == NULL )
        supplementary_Services_Information->standard_Supplementary_Services = new Standard_Supplementary_Services;
}
void PartyInformation::AddStandardSupplementaryServicesISUP_SS_parameters(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->iSUP_SS_parameters == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->iSUP_SS_parameters = new ISUP_SS_parameters;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->iSUP_SS_parameters->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesDSS1_SS_parameters_codeset_0(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_0 == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_0 = new DSS1_SS_parameters_codeset_0;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_0->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesDSS1_SS_parameters_codeset_4(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_4 == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_4 = new DSS1_SS_parameters_codeset_4;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_4->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesDSS1_SS_parameters_codeset_5(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_5 == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_5 = new DSS1_SS_parameters_codeset_5;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_5->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesDSS1_SS_parameters_codeset_6(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_6 == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_6 = new DSS1_SS_parameters_codeset_6;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_6->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesDSS1_SS_parameters_codeset_7(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_7 == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_7 = new DSS1_SS_parameters_codeset_7;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_parameters_codeset_7->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesDSS1_SS_Invoke_components(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_Invoke_components== NULL )
        supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_Invoke_components = new DSS1_SS_Invoke_Components;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->dSS1_SS_Invoke_components->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesMAP_SS_Parameters(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->mAP_SS_Parameters == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->mAP_SS_Parameters = new MAP_SS_Parameters;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->mAP_SS_Parameters->Append();
    parameter->Set(str);
}
void PartyInformation::AddStandardSupplementaryServicesMAP_SS_Invoke_Components(const char *str)
{
    CreateStandardSupplementaryServices();
    if( supplementary_Services_Information->standard_Supplementary_Services->mAP_SS_Invoke_Components == NULL )
        supplementary_Services_Information->standard_Supplementary_Services->mAP_SS_Invoke_Components = new MAP_SS_Invoke_Components;

    AsnOcts *parameter = supplementary_Services_Information->standard_Supplementary_Services->mAP_SS_Invoke_Components->Append();
    parameter->Set(str);
}

//Struct NonStandardSupplementaryServices of SupplementaryServices
void PartyInformation::CreateNonStandardSupplementaryServices()
{
    CreateSupplementaryServicesInformation();
    if ( supplementary_Services_Information->non_Standard_Supplementary_Services == NULL)
        supplementary_Services_Information->non_Standard_Supplementary_Services = new Non_Standard_Supplementary_Services;
}
void PartyInformation::AddNonStandardSupplementaryServicesSciData(const char *str)
{
    CreateNonStandardSupplementaryServices();
    supplementary_Services_Information->non_Standard_Supplementary_Services->Append(str);
}
void PartyInformation::AddNonStandardSupplementaryServicesSimpleIndication(SimpleIndication psimpleIndication)
{
    CreateNonStandardSupplementaryServices();
    supplementary_Services_Information->non_Standard_Supplementary_Services->Append(psimpleIndication);
}

void PartyInformation::AddOtherServices(const char *str)
{
    CreateSupplementaryServicesInformation();
    AsnOcts *other = supplementary_Services_Information->other_Services->Append();
    other->Set(str);
}

//Struct ServicesDataInformation
    //Struct GPRS_parameters of ServicesDataInformation
void PartyInformation::CreateServicesDataInformation()
{
    if( services_Data_Information == NULL )
        services_Data_Information = new Services_Data_Information;
}
void PartyInformation::CreateServicesDataInformationGPRS_Parameters()
{
    CreateServicesDataInformation();
    if( services_Data_Information->gPRS_parameters == NULL )
        services_Data_Information->gPRS_parameters = new GPRS_parameters;
}
void PartyInformation::CreateServicesDataInformationGPRS_Parameters_APN(const char *str)
{
    CreateServicesDataInformationGPRS_Parameters();
    delete services_Data_Information->gPRS_parameters->aPN;
    services_Data_Information->gPRS_parameters->aPN = new AsnOcts;
    services_Data_Information->gPRS_parameters->aPN->Set(str);
}
void PartyInformation::CreateServicesDataInformationGPRS_Parameters_PDP_Type(const char *str)
{
    CreateServicesDataInformationGPRS_Parameters();
    delete services_Data_Information->gPRS_parameters->pDP_type;
    services_Data_Information->gPRS_parameters->pDP_type = new AsnOcts;
    services_Data_Information->gPRS_parameters->pDP_type->Set(str);
}
void PartyInformation::CreateServicesDataInformationGPRS_Parameters_PDP_Address_Allocated_To_The_Target(const char *px25Address)
{
    CreateServicesDataInformationGPRS_Parameters();
    delete services_Data_Information->gPRS_parameters->pDP_address_allocated_to_the_target;
    services_Data_Information->gPRS_parameters->pDP_address_allocated_to_the_target = new DataNodeAddress(px25Address);
}
void PartyInformation::CreateServicesDataInformationGPRS_Parameters_PDP_Address_Allocated_To_The_Target(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress )
{
    CreateServicesDataInformationGPRS_Parameters();
    delete services_Data_Information->gPRS_parameters->pDP_address_allocated_to_the_target;
    services_Data_Information->gPRS_parameters->pDP_address_allocated_to_the_target = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress);
}
void PartyInformation::CreateServicesDataInformationGPRS_Parameters_PDP_Address_Allocated_To_The_Target(IPAddressEnum ip_type,IP_value::ChoiceIdEnum choiceIpTypeValue, const char *pipAddress, IPAddressEnum1 choiceIpAssignment )
{
    CreateServicesDataInformationGPRS_Parameters();
    delete services_Data_Information->gPRS_parameters->pDP_address_allocated_to_the_target;
    services_Data_Information->gPRS_parameters->pDP_address_allocated_to_the_target = new DataNodeAddress(ip_type, choiceIpTypeValue, pipAddress, choiceIpAssignment);
}
//void CreateServicesDataInformationGPRS_Parameters();

//End of this was not generated by snacc
//---------------------------------------------------------------------------------------------------

