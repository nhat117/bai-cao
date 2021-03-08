#ifndef ARRAY
#define ARRAY
//Library declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
//Define suit and rank with enum
typedef enum {SPADES = 1, CLUBS, DIAMONDS, HEARTS} // 1 to 4
	suittype;
typedef enum {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TINE, JACK, QUEEN, KING} // 1 to 13
	ranktype;
//Define 1 card 
typedef struct {
	suittype suit; // 1 to 4
	ranktype rank; // 1 to 13
} card;
//Function declaration
void print(card deck[]);
char *ranktostr(ranktype rank, char *str);
char *suittostr(suittype suit, char *str);
void shuffle(card *deck);
void intdeck(card deck[]);
void printcard(card deck[]);
void handout(card *deck, card *player, card *comp, int userselect) ;
void pointcalc(card *player, card *comp);
void printinfo(card *player, card *comp);
// Constant definition
#define DECK_SIZE 52
#define RANK_SIZE 13
#define MAXPLAYERCARD 4
#define MAXPRINT 3
#endif