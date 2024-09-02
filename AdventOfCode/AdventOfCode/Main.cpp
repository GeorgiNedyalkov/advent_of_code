#include <map>
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

static std::vector<std::string> splitString(std::string str, char delimiter)
{
	std::vector<std::string> splitVector;
	std::stringstream ss(str);

	while (std::getline(ss, str, delimiter))
	{
		splitVector.push_back(str);
	}

	return splitVector;
}

static std::vector<std::string> getLines(std::string filename)
{
	std::string line;
	std::ifstream inputStream("input.txt");
	std::vector<std::string> lines;
	if (inputStream.is_open())
	{
		while (std::getline(inputStream, line))
		{
			lines.push_back(line);
		}
	}
	else 
	{
		std::cout << "Error: couldn't open file" << std::endl;
	}

	return lines;
}


static bool foundBag(std::string line, std::string bagToFind)
{
	std::size_t found = line.find(bagToFind);
	if (found != std::string::npos)
	{
		std::vector<std::string> splitLine = splitString(line, ' ');
		std::string currentBag = splitLine[0] + " " + splitLine[1];

		if (currentBag != bagToFind)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::vector<std::string> bagsThatHoldShinyGoldBag;
	std::string bagToFind = "shiny gold bag";
	int countBags = 0;

	std::vector<std::string> lines = getLines("input.txt");

	for (auto l : lines)
	{

		if (foundBag(l, bagToFind))
		{
			std::vector<std::string> splitLine = splitString(l, ' ');
			std::string currentBag = splitLine[0] + " " + splitLine[1];
			bagsThatHoldShinyGoldBag.push_back(currentBag);
			std::cout << l << std::endl;
			countBags++;
		}
	}

	int count = 0;
	for (auto l : lines)
	{
		count++;
		std::cout << count << " " << l << std::endl;

		for (auto bag : bagsThatHoldShinyGoldBag)
		{
			//if (foundBag(l, bag))
			//{
			//	std::vector<std::string> splitLine = splitString(l, ' ');
			//	std::string currentBag = splitLine[0] + " " + splitLine[1];
			//	bagsThatHoldShinyGoldBag.push_back(bag);
			//	countBags++;
			//}
		}
	}

	return 0;
}


