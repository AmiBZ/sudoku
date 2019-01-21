#include "user.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int listeVide(listeUsers l){
	if(l == NULL)
		return 1;
	return 0;

}
donnee *saisirUser(int *n){ 

    donnee *Nouveau= Malloc(donnee);
	
    (*n)++;
    printf("\t\t Loging: ");
    scanf("%s",Nouveau->lg);
    printf("\t\t Pass word: ");
    scanf("%s",Nouveau->pw);
    
    return Nouveau;
}

user *creerUser(donnee *d){
    user *point_new=Malloc(user);
    point_new->infos=d;
    point_new->suivant=NULL;
    return point_new;
}

listeUsers insererUser(donnee *d,listeUsers l){


listeUsers p=creerUser(d); // contient l nouveau adh a inserer
listeUsers pl;	// pour parcourir la liste
listeUsers q;	// aider a inserer au milieu d la liste
			
		pl=l;
		 
						if( listeVide(l) || ( !listeVide(l) && strcmp(d->lg,pl->infos->lg)<0))
						{
							p->suivant=pl;
							pl=p;
							return pl;
						}else
					{
					q=pl;
					pl=pl->suivant;
					while(pl &&  strcmp(d->lg,pl->infos->lg)>0) {
						q=pl;
						pl=pl->suivant;
						}
						
					p->suivant=pl;
					q->suivant=p;
						
				return l; 		
		     	}
	
}

void afficherUsers(listeUsers liste){
listeUsers aux;
	if(liste==NULL){
		printf("il n'existe aucun user \n");
		return;
	}
	aux = liste; //on se place au début
	while(aux != NULL){
		printf("%s\t",aux->infos->lg);
		printf("%s\n",aux->infos->pw);
		
		aux = aux->suivant;
	}
	return;
}


listeUsers supprimerUser(listeUsers l,char *lg,int *n){

listeUsers pl=l,q;

	if(l==NULL){
			printf("il n'existe aucun user \n");
			return l;
		}
		if(!strcmp(lg,pl->infos->lg)){
			l=pl->suivant;
			free(pl);
			(*n)--;
			return l;
		}	
		q=pl;
		pl=pl->suivant;
		while(pl &&  (strcmp(lg,pl->infos->lg))) {
			q=pl;
			pl=pl->suivant;
		}
		if(pl){					
		q->suivant=pl->suivant;
		free(pl);
		(*n)--;
		}
		else
			printf("il n'existe aucun user \n");
		
		return l; 		
   	}


listeUsers charger(char* nomfichier1,char* nomfichier2, int* n) {
    listeUsers liste=Malloc(user);
	liste=NULL;
    FILE* file1;
    file1=fopen(nomfichier1,"rb");
	FILE* file2;
    file2=fopen(nomfichier2,"rb");
    if (file1==NULL || file2==NULL){
        printf("Erreur dans le chargement du fichier\n");
        exit(0);
    }
	fread(n, sizeof(int),1,file1);
	fread(n, sizeof(int),1,file2);

	printf("|=>n: %d\n",*n);
 	printf("\n~~ Les lg et pw existants dans votre fichier:\n\n");
 	for (int i = 0; i < *n; i++) {
        donnee* d=Malloc(donnee);
        fread(d->lg,50*sizeof(char),1,file1);
		printf("|=>lg: %s\t\n",d->lg);
        fread(d->pw,50*sizeof(char),1,file2);
        printf("|=> pw: %s\t\n",d->pw);
		liste=insererUser(d,liste);
    }
    
	fclose(file2);
	fclose(file1);

    return liste;
}

void sauvegarder(char* nomfichier1,char* nomfichier2, int n, listeUsers liste) {
    listeUsers aux;
    FILE* flot1=fopen(nomfichier1,"wb");
	FILE* flot2=fopen(nomfichier2,"wb");
    fwrite(&n,sizeof(int),1,flot1);
	fwrite(&n,sizeof(int),1,flot2);

    aux=liste; 
    while(aux!=NULL){
		//printf("|=>lg a svgrder: %s\t\n",aux->infos->lg);
        fwrite(aux->infos->lg,50*sizeof(char),1,flot1);
		//printf("|=>pw a svgrder: %s\t\n",aux->infos->pw);
        fwrite(aux->infos->pw,50*sizeof(char),1,flot2);
		aux=aux->suivant;
    }
	
	fclose(flot2);
	fclose(flot1);
    printf("\n~~ Sauvegardage terminé!\n");
    
}
