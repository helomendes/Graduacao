PROG = producao
OBJS = main.o func.o 

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

purge: clean
	@echo "Faxina..."
	@rm -f $(PROG) *.o a.out 
	@rm -f *.png marker.out


