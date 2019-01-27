
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include<stdbool.h>
#include <string.h>
#include"functions.h"
#include "constantes.h"



void jouer(SDL_Surface* ecran,int numero,int difficulte)
{
    int i=0,j=0,x,y,compteur,fin=0,tempsEcoule=1,tempsPrecedent=0,tempsActuel=0;
    int grille[4][4]={0};
    int grille2[4][4]={0};
    int grilleSolution[4][4]={0};
    SDL_Surface *jeu=NULL,*un=NULL,*deux=NULL,*trois=NULL,*quatre=NULL,*vide=NULL,*fond=NULL,*numABlitter=NULL;
    int continuer=1,numActuel=0,c=2,l=2;


    SDL_Event event;
    SDL_Rect position,positiongrille,positionfond,positionCurseur;

    vide=IMG_Load("vide.png");
    un=IMG_Load("t_1.png");

    deux=IMG_Load("c_2.png");
    trois=IMG_Load("cer_3.png");
    quatre=IMG_Load("e_4.png");

    fond=IMG_Load("JEU3.png");

    positionfond.x=0;
    positionfond.y=0;
    chargerNiveau(grille,numero,difficulte);
    chargerNiveau(grille2,numero,difficulte);
    chargerNiveau(grilleSolution,numero,difficulte);

    numABlitter=un;


    while (continuer)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_KP0:
                numABlitter=vide;
                numActuel=0;
                break;
            case SDLK_KP1:
                numABlitter=un;
                numActuel=1;
                break;
            case SDLK_KP2:
                numABlitter=deux;
                numActuel=2;
                break;
            case SDLK_KP3:
                numABlitter=trois;
                numActuel=3;
                break;
            case SDLK_KP4:
                numABlitter=quatre;
                numActuel=4;
                break;
            }
        break;
        case SDL_MOUSEBUTTONDOWN:

            switch (event.button.button )
            {
            case SDL_BUTTON_LEFT:
            //rejouer
            if ((event.button.x>190&& event.button.x<400)&&(event.button.y>53 && event.button.y<600))
            {
                selectionNiveau(ecran);
            }



            if ((event.button.x>200&& event.button.x<600)&&(event.button.y>200 && event.button.y<600))
            {
            x = ((event.button.x - 200) / 100);
            y = ((event.button.y-200) / 100);
            if(grille[x][y] == 0) {
            grille2[((event.button.x - 200) / 100)][((event.button.y-200) / 100)] = numActuel;
            l=event.button.x /TAILLE_BLOC;
            c=event.button.y/TAILLE_BLOC;
            }

            }

            //changer grille
            if ((event.button.x>0&& event.button.x<174)&&(event.button.y>244 && event.button.y<375))
            {   if (numero==6){numero=1;}
                numero++;
                    tempsEcoule=0;
                    chargerNiveau(grille,numero,difficulte);
                    chargerNiveau(grille2,numero,difficulte);
                ;
            }

        //j'ai fini
        if ((event.button.x>20&& event.button.x<150)&&(event.button.y>400 && event.button.y<500))
            {  for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
                {
                    for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
                    {
                        if (grille2[i][j]!=0)
                            {compteur++;}

                    }
                }
                if (compteur==16){
                    if (est_solution(grille2))
                    {
                        BlitScore(ecran,tempsEcoule,difficulte,numero);
                    }}
                if (compteur !=16)
                    {compteur=0;
                    }
            }

/*{



                                    Solveur(grilleSolution,0);
            for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
            {
                for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
                {
                    if (grilleSolution[i][j]=grille2[i][j])
                        {compteur++;}

                }
            }
            if (compteur==16){BlitScore(ecran,tempsEcoule,difficulte,numero);}
            else {compteur=0;}

            }*/
            break;
            }



        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(fond,NULL,ecran,&positionfond);


        for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
        {
            for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
            {
                position.x = (i * TAILLE_BLOC)+200;
                position.y = (j * TAILLE_BLOC)+200;

                switch(grille2[i][j])
                {
                    case 1:
                        SDL_BlitSurface(un, NULL, ecran, &position);
                        break;
                    case 2:
                        SDL_BlitSurface(deux, NULL, ecran, &position);
                        break;
                    case 3:
                        SDL_BlitSurface(trois, NULL, ecran, &position);
                        break;
                    case 4:
                        SDL_BlitSurface(quatre, NULL, ecran, &position);
                        break;
                }

            }
        }
        tempsActuel=SDL_GetTicks();




if (tempsActuel - tempsPrecedent >0)
{
    BlitTime(ecran,tempsEcoule);
    tempsEcoule=tempsEcoule+1;
    tempsPrecedent = tempsActuel;
}
else
{
    SDL_Delay(1 - (tempsActuel - tempsPrecedent));
}
if (tempsEcoule>3000)
{
    Perdu(ecran);
}

        SDL_Flip(ecran);



    }


}
