#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.h"

// Day 3.
// count all the tree "#" you encounter using the moving pattern - right 3 down 1 - until you reach the end.


int checkSlope(int right, int down)
{
	int treeIndex = 0;
	int treeCount = 0;

	std::vector<std::string> inputLines = getInput("input.txt");
	for (int row = down; row < inputLines.size(); row += down)
	{
		treeIndex += right;

		// if we go out of the row start from the beginning
		if (treeIndex >= inputLines[row].size())
		{
			treeIndex -= inputLines[row].size();
		}

		if (inputLines[row][treeIndex] == '#')
		{
			treeCount++;
		}
	}
	return treeCount;
}

int main()
{
	std::vector<std::vector<int>>  slopes = { {1,1}, {3,1 }, {5,1}, {7, 1}, {1, 2} };
	long long int product = 1;

	for (auto slope : slopes)
	{
		int treeCount = checkSlope(slope[0], slope[1]);
		product *= treeCount;
	}

	std::cout << product << std::endl;

	return 0;
}