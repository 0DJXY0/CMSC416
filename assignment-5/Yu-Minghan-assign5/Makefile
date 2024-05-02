CHARMC      = charmc
OPTS        = -O2

OBJS		= Prefix.o
OBJS_DECL	= prefix.decl.h

all: prefix

prefix: $(OBJS) $(OBJS_DECL)
	$(CHARMC) -o prefix $(OBJS) -language charm++ $(OPTS)

prefix.decl.h: prefix.ci
	$(CHARMC) prefix.ci

Prefix.o: prefix.C prefix.decl.h
	$(CHARMC) $(OPTS) -o Prefix.o prefix.C

clean:
	rm -f *.decl.h *.def.h *.o charmrun prefix

