/***************************************************************
* Filname: cardtest2.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test smithy_card(int i, struct gameState *state, int currentPlayer, int handPos) function
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"

int testing(int a, int b){
	if (a == b){
		printf("Success \n");
	}
	else{
		printf("Failure \n");
	}
}

int main(){
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = rand();
	struct gameState S;
	struct gameState testState;
	int bonus, handPos, choice1, choice2, choice3, con, i;
	choice1 = 0;
	choice2 = 0;
	choice3 = 0;

	printf("\n~~~~~~~~~~ Now Testing smithy_card Please Wait ~~~~~~~~~~\n\n");

	initializeGame(numPlayers, k, seed, &S);
	S.hand[0][0] = smithy;
	S.whoseTurn = 0;
	memcpy(&testState, &S, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testState, handPos, &bonus);
	
	con = testState.handCount[0] - S.handCount[0];
	printf("Testing 3 Drawn Cards & 1 Discarded: Expected Value: 2 cards, Returned Value: %d cards, Result: ", con);
	testing(con, 2);

	con = testState.playedCardCount;
	printf("Testing 1 Card Played: Expected Value: 1 card, Returned Value: %d card, Result: ", con);
	testing(con, 1);

	con = S.deckCount[0] - testState.deckCount[0];
	printf("Testing Deck decreased by 3: Expected Value: 3 cards, Returned Value: %d cards, Result: ", con);
	testing(con, 3);

	con = 0;
	for (i = 0; i < testState.handCount[0]; i++){
		if(testState.hand[0][i] == smithy) con = 1;
	}
	printf("Testing Smithy removed: Expected Value: 0 cards, Returned Value: %d cards, Result: ", con);
	testing(con, 0);

	return 0;
}