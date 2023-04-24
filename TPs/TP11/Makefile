CC=gcc
CFLAGS=-Wall -std=c99
EXEC=main
DEPS=fifo.h


SRCFILES := $(wildcard *.c) 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: $(EXEC)

main: $(SRCFILES)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm -rf *.o main
