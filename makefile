binarytree.exe : main.o binarytree.o node.o
	gcc main.o binarytree.o node.o -o binarytree.exe

main.o : main.c binarytree.h
	gcc -c main.c

binarytree.o : binarytree.c binarytree.h node.h
	gcc -c binarytree.c

node.o : node.c node.h
	gcc -c node.c

clean : 
	rm *.o binarytree.exe
	ls