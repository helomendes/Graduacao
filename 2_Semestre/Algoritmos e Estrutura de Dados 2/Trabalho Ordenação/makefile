parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: trab

$(nomePrograma): main.o ordenacao.o auxiliares.o
	gcc -o $(nomePrograma) main.o ordenacao.o auxiliares.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

auxiliares.o: auxiliares.h auxiliares.c
	gcc -c auxiliares.c $(parametrosCompilacao)
clean:
	rm -f *.o *.gch $(nomePrograma)
