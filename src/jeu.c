#include "jeu.h"
#include "chemin.h"
#include "lab.h"
#include <time.h>

/*
*\fn strpos entree(laby l);
* donne une position aleatoire pour l'entree (y=l->y-1)
*\paramètre :  laby : un pointeur sur un labyrinthe
*\return strpos : une position
*/
strpos entree(laby l)
{
    strpos ent;
    ent.x=alea_x(l);
    ent.y=(l->y)-1;
    if(ent.x<=0) ent.x=5;
    return ent;
}

/*
*\fn strpos sortie(laby l);
* donne une position aleatoire pour la sortie (y=0)
*\paramètre :  laby : un pointeur sur un labyrinthe
*\return strpos : une position
*/
strpos sortie(laby l)
{
    strpos sort;
    sort.x=alea_x(l)-1;
    if(sort.x<=0)sort.x=1;
    sort.y=0;
    return sort;
}

/*
*\fn strpos monter (pos b);
*\paramètre :  pos : un pointeur sur structure d'une position
*\return strpos : une position avec les coordonnées de l'ancienne un cran plus haut
*/
strpos monter (pos b)
{
    strpos a;
    a.x=b->x;
    a.y=(b->y)-1;
    return a;
}
/*
*\fn strpos descendre (pos b);
*\paramètre :  pos : un pointeur sur structure d'une position
*\return strpos : une position avec les coordonnées de l'ancienne un cran plus bas
*/
strpos descendre (pos b)
{
    strpos a;
    a.x=b->x;
    a.y=(b->y)+1;
    return a;
}
/*
*\fn strpos gauche (pos b);
*\paramètre :  pos : un pointeur sur structure d'une position
*\return strpos : une position avec les coordonnées de l'ancienne un cran à gauche
*/
strpos gauche (pos b)
{
    strpos a;
    a.y=b->y;
    a.x=(b->x)-1;
    return a;
}
/*
*\fn strpos droite (pos b);
*\paramètre :  pos : un pointeur sur structure d'une position
*\return strpos : une position avec les coordonnées de l'ancienne un cran à droite
*/
strpos droite (pos b)
{
    strpos a;
    a.x=(b->x)+1;
    a.y=(b->y);
    return a;
}


/*
*\fn int alea_x (laby l);
* fonction qui donne un chiffre alea dans les abscisses, utile pour entree(l) et sortie(l)
*\paramètre :  laby : un pointeur sur un labyrinthe
*\return x : un entier
*/
int alea_x (laby l)
{
    int x;
    x=(int)rand()%(l->x-1);
    return x;
}

/*
*\fn Bool on_est_deja_passe_par_la(laby l, pos a);
* 1 = vrai ; 0=false
*\paramètre :  laby : un pointeur sur un labyrinthe
*\paramètre :  pos : pointeur sur position
*\return x : bool
*/
Bool on_est_deja_passe_par_la(laby l, pos a)
{
	if(a->x>=l->x || a->y>=l->y || a->y<0 || a->x<0 ) {return 1;} // renvoie mauvaise direction si on est en dehors du tableau
	else { return l->v[a->y][a->x];}
    }


/*
*\fn Bool ca_donnera_de_place_publique(laby l, pos a1);
* 1 = vrai ; 0=false
*\paramètre :  laby : un pointeur sur un labyrinthe
*\paramètre :  pos : pointeur sur position
*\return x : bool
*/
Bool ca_donnera_place_publique(laby l, pos a1)
{
    if (((l->v[a1->y][a1->x-1]==true)&&(l->v[a1->y-1][a1->x]==true)&&(l->v[a1->y-1][a1->x-1]==true))||//regarde si les trois cases en bas à gauche sont déjà utilisées
            ((l->v[a1->y][a1->x-1]==true)&&(l->v[a1->y+1][a1->x-1]==true)&&(l->v[a1->y+1][a1->x]==true))||//en haut à gauche
            ((l->v[a1->y+1][a1->x]==true)&&(l->v[a1->y+1][a1->x+1]==true)&&(l->v[a1->y][a1->x+1]==true))||//en haut à droite
            ((l->v[a1->y][a1->x+1]==true)&&(l->v[a1->y-1][a1->x+1]==true)&&(l->v[a1->y-1][a1->x]==true))) // en bas à droite
           { return true;}
    else return false;
}

/*
*\fn Bool on_est_au_bord(pos a,laby l)
* 1 = vrai ; 0=false
*\paramètre :  laby : un pointeur sur un labyrinthe
*\paramètre :  pos : pointeur sur position
*\return x : bool
*/
Bool on_est_au_bord(pos a,laby l){
	if((a->x==0)||(a->x==l->x-1)||(a->y==l->y-1)||(a->y==0)) { return 1;}
	else return 0;
}


/*
*\fn int *comparaison(pos av, pos ap, int* t);
* donne sous forme d'un tableau le choix entre monter (t[3]), descendre (t[2]), gauche (t[1]) et droite (t[0])
*\paramètre :  av=pos : pointeur sur structure position, la position avant la nouvelle qu'on va mettre dans le chemin
*\paramètre :  ap=pos : pointeur sur structure position, la pos nommé nouvelle dans chem_initial
*\return un tableau dont les valeurs initiales sont 0123 et vallent 4 si une direction est interdite
*/
int *comparaison(pos av, pos ap, int* t)
{
    if(ap->x==av->x+1)
    {
        t[0]=4 ;
        return t;
    }
    else
    {
        if(ap->x==av->x-1)
        {
            t[1]=4 ;
            return t;
        }
        else
        {
            if(ap->y==av->y+1)
            {
                t[2]=4 ;
                return t;
            }
            else
            {
                t[3]=4 ;
                return t;
            }
        }
    }

}


/*
*\fn Bool faut_refaire (int*i);
*si les 4 cases de mon tableau valent 4, il n'y a plus de directions disponibles
*\paramètre :  i: un tableau dont les valeurs initiales sont 0123 et vallent 4 si une direction est interdite
*\return un bool
*/
Bool faut_refaire (int*i)
{
    int j=0,rep=0;
    for(j=0; j<4; j++)
    {
        if(i[j]==4)rep=rep+1;
    }
    return (rep==4);
}


/*
*\fn strpos avancer (pos avant,  int* t);
* donne une direction aleatoire grace aux directions disponibles de mon tableau  t
*\paramètre :  t :un tableau dont les valeurs initiales sont 0123 et vallent 4 si une direction est interdite
*\paramètre :  avant=pos : pointeur sur structure de la position à laquelle on veut une "suite", une suivante
*\return strpos : une position "nouvelle" qui est à coté de avant
*/
strpos avancer (pos avant,  int* t)
{
    int x;
    x=(int)rand()%4;
    if (x==t[3]) return monter(avant);
    else
    {
        if (x==t[2]) return descendre(avant);
        else
        {
            if (x==t[1]) return gauche(avant);
            else
            {
                if (x==t[0]) return droite (avant);
                else return avancer(avant,t) ;
            }
        }
    }


}

/*
*\fn chem rapprochement_sortie(chem c, strpos sort, laby l);
* à la deuxième ligne, on va se positionner sous la sortie en allant soit à gauche soit à droite en fonction de sort->x
*\paramètre :  strpos sort : la sortie
*\paramètre :  c=chem : on en a besoin pour rajouter les nouvelles pos à la queue
*\paramètre :  laby l : on en a besoin pour retirerMur afin d'afficher le chemin
*\return c=chem renvoie le chemin complet
*/
chem rapprochement_sortie(chem c, strpos sort, laby l)
{
    chem temp=c;
    if(temp->a->x>sort.x)
    {
        while(temp->a->x>sort.x)
        {
            strpos nouvelle;
            nouvelle=gauche(temp->a);
            c=adjq(c,&nouvelle);
            retirerMur(l,&nouvelle);
            temp=temp->suiv;
        }
    }
    else
    {
        while(temp->a->x<sort.x)
        {
            strpos nouvelle;
            nouvelle=droite(temp->a);
            c=adjq(c,&nouvelle);
            retirerMur(l,&nouvelle);
            temp=temp->suiv;
        }
    }
    c=adjq(c,&sort);
    retirerMur(l,&sort);
    return c;
}

/*
*\fn chem chem_init(laby l, strpos ent, strpos sort);
* donne un chemin aleatoire et modifie le labyrinthe afin de pouvoir visualiser les places-publiques etc
*\paramètre :  strpos sort : la sortie
*\paramètre :  strpos ent : l'entree
*\paramètre :  laby l : labyrinthe
*\return c=chem renvoie le chemin complet
*/
chem chem_init(laby l, strpos ent, strpos sort)
{
    chem c =adjq(creation(),&ent); //je crée un chemin et ajoute a la queue(marche) l'entree
    bonhomme_init(l,&ent);
    int* i=(int*)malloc(4*sizeof(int)); // i vaut 0123 à la base et chaque case peut etre remplacee par 4 si on ne veut plus use
    while (c->a->y!=1)//tant qu'on est pas tout en haut on fait
    {
        strpos nouvelle;//on cree une position
        i[0]=0;
        i[1]=1;
        i[2]=4;
        i[3]=3;
        nouvelle=avancer(c->a,i);//on avance avec avancer
        while(on_est_au_bord(&nouvelle,l)||(ca_donnera_place_publique(l,&nouvelle))||(on_est_deja_passe_par_la(l,&nouvelle)))
        {
            i=comparaison(c->a,&nouvelle,i);
            nouvelle=avancer(c->a,i);
        }
        if(faut_refaire(i)) return chem_init(l,ent,sort);
        c=adjq(c,&nouvelle);
        retirerMur(l,&nouvelle);
    }
    c=rapprochement_sortie(c,sort,l);
    free(i);
    return c;
}

/*
*\fn Bool on_touche_ailleurs(pos av, strpos ap, laby l)
* regarde si on ne coupe pas un autre chemin
*\paramètre :  pos a : pointeur sur position, la position avant le changement
*\paramètre :  strpos ap : position, la position au moment, celle que l'on teste
*\return une strpos
*/
Bool on_touche_ailleurs(pos av, strpos ap, laby l){/*après est la position qu'on veut etudier*/
	int a=0;
	if(l->v[ap.y+1][ap.x]==0 /*si ona un mur en dessous*/|| ((av->x==descendre(&ap).x) && (av->y==descendre(&ap).y))) a++;/*si la case avant est dessous*/
	if(l->v[ap.y][ap.x+1]==0 /*si on a un mur à droite*/|| ((av->x==droite(&ap).x)&&(av->y==droite(&ap).y))) a++;/*si la case avant est à droite*/
	if(l->v[ap.y][ap.x-1]==0 /*si on a un mur à gauche*/||((av->x==gauche(&ap).x)&&(av->y==gauche(&ap).y))) a++;/*si la case avant est à gauche*/
	if(l->v[ap.y-1][ap.x]==0 /*si on a un mur au dessus */|| ((av->x==monter(&ap).x)&&(av->y==monter(&ap).y))) a++;/*si la case avant est dessus*/
	return a!=4;
}


/*
*\fn chem chemins_suivants(chem c_init,int longueur_max,laby l);
* cree un chemin à la suite du precedant
*\paramètre :  c_init le chemin initial
*\paramètre :  longueur : longueur voulue
*\paramètre :  laby l : labyrinthe
*\return c=chem renvoie le chemin complet
*/
chem chemins_suivants(chem c_init,int longueur_max,laby l)
{
    int stop=0;
    strpos posinit=kieme_chem(c_init,alea_nb_chemin(c_init));//on dit que la position choisit est la 15eme pour l'instant (après on fera aleatoirement)
    int* i=(int*)malloc(4*sizeof(int));//alloue le tableau des possibilités de directions
    c_init=adjq(c_init,&posinit);//rajoute la posinit à la fin (oui ca fait un doublon mais on en a besoin

    while(longueur_max!=0 && stop!=2)//tant que la longueur est pas fini
    {
        strpos nouvelle;//on cree une position
        i[0]=0;//on remet le tableau avec les choix
        i[1]=1;
        i[2]=2;
        i[3]=3;
        nouvelle=avancer(c_init->a,i);//on avance
        while((stop!=2)&&((on_est_au_bord(&nouvelle,l))||(on_est_deja_passe_par_la(l,&nouvelle))||(on_touche_ailleurs(c_init->a,nouvelle,l))))
               {
            i=comparaison(c_init->a,&nouvelle,i);//on enleve la direction qui marche pas
            if(faut_refaire(i)) stop++;//si tout le tableau est rempli de 4 on arrete le chemin
            else nouvelle=avancer(c_init->a,i);//sinon on fait une autre position avec avancer
        }
        if(stop!=2) {c_init=adjq(c_init,&nouvelle);//on ajoute la nouvelle posisition qui est possible
        retirerMur(l,&nouvelle);//on modifie le laby

        longueur_max--;
        }
    }
    free(i);
    return c_init;
}

/*
*\fn void finition(laby l, chem c,int pourcentage_traduit);
* remplissage du labyrinthe
*\paramètre :  pourcentage traduit : le pourcentage entree en nombre de case deja defini
*\paramètre :  c : le chemin initial
*\paramètre :  laby l : labyrinthe
*\return void : FIN
*/
chem finition(laby l, chem c,int pourcentage_traduit){
	while (Nb_cases_Mur(l)>pourcentage_traduit){
		c=chemins_suivants(c,longueur(c),l);
	}
	return c;
}

