CC=gcc
FLAGS= -Wall -Wextra -g
OBJETS= sokoban.o

all:sokoban

sokoban:$(OBJETS) 2darr.h
	$(CC) $(FLAGS) `sdl-config --libs` -o $@ $(OBJETS)

sokoban.o:sokoban.c
	$(CC) $(FLAGS) `sdl-config --cflags` -c $<

clean:
	rm -f $(OBJETS)
