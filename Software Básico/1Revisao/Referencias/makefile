PROGRAMAS= somaVetor

all: $(PROGRAMAS)

somaVetor: somaVetor.o
	ld somaVetor.o -o somaVetor -dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 -lc
	
somaVetor.o: somaVetor.s
	as somaVetor.s -o somaVetor.o

clean:
	rm -rf *.o $(PROGRAMAS)
