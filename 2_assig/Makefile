cc=gcc

build : build.o add.o sub.o
	$(cc) -o build build.o add.o sub.o

build.o: build.c
	$(cc) -c -o build.o build.c

add.o: add.c
	$(cc)  -c -o add.o add.c

sub.o: sub.c
	$(cc)  -c -o sub.o sub.c

clean:
	rm -rf *.o build