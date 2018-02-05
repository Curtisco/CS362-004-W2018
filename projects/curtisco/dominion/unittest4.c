/***************************************************************
* Filname: unittest4.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test updateCoins() function
***************************************************************/
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

int main(){
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = rand();
	struct gameState S;
	int bonus = 2;

	initializeGame(numPlayers, k, seed, &S);
	printf("\n~~~~~~~~~~ Now Testing updateCoins() Please Wait ~~~~~~~~~~\n\n");

	S.hand[0][0] = copper;
	S.hand[0][1] = copper;
	S.hand[0][2] = copper;
	S.hand[0][3] = copper;
	S.hand[0][4] = copper;
	updateCoins(0, &S, 0);
	printf("Testing with 5 copper: Expected Value: 5 coins, Returned Value: %d coins, Result: ", S.coins);
	testing(S.coins, 5);

	S.hand[0][0] = silver;
	S.hand[0][1] = silver;
	S.hand[0][2] = silver;
	S.hand[0][3] = silver;
	S.hand[0][4] = silver;
	updateCoins(0, &S, 0);
	printf("Testing with 5 silver: Expected Value: 10 coins, Returned Value: %d coins, Result: ", S.coins);
	testing(S.coins, 10);

	S.hand[0][0] = gold;
	S.hand[0][1] = gold;
	S.hand[0][2] = gold;
	S.hand[0][3] = gold;
	S.hand[0][4] = gold;
	updateCoins(0, &S, 0);
	printf("Testing with 5 gold: Expected Value: 15 coins, Returned Value: %d coins, Result: ", S.coins);
	testing(S.coins, 15);

	S.hand[0][0] = gold;
	S.hand[0][1] = gold;
	S.hand[0][2] = gold;
	S.hand[0][3] = gold;
	S.hand[0][4] = gold;
	updateCoins(0, &S, bonus);
	printf("Testing with 5 gold, +2 bonus: Expected Value: 17 coins, Returned Value: %d coins, Result: ", S.coins);
	testing(S.coins, 17);

	S.hand[0][0] = adventurer;
	S.hand[0][1] = gardens;
	S.hand[0][2] = mine;
	S.hand[0][3] = village;
	S.hand[0][4] = baron;
	updateCoins(0, &S, 0);
	printf("Testing with cards: Expected Value: 0 coins, Returned Value: %d coins, Result: ", S.coins);
	testing(S.coins, 0);
	return 0;
}