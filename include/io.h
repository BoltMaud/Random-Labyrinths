#ifndef AFFICHAGE
#define AFFICHAGE
#include "lab.h"
#include "chemin.h"

//rend le terminal vide
void efface (laby l);

//affiche le laby avec des chiffres : 0=mur;1=chemin;8=bonhomme
void affichage(laby l);

//fonction inutile puisque je retire les murs au fur et à mesure
void affichage_chemin_init (laby l, chem c);

//modifie la position du 8
void deplacer_bonhomme(laby l, strpos a1, strpos a2);

//fonction "finale"
void interface_graph(laby l, chem chemin);

//autre affichage sous l'exemple de M.sauvage
void copie_affichage_sauvage (laby lab);

//affichage de M.Sauvage
void affiche_ligne (int c, Bool* ligne);

//affichage de M.Sauvage
void affiche_trait (int c);

//mise en page : donne les regles du jeu
void cmd_et_regle();

//AFFICHE la fin
void GAGNE(chem chemin, laby l);


#endif // AFFICHAGE
