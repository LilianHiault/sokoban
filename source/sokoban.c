#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "2darr.h"


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

  // Création du plateau de jeu

  int n = 10; // Longeur du plateau de jeu
  int m = 10; // Largeur du plateau de jeu

  int ** plateau = createArr2d(n, m);

  // Libération du plateau de jeu

  freeArr2d(plateau, n);

  return 0;
}
