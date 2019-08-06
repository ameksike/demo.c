/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef ListaSEH
#define ListaSEH
//---------------------------------------------------------------------------
#include<vcl.h>
#include "NodoSE.h"
//---------------------------------------------------------------------------
template <class T>
class CListaSE
{
        private:
                CNodoSE<T>* ptrcabeza;
                int size;
        public:
                CListaSE(){
                        ptrcabeza = NULL;
                        size = 0;
                }
//---------------------------------------------------------------------------
                void Adicionar(T valor)
                {
                        CNodoSE<T> *actual;
                        CNodoSE<T>* nodo = new CNodoSE<T>(valor);
                        if (Vacia())
                                ptrcabeza = nodo;
                        else
                        {
                                actual = ptrcabeza;
                                while(actual->GetSiguiente()!=NULL)
                                        actual = actual->GetSiguiente();
                                actual->SetSiguiente(nodo);
                        }
                        size++;
                }
//---------------------------------------------------------------------------
                void Insertar( T valor, int pos)
                {
                        if ((pos > 0) &&(pos <= Longitud()))
                        {
                                 CNodoSE<T>* nodo = new CNodoSE<T>(valor);
                                if (pos == 1)
                                {
                                        nodo->SetSiguiente(ptrcabeza);
                                        ptrcabeza = nodo;
                                }
                                else
                                {
                                        CNodoSE<T>* cursor = ptrcabeza;
                                        int cont = 1;
                                        while(cont < pos-1)
                                        {
                                                cursor = cursor->GetSiguiente();
                                                cont++;
                                        }
                                        nodo->SetSiguiente(cursor->GetSiguiente());
                                        cursor->SetSiguiente(nodo);
                                }
                                size++;
                        }
                        else
                        throw Exception("Posicion fuera de rango");
                }
//---------------------------------------------------------------------------
                T Obtener( int pos )
                {
                        CNodoSE<T>* cursor = ptrcabeza;;
                        int i = 1;
                        if ((pos > 0) && (pos <= Longitud()))
                        {
                                while (i < pos)
                                {
                                        cursor = cursor->GetSiguiente();
                                        i++;
                                }
                                return cursor->GetDato();
                        }
                        else
                                throw Exception("Posicion fuera de rango");
                }
//---------------------------------------------------------------------------
     void Eliminar( int pos)
     {
        if ((pos > 0) && (pos <= Longitud()))
        {
                CNodoSE<T>* cursor;
                CNodoSE<T>* temp;
                cursor = ptrcabeza;
                if (pos == 1)
                {
                        ptrcabeza = cursor->GetSiguiente();
                        cursor->SetSiguiente(NULL);
                        delete cursor;
                }
                else
                {
                         int i=1;
                        while(i<pos-1)
                        {
                                cursor = cursor->GetSiguiente();
                                i++;
                        }
                        temp = cursor->GetSiguiente();
                        cursor->SetSiguiente(temp->GetSiguiente());
                        delete temp;
                }
                size--;
        }
        else
                throw Exception("Posicion fuera de rango");
     }
//---------------------------------------------------------------------------
     int Longitud()
     {
        return size;
     }
//---------------------------------------------------------------------------
     bool Vacia()
     {
        return ptrcabeza == NULL;
     }     
};
//---------------------------------------------------------------------------
#endif
