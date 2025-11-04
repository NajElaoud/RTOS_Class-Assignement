CC=gcc
CFLAGS=-g
LDFLAGS= -lpthread
EXEC=threads

all:$(EXEC)

threads: threads.o
	$(CC) -o threads threads.o $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -rf *.o
mrproper: clean
	rm -rf threads
