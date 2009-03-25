#include <stdlib.h>
#include <iostream>
#include "terrain.h"


Case * Terrain_Getcase(Terrain &t,const int &posx,const int &posy)
{
    return &t.plateau[posy*t.dim + posx]; //Accesseur pour simplifier l'accès au tableau 2D <=> t[x][y] et remplace t[x*t.dim +y] :)
}

void Terrain_Setcase(Terrain &t, const Case &c, const int &posx,const int &posy)
{
        t.plateau[posy*t.dim + posx] = c; // Mutateur
}

void Terrain_initialisation(Terrain & t, const int &niveau)
{
    // Affectation tableaux pour chaque niveaux
        t.dim=2;
        t.plateau = new Case[t.dim*t.dim]; // On prend un tableau 1D de taille 15*15, pour accéder à la positio (x,y) on effectue t[y*15 + x] Allouer un teableau 2D dynamiquement est compliqué !!!

        /* Initialisation des tableaux pour chaque niveaux : c'est un tableau 1D que l'on utilise comme un 2D !!!
        exemple pour un plateau 2x2 : on a un tableau 1D de 4 cases; les deux premieres cases correspondent à (0,0) et (0,1), les deux autres sont
         (1,0) et (1,1) */

         // Exemple pour test du module
        if (niveau == 1)
        {
            Case a,b,c;
            Case_initialisation(a);
            strcpy(b.carre,"mursolide");
            strcpy(c.carre,"mur");
            Terrain_Setcase(t,a,0,0);
            Terrain_Setcase(t,b,0,1);
            Terrain_Setcase(t,a,1,0);
            Terrain_Setcase(t,c,1,1);
        }else{
            Case a,b,c;
            Case_initialisation(a);
            strcpy(b.carre,"mursolide");
            strcpy(c.carre,"mur");
            Terrain_Setcase(t,b,0,0);
            Terrain_Setcase(t,a,0,1);
            Terrain_Setcase(t,a,1,0);
            Terrain_Setcase(t,c,1,1);

        }
}

void Terrain_testament(Terrain &t)
{
        delete t.plateau;
}

void Terrain_affichageCase(Terrain &t,const int &posx,const int &posy)
{
    Case * p = Terrain_Getcase(t,posx,posy);
    printf("%s ",p->carre);
}

