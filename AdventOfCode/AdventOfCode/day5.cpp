#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

std::vector<std::string> getBoardingPasses(std::string filename)
{
	std::vector<std::string> boardingPasses;
	std::string boardingPass;
	std::ifstream ss(filename);

	if (ss.is_open())
	{
		while (getline(ss, boardingPass))
		{
			boardingPasses.push_back(boardingPass);
		}
	}
	else
	{
		std::cout << "Error: couldn't open file" << std::endl;
	}

	return boardingPasses;
}

std::vector<int> generateRowsCols(int num)
{
	std::vector<int> planeRowsCols(num, 0);

	for (int i = 0; i < num; i++)
	{
		planeRowsCols[i] = i;
	}

	return planeRowsCols;
}


int binarySearch(std::string letters, std::vector<int> planeRows)
{
	int seat = 0;
	int low = 0;
	int high = int(planeRows.size() - 1);

	//std::cout << letters << std::endl;

	for (int i = 0; i < letters.size(); i++)
	{
		int middle = (low + (high - low) / 2);

		//std::cout << "Low: " << low << " High: " << high << std::endl;
		//std::cout << "Middle: " << middle << std::endl;

		if (letters[i] == 'F' || letters[i] == 'L')
		{
			high = middle;
		}
		else if (letters[i] == 'B' || letters[i] == 'R')
		{
			low = middle + 1;
		}

		seat = middle;
	}
	

	// Hacky shit
	if (letters[letters.size() - 1] == 'R' || letters[letters.size() - 1] == 'B')
	{
		seat++;
	}

	return seat;
}

int getSeatID(int row, int col)
{
	//std::cout << row << " * " << 8 << " + " << col << " = " << row * 8 + col << std::endl;
	return row * 8 + col;
}

int findSeat(std::vector<int>& boardingPassIDs)
{
	std::sort(boardingPassIDs.begin(), boardingPassIDs.end());

	int seat = 0;
	for (int i = 1; i < boardingPassIDs.size(); i++)
	{
		if (boardingPassIDs[i] - boardingPassIDs[i - 1] != 1)
		{
			seat = boardingPassIDs[i] - 1;
		}
	}

	return seat;
}

int findMySeat(std::string inputFile)
{
	std::vector<std::string> boardingPasses = getBoardingPasses(inputFile);
	std::vector<int> planeRows = generateRowsCols(128);
	std::vector<int> planeCols = generateRowsCols(8);
	std::vector<int> boardingPassIDs;

	for (auto boardingPass : boardingPasses)
	{
		std::string rowCharacters = boardingPass.substr(0, 7);
		int rowSeat = binarySearch(rowCharacters, planeRows);
		std::string colCharacters = boardingPass.substr(boardingPass.size() - 3, 3);
		int colSeat = binarySearch(colCharacters, planeCols);
		int seatId = getSeatID(rowSeat, colSeat);

		boardingPassIDs.push_back(seatId);
	}

	int mySeat = findSeat(boardingPassIDs);
	std::cout << mySeat << std::endl;
	return mySeat;
}
