/***************************************************************
* Filname: randomtestadventurer.c
* Author: Courtney Curtis
* Date: 2/18/2018
* Description: Random tests on the adventurer card 
***************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

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
	int bonus, handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, con, i = 0, test1 = 0, test2 = 0;

	printf("\n~~~~~~~~~~ Now Testing adventurer_card Please Wait ~~~~~~~~~~\n\n");
	while (i<100){
		initializeGame(numPlayers, k, seed, &S);
		S.whoseTurn = 0;
		memcpy(&testState, &S, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);

		con = testState.handCount[0] - S.handCount[0];
		//printf("Testing 2 Cards Drawn: Expected Value: 2 cards, Returned Value: %d cards, Result: ", con);
		//testing(con, 2);
		if (con != 0 ) test1++;

		S.discard[0][0] = copper;
		S.discard[0][1] = smithy;
		S.discardCount[0] = 2;
		S.deckCount[0] = 2;
		S.deck[0][0] = smithy;
		S.deck [0][1] = adventurer;
		memcpy(&testState, &S, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);

		con = testState.handCount[0] - S.handCount[0];
		//printf("Testing No Treasure & 1 in Discard: Expected Value: 1 cards, Returned Value: %d cards, Result: ", con);
		//testing(con, 1);
		if (con != 0 ) test2++;
		i++;
	}	
	printf("The player got the wrong number of drawn cards %d of 100 times. \n The player didn't discarded the card %d of 100 times.", test1, test2);
	return 0;
}
