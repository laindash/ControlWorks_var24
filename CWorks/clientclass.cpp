#include "clientclass.h"
#include "input.h"

void Client::SetName(void)
{
    std::cout << "������� ���: ";
    GetLine(std::cin, _name.first_name, WITHOUT_DIGITS, MANUAL_INPUT);
    std::cout << "������� �������: ";
    GetLine(std::cin, _name.last_name, WITHOUT_DIGITS, MANUAL_INPUT);
    std::cout << "������� ��������: ";
    GetLine(std::cin, _name.patronymic, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Client::SetNameFromFile(std::istream& input)
{
    std::getline(input, _name.first_name);
    std::getline(input, _name.last_name);
    std::getline(input, _name.patronymic);
}

void Client::SetAddress(void)
{
    std::cout << "������� �������� ������: ";
    GetLine(std::cin, _address.city, WITH_DIGITS, MANUAL_INPUT);
    std::cout << "������� �������� �����: ";
    GetLine(std::cin, _address.street, WITH_DIGITS, MANUAL_INPUT);

    std::cout << "������� ����� ����: ";
    GetLine(std::cin, _address.appart, ALMOST_ALL_DIGITS, MANUAL_INPUT);
    std::cout << "������� ����� ��������: ";
    GetLine(std::cin, _address.flat, ALMOST_ALL_DIGITS, MANUAL_INPUT);
}

void Client::SetAddressFromFile(std::istream& input)
{
    std::getline(input, _address.city);
    std::getline(input, _address.street);
    std::getline(input, _address.appart);
    std::getline(input, _address.flat);
}

void Client::SetContact(void)
{
    std::cout << "������� ����� ��������: ";
    GetLine(std::cin, _contact.phone_num, ALMOST_ALL_DIGITS, MANUAL_INPUT);
    std::cout << "������� ����� ���������� �����(��� ��������): ";
    _contact.card_num = GetLongLong();
    std::cout << "������� ����� ����������� �����: ";
    GetLine(std::cin, _contact.bank_num, ONLY_DIGITS, MANUAL_INPUT);
}

void Client::SetContactFromFile(std::istream& input)
{
    std::getline(input, _contact.phone_num);
    input >> _contact.card_num;  input.get();
    std::getline(input, _contact.bank_num);
}

Name Client::GetName()
{
    return _name;
};

Address Client::GetAddress()
{
    return _address;
};

Contact Client::GetContact()
{
    return _contact;
};

void Client::ShowClient()
{
    std::cout
        << std::endl << "************************************************" << std::endl
        << "| ���: " << _name.first_name << std::endl
        << "| �������: " << _name.last_name << std::endl
        << "| ��������: " << _name.patronymic << std::endl

        << "| �����: " << _address.city << std::endl
        << "| �����: " << _address.street << std::endl
        << "| ���: " << _address.appart << std::endl
        << "| ��������: " << _address.flat << std::endl

        << "| �������: " << _contact.phone_num << std::endl
        << "| �����: " << _contact.card_num << std::endl
        << "| ���������� ����: " << _contact.bank_num << std::endl
        << "************************************************" << std::endl
        << std::endl;
};

bool Client::IsEmpty()
{
    if (!_name.first_name.empty())
        return false;
    if (!_name.last_name.empty())
        return false;
    if (!_name.patronymic.empty())
        return false;

    if (!_address.city.empty())
        return false;
    if (!_address.street.empty())
        return false;
    if (!_address.appart.empty())
        return false;
    if (!_address.flat.empty())
        return false;

    if (!_contact.phone_num.empty())
        return false;
    if (_contact.card_num != 0)
        return false;
    if (!_contact.bank_num.empty())
        return false;

    return true;
}

void Client::Delete()
{
    _name.first_name.clear();
    _name.last_name.clear();
    _name.patronymic.clear();

    _address.city.clear();
    _address.street.clear();
    _address.appart.clear();
    _address.flat.clear();

    _contact.phone_num.clear();
    _contact.card_num = 0;
    _contact.bank_num.clear();
}