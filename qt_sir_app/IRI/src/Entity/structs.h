//---------------------------------------------------------------------------
/**
 * @package    SIR
 * @subpackage util
 * @author     ing. Antonio Membrides Espinosa
 * @date       21/02/2021
 * @version    1.0
 */
//---------------------------------------------------------------------------
#ifndef CONTROLEREVENT_H_
#define CONTROLEREVENT_H_

 #include <QString>
 #include <bitset>
 #include <iostream>
 
using namespace std;

//#include"Function.h"




/*
 *
 */


//Structura ObjectNumber 

struct ObjectNumber
{
	unsigned char  Length[2];
	unsigned char  Dato[32];
};


inline void convertToBDObjectNumber(ObjectNumber structs,QString &Data)
{
	 unsigned char LengthObjectNumber[2];
	 short* pshort = NULL;      
	 	
	 	LengthObjectNumber[0]  = structs.Length[0];
	 	LengthObjectNumber[1]  = structs.Length[1]; 
	  	pshort = (short*)LengthObjectNumber;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
	 
};
//Structura para Time

struct Time
{
	 unsigned char   nYear[2];
	 unsigned char   nMonth;
	 unsigned char   nDay;
	 unsigned char   nHour;
	 unsigned char   nMin;
	 unsigned char   nSec;
};

inline short  convertLengthShort(unsigned char array[2])
{
	 unsigned char stringConvert[2];
	 stringConvert[0]  = array[0];
	 stringConvert[1]  = array[1];
			  
     short * shortConvert = NULL;
	 shortConvert = (short*)stringConvert; 

 return *shortConvert; 
};	

inline void convertToBDTime(Time structs,QString &timeData)
{

 	QString year;
 	year.setNum( convertLengthShort(structs.nYear) );
	 
	QString month;
    month.setNum((int)structs.nMonth);
          
	QString day;
    day.setNum((int)structs.nDay);
     
    QString hour;
    hour.setNum((int)structs.nHour);
     
    QString min;
    min.setNum((int)structs.nMin);
     
    QString sec;
    sec.setNum((int)structs.nSec);
      	
	timeData.append(year+":");
	timeData.append(month+":");
	timeData.append(day+" ");
	timeData.append(hour+":");
	timeData.append(min+":");
	timeData.append(sec);
};

//Structura ElementID

struct ElementID
{
	 unsigned char  Length[2];
	 unsigned char  Dato[15];
};

inline void convertToBDElementID(ElementID structs,QString &Data)
{
	 unsigned char LengthElementID[2];
	 short* pshort = NULL;      
	 	
	 	LengthElementID[0]  = structs.Length[0];
	 	LengthElementID[1]  = structs.Length[1]; 
	  	pshort = (short*)LengthElementID;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
	 
};

//Structura Cin

struct Cin
{
	 unsigned char  Length[2];
	 unsigned char  Dato[4];
};


inline void convertToBDCin(Cin structs,QString &Data)
{
	 unsigned char LengthCin[2];
	 short* pshort = NULL;      
	 	
	 	LengthCin[0]  = structs.Length[0];
	 	LengthCin[1]  = structs.Length[1]; 
	  	pshort = (short*)LengthCin;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
	 
};
//Structura para OperatorID
struct OperatorID
{
	 unsigned char  Length[2];
	 unsigned char  Dato[3];
};

inline void convertToBDOperatorID(OperatorID structs,QString &Data)
{
	 unsigned char LengthOperatorID[2];
	 short* pshort = NULL;      
	 	
	 	LengthOperatorID[0]  = structs.Length[0];
	 	LengthOperatorID[1]  = structs.Length[1]; 
	  	pshort = (short*)LengthOperatorID;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
	 
};

//Structura para LiiD
struct LiiD
{
	 unsigned char  Length[2];
	 unsigned char  Dato[20];
};


inline void convertToBDLiiD(LiiD structs,QString &Data)
{
	short pshort = convertLengthShort(structs.Length);	
	  
	 	for( int i = 0 ; i < pshort ; i++ )
	 		Data.append(structs.Dato[i]);
 
};


inline void convertToBDLEA(LiiD structs,QString &Data)
{
	 unsigned char Length[2];
	 short* pshort = NULL;      
	 	
	 	Length[0]  = structs.Length[0];
	 	Length[1]  = structs.Length[1]; 
	  	pshort = (short*)Length;
	  
	 	for( int i = 0 ; i < 4 ; i++ )
	 		Data.append(structs.Dato[i]);
 
};


//Structura para  CCLiD
struct CCLiD
{
	 unsigned char  Length[2];
	 unsigned char  Dato[4];
};

inline void convertToBDCCLiD(CCLiD structs,QString &Data)
{
     unsigned char Length[2];
     short* pshort = NULL;

    Length[0]  = structs.Length[0];
    Length[1]  = structs.Length[1];
    pshort = (short*)Length;

    for( int i = 0 ; i <*pshort ;i++ )
            Data.append(structs.Dato[i]);
	 
};

//Structura para  GatewayId
struct GatewayId
{
 unsigned char  Length[2];
 unsigned char  Dato[15];
};

inline void convertToBDGatewayId(GatewayId structs,QString &Data)
{
     unsigned char Length[2];
     short* pshort = NULL;

    Length[0]  = structs.Length[0];
    Length[1]  = structs.Length[1];
    pshort = (short*)Length;

    for( int i = 0 ; i <*pshort ;i++ )
            Data.append(structs.Dato[i]);
	 
};

//Implementacion NGN
//Esto es lo que me cambia CabeceraX2NGN
 struct CabeceraX2Fija
{
   //unsigned char preamble;       	/* m_buffer->m_nPreamble == 0xaa (sincronizar)*/
    unsigned char identificador;  	/*  m_buffer->m_nCmdCode ==  0x20 */
    unsigned char eventType; 		/* m_buffer->m_eventType == 0x01 // esto es para analisis semantico*/
    unsigned char dwReportID[4];
    unsigned char NEID[42];
    unsigned char LEAID[2];
    unsigned char wLength[2];		/* Longitud del mensaje, en bytes */
};


//Especificacion de la Movil

//Structura NEID 
struct NEID
{
    unsigned char  Length[2];
    unsigned char  Dato[20];
};


inline void convertToBDNEID(NEID structs,QString &Data)
{
    unsigned char Length[2];
    short* pshort = NULL;

    Length[0]  = structs.Length[0];
    Length[1]  = structs.Length[1];
    pshort = (short*)Length;

    for( int i = 0 ; i <*pshort ;i++ )
            Data.append(structs.Dato[i]);
	 
};

 
//Implementacion NGN
//Esto es lo que me cambia
typedef struct CabeceraX2Movil
{
	//unsigned char   preamble;       	/* m_buffer->m_nPreamble == 0xaa (sincronizar)*/ 
    unsigned char  identificador;  	/*  m_buffer->m_nCmdCode ==  0x20 */
    unsigned char  eventType; 		/* m_buffer->m_eventType == 0x01 // esto es para analisis semantico*/
    unsigned char  dwReportID[4];
    NEID  neid; //Que Ip me lo envio
    //unsigned char  LEAID[2]; //A que IP FTP debo enviarlo
    unsigned char  wLength[2];		/* Longitud del mensaje, en bytes */
    
    
} CabeceraX2Movil;

 
 
//Estructuras Location 
 
struct MSCID
{
	unsigned char  Length[2];
	unsigned char  Dato[20];
};


struct LAI
{
	unsigned char  Length[2];
	unsigned char  Dato[7];
};



struct CGI
{
	unsigned char  Length[2];
	unsigned char  Dato[7];
};

 
//Structura General 
struct LOCATION
{
   MSCID        MscID;
   LAI          lai;
   CGI          cgi;
};


inline void convertToBDMSCID(MSCID structs,QString &Data)
{
	 unsigned char Length[2];
	 short* pshort = NULL;      
	 	
	 	Length[0]  = structs.Length[0];
	 	Length[1]  = structs.Length[1]; 
	  	pshort = (short*)Length;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
	 
};

inline void convertToBDLAI(LAI structs,QString &Data)
{
	 unsigned char Length[2];
	 short* pshort = NULL;      
	 	
	 	Length[0]  = structs.Length[0];
	 	Length[1]  = structs.Length[1]; 
	  	pshort = (short*)Length;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
	 
};

inline void convertToBDCGI(CGI structs,QString &Data)
{
	 unsigned char Length[2];
	 short* pshort = NULL;      
	 	
	 	Length[0]  = structs.Length[0];
	 	Length[1]  = structs.Length[1]; 
	  	pshort = (short*)Length;
	  
	 	for( int i = 0 ; i < *pshort ;i++ )
	 		Data.append(structs.Dato[i]);
};



inline void convertToBDLOCATION(LOCATION structs,QString &Data)
{
	
	 convertToBDMSCID(structs.MscID,Data);
	/* convertToBDLAI(structs.lai,Data);
	 convertToBDCGI(structs.cgi,Data);*/
	
};

//Structura Number
struct NUMBER
{
	unsigned char  Length[2];
	unsigned char  Dato[15];
};

//El numero viene en BCD inverso.
inline void convertToBDNUMBER(NUMBER structs,QString &Data)
{
	
	short pshort = convertLengthShort(structs.Length);	        	
	 	
	 QString element;
	 
 	  char * cad = new char[pshort];
 	  char aux1;
	  char aux2;
	  
	  //
	 string s1 = "00000000";
	  bitset<8> bs1(s1);
	  
	  
 	 /*bs1.set(7,1);	
 	 unsigned char c(char(bs1.to_ulong()));
 	 element.setNum(c);
	 Data.append( c );*/
	 
	 for( int i = 0 ; i < pshort ; i++ )
	 {
	 	
	   aux1 = structs.Dato[i] >> 4;
	   aux2 = structs.Dato[i] << 4;
	 
	   sprintf(cad, "%x", (aux1 | aux2));
	  //sprintf(cad, "%x", (structs.Dato[i]));
	   
	   
	  // element.setNum(cad);  // 	
	   Data.append(cad);   // Es insertar en formato hexadecimal.
	
	 }
	 delete cad;
	  
};


//Structura FAILUREREASON
struct FAILUREREASON
{
	unsigned char  Length[2];
	unsigned char  Dato[80];
};

inline void convertToBDFAILUREREASON(FAILUREREASON structs,QString &Data)
{
	 unsigned char Length[2];
	 short* pshort = NULL;      
	 	
	 	Length[0]  = structs.Length[0];
	 	Length[1]  = structs.Length[1]; 
	  	pshort = (short*)Length;
	  
	 	for( int i = 0 ; i <*pshort ;i++ )
	 		Data.append(structs.Dato[i]);
};

//Success flag
typedef unsigned char SUCCESSFLAG;
#define SUCCESSFLAG_SUCCESS  1 // It denotes success.
#define SUCCESSFLAG_FAILUERE 0 // It denotes failure.


//The type of the intercepted number
typedef unsigned char STAKEOUTNUMTYPE;
#define STAKEOUTNUMTYPE_MSISDN          1 //It denotes the MSISDN
#define STAKEOUTNUMTYPE_IMSI            2 //It denotes the IMSI
#define STAKEOUTNUMTYPE_IMEI            4 //It denotes the IMEI
#define STAKEOUTNUMTYPE_ISDN            8 //It denotes the ISDN

//Operation type
typedef unsigned char OPERATETYPE;
#define OPERATETYPE_ACTIVE    0 //It denotes activation.
#define OPERATETYPE_DEACTIVE  1 //It denotes deactivation.
#define OPERATETYPE_PROVISION 2 //It denotes provision.
#define OPERATETYPE_RELEASE   3 //It denotes release.

//The calling/called flag of the intercepted user
typedef unsigned char CALLORCALLEDFLAG;
#define CALLORCALLEDFLAG_CALLER 0 /*It denotes that the intercepted user is the caller.*/
#define CALLORCALLEDFLAG_CALLED 1 /*It denotes that the  intercepted user is  the called.*/

//Local registered flag of the intercepted user
typedef unsigned char LOCALREGISTFLAG;
 //It denotes that the intercepted user is locally registered
#define LOCALREGISTFLAG_LOCALREGISTED               0 
 //It denotes that the intercepted user is not locally registered
#define LOCALREGISTFLAG_NOTLOCALREGISTED            1

//Split or combine flag of the receiving and sending
typedef unsigned char COMBINEORSPLITFLAG;
 //It denotes that the receiving and sending are combined
#define COMBINEORSPLITFLAG_COMBINE                     0
 //It denotes that the receiving and sending are split A
#define COMBINEORSPLITFLAG_SPLIT                       1

 //Type of requested service
typedef unsigned char SERVICETYPE;
#define SERVICETYPE_SPEECH     0 //It denotes the SPEECH
#define SERVICETYPE_FAX        1 //It denotes the FAX
#define SERVICETYPE_31K        2 //It denotes the 3.1KHz
#define SERVICETYPE_UDI        3 //It denotes the UDI

//  Sub code of service type
typedef unsigned char SUBSERVICETYPE;
//  SM
//  Service code
struct SERVICECODE
{
	unsigned char  Length[2];
	unsigned char  Dato[5];	
};

inline void convertToBDSERVICECODE(SERVICECODE structs,QString &Data)
{
	 unsigned char LengthSSCode[2];
	 short* pshort = NULL;      
	 	
	 	LengthSSCode[0]  = structs.Length[0];
	 	LengthSSCode[1]  = structs.Length[1]; 
	  	pshort = (short*)LengthSSCode;
	  
	 	for(int i = 0 ; i <*pshort ;i++  )
	 		Data.append(structs.Dato[i]);
	  
};




//  Operating code of SS
typedef unsigned char ADDEDSERVICECODE;        //It denotes the operating code of the SS

//Bit flag of CALLID1
#define X2_CALLID1_VALID                    (0x4000)


// Bit flag of CALLID2
#define X2_CALLID2_VALID                    (0x8000)
//BCD  CALLID y EventID SubEventID


/*
  BCD
  CALLID
  EventID
  SubEventID
  Number
  NEID
  
 */
 
 #include <qstring.h>

struct SMSMESSAGE	
{
	unsigned char  Length[2];
	unsigned char  Dato[164];	

};


inline void convertToBD(char var,QString &Data)
{
	QString numType;
	numType.setNum((int)var); 
	Data.append(numType);
};

inline void convertToBDSMSSMSMESSAGE(SMSMESSAGE structs,QString &Data)
{
	 short pshort = convertLengthShort(structs.Length);	  
	
	 for(int i = 0 ; i <pshort ;i++  )
	 		Data.append((char)structs.Dato[i]);
	 
	 
	 
};

inline char * converttoint(char caracter)
{
    
    
	
	char * cadint = new char[2];
	int  monthint = (int)caracter;

	sprintf( cadint , "%d", (monthint));
	if(monthint < 10)
	{
		char aux  = cadint[0];
		cadint[0]= 0x30;
                cadint[1]= aux;
	}
	char * ret = new char[2];
	ret[0]=cadint[0];
	ret[1]=cadint[1];
	delete cadint;
return ret;

};


inline char * convertToUTCTime(Time structs)
{
	  
	 
	 // "YYMMDD000000Z"
	 char * all =NULL;
	 all = new char[12];
	 
	
	char * cad = new char[4];    
	
	sprintf(cad , "%d", (convertLengthShort(structs.nYear))); 
	
	cout<< "cadyear" << cad << endl;
	all[0] = cad[2];
	all[1] = cad[3];
	
	all[2] = converttoint(structs.nMonth )[0];
	all[3] = converttoint(structs.nMonth )[1];
	
	
	all[4] = converttoint(structs.nDay )[0];
	all[5] = converttoint(structs.nDay )[1];
	
	all[6] = converttoint(structs.nHour )[0];
	all[7] = converttoint(structs.nHour )[1];
	
   
        all[8] = converttoint(structs.nMin )[0];
	all[9] = converttoint(structs.nMin )[1];
	
        all[10] = converttoint(structs.nSec )[0];
	all[11] = converttoint(structs.nSec )[1];
    
   
   cout<< "cadena all" ;
    for(int i = 0 ; i < 12 ; i++)
    cout<<  all[i];
    
    delete cad;

    
   	
	return all;
	
	 
	 
	 
};


    


#endif /*CONTROLEREVENT_H_*/
