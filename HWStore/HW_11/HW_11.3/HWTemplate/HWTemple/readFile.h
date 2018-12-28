#pragma once
#include <string>
#include <vector>
#include "Graph.h"

void readFile(std::string text, std::vector<std::string> &data);

void readFileByLines(std::string text, std::vector<std::string> &data);

void readGraphFromFile(std:: string text, Graph &map);
