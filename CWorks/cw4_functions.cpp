#include "input.h"
#include <iostream>
#include <regex>


void MakeListOfSubstrings(std::vector <std::string>& substrings, std::string& text) 
{
	std::string temp = "";
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
					if (temp[j] == ' ' or temp[j] == '\n' or temp[j] == '\t') 
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

void FindAllSubstrings(std::vector<int>& indexes, std::string substring, std::string& text, size_t sizeOfSubstring) 
{
	if (substring.size() > sizeOfSubstring) 
	{
		for (size_t i = 0; i < text.size(); i++) 
		{
			bool stringsAreEqual = true;
			if (substring[0] == text[i])
			{
				for (size_t j = 0; j < substring.size(); j++)
				{
					if (i + j > text.size())
					{
						stringsAreEqual = false;
						break;
					}
					if (substring[j] != text[i + j])
						stringsAreEqual = false;
				}
				if (stringsAreEqual)
					indexes.push_back(i);
			}
			else
				stringsAreEqual = false;
		}
	}

	for (size_t i = 1; i < indexes.size();) 
	{
		if (indexes[i - 1] + substring.size() - 1 == indexes[i])
			indexes.erase(indexes.begin() + i);
		else i++;
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

void FormatText(std::string& text, std::vector<std::string>& substrings, int reqSubstringLength) 
{
	std::string copyOfText = text;

	for (int i = 0; i < substrings.size(); i++) 
	{
		int substringEnteringsCounter(0);
		size_t indexOfOrigSubstring(0);
		size_t lengthOfOrigSubstirng = substrings[i].size();
		size_t previousIndex = 0;
		if (substrings[i].size() > reqSubstringLength) 
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

							std::string temp = '{' + std::to_string(indexOfOrigSubstring) + ", " + std::to_string(lengthOfOrigSubstirng) + '}';
							bool isReplacePossible = true;
							for (size_t l = 0; l < lengthOfOrigSubstirng; l++) if (text[l + indexOfOrigSubstring] == 
								'{' || text[l + indexOfOrigSubstring] == '}') isReplacePossible = false;

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
	std::string copyOfText = text;

	for (size_t i = 0; i < text.size(); i++)
	{
		std::string temp{};
		size_t borderPos(0), sepPos(0), index(0), length(0);

		/*
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
					index = std::stoi(temp.c_str());
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
				*/

				ReplaceText(text, i, borderPos - i + 1, temp);
				temp = "";
			//}
		//}
	}
}




bool CheckText(std::string& text, bool& textIsModified) 
{
	bool isTextOkay = true;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i] == '{')
		{
			for (size_t j = i; j < text.size(); j++)
			{
				if (text[j] == '}')
				{
					isTextOkay = false;
					textIsModified = true;
					break;
				}
			}
		}
	}
	return isTextOkay;
}


void StartModify(std::string text, std::vector<std::string>& changedStrings, int substring_size)
{
	std::vector<std::string> substrings{};
	MakeListOfSubstrings(substrings, text);
	FormatText(text, substrings, substring_size);
	changedStrings.push_back(text);
}

void StartRestore(std::string text, std::vector<std::string>& strings)
{
	RestoreText(text);
	strings.push_back(text);
}

void SetSubstringSize(int& substring_size)
{
	std::cout << "Введите минимальную длину подстроки: " << std::endl;
	substring_size = GetPosInt();
}

void InputText(std::string& text)
{
	std::cout << "Введите текст. Для окончания ввода введите quit." << std::endl;
	std::string input{};
	while (input != "quit")
	{
		GetLine(std::cin, input, WITH_DIGITS, MANUAL_INPUT);
		if (input != "quit")
			text += input;
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
