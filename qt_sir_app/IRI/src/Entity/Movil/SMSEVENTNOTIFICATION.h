#ifndef SMSEVENTNOTIFICATION_CPP_
#define SMSEVENTNOTIFICATION_CPP_

#include "../structs.h"

/*          Event type       Value
            SM sending         1
	        SM receiving       2
*/



class  SMSEVENTNOTIFICATION         //0x20
{
	public:
	#define SMSEVENTNOTIFICATION_MSISDN_VALID                     (0x01)
	#define SMSEVENTNOTIFICATION_IMSI_VALID                       (0x02)
	#define SMSEVENTNOTIFICATION_IMEI_VALID                       (0x04)
	
    unsigned char               nMask[2];       //It denotes the mask
    STAKEOUTNUMTYPE NumType;        //It denotes the type of the intercepted number
    NUMBER             MSISDN;      //It denotes the MSISDN, which is a conditional field and indicated by nMask
    NUMBER             IMSI;        //It denotes the IMSI, which is a conditional field and indicated by nMask
    NUMBER             IMEI;        //It denotes the IMEI, which is a conditional field and indicated by nMask
   
    Time               time;        //It denotes the time LOCATION           Location;    //It denotes the latest location
	
	NUMBER                 SMCNumber;     //It denotes the number of SM call center
	//It denotes the peer party number of communication; it is the called number when
	//sending SMS and is the number of calling party when receiving SMS.
    LOCATION Location; //It denotes the latest location
    NUMBER                 PeerPartyNum;
    SMSMESSAGE             SMSMessage; //It denotes the content of SMS
	unsigned char           EventID[4];       //It denotes the EventID
	LiiD liid; 	//It denotes the X2Id
	   		
};

#endif /*SMSEVENTNOTIFICATION_CPP_*/
