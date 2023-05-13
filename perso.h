#ifndef HEADER_H_
#define HEADER_H_
#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h>   
#include <errno.h>  
#include <termios.h> 
#include <string.h>   
#include <sys/ioctl.h>
#include <stdint.h> 


typedef struct
{
    SDL_Surface *sprite;
    SDL_Rect posPerso;
    SDL_Rect posSprite;
	int etat;
    int direction;
    int score;
    int vie;
} perso;

void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface *screen);
void deplacerPerso(perso *p,int a);
void saut(perso* p,int j);
void animerPerso(perso* p,int frame);

int serialport_init(const char* serialport, int baud);
int serialport_close( int fd );
int serialport_writebyte( int fd, uint8_t b);
int serialport_read_until(int fd, char* buf, char until, int buf_max, int timeout);
int serialport_flush(int fd);

#endif

