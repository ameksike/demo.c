#include "Query.h"
#include <iostream>
using namespace std;

// Constructors/Destructors
//
///Connection Query::connection;
Query::Query (string pname,
                        string pdataSource,
                        string puser,
                        string ppassword,
                        int pport,
                        string pserver,
                        string pdriver
                         )
                        
                         
{
    connection.set_atrivute(pname,pdataSource,puser,ppassword,pport,pserver,pdriver);

 		
   cant = 3;
   this->connection.openConnection();
}


Connection Query::getConnection()
{
	return connection;
}

Query::~Query ( )
{
    this->connection.closeConnection();
}

QString Query::get_query()
{
    return this->query;
}

QSqlQuery Query::getSqlQuery()
{
    return QSqlQuery(this->connection.getDatabase());
}

void  Query::set_query(QString query)
{
    this->query = query;
}

QSqlQuery Query::execute( QString sql )
{ 
  if ( this->connection.openConnection() )
   {
        QSqlQuery pquery = QSqlQuery( this->connection.get_connection() );
        if( !sql.length() )
          sql = this->query;
        pquery.prepare( sql );
        pquery.exec();
        //this->connection.closeConnection();
        return pquery;
   }
  return NULL;
}
