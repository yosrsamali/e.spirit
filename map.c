/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
/**

* @file map.c
*/
#include "map.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
 #include "string.h"
/**
* @brief To initialize the minimap b .
* @param b the background
* @param url the url of the image
* @return Nothing
*/

void initialiser_map (map *m,SDL_Surface *screen)
{
	m->map=IMG_Load("minimap.jpg");
	m->pos_map.x = 400;
	m->pos_map.y = 50;
	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0); 
	//SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,0,0,0));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}

/**
* @brief To show the minimap b .
* @param scren the screen
* @param b the background
* @return Nothing
*/

void perso_map(map *m,perso *p)
{
	m->perso_pos_map.x=p->posPerso.x/12+m->pos_map.x;
	m->perso_pos_map.y=(p->posPerso.y)/12+10+m->pos_map.y;
}

/**
* @brief To show the player in minimap .
* @param scren the screen
* @param b the background
* @return Nothing
*/

void affiche_map(map m , SDL_Surface *screen)
{
	SDL_BlitSurface(m.map, NULL, screen,&m.pos_map);
	SDL_BlitSurface(m.mini_perso, NULL, screen,&m.perso_pos_map);
}












