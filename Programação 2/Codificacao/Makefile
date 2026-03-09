CFLAGS = -std=c99 -Wall

objs = beale.o chave.o codificar.o decodificar.o

all: beale

beale: $(objs)

beale.o: beale.c chave.h codificar.h decodificar.h structs.h
chave.o: chave.c chave.h
codificar.o: codificar.c codificar.h
decodificar.o: decodificar.c decodificar.h

clean:
	-rm -f $(objs) *~

purge: clean
	-rm -f beale
