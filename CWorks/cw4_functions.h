#ifndef CW4_FUNCTIONS_H
#define CW4_FUNCTIONS_H
#include <vector>
#include <string>

std::string FindAndReplace(const std::string& text, int substring_size);
std::string RestoreOriginalText(const std::string& text, int substring_size);
void StartModify(std::vector<std::string>& strings, std::vector<std::string>& changedString, int substring_size);
void SetSubstringSize(int& substring_size);
void FillStrings(std::vector<std::string>& strings);
void ShowRestored(std::vector<std::string>& strings);
void ShowModified(std::vector<std::string>& changedStrings);



void MakeListOfSubstrings(std::vector <std::string>& substrings, std::string& text);

void FindAllSubstrings(std::vector <int>& indexes, std::string substring, std::string& text, size_t sizeOfSubstring);

void ReplaceText(std::string& text, int pos, int length, std::string input);

void FormatText(std::string& text, std::vector <std::string>& substrings, int reqSubstringLength);

int RestoreText(std::string& text);

bool CheckText(std::string& text);

#endif