#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
void init_backgrd(backgrd *backg)
{

backg->back=IMG_Load("/Desktop/background/back.png");
backg->pos.x=0;
backg->pos.y=0;
 
}

void display(SDL_Surface *ecran,backgrd *backg)
{

SDL_BlitSurface(backg->back,NULL, ecran, &backg->pos);
SDL_Flip(ecran);
}

void freegame(backgrd *backg)
{
SDL_FreeSurface(backg->back);
}


