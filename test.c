#include <stdio.h>
#include "puntoA.c"
#include "puntoB.c"
#include "puntoC.c"
#include "puntoD.c"
#include "puntoE.c"
#include "puntoF.c"

int main(){
    printf("\nTEST FUNCIONES TP1\n\n");
    
    //Punto A
    char cadenaA[] = "Esta cadena tiene 31 caracteres";
    int valorA = longitudCadena(cadenaA);
    printf("Punto A \n");
    printf("Cadena: %s\n", cadenaA);
    printf("Longitud de la cadena: %d\n\n", valorA);
    
    //Punto B
    char cadenaB[] = "1234";
    int valorB = convertirCadena(cadenaB);
    printf("Punto B \n");
    printf("Cadena de digitos: %s\n", cadenaB);
    printf("Numero entero: %d\n\n", valorB);

    //Punto C
    char cadenaC[] = "ahora susurro despues grito";
    printf("Punto C \n");
    printf("Cadena original: %s\n", cadenaC);
    pasarAMayusculas(cadenaC);
    printf("Cadena en mayusculas: %s\n\n", cadenaC);

    //Punto D
    char cadenaD[] = "A esta cadena se le va a quitar el caracter 'a'";
    printf("Punto D \n");
    printf("Cadena original: %s\n", cadenaD);
    eliminarCaracter(cadenaD, 'a');
    printf("Cadena modificada: %s\n\n", cadenaD);

    //Punto E
    char cadenaE1[] = "Sol";
    char cadenaE2[] = "Dado";
    printf("Punto E \n");
    printf("Cadenas 1: %s \n", cadenaE1);
    printf("Cadenas 2: %s \n", cadenaE2);
    concatenarCadenas(cadenaE1, cadenaE2);
    printf("Cadenas concatenadas: %s \n\n", cadenaE1);

    //Punto F
    char cadenaF[] = "SolDado";
    char caracterNuevo = ' ';
    int posicionCaracter = 3;
    printf("Punto F \n");
    printf("Cadena original: %s \n", cadenaF);
    insertarCharEnPos(cadenaF, caracterNuevo, posicionCaracter);

    return 0;
}