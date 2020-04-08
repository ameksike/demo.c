//******************************************************************************
#ifndef ErrorH
#define ErrorH
//******************************************************************************
class CExcepcion
{
  private:
     char* Mensage;
  public:
     CExcepcion(char* MensageE)
     {
          Mensage = MensageE; 
     }
     //.........................................................................
     char* Get_Mensage()
     { 
          return Mensage; 
     }
     //.........................................................................
};
#endif
//******************************************************************************
/*
  Nota: para capturar los errores se utiliza la siguente sintaxis:
      try
      {
         ...
      }
      catch(CExcepcion Error)
      {
        char* MyError = Error.Get_Mensage();
      }
*/
//..............................................................................
//    Ultima Modificacion : 6/10/2007
//    Autor: Antonio Membrides Espinosa
//******************************************************************************  
