all: clean compile test

clean:
	rm -f *.o

compile:
	gcc lists.h lists.c main.c -o main.o

test:
	./main.o
