#ifndef fonction_H
#define fontion_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_getenv.h>
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>

#define SCREEN_H 2000
#define SCREEN_W 2000

typedef struct {
    int heures;
    int minutes;
    int secondes;
} Temps;

typedef struct  {
    char nom[50];
    int age;
    float taille;
SDL_Rect position;
SDL_Surface*image;
}Personne;

typedef struct
{
char*url;
SDL_Rect pos_minimap;
SDL_Surface *image_miniature;
SDL_Surface *image_bonhomme;
SDL_Rect pos_bonhomme;

}Minimap;

typedef struct
{
SDL_Surface*txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font*police;
}texte;


void initmap(Minimap * m);
void afficherminimap (Minimap m, SDL_Surface * screen);
void affichertemps (Temps temps, SDL_Surface * screen);
int collisionPP( Personne p, SDL_Surface * masque);
void animerminimap(Minimap *m);
//int IA(Grille g, int Joueur_Programme);

#endif // FONTION_H_INCLUDED

