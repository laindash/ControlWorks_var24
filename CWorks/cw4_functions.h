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


#endif