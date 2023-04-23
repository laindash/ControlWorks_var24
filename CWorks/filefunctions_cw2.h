#ifndef FILEFUNCTIONS_CW2_H
#define FILEFUNCTIONS_CW2_H
#include "universityemployee.h"
#include "input.h"

bool IsDataCorrectCW2(std::ifstream& file);

std::string CheckFileCW2();

void GetEmployeesFromFile(std::vector<Personality*>& employees, int amount, std::string path = CheckFileCW2());

void SaveToFile(std::vector<Personality*>& employees);

int CountStringsCW2(std::string path);


#endif
