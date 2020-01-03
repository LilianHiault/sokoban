#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>


/* --- Structures --- */

typedef struct position{
  int x;
  int y;
}position;

struct player{
  position pos;
};


/* --- Functions prototypes --- */

void playerMove();


/* --- Main function --- */

int main (int argc, char * argv[]){
  (void) argc;
  (void) argv;

  printf("Jeu du Sokoban\n");

  return 0;
}
