#include "input.h"
#include <iostream>
#include <regex>


bool IsTextRestored(const std::string& text)
{
	std::regex pattern(".*((\\{)\\s*(\\d+),\\s*(\\d+)\\s*(\\})).*");
	bool isTextRestored = true;

	if (std::regex_search(text, pattern))
		isTextRestored = false;

	return isTextRestored;
}

void MakeListOfSubstrings(std::vector<std::string>& substrings, std::string& text) 
{
	std::string temp{};
	for (size_t pos = 0; pos < text.size(); pos++) 
	{
		for (size_t size = 0; size < text.size(); size++) 
		{
			temp = "";
			bool isSubstringContainsSpaces = false;
			bool isSubstringFound = false;
			for (size_t i = pos; i <= size; i++) 
			{
				temp += text[i];
				isSubstringFound = true;
			}
			if (isSubstringFound) 
			{
				for (size_t j = 0; j < temp.size(); j++) 
				{
					if (temp[j] == ' ' || temp[j] == '\n' || temp[j] == '\t') 
					{
						isSubstringContainsSpaces = true;
						break;
					}
				}
				if (!isSubstringContainsSpaces) 
				{
					bool isAlreadyExist = false;
					for (size_t j = 0; j < substrings.size(); j++)
						if (temp == substrings[j]) isAlreadyExist = true;

					if (!isAlreadyExist) substrings.push_back(temp);
				}
			}
		}
	}
}


void ReplaceText(std::string& text, size_t pos, size_t length, std::string input)
{
	std::string temp1{}, temp2{};

	for (size_t i = 0; i < pos; i++)
		temp1 += text[i];

	for (size_t i = pos + length; i < text.size(); i++)
		temp2 += text[i];

	text = temp1 + input + temp2;
}


void FormatText(std::string& text, std::vector<std::string>& substrings, size_t substring_size) 
{
	substring_size -= 1;
	for (int i = 0; i < substrings.size(); i++) 
	{
		int substringEnteringsCounter(0);
		size_t indexOfOrigSubstring(0);
		size_t lengthOfOrigSubstirng = substrings[i].size();
		size_t previousIndex = 0;
		if (substrings[i].size() > substring_size) 
		{
			for (size_t k = 0; k < text.size(); k++) 
			{
				bool stringsAreEqual = true;
				if (substrings[i][0] == text[k])
				{
					for (size_t j = 0; j < substrings[i].size(); j++) 
					{
						if (k + j > text.size()) 
						{
							stringsAreEqual = false;
							break;
						}
						if (substrings[i][j] != text[k + j]) stringsAreEqual = false;
					}
					if (stringsAreEqual) 
					{
						substringEnteringsCounter++;
						if (substringEnteringsCounter == 1) 
						{
							indexOfOrigSubstring = k;
							previousIndex = k;
						}
						else 
						{
							if (k - previousIndex < lengthOfOrigSubstirng)
								continue;

							std::string temp = '{' + std::to_string(indexOfOrigSubstring+1) + ", " + std::to_string(lengthOfOrigSubstirng) + '}';
							bool isReplacePossible = true;
							for (size_t l = 0; l < lengthOfOrigSubstirng; l++) 
								if (text[l + indexOfOrigSubstring] == '{' || text[l + indexOfOrigSubstring] == '}') isReplacePossible = false;

							if (isReplacePossible) 
							{
								ReplaceText(text, k, lengthOfOrigSubstirng, temp);
								previousIndex = k;
								k += temp.size() - lengthOfOrigSubstirng;
							}
						}
					}
				}
				else
					stringsAreEqual = false;
			}
		}
	}
}


void RestoreText(std::string& text) 
{
	std::regex pattern(".*((\\{)\\s*(\\d+),\\s*(\\d+)\\s*(\\})).*");
	std::smatch matches{};

	while (std::regex_search(text, matches, pattern))
	{
		std::string temp{};
		size_t index(0), length(0);
		index = static_cast<size_t>(std::stoi(matches[3].str())) - 1;

		if (index > text.size()) 
		{
			std::cout << "Специальная сигнатура " << matches[1] << " содержит невозможный индекс! Перезапустите программу." << std::endl;
			break;
		}

		length = static_cast<size_t>(std::stoi(matches[4].str()));

		if ((length > text.size()) || (index + length > text.size())) 
		{
			std::cout << "Специальная сигнатура " << matches[1] << " содержит недопустимую длину! Перезапустите программу." << std::endl;
			break;
		}

		for (size_t k = 0; k < length; k++) 
			temp += text[k + index];
		std::cout << matches.position(2) << ' ' << matches.position(5) << std::endl;

		index = static_cast<size_t>(matches.position(2));
		length = static_cast<size_t>(matches.position(5) - index + 1);
		ReplaceText(text, index, length, temp);
	}
}


void StartModify(std::string& text, std::string& modifiedText, size_t substring_size)
{
	std::vector<std::string> substrings{};
	MakeListOfSubstrings(substrings, text);
	FormatText(text, substrings, substring_size);
	modifiedText = text;
}


void StartRestore(std::string& text, std::string& restoredText)
{
	if (!IsTextRestored(text))
		RestoreText(text);
	restoredText = text;
}


void SetSubstringSize(size_t& substring_size)
{
	std::cout << "Введите минимальную длину подстроки: " << std::endl;
	substring_size = GetSubstringSize();
}


void InputText(std::string& text)
{
	std::cout << "Введите текст. Введите q чтобы завершить ввод." << std::endl;
	std::string input{};
	while (input != "q")
	{
		GetLine(std::cin, input, CW4_INPUT, MANUAL_INPUT);
		if (input != "q")
			text += (input + '\n');
	}
}


void ShowRestored(const std::string& restoredText)
{
	std::cout 
		<< "Восстановленный(исходный) текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< restoredText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}


void ShowModified(const std::string& modifiedText)
{
	std::cout 
		<< "Изменённый текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< modifiedText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}
