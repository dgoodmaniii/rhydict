# +AMDG  This document was begun on 3 May 1201, the feast
# of St. Juvenal, EC, and it is humbly dedicated to him and
# to the Immaculate Heart of Mary for their prayers, and to
# the Sacred Heart of Jesus for His mercy.

prefix ?= /usr/local
bindir ?= $(prefix)/bin
mandir ?= $(prefix)/share/man
binmode = 755
dirmode = 755
manmode = 644
CC = gcc
objects = main.o data.o
binobjects = rhydict
docobjects = rhydict.1

all: bin

rhydict : main.o data.h data.o exit_codes.h
	$(CC) -g -o rhydict main.o data.o

main.o : main.c data.h data.o exit_codes.h
	$(CC) -c -g main.c

data.o : data.c data.h
	$(CC) -c -g data.c

bin: $(binobjects)

installbin: $(binobjects)
	install -m $(binmode) $(binobjects) $(bindir)

installdoc:
	install -m $(manmode) $(docobjects) $(mandir)

install: installbin installdoc

uninstall:
	unlink $(bindir)/$(binobjects)
	unlink $(mandir)/$(docobjects)

clean:
	for obj in $(binobjects) $(objects) ; do \
		rm -f $${obj} ; done

.PHONY: bin clean install installbin uninstall installdocs
