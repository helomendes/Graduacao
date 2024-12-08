PROG = producao
OBJS = main.o input.o linprog.o 

CC = gcc -Wall

.PHONY: all debug clean purge

%.o: %.c %.h
	$(CC) -c $<

all: $(PROG)

debug: -g -D_DEBUG_
debug: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^

clean:
	@echo "Limpando..."
	@rm -f *~ *.bak *.tmp core
	@rm -f output.txt

purge: clean
	@echo "Faxina..."
	@rm -f $(PROG) *.o a.out 
	@rm -f *.png marker.out


