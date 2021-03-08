//Bai cao game function definition
//Library definition
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "baicaolib.h"
//Function definition
void printinfo(card *player1, card *comp) {
		printf("----Player's card ----- \n");
		printcard(player1);
		printf("----Computer's card ----\n");
		printcard(comp);
		printf("----Result----\n");		
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
		check10(comp, i);
		check10(player, i);
		player_score += player[i].rank;
		comp_score += comp[i].rank; 
	}
	player_score %= 10;
	comp_score %= 10;
	scorecompare(&comp_score, &player_score);
}

void check10(card *input, int i) {
	if (input[i].rank > 9) 
		input[i].rank = 0;
}

void scorecompare(int *comp_score, int *player_score) {
	//Compare score
	if (*player_score > *comp_score) {
		printf("Player win\n");
	} else if (*player_score == *comp_score) {
		printf("Draw");
	} else {
		printf("Computer win\n");
	}
}