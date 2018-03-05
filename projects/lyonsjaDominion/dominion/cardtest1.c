/***************************************************************
* Filname: cardtest1.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test adventurer_card(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z) function
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
	handPos = 0;

	printf("\n~~~~~~~~~~ Now Testing adventurer_card Please Wait ~~~~~~~~~~\n\n");

	initializeGame(numPlayers, k, seed, &S);
	S.whoseTurn = 0;
	memcpy(&testState, &S, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);

	con = testState.handCount[0] - S.handCount[0];
	printf("Testing 2 Cards Drawn: Expected Value: 2 cards, Returned Value: %d cards, Result: ", con);
	testing(con, 2);

	S.discard[0][0] = copper;
	S.discard[0][1] = smithy;
	S.discardCount[0] = 2;
	S.deckCount[0] = 2;
	S.deck[0][0] = smithy;
	S.deck [0][1] = adventurer;
	memcpy(&testState, &S, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);

	con = testState.handCount[0] - S.handCount[0];
	printf("Testing No Treasure & 1 in Discard: Expected Value: 1 cards, Returned Value: %d cards, Result: ", con);
	testing(con, 1);

	return 0;
}
