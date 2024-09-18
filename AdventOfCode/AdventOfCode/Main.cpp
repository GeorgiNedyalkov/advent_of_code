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

int main()
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

}

