// a. Calcular y retornar la longitud de una cadena dada.
#include <stdio.h>

int longitudCadena(char* cadena)
{
    int contador=0;
    while(cadena[contador]!='\0')
    {
        contador++;
    }
    return contador;
}