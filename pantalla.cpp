// PUNTO.CPP
#ifndef __PANTALLA_CPP__
#define __PANTALLA_CPP__

#include <cstdlib>
#include <iostream.h>
#include <string>
#include <windows.h>
#include "pantalla.h"
using std::string;

pantalla :: pantalla(float cx, float cy){
    x=cx;
    y=cy;
    /*Obtengo las filas y las columnas*/
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;    
}

char* pantalla :: getTitulo(void){
    return titulo;
}

void pantalla :: setTitulo(char* ctitulo){
     titulo=ctitulo;
}


int pantalla :: getNumero(void){
    return 0;
}

void pantalla :: setNumero(int ctitulo){
     numero=1;
}

void pantalla :: aumentar(float c1, float c2){
    x=x+c1;
    y=y+c2;
}
void pantalla :: imprimir(void){
    cout << "(" << x << "," << y << ")";
}

void pantalla :: pintar(void){     
     int posX, posY;
     //imprimimos titulo
     int posInicialTitulo;
     posInicialTitulo=int((columnas-strlen(titulo))/2);          
     for(posX=0;posX<columnas;posX++){                                      
       if(posInicialTitulo==posX){
         cout << titulo;
         posX+=strlen(titulo)-1;
       }else{
         cout << "=";
       }       
     }
     //imprimir resto
     for(posY=0;posY<filas-2;posY++){
          for(posX=0;posX<columnas;posX++){
            if(posY==filas-3){
              cout << "=";
            }else{
              if(posX==0 || posX==columnas-1){
               cout << "=";
              }else{
               cout << " ";
              }                     
            }            
          } 
     }
}

#endif
