#ifndef SSOPERATION_H
#define SSOPERATION_H

#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>

#include "../../BUSINESS_LOGIC/Entity/structs.h"
#include "../../BUSINESS_LOGIC/Entity/Movil/SSOPERATION.h"
class QSqlQuery;

class Ssoperation 
	{
	public:
							Ssoperation(QObject *parent = 0,const char *name = 0);
							Ssoperation(SSOPERATION &old);
							~Ssoperation();

	public:
		QString					getNmask();
		QString					getNumyype();
		QString					getNumber();
		QString					getTime();
		QString					getLocation();
		QString					getOperatetype();
		QString					getServicetype();
		QString					getForwardnumber();
		QString					getSuccessflag();
		QString					getLiid();
		QString					getEventtype();
		QString					getId();

	public:
		void					setNmask(QString s);
		void					setNumyype(QString s);
		void					setNumber(QString s);
		void					setTime(QString s);
		void					setLocation(QString s);
		void					setOperatetype(QString s);
		void					setServicetype(QString s);
		void					setForwardnumber(QString s);
		void					setSuccessflag(QString s);
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
		void					operator=(const Ssoperation &old);

	protected:
		QString					m_stNmask;
		QString					m_stNumyype;
		QString					m_stNumber;
		QString					m_stTime;
		QString					m_stLocation;
		QString					m_stOperatetype;
		QString					m_stServicetype;
		QString					m_stForwardnumber;
		QString					m_stSuccessflag;
		QString					m_stLiid;
		QString					m_stEventtype;
		QString					m_stId;
	};
#endif //SSOPERATION_H

