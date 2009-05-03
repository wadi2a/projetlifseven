#include "ennemi.h"

void Ennemi_Creation(Ennemi *& e)
{
        e = new Ennemi;
}

int Ennemi_Getposx(Ennemi * e)
{
    return e->posx;
}

int Ennemi_Getposy(Ennemi * e)
{
    return e->posy;
}

char Ennemi_Getdirection(Ennemi * e)
{
    return e->direction;
}

void Ennemi_Setposx(Ennemi * e,const int &x)
{
    if (x >= 0)
    {
            e->posx = x;
    }
}

void Ennemi_Setposy(Ennemi * e,const int &y)
{
    if (y >= 0)
    {
            e->posy = y;
    }
}

void Ennemi_Setdirection(Ennemi * e,const char &dir)
{
    if (dir == 'd' || dir == 'g' || dir == 'h' || dir == 'b')
    {
            e->direction = dir;
    }
}

int Ennemi_Getnbvie(Ennemi * e)
{
        return e->nb_vie;
}

void Ennemi_Setnbvie(Ennemi * e, const int &nbv)
{
        if (nbv >= 0)
        {
                e->nb_vie=nbv;
        }
}

void Ennemi_Decrementevie(Ennemi * e)
{
    Ennemi_Setnbvie(e,e->nb_vie - 1);
}

void Ennemi_affectationsurterrain(Ennemi * e, const Terrain &t)
{


    char dir = 'd';
    Ennemi_Setnbvie(e,1);

        int x,y;
       Case * p;


        do{
            x = rand()%14 +1;
            y = rand()%14 +1;
            p = Terrain_Getcase(t,x,y);
        }while( strcmp(p->carre,"V") < 0 || strcmp(p->carre,"V") > 0);

       Ennemi_Setposx(e,x);

    Ennemi_Setposy(e,y);

        Ennemi_Setdirection(e,dir);



}

void Ennemi_mouvement(Ennemi * e, const Terrain &t)
{
    int booleen,posy,posx;
    booleen = rand()%2;
    posx = Ennemi_Getposx(e);
    posy = Ennemi_Getposy(e);
    Case *p;

    if (booleen == 1) // variation de x
    {
        int x;
        do {
            if(posx == 0)
            {
                x = rand()%2;
                p = Terrain_Getcase(t,e->posx + x,e->posy);
            }else{
                if (posx == t.dim - 1)
                {
                    x = rand()%2 - 1;
                    p = Terrain_Getcase(t,e->posx + x,e->posy);
                }else{
                    x = rand()%3 - 1;
                    p = Terrain_Getcase(t,e->posx + x,e->posy);
                }
            }
        }while (strcmp(p->carre,"V") < 0 || strcmp(p->carre,"V") > 0);
        Ennemi_Setposx(e, e->posx + x);
    }else{
        if(booleen == 0)
        { // variation de y
            int y;
            do {
                if (posy == 0)
                {
                    y = rand()%2;
                    p = Terrain_Getcase(t,e->posx,e->posy + y);
                }else{
                    if (posy == t.dim - 1)
                    {
                        y = rand()%2 - 1;
                        p = Terrain_Getcase(t,e->posx,e->posy + y);
                    }else{
                        y = rand()%3 - 1;
                        p = Terrain_Getcase(t,e->posx,e->posy + y);
                    }
                }
            }while (strcmp(p->carre,"V") < 0 || strcmp(p->carre,"V") > 0);
            Ennemi_Setposy(e, e->posy + y);
        }
    }
}

bool Ennemi_PresenceSurTrajetBombe(Ennemi * e, Bombe * b)
{
    if (e->posx == b->x && e->posy == b->y) // Bomberman se trouve sur la position de la bombe (même si c'est impossible, corrige un eventuel bug
    {
            return true;
    }else{ // On teste si le bomberman se trouve sur la zone d'explosion de la bombe
        int i;
        for(i=(b->x-b->r_exp);i<=(b->x+b->r_exp);i++)
        {
            if( e->posx == i && e->posy == b->y) return true;
        }

        for(i=(b->y - b->r_exp);i<=(b->y + b->r_exp);i++)
        {
            if( e->posy == i && e->posx == b->x) return true;
        }
    }
    return false;
}

void Ennemi_testament(Ennemi * e)
{
        delete e;
}
