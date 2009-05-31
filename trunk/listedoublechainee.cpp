#include "liste.h"

void initialise(Liste & l)
{
	Cellule * p = new Cellule; // On crée une cellule avec un pointeur qui pointe dessus.
	l.prem = p; // Le champ prem de la liste pointe sur la cellule
	l.prem->suivant=l.prem;	// Le champ suivant de la cellule pointe sur lui-même
	l.prem->precedent=l.prem;// Le champ precedent de la cellule pointe sur lui-même
	l.prem->en = NULL;
	l.nb_elements = 0;
}

void ajoutEnQueue(Ennemi * e, Liste & l)
{
	Cellule * p = new Cellule;
	p->en = e;
	p->precedent = l.prem->precedent; // Le champ precedent de la nouvelle cellule pointe sur l'ancienne derniere cellule pointée par le champ precedent de la cellule bidon
	p->suivant = l.prem; // Le champ suivant de la nouvelle cellule pointe sur la cellule bidon
	l.prem->precedent->suivant = p; // On fait pointer le champ suivant de l'ancienne derniere cellule sur la cellule a inserer
	l.prem->precedent = p; // Le champ precedent de la cellule bidon pointe sur la nouvelle cellule
    l.nb_elements++;
}

void initialise(Liste & l1, const Liste & l2)
{
	initialise(l1); // Initialisation de l1 en tant que liste vide
	unsigned int i;
	Cellule * p = l2.prem->suivant; // Pointeur de travail qui pointe sur la premiere cellule de l2
	for(i=1;i<= l2.nb_elements;i++) // On fait varier i tant qu'on a pas dépassé le nombre d'element de la liste l2
	{
		ajoutEnQueue(p->en,l1); // On ajoute en queue à l1 l'element de la ieme cellule de l2
		p = p->suivant; // On deplace le ponteur sur la cellule suivant de l2
	}
}

void testament(Liste & l)
{
	Cellule * p = l.prem->suivant; // 1er Pointeur sur la premiere cellulle de l
	Cellule * m = p;// 2eme Pointeur sur la premiere cellulle de l
	while (m != l.prem) // Tant que le pointeur est different de la cellule bidon on effectue les operations de la boucle :
	{
		m = m->suivant; // On decale m sur la cellule suivante, pour ne pas perdre la suite de la liste en mémoire
		Ennemi_testament(p->en);
		delete p; // On supprime la cellule pointee par p
		p=m; // Après la suppression de la cellule pointée par p, on re-utilise p en le faisant pointeé sur la cellule suivante grace a m
	}
	delete l.prem; // Il ne reste plus que la cellule bidon en fin de boucle que l'on supprime
}


bool estVide(const Liste & l)
{
	return (l.prem == l.prem->suivant);
}


void ajoutEnTete(Ennemi * e,Liste & l)
{
	Cellule * p = new Cellule;
	p->en = e;
	p->suivant = l.prem->suivant; // Le champ suvant de la nouvelle cellule pointe sur l'ancienne premiere cellule de la liste
	l.prem->suivant->precedent = p; // Le champ precedent de l'ancienne premiere cellule de la liste pointe sur la nouvelle cellule à inserer
	l.prem->suivant = p; // Le champ suivant de la cellule bidon pointe sur la nouvelle cellule
	p->precedent = l.prem; // Le champ precedent de la nouvelle cellule pointe sur la cellule bidon
	l.nb_elements++;
}

void suppressionEnTete(Liste & l)
{
	Cellule *p = l.prem->suivant; // On cree un pointeur sur Cellule, qui pointe sur la premiere cellule
	Cellule *m = p->suivant; // On cree un pointeur sur Cellule, qui pointe sur la seconde cellule
	delete p; // On supprime la premiere cellule
	l.prem->suivant = m; // Le champ suivant de la cellule bidon pointe sur l'ancienne seconde cellule
    m->precedent = l.prem;	 // Le champ precedent de l'ancienne seconde cellule pointe sur la cellule bidon
}

void suppressionEnQueue(Liste & l)
{
	Cellule *p = l.prem->precedent; // On cree un pointeur sur Cellule, qui pointe sur la derniere cellule
	Cellule *m = p->precedent;// On cree un pointeur sur Cellule, qui pointe sur l'avant derniere cellule
	delete p; // On supprime la derniere cellule
	l.prem->precedent = m; // Le champ precedent de la cellule bidon pointe sur l'ancienne avant-derniere cellule
    m->suivant = l.prem; // Le champ suivant de l'ancienne avant-derniere cellule pointe sur la cellule bidon
}
