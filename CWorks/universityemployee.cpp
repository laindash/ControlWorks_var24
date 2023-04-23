#include "universityemployee.h"
#include "input.h"
#include <iomanip>

void UniversityEmployee::Show(void) const
{
    Personality::Show();
    std::cout
        << "| Должность: " << _position << std::endl
        << "| Кафедра: " << _department << std::endl
        << "| Обязанности: " << _responsibilities << std::endl
        << "| Зарплата: " << std::fixed << std::setprecision(2) << _salary << " $" << std::endl
        << "************************************************" << std::endl;
}

void UniversityEmployee::SetSalary(void)
{
    std::cout << "Введите зарплату сотрудника" << std::endl;
    _salary = GetPosDouble();
}

void UniversityEmployee::SetSalaryFromFile(std::istream& input)
{
    input >> _salary; input.get();
}

double UniversityEmployee::GetSalary(void)
{
    return fabs(_salary);
}

void UniversityEmployee::SetPosition(void)
{
    std::cout << "Введите позицию сотрудника" << std::endl;
    GetLine(std::cin, _position, WITHOUT_DIGITS, MANUAL_INPUT);
}

void UniversityEmployee::SetPositionFromFile(std::istream& input)
{
    std::getline(input, _position);
}


std::string UniversityEmployee::GetPosition(void)
{
    return _position;
}

void UniversityEmployee::SetResponsibilities(void)
{
    std::cout << "Перечислите обязанности сотрудника" << std::endl;
    GetLine(std::cin, _responsibilities, WITH_DIGITS, MANUAL_INPUT);
}

void UniversityEmployee::SetResponsibilitiesFromFile(std::istream& input)
{
    std::getline(input, _responsibilities);
}

std::string UniversityEmployee::GetResponsibilities(void)
{
    return _responsibilities;
}

void UniversityEmployee::SetDepartment(void)
{
    std::cout << "Введите название кафедры за которой закреплён сотрудник" << std::endl;
    GetLine(std::cin, _department, WITHOUT_DIGITS, MANUAL_INPUT);
}

void UniversityEmployee::SetDepartmentFromFile(std::istream& input)
{
    std::getline(input, _department);
}

std::string UniversityEmployee::GetDepartment(void)     
{
    return _department;
}

bool UniversityEmployee::IsEmpty(void)
{
    if (!_surname.empty())
        return false;
    if (!_gender.empty())
        return false;
    if (!_address.city.empty())
        return false;
    if (!_address.street.empty())
        return false;
    if (!_address.appart.empty())
        return false;
    if (!_address.flat.empty())
        return false;
    if (!_position.empty())
        return false;
    if (!_department.empty())
        return false;
    if (!_responsibilities.empty())
        return false;

    return true;
}

