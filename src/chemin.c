#include "chemin.h"
#include "lab.h"
#include "jeu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
*\fn int unounull ();
* renvoie 1 ou 0
*/
int unounull ()
{
    int x;
    x=(int)rand()%2;
    return x;
}


/*
*\fn chem creation();
* renvoie NULL pour un chemin
*/
chem creation()
{
    return NULL;
}

/*
*\fn chem adjq(chem c, pos a1);
* ajout à la queue une position dans le chemin
*\paramètre :  c de type chem (pointeur sur structure)
*\paramètre :  a1 de type pos (pointeur sur structure)
*\return c1 pointeur sur la queue
*/
chem adjq(chem c, pos a1)
{
    chem c1=(chem)malloc(sizeof(strchem));
    c1->a=(pos)malloc(sizeof(strpos));
    c1->a->x=a1->x;
    c1->a->y=a1->y;
    if (c==NULL) c1->suiv=c1;
    else
    {
        c1->suiv=c->suiv;
        c->suiv=c1;
    }
    return c1;
}

/*
*\fn void supt(chem c);
* supprime la premiere pos du chemin
*\paramètre :  c de type chem (pointeur sur structure)
*/
void supt(chem c)
{
    if (c->suiv==c) { free(c->a);
        free(c);
    }
    else
    {
        chem temp;
        temp=c->suiv;
        c->suiv=c->suiv->suiv;
        free(temp->a);
        free(temp);
        return ;
    }
}

/*
*\fn void destruction (chem c)
* supprime toutes les pos du chemin
*\paramètre :  c de type chem (pointeur sur structure)
*/
void destruction (chem c)
{
    int i=longueur(c);
    while (i!=0)
    {
        supt(c);
        i--;
    }

}

/*
*\fn int longueur (chem c);
*\paramètre :  c de type chem (pointeur sur structure)
*\return l le nombre de position du chemin
*/
int longueur (chem c)
{
    chem temp=c;
    int l=0;
    if (c!=NULL)
    {
        l++;
        while (temp->suiv!=c)
        {
            temp=temp->suiv;
            l++;
        }
    }
    return l;
}

/*
*\fn pos tete (chem c);
*\paramètre :  c de type chem (pointeur sur structure)
*\return la premiere position du chemin
*/
pos tete (chem c)
{
    return c->suiv->a;
}

/*
*\fn Bool vide (chem c);
* vrai si vide, faux sinon
*\paramètre :  c de type chem (pointeur sur structure)
*\return bool = vrai si vide
*/
Bool vide (chem c)
{
    if (c==NULL) return true;
    else return false ;
}

/*
*\fn chem clone (chem c);
* clone dans le tas un chem
*\paramètre :  c de type chem (pointeur sur structure)
*\return chem, le clone
*/
chem clone (chem c)
{
    chem temp=c->suiv;
    chem c1=creation();
    while (temp!=c)
    {
        adjq(c1,(temp->a));
        temp=temp->suiv;
    }
    return c1;
}


/*
*\fn int alea_nb_chemin(chem c)
* utile pour choisir une position aleatoire
*\paramètre :  chem : pointeur sur structure
*\return un nombre aleatoire entre 1 et lg-1
*/
int alea_nb_chemin(chem c){
	int x;
    x=(int)rand()%((longueur(c)-1));
    if(x==0) x=2;
    return x;
	}

/*
*\fn strpos kieme_chem (chem c, int n);
* utile pour dire qui est la position à partir de laquelle on va faire notre nouveau chem
*\paramètre :  chem : pointeur sur structure
*\return une strpos
*/
strpos kieme_chem (chem c, int n){
	chem temp=c->suiv;
	while(n!=1){
	n--;
	temp=temp->suiv;
	}
	return *(temp->a);
}








