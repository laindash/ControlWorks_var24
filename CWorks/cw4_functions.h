#ifndef CW4_FUNCTIONS_H
#define CW4_FUNCTIONS_H
#include <vector>
#include <string>

void StartRestore(std::string& text, std::string& restoredText);
void StartModify(std::string& text, std::string& modifiedText, size_t substring_size);
void SetSubstringSize(size_t& substring_size);
void InputText(std::string& text);
void ShowRestored(const std::string& restoredText);
void ShowModified(const std::string& modifiedText);

bool IsTextRestored(const std::string& text);
void MakeListOfSubstrings(std::vector <std::string>& substrings, std::string& text);
void ReplaceText(std::string& text, size_t pos, size_t length, std::string input);
void FormatText(std::string& text, std::vector <std::string>& substrings, size_t substring_size);
void RestoreText(std::string& text);

#endif