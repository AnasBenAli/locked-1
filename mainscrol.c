#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "locked.h"

int main()
{
SDL_Event event;
lvl1 lv1;
int done=0;

SDL_Init(SDL_INIT_EVERYTHING);

init_lvl1(&lv1);
load_lvl1(&lv1);
////
////
lv1.ecran.srf[0] = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);


while(!done)
{
display_lvl1(&lv1);
done=check_input_lvl1(event,&lv1);
}
free_srf_lvl1(&lv1);

return 0;
}
