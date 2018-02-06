/***************************************************************
* Filname: cardtest3.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test village_card(struct gameState *state, int currentPlayer, int handPos) function
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

	initializeGame(numPlayers, k, seed, &S);
	S.whoseTurn = 0;
	S.hand[1][0] = village;

	printf("\n~~~~~~~~~~ Now Testing village_card Please Wait ~~~~~~~~~~\n\n");

	memcpy(&testState, &S, sizeof(struct gameState));
	cardEffect(village, choice1, choice2, choice3, &testState, handPos, &bonus);

	con = testState.handCount[0] - S.handCount[0];
	printf("Testing 1 Card Drawn: Expected Value: 1 card, Returned Value: %d cards, Result: ", con);
	testing(con, 1);

	con = testState.numActions - S.numActions;
	printf("Testing 2 More Actions: Expected Value: 2 Actions, Returned Value: %d Actions, Result: ", con);
	testing(con, 2);

	return 0;
}
