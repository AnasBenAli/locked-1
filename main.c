#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include "background.h" 
int main () 
{
SDL_Surface *ecran ; 
  backgrd backg ; 
ecran=SDL_SetVideoMode(1000,800,32,SDL_HWSURFACE) ;
  SDL_Init(SDL_INIT_EVERYTHING); 
  init_backgrd(&backg);  

int done =0 ;
while(!done) 
{
  display(ecran,&backg); 

}
  freegame(&backg);
 return 0;
}
