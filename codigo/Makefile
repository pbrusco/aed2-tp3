GCCFLAGS= -g -o
CC=g++

.PHONY=clean all

parser: parser.cpp
	$(CC) $< $(GCCFLAGS) $@

all: clean parser

clean:
	rm -f *.o
	rm -f parser
