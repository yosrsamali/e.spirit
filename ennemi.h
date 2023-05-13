#ifndef ennemi_H
#define ennemi_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "perso.h"
#define posMax 610
#define posMin 300




typedef struct {
  SDL_Rect pos;
  SDL_Surface *t[8];
  int afficher_img; 

  int direction; 
  int etat; 
  int NombreTotale; 

 }Ennemi;
/*
typedef struct {
 SDL_Rect pos;
 SDL_Surface *t[8] ;
 int afficher_img;
int direction; 
  int etat; 
  int NombreTotale; 
 }perso ;

void initback (background * B);
void afficher_back (background B, SDL_Surface * screen);
void liberer_back(background B);
*/
void initEnnemi(Ennemi* E);
void afficher_Ennemi(Ennemi E, SDL_Surface * screen);
void animer_Ennemi (Ennemi* E);
void moveEnnemi (Ennemi* E);
int CollisonBB (perso P, Ennemi E);
void verifier_collision (perso *P, Ennemi *E); 
void moveIA( perso * P, Ennemi * E) ;
void liberer_Ennemi (Ennemi E);
/*
void initPerso (perso *P);
void afficher_Perso (perso P, SDL_Surface * screen);*/
#endif

