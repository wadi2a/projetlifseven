#ifndef _Bomberman
#define _Bomberman
#include "bombe.h"

struct sBomberman {
    int posx;
    int posy;
    char direction;
    int nb_vie;
    int nb_bombe;
};
typedef struct sBomberman Bomberman;

int Bombeman_Getnbvie(const Bomberman &b);

void Bomberman_Getnbvie(Bomberman &b, const int &nbv);

void Bomberman_Incrementvie(Bomberman &b);

void Bomberman_Initialisation(Bomberman &b);

void Bomberman_mouvement(Bomberman &a, const Terrain &t, const char &dir);

void Bomberman_testBombe(Bomberman &a, const Bombe &b);








#endif
