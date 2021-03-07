// Create a game of bai cao
#include <stdio.h>
#include <string.h>

const int DECK_SIZE = 52;
const int RANK_SIZE = 13;

//Enum definition 

typedef enum {SPADES = 1, HEARTS, DIAMONDS, CLUBS} // 1 to 4
	suittype;

typedef enum {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TINE, JACK, QUEEN, KING} // 1 to 13
	ranktype;

//Define 1 card;
typedef struct {
	suittype suit; // 1 to 4
	ranktype rank; // 1 to 13
} card;

//Function definition
void print(card cards[]);
char *ranktostr(ranktype rank, char *str);
char *suittostr(suittype suit, char *str);
//Make card in the same suit

void intdeck(card cards[]) {
	//Use for loop to create an organise deck
	for (int i = 0; i < DECK_SIZE; i ++) {
		cards[i].suit  = i / RANK_SIZE + 1; // Make 13 cards in the same suit
		cards[i].rank = i % RANK_SIZE + 1;
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
void print(card cards[]) {
	const int RANK_STR_SIZE = 6;
	const int SUIT_STR_SIZE = 9;
	char rankstr[RANK_STR_SIZE], suitstr[SUIT_STR_SIZE];
 for (int i = 0; i < DECK_SIZE; i++) {
        printf("%s of %s\n", ranktostr(cards[i].rank, rankstr), suittostr(cards[i].suit, suitstr));
    }
}

int main() {
		// Print out cards.
		// card card[DECK_SIZE];
		// intdeck(card);
		// print(card);
		return 0;
}






