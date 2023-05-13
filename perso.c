#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "perso.h"  
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 



void initPerso(perso *p)
{
    p->sprite=IMG_Load("persooo.png");

    p->posPerso.x=10;
    p->posPerso.y=300;
    p->posSprite.w=65;
    p->posSprite.h=180;
    p->posSprite.y=10;
    p->posSprite.x=20;
    p->score=0;
    p->vie=3;
    p->direction=2;
}



//height = hauteur
//wight = largeur
void afficherPerso(perso p, SDL_Surface *screen)
{
    SDL_Surface *texte=NULL;
    char s[10];
    TTF_Font *police=NULL;
    SDL_Color couleurBlanche= {255,255,255};
    TTF_Init();
    SDL_Rect positiontexte;
    
    police=TTF_OpenFont("angelina.TTF",40);
    sprintf (s,"Score: %d",p.score);
    //texte=TTF_RenderText_Blended(police,s,couleurBlanche);
    positiontexte.x=5;
    positiontexte.y=40;
    //SDL_BlitSurface(texte,NULL,screen,&positiontexte);

    SDL_Surface *imghearts=NULL;
    SDL_Rect posHearts;
    posHearts.x=70;
    posHearts.y=0;
    imghearts = IMG_Load("health1.png");
    SDL_BlitSurface(imghearts,NULL,screen,&posHearts);

    SDL_Surface *vie=NULL;
    SDL_Rect positiontxtvie;
    
    //vie=TTF_RenderText_Blended(police,"Vie",couleurBlanche);
    
    //positiontxtvie.x=5;
    //positiontxtvie.y=0;
    //SDL_BlitSurface(vie,NULL,screen,&positiontxtvie);
    SDL_BlitSurface(p.sprite,&p.posSprite,screen,&p.posPerso);
}




/*
void initPerso(perso *p)
{
    p->sprite = IMG_Load("persooo.png");

    p->posPerso.x = 10;
    p->posPerso.y = 300;
    p->posSprite.w = 65;
    p->posSprite.h = 180;
    p->posSprite.y = 10;
    p->posSprite.x = 20;
    p->score = 0;
    p->vie = 3;
    p->direction = 2;
}

void afficherPerso(perso p, SDL_Surface *screen)
{
    static TTF_Font *police = NULL;
    static SDL_Color couleurBlanche = {255, 255, 255};
    static SDL_Surface *texte = NULL;
    static SDL_Surface *vie = NULL;
    static SDL_Surface *imghearts = NULL;
    char s[10];
    SDL_Rect positiontexte;
    SDL_Rect positiontxtvie;
    SDL_Rect posHearts;

    if (police == NULL)
    {
        TTF_Init();
        police = TTF_OpenFont("angelina.TTF", 40);
    }

    sprintf(s, "Score: %d", p.score);
    texte = TTF_RenderText_Blended(police, s, couleurBlanche);
    positiontexte.x = 5;
    positiontexte.y = 40;
    SDL_BlitSurface(texte, NULL, screen, &positiontexte);

    imghearts = IMG_Load("health1.png");
    posHearts.x = 70;
    posHearts.y = 0;
    SDL_BlitSurface(imghearts, NULL, screen, &posHearts);

    vie = TTF_RenderText_Blended(police, "Vie", couleurBlanche);
    positiontxtvie.x = 5;
    positiontxtvie.y = 0;
    SDL_BlitSurface(vie, NULL, screen, &positiontxtvie);
    SDL_BlitSurface(p.sprite,&p.posSprite,screen,&p.posPerso);
    }
*/
void deplacerPerso(perso *p,int a)
{
    int speed=2;
    if(a==1)
        speed=10;
    if (a==0)
        speed=4;
    switch(p->direction)
    {
    case 3:
        p->posPerso.x+=speed;
        break;
    case 0:
        p->posPerso.x-=speed;
        break;
    }
}




void animerPerso(perso* p,int frame)
{
    if(p->direction==3) //yemshi aalimin
        p->posSprite.y=30;
    else if(p->direction==2) //yetnafes aalimin
        p->posSprite.y=0;
    else if(p->direction==0) //yemshi aalisar
        p->posSprite.y=160;
    else if(p->direction==1) //yetnafes aalisar
        p->posSprite.y=200;
    if(p->posSprite.x>=900) //350 --> kamelt e tsawer lkol
        p->posSprite.x=0;
    else p->posSprite.x+=50*frame;
}



void saut(perso* p,int j)
{

    if(p->direction==2)
    {
        if(j<=8)
        {
            p->posPerso.y= p->posPerso.y-(1*j);
            p->posPerso.x=p->posPerso.x+(0.5*j);
        }

        else if(j>8)
        {
            p->posPerso.y= p->posPerso.y+(1*(j-8));
            p->posPerso.x=p->posPerso.x+(0.5*j);
        }
    }
    else if(p->direction==1)
    {
        if(j<=8)
        {
            p->posPerso.y= p->posPerso.y-(1*j);
            p->posPerso.x=p->posPerso.x-(0.5*j);
        }

        else if(j>8)
        {
            p->posPerso.y= p->posPerso.y+(1*(j-8));
            p->posPerso.x=p->posPerso.x-(0.5*j);
        }
    }
}


int serialport_init(const char* serialport, int baud)
{
    struct termios toptions;
    int fd;

    //fd = open(serialport, O_RDWR | O_NOCTTY | O_NDELAY);
    fd = open(serialport, O_RDWR | O_NONBLOCK );

    if (fd == -1)  {
        perror("serialport_init: Unable to open port ");
        return -1;
    }

    //int iflags = TIOCM_DTR;
    //ioctl(fd, TIOCMBIS, &iflags);     // turn on DTR
    //ioctl(fd, TIOCMBIC, &iflags);    // turn off DTR

    if (tcgetattr(fd, &toptions) < 0) {
        perror("serialport_init: Couldn't get term attributes");
        return -1;
    }
    speed_t brate = baud; // let you override switch below if needed
    switch(baud) {
    case 4800:   brate=B4800;   break;
    case 9600:   brate=B9600;   break;
#ifdef B14400
    case 14400:  brate=B14400;  break;
#endif
    case 19200:  brate=B19200;  break;
#ifdef B28800
    case 28800:  brate=B28800;  break;
#endif
    case 38400:  brate=B38400;  break;
    case 57600:  brate=B57600;  break;
    case 115200: brate=B115200; break;
    }
    cfsetispeed(&toptions, brate);
    cfsetospeed(&toptions, brate);

    // 8N1
    toptions.c_cflag &= ~PARENB;
    toptions.c_cflag &= ~CSTOPB;
    toptions.c_cflag &= ~CSIZE;
    toptions.c_cflag |= CS8;
    // no flow control
    toptions.c_cflag &= ~CRTSCTS;

    //toptions.c_cflag &= ~HUPCL; // disable hang-up-on-close to avoid reset

    toptions.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
    toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl

    toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    toptions.c_oflag &= ~OPOST; // make raw

    // see: http://unixwiz.net/techtips/termios-vmin-vtime.html
    toptions.c_cc[VMIN]  = 0;
    toptions.c_cc[VTIME] = 0;
    //toptions.c_cc[VTIME] = 20;

    tcsetattr(fd, TCSANOW, &toptions);
    if( tcsetattr(fd, TCSAFLUSH, &toptions) < 0) {
        perror("init_serialport: Couldn't set term attributes");
        return -1;
    }

    return fd;
}

int serialport_close( int fd )
{
    return close( fd );
}

int serialport_writebyte( int fd, uint8_t b)
{
    int n = write(fd,&b,1);
    if( n!=1)
        return -1;
    return 0;
}


int serialport_write(int fd, const char* str)
{
    int len = strlen(str);
    int n = write(fd, str, len);
    if( n!=len ) {
        perror("serialport_write: couldn't write whole string\n");
        return -1;
    }
    return 0;
}


int serialport_read_until(int fd, char* buf, char until, int buf_max, int timeout)
{
    char b[1];  // read expects an array, so we give it a 1-byte array
    int i=0;
    do { 
        int n = read(fd, b, 1);  // read a char at a time

        if( n==-1) return -1;    // couldn't read
        if( n==0 ) {
            //usleep( 1 * 1000 );  // wait 1 msec try again
            timeout--;
            if( timeout==0 ) return -2;
            continue;
        }
#ifdef SERIALPORTDEBUG  
        printf("serialport_read_until: i=%d, n=%d b='%c'\n",i,n,b[0]); // debug
#endif
        buf[i] = b[0]; 
        i++;
    } while( b[0] != until && i < buf_max && timeout>0 );

    buf[i] = 0;  // null terminate the string
    return 0;
}

int serialport_flush(int fd)
{
    sleep(2); //required to make flush work, for some reason
    return tcflush(fd, TCIOFLUSH);
}

