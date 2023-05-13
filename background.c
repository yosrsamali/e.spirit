#include <string.h>
#include <string.h>
#include "background.h"


///////////////initialiser bg 
void initback(background *b)
{
b->url = "bgjeu.jpg";
b->img = IMG_Load(b->url);
if(b->img == NULL)
{
printf("unable to load bg %s \n",SDL_GetError());
return;
}
b->pos1.x=0;
b->pos1.y=0;
b->pos1.w=1025; 
b->pos1.h=410;
b->pos2.x=0;
b->pos2.y=0;
b->pos2.w=100;
b->pos2.h=0;
b->cam_pos.x=0; 
b->cam_pos.y=0;

}

void initialiser_imageBOUTON (image *imgbtn)
{

imgbtn->url="bestscore.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img == NULL)
{
printf("unable to load bg %s \n",SDL_GetError());
return;
}
imgbtn->pos_img_ecran.x=455;
imgbtn->pos_img_ecran.y=10;
}




void afficher_back(background *b,SDL_Surface *screen)
{
SDL_BlitSurface(b->img,&b->pos1,screen,&b->pos2);
}

void afficher_imageBTN1 (SDL_Surface *screen, image imge) 
{
SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_scrolling(background *b,int direction)
{
if(direction==0)   //droite=0
{

 b->cam_pos.x+=5;
 b->pos1.x+=5;

if(b->cam_pos.x >=1748 )
{
 
b->pos1.x=0;
b->cam_pos.x=0;
}
} 
if (direction==1)  //left=1
{
 b->cam_pos.x-=5;
b->pos1.x-=5;
if (b->cam_pos.x<=0)
{
b->cam_pos.x =0;
b->pos1.x=0;
}
}

if(direction==2)  //up=2
{
 b->cam_pos.y-=10;	
b->pos1.y-=10;
if (b->cam_pos.y<=0);
{
b->cam_pos.y=0;

}
}
if(direction==3) //down=3
{
 b->cam_pos.y+=5;
b->pos1.y+=5;
if(b->cam_pos.y >=5)
{
b->cam_pos.y=0;
}

}	
}

/*

void initializeEntity(Entity* entity, SDL_Surface* sprite, int x, int y) 
{
SDL_Surface* spriteSheet = IMG_Load("45726.jpg");
    entity->sprite = sprite;
    entity->postScreen.x = 40;
    entity->postScreen.y = 45;
    // On divise le sprite en 3 lignes et 3 colonnes
    int NBL = 3;
    int NBC = 3;
    entity->posSprite.x = 0;
    entity->posSprite.y = 0;
    entity->posSprite.w = sprite->w / NBC;
    entity->posSprite.h = sprite->h / NBL;
}





void animateEntity(Entity* entity)
 {
    // On choisit la partie du sprite sheet à afficher
    SDL_Rect src = entity->posSprite;
    src.x = src.w * (entity->direction % 4);
    src.y = src.h * (entity->direction / 4);

    // On affiche l'image sur l'écran
    SDL_Rect dest = entity->postScreen;

    // On met à jour la position du sprite pour la prochaine itération
    entity->posSprite.x += entity->posSprite.w;
    if (entity->posSprite.x >= entity->sprite->w)
    {
        entity->posSprite.x = 0;
    }
}

void animate (image entity[])
{
int i;
char animation[20];
for (i=0; i<68; i++)
{
sprintf(animation,"images/image%d.png",i+1);
printf("%s",animation);
entity[i].img=IMG_Load(animation);  
if(entity[i].img == NULL)
{
printf("unable to load bg %s\n",SDL_GetError());
return;
}
entity[i].pos_img_ecran.x=0;
entity[i].pos_img_ecran.y=0;
}
}*/


///////liberation
void liberer_back(background *b)
{
SDL_FreeSurface(b->img);
}
void liberer_bouton (image imge)
{
SDL_FreeSurface(imge.img);
}
////////////////init audio
void initialiser_audio (Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==1)
{
printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("got.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME);
}

void liberer_musique (Mix_Music *music)
{
Mix_FreeMusic(music);
}
/*
/////les scores 
void savescore(scoreinfo s, char *filename )
{ 
FILE *fichier=NULL;
fichier=fopen("score.txt","a+");
if (fichier==NULL)
{
printf("impossible d'ouvrir le fichier");
}
else 
{
fprintf("le score du player %s est %d et le temps et %d",s.playername,s.score,s.temps);
fclose(fichier);
}
}


void bestscore(char *filename, scoreinfo t[])
{
scoreinfo s;
char ch[20];
FILE *fichier=NULL;
fichier=fopen("score.txt","r");
if (fichier==NULL)
{
printf("impossible d'ouvrir le fichier");
}
else 
{
sprintf(ch,"%d",s.score);
printf("%s",ch);
}
}*/



