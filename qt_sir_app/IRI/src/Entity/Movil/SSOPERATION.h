#ifndef SSOPERATION_CPP_
#define SSOPERATION_CPP_


#include "../structs.h"

/* EventType it is invalid and should be filled with 0Xff frame structure */ 


class  SSOPERATION                  //0x40
{
	public:
	#define SSOPERATION_MSISDN_VALID          (0x01)
	#define SSOPERATION_IMSI_VALID            (0x02)
	#define SSOPERATION_IMEI_VALID            (0x04)
	#define SSOPERATION_FORWARDNUM_VALID      (0x08)

    unsigned char  nMask[2]; //It denotes the mask
    //It denotes the type of the intercepted number
     STAKEOUTNUMTYPE NumType;
	 //It denotes the MSISDN, which is a conditional field and indicated by nMask
     NUMBER                    MSISDN;
     //It denotes the IMSI, which is a conditional field and indicated by nMask
     NUMBER                    IMSI;
     //It denotes the IMEI, which is a conditional field and indicated by nMask
     NUMBER                    IMEI;
     Time                      time;           //It denotes the time
     LOCATION                  Location;       //It denotes the latest location
     OPERATETYPE               OperateType;    //It denotes the type of operation
     SERVICETYPE               ServiceType;    //It denotes the type of service
     //It denotes the call forward number, which is a conditional field and will be valid when
     //configuring call forward Indicated by nMask
     NUMBER ForwardNumber;
	 //It denotes the success flag of SS operation
     SUCCESSFLAG               SuccessFlag;
	 LiiD liid; 	//It denotes the X2Id
};

#endif /*SSOPERATION_CPP_*/
