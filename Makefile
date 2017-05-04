# +AMDG  This document was begun on 3 May 1201, the feast
# of St. Juvenal, EC, and it is humbly dedicated to him and
# to the Immaculate Heart of Mary for their prayers, and to
# the Sacred Heart of Jesus for His mercy.

prefix ?= /usr/local
bindir ?= $(prefix)/bin
binmode = 755
dirmode = 755
IDIR =../include
CC = gcc
binobjects = rhydict

all: bin

rhydict : main.o data.h data.o exit_codes.h
	$(CC) -o rhydict main.o data.o

main.o : main.c data.h data.o exit_codes.h
	$(CC) -c main.c

data.o : data.c data.h
	$(CC) -c data.c

bin: $(binobjects)

installbin: $(binobjects)
	for obj in $(binobjects) ; do \
		install -m $(binmode) $${obj} $(bindir) ; done

install: installbin

uninstall:
	for bin in $(binobjects) ; do \
		unlink $(bindir)/$${bin} ; done

clean:
	for obj in $(binobjects) $(objects) ; do \
		rm -f $${obj} ; done

.PHONY: bin clean install installbin uninstall

