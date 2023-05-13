#include "ennemi.h"
#include "perso.h"
/*
void initback (background *B) 
{
	B->img = IMG_Load ("esprit_face.png");
	if (B->img == NULL) 
{ 
printf ("erreur \n");
}
	else { 
                B->pos.x = 0;
		B->pos.y = 0;
		B->pos.w = 1920;
		B->pos.h = 1080;
              }
}
*/
void initEnnemi (Ennemi* E)
{
	E -> t[0] = IMG_Load ("STAND.png");
        E -> t[1] = IMG_Load ("RIGHT.png");	
	E -> t[2] = IMG_Load ("RIGHT1.png");	
	E -> t[3] = IMG_Load ("RIGHT2.png");
	E -> t[4] = IMG_Load ("LEFT.png");
	E -> t[5] = IMG_Load ("LEFT1.png");	
	E -> t[6] = IMG_Load ("LEFT2.png");
	E -> t[7] = IMG_Load ("DEAD.png");
	
if ((E->t[0] == NULL))  
	{ printf ("error. \n");}

else { 
                E->pos.x = 40;
		E->pos.y = 250;
		E->pos.w = 0;
		E->pos.h = 0;
		E->afficher_img =0;
		E->etat = 1;
		(*E).direction = 0;
		E->NombreTotale = 8;}
}
/*
void afficher_back (background B, SDL_Surface * screen)
{
SDL_BlitSurface (B.img, NULL, screen, &B.pos); 
}
*/
void afficher_Ennemi (Ennemi E, SDL_Surface* screen) 
{if (E.etat ==1) {SDL_BlitSurface (E.t[E.afficher_img], NULL, screen, &E.pos); }
else {SDL_BlitSurface (E.t[7], NULL, screen, &E.pos);}
}
/*
void liberer_back (background B) 
{
SDL_FreeSurface (B.img);
}
*/
void liberer_Ennemi (Ennemi E)
{
int i;
for (i=0;i<E.NombreTotale;i++) SDL_FreeSurface (E.t[i]);
}

void moveEnnemi (Ennemi* E)
{
	if (E->pos.x > posMax) {E->direction = 1;}
	if (E->pos.x < posMin) {E->direction = 0;}
	if (E->direction == 0) {E->pos.x ++;}
	else {E->pos.x -- ;}
}

void animer_Ennemi (Ennemi* E)
{
	if (E->direction == 0) {if (E->afficher_img < 3) {E->afficher_img ++;}
	else {E->afficher_img=1;}}
	if (E->direction == 1) {if ((E->afficher_img < 4) || (E->afficher_img==6)) {E->afficher_img=4;}
	else {E->afficher_img++;}}
}


int CollisonBB (perso P, Ennemi E)
{
	int collision;
if ((P.posPerso.w + P.posPerso.x < E.pos.x) || (P.posPerso.x > E.pos.x + E.pos.w) || (P.posPerso.h + P.posPerso.y < E.pos.y) || (P.posPerso.y > P.posPerso.y + P.posPerso.h))
	{collision = 0;}
	else {collision = 1;}
	return collision;
}
/*
void initPerso (perso* E)
{
	E -> t[0] = IMG_Load ("stand.png");
	E -> t[1] = IMG_Load ("right.png");	
	E -> t[2] = IMG_Load ("right1.png");	
	E -> t[3] = IMG_Load ("right2.png");
	E -> t[4] = IMG_Load ("left.png");
	E -> t[5] = IMG_Load ("left1.png");	
	E -> t[6] = IMG_Load ("left2.png");
	E -> t[7] = IMG_Load ("dead.png");
if ((E->t [0] == NULL))  
	{ printf ("There has been an error. \n");}
	else { E->pos.x = 400;
		E->pos.y = 400;
		E->pos.w = 88;
		E->pos.h = 125;
		E->afficher_img =0;
		E->etat = 1;
		E->direction = 0;
		E->NombreTotale = 8;}
}

void afficher_Perso (perso P, SDL_Surface* screen) 
{
if (P.etat == 1) {SDL_BlitSurface (P.t[0], NULL, screen, &P.pos);}
else {SDL_BlitSurface (P.t[7], NULL, screen, &P.pos);}
}
*/
void verifier_collision (perso *P, Ennemi *E) 
{
int collision;
collision = CollisonBB (*P, *E); 
if (collision == 1) {P->etat = 0;}
}
void moveIA( perso *P, Ennemi *E)
{
  if ((P->posPerso.x >= posMin) && (P->posPerso.x <= posMax))
    if (P->posPerso.x - E ->pos.x > 0)
      E -> direction = 0;
    else if (P->posPerso.x - E ->pos.x <= 0)
      E -> direction = 1;
}

