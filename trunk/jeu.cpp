#include "jeu.h"

void Jeu_InitRand()
{
  srand(time(NULL));
}

void Jeu_PerteVieContactEnnemi(Bomberman &b, const dEnnemi &e)
{
    Cellule * p = e.liste_en.prem->suivant;
    while(p != e.liste_en.prem)
    {
        if(b.posx==p->en->posx && b.posy==p->en->posy)
        {
            Bomberman_Setnbvie(b,0);
        }
        p=p->suivant;
    }
}

void Jeu_ChoixNiveau(Jeu &j, const int &niv)
{
        j.niveau = niv;
}

void Jeu_ChoixMechant(Jeu &j, const int &mech)
{
        j.nb_mechant = mech;
}

void Jeu_Initialisation(Jeu &j, Terrain &t, dEnnemi &l, Bomberman &b, const int &temps)
{
    Terrain_initialisation(t);
    Terrain_affectationaleatoire(t);
    Bomberman_Initialisation(b);
    dEnnemi_Initialisation(l,t,j.nb_mechant);
    j.temps_mouvement=temps;
}




