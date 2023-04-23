#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H

#include <string>
#include <iostream>

struct Name
{
	std::string first_name{}, last_name{}, patronymic{};
};

struct Address
{
	std::string city{}, street{}, appart{}, flat{};	
};

struct Contact
{
	long long card_num{};
	std::string phone_num{}, bank_num{};	
};

class Client
{
private:
	Name    _name{};
	Address _address{};
	Contact _contact{};

public:
	void SetName();
	void SetNameFromFile(std::istream& input);
	void SetAddress();
	void SetAddressFromFile(std::istream& input);
	void SetContact();
	void SetContactFromFile(std::istream& input);
	Name GetName();
	Address GetAddress();
	Contact GetContact();
	void ShowClient();
	bool IsEmpty();
	void Delete();
};

#endif