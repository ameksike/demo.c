#ifndef CALLRELATEDEVENTNOTIFICATION_H
#define CALLRELATEDEVENTNOTIFICATION_H

#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>

#include "../../BUSINESS_LOGIC/Entity/structs.h"
#include "../../BUSINESS_LOGIC/Entity/Movil/CALLRELATEDEVENTNOTIFICATION.h"


class QSqlQuery;

class Callrelatedeventnotification 
	{
	public:
							Callrelatedeventnotification(QObject *parent = 0,const char *name = 0);
							Callrelatedeventnotification(CALLRELATEDEVENTNOTIFICATION &old);
							~Callrelatedeventnotification();

	public:
		QString					getNmask();
		QString					getNumtype();
		QString					getNumber();
		QString					getTime();
		QString					getLocation();
		QString					getCallorcalledflag();
		QString					getIslocalregisted();
		QString					getCallnumber();
		QString					getCallednumber();
		QString					getOrgcallednumber();
		QString					getServicetype();
		QString					getSscode();
		QString					getCallid1();
		QString					getCallid2();
		QString					getEventid();
		QString					getSubeventid();
		QString					getCombineorsplitflag();
		QString					getSuccessfag();
		QString					getFailurereasson();
		QString					getLiid();
		QString					getEventtype();
		QString					getId();

	public:
		void					setNmask(QString s);
		void					setNumtype(QString s);
		void					setNumber(QString s);
		void					setTime(QString s);
		void					setLocation(QString s);
		void					setCallorcalledflag(QString s);
		void					setIslocalregisted(QString s);
		void					setCallnumber(QString s);
		void					setCallednumber(QString s);
		void					setOrgcallednumber(QString s);
		void					setServicetype(QString s);
		void					setSscode(QString s);
		void					setCallid1(QString s);
		void					setCallid2(QString s);
		void					setEventid(QString s);
		void					setSubeventid(QString s);
		void					setCombineorsplitflag(QString s);
		void					setSuccessfag(QString s);
		void					setFailurereasson(QString s);
		void					setLiid(QString s);
		void					setEventtype(QString s);
		void					setId(QString s);

	public:
		QString					generateDeleteStatement();
		QString					generateInsertStatement();
		QString					generateInsertStatementNoSequence();
		void					readRecord(QSqlQuery query);
		QString					generateSelectStatement();
		QString					generateUpdateStatement();
		QStringList					generateFieldList();
		QString					escapeString(QString stText,QChar cEscapeChar);

	public:
		void					operator=(const Callrelatedeventnotification &old);
		short  				    convertLength(char array0,char array1)
		{
			     
			 char stringConvert[2];
	 		 stringConvert[0]  = array0;
			 stringConvert[1]  = array1;
			  
    		 short * shortConvert = NULL;
			 shortConvert = (short*)stringConvert; 
			 return *shortConvert; 
		}	

	protected:
		QString					m_stNmask;
		QString					m_stNumtype;
		QString					m_stNumber;
		QString					m_stTime;
		QString					m_stLocation;
		QString					m_stCallorcalledflag;
		QString					m_stIslocalregisted;
		QString					m_stCallnumber;
		QString					m_stCallednumber;
		QString					m_stOrgcallednumber;
		QString					m_stServicetype;
		QString					m_stSscode;
		QString					m_stCallid1;
		QString					m_stCallid2;
		QString					m_stEventid;
		QString					m_stSubeventid;
		QString					m_stCombineorsplitflag;
		QString					m_stSuccessfag;
		QString					m_stFailurereasson;
		QString					m_stLiid;
		QString					m_stEventtype;
		QString					m_stId;
	};
#endif //CALLRELATEDEVENTNOTIFICATION_H

