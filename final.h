/**
 * \file final.h
 * \brief Déclarations des fonctions pour l'utilisation de la SDL.
 *
 * Ce fichier d'en-tête permet l'initialisation de la SDL, l'initialisation des variables nécessaires pour la SDL,
 * la gestion du mouvement, les Menus, la gestion des explosions et de l'affichage du Terrain, des Ennemis et du Bomberman.
*/
#ifndef _Final
#define _Final
#include "jeu.h"
#include <SDL.h>

/**
@brief Allocation des images des nombres
@param nombre un tableau de taille 10 de SDL_Surface

Cette fonction affecte pour chaque élément du tableau l'image correspondant au nombre (de 0 à 9).
*/
void Final_AllocationNombre(SDL_Surface * nombre[10]);

/**
@brief Allocation des postions d'une surface
@param val un SDL_Rect en donnée/résultat
@param x un Entier en donnée
@param y un Entier en donnée

Cette fonction est un mutateur qui permet d'allouer les positions (x,y) pour l'affichage à l'écran d'une Image.
*/
void Final_AllocationValeurRect(SDL_Rect & val, const int &x, const int &y);

/**
@brief Allocation des images de fond et de Terrain.
@param terrain un pointeur sur SDL_Surface en donnée/résultat
@param fond un pointeur sur SDL_Surface en donnée/résultat
@param niveau un Entier en donnée

Cette fonction affecte les images de fond d'écran et de fond de terrain en fonction du niveau. Il existe trois fonds différents pour l'ensemble du jeu.
Ces fonds alterne de niveaux en niveaux.
*/
void Final_AllocationImageFT(SDL_Surface *& terrain, SDL_Surface *& fond, const int &niveau);

/**
@brief Allocation des images des murs solides, mur, bombes et explosion.
@param mursolide un pointeur sur SDL_Surface en donnée/résultat
@param mur un pointeur sur SDL_Surface en donnée/résultat
@param bombes un pointeur sur SDL_Surface en donnée/résultat
@param explode un pointeur sur SDL_Surface en donnée/résultat
@param niveau un Entier en donnée

Cette fonction affecte les images de mur solides, de mur, de bombes et explosion en fonction du niveau. A l'image du terrain, il existe trois sets, un pour
le niveau de l'herbe, un pour le niveau aquatique et un pour le niveau de l'espace.
*/
void Final_AllocationImageMMBE(SDL_Surface *& mursolide, SDL_Surface *& mur ,SDL_Surface *& bombes, SDL_Surface *& explode, const int &niveau);

/**
@brief Blittage des images des murs solides, mur, bombes et explosion sur l'Ecran.
@param jeu un Terrain en donnée
@param ecran un pointeur sur SDL_Surface en donnée/résultat
@param mursolide un pointeur sur SDL_Surface en donnée/résultat
@param mur un pointeur sur SDL_Surface en donnée/résultat
@param bombes un pointeur sur SDL_Surface en donnée/résultat
@param explode un pointeur sur SDL_Surface en donnée/résultat
@param murpos un SDL_Rect en donnée/résultat

Cette fonction gère l'affichage du plateau du jeu en utilisant les images et en affectant à la varibale SDL_Rect murpos la coordonnée dans le Terrain.
*/
void Final_AllocationValeurRectMMBE(const Terrain &jeu,SDL_Surface *& ecran, SDL_Surface *& mursolide, SDL_Surface *& mur ,SDL_Surface *& bombes, SDL_Surface *& explode, SDL_Rect & murpos);

/**
@brief Allocation des images du Bomberman et des Ennemis.
@param ennemi un tableau de taille 4 de pointeur sur SDL_Surface
@param personnage un tableau de taille 4 de pointeur sur SDL_Surface
@param persoact un pointeur sur SDL_Surface en donnée/résultat
@param ennemiact un pointeur sur SDL_Surface en donnée/résultat
@param niveau un Entier en donnée

Cette fonction alloue les sprites du Bomberman et des Ennemis en fonction du niveau (3 sets = herbe, aquatique et espace), puis les variables ennemiact et persoact
pointent sur le premier sprite pour le démarrage du Jeu. Ces variables seront utilisées dans la fonction de mouvement.
*/
void Final_AllocationImagePE(SDL_Surface * ennemi[4], SDL_Surface * personnage[4] ,SDL_Surface *& persoact, SDL_Surface *& ennemiact, const int &niveau);

/**
@brief Gestion d'affichage et d'évènements du Menu.
@param event un SDL_Event en donnée
@param niveau un Entier en donnée/résultat
@param win un Entier en donnée/résultat
@param quitter un Entier en donnée/résultat
@param jeufin un Booléen en donnée/résultat

Cette fonction permet de choisir entre quitter le jeu ou commencer une partie. L'ensemble des variables en paramètre doivent être initialisées.
Si l'option quitter est choisie jeufin = true et quitter = 1 ce qui permet de sortir des deux boucles dans le fichier main.
Si l'option jouer est choisie win = 1 et niveau = 1, ce qui permet de rentrer dans la boucle de jeu tant que le Bomberman est vivant.
*/
void Final_Menu(SDL_Event &event,int & niveau, int & win, int & quitter, bool &jeufin);

/**
@brief Blittage des images des Ennemis
@param mechant une Liste d'Ennemis en donnée
@param ennemiact un pointeur sur SDL_Surface en donnée/résultat
@param ecran un pointeur sur SDL_Surface en donnée/résultat
@param posennemi un SDL_Rect en donnée/résultat

Cette fonction gère l'affichage des Ennemis en utilisant les images et en affectant à la varibale SDL_Rect murpos la coordonnée dans le Terrain à l'aide
de la fonction GetPostion du module dennemis. Cette fonction sert juste à l'initialisation de l'image. Une autre est utilisée pour les mouvements.
*/
void Final_AffichageMechant(const dEnnemi &mechant, SDL_Surface * ennemiact,SDL_Surface * ecran, SDL_Rect &posennemi, int * tab);

/**
@brief Gestion d'affichage et d'évènements du Menu de pause.
@param mpause un tableau de taille 3 de pointeur sur SDL_Surface
@param ecran un pointeur sur SDL_Surface en donnée/résultat
@param menpos un SDL_Rect en donnée/résultat
@param jeufin un Booléen en donnée/résultat
@param quitter un Entier en donnée/résultat
@param continuer un Entier en donnée/résultat
@param win un Entier en donnée/résultat
@param event un SDL_Event en donnée

Cette fonction permet de mettre en pause le jeu lorsque la touche ESC est activée (utilisé dans la fonction de mouvement). Le jeu rentre alors dans une boucle tant qu'on a pas choisie une option.
Reprendre : on sort de la boucle en affectant false à true. Le jeu reprend normalement.
Menu : On sort de la boucle du jeu en mettatn continuer et win à 0 , on affecte false à jeufin mais 1 à quitter, on revient ainsi au menu principal
Quitter : On sort de la boucle du jeu en mettant continuer et win à 0 , on affecte true à jeufin et 1 à quitter, on quitte ainsi le jeu, car on sort de toutes les boucles.
*/
void Final_MenuPause(SDL_Surface *mpause[3], SDL_Surface *ecran, SDL_Rect &menpos, bool &jeufin,int &quitter, int &continuer, int &win, SDL_Event &event);

/**
@brief Gestion des mouvements, des events du Bomberman
@param event un SDL_Event en donnée
@param continuer un Entier en donnée/résultat
@param win un Entier en donnée/résultat
@param bombepos un Entier en donnée/résultat
@param bombe un pointeur sur Bombe
@param quitter un Entier en donnée/résultat
@param personnage un tableau de taille 4 de pointeur sur SDL_Surface
@param persoactuel un pointeur sur SDL_Surface en donnée/résultat
@param jeu un Terrain en donnée
@param perso un Bomberman en donnée/résultat
@param mpause un tableau de taille 3 de SDL_Surface
@param jeufin un Booléen en donnée/résultat
@param menpos un SDL_Rect en donnée/résultat

Cette fonction permet la gestion des évènnements pour le Bomberman. Elle affecte une touche du clavier à une action du bomberman.
Espace : On pose une Bombe si aucune autre bombe est posée. La variable bombepos prend la valeur 1, permet l'explosion dans une autre fonction.
Haut : Bomberman monte d'une case s'il le peut. Execute la fonction de mouvement pour avancer ves le haut et charge l'image "haut" du bomberman dans persoactuel.
Bas : Bomberman descend d'une case s'il le peut.Execute la fonction de mouvement pour avancer ves le bas et charge l'image "bas" du bomberman dans persoactuel.
Gauche : Bomberman avance d'une case vers la gauche s'il le peut. Execute la fonction de mouvement pour avancer ves la gauche et charge l'image "gauche" du bomberman dans persoactuel.
Droite : Bomberman avance d'une case vers la droite s'il le peut. Execute la fonction de mouvement pour avancer ves le droite et charge l'image "droit" du bomberman dans persoactuel.
Echap : Met le jeu en Pause. En appelant la fonction de Pause de ce module elle donne en paramètre les variables mpause, ecran, menpos, jeufin, quitter, continuer, win et event
*/
void Final_MouvementEvent(SDL_Event &event,int & continuer, int & win, int & bombepos, Bombe *bombe,int & quitter, SDL_Surface * personnage[4], SDL_Surface *& persoactuel, const Terrain &jeu, Bomberman &perso, SDL_Surface *ecran, SDL_Surface *mpause[3], bool &jeufin, SDL_Rect &menpos);

/**
@brief Initialise la Bombe si elle a déjà explosé
@param initb un Entier en donnée/résultat
@param init_a un Entier en donnée/résultat
@param bombe un pointeur sur Bombe en donnée/résultat

Cette fonction initialise la Bombe si elle a déjà explosé (Testament), elle a explosé si initb vaut 1.
Si elle a explosé, on l'initialise et on affecte 1 à init_a qui permet de dire que la Bombe est initialisée et qu'on peut l'utiliser
ou la supprime proprement en mémoire à la fin du jeu si elle n'a pas resservie.
*/
void Final_TestInitBombe(int &initb, int & init_a, Bombe *& bombe);

/**
@brief Fonction qui pose la Bombe
@param poser un Entier en donnée/résultat
@param bombe un pointeur sur Bombe en donnée/résultat
@param jeu un Terrain en donnée/résultat
@param perso un Bomberman en donnée
@param init_a un Entier en donnée/résultat
@param initb un Entier en donnée/résultat
@param bombepos un Entier en donnée/résultat

Cette fonction pose la Bombe aux coordonnées ou se trouve le Bomberman si bombepos = 1.
On lance la fonction de teste du posage de Bombe dans le module Bombe.
Si on ne peut poser la bombe, on utilise Testament de la bombe et on affecte 1 à initb pour l'initialiser au prochain tour de boucle.
Si on peut poser la bombe, on decremente le nombre de bombe du Bomberman et on affecte 1 à poser pour effectuer l'explosion. L'heure système du posage de
bombe est enregistré dans le champs temps de la bombe.
*/
void Final_PoseBombe(int &poser, Bombe *& bombe,  Terrain &jeu, const Bomberman &perso, int &init_a, int &initb, int &bombepos);

/**
@brief Fonction qui effectue l'explosion de la Bombe
@param poser un Entier en donnée/résultat
@param perte_v un Entier en donnée/résultat
@param explosion un Entier en donnée/résultat
@param temps_explosion un Entier en donnée/résultat
@param initb un Entier en donnée/résultat
@param possible_mb un Entier en donnée/résultat
@param bombe un pointeur sur Bombe en donnée/résultat
@param perso un Bomberman en donnée
@param jeu un Terrain en donnée/résultat
@param mechant une Liste d'Ennemis en donnée/résultat
@param init_a un Entier en donnée/résultat

Cette fonction effectue l'explosion de la Bombe si la variable poser = 1
Ensuite si le temps actuel - le champs temps de la bombe est inférieur à 2500ms, on effectue pas l'explosion.
Une fois ce temps >= 2500ms, on affecte 1 à explosion, on incremente le nombre de bombe du Bomberman, on affecte 0 à poser, à init_a et 1 à initb (afin de reposer une bombe).
On execute la fonction d'explosion des Murs, de teste de presénce du Bomberman et d'Ennemis sur le rayon.
Puis on affecte l'heure où à lieu l'explosion dans la variable temps_explosion, afin de maintenir quelques secondes l'explosion.
Si le Bomberman perd une vie à cause de l'explosion, on affecte 1 à perte_v afin qu'il ne perde pas de vie s'il reste au contact de l'explosion.

*/
void Final_ExplosionBombe(int &poser,int &perte_v,int &explosion,int &temps_explosion,int &initb, int &possible_mb, Bombe *& bombe, Bomberman &perso, Terrain &jeu, dEnnemi &mechant, int &init_a);

/**
@brief Fonction qui gère l'affichage de l'explosion
@param explosion un Entier en donnée/résultat
@param temps_explosion un Entier en donnée
@param perte_v un Entier en donnée/résultat
@param jeu un Terrain en donnée/résultat

Cette fonction gère l'affichage de l'explosion. En fait, elle désactive l'état "E" sur le plateau qui est activé par la fonction d'explosion.
Si le temps actuel - temps_explosion > 500ms et explosion = 1, alors on change l'état à "V".
On affecte 0 à explosion et perte_v afin que le Bomberman puisse reperdre une vie à la prochaine bombe.
*/
void Final_AffichageExplosion(int &explosion, const int & temps_explosion,int &perte_v, Terrain &jeu);

/**
@brief Blittage des images des Ennemis lors des Mouvements
@param mechant une Liste d'Ennemis en donnée
@param posennemi un SDL_Rect en donnée/résultat
@param ennemiact un pointeur sur SDL_Surface en donnée/résultat
@param ennemi un tableau de taille 4 de pointeur sur SDL_Surface
@param ecran un pointeur sur SDL_Surface en donnée/résultat
@param en_dir un tableau de Caractère
@param tab un tableau d'Entiers

Cette fonction gère l'affichage des Ennemis en utilisant les images et en affectant à la varibale SDL_Rect murpos la coordonnée dans le Terrain à l'aide
du tableau d'Entier donné en paramètre. La fonction choisie le bon sprite en fonction de la direction pour chaque ennemis donné par le tableau de caractère.
*/
void Final_AffichageEnnemis(const dEnnemi &mechant, SDL_Rect &posennemi, SDL_Surface *& ennemiact, SDL_Surface * ennemi[4],SDL_Surface *& ecran, char *en_dir, int * tab);

/**
@brief Gère les teste finaux du Jeu.
@param mechant une Liste d'Ennemis en donnée
@param bombermangame un Jeu en donnée
@param jeu un Terrain en donnée/résultat

Cette fonction gère le mouvement des Ennemis à la vitesse prédéfinis par le champs temps_mouvement dans la structure Jeu.
Pour cela on teste si temps actuel - temps_ennemis (initialisation) >= temps_mouvement. Si oui on effectue les mouvements et temps_ennemis = temps_actuels, pour
le prochain mouvement.
*/
void Final_TestFinaux(dEnnemi &mechant, Bomberman &perso,Terrain &jeu,int &win,int &niveau, int &vie_niveau, int &perte_v, int &continuer, int &dead, Case * touche_explosion);

/**
@brief Gère le mouvement des Ennemis
@param mechant une Liste d'Ennemis en donnée
@param bombermangame un Jeu en donnée
@param jeu un Terrain en donnée/résultat

Cette fonction gère le mouvement des Ennemis à la vitesse prédéfinis par le champs temps_mouvement dans la structure Jeu.
Pour cela on teste si temps actuel - temps_ennemis (initialisation) >= temps_mouvement. Si oui on effectue les mouvements et temps_ennemis = temps_actuels, pour
le prochain mouvement.
*/
void Final_MouvementEnnemis(dEnnemi &mechant,const Jeu &bombermangame, Terrain &jeu);

/**
@brief Libération propre en mémoire des SDL_Surface
@param ecran un pointeur sur SDL_Surface
@param menu un pointeur sur SDL_Surface
@param gameover un pointeur sur SDL_Surface
@param nombre un tableau de taille 10 de pointeur sur SDL_Surface
@param terrain un pointeur sur SDL_Surface
@param bombes un pointeur sur SDL_Surface
@param mursolide un pointeur sur SDL_Surface
@param explode un pointeur sur SDL_Surface
@param mur un pointeur sur SDL_Surface
@param fond un pointeur sur SDL_Surface
@param personnage un tableau de taille 4 de pointeur sur SDL_Surface
@param ennemi un tableau de taille 4 de pointeur sur SDL_Surface
@param load un tableau de taille 5 de pointeur sur SDL_Surface
@param menufin un tableau de taille 2 de pointeur sur SDL_Surface
@param mpause un tableau de taille 3 de pointeur sur SDL_Surface

Cette fonction libère proprement en mémoire l'ensemble des SDL_Surface utilisée au cours de la partie de Bomberman. Elle est utilisée en toute fin de partie, avant que le jeu ne se quitte.
*/
void Final_LiberationMemoire(SDL_Surface * ecran, SDL_Surface * menu, SDL_Surface * gameover, SDL_Surface *nombre[10],SDL_Surface *terrain, SDL_Surface *bombes, SDL_Surface *mursolide, SDL_Surface * explode, SDL_Surface * mur,SDL_Surface *fond, SDL_Surface *personnage[4],SDL_Surface *ennemi[4], SDL_Surface *load[5],SDL_Surface * menufin[2], SDL_Surface *mpause[3]);
/**
@brief Allocation des images pour Chargement.
@param load un tableau de taille 5 de SDL_Surface

Cette fonction affecte pour chaque élément du tableau l'image correspondant au temps de chargement. Ici 1s,2s,...,5s.
*/
void Final_AllocationLoad(SDL_Surface *load[5]);

/**
@brief Affichage du chargement entre Niveaux
@param load un tableau de taille 5 de pointeur sur SDL_Surface
@param ecran un pointeur sur SDL_Surface en donnée/résultat

Cette fonction affichage toutes les secondes un image appartenant au tableau load.
1s = load[0]
2s = load[1] etc ...
Le chargement dure 5s et se situe entre les niveaux et au niveau du jeu.
*/
void Final_ChargementEntreNiveau(SDL_Surface *load[5], SDL_Surface *&ecran);

/**
@brief Gestion d'affichage du menu de fin
@param event un SDL_Event en donnée/résultat
@param menufin un tableau de taille 2 de pointeur sur SDL_Surface
@param menpos un SDL_Rect en donnée/résultat
@param ecran un pointeur sur SDL_Surface
@param jeufin un Booléen en donnée/résultat

Cette fonction affiche le menu de fin en fin de partie (game over), en blittant sur l'ecran l'image qui correspond au choix du joueur
en appuyant sur H/B. Si le joueur appuis espace:
S'il se trouve sur Quitter, jeufin prend la valeur true, le jeu se quitte,
S'il se trouve sur Menu, jeufin prend la valeur false, il retourne sur le Menu.
*/
void Final_MenuFin(SDL_Event &event, SDL_Surface *menufin[2],SDL_Rect &menpos, SDL_Surface *ecran, bool &jeufin);

/**
@brief Allocation des images pour le menu de fin
@param menufin un tableau de taille 2 de SDL_Surface

Cette fonction affecte pour chaque élément du tableau l'image correspondant au choix du menu. Ici quitter et menu.
*/
void Final_AllocationMenuFin(SDL_Surface * menufin[2]);

/**
@brief Allocation des images pour le menu de pause
@param mpause un tableau de taille 3 de SDL_Surface

Cette fonction affecte pour chaque élément du tableau l'image correspondant au choix du menu de pause. Ici Reprendre, Menu et Quitter.
*/
void Final_AllocationMenuPause(SDL_Surface * mpause[3]);
#endif

