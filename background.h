#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
typedef struct
{
	SDL_Surface *back ;
	SDL_Rect pos;
}backgrd;


void init_backgrd(backgrd *backg);
void display(SDL_Surface *ecran,backgrd *backg);
void freegame(backgrd *backg);







#endif

