%{
	#include <stdio.h>
	#include "lenguajeGriton.tab.h"
%}
%option noyywrap
%%
ent					{return ENT;};
cad					{return CAD;};
mostrar				{return MOSTRAR;};
ing					{return ING;};
[A-Z]([A-Z_])*		{return ID;};
0|(-?[1-9][0-9]*)	{return CONSTANTE;};
\"[a-z ]*\" 		{return CADENA;};
[+*()=]				{return yytext[0];};
\ |\n 					;
.					{return ERROR;};
%%