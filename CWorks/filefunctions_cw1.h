#ifndef filefunctions_cw1_H
#define filefunctions_cw1_H

#include "clientclass.h"

bool IsDataCorrect(std::ifstream& file);

std::string CheckFile(void);

void GetListFromFile(Client *List, int amount, std::string path = CheckFile());

void SaveToFile(Client *List, int amount);

int CountStrings(std::string path);


#endif
