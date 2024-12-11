all: lenguajeGriton

lenguajeGriton.tab.c lenguajeGriton.tab.h:	lenguajeGriton.y
	bison -t -d lenguajeGriton.y

lex.yy.c: lenguajeGriton.l lenguajeGriton.tab.h
	flex lenguajeGriton.l

lenguajeGriton: lex.yy.c lenguajeGriton.tab.c lenguajeGriton.tab.h
	gcc -o lenguajeGriton lenguajeGriton.tab.c lex.yy.c

clean:
	rm lenguajeGriton.tab.c lex.yy.c lenguajeGriton.tab.h