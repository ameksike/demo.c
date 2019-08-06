#include "Connection.h"

// Constructors/Destructors
//

Connection::Connection ( )
{}

Connection::~Connection ( )
{
    this->closeConnection();    
}
void Connection::set_atrivute( string pname,
                        string pdataSource,
                        string puser,
                        string ppassword,
                        int pport,
                        string pserver,
                        string pdriver )
{
   this->dataSource = pdataSource;
   this->user = puser;
   this->password = ppassword;
   this->port = pport;
   this->server = pserver;
   this->driver = pdriver;

   this->connect = QSqlDatabase::addDatabase( pdriver.c_str(), pname.c_str() );
   this->connect.setHostName( pserver.c_str() );
   this->connect.setDatabaseName( pdataSource.c_str() );
   
   this->connect.setPort( pport );
   this->connect.setUserName( puser.c_str() );
   this->connect.setPassword( ppassword.c_str() );


}                  
Connection::Connection( string pname,
                        string pdataSource,
                        string puser,
                        string ppassword,
                        int pport,
                        string pserver,
                        string pdriver )
{
   this->dataSource = pdataSource;
   this->user = puser;
   this->password = ppassword;
   this->port = pport;
   this->server = pserver;
   this->driver = pdriver;

   this->connect = QSqlDatabase::addDatabase( pdriver.c_str(), pname.c_str() );
   this->connect.setHostName( pserver.c_str() );
   this->connect.setDatabaseName( pdataSource.c_str() );
   
   this->connect.setPort( pport );
   this->connect.setUserName( puser.c_str() );
   this->connect.setPassword( ppassword.c_str() );
}

string Connection::get_dataSource()
{
   return this->dataSource;
}

string Connection::get_user()
{
   return this->user;
}

string Connection::get_password()
{
   return this->password;
}

int Connection::get_port()
{
   return this->port;
}

void Connection::set_port( int port )
{
   this->port = port;
}

string Connection::get_server()
{
   return this->server;
}

string Connection::get_driver()
{
   return this->driver;
}

QSqlDatabase Connection::get_connection()
{
   return this->connect;
}

bool Connection::openConnection()
{
   return this->connect.open();
}

bool Connection::openConnection( string puser, string ppassword )
{
   return this->connect.open( puser.c_str(), ppassword.c_str() );
}

bool Connection::closeConnection()
{
   if ( connect.isOpen() )
   {
      this->connect.close();
      this->connect.removeDatabase( name.c_str() );
      return true;
   }
   else
      return false;
}

bool Connection::isValidConnection()
{
   return this->connect.isValid();
}


