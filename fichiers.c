#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<stdbool.h>

#include "constantes.h"


int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR],int numero,int difficulte)
{
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    int i = 0, j = 0;
    switch(difficulte)
    {
    case 1:
        fichier = fopen("difficile.txt", "r");
        break;
    case 2:
        fichier = fopen("facile.txt", "r");
        break;
    case 3:
        fichier = fopen("moyen.txt", "r");
        break;
    }

    if (fichier == NULL)
    return 0;
    fseek(fichier,(numero-1)*16,0);
    fgets(ligneFichier, (NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR )+ 1, fichier);
    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {

            switch (ligneFichier[(i * NB_BLOCS_LARGEUR) + j])
            {
                case '0':
                    niveau[j][i] = 0;
                    break;
                case '1':
                    niveau[j][i] = 1;
                    break;
                case '2':
                    niveau[j][i] = 2;
                    break;
                case '3':
                    niveau[j][i] = 3;
                    break;
                case '4':
                    niveau[j][i] = 4;
                    break;
            }
        }
    }

    fclose(fichier);
    return 1;
}



