int printf(const char* restrict s, ...); 

/* La parte de const char* restrict s, es un puntero a una cadena, que identifica como se va a formatear la salida
    de la función. 
    Los puntos suspensivos despues de la coma indican que puede haber una cantidad variable de argumentos adicionales.
    El restrict es un calificador de tipo e indica que, dentro de la función, ningún otro puntero (no derivado de s) puede acceder
    a lo apuntado por s si se le hace alguna modificación a su contenido. Esto permite que el compilador se tome algunas libertades
    para optimizar.
*/


int main(void){
    int i = 42;
    prontf("la respuesta es %d\n");


/*

La diferencia entre hello3.c y hello3.i es que se agregan los comandos:
# 1 "hello3.c"
# 1 "<built-in>"
# 1 "<command-line>"

La diferencia entre hello2.i y hello3.i es que al no hacer un include de 
la libreria stdio.h, durante la precompilacion no se 
agregan todos los archivos de cabezera alojados en dicha libreria
*/
