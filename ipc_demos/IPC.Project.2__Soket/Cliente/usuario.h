#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
class Usuario
{
    QString usuario;
    QString nick;
    QString password;
public:
    Usuario(QString usuario, QString nick, QString password);
    Usuario();
    QString getUsuario();
    QString getNick();
    QString getPaswword();
    void setUsuario(QString valor);
    void setPassword(QString valor);
    void setNick(QString valor);
};

#endif // USUARIO_H
