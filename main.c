#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include<SDL.h>
#define RESET 0
#include "sudoku44.h"
#include "user.h"



/*
SDL_version nb;
SDL_VERSION(&nb);
 
printf("\nmaj %d .. min %d ... patch %d ..\n",nb.major,nb.minor,nb.patch);


*/
void sudoku(){

    int i,j,solution=0,nCellVide;
    char ch;
    printf("\t\t\tYou can change the puzzle before running the program \n\t\t\tby changing the values in the \"grid\" array\n\n");
    printf("\t\t\tThe Entered Sudoku puzzle is: \n");
    printGrid();
    printf("\t\t\tPress 'c' to confirm and solve, or 'e' to exit: ");
    ch=getch();
    if(ch=='e')
       exit(0);
    else if(ch=='c'){
   
		nCellVide=nEmptyCell();
		if(nCellVide){	
			sol_user();
		}
		printf("\t\t\t\n-----\n");
		prin();
		printf("\t\t\t\n-----\n");
	
	solution=sudokuSolver();
    if(solution){
	 printf("\n\t\t\tThe Solved Sudoku is: \n\n");
	 printGrid();
    }
    else
    printf("\n\t\t\tSolution Non valide !!\n\n");
    getch();
    }

}


int c=0;
void main(){
	
	printf("\n\t\t\t########### MENU DES User ###########\n\n");

	int reponse,code,continuer=1,n=0;

    listeUsers l=NULL;
	char lg[20];
	char* nomfichier1="lg.dta";
	char* nomfichier2="pw.dta";

    l=charger(nomfichier1,nomfichier2,&n); 
		donnee * d1;
	do
    {

        printf("\n\t\t\t########### MENU DES User ###########\n\n");
        printf("\t\t\t\t1.Ajouter un User\n");
		printf("\t\t\t\t2.Afficher la liste des Users\n");
        printf("\t\t\t\t3.supprimer User un User\n");
        printf("\t\t\t\t4.Jouer\n\n");
		printf("\t\t\t\t0.Quiter\n\n");

        printf("\t\t\t#####################################\n\n");
        printf("\t\t\tDonner votre choix: ");

        /**********************************/
        scanf("%d",&reponse);
        switch(reponse)
        {
			case 1:
						

				d1=saisirUser(&n);

				l=insererUser(d1,l);
				printf("\nUser saisi \n");
				system("pause");
				system("cls");
				
					break;
			
			case 2:
				afficherUsers(l);
				system("pause");
				system("cls");
				break;
			
			case 3:

				printf("\t\tEntrer le lg du User a supprimer de la liste: ");
				scanf("%s",lg);
				l=supprimerUser(l,lg,&n);
				system("pause");
				system("cls");
				break;
			case 4:
			system("pause");
				system("cls");
				sudoku();
				
				break;
			case 0:
                sauvegarder(nomfichier1,nomfichier2,n,l);
                exit(1);	
			
		
        }
    }
    while(continuer==1);
}



