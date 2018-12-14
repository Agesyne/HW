#pragma once
#include <iostream>
#include <vector>
#include <string>

int initNumber(std::string text);

template<std::size_t SIZE>
void initArray(std::string text, std::array<int, SIZE>& initingArray);


void enterData(int *n, int *m, std::vector<std::vector<int> > &data);