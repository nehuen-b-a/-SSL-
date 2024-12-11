int printf(const char* restrict s, ...); 

int main(void){
    int i = 42;
    prontf("la respuesta es %d\n");
}


/*
Para compilar se usa el comando gcc -S hello4.c -o nombre.s

Durante la compilacion se ejecuta el analisis sintactico y semantico sobre el .c
y se traduce el codigo a un lenguaje de maquina

para ensamblar se utiliza 

gcc -c archivo.s -o nombre.o
o
as -o nombre.o archivo.s

*/