all:
	gcc -Wall -ansi -pedantic -Iinclude avltree.c -Iinclude parsefile.c -Include treeoperations.c -o avltree
