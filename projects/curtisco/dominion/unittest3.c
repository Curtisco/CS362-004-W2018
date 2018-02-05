/***************************************************************
* Filname: unittest3.c
* Author: Courtney Curtis
* Date: 2/4/2018
* Description: Unit Test getCost() function
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int getCostTest(int card){
	int costTest;
	costTest = getCost(card);
	return costTest;
}

int testing(int a, int b){
	if (a == b){
		printf("Success \n");
	}
	else{
		printf("Failure \n");
	}
}

int main(){
	int costTest;
	printf("\n~~~~~~~~~~ Now Testing getCost Please Wait ~~~~~~~~~~\n\n");

	costTest = getCostTest(-1);
	printf("Testing Invalid Value: Expected Value: -1, Returned Value: %d, Result: ", costTest);
	testing(costTest, -1);

	costTest = getCostTest(0);
	printf("Testing curse: Expected Value: 0, Returned Value: %d, Result: ", costTest);
	testing(costTest, 0);

	costTest = getCostTest(1);
	printf("Testing estate: Expected Value: 2, Returned Value: %d, Result: ", costTest);
	testing(costTest, 2);

	costTest = getCostTest(2);
	printf("Testing duchy: Expected Value: 5, Returned Value: %d, Result: ", costTest);
	testing(costTest, 5);

	costTest = getCostTest(3);
	printf("Testing province: Expected Value: 8, Returned Value: %d, Result: ", costTest);
	testing(costTest, 8);

	costTest = getCostTest(4);
	printf("Testing copper: Expected Value: 0, Returned Value: %d, Result: ", costTest);
	testing(costTest, 0);

	costTest = getCostTest(5);
	printf("Testing silver: Expected Value: 3, Returned Value: %d, Result: ", costTest);
	testing(costTest, 3);

	costTest = getCostTest(6);
	printf("Testing gold: Expected Value: 6, Returned Value: %d, Result: ", costTest);
	testing(costTest, 6);

	costTest = getCostTest(7);
	printf("Testing adventurer: Expected Value: 6, Returned Value: %d, Result: ", costTest);
	testing(costTest, 6);

	costTest = getCostTest(8);
	printf("Testing council_room: Expected Value: 5, Returned Value: %d, Result: ", costTest);
	testing(costTest, 5);

	costTest = getCostTest(9);
	printf("Testing feast: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(10);
	printf("Testing gardens: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(11);
	printf("Testing mine: Expected Value: 5, Returned Value: %d, Result: ", costTest);
	testing(costTest, 5);

	costTest = getCostTest(12);
	printf("Testing remodel: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(13);
	printf("Testing smithy: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(14);
	printf("Testing village: Expected Value: 3, Returned Value: %d, Result: ", costTest);
	testing(costTest, 3);

	costTest = getCostTest(15);
	printf("Testing baron: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(16);
	printf("Testing great_hall: Expected Value: 3, Returned Value: %d, Result: ", costTest);
	testing(costTest, 3);

	costTest = getCostTest(17);
	printf("Testing minion: Expected Value: 5, Returned Value: %d, Result: ", costTest);
	testing(costTest, 5);

	costTest = getCostTest(18);
	printf("Testing steward: Expected Value: 3, Returned Value: %d, Result: ", costTest);
	testing(costTest, 3);

	costTest = getCostTest(19);
	printf("Testing tribute: Expected Value: 5, Returned Value: %d, Result: ", costTest);
	testing(costTest, 5);

	costTest = getCostTest(20);
	printf("Testing ambassador: Expected Value: 3, Returned Value: %d, Result: ", costTest);
	testing(costTest, 3);

	costTest = getCostTest(21);
	printf("Testing cutpurse: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(22);
	printf("Testing embargo: Expected Value: 2, Returned Value: %d, Result: ", costTest);
	testing(costTest, 2);

	costTest = getCostTest(23);
	printf("Testing outpost: Expected Value: 5, Returned Value: %d, Result: ", costTest);
	testing(costTest, 5);

	costTest = getCostTest(24);
	printf("Testing salvager: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(25);
	printf("Testing sea_hag: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	costTest = getCostTest(26);
	printf("Testing treasure_map: Expected Value: 4, Returned Value: %d, Result: ", costTest);
	testing(costTest, 4);

	return 0;
}