CC = gcc
TARGETS = ConversionTest TablasDeConversion
OBJ1 = Conversion.o ConversionTest.o
OBJ2 = Conversion.o TablasDeConversion.o

all: $(TARGETS)

ConversionTest: $(OBJ1)
	$(CC) -o test $(OBJ1) -lm

TablasDeConversion: $(OBJ2)
	$(CC) -o output $(OBJ2) -lm

Conversion.o: Conversion.c Conversion.h
ConversionTest.o: ConversionTest.c Conversion.h
TablasDeConversion.o: TablasDeConversion.c Conversion.h

clean:
	rm -f *.o *.exe