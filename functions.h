#ifndef RP
#define RP
#include<stdio.h>
#include<stdlib.h>
int BlitTime(SDL_Surface *ecran,int tempsEcoule);
void affichage(int sudoku[4][4]);
bool absentSurLigne(int n ,int sudoku[4][4] ,int i);
bool absentSurColonne(int n ,int sudoku[4][4] ,int j);
bool absentSurBloc(int n, int sudoku[4][4], int i0, int j0);
bool Solveur(int sudoku[4][4], int position);
#endif
