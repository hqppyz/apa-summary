all: clean compile test

clean:
	rm -f *.o

compile:
	gcc lists.h lists.c es1.h es1.c es2.h es2.c es3.h es3.c es4.h es4.c es5.h es5.c es6.h es6.c main.c -o main.o

test:
	./main.o 3
