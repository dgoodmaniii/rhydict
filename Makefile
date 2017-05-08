# +AMDG  This document was begun on 3 May 1201, the feast
# of St. Juvenal, EC, and it is humbly dedicated to him and
# to the Immaculate Heart of Mary for their prayers, and to
# the Sacred Heart of Jesus for His mercy.
#
#  (C) Copyright 2017  Donald P. Goodman III
# 
#  This file is part of rhydict.
# 
#  rhydict is free software:  you can redistribute it and/or
#  modify it under the terms of the GNU General Public
#  License as published by the Free Software Foundation,
#  either version 3 of the License, or (at your option) any
#  later version.
# 
#  rhydict is distributed in the hope that it will be
#  useful, but WITHOUT ANY WARRANTY; without even the
#  implied warranty of MERCHANTABILITY or FITNESS FOR A
#  PARTICULAR PURPOSE.  See the GNU General Public License
#  for more details.
# 
#  You should have received a copy of the GNU General Public
#  License along with rhydict.  If not, see
#  <http://www.gnu.org/licenses/>.

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
