link:
	gcc bin/functions.o bin/main.o -pthread -o bin/main
main.o:
	gcc -c main.c -o bin/main.o
functions.o:
	gcc -c functions.c -o bin/functions.o
clear:
	rm -r -f build
build:
	make clear
	make functions.o
	make main.o
	make link
	clear
