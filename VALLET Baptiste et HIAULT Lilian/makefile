CC=gcc
FLAGS= -g
OBJETS= sokoban.o

all:sokoban

sokoban:$(OBJETS) 2darr.h
	$(CC) $(FLAGS) -o $@ $(OBJETS) `sdl-config --libs`

sokoban.o:sokoban.c
	$(CC) $(FLAGS) `sdl-config --cflags` -c $<

clean:
	rm -f $(OBJETS)
