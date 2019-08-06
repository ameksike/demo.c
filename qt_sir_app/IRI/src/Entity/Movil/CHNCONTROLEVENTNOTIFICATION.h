#ifndef CHNCONTROLEVENTNOTIFICATION_CPP_
#define CHNCONTROLEVENTNOTIFICATION_CPP_

#include "../structs.h"
/*          Event Type       Value
          Channel establishing    1
          Channel closeing        2
*/


class  CHNCONTROLEVENTNOTIFICATION   //0x50
{
	public:
	 #define CHNCONTROLEVENTNOTIFICATION_MSISDN_VALID    (0x01)
	 #define CHNCONTROLEVENTNOTIFICATION_IMSI_VALID      (0x02)
	 #define CHNCONTROLEVENTNOTIFICATION_IMEI_VALID      (0x04)
	 #define CHNCONTROLEVENTNOTIFICATION_ISDN_VALID      (0x08)
	 
	 #define CHNCONTROLEVENTNOTIFICATION_CALLORCALLEDFLAG_VALID                    (0x10)
	 #define CHNCONTROLEVENTNOTIFICATIONOPEN_SUCCESSFLAG_VALID                     (0x20)
	 #define CHNCONTROLEVENTNOTIFICATION_ERRCODE_VALID                             (0x40)
     
     unsigned char             nMask[2];       //It denotes the mask
     STAKEOUTNUMTYPE  NumType;      //It denotes the type of the intercepted number
     NUMBER           MSISDN;            //It denotes the MSISDN, which is aconditional field and indicated by nMask
     NUMBER                     IMSI;              //It denotes the IMSI, which is a conditional field and indicated by nMask
     NUMBER                     IMEI;              //It denotes the IMEI, which is a conditional field and indicated by nMask
	//It denotes the ISDN, which is a conditional field and indicated by nMask
     NUMBER                     ISDN;
     Time                       time;              //It denotes the time
	//It denotes the start time of the related call
     Time             RelatedCallStartTime;
	//It denotes the combine/split flag of receiving and sending.
     COMBINEORSPLITFLAG                   CombineOrSplitFlag;
	//It denotes the caller/called flag of the intercepted user, which is a conditional field. It
	//is valid during the split of receiving and sending and is indicated by nMask
     CALLORCALLEDFLAG CallOrCalledFlag;
     NUMBER           LEAAccessNum;  //It denotes the access number of LEA
	//It denotes the CallID1, which is an optional field and indicated by nMask
     unsigned char CallID1[2];
     unsigned char EventID[4];             //It denotes the EventID
     unsigned char             SubEventID[2];                  //It denotes the SubEventID
	//It denotes the success flag, which is valid when reporting the establishing of channel
     SUCCESSFLAG             SuccessFlag;
	//It denotes the failure reason, which is a conditional field. It is valid when reporting
	//the event of channel established to report the failure reason of the channel
	//establishing.
     FAILUREREASON           FailureReasson;
	 LiiD liid; 	//It denotes the X2Id
};

#endif /*CHNCONTROLEVENTNOTIFICATION_CPP_*/
