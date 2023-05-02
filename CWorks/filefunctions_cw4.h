#ifndef FILEFUNCTIONS_CW4_H
#define FILEFUNCTIONS_CW4_H

bool IsDataCorrectCW4(std::ifstream& file);
std::string CheckFileCW4();
void GetTextFromFile(std::string& text, std::string& path);
void SaveToFile(std::vector<std::string>& strings, std::vector<std::string>& changedStrings, int save_choice);

#endif