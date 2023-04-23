#include "input.h"
#include <iostream>
#include <algorithm>
#include <regex>

std::string FindAndReplace(const std::string& text, int substring_size)
{
    std::vector<std::string> substrings{};

    for (size_t i = 0; i < text.length(); i++)  // find all substrings longer than substring_size
    {
        for (size_t j = substring_size; j < text.length() - i + 1; j++)
        {
            std::string substring = text.substr(i, j);
            if (count(substrings.begin(), substrings.end(), substring) == 0)
                substrings.push_back(substring);
        }
    }

    std::string result = text;
    //replace strings

    return result;
}

std::string RestoreOriginalText(const std::string& text, int substring_size)
{
    std::vector<std::string> substrings{};

    for (size_t i = 0; i < text.length(); i++)  // find all substrings longer than substring_size
    {
        for (size_t j = substring_size; j < text.length() - i + 1; j++)
        {
            std::string substring = text.substr(i, j);
            if (count(substrings.begin(), substrings.end(), substring) == 0)
                substrings.push_back(substring);
        }
    }

    std::string result = text;

    return result;
}

void StartModify(std::vector<std::string>& strings, std::vector<std::string>& changedStrings, int substring_size)
{
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        std::string modifiedString = FindAndReplace(*it, substring_size);
        changedStrings.push_back(modifiedString);
    }
}

void StartRestore(std::vector<std::string>& strings, std::vector<std::string>& changedStrings, int substring_size)
{
    for (std::vector<std::string>::iterator it = changedStrings.begin(); it != changedStrings.end(); it++)
    {
        std::string restoredString = RestoreOriginalText(*it, substring_size);
        strings.push_back(restoredString);
    }
}

void SetSubstringSize(int& substring_size)
{
	std::cout << "Введите минимальную длину подстроки: " << std::endl;
	substring_size = GetPosInt();
}

void FillStrings(std::vector<std::string>& strings)
{
	std::cout << "Введите текст. Для окончания ввода введите quit." << std::endl;
	std::string input{};
	while (input != "quit")
	{
		GetLine(std::cin, input, WITH_DIGITS, MANUAL_INPUT);
		if (input != "quit")
			strings.push_back(input);
	}
}

void ShowRestored(std::vector<std::string>& strings)
{
	std::cout << "Восстановленный(исходный) текст: " << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
}

void ShowModified(std::vector<std::string>& changedStrings)
{
	std::cout << "Изменённый текст: " << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	for (std::vector<std::string>::iterator it = changedStrings.begin(); it != changedStrings.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
}

