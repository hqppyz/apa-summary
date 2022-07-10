all: clean compile test

clean:
	rm -f *.o

compile:
	gcc lists.h lists.c es1.h es1.c es2.h es2.c es3.h es3.c main.c -o main.o

test:
	./main.o 3
