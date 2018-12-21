#pragma once
#include <vector>
#include "Graph.h"

void checkAllVertex(Graph &map, std::vector<std::vector<bool>> &isReacheable);

bool isReacheableFromEverywhere(const int vertexNumber, const std::vector<std::vector<bool>> &isReacheable);
