#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED
typedef struct
{
Uint32 start;
Uint32 end;
Uint32 diff;
}timer;
typedef struct
{
int xscroll;
int yscroll;
SDL_Rect camera;
int state[4];
}scroll;
typedef struct
{
SDL_Surface* srf;
SDL_Rect pos;
}boxx;
typedef struct 
{
SDL_Surface* srf[8];
SDL_Rect pos;
int blit[2];
int current_frame;
int direction,dp;
boxx box;
}Imm;
typedef struct
{
Imm back_pack;
Imm torch;
Imm boussole;
Imm outils;
Imm cheese;
Imm bar;
int item_counter;
}items;
typedef struct 
{
SDL_Surface* srf[14];
SDL_Rect pos;
int blit[2];
int jump_state;
int jump_distance;
int enable_fall;
int accel;
int current_frame;
boxx box;
}hero;
typedef struct
{
SDL_Surface *srf;
SDL_Rect pos[3];
int current_pos;
int enter_state;
}pointeur;

typedef struct
{
TTF_Font *police;
SDL_Surface *text;
SDL_Rect pos;
}text_cpr;
typedef struct
{
Imm start;
Imm imageDeFond;
Imm settings;
Imm exit;
Imm title;
Imm ecran;
Imm window;
pointeur curseur;
int lvl_play[3];
}menu_buttons;

typedef struct
{
TTF_Font* font;
SDL_Surface* text;
SDL_Rect pos;
SDL_Color color;
}text;

typedef struct score
{
int nb;
SDL_Surface *textScore;
SDL_Rect posScore;
}score;

typedef struct vie
{
SDL_Surface *vie0 ; 
SDL_Surface *vie1 ;
SDL_Surface *vie2 ; 
SDL_Surface *vie3 ;
SDL_Rect positionvie;
SDL_Rect positiongameover ; 
int nbr;
}vie;

typedef struct
{
Imm ecran;
Imm fond;
Imm mask;
hero perso;
scroll s;
int ground_lvl;
Imm sourrie;
Imm box_table;
text test;
Imm mouse;
Imm enigme;
boxx sr;
items i;
}lvl1;

typedef struct
{
Mix_Chunk *scrible1;
Mix_Chunk *scrible2;
Mix_Chunk *scrible3;
}SFX;

int check_input(SDL_Event event, int* choice, menu_buttons* test,SFX *snd,int *check_window);
void init(menu_buttons* test,SFX *snd);
void load(menu_buttons* test,SFX *snd);
void display(menu_buttons* test,int *check_window);
int distance(int a,int b,int c);
void load_frames(Imm* imageDeFond);
int check_inpute_lvl1(SDL_Event event);
int check_distance(SDL_Rect a,SDL_Rect b,SDL_Event event);

void init_enigme(Imm * e) ;
void  load_enigme(Imm* screen  , char image [],Imm *e,int *alea) ;
int solution_e (char image []) ;
int check_input_enigme(int * running,int *run);
void display_enigme(Imm* screen,int s,int r,Imm *en) ;

void init_lvl1(lvl1* lv1);
void load_lvl1(lvl1* lv1);
void display_lvl1(lvl1* lv1);
int check_input_lvl1(SDL_Event event,lvl1* lv1);
void free_srf_lvl1(lvl1* lv1);
int power(int base,int expo);

SDL_Color GetPixel (SDL_Surface *pSurface,int x,int y);
int collision_back_red(hero personnage,Imm bg1);
int collision_back_door1(hero personnage,Imm bg1);
int collision_back_door2(hero personnage,Imm bg1);
int collision_back_door3(hero personnage,Imm bg1);
int collision_back(Imm personnage,Imm bg1);
int collision_box(boxx box1,boxx box2);

void deplacer_aleatoire_ennemi(Imm* ennemi,hero* bg1);

void init_font(text* t);
void blit_font(text* t,SDL_Surface* ecran,char text[]);

/*void initialiserscore(score *score);
void afficherscore(score *score , SDL_Surface *ecran,TTF_Font *police);
void calculerScore(score *score,int collision);
void loadFont(TTF_Font **police);
void freeFont(TTF_Font **police);*/

/*void intialiser_temps(temps *s);
void temps_pers(temps *s,SDL_Surface *ecran);
void afficher_temps(temps* s,SDL_Surface *ecran);*/

void intialiser_vie (vie *v);
void gestion_vie (vie *v, int collision_trigo,SDL_Surface *screen);


#endif // HEADERNAME_H_INCLUDED
