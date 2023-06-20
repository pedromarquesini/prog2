all:	
	gcc -g -Wall -o trab1 *.c -lm

clean:
	rm trab1 

limpa:
	rm -rf saida
	rm trab1
	
clOutput:
	rm -rf output/*

run:	
	rm -rf output/*
	./trab1 ./output < teste_1/teste_1/entrada_1

run2:	
	rm -rf output/*
	./trab1 ./output < teste_2/teste_2/entrada_2

run3:	
	rm -rf output/*
	./trab1 ./output < teste_3/teste_3/entrada_3
	
valgrind:
	valgrind ./trab1 ./output < teste_3/teste_3/entrada_3

valgrindFull:
	valgrind  --leak-check=full --show-leak-kinds=all ./trab1 ./output < testes_correcao/teste_12/entrada
