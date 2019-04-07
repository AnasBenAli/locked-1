#include <stdio.h>
#include <stdlib.h> 
#include "score.h"
void initialiserscore(score *score){

score->posScore.x=122.5;
score->posScore.y=100;
score->nb=00;
score->textScore=NULL;
}

void loadFont(TTF_Font **police)
{
	TTF_Init(); 
	*police = TTF_OpenFont("this.ttf", 13);

}

void calculerScore(score *score,int collision)
{
if(collision==1) 
{
score->nb++;

}
}
void afficherscore(score *score , SDL_Surface *ecran,TTF_Font *police){
char kda[50];
if(score->nb<=0) score->nb=0;
	sprintf(kda,"score= %d s",score->nb);
SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};

	score->textScore = TTF_RenderText_Blended(police,kda,couleurNoire);
	SDL_SetColorKey(score->textScore, SDL_SRCCOLORKEY, SDL_MapRGB(score->textScore->format, 255, 255, 255));
	SDL_BlitSurface(score->textScore,NULL,ecran,&score->posScore);
}
void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}
