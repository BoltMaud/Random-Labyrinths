#ifndef LABY
#define LABY

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//booleen
typedef enum {true=1,false=0,bonhomme=8,} Bool;

//pointeur sur structure pour un labyrinthe et structure
typedef struct strlab  { int x ; int y ; Bool** v ; } *laby, strlab ;

// structure sur une position et pointeur
typedef struct strpos { int x ; int y ; } *pos , strpos ;

//creation d'un labyrinthe avec c pour les colones et l pour les lignes (lab vaut simplement init())
void cree_lab(int l,int c,laby lab);

//libere labyrinthe, fait les free
void libere_lab(laby lab);

//alloue la place pour la structure
laby init ();

//renvoie 1 pour un mur et 0 sinon
int contraire_case(int i);

//compte le nombre de case murs
int Nb_cases_Mur (laby l);

//met à 1 la case du laby correspondant à pos p
void retirerMur (laby l, pos p);

//met 0 à la pos
void AjoutMur (laby l, pos p);

//met à 8 la case du laby correspondant à pos p
void bonhomme_init(laby l, pos p);

//renvoie vrai si ya pas de mur et false sinon
Bool case_chemin (laby l, strpos p);

//traduit en entier le pourcentage voulu de mur
int pourcentage_voulu(int i, laby l);


#endif // LABY
