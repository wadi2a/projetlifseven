#include "bomberman.h"
#include <iostream>
#include <stdlib.h>

int Bomberman_Getposx(const Bomberman &b)
{
    return b.posx;
}

int Bomberman_Getposy(const Bomberman &b)
{
    return b.posy;
}

char Bomberman_Getdirection(const Bomberman &b)
{
    return b.direction;
}

int Bomberman_Getbombe(const Bomberman &b)
{
    return b.nb_bombe;
}

void Bomberman_Setbombe(Bomberman &b, const int &nb)
{
    if (nb >= 0)
    {
            b.nb_bombe = nb;
    }
}

void Bomberman_Setposx(Bomberman &b, const int &nb)
{
    if (nb >= 0)
    {
            b.posx = nb;
    }
}

void Bomberman_Setposy(Bomberman &b, const int &nb)
{
    if (nb >= 0)
    {
            b.posy = nb;
    }
}

void Bomberman_Setdirection(Bomberman &b, const char &nb)
{
    if (nb == 'd' || nb == 'g' || nb == 'h' || nb == 'b')
    {
            b.direction = nb;
    }
}

int Bombeman_Getnbvie(const Bomberman &b)
{
        return b.nb_vie;
}

void Bomberman_Setnbvie(Bomberman &b, const int &nbv)
{
        if (nbv >= 0)
        {
                b.nb_vie=nbv;
        }
}

void Bomberman_Incrementevie(Bomberman &b)
{
        Bomberman_Setnbvie(b,b.nb_vie + 1);
}

void Bomberman_Initialisation(Bomberman &b)
{
        char dir = 'd';
        Bomberman_Setnbvie(b,3);
        Bomberman_Setposx(b,0);
        Bomberman_Setposy(b,0);
        Bomberman_Setdirection(b,dir);
        Bomberman_Setbombe(b,30);
}

void Bomberman_mouvement(Bomberman &a, const Terrain &t, char &dir_act, const char &dir_clavier)
{
    if ( dir_act != dir_clavier )
    {
            Bomberman_Setdirection(b,dir_clavier);
    }else{
        x = Bomberman_Getposx(b);
        y = Bomberman_Getposy(b);
        if (dir_clavier == 'h')
        {
            if (y != 0)
            {
                Case * c;
                c = Terrain_Getcase(t,x,y+1);
                if (!strcmp(c->carre,"vide"))
                {
                    Bomberman_Setposy(b,y+1);
                }
            }
        }else{
            if (dir_clavier == 'b')
            {
                    if (y != t.dim - 1)
                    {
                            Case * c;
                            c = Terrain_Getcase(t,x,y-1);
                            if (!strcmp(c->carre,"vide"))
                            {
                                Bomberman_Setposy(b,y-1);
                            }
                    }
            }else{
                if (dir_clavier == 'd')
                {
                            Case * c;
                            c = Terrain_Getcase(t,x+1,y);
                            if (!strcmp(c->carre,"vide"))
                            {
                                Bomberman_Setposx(b,x+1);
                            }
                }else{

}

//void Bomberman_testBombe(Bomberman &a, const Bombe &b);
