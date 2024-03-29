#include "dennemis.h"

void dEnnemi_Initialisation(dEnnemi & e, const Terrain &t, const int & nb)
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

            e.liste_en.nb_en--;
            break;
        }
    }
}

void dEnnemi_Testament(dEnnemi & e)
{
    testament(e.liste_en);
}

void dEnnemi_Mouvement(dEnnemi & e, const Terrain &t)
{
    Cellule * p = e.liste_en.prem->suivant;
    while(p != e.liste_en.prem)
    {
        Ennemi_mouvement(p->en,t);
        p=p->suivant;
    }
}

void dEnnemi_PresenceSurBombe(dEnnemi & e, Bombe * b, Terrain &t)
{
    Cellule * p = e.liste_en.prem->suivant;
    while(p != e.liste_en.prem)
    {
        if(Ennemi_PresenceSurTrajetBombe(p->en,b,t))
        {
            Ennemi_Decrementevie(p->en);
            if(Ennemi_Getnbvie(p->en) <= 0)
            {

                Case a;
                strcpy(a.carre,"E");
                Terrain_Setcase(t,a,p->en->posx,p->en->posy);
                dEnnemi_SupprimeEnnemi(e,p->en);
            }
        }
        p=p->suivant;
    }
}

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

char * dEnnemi_GetDirection(dEnnemi & e)
{

        char * p = new char[e.liste_en.nb_en];
        Cellule * m = e.liste_en.prem->suivant;
        int i = 0;

        while(m != e.liste_en.prem)
        {
            p[i]=Ennemi_Getdirection(m->en);


            m = m->suivant;
            i=i+1;
        }
        return p;
}

void dEnnemi_ToucheExplosion(dEnnemi & e, const Terrain &t)
{

        Cellule * m = e.liste_en.prem->suivant;
        Case * p;
        Ennemi * k;
        int i,j;

        while(m != e.liste_en.prem)
        {
               i=Ennemi_Getposx(m->en);
               j=Ennemi_Getposy(m->en);
               p=Terrain_Getcase(t,i,j);
               if(!strcmp(p->carre,"E"))
               {
                  k = m->en;
                  m = m->suivant;
                  dEnnemi_SupprimeEnnemi(e,k);
              }else m=m->suivant;
        }
}
