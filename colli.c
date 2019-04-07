#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <math.h>  
#include "colli.h"
int collision_trigo(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE)
{ SDL_Surface *screen;
    E=IMG_Load("mario.png"); 
 P=IMG_Load("Fleur.png"); 
 screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);  
posE.x = 200 ; 
posE.y = 200 ;  
posP.x = 300 ; 
posP.y = 300 ;
cercle C1,C2; 
int d ;
C1.x=posP.x+P->w/2;
C1.y=posP.y+P->h/2;

C2.x=posE.x+E->w/2;
C2.y=posE.y+E->h/2;


C1.rayon=P->h/2;
C2.rayon=E->h/2;


d =sqrt((C1.x-C2.x)*(C1.x-C2.x) + (C1.y-C2.y)*(C1.y-C2.y));
   if (d > (C1.rayon + C2.rayon))

      return 0;

   else

      return 1; 
   
      SDL_BlitSurface(E, NULL, screen, & posE); 
      SDL_BlitSurface(P, NULL, screen, & posP); 
       SDL_Flip(screen) ;

}
