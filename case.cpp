#include "case.h"

void Case_initialisation(Case &a)
{
    strcpy(a.carre,"V");
}

void Case_setCase(Case &a, const Case &b)
{
        strcpy(a.carre,b.carre);
}
