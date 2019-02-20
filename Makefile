CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Werror -std=c99 -pedantic

all: main

main: main.o resolve.o pilha.o
	$(CC) $(CFLAGS) main.o resolve.o pilha.o -o tp0

main.o: main.c resolve.h pilha.h
	$(CC) $(CFLAGS) -c main.c

resolve.o: resolve.c resolve.h
	$(CC) $(CFLAGS) -c resolve.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

clean:
	rm -f $(binaries) *.o