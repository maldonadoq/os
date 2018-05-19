CC = gcc
OPTS = -O
OBJS = bin/shmp.exe bin/shmc.exe bin/mqc.exe
LIBS = -lrt

all: shmp shmc mqc

help:
	@echo [1] shmp create share memory - [bucle to receive data].
	@echo [2] shmc read share memory and send data to mqc.
	@echo [3] mqc receive mqc data and print. [press enter]

shmp:
	$(CC) $(OPTS) -o bin/shmp.exe src/shmp.c $(LIBS)
shmc:
	$(CC) $(OPTS) -o bin/shmc.exe src/shmc.c $(LIBS)
mqc:
	$(CC) $(OPTS) -o bin/mqc.exe src/mqc.c $(LIBS)
clean:
	rm -f $(OBJS)