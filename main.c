#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "locked.h"

int main()
{
  float time;
  timer t;
   SDL_Event event;
   menu_buttons test;
   lvl1 lv1;
   SFX snd;
int a;
   SDL_Init(SDL_INIT_EVERYTHING);
int i;
   init(&test,&snd);
   load(&test,&snd);
   init_lvl1(&lv1);
   load_lvl1(&lv1);
   test.ecran.srf[0] = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF|SDL_SWSURFACE);
TTF_Init();

SDL_Color Colorfont = {255,255,255};
TTF_Font *police = NULL;
SDL_Surface *text;
SDL_Rect rect_text;
police = TTF_OpenFont("Game project/fonts/pencilgrid.ttf",22); 
text = TTF_RenderText_Blended(police, "All Rights Reserved, Copyright @ 2019 by OmegaSquad",Colorfont); 
rect_text.x = 200; 
rect_text.y = 450;

   int done=0,check_window=0, choice=0;
 while(!done)
{

   t.start= SDL_GetTicks();

   display(&test,&check_window);
   SDL_BlitSurface(text,NULL,test.ecran.srf[0],&rect_text);
   done= check_input(event,&choice,&test,&snd,&check_window);

   t.end= SDL_GetTicks();
   t.diff+= t.end-t.start;
if(t.diff>= 120)
{
	t.diff=0;
	test.imageDeFond.current_frame++;
if(test.imageDeFond.current_frame > 7)
test.imageDeFond.current_frame=0;
}

}
for(i=0;i<7;i++)
{
SDL_FreeSurface(test.imageDeFond.srf[i]); 
}
SDL_FreeSurface(test.start.srf[0]);
SDL_FreeSurface(test.settings.srf[0]);
SDL_FreeSurface(test.title.srf[0]);
SDL_FreeSurface(test.exit.srf[0]);
SDL_FreeSurface(test.curseur.srf);
SDL_Quit();
if(test.lvl_play[0])
{
done= 0;
TTF_Init();
lv1.ecran.srf[0] = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF|SDL_SWSURFACE); 
while(!done)
{
   t.start= SDL_GetTicks();
   deplacer_aleatoire_ennemi(&lv1.mouse,&lv1.perso);
   display_lvl1(&lv1);
   done=check_input_lvl1(event,&lv1);



   t.end= SDL_GetTicks();
   t.diff+= t.end-t.start;


if(t.diff>= 100 && (lv1.s.state[1] || lv1.s.state[0]))
{
	t.diff=0;
	lv1.perso.current_frame++;
}
if(lv1.perso.current_frame > 6 && lv1.s.state[0])
lv1.perso.current_frame=0;
if(lv1.perso.current_frame > 13  && lv1.s.state[1])
lv1.perso.current_frame= 7;

}
}
free_srf_lvl1(&lv1);
time=SDL_GetTicks()/1000;
printf("Time passed: %.3fs\n",time);
return 0;
}
