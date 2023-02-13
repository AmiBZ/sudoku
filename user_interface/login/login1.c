#include "SDL.h"

extern void InitVideo();
extern void Redraw();

extern char *text;
extern char *composition;
extern Sint32 cursor;
extern Sint32 selection_len;

int main(int argc, char *argv[])
{

 //  int BlitTime(SDL_Surface *ecran,int tempsEcoule) {

    TTF_Font *font1 = NULL;
    SDL_Surface *temps_surf = NULL;
    SDL_Rect temps_pos;
    SDL_Color couleur = {0,0,0,0};
    char temps_txt[30];
    char dimensions[20];
    int time = 2*60*1000; // 3 min en millisecondes
    time -= tempsEcoule;
    int min = time /(1000*60);
    int sec = (time % (1000*60)) / 1000;
    font1 =  TTF_OpenFont("police.ttf",50);
    sprintf(temps_txt,"Temps 0%d : %2d",min,sec);
    temps_surf = TTF_RenderText_Solid(font1,temps_txt,couleur);
    temps_pos.x = 700/2 - temps_surf->w/2;
    temps_pos.y = 50;


    SDL_BlitSurface(temps_surf,NULL,ecran,&temps_pos);
    SDL_Flip(ecran);


    SDL_FreeSurface(temps_surf);
    TTF_CloseFont(font1);

SDL_Quit();

    return 0;
}
