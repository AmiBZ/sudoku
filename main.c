#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include<stdbool.h>
#include "constantes.h"


int main(int argc, char *argv[])
{

    SDL_Surface *ecran=NULL,*menu=NULL,*imgacharger=NULL,*menu_niveau=NULL;
    int continuer=1;
    SDL_Event event;
    SDL_Rect positionmenu;


    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_WM_SetIcon(SDL_LoadBMP("icone2.bmp"),NULL);
    ecran=SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    menu=IMG_Load("entree3.png");
    menu_niveau=IMG_Load("menu_pre_jeu");
    imgacharger=menu;

    positionmenu.x=0;
    positionmenu.y=0;
    SDL_WM_SetCaption("Sudoku4*4 pour enfants (BANIABAZ_ELHARCHAOUI)",NULL);
    SDL_EnableKeyRepeat(10,10);
    while (continuer)
    {
        SDL_WaitEvent(&event);



        switch (event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    if((event.button.x>210 && event.button.x<575)&&(event.button.y>268 && event.button.y<480))
                    {
                        selectionNiveau(ecran);

                    }

                    break;


                }
                break;
        }




        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(imgacharger,NULL,ecran,&positionmenu);
        SDL_Flip(ecran);
        }

    SDL_FreeSurface(menu);
    SDL_Quit();
    return EXIT_SUCCESS;
}

