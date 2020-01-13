CC=gcc
FLAGS= -Wall -Wextra -g
OBJETS= sokoban.o

all:sokoban

sokoban:$(OBJETS)
	$(CC) $(FLAGS) -o $@ $(OBJETS)

sokoban.o:sokoban.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJETS)
