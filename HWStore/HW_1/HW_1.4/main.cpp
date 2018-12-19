#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

const int debugCounter = 1;
const int totalNumberOfHappyTicket = 55252;


int countHappyTickets()
{
	int counter = 0;

	int *arrayOfSums = new int[28];
	for (int j = 0; j < 28; j++)
	{
		arrayOfSums[j] = 0;
	}
	for (int j = 0; j < 1000; j++)
	{
		int number = j;
		int sum = 0;
		while (number > 0)
		{
			sum += number % 10;
			number /= 10;
		}
		arrayOfSums[sum]++;
	}

	for (int j = 0; j < 28; j++)
	{
		counter += arrayOfSums[j] * arrayOfSums[j];
	}

	delete[] arrayOfSums;

	return counter;
}


int initNumberOfTicket()
{
	int numberOfTickets = 0;
	printf("Enter number of tickets to check from \"000000\" (usually 1'000'000): ");
	scanf("%d", &numberOfTickets);
	return numberOfTickets;
}

void checkFunction()
{
	int ticket = 0;

	for (int i = 0; i < debugCounter; i++)
	{
		const int counter = countHappyTickets();

		//printf("Total: %d", counter);
		if (counter != totalNumberOfHappyTicket)
		{
			printf("Some mistakes here\n");
			exit(1);
		}
	}
}

void showResult(int number)
{
	printf("Number of happy tikets among first %d ones: %d", 1000000, number);
}

int main()
{
	checkFunction();

	const int counter = countHappyTickets();

	showResult(counter);

	return 0;
}