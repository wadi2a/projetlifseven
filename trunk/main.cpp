#include <stdlib.h>
#include <iostream>
#include "bomberman.h"
#include "terrain.h"
#include "time.h"

void Jeu_Affichagetemporaire(const Terrain &t);
//Procédure temporaire d'affichae du terrain

int main(void)
{
    Bombe test;
    Terrain jeu;
    Bomberman perso;
    Bomberman_Initialisation(perso);
    Bomberman_Setposx(perso,2);
    Bomberman_Setposy(perso,0);
    Terrain_initialisation(jeu,2);
    int vie = Bombeman_Getnbvie(perso);
    //Affichage
    Jeu_Affichagetemporaire(jeu);
    printf("\n");
    printf("%d",vie);
    printf("\n");
    sleep(5);

    //On tente de poser une bombe aux coordonnée (x,y)

    if (Bombe_posebombe(test,2,0,jeu,1))
        {
                Case a;
                strcpy(a.carre,"bombe");
                Terrain_Setcase(jeu,a,2,0);
                Jeu_Affichagetemporaire(jeu);
                printf("\n");

                Bombe_minuteur(3);

                if (Bomberman_PresenceSurTrajetBombe(perso,test)) Bomberman_Decrementevie(perso);
                vie = Bombeman_Getnbvie(perso);
                Bombe_ExplosionSurTerrain(test,jeu);
        }

    // Ce if correspondra a une fonctione finale regroupant tout lorsque l'on pose une bombe
    Jeu_Affichagetemporaire(jeu);
    sleep(3);
    printf("%d",vie);

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
