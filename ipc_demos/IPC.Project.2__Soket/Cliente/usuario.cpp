#include "usuario.h"

Usuario::Usuario()
{
}
Usuario::Usuario(QString usuario, QString nick, QString password)
{
    this->usuario = usuario;
    this->nick =nick;
    this->password = password;
}
QString Usuario::getUsuario(){
    return usuario;
}
    QString Usuario::getNick(){return nick;}
    QString Usuario::getPaswword(){return password;}
    void Usuario::setUsuario(QString valor){usuario =valor;}
    void Usuario::setPassword(QString valor){password = valor;}
    void Usuario::setNick(QString valor){nick = valor;}
