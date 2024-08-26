#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> getInput(std::string filename)
{
	std::ifstream inputFileStream(filename);
	std::string currentLine;
	std::vector<std::string> outputArray;
	std::string outputStr;

	if (inputFileStream.is_open())
	{
		while (std::getline(inputFileStream, currentLine))
		{
			//std::cout << currentLine << std::endl;
			outputArray.push_back(currentLine);

			outputStr += currentLine;
		}

		inputFileStream.close();
	}
	else
	{
		std::cout << "Error: couldn't open file " << filename << '\n';
	}

	return outputArray;
}

std::string getInputString(std::string filename)
{
	std::ifstream inputFileStream(filename);
	std::string currentLine;
	std::string outputStr;

	if (inputFileStream.is_open())
	{
		while (std::getline(inputFileStream, currentLine))
		{
			outputStr += currentLine;
		}

		inputFileStream.close();
	}
	else
	{
		std::cout << "Error: couldn't open file " << filename << '\n';
	}

	return outputStr;
}

void printArrayElements(std::string arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << '\n';
	}
}


void printArrayElements(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << '\n';
	}
}


