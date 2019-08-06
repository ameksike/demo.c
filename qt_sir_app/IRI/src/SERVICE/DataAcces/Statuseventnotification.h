#ifndef STATUSEVENTNOTIFICATION_H
#define STATUSEVENTNOTIFICATION_H


#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>

#include "src/Entity/structs.h"
#include "../../BUSINESS_LOGIC/Entity/Movil/STATUSEVENTNOTIFICATION.h"


class QSqlQuery;

class Statuseventnotification 
	{
	public:
							Statuseventnotification(QObject *parent = 0,const char *name = 0);
							Statuseventnotification(STATUSEVENTNOTIFICATION &old);
							~Statuseventnotification();

	public:
		QString					getNmask();
		QString					getNumtype();
		QString					getNumber();
		QString					getTime();
		QString					getOrglocation();
		QString					getCurlocation();
		QString					getLiid();
		QString					getEventtype();
		QString					getId();

	public:
		void					setNmask(QString s);
		void					setNumtype(QString s);
		void					setNumber(QString s);
		void					setTime(QString s);
		void					setOrglocation(QString s);
		void					setCurlocation(QString s);
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
		void					operator=(const Statuseventnotification &old);

	protected:
		QString					m_stNmask;
		QString					m_stNumtype;
		QString					m_stNumber;
		QString					m_stTime;
		QString					m_stOrglocation;
		QString					m_stCurlocation;
		QString					m_stLiid;
		QString					m_stEventtype;
		QString					m_stId;
	};
#endif //STATUSEVENTNOTIFICATION_H

