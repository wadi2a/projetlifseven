#ifndef _Case
#define _Case
#include <stdlib.h>
#include <iostream>

struct sCase
{
  char carre[20];
};
typedef struct sCase Case;

void Case_initialisation(Case &a);
/* Fonction qui initialise la case à vide */

void Case_setCase(Case &a, const Case &b);


#endif

