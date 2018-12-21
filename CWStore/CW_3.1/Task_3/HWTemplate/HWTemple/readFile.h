#pragma once
#include <string>
#include <vector>
#include "GraphField.h"
#include "Graph.h"

void readFile(std::string text, std::vector<std::string> &data);

void readResultFile(std::string text, std::vector<std::vector<int>> &data, const int linesNumber);

void readGraphFromFile(std::string text, Graph &map);
