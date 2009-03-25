#include <stdlib.h>
#include <iostream>
#include "terrain.h"

int main(void)
{
    Terrain jeu;
    Terrain_initialisation(jeu,2);
    int i,j;


    for (i=0;i<=jeu.dim/jeu.dim;i++)
    {
        for (j=0;j<=jeu.dim/jeu.dim;j++)
        {
            Terrain_affichageCase(jeu,i,j);

        }
        printf("\n");
    }
    /*char a[10],b[10],c[10],d[10];
    strcpy(a,jeu.plateau[0].carre);
    strcpy(b,jeu.plateau[1].carre);
    strcpy(c,jeu.plateau[2].carre);
    strcpy(d,jeu.plateau[3].carre);
    std::printf("%s ",a);
    std::printf("%s ",b);
    std::printf("%s ",c);
    std::printf("%s ",d);*/

    Terrain_testament(jeu);
    return EXIT_SUCCESS;
}
