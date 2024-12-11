#include <stdio.h>
#include "Conversion.h"

int main()
{
    double fahr, celsius;
    const int lower = 0;   /* límite superior de la tabla de temperaturas */
    const int upper = 300; /* límite superior */
    const int step = 20;   /* tamaño del incremento */

    // imprime tabla de fahrenheit a celsius
    fahr = lower;

    while (fahr <= upper)
    {
        celsius = Celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    // imprime tabla de celsius a fahrenheit
    celsius = lower;

    while (celsius <= upper)
    {
        fahr = Farenheit(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
