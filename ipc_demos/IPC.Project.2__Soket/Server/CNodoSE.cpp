//******************************************************************************
#ifndef NodoSEH
#define NodoSEH
//******************************************************************************
template <class T>
class CNodoSE
{
 protected:
   T Dato;
   CNodoSE<T>* Siguiente;

 public:
   CNodoSE();
   CNodoSE(T Valor, CNodoSE<T>* siguiente = 0);
   CNodoSE<T>* Get_Siguiente();
   void Set_Siguiente(CNodoSE<T>* siguiente);
   void Set_Dato(T Valor);
   T Get_Dato();
   virtual ~CNodoSE(){}
};
//******************************************************************************
//..............................................................................
//    Ultima Modificacion : 15/11/2007
//    Autor: Antonio Membrides Espinosa
//..............................................................................
//*********** IMPLEMENTACION ***************************************************
template <class T>
CNodoSE<T>::CNodoSE()
{
        Siguiente = 0;
}
//...........................................................................
template <class T>
CNodoSE<T>::CNodoSE(T Valor, CNodoSE<T>* siguiente)
{
        Dato = Valor;
        this->Siguiente = siguiente;
}
//...........................................................................
template <class T>
CNodoSE<T>* CNodoSE<T>::Get_Siguiente()
{
      return this->Siguiente;
}
//...........................................................................
template <class T>
void CNodoSE<T>::Set_Siguiente(CNodoSE<T>* siguiente)
{
      this->Siguiente = siguiente;
}
 //...........................................................................
template <class T>
void CNodoSE<T>::Set_Dato(T Valor)
{
      Dato = Valor;
}
//...........................................................................
template <class T>
T CNodoSE<T>::Get_Dato()
{
      return Dato;
}
//...........................................................................
#endif
