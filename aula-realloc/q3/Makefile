CC = gcc
CFLAGS = -Wall -Werror
OBJFILES = main.o pessoa.o

all: main

main: $(OBJFILES)
	$(CC) $(CFLAGS) -o main $(OBJFILES)

main.o: main.c pessoa.h
	$(CC) $(CFLAGS) -c main.c

pessoa.o: pessoa.c pessoa.h
	$(CC) $(CFLAGS) -c pessoa.c

clean:
	rm -f *.o main
