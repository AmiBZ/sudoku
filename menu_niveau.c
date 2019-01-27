#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<stdbool.h>
#include <string.h>

#include "constantes.h"
void selectionNiveau(SDL_Surface* ecran)
{
    SDL_Surface *menu_pre_jeu=NULL,*menu_diff=NULL,*menu_moy=NULL,*menu_facile=NULL,*image=NULL;
    int continuer=1,difficulte,numero;


    SDL_Event event;
    SDL_Rect position;

    menu_pre_jeu=IMG_Load("menu_pre_jeu.png");
    menu_diff=IMG_Load("lol.png");
    menu_facile=IMG_Load(("lel.png"));
    menu_moy=IMG_Load("lul.png");
    position.x=0;
    position.y=0;


    image=menu_pre_jeu;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);

        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
                if ((event.button.x>103&& event.button.x<328)&&(event.button.y>262 && event.button.y<405))
                {   difficulte=1;
               afficherLesGrilles(ecran,difficulte);

                }
               if ((event.button.x>476&& event.button.x<696)&&(event.button.y>262 && event.button.y<405))
                {
                    difficulte=2;
               afficherLesGrilles(ecran,difficulte);
                }
                if ((event.button.x>282&& event.button.x<526)&&(event.button.y>488 && event.button.y<633))
                {
                   difficulte=3;
                                   afficherLesGrilles(ecran,difficulte);
                }



                break;
            }
        break;

        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(menu_pre_jeu,NULL,ecran,&position);
        SDL_Flip(ecran);

    }

        SDL_FreeSurface(menu_pre_jeu);


}
