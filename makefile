all: main.o list.o
	gcc main.o list.o -o tunez.out

main.o: main.c
	gcc -c main.c

list.o: list.c
	gcc -c list.c

run: tunez
	./tunez

clean:
	rm *.o
	rm *.out
	rm *~
