#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.h"

std::vector<std::string> splitString(std::string inputLine, char delimiter = ' ')
{
	std::vector<std::string> splitStrings;
	std::istringstream ss(inputLine);
	std::string currentLine;

	while (std::getline(ss, currentLine, delimiter))
	{
		splitStrings.push_back(currentLine);
	}

	return splitStrings;
}

std::vector<std::string> extractPassportKeys(std::string passportData)
{
	std::vector<std::string> passportKeyValues = splitString(passportData);
	std::vector<std::string> passportKeys;

	for (int i = 0; i < passportKeyValues.size(); i++)
	{
		std::vector<std::string> passportKeysSplit = splitString(passportKeyValues[i], ':');
		passportKeys.push_back(passportKeysSplit[0]);
	}

	return passportKeys;
}


bool isValidPassport(std::vector<std::string> passport)
{
	std::vector<std::string> requiredFields = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid" }; // cid is not necessary

	// we need seven fields

	if (passport.size() < requiredFields.size() - 1)
	{
		return false;
	}



	return true;
}


int main()
{
	// Get the data
	std::ifstream passportDataStream("test_input.txt");
	std::vector<std::string> passports;
	std::string currentPassportData;

	if (passportDataStream.is_open())
	{
		std::string currentLine;
		while (std::getline(passportDataStream, currentLine))
		{
			if (currentLine.empty())
			{
				passports.push_back(currentPassportData);
				currentPassportData.clear();
			}
			else
			{
				if (!currentPassportData.empty())
				{
					currentPassportData += " ";
				}
				currentPassportData += currentLine;
			}
		}

		if (!currentPassportData.empty())
		{
			passports.push_back(currentPassportData);
		}
	}
	else
	{
		std::cout << "Error: couldn't not get data from file" << std::endl;
	}

	int validPasswords = 0;
	for (auto passport : passports)
	{
		std::vector<std::string> passportKeys = extractPassportKeys(passport);

		if (isValidPassport(passportKeys))
		{
			validPasswords++;
		}
	}

	std::cout << validPasswords << std::endl;

	return 0;
}


