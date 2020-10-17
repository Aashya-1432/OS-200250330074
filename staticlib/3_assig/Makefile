
arith: arith.o add.o mul.o
	gcc -o arith arith.o add.o mul.o

arith.o:arith.c
	gcc -c -o arith.o arith.c

add.o: add.c
	gcc -c -o add.o add.c

mul.o: mul.c
	gcc -c -o mul.o mul.c

clean:
	rm -rf *.o arith