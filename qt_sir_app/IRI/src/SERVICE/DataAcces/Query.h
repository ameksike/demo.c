#ifndef QUERY_H
#define QUERY_H

#include "Connection.h"



#include <QSqlRecord>
#include <QSqlField>

#include <string>
#include <vector>
#include <map>

using namespace std;

class Query
{

   public:
      Query (string pname,
                        string pdataSource,
                        string puser,
                        string ppassword,
                        int pport,
                        string pserver,
                        string pdriver );
      //Query( string pname, this->Query::connection * pconnection, string pquery );
      ~Query ( );
      QSqlQuery execute( QString sql = "");
      QString get_query();
      QSqlQuery getSqlQuery();
      void set_query(QString query);
      Connection getConnection();

   private:
      Connection connection;
      QString query;
      
      //tabla a insetar
      //DatHead * test;
      int cant;
};



#endif // QUERY_H
