// c. Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula.
#include <stdio.h>

void pasarAMayusculas(char *cadena)
{
    for (char *aux = cadena; *aux != '\0'; aux++)
    {
        if (*aux >= 'a' && *aux <= 'z')
        {
            *aux = *aux - ('a' - 'A');
        }
    }
}