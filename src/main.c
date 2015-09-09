#include "lab.h"
#include "chemin.h"
#include "io.h"
#include "jeu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{	int a,b,d;
    printf("Donner le nombre de colones (>2):\n");
    scanf("%d",&a);
    printf("Donner le nombre de lignes (>2): \n");
    scanf("%d",&b);
    printf("Donner le pourcentage de cases mur (optimal entre 40 et 70): \n");
    scanf("%d",&d);
    printf("\x1B[2J");//efface tout ce qui se trouve dans le terminal
    srand(time(NULL));//pour les aleatoires
    laby l = init();//alloue la place pour la structure
    cree_lab(a,b,l);//creation du tableau (avec les allocs)


    chem c =chem_init(l,entree(l),sortie(l));//creation du chemin initial aleatoire avec entree et sortie aleatoires
    c=finition(l,c,pourcentage_voulu(d,l));//pourcentage de murs voulus
    affichage(l);
    cmd_et_regle();
    interface_graph(l,c);//jeu
    destruction(c);//free du chemin
    libere_lab(l);// free du lab

    return 0;
}
