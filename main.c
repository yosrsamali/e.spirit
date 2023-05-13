#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include "background.h"
#include "perso.h"
#include "ennemi.h"
#include "SDL/SDL.h"
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 
#include "map.h"
#include "time.h"
#include "menu.h"

int main()
{
int conti =0;
SDL_Rect enigpos;
    
    
    
SDL_Rect cam_pos;
Ennemi E;
SDL_Surface *screen,*enig;
//Entity ent;
image ent[9];
SDL_Surface sprite;
//MINI
Time temps;
Time tempsenig;
int hi=1;

int x=0,y=0,i=1;
Mix_Music *music;
image imscore;
int done=1,cont=1;
SDL_Event event,eventa;
background bg;
Mix_Music *musice;
Mix_Chunk *bref;
int com =1;
int ih=1,donee=1;
TTF_Init();

imagee s, Menu[9], meet,play,set,quit;


/// JEUU

int frame=0;
const int FPS=30;
int acc=0;
int jump=0;
int j=0;
Uint32 start;
// NOUV pour integ MINIMAP
map m;
initialiser_map (&m,screen) ;

inittemps(&temps);
inittempsenig(&tempsenig);
enig = IMG_Load("1.jpg");
enigpos.x=0;
enigpos.y=0;
//
perso p;
initPerso(&p);
SDL_EnableKeyRepeat(1,1);
initialiser_audio(music);
initback(&bg);
//initializeEntity(& ent,&sprite,x,y);
initialiser_imageBOUTON (&imscore);
initPerso(&p);
initEnnemi (&E);


SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(640,410,32,SDL_SWSURFACE |SDL_SRCALPHA | SDL_RESIZABLE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("-- E.SPIRIT --",NULL);
SDL_WM_SetIcon(IMG_Load("logo.png"),NULL);
printf("DUCKK \n");


if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
musice = Mix_LoadMUS("sounds/helloo.mp3");
Mix_PlayMusic(musice,-1);
Mix_VolumeMusic(50);
bref=Mix_LoadWAV("sounds/simple.wav");
	    
	    
	    
initmenu(&Menu[i]);
initmenus(&s);
initialiser_meet(&meet);
initialiser_set(&set);
initialiser_play(&play);
initialiser_qt(&quit);



while (donee ==1)
{
affiche(s,screen);
if(com == 1)
{
if(ih==68)
{
ih=0;
}
SDL_BlitSurface(Menu[ih].img,NULL,screen,&Menu[ih].pos_img_ecran);
ih++;
SDL_Delay(300);

affiche(play,screen);
affiche(set,screen);
affiche(quit,screen);
affiche(meet,screen);
while(SDL_PollEvent(&eventa))
{
switch(eventa.type)
{

case SDL_KEYDOWN:

switch(eventa.key.keysym.sym)
{


case SDL_RESIZABLE:   //pour passer en mode fullscreen windowed
conti+=1;
break;

case SDLK_ESCAPE:    //quit
done=0;
break;
case SDLK_a:

{
while(done)
{

        /*serialport_read_until(fd, buffer, '\r',99, 10000);
        for (h=0 ; buffer[h]!='\r' && h<100 ; h++);
        buffer[h] = 0;
         if(strstr(buffer,"Forward"))
         {
afficher_scrolling(&bg,0);
	p.score++;
                    p.direction=3;
                    deplacerPerso(&p,acc);
        // écriture du résultat
        printf("Forward \n");
        serialport_writebyte(fd,val1);
         }
         if(strstr(buffer,"Jump"))
         {
afficher_scrolling(&bg,2);
	jump=1;
        // écriture du résultat
        printf("Jump \n");
        serialport_writebyte(fd,val2);
         }
*/
afficher_back(&bg,screen);

afficher_Ennemi (E, screen); 

afficherPerso(p,screen);
//animate (&ent[i]);
 //SDL_BlitSurface(img,NULL,screen,&posImage);
        if(jump==1)
        {
            j++;
            if(j==17)
            {
                j=0;
                jump=0;
            }
        }
	
start=SDL_GetTicks();
afficherPerso(p,screen);
animerPerso(&p,frame);
SDL_PollEvent(&event);
if (E.etat == 1) 
{
moveEnnemi(&E); 
animer_Ennemi(&E);
}
verifier_collision (&p, &E);
moveIA(  &p, &E) ;
switch(event.type)
{
case SDL_QUIT:
done=0;
break;
// MINIMAP ****************
case SDL_KEYUP:
	switch(event.key.keysym.sym)
   {
   	case SDLK_k:
   	{
			while(hi)
			{
				update_timeenig(&tempsenig);
				SDL_BlitSurface(enig,NULL,screen,&enigpos);
				displaytime(tempsenig,screen);
				SDL_Flip(screen);
				if(tempsenig.ss==temps.ss+15)
				{
					hi=0;
				}
			}
			break ;
		}
	}
break;
                //////////////////
case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
	afficher_scrolling(&bg,0);
	p.score++;
        p.direction=3;
        deplacerPerso(&p,acc);
	
}
if (event.key.keysym.sym==SDLK_LEFT)
{
	afficher_scrolling(&bg,1);
	p.score--;
        p.direction=0;
        deplacerPerso(&p,acc);
}
if (event.key.keysym.sym==SDLK_UP)
{	
	//afficher_scrolling(&bg,2);
	jump=1;
	
}
/*if (event.key.keysym.sym==SDLK_DOWN)
{ 
	afficher_scrolling(&bg,3);
}*/
break;

}
//// MINIII
update_time(&temps);
displaytime(temps,screen);
///////////
saut(&p,j);
perso_map(&m,&p);
affiche_map(m,screen);
SDL_Flip(screen);
}

}
break;
//  utilisation du clavier pour naviguer sur le menu
/*case SDLK_UP:

	if (i==1)
		{
		 Mix_PlayChannel(1,clickmusic,0);
			i=3;
		}
	else
	        {
	         Mix_PlayChannel(1,clickmusic,0);
		        i--;
	        }
break;


case SDLK_DOWN:
	if(i==3)
              	{
              	Mix_PlayChannel(1,clickmusic,0);
              	i=1;
              	}
	else
               {
                 Mix_PlayChannel(1,clickmusic,0);
                 i++;

                }
break;
*/
/*case SDLK_RETURN:
if(i==1)
{
Mix_PlayChannel(1,clickmusic,0);
start(screen);

}
else if (i==2)
{
Mix_PlayChannel(1,clickmusic,0);
option(screen);

}
else if(i==3)
{
Mix_PlayChannel(1,clickmusic,0);
done=0;
}
break;
}

*/

}
break;
case SDL_QUIT:
done =0;
break;
}


SDL_Flip(screen);
}
}}

liberer_Ennemi (E);

liberer_back(&bg);
liberer_bouton (imscore);
liberer_musique(music);
liberer(s);
liberer(set);
liberer(meet);
liberer(quit);
liberer(play);
SDL_FreeSurface(screen);
SDL_Quit();
TTF_Quit();
return 0;
}
