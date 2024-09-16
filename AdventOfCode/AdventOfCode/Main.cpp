#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
#include "utils.h"

// Big O(n)
int day_1_part_one()
{
	std::vector<std::string> lines = Utils::getLines("input.txt");

	int previous_depth = std::stoi(lines[0]);
	int depth_increase_count = 0;

	for (int i = 1; i < lines.size(); i++)
	{
		int current_depth = std::stoi(lines[i]);
		if (previous_depth < current_depth)
		{
			depth_increase_count++;
		}

		previous_depth = current_depth;
	}

	return depth_increase_count;
}

// Sliding window
int day_2_part_one()
{
	std::vector<std::string> lines = Utils::getLines("input.txt");

	// calculate the sum of the first three items
	int previous_sum = 0;
	int increases_count = 0;
	for (int i = 0; i < lines.size() - 3; i++)
	{
		int current_sum = 0;
		for (int j = i; j < i + 3; j++)
		{
			current_sum += std::stoi(lines[j]);
		}

		if (previous_sum < current_sum)
		{
			increases_count++;
		}

		previous_sum = current_sum;
	}

	std::cout << increases_count << std::endl;

	return 0;
}

int main()
{
	day_2_part_one();
}

