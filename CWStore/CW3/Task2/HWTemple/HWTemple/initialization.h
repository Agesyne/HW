#pragma once
#include <iostream>
#include <string>
using namespace std;

int initNumber(string text);

template<std::size_t SIZE>
void initArray(string text, array<int, SIZE>& initingArray);

void enterData(int *n, int *m, vector<vector<int> > &data);
