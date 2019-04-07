#ifndef _VIE_H
#define _VIE_H
#include <SDL/SDL.h>

int k;
typedef struct vie
{
	SDL_Surface *vie0 ; 
SDL_Surface *vie1 ;
SDL_Surface *vie2 ; 
SDL_Surface *vie3 ;
SDL_Rect positionvie;
SDL_Rect positiongameover ; 
int nbr;

} vie ;
void intialiser_vie (vie *v);

void gestion_vie (vie *v, int collision_trigo,SDL_Surface *screen) ;

#endif
