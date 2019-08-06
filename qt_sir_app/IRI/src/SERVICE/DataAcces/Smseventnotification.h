#ifndef SMSEVENTNOTIFICATION_H
#define SMSEVENTNOTIFICATION_H


#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>

#include "../../BUSINESS_LOGIC/Entity/structs.h"
#include "../../BUSINESS_LOGIC/Entity/Movil/SMSEVENTNOTIFICATION.h"


class QSqlQuery;

class Smseventnotification
	{
	public:
							Smseventnotification(QObject *parent = 0,const char *name = 0);	Smseventnotification(SMSEVENTNOTIFICATION &old);
							~Smseventnotification();

	public:
		QString					getNmask();
		QString					getNumtype();
		QString					getNumber();
		QString					getTime();
		QString					getSmcnumber();
		QString					getPeerpartynum();
		QString					getSmsmessage();
		QString					getEventid();
		QString					getLiid();
		QString					getEventtype();
		QString					getId();

	public:
		void					setNmask(QString s);
		void					setNumtype(QString s);
		void					setNumber(QString s);
		void					setTime(QString s);
		void					setSmcnumber(QString s);
		void					setPeerpartynum(QString s);
		void					setSmsmessage(QString s);
		void					setEventid(QString s);
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
		void					operator=(const Smseventnotification &old);

	protected:
		QString					m_stNmask;
		QString					m_stNumtype;
		QString					m_stNumber;
		QString					m_stTime;
		QString					m_stSmcnumber;
		QString					m_stPeerpartynum;
		QString					m_stSmsmessage;
		QString					m_stEventid;
		QString					m_stLiid;
		QString					m_stEventtype;
		QString					m_stId;
	};
#endif //SMSEVENTNOTIFICATION_H

