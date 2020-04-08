//******************************************************************************
#ifndef ListaSEH
#define ListaSEH
//... Librerias necesarias .....................................................
#include <string>
using namespace std;
#include "CNodoSE.cpp"
#include "CExcepcion.cpp"
//******************************************************************************
template <class T>
class CListaSE
{
   private:
     CNodoSE<T>* ptr_cabeza;
     int size;

   private:
     CNodoSE<T>*  Obtener_Nodo( int pos )const;
     void Intercambiar_Datos(int i,int j);

   public:
     CListaSE();
     ~CListaSE();
     T operator[](int pos);
     T Obtener(int pos);
     //T Obtener(int I=1, int F=Longitud(), char Criterio[]="Mayor");
     void operator+=(CListaSE<T>* Lista);
     void operator+=(T valor);
     void Adicionar(T valor);
     void Insertar(T valor, int pos);
     void Modificar(T valor, int pos);
     void Eliminar(int pos);
     void Eliminar(int Inicio, int Final);
     void Limpiar();
     void Ordenar_Burbuja(char* Criterio);
     void Concatenar(CListaSE<T>* L);
     int  Longitud();
     int  Buscar(T valor);
     bool Vacia();
     CListaSE<T>* Copy_To_List();
};
//******************************************************************************
//..............................................................................
//... Nota: En esta lista los indices comienzan en 1  ..........................
//    Ultima Modificacion : 6/10/2007
//    Autor: Antonio Membrides Espinosa
//..............................................................................
//*********** IMPLEMENTACION ***************************************************
template <class T>
CNodoSE<T>* CListaSE<T>::Obtener_Nodo( int pos )const
{
        CNodoSE<T> * cursor = ptr_cabeza;
        int pos_cursor = 1;
        while (cursor != 0 && pos_cursor != pos )
        {
           cursor = cursor->Get_Siguiente();
           pos_cursor++;
        }
        return cursor;
}
//..............................................................................
template <class T>
CListaSE<T>::CListaSE()
{
         ptr_cabeza = 0;
         size = 0;
}
//..............................................................................
template <class T>
CListaSE<T>::~CListaSE()
{
     Limpiar();
     delete ptr_cabeza;
}
//..............................................................................
template <class T>
T CListaSE<T>::operator[](int pos)
{
     return this->Obtener(pos);
}
//..............................................................................
template <class T>
void CListaSE<T>::operator+=(CListaSE<T>* Lista)
{
    for(int i=1;i<= Lista->Longitud(); i++)
        this->Adicionar(Lista->Obtener(i));
}
//..............................................................................
template <class T>
void CListaSE<T>::operator+=(T valor)
{
        this->Adicionar(valor);
}
//..............................................................................
template <class T>
int CListaSE<T>::Buscar(T valor)
{
        if(!Vacia())
        {
           CNodoSE<T>* Cursor = ptr_cabeza;
           int pos = 1;
           while(Cursor->Get_Siguiente() != 0 && Cursor->Get_Dato()!= valor)
           {
              Cursor = Cursor->Get_Siguiente();
              pos++;
           }
           if(Cursor->Get_Siguiente() == 0 && Cursor->Get_Dato()!= valor)
              return 0;
           return pos;
        }
       /* else
            throw CExcepcion("Error: La lista esta vacia, no se puede realizar la operación de Busqueda");
*/
}
//..............................................................................
template <class T>
void CListaSE<T>::Adicionar(T valor)
{
        CNodoSE<T>* actual;
        CNodoSE<T>* nodo = new CNodoSE<T>(valor);
        if (Vacia())
            ptr_cabeza = nodo;
        else
        {
            actual = ptr_cabeza;
            while(actual->Get_Siguiente()!=0)
                actual = actual->Get_Siguiente();
            actual->Set_Siguiente(nodo);
        }
        size++;
}
//..............................................................................
template <class T>
void CListaSE<T>::Insertar( T valor, int pos)
{
         if ((pos > 0) &&(pos <= Longitud()))
         {
             CNodoSE<T>* nodo = new CNodoSE<T>(valor);
             if (pos == 1)
             {
                 nodo->Set_Siguiente(ptr_cabeza);
                 ptr_cabeza = nodo;
             }
             else
             {
                  CNodoSE<T>* cursor = ptr_cabeza;
                  int cont = 1;
                  while(cont < pos-1)
                  {
                     cursor = cursor->Get_Siguiente();
                     cont++;
                  }
                  nodo->Set_Siguiente(cursor->Get_Siguiente());
                  cursor->Set_Siguiente(nodo);
             }
             size++;
         }
        /* else
           throw CExcepcion("Error: Posicion fuera de rango, no se puede realizar la operación de Insertar");*/
}
//..............................................................................
template <class T>
T CListaSE<T>::Obtener( int pos )
{
       if(!Vacia())
       {
          CNodoSE<T>* cursor = ptr_cabeza;;
          int i = 1;
          if ((pos > 0) && (pos <= Longitud()))
          {
              while (i < pos)
              {
                   cursor = cursor->Get_Siguiente();
                   i++;
              }
              return cursor->Get_Dato();
          }
	 /* else
	  {
		char mensaje[] = "Error: Posicion fuera de rango, no se puede realizar la operación de Obtener en una posicion";
		throw CExcepcion(mensaje);
	  }*/
       }
      /* else
       {
		char mensaje[] = "Error: La lista esta vacia, no se puede realizar la operación de Obtener en una posicion";
		throw CExcepcion(mensaje);
       }*/

}
//.............................................................................. Algorismo Divide y Venceras, metodo del mayor o el menor
/*template <class T>
T CListaSE<T>::Obtener(int I, int F, char Criterio[])          //...... Uso de la sobrecarga de funciones
{
       if(!Vacia())
       {
         T aux1, aux2;
         if (I == F)
           return (Obtener(I));
         else
         {
           aux1 = Obtener(I, (I+F)/2, Criterio);
           aux2 = Obtener(((I+F)/2)+1, F, Criterio);
           if (!strcmp(Criterio, "Mayor") && aux1 > aux2 || !strcmp(Criterio, "Menor") && aux1 < aux2)
               return (aux1);
           else
               return (aux2);
         }
       }
       else
           throw CExcepcion("Error: La lista esta vacia, no se puede realizar la operación de Obtener dado un criterio");
}*/
//..............................................................................
template <class T>
void CListaSE<T>::Eliminar( int pos)
{
        if ((pos > 0) && (pos <= Longitud()))
        {
                CNodoSE<T>* cursor;
                CNodoSE<T>* temp;
                cursor = ptr_cabeza;
                if (pos == 1)
                {
                    ptr_cabeza = cursor->Get_Siguiente();
                    cursor->Set_Siguiente(0);
                    delete cursor;
                }
                else
                {
                     int i=1;
                     while(i<pos-1)
                     {
                          cursor = cursor->Get_Siguiente();
                          i++;
                     }
                     temp = cursor->Get_Siguiente();
                     cursor->Set_Siguiente(temp->Get_Siguiente());
                     delete temp;
                }
                size--;
        }
        /*else
	{
		/*char mensaje[] = "Error: Posicion fuera de rango, no se puede realizar la operación de Eliminar en una posicion";
		throw CExcepcion(mensaje);
	}*/

}
//..............................................................................
template <class T>
void CListaSE<T>::Eliminar(int Inicio, int Final)
{
   if(Inicio<=Final)
   {
     while(Inicio!=Final)
     {
       Eliminar(Inicio);
       Final--;
     }
     Eliminar(Inicio);
   }
   /*else
	{
		char mensaje[] = "Error: Rango de eliminacion Incorrecto, no se puede realizar la operación de Eliminar";
		throw CExcepcion(mensaje);
	}*/
}
//..............................................................................
template <class T>
int CListaSE<T>::Longitud()
{
        return size;
}
//..............................................................................
template <class T>
bool CListaSE<T>::Vacia()
{
        return ptr_cabeza == 0;
}
//..............................................................................
template <class T>
void CListaSE<T>::Limpiar()
{
         while(!Vacia())
         {
           CNodoSE<T> * cursor = ptr_cabeza;
           ptr_cabeza = ptr_cabeza->Get_Siguiente();
           delete cursor;
           size--;
         }
}
//..............................................................................
template <class T>
void CListaSE<T>::Intercambiar_Datos(int i,int j)
{
        T temporal;
        temporal = Obtener_Nodo(i)->Get_Dato();
        Obtener_Nodo(i)->Set_Dato(Obtener_Nodo(j)->Get_Dato());
        Obtener_Nodo(j)->Set_Dato(temporal);
}
//.............................................................................. Algorismo Burbuja
/*template <class T>
void CListaSE<T>::Ordenar_Burbuja(char* Criterio)
{
        for (int i = 1;i <= Longitud(); i++)
         for (int j = i+1;j <= Longitud(); j++)
          if(!strcmp(Criterio, "Menor-Mayor" )&& Obtener(i) > Obtener(j) || !strcmp(Criterio, "Mayor-Menor" )&& Obtener(i) < Obtener(j))
               Intercambiar_Datos(i,j);
}*/
//..............................................................................
template <class T>
void CListaSE<T>::Concatenar(CListaSE<T>* L)
{
    if(L)
    {
      for(int i=1; i<= L->Longitud(); i++)
      Adicionar(L->Obtener(i));
    }
   /* else
	{
		char mensaje[] = "Error: Lista por parametro ausente de valor, no se puede realizar la operación de Concatenar";
		throw CExcepcion(mensaje);
	}*/
}
//..............................................................................
template <class T>
CListaSE<T>* CListaSE<T>::Copy_To_List()
{
   CListaSE<T>* Lista_C = new CListaSE<T>();
   for(int i=1; i<=Longitud(); i++)
    Lista_C->Adicionar(Obtener(i));
   return Lista_C;
}
//..............................................................................
template <class T>
void CListaSE<T>::Modificar(T valor, int pos)
{
    Obtener_Nodo(pos)->Set_Dato(valor);
}
//..............................................................................
#endif
//******************************************************************************
