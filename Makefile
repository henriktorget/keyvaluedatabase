main: main.c node.c node.h parser.c parser.h
	g++ -Wall main.c node.c parser.c -o keyvalue

gcc: main.c node.c node.h parser.c parser.h
	gcc main.c node.c parser.c -o keyvalue

debug: main.c node.c node.h parser.c parser.h
	g++ -g main.c node.c parser.c -o keyvalue

clean: 
	rm keyvalue

run:
	./keyvalue
