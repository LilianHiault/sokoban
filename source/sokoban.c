#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_types.h>
#include <time.h>

#include "2darr.h"


/* --- Structures --- */

typedef struct pos{
  int x;
  int y;
}pos;


/* --- Prototypes de fonction --- */

void initPlateau(char ** plateau, int largeur, int hauteur, FILE * level);


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

  char ** plateau = createArr2d(largeur, hauteur);

  // Mettre le contenu du niveau dans le plateau de jeu

  initPlateau(plateau, largeur, hauteur, level);
  printf("\n");
  printArr2d(plateau, largeur, hauteur);
  plateau[9][7] = 'D';
  plateau[0][0] = 'A';
  printArr2d(plateau, largeur, hauteur);

  // Fermeture du fichier niveau

  fclose(level);

  // Libération du plateau de jeu

  freeArr2d(plateau, largeur);

  return 0;
}

void initPlateau(char ** plateau, int largeur, int hauteur, FILE * level){
  /* --- Mettre le contenu du niveau dans le plateau de jeu --- */
  int i, j;
  for(i = 0; i < hauteur; i++){
    for(j = 0; j < largeur; j++){
      plateau[i][j] = fgetc(level); // Lit et avance d'un caractère
    }
    fgetc(level); // Enlève le retour à la ligne
  }
}
