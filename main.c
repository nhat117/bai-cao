// Create a game of bai cao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
//Constant definition
#define DECK_SIZE  52
#define RANK_SIZE  13
#define MAXPLAYERCARD 4
#define MAXPRINT 3
//Enum definition 
typedef enum {SPADES = 1, CLUBS, DIAMONDS, HEARTS} // 1 to 4
	suittype;

typedef enum {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TINE, JACK, QUEEN, KING} // 1 to 13
	ranktype;

//Define 1 card include suit & rank;
typedef struct {
	suittype suit; // 1 to 4
	ranktype rank; // 1 to 13
} card;
//Function definition
void print(card deck[]);
char *ranktostr(ranktype rank, char *str);
char *suittostr(suittype suit, char *str);
void shuffle(card *deck);
void intdeck(card deck[]);
void printcard(card deck[]);
void handout(card *deck, card *player, card *comp, int userselect) ;
void pointcalc(card *player, card *comp);
void printinfo(card *player, card *comp);
// Main function
int main() {
		// Print out deck.
		card deck[DECK_SIZE], player1[MAXPLAYERCARD], comp[MAXPLAYERCARD];
		int userselect;
		intdeck(deck); // Initialise card
		printf("----Shuffle deck-----\n");
		shuffle(deck);
		printf(" Please enter 1 or 2 to select prepared deck: ");
		scanf("%d", &userselect);
		handout(deck, player1, comp, userselect);
		printinfo(player1, comp);
		return 0;
}
void printinfo(card *player1, card *comp) {
		printf("Player's card: \n");
		printcard(player1);
		printf("Computer's card: \n");
		printcard(comp);		
		pointcalc(player1, comp);
}
//Make a deck of card
void intdeck(card deck[]) {
	//Use for loop to create an organise deck
	for (int i = 0; i < DECK_SIZE; i ++) {
		deck[i].suit  = i / RANK_SIZE + 1; // Make 13 deck in the same suit
		deck[i].rank = i % RANK_SIZE + 1;
	}
}
//Convert suit to str to display
char *suittostr(suittype suit, char *str) { // Pass by reference
	const char *suits[] = {"Clubs", "Hearts", " Diamonds", "Spades"};
	strcpy(str, suits[suit- 1]);
	return str;
}
//Convt rank to str to display
char *ranktostr(ranktype rank, char *str) { // Pass by reference
	const char *ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",  							"Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	strcpy(str, ranks[rank - 1]);
	return str;
}
//Print out the card 
void printcard(card *deck) {
	const int RANK_STR_SIZE = 6;
	const int SUIT_STR_SIZE = 9;
	char rankstr[RANK_STR_SIZE], suitstr[SUIT_STR_SIZE];
 	for (int i = 0; i < MAXPRINT; i++) {
        printf("%s of %s\n", ranktostr(deck[i].rank, rankstr), suittostr(deck[i].suit, suitstr));
	}
}
//Card hand out
void handout(card *deck, card *player, card *comp, int userselect) {
	const int RANK_STR_SIZE = 6;
	const int SUIT_STR_SIZE = 9;
	char rankstr[RANK_STR_SIZE], suitstr[SUIT_STR_SIZE];
	if(userselect == 1) {
		for (int i = 0; i < 3; i++) {
			player[i] = deck[i];
			comp[i] = deck[i + 3];
		}
	} else {
		for (int i = 0; i < 3; i++) {
			player[i] = deck[i + 3];
			comp[i] = deck[i];
		}
	}
}
//Shuffle the card decks
void shuffle(card *deck) { // Pass by reference
	struct timeval tv;
	gettimeofday(&tv, NULL);
	int usec = tv.tv_usec;
	srand48(usec);
	for(int i = DECK_SIZE - 1; i > 0; i --) {
		size_t j = (unsigned int) (drand48() * (i + 1));
		card temp = deck[j];
		deck[j] = deck[i];
		deck [i] = temp;
	}
}
// Calculate point
void pointcalc(card *player, card *comp){
	int player_score, comp_score;
	for (int i = 0; i < MAXPRINT;i ++) {
		player_score += player[i].suit + player[i].rank;
		comp_score += comp[i].suit + comp[i].rank; 
	}
	if (player_score > comp_score) {
		printf("Player win\n");
	} else {
		printf("Computer win\n");
	}
}









