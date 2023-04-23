#include "personality.h"
#include "input.h"
#include <vector>

void Personality::Show(void) const
{
    std::cout
        << "************************************************" << std::endl
        << "| Фамилия: " << _surname << std::endl
        << "| Пол: " << _gender << std::endl
        << "| Город: " << _address.city << std::endl
        << "| Улица: " << _address.street << std::endl
        << "| Дом: " << _address.appart << std::endl
        << "| Квартира: " << _address.flat << std::endl
        << "************************************************" << std::endl;
}

void Personality::SetSurname(void)
{
    std::cout << "Введите фамилию: ";
    GetLine(std::cin, _surname, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Personality::SetSurnameFromFile(std::istream& input)
{
    std::getline(input, _surname);
}

void Personality::SetGender(void)
{
    std::cout << "Введите пол: ";
    GetLine(std::cin, _gender, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Personality::SetGenderFromFile(std::istream& input)
{
    std::getline(input, _gender);
}

void Personality::SetAddress(void)
{
    std::cout << "Введите название города: ";
    GetLine(std::cin, _address.city, WITH_DIGITS, MANUAL_INPUT);
    std::cout << "Введите название улицы: ";
    GetLine(std::cin, _address.street, WITH_DIGITS, MANUAL_INPUT);

    std::cout << "Введите номер дома: ";
    GetLine(std::cin, _address.appart, ALMOST_ALL_DIGITS, MANUAL_INPUT);
    std::cout << "Введите номер квартиры: ";
    GetLine(std::cin, _address.flat, ALMOST_ALL_DIGITS, MANUAL_INPUT);
}

void Personality::SetAddressFromFile(std::istream& input)
{
    std::getline(input, _address.city);
    std::getline(input, _address.street);
    std::getline(input, _address.appart);
    std::getline(input, _address.flat);
}

std::string Personality::GetSurname(void)
{
    return _surname;
}

std::string Personality::GetGender(void)
{
    return _gender;
}

AddressCW2 Personality::GetAddress(void)
{
    return _address;
}

void Personality::Delete(std::vector<Personality*>& personalities, int id)
{
    std::vector<Personality*>::iterator it = personalities.begin();
    advance(it, id);
    personalities.erase(it);
}