#define Malloc(t) (t*)malloc(sizeof(t));


typedef struct _user{
char lg[50];
char pw[50];
}donnee;

typedef struct  user {
	donnee* infos;
	struct  user* suivant;
}user;

typedef user* listeUsers;

donnee *saisirUser(int *n);
user *creerUser(donnee *d);
listeUsers insererUser(donnee *d,listeUsers liste);
void afficherUsers(listeUsers liste);
listeUsers supprimerUser(listeUsers liste,char *lg, int* n);
listeUsers charger(char* nomfichier1,char* nomfichier2, int* n);
void sauvegarder(char* nomfichier1,char* nomfichier2, int n, listeUsers liste); 