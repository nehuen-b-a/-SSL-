// b. Convertir una cadena de dígitos en su equivalente numérico.
#include <stdio.h>

int convertirCadena(char str[])
{
    int num = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0'); 
        i++;
    }

    return num;
}