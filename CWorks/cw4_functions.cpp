#include "input.h"
#include <iostream>
#include <algorithm>
#include <regex>


std::string RestoreOriginalText(const std::string& text, int substring_size)
{
    std::vector<std::string> substrings{};

    for (size_t i = 0; i < text.length(); i++)  // find all substrings longer than substring size
    {
        for (size_t j = substring_size; j < text.length() - i + 1; j++)
        {
            std::string substring = text.substr(i, j);
            if (count(substrings.begin(), substrings.end(), substring) == 0)
                substrings.push_back(substring);
        }
    }

    std::string result = text;
    //restore strings

    return result;
}

void StartModify(std::vector<std::string>& strings, std::vector<std::string>& changedStrings, std::vector<std::string>& substrings, int substring_size, int type_strings)
{
	std::string text{};
	if (!strings.empty())
	{
		for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
			text += *it;
		MakeListOfSubstrings(substrings, text);
		FormatText(text, substrings, substring_size);
	}
	
	
}

void StartRestore(std::vector<std::string>& strings, std::vector<std::string>& changedStrings, int substring_size)
{
	std::string text{};
	if (!changedStrings.empty())
	{
		for (std::vector<std::string>::iterator it = changedStrings.begin(); it != changedStrings.end(); it++)
			text += *it;
		RestoreText(text);
	}
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



void MakeListOfSubstrings(std::vector <std::string>& substrings, std::string& text) {
	std::string temp = "";
	for (size_t pos = 0; pos < text.size(); pos++) {
		for (size_t size = 0; size < text.size(); size++) {
			temp = "";
			bool isSubstringContainsSpaces = false;
			bool isSubstringFound = false;
			for (size_t i = pos; i <= size; i++) {
				temp += text[i];
				isSubstringFound = true;
			}
			if (isSubstringFound) {
				for (size_t j = 0; j < temp.size(); j++) {
					if (temp[j] == ' ' or temp[j] == '\n' or temp[j] == '\t') {
						isSubstringContainsSpaces = true;
						break;
					}
				}
				if (!isSubstringContainsSpaces) {
					bool isAlreadyExist = false;
					for (size_t j = 0; j < substrings.size(); j++) {
						if (temp == substrings[j]) isAlreadyExist = true;
					}
					if (!isAlreadyExist) substrings.push_back(temp);
				}
			}
		}
	}
}

void FindAllSubstrings(std::vector <int>& indexes, std::string substring, std::string& text, size_t sizeOfSubstring) {
	if (substring.size() > sizeOfSubstring) {
		for (int i = 0; i < text.size(); i++) {
			bool stringsAreEqual = true;
			if (substring[0] == text[i]) {
				for (int j = 0; j < substring.size(); j++) {
					if (i + j > text.size()) {
						stringsAreEqual = false;
						break;
					}
					if (substring[j] != text[i + j]) stringsAreEqual = false;
				}
				if (stringsAreEqual) {
					indexes.push_back(i);
				}
			}
			else {
				stringsAreEqual = false;
			}
		}
	}
	for (int i = 1; i < indexes.size();) {
		if (indexes[i - 1] + substring.size() - 1 == indexes[i]) {
			indexes.erase(indexes.begin() + i);
		}
		else i++;
	}
}

void ReplaceText(std::string& text, int pos, int length, std::string input) {

	std::string temp1;
	std::string temp2;

	for (size_t i = 0; i < pos; i++) {
		temp1 += text[i];
	}
	for (size_t i = pos + length; i < text.size(); i++) {
		temp2 += text[i];
	}

	text = temp1 + input + temp2;
}

void FormatText(std::string& text, std::vector <std::string>& substrings, int reqSubstringLength) {

	std::string copyOfText = text;

	for (int i = 0; i < substrings.size(); i++) 
	{
		int substringEnteringsCounter = 0;
		int indexOfOrigSubstring = 0;
		int lengthOfOrigSubstirng = static_cast <int> (substrings[i].size());
		int previousIndex = 0;
		if (substrings[i].size() > reqSubstringLength) 
		{
			for (int k = 0; k < text.size(); k++) 
			{
				bool stringsAreEqual = true;
				if (substrings[i][0] == text[k])
				{
					for (int j = 0; j < substrings[i].size(); j++) 
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

							std::string temp = '{' + std::to_string(indexOfOrigSubstring) + ", " + std::to_string(lengthOfOrigSubstirng) + '}';
							bool isReplacePossible = true;
							for (size_t l = 0; l < lengthOfOrigSubstirng; l++) if (text[l + indexOfOrigSubstring] == '{' or text[l + indexOfOrigSubstring] == '}') isReplacePossible = false;
							if (isReplacePossible) 
							{
								ReplaceText(text, k, lengthOfOrigSubstirng, temp);
								previousIndex = k;
								k += static_cast<int>(temp.size()) - lengthOfOrigSubstirng;
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

int RestoreText(std::string& text) 
{
	std::string copyOfText = text;

	for (int i = 0; i < text.size(); i++) 
	{
		std::string temp = "";
		int borderPos = 0;
		int sepPos = 0;
		int index = 0;
		int length = 0;

		if (text[i] == '{') 
		{
			temp = "";
			bool isBorderExist = false;
			bool isSeparatorExist = false;
			for (int j = i + 1; j < text.size(); j++) 
			{

				if (text[j] == '{' and isBorderExist == false)
					i = j;

				if (text[j] == ',') 
				{
					isSeparatorExist = true;
					sepPos = j;
				}

				if (text[j] == '}') 
				{
					isBorderExist = true;
					borderPos = j;
					break;
				}
			}

			if (isSeparatorExist and isBorderExist) 
			{
				for (size_t k = i + 1; k < sepPos; k++)
					temp += text[k];

				try 
				{
					index = stoi(temp.c_str());
				}
				catch (invalid_argument) 
				{
					cout << "Неверный формат специальной сигнатуры в тексте, надо исправить" << endl;
					return -1;
				}

				if (index > copyOfText.size()) 
				{
					cout << "Специальная сигнатура содержит невозможный индекс, надо исправить." << endl;
					return -1;
				}
				temp = "";

				for (size_t k = sepPos + 1; k < borderPos; k++)
					temp += text[k];

				try 
				{
					length = stoi(temp.c_str());
				}
				catch (invalid_argument) 
				{
					cout << "Неверный формат специальной сигнатуры в тексте, надо исправить" << endl;
					return -1;
				}

				if ((length > text.size()) or (index + length > copyOfText.size())) 
				{
					cout << "Специальная сигнатура содержит недопустимую длину." << endl;
					return -1;
				}

				temp = "";
				for (size_t k = 0; k < length; k++) temp += copyOfText[k + index];
				//cout << temp << endl;
				ReplaceText(text, i, borderPos - i + 1, temp);
				temp = "";
			}
		}
	}
	return 0;
}




bool CheckText(std::string& text) 
{
	bool isTextOkay = true;
	for (int i = 0; i < text.size(); i++) 
	{
		if (text[i] == '{')
		{
			for (int j = i; j < text.size(); j++)
			{
				if (text[j] == '}')
				{
					isTextOkay = false;
					break;
				}
			}
		}
	}
	return isTextOkay;
}