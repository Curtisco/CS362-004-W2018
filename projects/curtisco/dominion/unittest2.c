/***************************************************************
* Filname: unittest2.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test fullDeckCount() function
***************************************************************/
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

int testing(int a, int b){
	if (a == b){
		printf("Success \n");
	}
	else{
		printf("Failure \n");
	}
}

int wipeDeck(struct gameState *S){
	int i;
	for (i=0; i<MAX_HAND; i++)	S->hand[1][i] = -1;
	for (i=0; i<MAX_DECK; i++)	S->deck[1][i] = -1;
};

int main(){
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = rand();
	struct gameState S;
	int card, ranNum, i;

	initializeGame(numPlayers, k, seed, &S);
	card = k[rand()%10];					//Picks a randomly selected card in k
	ranNum = rand()%5+1;

	printf("\n~~~~~~~~~~ Now Testing fullDeckCount Please Wait ~~~~~~~~~~\n\n");

	printf("Testing 0 cards: Expected Value: 0 cards, Returned Value: %d cards, Result: ", fullDeckCount(1, card, &S));
	testing(fullDeckCount(1, card, &S), 0);

	gainCard(card, &S, 2, 1);
	printf("Testing 1 card in hand 0 cards in deck: Expected Value: 1 cards, Returned Value: %d cards, Result: ", fullDeckCount(1, card, &S));
	testing(fullDeckCount(1, card, &S), 1);
	wipeDeck(&S);

	gainCard(card, &S, 1, 1);
	printf("Testing 0 cards in hand 1 card in deck: Expected Value: 1 cards, Returned Value: %d cards, Result: ", fullDeckCount(1, card, &S));
	testing(fullDeckCount(1, card, &S), 1);
	wipeDeck(&S);

	gainCard(card, &S, 1, 1);
	gainCard(card, &S, 2, 1);
	printf("Testing 1 card in hand and deck: Expected Value: 2 cards, Returned Value: %d cards, Result: ", fullDeckCount(1, card, &S));
	testing(fullDeckCount(1, card, &S), 2);
	wipeDeck(&S);

	for (i=0; i<ranNum; i++) gainCard(card, &S, 2, 1);
	printf("Testing multible cards in hand: Expected Value: %d cards, Returned Value: %d cards, Result: ", ranNum, fullDeckCount(1, card, &S));
	testing(fullDeckCount(1, card, &S), ranNum);
	wipeDeck(&S);

	for (i=0; i<ranNum; i++) gainCard(card, &S, 1, 1);
	printf("Testing multible cards in deck: Expected Value: %d cards, Returned Value: %d cards, Result: ", ranNum, fullDeckCount(1, card, &S));
	testing(fullDeckCount(1, card, &S), ranNum);
	wipeDeck(&S);



	return 0;
}