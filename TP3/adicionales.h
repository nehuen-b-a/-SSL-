int longitudArreglo(int *arreglo)
{
    int contador = 0;
    // 10 iteraciones como máximo por si nos olvidamos del -1, así no se queda en un loop infinito
    while(arreglo[contador] != -1 && contador < 10){
        contador++;
    }

    return contador;
}

int longitudCadena(char *cadena)
{
    int contador = 0;
    while (cadena[contador] != '\0')
    {
        contador++;
    }
    return contador;
}