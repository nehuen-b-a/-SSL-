// f. Modificar la cadena dada con la inserción de un carácter dado en una posición determinada.
#include <stdio.h>

void insertarCharEnPos(char *cadena, char caracter, int pos)
{
    int longAux = longitudCadena(cadena)+1;
    char aux[longAux];

    for (int i = 0; i <= longAux; i++)
    {
        *(aux+i) = i < pos? *(cadena+i) : i == pos? caracter : *(cadena+i-1);
    }
    printf("Cadena con el caracter '%c' insertado en la posicion %d: %s\n\n", caracter, pos, aux);
}