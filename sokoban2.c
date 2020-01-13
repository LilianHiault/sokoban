#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void fillPlateau(int ** plateau, int largeur, int hauteur, FILE * level);


/* --- Main --- */

int main (int argc, char * argv[]) {
  (void) argc;
  (void) argv;

  printf("Jeu du Sokoban\n");

  // Ouverture du niveau

  int largeur = 10; // Longeur du plateau de jeu
  int hauteur = 10; // Hauteur du plateau de jeu

  const char fileLevel[] = "levels/level1.txt";

  FILE * level = NULL;
  if((level = fopen(fileLevel, "r")) == NULL){
    perror("Problème d'ouverture du fichier de niveau");
    exit(EXIT_FAILURE);
  }

  /* --- Récupérer la taille du niveau --- */
  char buffer[BUFSIZ];
  fgets(buffer, BUFSIZ, level); // buffer contient la première ligne du fichier

  char * token = strtok(buffer, " ");
  int comp = 0;
  while(token != NULL) {
    if(comp == 0){
      largeur = strtol(token, NULL, 10);
      printf("Largeur : %d\n", largeur);

    }
    if(comp == 1) {
      hauteur = strtol(token, NULL, 10);
      printf("Hauteur : %d\n", hauteur);
    }

    comp++;
    token = strtok(NULL, " ");
  }

  // Création du plateau de jeu

      printf("avant \n");
  int ** plateau = createArr2d(largeur, hauteur);

      printf("après \n");
  // Mettre le contenu du niveau dans le plateau de jeu

  fillPlateau(plateau, largeur, hauteur, level);

  printf("\n");
  printArr2d(plateau, largeur, hauteur);

  // Fermeture du fichier niveau

  fclose(level);

  // Libération du plateau de jeu

  freeArr2d(plateau, largeur);

  return 0;
}

void fillPlateau(int ** plateau, int largeur, int hauteur, FILE * level){
  /* --- Mettre le contenu du niveau dans le plateau de jeu --- */
  int carac = 'a';

  int i, j;
    for(i = 0; i < hauteur; i++){
      for(j = 0; j < largeur; j++){
      carac = fgetc(level); // Lit et avance d'un caractère
      printf("%c", carac);
      plateau[j][i] = carac;
    }
    fgetc(level); // Enlève le retour à la ligne
  }
}
