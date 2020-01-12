#include <stdlib.h>

/* --- Protoypes --- */

void printArr2d(int ** , int, int);

int ** createArr2d(int, int);

void freeArr2d(int **, int);


/* --- Functions --- */

int ** createArr2d(int n, int m){
  // Creates 2 dimensions array
  int ** tab = NULL;
  tab = malloc(n * sizeof(*tab));
  if (tab == NULL){
    perror("Problème lors de la création du tableau");
    exit(EXIT_FAILURE);
  }

  int i, k;
  for(i = 0; i < n; i++){
    tab[i] = malloc(m * sizeof(*tab[i]));
    if (tab[i] == NULL){
      for(k = 0; k <= i; k++){
        free(tab[k]);
      }
      free(tab);
      break;
    }
  }
  return tab;
}

void printArr2d(int ** tab, int n, int m)
// Prints a 2 dimensions array
{
  int i,j;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      printf("%c", tab[i][j]);
    }
    printf("\n");
  }
}

void freeArr2d(int ** tab, int taille){
  int i;
  for(i = 0; i < taille; i++){
    free(tab[i]);
  }
  free(tab);
}
