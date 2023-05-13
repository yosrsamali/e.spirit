#ifndef MENU_H_
#define MENU_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#define SCREEN_H 410 
#define SCREEN_W 640 
typedef struct
{
char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}imagee;

// ******* ANNIMATION ***********

void initmenu(imagee Menu[]);
void initmenus(imagee *s);
void liberer(imagee A);
void affiche(imagee p,SDL_Surface *screen);

void initialiser_meet(imagee *imgbtn);
void initialiser_play(imagee *imgbtn);
void initialiser_qt(imagee *imgbtn);
void initialiser_set(imagee *imgbtn);
/*
//TEXTE
void initialiser_texte(texte *txte);
void initialiser_texte1(texte *txte);
void afficher_texte(SDL_Surface **screen, texte txte);
void liberer_texte (texte txte);

void initialiser_audio (Mix_Music *music);
void liberer_musique (Mix_Music *music);

void initialiser_audiobref (Mix_Chunk *music) ;
void liberer_musiquebref (Mix_Chunk *music) ;
*/
#endif
/*typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte;

void initialiser_jeu (image *imge);
void afficher_textejeu(SDL_Surface **screen, texte txte);
void initialiser_imageBOUTON1 (image *imgbtn);
void initialiser_imageBOUTON2 (image *imgbtn);
void initialiser_imageBOUTON3 (image *imgbtn);
void initialiser_imageBOUTON66 (image *imgbtn);
void initialiser_imageBOUTON4 (image *imgbtn);
void initialiser_pd(image *imgbtn);
void initialiser_qd(image *imgbtn);
void initialiser_md(image *imgbtn);
void initialiser_sd(image *imgbtn);
void initialiser_blocd(image *imgbtn);
void initialiser_imageBACK (image *imge);
void afficher_imageBMP (SDL_Surface *screen, image imge);
void liberer_image (image imge);
void afficher_image(SDL_Surface *screen, image imge) ;

*/

