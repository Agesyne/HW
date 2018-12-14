#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
using namespace std;


int main()
{
	//checkFromFile();
	vector<vector<int> > table;
	int n = 0;
	int m = 0;

	enterData(&n, &m, table);

	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		bool isTheNode = true;
		vector<int> nodes{};
		nodes.resize(n);
		dfs(i, nodes, table);
		for (int i = 0; i < nodes.size(); ++i)
		{
			if (nodes[i] == 0)
			{
				isTheNode = false;
				break;
			}
		}

		if (isTheNode)
		{
			counter++;
			cout << "Node number: " << i << endl;
		}
	}

	if (counter == 0)
	{
		cout << "No nodes" << endl;
	}

	return 0;
}