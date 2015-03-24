#include <iostream>
#include <windows.h>
#include "pantalla.h" 

  
using namespace std;

int main(int argc, char *argv[])
{
    float cox, coy;
    pantalla oPantalla(5.1, 8.3);
    //seteando propiedades iniciales
    oPantalla.setTitulo("Sistema de Facturacion");
    oPantalla.pintar();
    
    getchar();
    system("PAUSE");
    return EXIT_SUCCESS;
}

