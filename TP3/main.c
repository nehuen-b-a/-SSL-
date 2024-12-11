#include <stdio.h>
#include "categoriasLexicas.h"
#include "adicionales.h"

int esFinal(int estado, int *estadosFinales, int nroEstadosFinales);
int esFinalSegunLexema(int estado, int categoria);
int posicionAlfabeto(char c, char *alfabeto);
int procesarTabla(int estado, char c, int i);
char *perteneceA(int categoria);
int esLexema(char cadena[]);

int main()
{
    printf("Ingresar lexema: ");
    char cadena[] = "";
    scanf("%[^\n]", &cadena);

    if (esLexema(cadena))
        printf("Cadena valida \n");
    else
        printf("Cadena NO valida \n");

    return 0;
}

int esFinal(int estado, int *estadosFinales, int nroEstadosFinales)
{
    for (int i = 0; i < nroEstadosFinales; i++)
    {
        if (estado == estadosFinales[i])
            return 1;
    }
    return 0;
}

int esFinalSegunLexema(int estado, int categoria)
{
    int *estadosFinales;
    int nroEstadosFinales, resultado;

    switch (categoria)
    {
    case PALABRAS_RESERVADAS:
        estadosFinales = estadosFinalesPalabrasReservadas;
        break;
    case CARACTERES_PUNTUACION:
        estadosFinales = estadosFinalesCaracteresPuntuacion;
        break;
    case IDENTIFICADOR:
        estadosFinales = estadosFinalesIdentificador;
        break;
    case CONSTANTE_ENTERA:
        estadosFinales = estadosFinalesCteEntera;
        break;
    case CADENA:
        estadosFinales = estadosFinalesCadenas;
        break;
    case OPERADORES:
        estadosFinales = estadosFinalesOperador;
        break;
    }

    nroEstadosFinales = longitudArreglo(estadosFinales);
    resultado = esFinal(estado, estadosFinales, nroEstadosFinales);
    return resultado;
}

int posicionAlfabeto(char c, char *alfabeto)
{
    for (int i = 0; i < longitudCadena(alfabeto); i++)
        if (alfabeto[i] == c)
            return i;

    return -1;
}

int procesarTabla(int estado, char c, int categoria)
{
    int *transicionesDeEstado;
    char *alfabeto;
    int posicion, nuevoEstado;

    switch (categoria)
    {
    case PALABRAS_RESERVADAS:
        transicionesDeEstado = tablaPalabrasReservadas[estado];
        alfabeto = alfabetoPalabrasReservadas;
        break;
    case CARACTERES_PUNTUACION:
        transicionesDeEstado = tablaCaracteresPuntuacion[estado];
        alfabeto = alfabetoCaracteresPuntuacion;
        break;
    case IDENTIFICADOR:
        transicionesDeEstado = tablaIdentificador[estado];
        alfabeto = alfabetoIdentificador;
        break;
    case CONSTANTE_ENTERA:
        transicionesDeEstado = tablaCteEntera[estado];
        alfabeto = alfabetoCteEntera;
        break;
    case CADENA:
        transicionesDeEstado = tablaCadenas[estado];
        alfabeto = alfabetoCadenas;
        break;
    case OPERADORES:
        transicionesDeEstado = tablaOperador[estado];
        alfabeto = alfabetoOperador;
        break;
    }

    posicion = posicionAlfabeto(c, alfabeto);

    if (posicion == -1)
        nuevoEstado = -1;
    else
        nuevoEstado = transicionesDeEstado[posicion];

    return nuevoEstado;
}

char *perteneceA(int categoria)
{
    switch (categoria)
    {
    case PALABRAS_RESERVADAS:
        return "Palabras reservadas";
    case CARACTERES_PUNTUACION:
        return "Caracteres de puntuacion";
    case IDENTIFICADOR:
        return "Identificador";
    case CONSTANTE_ENTERA:
        return "Constante entera";
    case CADENA:
        return "Cadena";
    case OPERADORES:
        return "Operador";
    }
}

int esLexema(char cadena[])
{
    for (int categoria = 0; categoria < CANTIDAD_TABLAS; categoria++)
    {
        int estado = 0;
        for (int i = 0; i < longitudCadena(cadena); i++)
        {
            char c = cadena[i];
            estado = procesarTabla(estado, c, categoria);

            if (estado == -1)
                break;
        }

        if (estado != -1 && esFinalSegunLexema(estado, categoria))
        {
            printf("Categoria: %s. ", perteneceA(categoria));
            return 1;
        }
    }

    return 0;
}