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
//struct Node1
//{
//	Node1(std::string name)
//		: bag_name(name)
//	{
//	}
//
//	std::string bag_name;
//	std::vector<Node1*> m_bagsThatHoldMe;
//};
//
//void add_bag_children(Node1* node, std::vector<std::string>& lines)
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
//				Node1* bag = new Node1(currentBag);
//				node->m_bagsThatHoldMe.emplace_back(bag);
//			}
//		}
//	}
//}
//
//void part_1()
//{
//	std::vector<std::string> lines = getLines("test_input.txt");
//	std::set<std::string> nodeSet;
//
//	Node1* shinyGold = new Node1("shiny gold");
//
//	std::queue<Node1*> q;
//	q.emplace(shinyGold);
//
//	while (!q.empty())
//	{
//		Node1* curr = q.front();
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
//}
//
//bool is_integer(std::string str)
//{
//	bool is_integer = false;
//
//	try {
//		std::stoi(str);
//		is_integer = true;
//	}
//	catch (std::invalid_argument& e) {
//		is_integer = false;
//	}
//
//	return is_integer;
//}
//
//
//struct Node
//{
//	Node(std::string name)
//		: m_name(name) 
//		, m_count(1)
//		, m_num_of_bags_held(0)
//	{
//	}
//
//	std::string        m_name;
//	std::vector<Node*> m_children;
//	int				   m_count;
//	int				   m_num_of_bags_held;
//};
//
//
//void dfs(Node* root)
//{
//	if (root == nullptr) return;
//
//	for (auto& child_node : root->m_children)
//	{
//		dfs(child_node);
//
//		if (child_node->m_num_of_bags_held == 0)
//		{
//			root->m_num_of_bags_held += child_node->m_count;
//		}
//		else
//		{
//			root->m_num_of_bags_held += child_node->m_count * child_node->m_num_of_bags_held;
//		}
//	}
//}
//
//
//int main()
//{
//	std::vector<std::string> lines = getLines("test_input.txt");
//	std::queue<Node*> queue;
//
//	Node* shinyGold = new Node("shiny gold");
//	queue.emplace(shinyGold);
//
//	while (!queue.empty())
//	{
//		Node* curr = queue.front();
//		queue.pop();
//
//		for (auto& line : lines)
//		{
//			std::vector<std::string> split_line = splitString(line, ' ');
//			std::string current_bag = split_line[0] + " " + split_line[1];
//
//			if (current_bag == curr->m_name)
//			{
//				for (int i = 4; i < split_line.size(); i++)
//				{
//					if (is_integer(split_line[i]))
//					{
//						Node* bag_node = new Node(split_line[i + 1] + " " + split_line[i + 2]);
//						bag_node->m_count = std::stoi(split_line[i]);
//
//						curr->m_children.emplace_back(bag_node);
//						queue.emplace(bag_node);
//					}
//				}
//			}
//		}
//	}
//
//	dfs(shinyGold);
//
//	return 0;
//}
//
