CC = g++
SRCS = src/queue.h
OPTS = -std=c++17
INC = -I src/
TR1 = bin/jm-signal.exe
TR2 = bin/jm-pipe.exe
TR3 = bin/jm-receive.exe
TR4 = bin/jm-shc.exe
TR5 = bin/jm-mqc.exe

OBJS = $(TR1) $(TR2) $(TR3) $(TR4) $(TR5)

LIBS = -pthread -lrt

all: $(TR1) $(TR2) $(TR3) $(TR4) $(TR5)

$(TR1):	signal.cpp
	$(CC) $(OPTS) $< -o $@ $(LIBS)
$(TR2):	pipe.cpp
	$(CC) $(OPTS) $< -o $@ $(LIBS)
$(TR3):	receive.cpp
	$(CC) $(OPTS) $< -o $@ $(LIBS)
$(TR4):	shc.cpp
	$(CC) $(OPTS) $< -o $@ $(LIBS)
$(TR5):	mqc.cpp
	$(CC) $(OPTS) $< -o $@ $(LIBS)

clean:
	rm -f $(OBJS) bin/data
