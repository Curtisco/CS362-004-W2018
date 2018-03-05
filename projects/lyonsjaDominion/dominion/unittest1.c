/***************************************************************
* Filname: unittest1.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test isGameOver() function
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

int testing(int a, int b){
	if (a == b){
		printf(" Result: Success \n");
	}
	else{
		printf(" Result: Failure \n");
	}
}

int retVal(int a){
	if (a == 0){
		printf(" Returned Value: Game still going,");
	}
	else{
		printf(" Returned Value: Game is over,");
	}
}

int main(){
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = rand();
	struct gameState S;
	int card1, card2, card3;

	printf("\n~~~~~~~~~~ Now Testing isGameOver() Please Wait ~~~~~~~~~~\n\n");

	initializeGame(numPlayers, k, seed, &S);
	S.supplyCount[province] = 1;
	printf("Testing with one province: Expected Value: Game still going,");
	retVal(isGameOver(&S));
	testing(isGameOver(&S), 0);

	initializeGame(numPlayers, k, seed, &S);
	S.supplyCount[province] = 0;
	printf("Testing with no provinces: Expected Value: Game is over,");
	retVal(isGameOver(&S));
	testing(isGameOver(&S), 1);

	initializeGame(numPlayers, k, seed, &S);
	card1 = k[rand()%10];				//Picks a randomly selected card in k
	do{
		card2 = k[rand()%10];
	} while (card1 == card2);
	S.supplyCount[card1] = 0;
	S.supplyCount[card2] = 0;
	S.supplyCount[province] = 1;
	printf("Testing with one province and two empty supply decks: Expected Value: Game still going,");
	retVal(isGameOver(&S));
	testing(isGameOver(&S), 0);

	initializeGame(numPlayers, k, seed, &S);
	do{
		card3 = k[rand()%10];
	} while (card3 == card2 | card3 == card1);
	S.supplyCount[card1] = 0;
	S.supplyCount[card2] = 0;
	S.supplyCount[card3] = 0;
	S.supplyCount[province] = 1;
	printf("Testing with one province and three empty supply decks: Expected Value: Game is over,");
	retVal(isGameOver(&S));
	testing(isGameOver(&S), 1);

	initializeGame(numPlayers, k, seed, &S);
	S.supplyCount[card1] = 0;
	S.supplyCount[card2] = 0;
	S.supplyCount[card3] = 0;
	S.supplyCount[province] = 0;
	printf("Testing with no provinces and three empty supply decks: Expected Value: Game is over,");
	retVal(isGameOver(&S));
	testing(isGameOver(&S), 1);

	return 0;
}