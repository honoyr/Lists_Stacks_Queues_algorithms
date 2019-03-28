#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 500);
	tankPush(tank, 510);
	tankPush(tank, 520);
	tankPush(tank, 530);
	tankPush(tank, 540);
	printf("Complete!\n");

	printf("Number of stacks in tank: %d\n", tank->n);
	printf("Popping:\n");
	for (int i = 0; i < 5; i++)
		printf("%d\n", tankPop(tank));

	printf("Check stack: %d\n", tankPop(tank));
	return (0);
}



// Function used for the test
// Don't go further :)
