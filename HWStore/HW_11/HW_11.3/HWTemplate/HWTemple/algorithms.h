#pragma once
#include "Graph.h"
#include <string>

Graph *makeDyingTree(Graph &map, int vertexNumber);

void printAllEdges(Graph &map, const std::string &text = "");
