make: cgol.o reduceSpace.o
	gcc -ansi -Wall -o cgol cgol.o reduceSpace.o

cgol: cgol.o reduceSpace.o
	gcc -ansi -Wall -o cgol cgol.o reduceSpace.o

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

reduceSpace.o: reduceSpace.c
	gcc -ansi -Wall -c reduceSpace.c

clean:
	rm cgol reduceSpace.o cgol.o
