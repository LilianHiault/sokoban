#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes>

#include "2darr.h"


/* --- Structures --- */

typedef struct position{
  int x;
  int y;
}position;

struct player{
  position pos;
};


/* --- Prototypes de fonction --- */

void playerMove();


/* --- Main --- */

int main (int argc, char * argv[]) {
  (void) argc;
  (void) argv;

  printf("Jeu du Sokoban\n");

  // Ouverture du niveau

  int largeur = 10; // Longeur du plateau de jeu
  int hauteur = 10; // Hauteur du plateau de jeu

  FILE * level = NULL;
  if((level = fopen("levels/level1.txt", "r")) == NULL){
    perror("Problème d'ouverture du fichier de niveau");
    exit(EXIT_FAILURE);
  }

  char buffer[BUFSIZ];
  fgets(buffer, BUFSIZ, level); // buffer contient la première ligne du fichier

  char * token = strtok(buffer, " ");
  while(token != NULL) {
    printf("Token : %s\n", token);

    largeur = strtoi(token, NULL);
    hauteur = strtoi(token, NULL);
    printf("Largeur : %d", largeur);
    printf("Hauteur : %d", hauteur);

    token = strtok(NULL, " ");
  }

  // Fermeture du fichier niveau

  fclose(level);

  // Création du plateau de jeu

  int ** plateau = createArr2d(largeur, hauteur);

  // Libération du plateau de jeu

  freeArr2d(plateau, largeur);

  return 0;
}
