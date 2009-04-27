#include "dennemis.h"

void dEnnemi_Initialisation(dEnnemi & e, const Terrain &t, const int & nb)
// Initilialise la liste et rajoute le nombre d'ennemis en les affectant sur le terrain
{
    initialise(e.liste_en);
    int i;
    for(i=1;i<=nb;i++)
    {
            Ennemi * me;
            Ennemi_Creation(me);
            Ennemi_affectationsurterrain(me,t);
            ajoutEnQueue(me,e.liste_en);
    }
    e.liste_en.nb_en=nb;
}

void dEnnemi_SupprimeEnnemi(dEnnemi & e, Ennemi * m)
// Supprime l'ennemi m s'il est égal à m donné en paramètre. Suppression propre en mémoire
{
    Cellule * p = e.liste_en.prem->suivant;

    while(p != e.liste_en.prem)
    {
        Ennemi * k = p->en;
        if(m != k)
        {
            p=p->suivant;

        }else{
            p->precedent->suivant = p->suivant;
            p->suivant->precedent = p->precedent;
            Ennemi_testament(k);
            delete p;
            e.liste_en.nb_en--;
            break;
        }
    }
}

void dEnnemi_Testament(dEnnemi & e)
// Supprime proprement en mémoire la liste d'ennemis
{
    testament(e.liste_en);
}

void dEnnemi_Mouvement(dEnnemi & e, const Terrain &t)
// Effectue les mouvements sur l'ensemble des ennemis du terrain
{
    Cellule * p = e.liste_en.prem->suivant;
    while(p != e.liste_en.prem)
    {
        Ennemi_mouvement(p->en,t);
        p=p->suivant;
    }
}

void dEnnemi_PresenceSurBombe(dEnnemi & e, Bombe * b);

int * dEnnemi_GetPosition(dEnnemi & e)
{
        int * p = new int[2*e.liste_en.nb_en];
        Cellule * m = e.liste_en.prem->suivant;
        int i = 0;

        while(m != e.liste_en.prem)
        {
            p[i]=Ennemi_Getposx(m->en);
            p[i+1]=Ennemi_Getposy(m->en);

            m = m->suivant;
            i=i+2;
        }
        return p;
}



