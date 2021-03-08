//Baicao function declaration
#ifndef ARRAY
#define ARRAY
//Define suit and rank with enum
typedef enum {SPADES = 1, CLUBS, DIAMONDS, HEARTS} // 1 to 4
	suittype;
typedef enum {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} // 1 to 13
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
void check10(card *input, int i);
void scorecompare(int *comp_score, int *player_score);
// Constant definition
#define DECK_SIZE 52
#define RANK_SIZE 13
#define MAXPLAYERCARD 4
#define MAXPRINT 3
#endif