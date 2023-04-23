#include "input.h"
#include "filefunctions_cw2.h"
#include "universityemployee.h"
#include <vector>


void FillEmployees(std::vector<Personality*>& employees, int amount)
{
    std::cout << std::endl;
    int UniversityEmployee_id = 1;
    for (int i = 0; i < amount; i++)
    {
        std::cout << "Заполните информацию о сотруднике # " << UniversityEmployee_id << std::endl;
        UniversityEmployee* new_employee = new UniversityEmployee;
        new_employee->SetSurname();
        new_employee->SetGender();
        new_employee->SetAddress();
        new_employee->SetPosition();
        new_employee->SetDepartment();
        new_employee->SetResponsibilities();
        new_employee->SetSalary();
        employees.push_back(new_employee);
        UniversityEmployee_id++;
    }
}

void ShowEmployees(std::vector<Personality*>& employees)
{
    int UniversityEmployee_id = 1;
    for (std::vector<Personality*>::const_iterator it = employees.cbegin(); it != employees.cend(); it++, UniversityEmployee_id++)
    {
        std::cout << "ID " << UniversityEmployee_id << std::endl;
        dynamic_cast<UniversityEmployee*>(*it)->Show();
    }
}