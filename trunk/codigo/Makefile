OBJ = enrutador.o tipos_impl.o tipos_basicos.o
GCCFLAGS= -g -c -o
CC=g++
MAIN = parser.cpp

.PHONY=clean all

all: clean parser

%.o: %.h
	$(CC) $(GCCFLAGS) $@ $^

parser: parser.o $(OBJ)
	$(CC) $(MAIN) $(GCCFLAGS) $@

clean:
	rm -f *.o

