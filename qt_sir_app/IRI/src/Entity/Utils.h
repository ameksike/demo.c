//---------------------------------------------------------------------------
/**
 * @package    SIR
 * @subpackage util
 * @author     ing. Antonio Membrides Espinosa
 * @date       21/02/2021
 * @version    1.0
 */
//---------------------------------------------------------------------------
#ifndef UTILS_H
#define UTILS_H
#include <QByteArray>
#include <QString>
#include <iostream>
#include <QDebug>

using namespace std;

    class Utiles
    {
      public:
        template<typename tr>
        static tr toInteger(const QByteArray *ba, QSysInfo::Endian baByteOrder)
        {
          quint8 tamanoBytes = ba->size();
          quint8 dif = (sizeof(tr) - tamanoBytes);
          char temp[tamanoBytes + dif];

          if( QSysInfo::ByteOrder == baByteOrder )
          {
              for( int i = 0; i < ba->size(); i++ )
                 temp[i] = (quint8)ba->at(i);
          }
          else
          {

              for( int i = ba->size(); i > 0; i-- )
                 temp[ba->size()-i] = (quint8)ba->at(i-1);
          }
          return *((tr *)temp);
        }

        static quint64 QByteArrayToInteger(const QByteArray *ba, QSysInfo::Endian baByteOrder)
        {
           quint8 tamanoBytes = ba->size();
           if( tamanoBytes <= sizeof(quint64) )
           {
               if( tamanoBytes == 1 )
                 return toInteger<quint8>(ba, baByteOrder);

               if( tamanoBytes <= 2 )
                 return toInteger<quint16>(ba, baByteOrder);

               if( tamanoBytes <= 4  )
                 return toInteger<quint32>(ba, baByteOrder);

               if( tamanoBytes > 4 )
                 return toInteger<quint64>(ba, baByteOrder);
           }
           return 0;
        }

        static QString QByteArrayBCDToDecimal(const QByteArray *ba, bool bcdIvertido = true)
        {
            QByteArray temp;
            for( int i = 0; i < ba->length(); i++ )
            {
                /**
                   se desplazan 4 bits a la derecha el byte actual
                   si byte = 0x30 ==> byte = 0x03
                  **/
                quint8 nibbleH = (quint8)ba->at(i) >> 4;
                /**
                  se deja el nibble bajo del byte
                  si byte = 0x30 ==> byte = 0x00
                  **/
                quint8 nibbleB = (quint8)ba->at(i) & 0x0F;
                quint8 digitoH = ( (nibbleH & 0x0F) == 0x0F ) ? 0 : (quint8)(48 + nibbleH);
                quint8 digitoB = ( (nibbleB & 0x0F) == 0x0F ) ? 0 : (quint8)(48 + nibbleB);                
                if( bcdIvertido )
                {
                    temp.append( digitoB );
                    if( digitoH > 0 )
                      temp.append( digitoH );
                }
                else
                {
                    temp.append( digitoH );
                    if( digitoB > 0 )
                      temp.append( digitoB );
                }
            }
            return QString( temp );
        }

        static QByteArray QStringtoBCD( const QString cadena, bool bcdInvertido = true)
        {
            QByteArray temp;

            int i   = 0;
            int len = cadena.length();
            while( i < len )
            {
               // 0x30 = codigo ascii del numero 0 en hex
               // se lo resto para obtener el valor decimal del numero                
               quint8 n1  = (quint8)cadena.at(i).toAscii() - 48;
               quint8 n2  = 0;               
               i++;
               if( !bcdInvertido ) n1  = (n1 * 16) & 0xF0;

               if( (len - i) > 0 )
               {                  
                  n2 = (quint8)cadena.at(i).toAscii() - 48;                  
                  i++;
                  if( bcdInvertido )  n2  = (n2 * 16) & 0xF0;
               }
               else
               {
                  n2 = (bcdInvertido ) ? 0xF0 : 0x0F ;
               }

               temp.append( n1 | n2 );
            }
            return temp;
        }

        //se encarga de obtener los datos del byte array
        // 2 primeros bytes=>indican la cantidad de datos validos en el array
        //y el resto es la informacion
        static QString getData(QByteArray *byteArray, quint16 tamanoCampo, quint8 bytesIndicanTamano = 2)
        {
            //cout<<"byteArray-->size="<<QString().setNum(byteArray->size()).toStdString().c_str()<<endl;
            quint64 len = Utiles::QByteArrayToInteger( &byteArray->left(2) , QSysInfo::LittleEndian);
            byteArray->remove(0, bytesIndicanTamano);
            cout<<"getData-->len="<<QString().setNum(len).toStdString().c_str()<<endl;
            if(len > (tamanoCampo - bytesIndicanTamano) )
            {
                qWarning()<<"getData: len calculado: "<<len << " debe ser <= a "<<tamanoCampo - bytesIndicanTamano;
                len = tamanoCampo - bytesIndicanTamano;
            }
            QByteArray temp = byteArray->left(len) ;
            //cout<<"getData-->data="<<QString( temp ).toStdString().c_str()<<endl;
            byteArray->remove(0, (tamanoCampo - bytesIndicanTamano) );

            return QString(temp);
        }

        static void filtrarCodigos(QString &num)
        {
            QString reMoviles("532105");
            QString reFijosCHO1("53217");
            QString reFijosCH02("532121");

            if ( num.startsWith( reMoviles ) )
            {
                num.remove(2, 3);
                return;
            }

            if ( num.startsWith( reFijosCHO1 ) || num.startsWith( reFijosCH02 ))
            {
                num.remove(2, 2);
                return;
            }
        }
    };
#endif // UTILS_H
