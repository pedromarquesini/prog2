all:
	gcc -g -Wall -o trab1 *.c 
clean:
	rm trab1 
run:
	./trab1 < /input/in_1.txt
valgrind:
	valgrind --track-origins=yes --leak-check=full ./trab1 < /input/entrada_1