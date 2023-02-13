#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"functions.h"

bool absentSurLigne(int n ,int sudoku[4][4] ,int i)
{	int j;
	for(j=0;j<4;j++)

		if(sudoku[i][j]==n)
			return false;
	return true;
}
bool absentSurColonne(int n ,int sudoku[4][4] ,int j)
{	int i;
	for(i=0;i<4;i++)

		if(sudoku[i][j]==n)
			return false;
	return true;
}
bool absentSurBloc(int n, int sudoku[4][4], int i0, int j0)
{
	int i=2*(i0/2),j=2*(j0/2);
	int r,s;
	/*parcourir le bloc auquel la case(i,j) appartient*/
	for(r=i;r<i+2;r++)
	{
		for(s=j;s<j+2;s++)
		{
			if(sudoku[r][s]==n)
				return false;
			return true;
		}
	}
}

bool Solveur(int sudoku[4][4],int position)/*position=i*(largeur resp(hauteur))+j  ;largeur=4*/
{	int n;
	/*si on est à la position 16 alors la grille est correcte et on sort avec un true*/
    if (position == 4*4)
        return true;
    int i = position/4, j = position%4;/*on recupere les coordonnees de la case*/
    if (sudoku[i][j] != 0)
        return Solveur(sudoku, position+1);/*passer à la case suivante*/
    for(n=1;n<=4;n++)
    {	/*on teste si n est absent sur ligne/colonne/bloc */
    	if(absentSurLigne(n,sudoku,i) && absentSurColonne(n,sudoku,j) && absentSurBloc(n,sudoku,i,j))
		{
			sudoku[i][j]=n;/*on stock n dans la case(i,j)*/
			if(Solveur(sudoku,position+1))
			{
				return true;
			}
		}
    }
    sudoku[i][j]=0;
    return false;
}



int BlitTime(SDL_Surface *ecran,int tempsEcoule) {

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
    if(time <= 0)
        return 0;
    else
        return 1;
}
void BlitScore(SDL_Surface *ecran,int tempsEcoule,int difficulte,int numero) {

    TTF_Font *font1 = NULL;
    SDL_Event event;
    SDL_Surface *score_surf = NULL,*gagne=NULL;
    gagne=IMG_Load("gagne.png");
    SDL_Rect score_pos,pos;
    pos.x=0;
    pos.y=0;
    SDL_Color couleur = {0,0,0,0};
    char score_txt[30];
    char dimensions[20];
    int time = 2*60*1000,continuer=1;
    time -= tempsEcoule;
    int score;
    switch (difficulte){
case 1:
    score=time*2;
    break;
case 2:
    score=time/2;
    break;
case 3:
    score=time;
    break;


    }

    font1 =  TTF_OpenFont("police.ttf",50);
    sprintf(score_txt,"%d",score);
    score_surf = TTF_RenderText_Solid(font1,score_txt,couleur);
    score_pos.x = 400 - score_surf->w/2;
    score_pos.y = 419;
while (continuer)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {case SDL_QUIT:
                exit(0);
        case SDL_MOUSEBUTTONDOWN:
            if ((event.button.x>0&& event.button.x<239)&&(event.button.y>0 && event.button.y<100))
            {   tempsEcoule=0;
                jouer(ecran,numero,difficulte,tempsEcoule);
            }
            break;
        }
    SDL_BlitSurface(gagne,NULL,ecran,&pos);
    SDL_BlitSurface(score_surf,NULL,ecran,&score_pos);
    SDL_Flip(ecran);
    }


    TTF_CloseFont(font1);

}

void Perdu (SDL_Surface *ecran) {

    int continuer=1;
    SDL_Event event;
    SDL_Surface *perdu=NULL;
    perdu=IMG_Load("perdu.png");
    SDL_Rect pos;
    pos.x=0;
    pos.y=0;

while (continuer)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {case SDL_QUIT:
                exit(0);
        case SDL_MOUSEBUTTONDOWN:
            if ((event.button.x>150&& event.button.x<620)&&(event.button.y>431 && event.button.y<600))
            {
                selectionNiveau(ecran);
            }
            break;
        }
    SDL_BlitSurface(perdu,NULL,ecran,&pos);

    SDL_Flip(ecran);
    }




}
