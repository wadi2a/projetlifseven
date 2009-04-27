#include "jeu.h"

void Jeu_Affichagetemporaire(const Terrain &t);
//Procédure temporaire d'affichae du terrain



int main(void)
{
    /*Jeu_InitRand();

    int nb;
    Jeu j;
    printf("Choix du nombre d'ennemis ?\n");
    scanf("%d",&nb);
    Jeu_ChoixNiveau(j,nb);
    Jeu_ChoixMechant(j,nb);


    Bombe * test;
    dEnnemi mechant;
    Bombe_InitialisationBombe(test);
    Terrain jeu;
    Bomberman perso;
    Jeu_Initialisation(j,jeu,mechant,perso);




    int vie = Bombeman_Getnbvie(perso);
    //Affichage
    Jeu_Affichagetemporaire(jeu);
    printf("\n");
    printf("%d",vie);
    printf("\n");
    sleep(5);

//On tente de poser une bombe aux coordonnée (x,y)

    if (Bombe_posebombe(test,2,3,jeu,1))
        {
                Case a;
                strcpy(a.carre,"B");
                Terrain_Setcase(jeu,a,2,3);
                Jeu_Affichagetemporaire(jeu);
                printf("\n");

                Bombe_minuteur(3);

                if (Bomberman_PresenceSurTrajetBombe(perso,test)) Bomberman_Decrementevie(perso);
                vie = Bombeman_Getnbvie(perso);
                Bombe_ExplosionSurTerrain(test,jeu);
        }

    // Ce if correspondra a une fonctione finale regroupant tout lorsque l'on pose une bombe
    Jeu_Affichagetemporaire(jeu);
    sleep(3);
    printf("%d",vie);
    Bombe_testament(test);
    Terrain_testament(jeu);*/


    Jeu_InitRand();

    int nb;
    Jeu j;
    printf("Choix du nombre d'ennemis ?\n");
    scanf("%d",&nb);
    Jeu_ChoixNiveau(j,nb);
    Jeu_ChoixMechant(j,nb);

    dEnnemi mechant;
    Terrain jeu;
    Bomberman perso;
    Jeu_Initialisation(j,jeu,mechant,perso);

    int x,y,i;
    int * tab;
    tab = dEnnemi_GetPosition(mechant);

    for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
    {
        x=tab[i];
        y=tab[i+1];
        printf("x = %d et y = %d \n \n" , x,y);
    }

    Jeu_Affichagetemporaire(jeu);
    sleep(5);
    delete tab;

    Ennemi * test = mechant.liste_en.prem->suivant->suivant->en;
    dEnnemi_SupprimeEnnemi(mechant,test);

    tab = dEnnemi_GetPosition(mechant);
    for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
    {
        x=tab[i];
        y=tab[i+1];
        printf("x = %d et y = %d \n \n" , x,y);
    }
    int com;
    for(com=0;com<=4;i++)
    {
        sleep(5);
        printf("\n");
        delete tab;
        dEnnemi_Mouvement(mechant,jeu);
        tab = dEnnemi_GetPosition(mechant);
        for(i=0;i<=2*(mechant.liste_en.nb_en)-1;i=i+2)
        {
            x=tab[i];
            y=tab[i+1];
            printf("x = %d et y = %d \n \n" , x,y);
        }
    }

        /*int i=0;
        do
        {
            Ennemi_mouvement(mechant,jeu);
            x=Ennemi_Getposx(mechant);
            y=Ennemi_Getposy(mechant);
            vie = Ennemi_Getnbvie(mechant);
            printf("vie = %d, \nx = %d et y = %d \n \n" , vie,x,y);
            i++;mechant
        }while(i<=10);*/

    Terrain_testament(jeu);
    dEnnemi_Testament(mechant);


    return EXIT_SUCCESS;
}

void Jeu_Affichagetemporaire(const Terrain &t)
{
   int i,j;
   for (i=0;i<=t.dim-1;i++)
    {
        for (j=0;j<=t.dim-1;j++)
        {
            Terrain_affichageCase(t,j,i);

        }
        printf("\n");
    }
}

