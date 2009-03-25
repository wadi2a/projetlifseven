#include <stdlib.h>
#include <iostream.h>
#include "terrain.h"

void Terrain_initialisation(Terrain & t, const int &niveau)
{
    // Affectation tableaux pour chaque niveaux
        Case * p1 = new Case n1[t.dim][t.dim] = {"vide","mur","brique"};
        Case * p2 = new Case n2[t.dim][t.dim] = {"vide","mur"};
        Case * p3 = new Case n3[t.dim][t.dim] = {"vide","mur"};

        if (niveau == 1)
        {
            t.plateau = p1;

        }else{ if (niveau == 2)
                {
                    t.plateau = p2;

                }else{

                    t.plateau = p3;
                }
        }
}

void Terrain_testament(Terrain &t)
{
        delete t.plateau;
}

