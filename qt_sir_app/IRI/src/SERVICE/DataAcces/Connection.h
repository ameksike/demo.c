#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

class Connection
{

   public:
      Connection ( );
      Connection( string pname,
                  string pdataSource,
                  string puser,
                  string ppassword,
                  int pport,
                  string pserver,
                  string pdriver );
      ~Connection ( );
      
       void set_atrivute( string pname,
                  string pdataSource,
                  string puser,
                  string ppassword,
                  int pport,
                  string pserver,
                  string pdriver );

      string get_dataSource();
      void set__dataSource(string pdataSource);
      
      string get_user();
      void set__user();
      
      string get_password();
      int get_port();
      void set_port( int pport );
      string get_server();
      string get_driver();
      QSqlDatabase get_connection();
      bool openConnection();
      bool openConnection( string puser, string ppassword );
      bool closeConnection();
      bool isValidConnection();
      QSqlDatabase getDatabase()
      {
      	return connect;
      }
      

   private:
      QSqlDatabase connect;
      string dataSource;
      string user;
      string password;
      int port;
      string server;
      string driver;
      string name;
};

#endif // CONNECTION_H
