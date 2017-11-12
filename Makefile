main: main.c node.c node.h parser.c parser.h
	gcc -Wall main.c node.c parser.c -o keyvalue

clean: 
	rm keyvalue

run:
	./keyvalue
