#include "pch.h"
#include <iostream>

int initNumber(char text[])
{
	int number = 0;
	printf("%s", text);
	scanf("%d", &number);
	return number;
}