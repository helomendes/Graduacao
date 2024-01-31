PROGRAMAS= area

all: $(PROGRAMAS)

area: area.o
	ld area.o -o area -dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 -lc
	
area.o: area.s
	as area.s -o area.o

clean:
	rm -rf *.o $(PROGRAMAS)
