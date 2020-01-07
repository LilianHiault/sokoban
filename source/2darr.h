/* --- Protoypes --- */

void fillArr2d(int **, int);

void printArr2d(int ** , int);

int ** createArr2d(int, int);

void freeArr2d(int **, int);


/* --- Functions --- */

float ** createArr2d(int n, int m){
  // Create 2 dimensions array
  float ** tab = NULL;
  if ((tab = (float **)malloc(n * sizeof(float *)) == NULL)){
    free(tab);
    tab = NULL;
  }

  int i, k;
  for(i = 0; i < n; i++){
    if ((tab[i] = (float *)malloc(m * sizeof(float)) == NULL)){
      for(k = 0; k <= i; k++){
        free(tab[k]);
      }
      free(tab);
      break;
    }
  }
  return tab;
}

void fillArr2d(int ** tab, int n, int m)
// Asks for values to fill a 2 dimensions array
{
  int i,j;
  int valeur = 0;
  for(i = 0; i < n; i++)
  {
    // printf("i%d",i);
    for(j = 0; j < m; j++)
    {
      //printf("j%d",j);
      printf("[%d, %d]: ", i + 1, j + 1);
      scanf("%d", &valeur);
      tab[i][j] = valeur;
    }
  }
}

void printArr2d(int ** tab, int n, int m)
// Prints a 2 dimensions array
{
  int i,j;
  for(i = 0; i < n; i++)
  {
    printf("\n");
    for(j = 0; j < m; j++)
    {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void freeArr2d(tab **, taille){
  int i;
  for(i = 0; i < taille; i++){
    free(tab[i]);
  }
  free(tab);
}
