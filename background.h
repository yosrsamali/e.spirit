#ifndef header_h
#define header_h
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
 

typedef struct
{
	char *url;
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img;
	//Mix_Music *music;
	//Mix_Chunk *mus;
	SDL_Rect cam_pos;
}background;
typedef struct
{
char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;

typedef struct 
{
int score,temps;
char playername[20];
}scoreinfo;

typedef struct {
    SDL_Surface* sprite;    // image du sprite sheet
    int direction;          // direction de déplacement
    SDL_Rect postScreen;    // position par rapport à l'écran
    SDL_Rect posSprite;     // position par rapport au sprite sheet
} Entity;
void initback(background *b);
void initialiser_imageBOUTON (image *imgbtn);
//void initializeEntity(Entity* entity, SDL_Surface* sprite, int x, int y);
//void animate (image entity[]);

void afficher_back(background *b,SDL_Surface *screen);
void afficher_imageBTN1 (SDL_Surface *screen, image imge) ;

void partage(background *b,SDL_Surface *screen);
void afficher_scrolling(background *b,int direction);
//void animateEntity(Entity* entity);

void initialiser_audio (Mix_Music *music);
void liberer_musique (Mix_Music *music);
void liberer_back(background *b);
void liberer_bouton (image imge);
void savescore(scoreinfo s, char *filename );
void bestscore(char *filename, scoreinfo t[]);
#endif

