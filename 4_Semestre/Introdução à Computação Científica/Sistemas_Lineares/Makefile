PROG = perfSL
OBJS = main.o toolbox.o EG.o GS.o structs.o utils.o

CC = gcc
CFLAGS = -O0 -DLIKWID_PERFMON -I$(LIKWID_INCLUDE)
LFLAGS = -lm
LDFLAGS = -L$(LIKWID_LIB) -llikwid

DISTFILES = *.c *.h *.dat LEIAME* Makefile script.sh
DISTDIR = `basename ${PWD}`

.PHONY: all clean purge dist

%.o: %.c %.h
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LFLAGS)

clean:
	@rm -f *~ *.bak

purge: clean
	@rm -f $(PROG) $(OBJS) core a.out $(DISTDIR) $(DISTDIR).tar

dist: purge
	@ln -s . $(DISTDIR)
	@tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)
