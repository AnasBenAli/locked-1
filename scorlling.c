#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "locked.h"



void init_lvl1(lvl1* lv1)
{
lv1->ecran.srf[0] = NULL;
lv1->fond.srf[0] = NULL;

lv1->mouse.srf[0]=NULL;
lv1->mouse.pos.x= 0;
lv1->mouse.pos.y= 2500;

lv1->fond.pos.x=0;
lv1->fond.pos.y=0;

lv1->ecran.pos.h=640;
lv1->ecran.pos.w=480;

lv1->s.xscroll= 0;
lv1->s.yscroll= 0;
lv1->s.camera.x=0;
lv1->s.camera.y=2076;
lv1->s.camera.w=640;
lv1->s.camera.h=480;
lv1->s.state[0]=0;
lv1->s.state[1]=0;
lv1->s.state[2]=0;
lv1->s.state[3]=0;

lv1->mouse.blit[0]= 0;
lv1->mouse.blit[1]= 0;
}
void load_lvl1(lvl1* lv1)
{
lv1->fond.srf[0] = IMG_Load("lvl1.png");
lv1->fond.srf[1] = IMG_Load("lvl1.png");
lv1->mouse.srf[0] = IMG_Load("mouse.png");
}

void display_lvl1(lvl1* lv1)
{
SDL_BlitSurface(lv1->mouse.srf[0], NULL, lv1->fond.srf[0],&lv1->mouse.pos);
SDL_BlitSurface(lv1->fond.srf[0], &lv1->s.camera, lv1->ecran.srf[0],NULL);
SDL_Flip(lv1->ecran.srf[0]);
if(lv1->mouse.blit[0] || lv1->mouse.blit[1])
{
SDL_BlitSurface(lv1->fond.srf[1], NULL, lv1->fond.srf[0],NULL);
}
}


int check_input_lvl1(SDL_Event event,lvl1* lv1)
{
const int vitess_cam= 10;

while( SDL_PollEvent( &event ) ){
        switch( event.type ){
/////////////Inpute check/////////////////////////
case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_ESCAPE:
			 return 1;
		break;
		    case SDLK_d:
			 lv1->s.state[0]=1;
			lv1->mouse.blit[0]= 1;
		break;
                    case SDLK_q:
			 lv1->s.state[1]=1;
			lv1->mouse.blit[1]= 1;
		break;
                    case SDLK_s:
			 lv1->s.state[2]=1;
		break;
                    case SDLK_z:
			 lv1->s.state[3]=1;
		break;
                                               }
break;
case SDL_KEYUP:
                switch( event.key.keysym.sym ){
			case SDLK_d:
			lv1->s.state[0]=0;
			lv1->mouse.blit[0]= 0;
			lv1->s.xscroll = 0;
			break;
                        case SDLK_q:
			lv1->s.state[1]=0;
			lv1->mouse.blit[1]= 0;
			lv1->s.xscroll = 0;
			break;
                        case SDLK_s:
			lv1->s.state[2]=0;
			break;
                        case SDLK_z:
			lv1->s.state[3]=0;
			break;
                                              }                                        
break;
}
}
////////Camera control////////////////////
if(lv1->s.state[0])
{
lv1->mouse.pos.x+= vitess_cam;
lv1->s.xscroll+= vitess_cam;
if(lv1->mouse.pos.x >= 320)
{
lv1->s.camera.x+= vitess_cam;
lv1->s.xscroll=180;
}
	if(lv1->s.camera.x > 7360)
		lv1->s.camera.x= 7360;
if(lv1->mouse.pos.x >= 7904)
lv1->mouse.pos.x=7904;
}
	else if(lv1->s.state[1])
{
lv1->mouse.pos.x-=vitess_cam;
lv1->s.xscroll+= vitess_cam;
if(lv1->mouse.pos.x <= 7680)
{
lv1->s.camera.x-= vitess_cam;
lv1->s.xscroll= 180;
}
	if(lv1->s.camera.x< 0)
		lv1->s.camera.x= 0;
}
else if(lv1->s.state[2])
{
lv1->s.yscroll+= vitess_cam;
lv1->s.camera.y+= vitess_cam;
	if(lv1->s.camera.y > 2076)
		lv1->s.camera.y= 2076;
}
else if(lv1->s.state[3])
{
lv1->s.yscroll-= vitess_cam;
lv1->s.camera.y-= vitess_cam;
	if(lv1->s.camera.y< 0)
		lv1->s.camera.y= 0;
}
//////////////////////////////////////////

return 0;
}

void free_srf_lvl1(lvl1* lv1)
{
SDL_FreeSurface(lv1->fond.srf[0]);
SDL_FreeSurface(lv1->fond.srf[1]);
SDL_FreeSurface(lv1->ecran.srf[0]);
SDL_FreeSurface(lv1->mouse.srf[0]);
}
















