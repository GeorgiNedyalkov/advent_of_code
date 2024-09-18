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

int binary_to_decimal(std::string binary_number)
{
	int decimal = 0;

	int power_of_count = 0;

	int length = binary_number.size();

	for (int i = 0; i < length; i++)
	{
		if (binary_number[length - 1 - i] == '1')
		{
			decimal += std::pow(2, i);
		}
	}

	return decimal;
}


int part_1()
{
	std::vector<std::string> lines = Utils::getLines("input.txt");
	int count_0 = 0;
	int count_1 = 0;

	int length = lines[0].size();

	std::string gamma_rate;
	std::string epilson_rate;

	for (int col = 0; col < length; col++)
	{
		// count occurences
		for (int row = 0; row < lines.size(); row++)
		{
			//std::cout << lines[row][col];
			char current_char = lines[row][col];

			if (current_char == '0')
			{
				count_0++;
			}
			else
			{
				count_1++;
			}
		}
		//std::cout << std::endl;
		//std::cout << "O: " << count_0 << " 1: " << count_1 << std::endl;

		// check which bit occurred more times
		if (count_0 > count_1)
		{
			gamma_rate   += '0';
			epilson_rate += '1';
		}
		else
		{
			gamma_rate   += '1';
			epilson_rate += '0';
		}

		// reset count
		count_0 = 0;
		count_1 = 0;
	}

	std::cout << gamma_rate << std::endl;
	std::cout << epilson_rate << std::endl;
	std::cout << std::endl;

	int i_gamma_rate   = binary_to_decimal(gamma_rate);
	int i_epilson_rate = binary_to_decimal(epilson_rate);

	std::cout << i_gamma_rate * i_epilson_rate << std::endl;

	return i_gamma_rate * i_epilson_rate;
}













std::vector<std::string> find_oxygen_rating(std::vector<std::string>& lines, int position)
{
	std::vector<std::string> zero_bit_numbers;
	std::vector<std::string> one_bit_numbers;

	for (int i = 0; i < lines.size(); i++)
	{
		char current_bit = lines[i][position];

		if (current_bit == '0')
		{
			zero_bit_numbers.emplace_back(lines[i]);
		}
		else if (current_bit == '1')
		{
			one_bit_numbers.emplace_back(lines[i]);
		}
	}

	if (zero_bit_numbers.size() > one_bit_numbers.size())
	{
		lines = zero_bit_numbers;
	}
	else if (zero_bit_numbers.size() <= one_bit_numbers.size())
	{
		lines = one_bit_numbers;
	}

	return lines;
}

std::vector<std::string> find_c02_rating(std::vector<std::string>& lines, int position)
{
	std::vector<std::string> zero_bit_numbers;
	std::vector<std::string> one_bit_numbers;

	for (int i = 0; i < lines.size(); i++)
	{
		char current_bit = lines[i][position];

		if (current_bit == '0')
		{
			zero_bit_numbers.emplace_back(lines[i]);
		}
		else if (current_bit == '1')
		{
			one_bit_numbers.emplace_back(lines[i]);
		}
	}

	if (zero_bit_numbers.size() > one_bit_numbers.size())
	{
		lines = one_bit_numbers;
	}
	else if (zero_bit_numbers.size() <= one_bit_numbers.size())
	{
		lines = zero_bit_numbers;
	}

	return lines;
}

int main()
{	
	std::vector<std::string> lines = Utils::getLines("input.txt");
	std::vector<std::string> oxygen_generator_rating(lines);
	std::vector<std::string> co2_scrubber_rating(lines);

	size_t number_length = lines[0].size();

	int position = 0;
	while (oxygen_generator_rating.size() > 1)
	{
		find_oxygen_rating(oxygen_generator_rating, position);
		position++;
	}

	position = 0;
	while (co2_scrubber_rating.size() > 1)
	{
		find_c02_rating(co2_scrubber_rating, position);
		position++;
	}

	int oxygen_rating = binary_to_decimal(oxygen_generator_rating[0]);
	int co2_rating = binary_to_decimal(co2_scrubber_rating[0]);

	std::cout << oxygen_rating * co2_rating << std::endl;

	return 0;
}

