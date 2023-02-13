#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int est_solution(int A[4][4]) {
	/*Fonction qui teste si la matrice donnée en paramètre verifie les
	règles du Sudoku.*/
	int i,j;
	int test=1;
	for(i=0;i<4;++i) {
		if(repeterbloc(A,i) || repetercolonne(A,i) || repeterligne(A,i))
			test = 0;
	}
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			if(A[i][j] == 0)
				test = 0;
		}
	}
	for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            if(A[i][j] != 1 && A[i][j] != 2 && A[i][j] != 3 && A[i][j] != 4 )
                return 0;
        }
	}
	return test;
}

int repeterligne(int A[4][4],int l) {
	/*Fonction qui verifie s'il ya une repetition de la même valeur
	dans une même ligne.*/
	int i,j,a;
	int repet=0;
	for(i=0;i<4 && !repet;i++) {
		for(j=i+1;j<4 && !repet;j++)
			if(A[l][i]==A[l][j])
				repet=1;
	}
	return repet;
}

int repetercolonne(int A[4][4],int c) {
	/*Fonction qui verifie s'il ya une repetition de la même valeur
	dans une même colonne.*/
	int i,j,a;
	int repet=0;
	for(i=0;i<4 && !repet;i++) {
		for(j=i+1;j<4 && !repet;j++)
			if(A[i][c]==A[j][c])
				repet=1;
	}
	return repet;
}
void copie_bloc(int A[4][4],int b,int T[4]) {
	/*Fonction qui copie les éléments du bloc d'indince "b"
	de la matrice A dans le tableau T */
	int i,j;
	if(b%2 == 0)
		for(i=b,j=0;i<=(b+1);i++,j+=2){
			T[j] = A[i][0];
			T[j+1] = A[i][1];
		}
	else
		for(i=b-1,j=0;i<=b;i++,j+=2){
			T[j] = A[i][2];
			T[j+1] = A[i][3];
		}
}
int repeterbloc(int A[4][4],int b) {
	/*Fonction qui verifie s'il ya une repetition de la même valeur
	dans un même bloc.*/
	int i,j;
	int repet=0;
	int T[4];
	copie_bloc(A,b,T);
	for(i=0;i<4 && !repet;i++) {
		for(j=i+1;j<4 && !repet;j++)
			if(T[j]==T[i])
				repet = 1;
	}
	return repet;
}

