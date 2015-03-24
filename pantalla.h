//PANTALLA.H
#ifndef __PUNTO_H__
#define __PUNTO_H__
class pantalla {
      float x, y;
      char* titulo;
      int numero, filas, columnas;
      public:
         pantalla(float=0, float=0);
         void aumentar(float, float);
         void imprimir(void);
         
         char* getTitulo(void);
         void setTitulo(char*);
         
         int getNumero(void);
         void setNumero(int);
         
         void pintar(void);
};
#endif
//
