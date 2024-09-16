//#include <map>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <math.h>
//#include <unordered_set>
//#include "utils.h"
//
//static std::vector<std::string> splitString(std::string str, char delimiter = ' ')
//{
//	std::vector<std::string> splitVector;
//	std::stringstream ss(str);
//
//	while (std::getline(ss, str, delimiter))
//	{
//		splitVector.push_back(str);
//	}
//
//	return splitVector;
//}
//
//static std::vector<std::string> getLines(std::string filename)
//{
//	std::string line;
//	std::ifstream inputStream(filename);
//	std::vector<std::string> lines;
//	if (inputStream.is_open())
//	{
//		while (std::getline(inputStream, line))
//		{
//			lines.push_back(line);
//		}
//	}
//	else 
//	{
//		std::cout << "Error: couldn't open file" << std::endl;
//	}
//
//	return lines;
//}
//
//struct Node
//{
//	Node(std::string name)
//		: bag_name(name)
//	{
//	}
//
//	std::string bag_name;
//	std::vector<Node*> m_bagsThatHoldMe;
//};
//
//void add_bag_children(Node* node, std::vector<std::string>& lines)
//{
//	for (std::string& line : lines)
//	{
//		if (line.find(node->bag_name) != std::string::npos)
//		{
//			std::vector<std::string> splitLine = splitString(line);
//			std::string currentBag = splitLine[0] + " " + splitLine[1];
//
//			if (currentBag != node->bag_name)
//			{
//				Node* bag = new Node(currentBag);
//				node->m_bagsThatHoldMe.emplace_back(bag);
//			}
//		}
//	}
//}
//
//int main()
//{
//	std::vector<std::string> lines = getLines("input.txt");
//	std::set<std::string> nodeSet;
//
//	Node* shinyGold = new Node("shiny gold");
//
//	std::queue<Node*> q;
//	q.emplace(shinyGold);
//
//	while (!q.empty())
//	{
//		Node* curr = q.front();
//		q.pop();
//
//		add_bag_children(curr, lines);
//
//		for (auto& node : curr->m_bagsThatHoldMe)
//		{
//			q.emplace(node);
//			nodeSet.emplace(node->bag_name);
//		}
//	}
//
//	std::cout << nodeSet.size() << std::endl;
//
//	return 0;
//}
//
//
