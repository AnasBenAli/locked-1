#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "temps.h"

void intialiser_score(score *s)
{  SDL_Surface *ecran ;
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE) ;
SDL_Color couleurNoire = {0, 0, 0};
  SDL_Color  couleurBlanche = {255, 255, 255};
char  temps[20] = "";
   s->police = NULL;
      s->tempsActuel = 0;
 s->tempsPrecedent = 0;
 s->compteur =2;
  s->police = TTF_OpenFont("ASMAN.ttf", 60); 
        s->position.x = 200;
        s->position.y = 200;
            s->texte = TTF_RenderText_Shaded(s->police, temps, couleurNoire,couleurBlanche); /* On écrit la chaine temps dans la SDL_Surface */

}
 void score_pers( score *s,SDL_Surface *ecran)
{    

 SDL_Color couleurNoire = {0, 0, 0};
  SDL_Color  couleurBlanche = {255, 255, 255}; 
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));



 char  temps[20] = "";

sprintf(temps, "score : %d", s->compteur);

    s->tempsActuel = SDL_GetTicks();
        if (s->tempsActuel - s->tempsPrecedent >= 1000) /* Si 100ms au moins se sont écoulées */
        {
            s->compteur += 2; /* On rajoute 100ms au compteur */
            sprintf(temps, "score : %d", s->compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(s->texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
            s->texte = TTF_RenderText_Shaded(s->police, temps, couleurNoire,couleurBlanche); /* On écrit la chaine temps dans la SDL_Surface */
            s->tempsPrecedent = s->tempsActuel; /* On met à jour le tempsPrecedent */
	} 
}   
void afficher_score(score* s,SDL_Surface *ecran)
{
	SDL_BlitSurface(s->texte, NULL, ecran, &s->position); 
        SDL_Flip(ecran);
}
