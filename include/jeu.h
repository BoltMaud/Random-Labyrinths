#ifndef JEU
#define JEU
#include "lab.h"
#include "chemin.h"

//renvoie une position aleatoire pour l'entree dans le cadre de lab
strpos entree(laby l);

//renvoie une position aleatoire pour la sortie dans le cadre de lab
strpos sortie(laby l);

//renvoie une nouvelle pos à cote de b, ne change pas b
strpos monter (pos b);
strpos descendre (pos b);
strpos gauche (pos b);
strpos droite (pos b);

//renvoie un nombre aleatoire entre 1 et l->x-1 (pour l'entree et la sortie)
int alea_x (laby l);

// regarde si (pos a)  est déjà à 1 dans le laby
Bool on_est_deja_passe_par_la(laby l, pos a);

//regarde si les 4 cas de trois cases à coté de (pos a1) sont à 1 dans le laby
Bool ca_donnera_place_publique(laby l, pos a1);

//dit si on est au bord
Bool on_est_au_bord(pos a,laby l);

//donne le chemin aleatoire initial de la sortie à l'entree
chem chem_init (laby l, strpos ent, strpos sort);

//renvoie une position à coté de avant(pos) parmis les choix possibles du tableau t
//t vaut 0123 à la base, une valeur à 4 est inaccessible
//t[0]=droite ; t[1]=gauche ; t[2]=descendre ; t[3] =monter
strpos avancer (pos avant, int*t);

//si les 4 cases du tableau valent 4, il n'y a plus de directions possibles
Bool faut_refaire (int*i);

//met à 4(inaccessible) la case du tableau correspondant à la direction de av à ap car elle ne marche pas
int *comparaison(pos av, pos ap, int* t);

//regarde si on ne touche pas ailleurs
Bool on_touche_ailleurs(pos av, strpos ap, laby l);

//cree un chemin suivant à partir du premier
chem chemins_suivants(chem c_init,int longueur_max,laby l);

//remplissage du labyrinthe
chem finition(laby l, chem c,int pourcentage_traduit);


#endif // JEU

