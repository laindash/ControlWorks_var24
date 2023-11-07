#include <filesystem>
#include <fstream>
#include "clientclass.h"
#include "input.h"

bool IsDataCorrect(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};

    long long test_ll{};

    while (!file.eof())
    {
        std::getline(file, test_string); //first_name
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //last_name
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //patronymic
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //city
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //street
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //appart
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //flat
        if (test_string.empty())
            return false;

        std::getline(file, test_string); //phone_number
        if (test_string.empty())
            return false;

        file >> test_ll;
        if (file.fail())
            return false; //Returns false if the card_number could not be read
        file.get();

        std::getline(file, test_string); //bank_number
        if (test_string.empty())
            return false;
    }
    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file

    return true;
}

std::string CheckFile()
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "������� ���� � �����: ";
        std::getline(std::cin, path);

        if (!std::ifstream(path))
        {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrect(file))
        {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void GetListFromFile(Client List[], int amount, std::string path = CheckFile())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        if (List[i].IsEmpty())
        {
            List[i].SetNameFromFile(file);
            List[i].SetAddressFromFile(file);
            List[i].SetContactFromFile(file);
        }
    }

    std::cout << "������ ��������!" << std::endl;

    file.close();
}

void SaveToFile(Client List[], int amount)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout 
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        std::getline(std::cin, path);

        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout 
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (GetKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    Name outputName{};
    Address outputAddress{};
    Contact outputContact{};

    for (int i = 0; i < amount && !List[i].IsEmpty(); i++)
    {
        outputName = List[i].GetName();
        outputAddress = List[i].GetAddress();
        outputContact = List[i].GetContact();

        if (i != 0)
            file << std::endl;

        file << outputName.first_name << std::endl << outputName.last_name << std::endl << outputName.patronymic << std::endl;
        file << outputAddress.city << std::endl << outputAddress.street << std::endl << outputAddress.appart << std::endl << outputAddress.flat << std::endl;
        file << outputContact.phone_num << std::endl << outputContact.card_num << std::endl << outputContact.bank_num;
    }

    std::cout << "������� ��������� � " << path << std::endl;
}

int CountStrings(std::string path)
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