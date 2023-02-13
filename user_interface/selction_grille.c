#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "constantes.h"


void afficherLesGrilles(SDL_Surface *ecran,int difficulte)
{
    SDL_Surface *lol=NULL,*lul=NULL,*lel=NULL,*image=NULL;
    int continuer=1,numero;


    SDL_Event event;
    SDL_Rect position;


    lol=IMG_Load("frm_dif.png");
    lel=IMG_Load(("frm_fac.png"));
    lul=IMG_Load("frm_mo.png");
    position.x=0;
    position.y=0;
    switch (difficulte)
    {
    case 1:
        image=lol;
        break;
    case 2:
        image=lel;
        break;
    case 3:
        image=lul;
        break;
    }


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
                if ((event.button.x>0&& event.button.x<224)&&(event.button.y>0 && event.button.y<224))
                {
                    numero=1;
                                    jouer(ecran,numero,difficulte);
                }
                if ((event.button.x>228&& event.button.x<448)&&(event.button.y>0 && event.button.y<224))
                {
                    numero=2;
                                    jouer(ecran,numero,difficulte);
                }
                if ((event.button.x>454&& event.button.x<675)&&(event.button.y>0 && event.button.y<224))
                {
                    numero=3;
                                    jouer(ecran,numero,difficulte);
                }
                if ((event.button.x>0&& event.button.x<224)&&(event.button.y>227 && event.button.y<453))
                {
                    numero=4;
                                    jouer(ecran,numero,difficulte);
                }
                if ((event.button.x>228&& event.button.x<448)&&(event.button.y>227 && event.button.y<453))
                {
                    numero=5;
                                    jouer(ecran,numero,difficulte);
                }
                if ((event.button.x>450&& event.button.x<675)&&(event.button.y>227 && event.button.y<453))
                {
                    numero=6;
                                    jouer(ecran,numero,difficulte);
                }



                break;
            }
        break;

        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(image,NULL,ecran,&position);
        SDL_Flip(ecran);

    }



}
