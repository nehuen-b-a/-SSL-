%{
      #include <stdio.h>
      void yyerror(const char *);
      extern FILE* yyin;
%}

%token ENT CAD MOSTRAR ING
%token ID
%token CONSTANTE
%token CADENA
%token ERROR

%%

programa: listaDeclaraciones listaSentencias

listaDeclaraciones: sentDeclaracion listaDeclaraciones    
                  | /*epsilon*/

sentDeclaracion: tipoDeDato ID valorAsignado
               | tipoDeDato ID

valorAsignado: '=' valorAAsignar

valorAAsignar: CADENA | expAritmetica

tipoDeDato: ENT | CAD

listaSentencias: sentIO listaSentencias  
               | /*epsilon*/

sentIO: sentIngreso
      | sentSalida

sentIngreso: ING ID

sentSalida: MOSTRAR salida

salida: CADENA | expAritmetica 

expAritmetica: termino '+' expAritmetica
             | termino

termino: factor '*' termino
       | factor

factor: ID | CONSTANTE | '(' expAritmetica ')' 

%%

int main(void)
{
	
	if(yyparse()==0)
		printf("Compilacion exitosa\n");
	else
		printf("NO Compila\n");
	return 0;
}

void yyerror(const char * s)
{
	puts(s);
	return ;
}