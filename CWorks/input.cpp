#include <iostream>
#include <limits>
#include <cctype>
#include "input.h"
#include "wchar.h"
#include <iomanip>
#include <vector>

template<typename T>
T GetT()
{
    T input{};

    std::cin >> input;
    do
    {
        if (std::cin.fail())
        {
            std::cout << "Неверный ввод, повторите попытку!" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin >> input;
        }
    } 
    while (std::cin.fail());
    std::cin.ignore(INT_MAX, '\n');

    return input;
}



int GetKey(int key_min, int key_max)
{
    int key = 0;

    do
    {
        key = _getch();
        if (key == KEY_ESC)
            return key;
    } 
    while ((key < key_min) || (key > key_max));

    return key;

}

template<typename T>
T GetPosT()
{
    T num = 0;
    do
    {
        num = GetT<T>();
        if (num < 0)
        {
            std::cout << "Взято значение по модулю!" << std::endl;
            num = abs(num);
        }
        if (num > DBL_WRONG)
        {
            std::cout << "Вводимое значение должно быть не больше чем " << std::fixed << DBL_WRONG << std::endl;
            continue;
        }
        else if (num == 0)
            std::cout << "Вводимое значение не должно быть равно 0. Повторите попытку!" << std::endl;
    } 
    while (num <= 0 || num > DBL_WRONG);
    return num;
}

int GetPosInt()
{
    return GetPosT<int>();
}

size_t GetSubstringSize()
{
    size_t size{};
    do
    {
        size = static_cast<size_t>(GetPosT<long long>());
        if (size < 2)
            std::cout << "Размер подстроки должен быть >=2" << std::endl;
    } 
    while (size < 2);

    return size;
}

int GetInt() 
{
    return GetT<int>();
}

double GetDouble()
{
    return GetT<double>();
}


double GetPosDouble()
{
    return GetPosT<double>();
}

long long GetPosLongLong()
{
    return GetPosT<long long>();
}

long long GetLongLong()
{
    return GetT<long long>();
}

bool GetBool()
{
    return GetT<bool>();
}

int GetRandInt(int lowBound, int upBound)
{
    return (rand() % (upBound - lowBound) + lowBound);
}



std::string GetLine(std::istream& _Input, std::string& line, int num_exists, int isInput) 
{
    bool validInput = true;
    do
    {
        std::getline(_Input, line);
        do
        {
            if (std::cin.fail())
            {
                _Input.clear();
                _Input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод, повторите попытку!" << std::endl;
                std::getline(_Input, line);
                if (isInput == FILE_INPUT)
                    validInput = false;
            }
        } 
        while (std::cin.fail() && isInput != FILE_INPUT);

        if (isInput == FILE_INPUT && !validInput)
            break;

        if (line.empty() && isInput != FILE_INPUT)
        {
            std::cout << "Вводимое значение не должно быть пустым!" << std::endl;
            validInput = false;
            continue;
        }

        if (num_exists != CW4_INPUT)
        {
            int space_position(0);
            int character_position(0);
            for (const unsigned char c : line)  //checking that a string does not start with spaces
            {
                if (!iswprint(c))
                {
                    validInput = false;
                    std::cout << "Вводимое значение не должно содержать непечатные символы!" << std::endl;
                    break;
                }
                if (c == ' ')
                    space_position++;
                if (c != ' ')
                    character_position++;
                if (space_position > character_position)
                {
                    validInput = false;
                    std::cout << "Вводимое значение не должно начинаться с пробела!" << std::endl;

                    break;
                }
                else
                    validInput = true;
            }
        }

        if (num_exists == WITHOUT_DIGITS)
        {
            for (const unsigned char c : line)
            {
                if (isdigit(c))
                {
                    validInput = false;
                    std::cout << "Вводимое значение не должно содержать цифр!" << std::endl;
                    break;
                }
            }
        }  

        if (num_exists == ONLY_DIGITS)
        {
            for (const unsigned char c : line)
            {
                if (!isdigit(c))
                {
                    validInput = false;
                    std::cout << "Вводимое значение может содержать только цифры!" << std::endl;
                    break;
                }
            }
        }

        if (num_exists == ALMOST_ALL_DIGITS)
        {
            for (const unsigned char c : line)
            {
                if (!isdigit(c) && !((c == '/') || (c == ' ') || (c == '+') || (c == '-')))
                {
                    validInput = false;
                    std::cout << "Вводимое значение может содержать только цифры и символы '+ - /' !" << std::endl;
                    break;
                }
            }
        }
    } 
    while (!validInput && isInput == MANUAL_INPUT);

    if (!validInput && isInput == FILE_INPUT)
    {
        line = "";
        return line;
    }

    return line;
}

size_t GetMaxNumLength(std::vector<std::vector<int>> matrix, int rows, int columns)
{
    int num{};
    size_t length{}, max_num_length(0);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            num = matrix[i][j];
            length = std::to_string(num).length();
            if (length > max_num_length)
                max_num_length = length;
        }
    }
    return max_num_length;
}

void ShowColoredNum(int& num, size_t max_num_length, int white)
{
    if (white == 0)
        std::cout << "\033[47m";
    if (white == 1)
        std::cout << "\033[40m";
    std::cout
        << std::setw(max_num_length)
        << num << ' ';
    std::cout << "\033[0m";
}