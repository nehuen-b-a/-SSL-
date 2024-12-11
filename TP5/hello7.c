int main(void) {
    int i=42;
    printf("La respuesta es %d\n", i);
}

/*
5a.

> gcc hello7.c -o hello7.exe

hello7.c: In function 'main':
hello7.c:3:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
     printf("La respuesta es %d\n", i);
     ^~~~~~
hello7.c:3:5: warning: incompatible implicit declaration of built-in function 'printf'
hello7.c:3:5: note: include '<stdio.h>' or provide a declaration of 'printf'

> .\hello7.exe
La respuesta es 42


5b.

El proceso de build arrojó dos advertencias, mas no errores.
La primera advertencia indica que existe una declaración implícita de la función printf. En el programa que escribimos,
no existe el prototipo de la función. Por esa razón, se generó una declaración implícita, la cual tiene la siguiente forma:

int printf();

Desde el estándar C99, todos los identificadores deben ser declarados antes de ser utilizados. Por lo tanto, 
no debería haber una declaración implícita. A eso se debe la advertencia.
Si probamos con C90, obtenemos únicamente la otra advertencia que nos salió antes:

> gcc hello7.c -o hello7.exe -std=c90
hello7.c: In function 'main':
hello7.c:3:5: warning: incompatible implicit declaration of built-in function 'printf'
     printf("La respuesta es %d\n", i);
     ^~~~~~
hello7.c:3:5: note: include '<stdio.h>' or provide a declaration of 'printf'

Esta advertencia nos dice que la declaración implícita no es compatible con la forma en la que usamos printf en el programa, pues
le estamos pasando dos parámetros cuando realmente no espera ninguno.

Por último, vemos una nota sugiriendo proveer una declaración o incluir stdio.h. Observando la salida del programa, puede verse
que funciona correctamente, por lo cual sí se hizo uso del printf de stdio aunque no lo hayamos incluido. Esto es porque gcc
implícitamente vincula stdio. De hecho, podemos pedirle que no lo haga, y veremos que el linker no puede encontrar una declaración
acorde a printf, y mucho menos una definición:

> gcc hello7.c -o hello7.exe -std=c90 -nostdlib -lgcc
hello7.c: In function 'main':
hello7.c:3:5: warning: incompatible implicit declaration of built-in function 'printf'
     printf("La respuesta es %d\n", i);
     ^~~~~~
hello7.c:3:5: note: include '<stdio.h>' or provide a declaration of 'printf'
C:\Users\Rocio\AppData\Local\Temp\ccsgSVWq.o:hello7.c:(.text+0x26): undefined reference to `printf'
collect2.exe: error: ld returned 1 exit status
*/