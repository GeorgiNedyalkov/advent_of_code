#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Advent of code 2020
// Find 50 coins

int findEntriesProduct(std::vector<int> expensesReport)
{
	for (int i = 0; i < expensesReport.size() - 1; i++)
	{
		for (int j = i + 1; j < expensesReport.size(); j++)
		{
			if (expensesReport[i] + expensesReport[j])
			{
				std::cout << expensesReport[i] * expensesReport[j];
				return expensesReport[i] * expensesReport[j];
			}
		}
	}

	return 0;
}

int findEntriesProductWithThreeNumbers(std::vector<int> entries)
{
	int productEntries = 0;

	for (int i = 0; i < entries.size(); i++)
	{
		for (int j = i + 1; j < entries.size(); j++)
		{
			// if the sum of the first two numbers is bigger than 2020 continue
			if (entries[i] + entries[j] > 2020)
			{
				continue;
			}

			for (int k = 0; k < entries.size(); k++)
			{
				int sum = entries[i] + entries[j] + entries[k];

				if (sum == 2020)
				{
					std::cout << entries[i] * entries[j] * entries[k] << '\n';
					return entries[i] * entries[j] * entries[k];
				}
			}
		}
	}

	return productEntries;
}

int main()
{
	std::string line;
	std::ifstream inputFile("input.txt");
	std::vector<int> expensesReport;

	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			expensesReport.push_back(std::stoi(line));
		}

		inputFile.close();
	}
	else std::cout << "Error: could not open file input.txt" << '\n';

	findEntriesProductWithThreeNumbers(expensesReport);
	//findEntriesProduct(expensesReport);

	return 0;
}