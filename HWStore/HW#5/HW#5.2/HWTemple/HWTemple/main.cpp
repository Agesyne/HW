#include "pch.h"
#include <iostream>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	checkFromFile();

	const int numberOfDeadmen = initNumber("Введите число самоубийц: ");
	const int period = initNumber("Введите период убийства: ");

	cyclicBiconnectedList listOfDeadmen;
	initListOfDeadmen(&listOfDeadmen, numberOfDeadmen);

	killAllMenExceptN(&listOfDeadmen, period, 1);
	printf("Остался смертник на %d-й позиции\n", deleteElementFromList(&listOfDeadmen, 1));

	deleteList(&listOfDeadmen);

	return 0;
}
