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

namespace Day1_2021 {

	static int part_1()
	{
		std::string line;
		std::ifstream ss("input.txt");

		if (!ss.is_open())
		{
			std::cout << "Error: couldn't open file" << std::endl;
		}

		int posX = 0;
		int posY = 0;

		while (std::getline(ss, line))
		{
			char command = line.front();
			int speed = line.back() - '0'; // convert the char digit to a integer

			switch (command)
			{
			case 'f':
				posX += speed;
				break;
			case 'b':
				posX -= speed;
				break;
			case 'u':
				posY -= speed;
				break;
			case 'd':
				posY += speed;
				break;
			}
		}

		return posX * posY;
	}

	static int part_2()
	{
		std::string line;
		std::ifstream ss("input.txt");

		if (!ss.is_open())
		{
			std::cout << "Error: couldn't open file" << std::endl;
		}

		int posX = 0;
		int posY = 0;
		int aim = 0;

		while (std::getline(ss, line))
		{
			char command = line.front();
			int speed = line.back() - '0'; // convert the char digit to a integer

			switch (command)
			{
			case 'f':
				posX += speed;
				posY += aim * speed;
				break;
			case 'b':
				posX -= speed;
				posY -= aim * speed;
				break;
			case 'u':
				aim -= speed;
				break;
			case 'd':
				aim += speed;
				break;
			}
		}

		return posX * posY;
	}

}

int main()
{
	std::cout << Day1_2021::part_1() << std::endl;
	std::cout << Day1_2021::part_2() << std::endl;
}


