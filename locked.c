#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "locked.h"


int check_input(SDL_Event event, int* choice, menu_buttons* test,SFX* snd,int *check_window)
{
int test_sound;
while( SDL_PollEvent( &event ) ){
        switch( event.type ){
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){

			case SDLK_UP:
				test->curseur.current_pos--;
				if(test->curseur.current_pos < 0)
					test->curseur.current_pos = 2;
			break;

			case SDLK_DOWN:
				test->curseur.current_pos++;
				if(test->curseur.current_pos > 2)
					test->curseur.current_pos = 0;

			break;
			
			case SDLK_SPACE:
				if(test->curseur.current_pos== 0)
					{
					//*check_window= 1;
					test->lvl_play[0]= 1;
					return 1;
					}
				if(test->curseur.current_pos== 2)
					return 1;
			break;

			case SDLK_ESCAPE:
				if(*check_window== 1)
					*check_window=0;
			break;
					      }
	     case SDL_KEYUP:
			switch( event.key.keysym.sym ){
				case SDLK_SPACE:
					
				break; 
						      }
		break;
                    case SDL_MOUSEMOTION:

if(distance(event.motion.x,test->start.pos.x+test->start.srf[0]->w,test->start.pos.x) && distance(event.motion.y,test->start.pos.y+test->start.srf[0]->h,test->start.pos.y))
                          {
                             SDL_FreeSurface(test->start.srf[0]);
                             test->start.srf[0]=IMG_Load("Game project/Sprites/Menu_Sprites/play_h.png");
			     test->curseur.current_pos=0;
                          }
else if(distance(event.motion.x,test->settings.pos.x+test->settings.srf[0]->w,test->settings.pos.x) && distance(event.motion.y,test->settings.pos.y+test->settings.srf[0]->h,test->settings.pos.y))
                        {
				SDL_FreeSurface(test->settings.srf[0]);
				test->settings.srf[0]=IMG_Load("Game project/Sprites/Menu_Sprites/options_h.png");
				test->curseur.current_pos=1;
                        }
else if(distance(event.motion.x,test->exit.pos.x+test->exit.srf[0]->w,test->exit.pos.x) && distance(event.motion.y,test->exit.pos.y+test->exit.srf[0]->h,test->exit.pos.y))
			{
				SDL_FreeSurface(test->exit.srf[0]);
				test->exit.srf[0]=IMG_Load("Game project/Sprites/Menu_Sprites/quit_h.png");
				test->curseur.current_pos=2;
			}
                
else
{
    test->start.srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/play.png");
    test->settings.srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/options.png");
    test->exit.srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/quit.png");
}

        break;

			break;
                              case SDL_MOUSEBUTTONDOWN:
			if(distance(event.motion.x,test->exit.pos.x+test->exit.srf[0]->w,test->exit.pos.x) && distance(event.motion.y,test->exit.pos.y+test->exit.srf[0]->h,test->exit.pos.y))	
                 return 1;
		   else if(distance(event.motion.x,test->start.pos.x+test->start.srf[0]->w,test->start.pos.x) && distance(event.motion.y,test->start.pos.y+test->start.srf[0]->h,test->start.pos.y))
{
				test_sound= Mix_PlayChannel(-1,snd->scrible1, 0 );
				test->lvl_play[0]= 1;
				return 1;
}
else if(distance(event.motion.x,test->settings.pos.x+test->settings.srf[0]->w,test->settings.pos.x) && distance(event.motion.y,test->settings.pos.y+test->settings.srf[0]->h,test->settings.pos.y))
{
				test_sound= Mix_PlayChannel(-1,snd->scrible2,0);
}
else if(!(distance(event.motion.x,test->window.pos.x+test->window.srf[0]->w,test->window.pos.x) && distance(event.motion.y,test->window.pos.y+test->window.srf[0]->h,test->window.pos.y)))
   *check_window= 0;
break;

             }
           } 
return 0;
}

int distance(int a, int b,int c)
{
if (a<b && a>c)
return 1;
else
return 0;
}

void init(menu_buttons* test,SFX* snd)
{
test->imageDeFond.srf[0] = NULL;
test->imageDeFond.current_frame= 0;

test->start.srf[0] = NULL;

test->settings.srf[0] = NULL;
test->exit.srf[0] = NULL;

test->curseur.srf= NULL;

test->lvl_play[0]=0;


    test->ecran.srf[0]= NULL;
    test->title.srf[0] = NULL;
    test->imageDeFond.pos.x =0 ;
    test->imageDeFond.pos.y=0 ;
 
    test->start.pos.x = 80;
    test->start.pos.y = 180;

	test->curseur.pos[0].x=49;
	test->curseur.pos[0].y=177;

	test->curseur.pos[1].x=9;
	test->curseur.pos[1].y=247 ;

	test->curseur.pos[2].x=52;
	test->curseur.pos[2].y=317;
	
	test->curseur.current_pos= 0;
	test->curseur.enter_state= -1;




    test->settings.pos.x = 40;
    test->settings.pos.y = 250;
    test->exit.pos.x = 83;
    test->exit.pos.y = 320;
    test->title.pos.x=38;
    test->title.pos.y=90;
    test->window.pos.x=160;
    test->window.pos.y=120;
    snd->scrible1 = NULL;
    snd->scrible2 = NULL;
    snd->scrible3 = NULL;

SDL_WM_SetCaption( "..LOCKED..", NULL );
if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096)==-1)
printf("Error Initialising MIX_OPEN_AUDIO: %s\n",SDL_GetError());
}
void load_frames(Imm* imageDeFond)
{
imageDeFond->srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_0.png");
imageDeFond->srf[1] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_1.png");
imageDeFond->srf[2] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_2.png");
imageDeFond->srf[3] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_3.png");

imageDeFond->srf[4] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_4.png");
imageDeFond->srf[5] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_5.png");
imageDeFond->srf[6] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_6.png");
imageDeFond->srf[7] = IMG_Load("Game project/Sprites/Menu_Sprites/Frames_of_menu/frame_7.png");
}

void load(menu_buttons* test,SFX* snd)
{
    load_frames(& test->imageDeFond);
    test->start.srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/play.png");
    test->settings.srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/options.png");
    test->exit.srf[0] = IMG_Load("Game project/Sprites/Menu_Sprites/quit.png");
    test->window.srf[0] = IMG_Load("Game project/test.png");
    test->title.srf[0]= IMG_Load("Game project/Sprites/Menu_Sprites/title.png");
    test->curseur.srf= IMG_Load("Game project/Sprites/Menu_Sprites/Pointeur.png");


    snd->scrible1 = Mix_LoadWAV("Game project/Sound Effects/Scrible.wav");
    snd->scrible2 = Mix_LoadWAV("Game project/Sound Effects/Scrible2.wav");

    Mix_Music *music1=Mix_LoadMUS("Game project/Soundtracks/Menu_soundtrack.mp3");  
	Mix_PlayMusic(music1, 1);
        Mix_VolumeMusic(50);
}


void display(menu_buttons* test,int *check_window)
{


    SDL_BlitSurface(test->imageDeFond.srf[test->imageDeFond.current_frame], NULL, test->ecran.srf[0], & test->imageDeFond.pos);

    SDL_BlitSurface(test->start.srf[0], NULL, test->ecran.srf[0], & test->start.pos);
    SDL_BlitSurface(test->settings.srf[0], NULL, test->ecran.srf[0], & test->settings.pos);
    SDL_BlitSurface(test->exit.srf[0], NULL, test->ecran.srf[0], & test->exit.pos);
    SDL_BlitSurface(test->title.srf[0],NULL,test->ecran.srf[0],& test->title.pos);
    SDL_BlitSurface(test->curseur.srf,NULL,test->ecran.srf[0],& test->curseur.pos[test->curseur.current_pos]);

    SDL_Flip(test->ecran.srf[0]);

}



/*int check_inpute_lvl1(SDL_Event event)
{
while( SDL_PollEvent( &event ) ){
        switch( event.type ){
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
			case SDLK_ESCAPE:
				return 1;
					break;
  }
 }
}
return 0;
}*/

void init_lvl1(lvl1* lv1)
{
lv1->ecran.srf[0] = NULL;
lv1->fond.srf[0] = NULL;
lv1->fond.srf[2] = NULL;
lv1->mask.srf[0]=NULL;

lv1->perso.srf[0]=NULL;
lv1->perso.srf[1]=NULL;
lv1->perso.srf[2]=NULL;
lv1->perso.srf[3]=NULL;
lv1->perso.srf[4]=NULL;
lv1->perso.srf[5]=NULL;
lv1->perso.srf[6]=NULL;
lv1->ground_lvl= 2400;

lv1->perso.srf[7]=NULL;
lv1->perso.srf[8]=NULL;
lv1->perso.srf[9]=NULL;
lv1->perso.srf[10]=NULL;
lv1->perso.srf[11]=NULL;
lv1->perso.srf[12]=NULL;
lv1->perso.srf[13]=NULL;




lv1->i.cheese.srf[0]=NULL;
lv1->i.boussole.srf[0]=NULL;
lv1->i.outils.srf[0]=NULL;
lv1->i.torch.srf[0]=NULL;
lv1->i.back_pack.srf[0]=NULL;
lv1->i.item_counter=0;

lv1->i.bar.srf[0]=NULL;

lv1->i.bar.pos.x=0;
lv1->i.bar.pos.y=0;

/*lv1->i.cheese.pos.x=;
lv1->i.cheese.pos.y=;*/

lv1->i.back_pack.pos.x=1151;
lv1->i.back_pack.pos.y=2491;

lv1->i.torch.pos.x=5545;
lv1->i.torch.pos.y=1436;

lv1->i.outils.pos.x=7412;
lv1->i.outils.pos.y=600;

/*lv1->i.boussole.pos.x=;
lv1->i.boussole.pos.y=;*/

lv1->i.cheese.blit[0]=1;
lv1->i.boussole.blit[0]=1;
lv1->i.torch.blit[0]=1;
lv1->i.back_pack.blit[0]=1;
lv1->i.outils.blit[0]=1;

lv1->perso.pos.x= 0;
lv1->perso.pos.y= lv1->ground_lvl;

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

lv1->mask.pos.x=0;
lv1->mask.pos.y=0;

lv1->perso.blit[0]= 0;
lv1->perso.blit[1]= 0;
lv1->perso.jump_state=0;
lv1->perso.jump_distance=0;
lv1->perso.enable_fall = 0;
lv1->perso.accel=5;
lv1->perso.current_frame=0;

        lv1->perso.box.pos.x = 0;
        lv1->perso.box.pos.y = lv1->ground_lvl;
        lv1->perso.box.pos.w = 60;
        lv1->perso.box.pos.h = 140;

	lv1->box_table.pos.x= 100;
	lv1->box_table.pos.y= lv1->ground_lvl;
	lv1->box_table.pos.w= 60;
	lv1->box_table.pos.h= 140;

lv1->mouse.srf[0]= NULL;
lv1->mouse.pos.x=100;
lv1->mouse.pos.y=lv1->ground_lvl+100;

lv1->mouse.box.pos.x=100;
lv1->mouse.box.pos.y=lv1->ground_lvl+100;
lv1->mouse.box.pos.w=96;
lv1->mouse.box.pos.h=32;

init_enigme(&lv1->enigme);

//init_font(&lv1->test);
//initialiserscore(&lv1->sc);

}
void load_lvl1(lvl1* lv1)
{
lv1->fond.srf[0] = IMG_Load("Game project/Sprites/lvl1/lvl1.png");
lv1->fond.srf[1] = IMG_Load("Game project/Sprites/lvl1/lvl1.png");
lv1->mask.srf[0]= IMG_Load("Game project/Sprites/lvl1/lvl1_mask.png");

lv1->perso.srf[0] = IMG_Load("Game project/Sprites/walk_cycle_yass/1.png");
lv1->perso.srf[1] = IMG_Load("Game project/Sprites/walk_cycle_yass/2.png");
lv1->perso.srf[2] = IMG_Load("Game project/Sprites/walk_cycle_yass/3.png");
lv1->perso.srf[3] = IMG_Load("Game project/Sprites/walk_cycle_yass/4.png");
lv1->perso.srf[4] = IMG_Load("Game project/Sprites/walk_cycle_yass/5.png");
lv1->perso.srf[5] = IMG_Load("Game project/Sprites/walk_cycle_yass/6.png");
lv1->perso.srf[6] = IMG_Load("Game project/Sprites/walk_cycle_yass/7.png");

lv1->perso.srf[7] = IMG_Load("Game project/Sprites/walk_cycle_yass/8.png");
lv1->perso.srf[8] = IMG_Load("Game project/Sprites/walk_cycle_yass/9.png");
lv1->perso.srf[9] = IMG_Load("Game project/Sprites/walk_cycle_yass/10.png");
lv1->perso.srf[10] = IMG_Load("Game project/Sprites/walk_cycle_yass/11.png");
lv1->perso.srf[11] = IMG_Load("Game project/Sprites/walk_cycle_yass/12.png");
lv1->perso.srf[12] = IMG_Load("Game project/Sprites/walk_cycle_yass/13.png");
lv1->perso.srf[13] = IMG_Load("Game project/Sprites/walk_cycle_yass/14.png");
lv1->mouse.srf[0] = IMG_Load("Game project/Sprites/lvl1/mouse.png");

lv1->i.cheese.srf[0]= IMG_Load("Game project/Sprites/lvl1/cheese.png");
lv1->i.outils.srf[0]= IMG_Load("Game project/Sprites/lvl1/trousse a outil.png");
lv1->i.back_pack.srf[0]= IMG_Load("Game project/Sprites/lvl1/backpack.png");
lv1->i.torch.srf[0]= IMG_Load("Game project/Sprites/lvl1/torch.png");
//lv1->i.boussole.srf[0]= IMG_Load("Game project/Sprites/lvl1/boussole.png");

lv1->i.bar.srf[0]=IMG_Load("Game project/Sprites/lvl1/Item_barr.png");




//loadFont(&lv1->police);
}


void display_lvl1(lvl1* lv1)
{
/*text t;
init_font(&t);*/


if(lv1->i.back_pack.blit[0])
SDL_BlitSurface(lv1->i.back_pack.srf[0], NULL, lv1->fond.srf[0],&lv1->i.back_pack.pos);

if(lv1->i.torch.blit[0])
SDL_BlitSurface(lv1->i.torch.srf[0], NULL, lv1->fond.srf[0],&lv1->i.torch.pos);

if(lv1->i.outils.blit[0])
SDL_BlitSurface(lv1->i.outils.srf[0], NULL, lv1->fond.srf[0],&lv1->i.outils.pos);

SDL_BlitSurface(lv1->perso.srf[lv1->perso.current_frame], NULL, lv1->fond.srf[0],&lv1->perso.pos);
SDL_BlitSurface(lv1->mouse.srf[0], NULL, lv1->fond.srf[0],&lv1->mouse.pos);
SDL_BlitSurface(lv1->fond.srf[0], &lv1->s.camera, lv1->ecran.srf[0],NULL);

SDL_BlitSurface(lv1->i.bar.srf[0], NULL, lv1->ecran.srf[0],&lv1->i.bar.pos);
/*if(collision_back_door1(lv1->perso,lv1->mask))
{
SDL_BlitSurface(t.text,NULL, lv1->ecran.srf[0],NULL);
SDL_FreeSurface(t.text);
TTF_CloseFont(t.font);
}*/




SDL_Flip(lv1->ecran.srf[0]);
SDL_BlitSurface(lv1->fond.srf[1], NULL, lv1->fond.srf[0],NULL);



}


int check_input_lvl1(SDL_Event event,lvl1* lv1)
{
const int vitess_cam= 20;
const int jump_speed= 25;
const int accel_max= 5;

int s,r,run =1,running=1,alea;
char image[30]="";

while( SDL_PollEvent( &event ) ){
        switch( event.type ){
/////////////Inpute check/////////////////////////
case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_ESCAPE:
			 return 1;
		break;
		    case SDLK_d:
			if(lv1->perso.current_frame > 6)
				lv1->perso.current_frame= 0;

			 lv1->s.state[0]=1;
			lv1->perso.blit[0]= 1;
			lv1->perso.box.pos.x= lv1->perso.pos.x;

		break;
                    case SDLK_q:
			if(lv1->perso.current_frame < 7)
				lv1->perso.current_frame= 7;

			lv1->s.state[1]=1;
			lv1->perso.blit[1]= 1;
			lv1->perso.box.pos.x= lv1->perso.pos.x;
		break;
                    case SDLK_s:
			 lv1->s.state[2]=1;
		break;
                    case SDLK_z:
			 lv1->s.state[3]=1;
		break;
		    case SDLK_SPACE:
			if(!lv1->perso.jump_state)
			{
			lv1->perso.jump_state=1;
			lv1->perso.blit[0]= 1;
			}
		break;
			case SDLK_e:
				if(collision_back_door1(lv1->perso,lv1->mask) && lv1->ground_lvl==2400)
                                       {
					lv1->ground_lvl= 1460;
					lv1->perso.pos.y=lv1->ground_lvl;
					lv1->s.camera.y=lv1->perso.pos.y-320;
					}
				else if(collision_back_door1(lv1->perso,lv1->mask) && lv1->ground_lvl==1460)
					{
					lv1->ground_lvl= 2400;
					lv1->perso.pos.y=lv1->ground_lvl;
					lv1->s.camera.y=2076;
					}

					if(collision_back_door2(lv1->perso,lv1->mask) && lv1->ground_lvl==1460)
					{
					lv1->ground_lvl= 500;
					lv1->perso.pos.y=lv1->ground_lvl;
					lv1->s.camera.y=lv1->perso.pos.y-320;	
					}
					else if(collision_back_door2(lv1->perso,lv1->mask) && lv1->ground_lvl==500)
					{
					lv1->ground_lvl= 1460;
					lv1->perso.pos.y=lv1->ground_lvl;
					lv1->s.camera.y=lv1->perso.pos.y-320;
					}
					else if(collision_back_door3(lv1->perso,lv1->mask))
						
//////////////////////////////////////////////////////////////////////////////////////
{
      load_enigme(&lv1->ecran,image,&lv1->enigme,&alea);
      s=solution_e(image);
while (run)
	 {
	    running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	
			do{
			r=check_input_enigme(&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			
			
      while(running){

				display_enigme(&lv1->ecran,s,r,&lv1->enigme) ;
			       SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              running =0 ;
						      run=0 ;
					     break ;
                       }
                    } 	
   }
SDL_FreeSurface(lv1->enigme.srf[0]);
////////////////////////////////////////////////////////////////////////////
						}
			break;
                                               }
break;
case SDL_KEYUP:
                switch( event.key.keysym.sym ){
			case SDLK_d:
			lv1->s.state[0]=0;
			lv1->perso.blit[1]= 0;
			lv1->s.xscroll = 0;
				lv1->perso.current_frame= 0;
			break;
                        case SDLK_q:
			lv1->s.state[1]=0;
			lv1->perso.blit[1]= 0;
			lv1->s.xscroll = 0;
				lv1->perso.current_frame= 7;
			break;
                        case SDLK_s:
			lv1->s.state[2]=0;
			break;
                        case SDLK_z:
			lv1->s.state[3]=0;
			break;
                                              }                                        
break;
case SDL_MOUSEBUTTONDOWN:
if(event.button.x>320)
lv1->perso.pos.x+=50;
else
lv1->perso.pos.x-=50;

        break;

}
}
////////Camera control////////////////////
if(lv1->s.state[0])
{
lv1->perso.pos.x+= vitess_cam;
lv1->s.xscroll+= vitess_cam;

if(lv1->perso.pos.x >= 320)
{
lv1->s.camera.x+= vitess_cam;
lv1->s.xscroll=180;
}
	if(lv1->s.camera.x > 7360)
		lv1->s.camera.x= 7360;
if(lv1->perso.pos.x >= 7904)
lv1->perso.pos.x=7904;
}
	else if(lv1->s.state[1])
{
lv1->perso.pos.x-=vitess_cam;
lv1->s.xscroll+= vitess_cam;
if(lv1->perso.pos.x <= 7680)
{
lv1->s.camera.x-= vitess_cam;
lv1->s.xscroll= 180;
}
	if(lv1->s.camera.x< 0)
		lv1->s.camera.x= 0;
}
/*else if(lv1->s.state[2])
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
}*/
if(lv1->perso.jump_state)
{
if(lv1->perso.jump_distance < 175 && lv1->perso.enable_fall== 0)
{
if(lv1->perso.accel<0)
lv1->perso.accel=0;
lv1->perso.pos.y-= (jump_speed+lv1->perso.accel)+(power(jump_speed,2))/2;
lv1->perso.jump_distance+=(jump_speed+lv1->perso.accel)+(power(jump_speed,2))/2;
lv1->perso.accel-=1;
lv1->perso.box.pos.y= lv1->perso.pos.y;
}
else
{
if(lv1->perso.accel>accel_max)
lv1->perso.accel=accel_max;

lv1->perso.enable_fall= 1;
lv1->perso.pos.y+=(jump_speed+lv1->perso.accel)+(power(jump_speed,2))/2;
lv1->perso.jump_distance-=(jump_speed+lv1->perso.accel)+(power(jump_speed,2))/2;
lv1->perso.accel+=1;
lv1->perso.box.pos.y= lv1->perso.pos.y;
if(lv1->perso.jump_distance < 10)
{
lv1->perso.jump_distance=0;
lv1->perso.pos.y=lv1->ground_lvl;
lv1->perso.enable_fall=0;
lv1->perso.jump_state=0;
}
}
}
/*if(collision_box(lv1->sr,lv1->perso.box))
printf("test\n");

SDL_MouseMotionEvent m;

lv1->sr.pos.x = m.x;
lv1->sr.pos.y = m.y;*/
///////////////enigme////////////////////

//////////////////////////////////////////

return 0;
}

void free_srf_lvl1(lvl1* lv1)
{
int i;
SDL_FreeSurface(lv1->fond.srf[0]);
SDL_FreeSurface(lv1->fond.srf[1]);
SDL_FreeSurface(lv1->mask.srf[0]);
SDL_FreeSurface(lv1->mouse.srf[0]);
SDL_FreeSurface(lv1->i.cheese.srf[0]);
SDL_FreeSurface(lv1->i.outils.srf[0]);
SDL_FreeSurface(lv1->i.back_pack.srf[0]);
SDL_FreeSurface(lv1->i.torch.srf[0]);
SDL_FreeSurface(lv1->i.bar.srf[0]);
/*TTF_CloseFont(lv1->test.font);*/
TTF_Quit();
for(i=0;i<14;i++)
{
SDL_FreeSurface(lv1->perso.srf[i]); 
}
}


int power(int base,int expo)
{
int total=1,i;
for(i=0;i<expo;i++)
{
total= total*total;
}
return total;
}
SDL_Color GetPixel (SDL_Surface *pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}

int collision_back_red(hero personnage,Imm bg1)
{
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=personnage.pos.x+personnage.pos.w+10;
point[0].y=personnage.pos.y+personnage.pos.h/2;

point[4].x=personnage.pos.x+personnage.pos.w+10;
point[4].y=personnage.pos.y+personnage.pos.h/4;

point[5].x=personnage.pos.x+personnage.pos.w+10;
point[5].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[1].x=personnage.pos.x+personnage.pos.w/2;
point[1].y=personnage.pos.y+personnage.pos.h;

point[2].x=personnage.pos.x-10;
point[2].y=personnage.pos.y+personnage.pos.h/2;

point[6].x=personnage.pos.x-10;   
point[6].y=personnage.pos.y+personnage.pos.h/4;

point[7].x=personnage.pos.x-10;
point[7].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[3].x=personnage.pos.x+personnage.pos.w/2;
point[3].y=personnage.pos.y;  
 
couleur[0]=GetPixel (bg1.srf[0], point[0].x, point[0].y);
couleur[1]=GetPixel (bg1.srf[0], point[1].x, point[1].y);
couleur[2]=GetPixel (bg1.srf[0], point[2].x, point[2].y);
couleur[3]=GetPixel (bg1.srf[0], point[3].x, point[3].y);
couleur[4]=GetPixel (bg1.srf[0], point[4].x, point[4].y);
couleur[5]=GetPixel (bg1.srf[0], point[5].x, point[5].y);
couleur[6]=GetPixel (bg1.srf[0], point[6].x, point[6].y);
couleur[7]=GetPixel (bg1.srf[0], point[7].x, point[7].y);


if (couleur[1].r==255 && couleur[1].g==0 && couleur[1].b==0)
return 1;

else if (couleur[3].r==255 && couleur[3].g==0 && couleur[3].b==0)
return 1;

else if (couleur[1].r==255&& couleur[1].g==0 && couleur[1].b==0)
return 1;

else if ((couleur[2].r==255 && couleur[2].g==0 && couleur[2].b==0)||(couleur[6].r==255 && couleur[6].g==0 && couleur[6].b==0)||(couleur[7].r==255 && couleur[7].g==0 && couleur[7].b==0))
return 1;

else if ((couleur[0].r==255 && couleur[0].g==0 && couleur[0].b==0)||(couleur[4].r==255 && couleur[4].g==0 && couleur[4].b==0)||(couleur[5].r==255 && couleur[5].g==0 && couleur[5].b==0))
return 1;

else return 0;

}
/*
RGB:
Tableau de bord: 255 186 0 = yellow
table: 26 255 0 = green
Door: 0 14 140 = blue
Fridge: 255 0 0 =red
*/
int collision_box(boxx box1,boxx box2)
{
   if((box2.pos.x >= box1.pos.x + box1.pos.w)|| (box2.pos.x + box2.pos.w <= box1.pos.x) || (box2.pos.y >= box1.pos.y + box1.pos.h) || (box2.pos.y + box2.pos.h <= box1.pos.y))
          return 0;
   else
          return 1;
}
int collision_back_door1(hero personnage,Imm bg1)
{
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=personnage.pos.x+personnage.pos.w+10;
point[0].y=personnage.pos.y+personnage.pos.h/2;

point[4].x=personnage.pos.x+personnage.pos.w+10;
point[4].y=personnage.pos.y+personnage.pos.h/4;

point[5].x=personnage.pos.x+personnage.pos.w+10;
point[5].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[1].x=personnage.pos.x+personnage.pos.w/2;
point[1].y=personnage.pos.y+personnage.pos.h;

point[2].x=personnage.pos.x-10;
point[2].y=personnage.pos.y+personnage.pos.h/2;

point[6].x=personnage.pos.x-10;   
point[6].y=personnage.pos.y+personnage.pos.h/4;

point[7].x=personnage.pos.x-10;
point[7].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[3].x=personnage.pos.x+personnage.pos.w/2;
point[3].y=personnage.pos.y;  
 
couleur[0]=GetPixel (bg1.srf[0], point[0].x, point[0].y);
couleur[1]=GetPixel (bg1.srf[0], point[1].x, point[1].y);
couleur[2]=GetPixel (bg1.srf[0], point[2].x, point[2].y);
couleur[3]=GetPixel (bg1.srf[0], point[3].x, point[3].y);
couleur[4]=GetPixel (bg1.srf[0], point[4].x, point[4].y);
couleur[5]=GetPixel (bg1.srf[0], point[5].x, point[5].y);
couleur[6]=GetPixel (bg1.srf[0], point[6].x, point[6].y);
couleur[7]=GetPixel (bg1.srf[0], point[7].x, point[7].y);


int R=0,G=14,B=140;
if (couleur[1].r==R && couleur[1].g==G && couleur[1].b==B)
return 1;

else if (couleur[3].r==R && couleur[3].g==G && couleur[3].b==B)
return 1;

else if (couleur[1].r==R && couleur[1].g==G && couleur[1].b==B)
return 1;

else if ((couleur[2].r==R && couleur[2].g==G && couleur[2].b==B)||(couleur[6].r==R && couleur[6].g==G && couleur[6].b==B)||(couleur[7].r==R && couleur[7].g==G && couleur[7].b==B))
return 1;

else if ((couleur[0].r==R && couleur[0].g==G && couleur[0].b==B)||(couleur[4].r==R && couleur[4].g==G && couleur[4].b==B)||(couleur[5].r==R && couleur[5].g==G && couleur[5].b==B))
return 1;

else return 0;
}

int collision_back_door3(hero personnage,Imm bg1)
{
SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=personnage.pos.x+personnage.pos.w+10;
point[0].y=personnage.pos.y+personnage.pos.h/2;

point[4].x=personnage.pos.x+personnage.pos.w+10;
point[4].y=personnage.pos.y+personnage.pos.h/4;

point[5].x=personnage.pos.x+personnage.pos.w+10;
point[5].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[1].x=personnage.pos.x+personnage.pos.w/2;
point[1].y=personnage.pos.y+personnage.pos.h;

point[2].x=personnage.pos.x-10;
point[2].y=personnage.pos.y+personnage.pos.h/2;

point[6].x=personnage.pos.x-10;   
point[6].y=personnage.pos.y+personnage.pos.h/4;

point[7].x=personnage.pos.x-10;
point[7].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[3].x=personnage.pos.x+personnage.pos.w/2;
point[3].y=personnage.pos.y;  
 
couleur[0]=GetPixel (bg1.srf[0], point[0].x, point[0].y);
couleur[1]=GetPixel (bg1.srf[0], point[1].x, point[1].y);
couleur[2]=GetPixel (bg1.srf[0], point[2].x, point[2].y);
couleur[3]=GetPixel (bg1.srf[0], point[3].x, point[3].y);
couleur[4]=GetPixel (bg1.srf[0], point[4].x, point[4].y);
couleur[5]=GetPixel (bg1.srf[0], point[5].x, point[5].y);
couleur[6]=GetPixel (bg1.srf[0], point[6].x, point[6].y);
couleur[7]=GetPixel (bg1.srf[0], point[7].x, point[7].y);


int R=255,G=127,B=0;
if (couleur[1].r==R && couleur[1].g==G && couleur[1].b==B)
return 1;

else if (couleur[3].r==R && couleur[3].g==G && couleur[3].b==B)
return 1;

else if (couleur[1].r==R && couleur[1].g==G && couleur[1].b==B)
return 1;

else if ((couleur[2].r==R && couleur[2].g==G && couleur[2].b==B)||(couleur[6].r==R && couleur[6].g==G && couleur[6].b==B)||(couleur[7].r==R && couleur[7].g==G && couleur[7].b==B))
return 1;

else if ((couleur[0].r==R && couleur[0].g==G && couleur[0].b==B)||(couleur[4].r==R && couleur[4].g==G && couleur[4].b==B)||(couleur[5].r==R && couleur[5].g==G && couleur[5].b==B))
return 1;

else return 0;
}



void deplacer_aleatoire_ennemi(Imm* ennemi,hero* bg1){

const int dp=10;
    srand((unsigned) time(NULL));
    if(ennemi->dp == 0)//distance parcou
{
	    ennemi->direction = rand() % 2;//0(gauche),0(gauche)
	    ennemi->dp = (rand() % 100) + 1;//100,1 101(pas maximale)
	}
	if(ennemi->direction){
		if(!collision_box(ennemi->box,bg1->box) && ennemi->dp > 0){
			ennemi->pos.x+=dp;
			ennemi->dp+=dp;
		}else{
			ennemi->dp = 0;
		}
	}else{
		if(!collision_box(ennemi->box,bg1->box) && ennemi->dp > 0){
			ennemi->pos.x-=dp;
			ennemi->dp-=dp;
		}else{
			ennemi->dp = 0;
		}
	}
			if(ennemi->pos.x < 0)
			ennemi->pos.x=0;
			if(ennemi->pos.x>7904)
			ennemi->pos.x=7904;
			
			ennemi->box.pos.x=ennemi->pos.x;
}

int collision_back_door2(hero personnage,Imm bg1)
{
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=personnage.pos.x+personnage.pos.w+10;
point[0].y=personnage.pos.y+personnage.pos.h/2;

point[4].x=personnage.pos.x+personnage.pos.w+10;
point[4].y=personnage.pos.y+personnage.pos.h/4;

point[5].x=personnage.pos.x+personnage.pos.w+10;
point[5].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[1].x=personnage.pos.x+personnage.pos.w/2;
point[1].y=personnage.pos.y+personnage.pos.h;

point[2].x=personnage.pos.x-10;
point[2].y=personnage.pos.y+personnage.pos.h/2;

point[6].x=personnage.pos.x-10;   
point[6].y=personnage.pos.y+personnage.pos.h/4;

point[7].x=personnage.pos.x-10;
point[7].y=personnage.pos.y+(personnage.pos.h*3)/4;

point[3].x=personnage.pos.x+personnage.pos.w/2;
point[3].y=personnage.pos.y;  
 
couleur[0]=GetPixel (bg1.srf[0], point[0].x, point[0].y);
couleur[1]=GetPixel (bg1.srf[0], point[1].x, point[1].y);
couleur[2]=GetPixel (bg1.srf[0], point[2].x, point[2].y);
couleur[3]=GetPixel (bg1.srf[0], point[3].x, point[3].y);
couleur[4]=GetPixel (bg1.srf[0], point[4].x, point[4].y);
couleur[5]=GetPixel (bg1.srf[0], point[5].x, point[5].y);
couleur[6]=GetPixel (bg1.srf[0], point[6].x, point[6].y);
couleur[7]=GetPixel (bg1.srf[0], point[7].x, point[7].y);


int R=228,G=255,B=0;
if (couleur[1].r==R && couleur[1].g==G && couleur[1].b==B)
return 1;

else if (couleur[3].r==R && couleur[3].g==G && couleur[3].b==B)
return 1;

else if (couleur[1].r==R && couleur[1].g==G && couleur[1].b==B)
return 1;

else if ((couleur[2].r==R && couleur[2].g==G && couleur[2].b==B)||(couleur[6].r==R && couleur[6].g==G && couleur[6].b==B)||(couleur[7].r==R && couleur[7].g==G && couleur[7].b==B))
return 1;

else if ((couleur[0].r==R && couleur[0].g==G && couleur[0].b==B)||(couleur[4].r==R && couleur[4].g==G && couleur[4].b==B)||(couleur[5].r==R && couleur[5].g==G && couleur[5].b==B))
return 1;

else return 0;
}

void init_font(text* t)
{
SDL_Color color={232,12,122};
t->color= color;
t->font= TTF_OpenFont("Game project/fonts/pencilgrid.ttf",60);
t->text= TTF_RenderText_Blended(t->font,"E",t->color);
}

void blit_font(text* t,SDL_Surface* ecran,char text[])
{
t->text= TTF_RenderText_Blended(t->font,text,t->color);
SDL_BlitSurface(t->text,NULL,ecran,NULL);
}







///enigme/////

void init_enigme(Imm * e)
{
	e->pos.x=0;
	e->pos.y=0;	
	e->srf[0]=NULL;
}

void load_enigme(Imm * screen  , char image [],Imm *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"Game project/enigme/%d.jpg",*alea);
e->srf[0] = IMG_Load(image);
 SDL_BlitSurface(e->srf[0],NULL,screen->srf[0],&(e->pos)) ;
  SDL_Flip(screen->srf[0]) ;
}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"Game project/enigme/1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"Game project/enigme/2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"Game project/enigme/3.jpg")==0)
 	{
 		solution =1;	
 	}
 	return solution;
 }

int check_input_enigme(int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}
  return r ;
}

void display_enigme(Imm * screen,int s,int r,Imm *en)
 {
 
 	if (r==s)
 	{
 		en->srf[0]=IMG_Load("Game project/enigme/00.jpg");
 		SDL_BlitSurface(en->srf[0], NULL, screen->srf[0], &(en->pos)) ;
        SDL_Flip(screen->srf[0]);
 	}
 	else
 	{
 		en->srf[0]=IMG_Load("Game project/enigme/11.jpg");
 		SDL_BlitSurface(en->srf[0], NULL, screen->srf[0], &(en->pos)) ;
        SDL_Flip(screen->srf[0]);
 	}
 }


 
