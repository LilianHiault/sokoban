#include <stdlib.h>

/* --- Protoypes --- */

void printArr2d(char ** , int, int);

char ** createArr2d(int, int);

void freeArr2d(char **, int);

char ** reverseArr2d(char ** tab, int n, int m);

void remplirTab(char ** tab, int n, int m);


/* --- Functions --- */

char ** createArr2d(int n, int m) {
  // Creates 2 dimensions array
  char ** tab = NULL;
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
      perror("Problème lors de la création du tableau");
      exit(EXIT_FAILURE);
    }
  }
  return tab;
}

void printArr2d(char ** tab, int n, int m)
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

void freeArr2d(char ** tab, int taille){
  int i;
  for(i = 0; i < taille; i++){
    free(tab[i]);
  }
  free(tab);
}

char ** reverseArr2d(char ** tab, int n, int m) {
  int i, j;
  char ** inverse = createArr2d(m, n);
  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++) {
      inverse[i][j] = tab[j][i];
    }
  }
  return inverse;
}

void remplirTab(char ** tab, int n, int m)
// Remplit une matrice
{
  int i,j;
  char valeur;
  for(i = 0; i < n; i++)
  {
    // printf("i%d",i);
    for(j = 0; j < m; j++)
    {
      //printf("j%d",j);
      printf("Valeur de [%d, %d] : ", i, j);
      scanf("%c", &valeur);
      tab[i][j] = valeur;
    }
  }
}
