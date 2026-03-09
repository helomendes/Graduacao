parametrosComparacao=-Wall #-Wshadow
nomePrograma=deburger

all: $(nomePrograma)

$(nomePrograma): main.o mapa.o filacerto.o pilhascerto.o cores.o
	gcc -o $(nomePrograma) main.o mapa.o filacerto.o pilhascerto.o cores.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

mapa.o: mapa.h mapa.c
	gcc -c mapa.c $(parametrosCompilacao)

filacerto.o: filacerto.h filacerto.c
	gcc -c filacerto.c $(parametrosCompilacao)

pilhascerto.o: pilhascerto.h pilhascerto.c
	gcc -c pilhascerto.c $(parametrosCompilacao)

cores.o: cores.h cores.c 
	gcc -c cores.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
