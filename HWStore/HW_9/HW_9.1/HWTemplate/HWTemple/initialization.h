#pragma once
#include <iostream>
#include <string>

int initNumber(std::string text);

template<std::size_t SIZE>
void initArray(std::string text, std::array<int, SIZE>& initingArray);
