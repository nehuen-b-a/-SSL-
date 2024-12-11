#include "Conversion.h"

double Celsius(double fahr)
{
    return (fahr - 32) * 5 / 9;
}

double Farenheit(double celsius)
{
    return (celsius * 9 / 5) + 32;
}
