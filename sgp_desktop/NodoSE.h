/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//**************************************************************************************
//*** Derecho de Autor: reservados todos los derechos UCI. *****************************
//*** Autores : Joan P Milian - Antonio Membrides - Angel R Salazar - Daryll Miqueli ***
//**************************************************************************************
#ifndef NodoSEH
#define NodoSEH
//---------------------------------------------------------------------------
template <class T>
class CNodoSE
{
 private:
   T info;
   CNodoSE<T>* siguiente;
 public:
   CNodoSE(T Valor, CNodoSE<T>* Siguiente = NULL)
   {
        info = Valor;
        this->siguiente = Siguiente;
   }
   
   CNodoSE<T>* GetSiguiente(){return this->siguiente;}
   void SetSiguiente(CNodoSE<T>* Siguiente){this->siguiente = Siguiente;}
   T GetDato(){return info;}
   void SetDato(T Valor){info = Valor;}
};
//---------------------------------------------------------------------------
#endif

