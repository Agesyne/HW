#pragma once
#include <iostream>
#include <vector>


void makeRows(std::vector<std::vector<int> > &data, std::vector<std::pair<int, int> > &rows, const int n, const int m);

void makeCells(std::vector<std::vector<int> > &data, std::vector<std::pair<int, int> > &cells, const int n, const int m);
