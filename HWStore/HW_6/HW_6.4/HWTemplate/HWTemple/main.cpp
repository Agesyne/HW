#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "readFile.h"
#include "List.h"
using namespace std;


int main()
{
	checkFromFile();
	List list;
	readDataToList("data.txt", list);

	list.mergeSort(true);
	list.printList();
	list.mergeSort(false);
	list.printList();

	list.deleteList();
	return 0;
}