
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

// Advent of code 2020
// Find 50 coins

std::vector<std::string> getInputLines()
{
	std::vector<std::string> lines;
	std::string line;
	std::ifstream inputFile("input.txt");
	std::vector<int> expensesReport;

	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			lines.push_back(line);
		}

		inputFile.close();
	}
	else std::cout << "Error: could not open file input.txt" << '\n';

	return lines;
}


std::vector<std::string> splitLine(std::string line, char delimiter)
{
	std::istringstream ss(line);
	std::string currentLine;
	std::vector<std::string> strVector;

	while (std::getline(ss, currentLine, delimiter))
	{
		strVector.push_back(currentLine);
	}

	return strVector;
}

int solutionTwo()
{
	std::vector<std::string> lines = getInputLines();

	int validPasswordCount = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> passwordData = splitLine(lines[i], ' ');
		std::vector<std::string> range        = splitLine(passwordData[0], '-');

		int positionOne      = std::stoi(range[0]);
		int positionTwo      = std::stoi(range[1]);
		char character       = passwordData[1][0];
		std::string password = passwordData[2];

		if (password[positionOne - 1] == character && password[positionTwo - 1] != character ||
			password[positionOne - 1] != character && password[positionTwo - 1] == character)
		{
			validPasswordCount++;
		}
	}

	std::cout << validPasswordCount << std::endl;

	return 0;
}

int solutionOne()
{
	std::vector<std::string> lines = getInputLines();

	int validPasswordCount = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> passwordData = splitLine(lines[i], ' ');
		std::vector<std::string> range        = splitLine(passwordData[0], '-');

		int lowCharCount     = std::stoi(range[0]);
		int highCharCount    = std::stoi(range[1]);
		char charToCount     = passwordData[1][0];
		std::string password = passwordData[2];

		int countChar = 0;
		for (int i = 0; i < password.size(); i++)
		{
			if (password[i] == charToCount)
			{
				countChar++;
			}
		}

		if (countChar >= lowCharCount && countChar <= highCharCount)
		{
			validPasswordCount++;
		}
	}

	std::cout << validPasswordCount << std::endl;

	return 0;
}
