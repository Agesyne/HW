#include "pch.h"
#include "check.h"
#include "initialization.h"
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	checkFunction();

	return 0;
}
