#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED
typedef struct 
{
SDL_Surface* srf[8];
SDL_Rect pos;
int blit[2];
}Imm;
typedef struct
{
int xscroll;
int yscroll;
SDL_Rect camera;
int state[4];
}scroll;

typedef struct
{
Imm ecran;
Imm fond;
Imm mouse;
scroll s;
}lvl1;


void init_lvl1(lvl1* lv1);
void load_lvl1(lvl1* lv1);
void display_lvl1(lvl1* lv1);
int check_input_lvl1(SDL_Event event,lvl1* lv1);
void free_srf_lvl1(lvl1* lv1);





#endif // HEADERNAME_H_INCLUDED
