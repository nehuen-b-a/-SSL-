// e. Concatenar al final de la primera cadena dada una segunda cadena también dada.
#include <stdio.h>

void concatenarCadenas(char *cadena1, char *cadena2)
{
    int longitud1 = longitudCadena(cadena1);
    int longitud2 = 0;

    while (cadena2[longitud2] != '\0') {
        cadena1[longitud1 + longitud2] = cadena2[longitud2];
        longitud2++;
    }

    cadena1[longitud1 + longitud2] = '\0';
}