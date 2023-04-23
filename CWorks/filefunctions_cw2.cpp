#include <filesystem>
#include <fstream>
#include "personality.h"
#include "universityemployee.h"
#include "input.h"


bool IsDataCorrectCW2(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    double test_double{};
    while (!file.eof())
    {
        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //surname
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания фамилии" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //gender
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания пола" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //city
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания города" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //street
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания улицы" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //appart
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания номера дома" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //flat
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания номера квартиры" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //position
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания должности сотрудника" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //department
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания кафедры сотрудника" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //resp
        if (test_string.empty())
        {
            std::cout << "Ошибка считывания обязанностей сотрудника" << std::endl;
            return false;
        }

        file >> test_double;
        if (test_double > DBL_WRONG)
        {
            std::cout << "Ошибка считывания зарплаты сотрудника, превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "Ошибка считывания зарплаты сотрудника" << std::endl;
            return false; //Returns false if salary not be read
        }
        file.get();
    }
    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file

    return true;
}

std::string CheckFileCW2(void)
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "Введите путь к файлу: ";
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path))
        {
            std::cout << "Указанный файл не найден!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "Ошибка открытия файла!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrectCW2(file))
        {
            std::cout << "Данные некорректны!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "Файл открыт!" << std::endl;
    file.close();

    return path;
}

void GetEmployeesFromFile(std::vector<Personality*>& employees, int amount, std::string path = CheckFileCW2())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        UniversityEmployee* new_employee = new UniversityEmployee;
        new_employee->SetSurnameFromFile(file);
        new_employee->SetGenderFromFile(file);
        new_employee->SetAddressFromFile(file);
        new_employee->SetPositionFromFile(file);
        new_employee->SetDepartmentFromFile(file);
        new_employee->SetResponsibilitiesFromFile(file);
        new_employee->SetSalaryFromFile(file);
        employees.push_back(new_employee);
    }

    std::cout << "Список загружен!" << std::endl;

    file.close();
}

void SaveToFile(std::vector<Personality*>& employees)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout
            << "Введите путь к файлу для сохранения. "
            << "Если указать только имя и расширение файла, стандартным путём будет являться путь к исходному коду программы." << std::endl;
        std::getline(std::cin, path);

        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
                continue;
            }

            std::cout
                << "Данный файл уже существует!." << std::endl
                << "1 - Перезаписать." << std::endl
                << "2 - Выбрать другой." << std::endl;

            if (GetKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "Ошибка открытия файла!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    std::string outputSurname{}, outputGender{},
        outputPosition{}, outputDepartment{}, outputResponsibilities{};
    AddressCW2 outputAddress{};
    double outputSalary{};
    for (std::vector<Personality*>::iterator it = employees.begin(); it != employees.end() && !(dynamic_cast<UniversityEmployee*>(*it)->IsEmpty()); it++)
    {
        outputSurname = (*it)->GetSurname();
        outputGender = (*it)->GetGender();
        outputAddress = (*it)->GetAddress();
        outputPosition = dynamic_cast<UniversityEmployee*>(*it)->GetPosition();
        outputDepartment = dynamic_cast<UniversityEmployee*>(*it)->GetDepartment();
        outputResponsibilities = dynamic_cast<UniversityEmployee*>(*it)->GetResponsibilities();
        outputSalary = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();

        if (it != employees.begin())
            file << std::endl;
        file << outputSurname << std::endl;
        file << outputGender << std::endl;
        file << outputAddress.city << std::endl 
             << outputAddress.street << std::endl 
             << outputAddress.appart << std::endl 
             << outputAddress.flat << std::endl;
        file << outputPosition << std::endl;
        file << outputDepartment << std::endl;
        file << outputResponsibilities << std::endl;
        file << outputSalary;
    }
    std::cout << "Успешно сохранено в " << path << std::endl;
}

int CountStringsCW2(std::string path)
{
    int stringsAmount{};

    std::ifstream file;
    file.open(path);
    std::string tmp{};

    while (!file.eof())
    {
        std::getline(file, tmp);
        stringsAmount++;
    }

    return stringsAmount;
}