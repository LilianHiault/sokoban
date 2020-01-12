#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include<SDL_types.h>
#include<time.h>
#include<string.h>

typedef struct pos{
  int x;
  int y;
}pos;


#define LC 32



//Fonctionnement
SDL_Event pause();
void trouvePerso(char ** TJeu,int ,int,pos * perso,char* caseInit);
void afficheTab2D(char **, int ,int);
void deplacement(char** TJeu,int,int);
void bouge(char**,char,int,int,pos * posPrev,pos * posSuiv);
void victoire(char**,int,int,int*);

// Affichage
void dessine(SDL_Surface*);
void dessineTJeu(char ** TJeu, int ,int);



SDL_Surface * Brique = NULL;
SDL_Surface * Michel = NULL;
SDL_Surface * ON = NULL;
SDL_Surface * OFF = NULL;
SDL_Surface * MichelPoint = NULL;
SDL_Surface * Point = NULL;
SDL_Surface * ecran = NULL;
SDL_Surface * rectangle = NULL;
SDL_Surface * carre = NULL;
SDL_Rect position;


int main(){
  int hauteur = 4;
  int largeur =7;
  int i,j;
  int WIDTH =  largeur * LC;
  int HEIGHT= hauteur * LC;
  if(SDL_Init(SDL_INIT_VIDEO) == 1){
    fprintf(stderr,"Erreur SDL : %s\n",SDL_GetError());
    return -1;
  }

  if(( ecran = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE)) == NULL){
    fprintf(stderr,"Erreur VideoMode : %s\n",SDL_GetError());
    exit(EXIT_FAILURE);}


  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,150,200,175));
  SDL_Flip(ecran);
  OFF =  SDL_LoadBMP("interrupteurOff.bmp");
  ON =  SDL_LoadBMP("interrupteurOn.bmp");
  Brique = SDL_LoadBMP("Bloc.bmp");
  Michel = SDL_LoadBMP("Michel2.bmp");
  MichelPoint = SDL_LoadBMP("MichelPoint.bmp");
  Point = SDL_LoadBMP("Point.bmp");


  
  SDL_WM_SetCaption("SokobanBV",NULL);
  SDL_Flip(ecran);
  
  char** TJeu =(char**) malloc(largeur*sizeof(char*));
  for(i=0; i<largeur;i++){
  TJeu[i]=   (char*) malloc((hauteur+1)*sizeof(char));
  }
  for(i = 0; i < largeur; i++)
  {
    for(j = 0; j < hauteur; j++)
    {
       TJeu[i][j]=' ';
    }
    TJeu[i][2]='#';
  }
  TJeu[3][3]='P';
  TJeu[2][2]='I';
  TJeu[1][1]='C';
  TJeu[5][0]='I';
  TJeu[4][1]='C';
  TJeu[4][2]=' ';
  TJeu[5][2]=' ';
  
  

  
  deplacement(TJeu,hauteur,largeur);
  SDL_FreeSurface(ecran);
  SDL_Quit();
  free(TJeu);
  
  return 0;}

void trouvePerso(char ** TJeu,int hauteur,int largeur,pos * perso,char* caseInit){
  // position perso;
  perso->x=0;
  perso->y=0;
  
  int i,j;
  for(i = 0; i < largeur; i++)
  {
    for(j = 0; j < hauteur; j++)
      {
        if(TJeu[i][j]=='p' || TJeu[i][j]=='P'){
	  perso->x = j;
	  perso->y = i;
	}
      }
  }
  caseInit=&TJeu[perso->y][perso->x];
  //printf("position=%d %d\n",perso->x,perso->y);
}
    

void afficheTab2D(char ** tab, int hauteur,int largeur)
{
  int i,j;
  for(i = 0; i < hauteur; i++)
  {
    printf("\n");
    for(j = 0; j < largeur; j++)
    {
      printf("%c  ", tab[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}


	
SDL_Event pause(){
  // printf("oijio");
  int cont=1;
  SDL_Event event;
  while( cont){
    SDL_WaitEvent(&event);
    switch(event.type){
    case SDL_QUIT:
      cont=0;
      break;
    case SDL_KEYDOWN:
      cont=0;
      break;
    default:
      cont=1;
    }
  }
  return(event);
}

void deplacement(char** TJeu,int hauteur,int largeur){
  int cont=1 ;
  char* change= (char*) malloc((hauteur+1)*sizeof(char));
  SDL_Event event ;
  pos perso;
  pos posPrev;
  pos caisse;
  char nouvCase;
  char exCase;
  
  trouvePerso(TJeu,hauteur,largeur,&perso,&nouvCase);
  afficheTab2D(TJeu,hauteur,largeur);
  while(cont){
    posPrev= perso;
    exCase=nouvCase;
    printf("position=%d %d\n",perso.x,perso.y);
    printf("position=%d %d\n",posPrev.x,posPrev.y);
    event= pause();
    
    switch(event.type){
    case SDL_QUIT:
      cont=0;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
	
      case SDLK_UP:
	if(perso.y>0){ 
	  perso.y--;
	}
	break ;
	
      case SDLK_DOWN:
	if(perso.y<hauteur-1){
	  perso.y++;
	}
	break ;
	
      case SDLK_LEFT :
	if(perso.x>0){    
	  perso.x--;
	}
	break ;
	
      case SDLK_RIGHT:
	if(perso.x<largeur-1){
	  perso.x++;
	}
	break ;

      case 'q':
	cont=0 ;
	break ;
      }
    }


    
    if( TJeu[perso.x][perso.y]=='C' ||TJeu[perso.x][perso.y]=='c' ){
      caisse.x = perso.x + (perso.x - posPrev.x);
      caisse.y = perso.y + (perso.y - posPrev.y);
      if(caisse.x <largeur && caisse.x >=0 && caisse.y >=0 && caisse.y <hauteur){
      bouge(TJeu, TJeu[perso.x][perso.y], hauteur, largeur,  &perso , &caisse);
      }
      
    }
    bouge(TJeu, TJeu[posPrev.x][posPrev.y], hauteur, largeur,  &posPrev,&perso);

    
    afficheTab2D(TJeu,hauteur,largeur);   
    dessineTJeu(TJeu,hauteur,largeur);

      
    if(cont){
      victoire(TJeu,hauteur,largeur,&cont);
      if( cont-1){
	printf("Victoire !!\n");
      }
    }
  }
  
}


void bouge(char** TJeu,char objet,int hauteur,int largeur, pos * posPrev, pos * posSuiv){

  char nouvCase =objet ;
  char exCase = objet;
  char* change= (char*) malloc((hauteur+1)*sizeof(char));
  
  if(posSuiv->x < largeur && posSuiv->y >= 0 && posSuiv->x >=0 && posSuiv->y < hauteur){
    
    //   printf("a");
    if(TJeu[posSuiv->x][posSuiv->y]!='#' && TJeu[posSuiv->x][posSuiv->y]!='C'  && TJeu[posSuiv->x][posSuiv->y]!='c' ){
      
      
      //    printf("b");
      
      if((objet=='c' ||objet== 'p') && TJeu[posSuiv->x][posSuiv->y]==' '){
	nouvCase=objet-32;
	exCase='I';
        
	
	
      }
      else if((objet=='C' ||objet== 'P') && TJeu[posSuiv->x][posSuiv->y]=='I'){
	nouvCase=objet+32;
	exCase=' ';
	
	
      }
      else if((objet=='C' ||objet== 'P') && TJeu[posSuiv->x][posSuiv->y]==' '){

	nouvCase=objet;
	exCase=' ';
	
      
      }
      else if((objet=='c' ||objet== 'p') && TJeu[posSuiv->x][posSuiv->y]=='I'){

	nouvCase=objet;
	exCase='I';
      }


      
    }
    else{
      posSuiv->x = posPrev->x;
      posSuiv->y = posPrev->y;
      exCase = objet;
      nouvCase = objet;
    
    }
    
    //   printf("ex %c nouv%c",exCase,nouvCase);
  }
  else{
    posSuiv->x = posPrev->x;
    posSuiv->y = posPrev->y;
    exCase = objet;
    nouvCase = objet;
      
    //    printf("e0x %c nouv%c",exCase,nouvCase);
  }
  
  
  strcpy(change,TJeu[posPrev->x]);
  change[posPrev->y]=exCase;  
  strcpy(TJeu[posPrev->x],change);
  
  
  strcpy(change,TJeu[posSuiv->x]);
  change[posSuiv->y]=nouvCase;  
  strcpy(TJeu[posSuiv->x],change);
  free(change);
  
}

void victoire(char** TJeu, int hauteur,int largeur, int* cont){
  int i=0;
  int j=0;
  int reste = 1;
  *cont=0;
  
  while(i<largeur && reste){
    // printf("\ni%d\n",i);
    while(j<hauteur && reste){
      //  printf("j%d\n",j);
      if((TJeu[i][j]=='I'|| TJeu[i][j]=='p') && reste){
	reste=0;
	*cont=1;
	//printf("i %d j%d fin %d",i,j,*cont);
      }
      j++;
    }
    j=0;
    i++;
  }
  // printf("in victoire %d \n",*cont);

}


  void dessine(SDL_Surface * s){
    SDL_BlitSurface(s,NULL,ecran,&position) ;
    SDL_Flip(ecran) ;
  }

void dessineTJeu(char ** TJeu,int hauteur, int largeur){

  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,150,200,175));
  for(int i=0 ; i<largeur;i ++){
    position.x=i*LC;
    for(int j=0; j<hauteur; j++){
      position.y=j *LC;
      // printf("%d %d\n",i,j);
      if(TJeu[i][j]=='#'){
	//SDL_BlitSurface(Brique,NULL,ecran,&position) ;
	dessine(Brique);}
      else if(TJeu[i][j]=='C'){
	//	SDL_BlitSurface(OFF,NULL,ecran,&position) ;}
	
	dessine(OFF);}
      else if(TJeu[i][j]=='c'){
	//SDL_BlitSurface(ON,NULL,ecran,&position) ;}
	dessine(ON);}
      else if(TJeu[i][j]=='P'){
	//SDL_BlitSurface(Michel,NULL,ecran,&position) ;}
	dessine(Michel);}
      else if(TJeu[i][j]=='p'){
	//SDL_BlitSurface(Michel,NULL,ecran,&position) ;}
	dessine(MichelPoint);}
      else if(TJeu[i][j]=='I'){
	//SDL_BlitSurface(Michel,NULL,ecran,&position) ;}
	dessine(Point);}
    }
  }

SDL_Flip(ecran);
//pause();
}
