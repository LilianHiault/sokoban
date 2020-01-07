/* --- Protoypes --- */

void fillArr(int **, int);

void printArr(int ** , int);


/* --- Functions --- */

void fillArr(int ** tab, int taille)
// Asks for values to fill a 2 dimensions array
{
  int i,j;
  int valeur = 0;
  for(i = 0; i < taille; i++)
  {
    // printf("i%d",i);
    for(j = 0; j < taille; j++)
    {
      //printf("j%d",j);
      printf("Valeur de [%d, %d] : ", i + 1, j + 1);
      scanf("%d", &valeur);
      tab[i][j] = valeur;
    }
  }
}

void printArr(int ** tab, int taille)
// Prints a 2 dimensions array
{
  int i,j;
  for(i = 0; i < taille; i++)
  {
    printf("\n");
    for(j = 0; j < taille; j++)
    {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
