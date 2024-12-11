#include "Conversion.h"
#include <assert.h>
#include <math.h>

double redondear(double *num);

int main()
{
    double valoresFahr[] = {32.0, 77, 86};
    double valoresCelEsperados[] = {0, 25, 30};
    double valoresCel[] = {0, 20, 40, 80};
    double valoresFahrEsperados[] = {32, 68, 104, 176};
    double resultado; 

    for (int i = 0; i < 3; i++)
    {
        resultado = Celsius(valoresFahr[i]);
        redondear(&resultado);
        assert(resultado == valoresCelEsperados[i]);
    }

    for (int j = 0; j < 4; j++)
    {
        resultado = Farenheit(valoresCel[j]);
        redondear(&resultado);
        assert(resultado == valoresFahrEsperados[j]);
    }
}

double redondear(double *num){
    return round(*num * 100)/100;
}