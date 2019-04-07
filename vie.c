#include <SDL/SDL.h>

#include "vie.h"

#include <SDL/SDL_image.h>

#include <stdio.h>

#include <stdlib.h>

void intialiser_vie (vie *v)
{


v->positionvie.x=500;
v->positionvie.y=0; 

v->positiongameover.x=0; 
v->positiongameover.y=0 ; 
v->nbr = 3 ; 
v->vie3=IMG_Load ("vie0.png");
v->vie2=IMG_Load ("vie1.png"); 
v->vie1=IMG_Load ("vie2.png") ; 
v->vie0=IMG_Load ("vie3.png") ; 



}


void gestion_vie (vie *v, int enigme , SDL_Surface *screen )
{

SDL_BlitSurface (v->vie0,NULL,screen,&(v->positionvie));


if (enigme == 1) 
{ 
 {v->nbr--; 

 SDL_BlitSurface (v->vie1,NULL,screen,&(v->positionvie));} }


if (enigme == 1 ) 
 
 {  v->nbr-- ; 

  SDL_BlitSurface (v->vie2,NULL,screen,&(v->positionvie));} 

if (enigme == 1 ) 

 {v->nbr--; 

SDL_BlitSurface (v->vie3,NULL,screen,&(v->positiongameover)) ;}
}


































