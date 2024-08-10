parametrosCompilacao = -Wall
nomePrograma = vina++

all: $(nomePrograma)

$(nomePrograma): main.o arquivar.o
	gcc -o $(nomePrograma) main.o arquivar.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

arquivar.o: arquivar.c arquivar.h
	gcc -c arquivar.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)

purge:
	rm -f *.o *.gch *.txt $(nomePrograma)