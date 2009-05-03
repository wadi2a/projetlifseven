#include <stdlib.h>
#include <iostream>
#include "terrain.h"


Case * Terrain_Getcase(const Terrain &t,const int &posx,const int &posy)
{
    return &t.plateau[posy*t.dim + posx]; //Accesseur pour simplifier l'accès au tableau 2D <=> t[x][y] et remplace t[x*t.dim +y] :)
}

void Terrain_Setcase(Terrain &t, const Case &c, const int &posx,const int &posy)
{
        t.plateau[posy*t.dim + posx] = c; // Mutateur
}

void Terrain_initialisation(Terrain & t)
{
    // Affectation tableaux pour chaque niveaux
        t.dim=15;
        t.plateau = new Case[t.dim*t.dim];
        Case v;
        Case_initialisation(v);
         // On prend un tableau 1D de taille 15*15, pour accéder à la positio (x,y) on effectue t[y*15 + x] Allouer un teableau 2D dynamiquement est compliqué !!!

        /* Initialisation des tableaux pour chaque niveaux : c'est un tableau 1D que l'on utilise comme un 2D !!!
        exemple pour un plateau 2x2 : on a un tableau 1D de 4 cases; les deux premieres cases correspondent à (0,0) et (0,1), les deux autres sont
         (1,0) et (1,1) */
        int i,j;
        for(i=0;i<t.dim;i++)
        {
            for(j=0;j<t.dim;j++)
            {
                Terrain_Setcase(t,v,j,i);
            }
        }
}

void Terrain_affectationaleatoire(Terrain &t)
{
        Case s,c;
        strcpy(s.carre,"S");
        strcpy(c.carre,"M");


        int i,j,x,y;
        for(i=1;i<t.dim;i=i+2)
        {
            for(j=1;j<t.dim;j=j+2)
            {
                    Terrain_Setcase(t,s,j,i);
            }

        }

        for(i=0;i<61;i++)
        {
            do{
                x = rand()%15;
                y = rand()%15;
            }while((x%2 == 1 && y%2 == 1) || (x == 0 && y == 0) || (x == 1 && y == 0) || (x == 0 && y == 1));

            Terrain_Setcase(t,c,x,y);
        }
}

void Terrain_testament(Terrain &t)
{
        delete[] t.plateau;
}

void Terrain_affichageCase(const Terrain &t,const int &posx,const int &posy)
{
    Case * p = Terrain_Getcase(t,posx,posy);
    printf("%s ",p->carre);
}
