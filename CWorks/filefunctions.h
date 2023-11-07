#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include "clientclass.h"

bool IsDataCorrect(std::ifstream& file);

std::string CheckFile(void);

void GetListFromFile(Client List[], int amount, std::string path = CheckFile());

void SaveToFile(Client List[], int amount);

int CountStrings(std::string path);


#endif
