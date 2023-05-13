#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct 
{	
	SDL_Surface *map ;
	SDL_Rect pos_map;
	SDL_Surface *mini_perso;
	SDL_Rect perso_pos_map;

}map;//structure  bich tnks 3lina les variables 

	void initialiser_map (map *m,SDL_Surface *screen) ;
	void perso_map(map *m,perso *p);
	void affiche_map(map m, SDL_Surface *screen);

#endif
