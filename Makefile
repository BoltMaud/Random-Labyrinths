C=gcc
CFLAGS=-Wall -g
IFLAGS=-Iinclude
OPATH=./obj
CPATH=./src

vpath %.h include
vpath %.c src
vpath %.o obj

main : main.o lab.o chemin.o io.o jeu.o
	$(C) $(CFLAGS) -o $@ $(OPATH)/*.o

main.o : main.c lab.c lab.h chemin.h
jeu.o: jeu.c jeu.h chemin.h lab.h
lab.o : lab.c lab.h
chemin.o : chemin.c chemin.h lab.h
io.o: io.c io.h lab.h

%.o :
	$(C) $(CFLAGS) -c $< $(IFLAGS)
	mv $@ $(OPATH)

clean:
	rm -rf obj/* main


Archive:
	tar -cvz src/* obj Makefile include/* Bolten* -f Lab_BOLTENHAGEN.tar.gz
