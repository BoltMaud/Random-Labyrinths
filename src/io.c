#include "io.h"
#include "lab.h"
#include "chemin.h"
#include "jeu.h"

/*
*\fn void affichage(laby l);
* affiche le laby sous forme de chiffre (0=mur,1=chemin,8=bonhomme)
*\paramètre :  laby : structure sur labyrinthe
*\return void : affiche à l'écran
*/
void affichage(laby l)
{
    int i,j;
    for (i=0; i<l->y; i++)
    {
        printf("\n");
        for (j=0; j<l->x; j++)
        {

            printf("%d ",l->v[i][j]);
        }
    }
    printf("\n");

}

/*
*\fn void deplacer_bonhomme(laby l, strpos a1, strpos a2);
* fait bouger le chiffre 8 (bonhomme) et met à 1 la case précédante car c'est censé etre un chemin
*\paramètre :  laby : structure sur labyrinthe
*\paramètre :  strpos a1 : position avant du bonhomme
*\paramètre :  strpos a2 : position au moment du bonhomme
*\return void : modification du laby
*/
void deplacer_bonhomme(laby l, strpos a1, strpos a2)
{
    l->v[a1.y][a1.x]=true;
    l->v[a2.y][a2.x]=8;
    return;
}

/*
*\fn void affichage_chemin_init (laby l, chem c);
* fonction inutile car j'ai besoin de suppr mes murs au fur et a mesure pour place-publique et deja-passé-par-la
*/
void affichage_chemin_init (laby l, chem c)
{
    chem temp=c;
    while (temp->suiv->a->y!=0)
    {
        retirerMur(l,temp->a);
        temp=temp->suiv;
    }
    retirerMur(l,temp->a);
    return;
}

/*
*\fn void efface (laby l);
* efface la grille precedante
*\paramètre :  laby : structure sur labyrinthe
*\return void : renvoie du rien
*/
void efface (laby l)
{
    printf("\x1B[2J");
    }
/*
*\return void : affiche les bords
*/
void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}
/*
*\return affiche une ligne avec le symbole X pour un mur
*/
void affiche_ligne (int c, Bool* ligne){
	int i;
	for (i=0; i<c; ++i)
		if (ligne[i] == 1 ) printf ("|   "); else { if (ligne[i] == 8 ) printf ("| O ");
				else printf ("| X ");
		}
	printf("|\n");
	return;
}
/*
*\fn void copie_affichage_sauvage (laby lab);
*affichage sous l'exemple du professeur Sauvage dans son projet "jeu de la vie"
*/
void copie_affichage_sauvage (laby lab){
	int i, l=lab->y, c=lab->x;
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, lab->v[i]);
		affiche_trait(c);
	}
	printf("\n");
	return;
}

/*
*\return void : fonction affichage de textes
*/
void cmd_et_regle(){
	printf("		\033[25mLABYRINTHE\033[0;m\n");
	printf("a : changer le mode d'affichage\n");
	printf("h : aller en HAUT\t");
	printf("b : aller en BAS\n");
	printf("d : aller à DROITE\t");
	printf("g : aller à GAUCHE\n");
	printf("q : QUITTER\n\n ");
	printf("_");
}

void GAGNE(chem c, laby l){

	printf("\x1B[2J");
	printf("\n \n \n \t \t VOUS AVEZ GAGNE\n");
	}

/*
*\fn pointeur sur fonction affichage (permet de passer d'un affichage à un autre
*/
void (*style_affichage) (laby) = affichage ;

/*
*\fn void interface_graph(laby l, chem chemin);
* pour faire avancer le bonhomme avec h d g b
*\paramètre :  laby : structure sur labyrinthe
*\paramètre :  chem : structure sur chemin
*\return void : modification du laby et quitte avec q
*/
void interface_graph(laby l, chem chemin)
{
    char chara = getchar();
    strpos a1;
    a1.x = chemin->suiv->a->x;
    a1.y = chemin->suiv->a->y;
    strpos a2;
    while (chara != 'q') // touche 'q' pour quitter
    {
        switch (chara)
        {

		case 'a':{
		if(style_affichage==copie_affichage_sauvage) style_affichage=affichage;
		else style_affichage=copie_affichage_sauvage;
		efface(l);
		style_affichage(l);
		cmd_et_regle();
		break;
		}
        case 'b' :
        {
            if (case_chemin(l,descendre(&a1)))
            {
                a2=descendre(&a1);
                deplacer_bonhomme(l,a1,a2);
                a1=a2;
                efface(l);
                style_affichage(l);
                cmd_et_regle();
            }
            else { efface(l);
                style_affichage(l);
                cmd_et_regle();}
            break;
        }
        case 'h':
        {
            if(case_chemin(l,monter(&a1)))
            {
                a2=monter(&a1);
                if(a2.y==0 ) {GAGNE(chemin,l); chara='q'; }
                else {
                deplacer_bonhomme(l,a1,a2);
                a1=a2;
                efface(l);
                style_affichage(l);
                cmd_et_regle();
                }
            }
            else { efface(l);
                style_affichage(l);
                cmd_et_regle();}
            break;
        }
        case 'd':
        {
            if(case_chemin(l,droite(&a1)))
            {
                a2=droite(&a1);
                deplacer_bonhomme(l,a1,a2);
                a1=a2;
                efface(l);
                style_affichage(l);
                cmd_et_regle();
            }
            else { efface(l);
                style_affichage(l);
                cmd_et_regle();}
            break;
        }
        case 'g':
        {
            if(case_chemin(l,gauche(&a1)))
            {
                a2=gauche(&a1);
                deplacer_bonhomme(l,a1,a2);
                a1=a2;
                efface(l);
                style_affichage(l);
                cmd_et_regle();
            }
            else { efface(l);
                style_affichage(l);
                cmd_et_regle();}
            break;
        }
        default :
        {
            // touche non traitée
            printf("\n\e[1A");
            break;
        }
        }
        if (chara !='q') chara = getchar();
    }
}


