CC=g++
CFLAGS= -c -Wall -ansi -pedantic `sdl-config --cflags`
LDFLAGS= `sdl-config --libs`
EXEC=Bomberman

all: $(EXEC)

Bomberman: case.o terrain.o bombe.o bomberman.o ennemi.o liste.o dennemis.o jeu.o final.o main.o
	$(CC) -o Bomberman case.o terrain.o bombe.o bomberman.o ennemi.o liste.o dennemis.o jeu.o final.o main.o $(LDFLAGS)

case.o: case.cpp case.h
	$(CC) case.cpp $(CFLAGS)

terrain.o: terrain.cpp terrain.h case.h
	$(CC) terrain.cpp $(CFLAGS)

bombe.o: bombe.cpp bombe.h terrain.h 
	$(CC) bombe.cpp $(CFLAGS)

bomberman.o: bomberman.cpp bomberman.h bombe.h
	$(CC) bomberman.cpp $(CFLAGS)

ennemi.o: ennemi.cpp ennemi.h bombe.h
	$(CC) ennemi.cpp $(CFLAGS)

liste.o: listedoublechainee.cpp liste.h
	$(CC) -o liste.o listedoublechainee.cpp $(CFLAGS)

dennemis.o: dennemis.cpp dennemis.h ennemi.h liste.h
	$(CC) dennemis.cpp $(CFLAGS)

jeu.o: jeu.cpp dennemis.h jeu.h
	$(CC) jeu.cpp $(CFLAGS)

final.o: final.cpp final.h jeu.h
	$(CC) final.cpp $(CFLAGS) 

main.o: main.cpp final.h
	$(CC) main.cpp $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

execute:
	@./$(EXEC)
