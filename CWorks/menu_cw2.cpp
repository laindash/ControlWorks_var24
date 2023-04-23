#include "cw_info.h"
#include "input.h"
#include "cw2_functions.h"

void StartModMenuCW2(std::vector<Personality*>& employees)
{
    int current_id{};

    ShowEmployees(employees);
    do
    {
        std::cout << "Введите ID изменяемого сотрудника" << std::endl;
        current_id = GetPosInt() - 1;
        if (current_id > employees.size() - 1)
        {
            std::cout << "Ошибка! Сотрудника с данным ID не существует." << std::endl;
            continue;
        }
    }
    while (current_id > employees.size() - 1);

    std::vector<Personality*>::iterator it = employees.begin();
    advance(it, current_id);
    UniversityEmployee* current_employee = new UniversityEmployee(*dynamic_cast<UniversityEmployee*>(*it));
    bool isDelete = false;
    ShowModMenuCW2();
    int user_choice = GetKey(MOD_SURNAME, MOD_SALARY);
    switch (user_choice)
    {
    case MOD_SURNAME:
        (*it)->SetSurname();
        break;

    case MOD_GENDER:
        (*it)->SetGender();
        break;

    case MOD_ADDRESSCW2:
        (*it)->SetAddress();
        break;

    case MOD_POSITION:
        dynamic_cast<UniversityEmployee*>(*it)->SetPosition();
        break;

    case MOD_DEPARTMENT:
        dynamic_cast<UniversityEmployee*>(*it)->SetDepartment();
        break;

    case MOD_RESPONSIBILITIES:
        dynamic_cast<UniversityEmployee*>(*it)->SetResponsibilities();
        break;

    case MOD_SALARY:
        dynamic_cast<UniversityEmployee*>(*it)->SetSalary();
        break;

    case DELETE:
        (*it)->Delete(employees, current_id);
        isDelete = true;
        delete (*it);
        break;

    case QUIT:
        std::cout << "......................." << std::endl;
        break;
    }


    if (user_choice != QUIT)
    {
        std::cout
            << "Подтвердить изменение?" << std::endl
            << "1 - Да, 2 - Нет." << std::endl;
        if (GetKey(YES, NO) == NO)
        {
            if (!isDelete)
                employees.erase(it);
            it = employees.begin();
            advance(it, current_id);
            employees.insert(it, current_employee);
        }
        else
            delete current_employee;
    }
}
