//
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
//
//std::vector<std::string> getGroupAnswers(std::string inputFile)
//{
//	std::ifstream ss(inputFile);
//	std::string answer;
//	std::string group;
//
//	std::vector<std::string> groups;
//	int peopleInGroup = 0;
//
//	std::vector<std::string> peopleInGroupAndAnswer;
//
//
//	if (ss.is_open())
//	{
//		while (std::getline(ss, answer))
//		{
//			if (answer.size() == 0)
//			{
//				std::string str = std::to_string(peopleInGroup) + ":" + group;
//				peopleInGroupAndAnswer.emplace_back(str);
//
//				group.clear();
//				peopleInGroup = 0;
//			}
//			else
//			{
//				group += answer;
//				peopleInGroup++;
//			}
//		}
//
//		std::string str = std::to_string(peopleInGroup) + ":" + group;
//		peopleInGroupAndAnswer.emplace_back(str);
//	}
//	else
//	{
//		std::cout << "Error" << std::endl;
//	}
//
//	return peopleInGroupAndAnswer;
//}
//
//std::map<char, int> countOccurences(std::string str)
//{
//	std::map<char, int> charOccurencesMap;
//
//	for (char c : str)
//	{
//		auto iter = str.find(c);
//		if (iter != std::string::npos)
//		{
//			charOccurencesMap[c]++;
//		}
//		else
//		{
//			charOccurencesMap[c] = 1;
//		}
//	}
//
//	for (auto occ : charOccurencesMap)
//	{
//		std::cout << occ.first << " " << occ.second << std::endl;
//	}
//	std::cout << std::endl;
//
//	return charOccurencesMap;
//}
//
//
//int countAnswers(std::vector<std::string> groupData)
//{
//	int questionCount = 0;
//
//	std::map<char, int> answeredCountMap;
//
//	for (int i = 0; i < groupData.size(); i++)
//	{
//		std::vector<std::string> splitData = splitString(groupData[i], ':');
//
//		int peoplePerGroup = std::stoi(splitData[0]);
//		std::string answers = splitData[1];
//
//
//		std::map<char, int> answerOccurences = countOccurences(answers);
//		for (auto charOccurence: answerOccurences)
//		{
//			if (charOccurence.second == peoplePerGroup)
//			{
//				questionCount++;
//			}
//		}
//	}
//
//	std::cout << "Question count " << questionCount << std::endl;
//
//	return questionCount;
//}
//
