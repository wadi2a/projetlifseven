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

int Bomberman_Getposx(const Bomberman &b);

int Bomberman_Getposy(const Bomberman &b);

char Bomberman_Getdirection(const Bomberman &b);

int Bomberman_Getbombe(const Bomberman &b);

void Bomberman_Setbombe(Bomberman &b, const int &nb);

void Bomberman_Setposx(Bomberman &b, const int &nb);

void Bomberman_Setposy(Bomberman &b, const int &nb);

void Bomberman_Setdirection(Bomberman &b, const int &nb);

int Bombeman_Getnbvie(const Bomberman &b);

void Bomberman_Setnbvie(Bomberman &b, const int &nbv);

void Bomberman_Incrementevie(Bomberman &b);

void Bomberman_Decrementevie(Bomberman &b);

void Bomberman_Initialisation(Bomberman &b);

void Bomberman_mouvement(Bomberman &a, const Terrain &t, const char &dir);

bool Bomberman_PresenceSurTrajetBombe(Bomberman &a, const Bombe &b);
#endif
