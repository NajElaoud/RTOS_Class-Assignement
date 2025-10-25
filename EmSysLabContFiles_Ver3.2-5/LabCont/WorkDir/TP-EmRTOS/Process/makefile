CC=gcc
CFLAGS=-W  #-g
LDFLAGS= -lpthread
EXEC=process status PrintPIDStatus

all: $(EXEC)

process: process.o
	$(CC) -o $@ $^ $(LDFLAGS)
status: status.o
	$(CC) -o $@ $^ $(LDFLAGS)
PrintPIDStatus: PrintPIDStatus.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -rvf *.o
mrproper: clean
	rm -rvf $(EXEC)

