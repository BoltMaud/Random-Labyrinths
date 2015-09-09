#ifndef CHE
#define CHE

#include "lab.h"

// structure sur un chemin pointe sur le dernier element
typedef struct strchem { strpos * a ; struct strchem* suiv ; } *chem , strchem;

//renvoie un entier 0 ou 1
int unounull ();

//supprime la tete
void supt(chem c);

//ajout a la queue
chem adjq(chem c, pos a1);

//renvoie null
chem creation();

//détruit un chemin entier
void destruction (chem c);

//renvoie la longueur
int longueur(chem c);

//renvoie la pos de la tete
pos tete (chem c);

//fais un clone de c
chem clone (chem c);

//renvoie la kieme pos d'un chemin
strpos kieme_chem (chem c, int n);

//donne un nombre aleatoire d'un chemin
int alea_nb_chemin(chem c);

#endif
