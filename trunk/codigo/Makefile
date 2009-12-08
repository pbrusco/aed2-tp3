GCCFLAGS= -g -o
CC=g++

.PHONY=clean all

all: clean parser

parser: parser.cpp
	$(CC) $< $(GCCFLAGS) $@

clean:
	rm -f parser
