#include "lab.h"

/*
*\fn laby init ()
* alloue l'espace de la structure labyrinthe
*\return l : un labyrinthe vide
*/
laby init ()
{
    laby l;
    l=(laby)malloc(sizeof(strlab));
    l->x=0;
    l->y=0;
    l->v=NULL;
    return l;
}

/*
*\fn void cree_lab(int c,int l,laby lab);
* alloue les cases du labyrinthe représentées par des Bool
*\paramètre :  c : nombre de colones voulues
*\paramètre :  l : nombre de lignes voulues
*\paramètre :  lab : un labyrinthe si possible init()
*\return l : un labyrinthe complet, rempli de mur(=false)
*/
void cree_lab(int c,int l,laby lab)
{
    lab->y=l; // ligne
    lab->x=c; // colonne
    int i, j ;
    int k;
    lab->v=(Bool**)malloc((lab->y)*sizeof(Bool*));
    for (k=0;k<lab->y;k++)
        lab->v[k]=(Bool*)malloc((lab->x)*sizeof(Bool));

    for (j=0;j<lab->y;j++)
    {
        for (i=0;i<lab->x;i++)
        {
            lab->v[j][i]=false;//initialise à mur
        }
    }
    return;
}

/*
*\fn void libere_lab(laby lab);
*fais les free necessaires
*/
void libere_lab(laby lab)
{
    int i, l=lab->y;
    for (i=0; i<l; ++i) free(lab->v[i]);
    free (lab->v);
    free(lab);
}

/*
*\fn laby ajouterMur (laby l, pos p);
*met une case à false
*\paramètre :  p=pos : un pointeur sur structure
*\paramètre :  l=laby : pointeur sur structure
*\return renvoie le même laby avec une case Mur suplémentaire
*/
void AjoutMur (laby l, pos p){
	l->v[p->y][p->x]=false;
    return ;
}

/*
*\fn void retirerMur (laby l, pos p);
*met une case à true
*\paramètre :  p=pos : un pointeur sur structure
*\paramètre :  l=laby : pointeur sur structure
*\return void : affecte directement le laby
*/
void retirerMur (laby l, pos p)
{
    l->v[p->y][p->x]=true;
    return ;
}



/*
*\fn void bonhomme_bouge(laby l, pos p);
*met une case à "bonhomme"
*\paramètre :  p=pos : un pointeur sur structure
*\paramètre :  l=laby : pointeur sur structure
*\return void : affecte directement le laby
*/
void bonhomme_init(laby l, pos p){
		l->v[p->y][p->x]=8;
		return;
		}


/*
*\fn Bool case_chemin (laby l, strpos p)
* vrai=la pos est un chemin, false=pos est un mur
*\paramètre :  p=pos : un pointeur sur structure
*\paramètre :  l=laby : pointeur sur structure
*\return Bool
*/
Bool case_chemin (laby l, strpos p)
{
    return l->v[p.y][p.x];
}

/*
*\fn int contraire_case(int i);
* utile pour compter le nombre de murs
*\paramètre :  i un entier valant 1 ou 0 ou 8
*\return i : le contaire; si i=1 alors 0 sinon 1
*/
int contraire_case(int i)
{
    if (i==1 || i==8) return 0;
    else return 1;
}

/*
*\fn int Nb_cases_Mur (laby l);
* compter le nombre de murs
*\paramètre :  l=laby
*\return somme=int : le nombre de case MURs
*/
int Nb_cases_Mur (laby l)
{
    int j,k;
    int somme=0;
    for (k=0;k<l->y-1;k++)
    {
        for (j=0;j<l->x-1;j++)
        {
            somme=somme+contraire_case(l->v[k][j]);
        }
    }
    return somme;
}

//SEULE FONCTION AVEC PRECONDITION
/*
*\fn int pourcentage_voulu(int i, laby l);
* donne le nombre de case du pourcentage voulu
*\paramètre :  int i : chiffre entre 50 et 60
*\paramètre :  l=laby
*\return le nombre de case à garder en mur
*/
int pourcentage_voulu(int i, laby l){
	int a=(l->x)*(l->y)*i/100;
	return a;
}


