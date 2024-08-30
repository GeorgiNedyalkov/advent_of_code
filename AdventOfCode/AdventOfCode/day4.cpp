//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include "utils.h"
//
//std::vector<std::string> splitString(std::string inputLine, char delimiter = ' ')
//{
//	std::vector<std::string> splitStrings;
//	std::istringstream ss(inputLine);
//	std::string currentLine;
//
//	while (std::getline(ss, currentLine, delimiter))
//	{
//		splitStrings.push_back(currentLine);
//	}
//
//	return splitStrings;
//}
//
//std::unordered_map<std::string, std::string> extractPassportKeys(std::string passportData)
//{
//	std::vector<std::string> passportKeyValues = splitString(passportData);
//	std::unordered_map<std::string, std::string> passportsMap;
//
//	for (int i = 0; i < passportKeyValues.size(); i++)
//	{
//		std::vector<std::string> passportValues = splitString(passportKeyValues[i], ':');
//
//		passportsMap[passportValues[0]] = passportValues[1];
//	}
//
//	return passportsMap;
//}
//
//
//bool isValidPassport(std::unordered_map<std::string, std::string> passport)
//{
//	std::vector<std::string> requiredFields = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid" };
//	std::vector<std::string> validEyeColors = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
//	std::unordered_map<std::string, bool> validFieldsMap;
//
//	for (auto field : requiredFields)
//	{
//		validFieldsMap[field] = false;
//	}
//
//	validFieldsMap["cid"] = true;
//
//	// if there is a missing field othern than cid then return false
//	for (auto keyValue : passport)
//	{
//		std::string key = keyValue.first;
//		if (key == "cid")
//		{
//			continue;
//		}
//
//		auto iter = std::find(requiredFields.begin(), requiredFields.end(), key);
//		if (iter == requiredFields.end())
//		{
//			return false;
//		}
//	}
//
//	for (auto field : passport)
//	{
//		std::string key = field.first;
//		std::string value = field.second;
//
//		if (key == "byr")
//		{
//			int birthYear = std::stoi(value);
//			if (birthYear >= 1920 && birthYear <= 2002)
//			{
//				validFieldsMap[key] = true;
//			}
//		}
//
//		if (key == "iyr")
//		{
//			int issueYear = std::stoi(value);
//			if (issueYear >= 2010 && issueYear <= 2020)
//			{
//				validFieldsMap[key] = true;
//			}
//		}
//
//		if (key == "eyr")
//		{
//			int expirationYear = std::stoi(value);
//			if (expirationYear >= 2020 && expirationYear <= 2030)
//			{
//				validFieldsMap[key] = true;
//			}
//		}
//
//		if (key == "hgt")
//		{
//			std::string heightMeasurement = value.substr(value.size() - 2);
//
//			if (heightMeasurement != "cm" && heightMeasurement != "in")
//			{
//				validFieldsMap[key] = false;
//				continue;
//			}
//
//			value.erase(value.end() - 2, value.end());
//
//			int height = std::stoi(value);
//			if (heightMeasurement == "cm")
//			{
//				if (height >= 150 && height <= 193)
//				{
//					validFieldsMap[key] = true;
//				}
//			}
//			else if (heightMeasurement == "in")
//			{
//				if (height >= 59 && height <= 76)
//				{
//					validFieldsMap[key] = true;
//				}
//			}
//		}
//
//		if (key == "hcl")
//		{
//			if (value[0] != '#' || value.size() != 7)
//			{
//				validFieldsMap[key] = false;
//				continue;
//			}
//
//			for (int i = 1; i < value.size(); i++)
//			{
//				int asciiNum = int(value[i]);
//
//				if (asciiNum >= 48 && asciiNum <= 57)
//				{
//					validFieldsMap[key] = true;
//				}
//				else if (asciiNum >= 97 && asciiNum <= 102)
//				{
//					validFieldsMap[key] = true;
//				}
//			}
//		}
//
//		if (key == "ecl")
//		{
//			auto iter = std::find(validEyeColors.begin(), validEyeColors.end(), value);
//
//			if (iter != validEyeColors.end())
//			{
//				validFieldsMap[key] = true;
//			}
//		}
//
//		if (key == "pid")
//		{
//			if (value.size() == 9)
//			{
//				validFieldsMap[key] = true;
//			}
//		}
//
//		std::cout << "Key " << key << " Value " << value << " Valid " << validFieldsMap[key] << std::endl;
//	}
//
//	bool isValid = true;
//	for (auto field : validFieldsMap)
//	{
//		if (field.second == false)
//		{
//			isValid = false;
//		}
//	}
//
//	std::cout << std::endl;
//	return isValid;
//}
//
//int getValidPassords()
//{
//	std::ifstream passportDataStream("input.txt");
//	std::vector<std::string> passports;
//	std::string currentPassportData;
//
//	if (passportDataStream.is_open())
//	{
//		std::string currentLine;
//		while (std::getline(passportDataStream, currentLine))
//		{
//			if (currentLine.empty())
//			{
//				passports.push_back(currentPassportData);
//				currentPassportData.clear();
//			}
//			else
//			{
//				if (!currentPassportData.empty())
//				{
//					currentPassportData += " ";
//				}
//				currentPassportData += currentLine;
//			}
//		}
//
//		if (!currentPassportData.empty())
//		{
//			passports.push_back(currentPassportData);
//		}
//	}
//	else
//	{
//		std::cout << "Error: couldn't not get data from file" << std::endl;
//	}
//
//	int validPasswords = 0;
//	for (auto passport : passports)
//	{
//		std::unordered_map<std::string, std::string> passportMap = extractPassportKeys(passport);
//
//		if (isValidPassport(passportMap))
//		{
//			validPasswords++;
//		}
//	}
//
//	std::cout << validPasswords << std::endl;
//
//	return validPasswords;
//
//}
