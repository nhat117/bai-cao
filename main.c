// Create a game of bai cao
// Main function of bai cao game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "baicaolib.h"

int main() {
		// Print out deck.
		card deck[DECK_SIZE], player1[MAXPLAYERCARD], comp[MAXPLAYERCARD];
		int userselect;
		intdeck(deck); // Initialise card
		printf("------Bai Cao-----\n");
		shuffle(deck);
		printf(" Please enter 1 or 2 to select prepared deck: ");
		scanf("%d", &userselect);
		handout(deck, player1, comp, userselect);
		printinfo(player1, comp);
		return 0;
}










