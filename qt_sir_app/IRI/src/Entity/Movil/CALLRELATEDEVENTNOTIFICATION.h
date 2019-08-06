#ifndef CALLRELATEDEVENTNOTIFICATION_CPP_
#define CALLRELATEDEVENTNOTIFICATION_CPP_

#include "../structs.h"

/*
    Event Type         Value
    Call initiating      1
    Call alerting        2
    Call response        3
    Call termination     4
*/


 //Análisis de el comando(0x30) y del Tipo de Evento.
 
class  CALLRELATEDEVENTNOTIFICATION //0x30
{ 
	public:
	//Tipo de número.
	#define CALLRELATEDEVENTNOTIFICATION_MSISDN_VALID            (0x01)
	#define CALLRELATEDEVENTNOTIFICATION_IMSI_VALID              (0x02)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_IMEI_VALID         (0x04)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_ISDN_VALID         (0x08)
	
	#define CALLRELATEDEVENTNOTIFICATION_LOCATION_VALID          (0x10)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_LOCALREGISTFLAG_VALID        (0x20)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_CALLNUM_VALID                (0x40)

	#define CALLRELATEDEVENTNOTIFICATION_ORGCALLEDNUM_VALID            (0x80)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_SERVICETYPE_VALID        (0x0100)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_SERVICECODE_VALID        (0x0200)
	
	#define CALLRELATEDEVENTNOTIFICATIONSTART_COMBINEORSPLITFLAG_VALID (0x0400)
	
	#define CALLRELATEDEVENTNOTIFICATIONSTART_SUCCESSFLAG_VALID        (0x0800)
	#define CALLRELATEDEVENTNOTIFICATIONSTART_FAILUREREASON_VALID      (0x1000)
	
	
    unsigned char                     nMask[2];        //It denotes the mask
    STAKEOUTNUMTYPE 		 NumType;         //It denotes the type of the intercepted number
    NUMBER                   MSISDN;          //It denotes the MSISDN, which is a  conditional field and indicated by nMask
    NUMBER                   IMSI;            //It denotes the IMSI, which is a    conditional field and indicated by nMask
    NUMBER                   IMEI;            //It denotes the IMEI, which is a   conditional field and indicated by nMask
    NUMBER                   ISDN;            //It denotes the ISDN, which is a   conditional field and indicated by nMask
    
    Time                     time;            //It denotes the time
    	
	//It denotes the latest location, which is a conditional field and is valid when it can be
	//acquired.Indicated by nMask
    LOCATION                 Location;

	//It denotes the caller or called flag of the intercepted user
    CALLORCALLEDFLAG CallOrCalledFlag;
	//It denotes the local registered flag of the intercepted user
    LOCALREGISTFLAG           IsLocalRegisted;
	//It denotes the call number, which is a conditional field and is valid when it can be
	//acquired. Indicated by nMask
    NUMBER           CallNumber;
    NUMBER           CalledNumber;              //It denotes the called number
	//It denotes the original called number, which is a conditional field and is valid during
	//the call forwarding Indicated by nMask

    NUMBER                    OrgCalledNumber;
    SERVICETYPE               ServiceType;   //It denotes the type of requested service
    SERVICECODE               SSCode;        //It denotes the service code
	//It denotes the CallID1, whish is an optional field and indicated by nMask
    unsigned char    CallID1[2];		
	//It denotes the CallID2, which is a conditional field with and is valid when the
	//receiving and sending is split.Indicated by nMask
    unsigned char            CallID2[2];
     
    unsigned char            EventID[4];                //It denotes the EventID
    unsigned char            SubEventID[2];             //It denotes the SubEventID
	//It denotes the combine/split flag of receiving and sending, and is only valid during
	//the starting time of the call.
    COMBINEORSPLITFLAG CombineOrSplitFlag;
	//It denotes the success flag, and the”1”denotes that the call is terminated normally,
	//and the “0” denotes that the call is not terminated normally. It is only valid in the
	//event of call terminating to indicate whether it is a normal termination or an abnormal
	//termination.
    SUCCESSFLAG              SuccessFlag;
	//It denotes the failure reason, which is a conditional field and is valid when failure, it
	//is indicated by nMask.
     FAILUREREASON            FailureReasson;
	 LiiD liid; 			  //It denotes the X2Id    para el evio del FTP
};


#endif /*CALLRELATEDEVENTNOTIFICATION_CPP_*/
