#include "menu.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
 #include "string.h"

// *************** ANIMATION ****************

void initmenu(imagee Menu[])
{
int i;
char animation[20];
for (i=0; i<68; i++)
{
sprintf(animation,"menu/menu-%d.png",i+1);
printf("%s",animation);
Menu[i].img=IMG_Load(animation);  
if(Menu[i].img == NULL)
{
printf("unable to load bg %s\n",SDL_GetError());
return;
}
Menu[i].pos_img_ecran.x=0;
Menu[i].pos_img_ecran.y=0;
}
}

// INITIALISATION DES IMAGES ET DES BOUTONS ************


// PLAY BOUTTON *********

void initialiser_play(imagee *imgbtn)
{
imgbtn->url="buttons/play.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img == NULL)
{
printf("unable to load bg %s \n",SDL_GetError());
return;
}
imgbtn->pos_img_ecran.x=270;
imgbtn->pos_img_ecran.y=170;
}

// SETTINGS BOUTTON

void initialiser_set(imagee *imgbtn)
{
imgbtn->url="buttons/settings.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img == NULL)
{
printf("unable to load bg %s \n",SDL_GetError());
return;
}
imgbtn->pos_img_ecran.x=270;
imgbtn->pos_img_ecran.y=225;
}

// Quit BOUTTON

void initialiser_qt(imagee *imgbtn)
{
imgbtn->url="buttons/quit.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img == NULL)
{
printf("unable to load bg %s \n",SDL_GetError());
return;
}
imgbtn->pos_img_ecran.x=270;
imgbtn->pos_img_ecran.y=335;
}

// MEET BOUTTON

void initialiser_meet(imagee *imgbtn)
{
imgbtn->url="buttons/meet.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img == NULL)
{
printf("unable to load bg %s \n",SDL_GetError());
return;
}
imgbtn->pos_img_ecran.x=270;
imgbtn->pos_img_ecran.y=280;
}



void initmenus(imagee *s)
{
s->img= IMG_Load("menu/menu-5.png");
s->pos_img_ecran.x=0;
s->pos_img_ecran.y=0;
s->pos_img_affiche.w=640;
s->pos_img_affiche.h=410;
}
void affiche(imagee p,SDL_Surface *screen)
{
SDL_BlitSurface(p.img,NULL,screen,&p.pos_img_ecran);
}
void liberer(imagee A)
{
SDL_FreeSurface(A.img);
}
