#include <stdlib.h>
#include <iostream>
#include "terrain.h"
#include "bombe.h"

void Jeu_Affichagetemporaire(const Terrain &t);
//Procédure temporaire d'affichae du terrain

int main(void)
{
    Terrain jeu;
    Bombe test;
    // Initialisation du jeu en niveau 2
    Terrain_initialisation(jeu,2);
    //Affichage
    Jeu_Affichagetemporaire(jeu);
    printf("\n");
    //On tente de poser une bombe aux coordonnée (0,0)
    Bombe_bombe(test,jeu,0,0);
    system("clear");
    //Affichage du résultat
    Jeu_Affichagetemporaire(jeu);


    Terrain_testament(jeu);

    return EXIT_SUCCESS;
}

void Jeu_Affichagetemporaire(const Terrain &t)
{
   int i,j;
   for (i=0;i<=t.dim-1;i++)
    {
        for (j=0;j<=t.dim-1;j++)
        {
            Terrain_affichageCase(t,j,i);

        }
        printf("\n");
    }
}
