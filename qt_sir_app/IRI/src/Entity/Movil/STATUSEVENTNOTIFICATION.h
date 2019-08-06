#ifndef STATUSEVENTNOTIFICATION_CPP_
#define STATUSEVENTNOTIFICATION_CPP_

#include "../structs.h"

/*
      Event type      		Value
      Switch on machine       1
      Switch off machine      2
      Update location         3
*/

class  STATUSEVENTNOTIFICATION      //0x10
{
	public:
	
	#define STATUSEVENTNOTIFICATIION_MSISDN_VALID  		(0x01)
	#define STATUSEVENTNOTIFICATIION_IMSI_VALID    		(0x02)
	#define STATUSEVENTNOTIFICATIION_IMEI_VALID    		(0x04)
	#define STATUSEVENTNOTIFICATIION_ORGLOCATION_VALID  (0x08)
	
    unsigned char  nMask[2]; //It denotes the mask
    //It denotes thSTATUSEVENTNOTIFICATIONe type of the intercepted number
    STAKEOUTNUMTYPE NumType;
	
	//It denotes the MSISDN, which is a conditional field and indicated by nMask
    NUMBER                   MSISDN;
	//It denotes the IMSI, which is a conditional field and indicated by nMask
    NUMBER                   IMSI;
	//It denotes the IMEI, which is a conditional field and indicated by nMask
    NUMBER                   IMEI;
	//It denotes the time when the machine is switched on.
    Time                     time;
	//It denotes the original location and is only valid when EvenType=3 (location update)
    LOCATION                 OrgLocation;
	//It denotes the current location. During the events of switching on/off MS, it denotes
	//the location area cell of system when switching on/off MS, and it denotes the
	//objective location area cell when updating location.
    LOCATION                 CurLocation;
    LiiD liid; 	//It denotes the X2Id
             
};

#endif /*STATUSEVENTNOTIFICATION_CPP_*/
