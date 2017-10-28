main: home.c node.c node.h
	gcc home.c node.c -o home

clean: 
	rm home
