#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
typedef struct 
{ int x,y;
   float rayon  ; 

} cercle ; 
int collision_trigo(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE) ;
#endif // HEADERNAME_H_INCLUDED
