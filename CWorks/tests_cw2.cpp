#include "tests_cw2.h"
#include "personality.h"
#include "universityemployee.h"
#include "cw2_functions.h"
#include "filefunctions_cw2.h"
#include <filesystem>
#include <fstream>

bool UnitTestCW2::TestCaseOne() // boot Employee from valid file
{
	std::vector<Personality*> employees{};
	const int employees_amount = 2;
	AddressCW2 address1{}, address2{};  //booted from file
	std::string
		surname1{},
		gender1{},
		position1{},
		department1{},
		responsibilities1{},
		surname2{},
		gender2{},
		position2{},
		department2{},
		responsibilities2{};
	double salary1{}, salary2{};

	std::string  	//answers
		asurname1 = "Fedin",
		asurname2 = "Slobodinskaya",
		agender1 = "m",
		agender2 = "f",		
		aposition1 = "st.pr",
		aposition2 = "docent",
		adepartment1 = "sapriu",
		adepartment2 = "matematika",
		aresponsibilities1 = "education",
		aresponsibilities2 = "education";
	AddressCW2 aaddress1{}, aaddress2{};
	aaddress1.city = "spb",
	aaddress1.street = "gti",
	aaddress1.appart = "-",
	aaddress1.flat = "-",
	aaddress2.city = "spb",
	aaddress2.street = "gti",
	aaddress2.appart = "-",
	aaddress2.flat = "-";
	double asalary1 = 1000000, asalary2 = 1000000000;


	GetEmployeesFromFile(employees, employees_amount, "test1cw2.txt");
	std::vector<Personality*>::iterator it = employees.begin();
	surname1 = (*it)->GetSurname();
	gender1 = (*it)->GetGender();
	address1 = (*it)->GetAddress();
	position1 = dynamic_cast<UniversityEmployee*>(*it)->GetPosition();
	department1 = dynamic_cast<UniversityEmployee*>(*it)->GetDepartment();
	responsibilities1 = dynamic_cast<UniversityEmployee*>(*it)->GetResponsibilities();
	salary1 = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();
	(*it)->Show();
	it++;
	surname2 = (*it)->GetSurname();
	gender2 = (*it)->GetGender();
	address2 = (*it)->GetAddress();
	position2 = dynamic_cast<UniversityEmployee*>(*it)->GetPosition();
	department2 = dynamic_cast<UniversityEmployee*>(*it)->GetDepartment();
	responsibilities2 = dynamic_cast<UniversityEmployee*>(*it)->GetResponsibilities();
	salary2 = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();


	if (asurname1 != surname1)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник с фамилией " << asurname1 << std::endl
			<< "Получено: " << surname1 << std::endl;
		return false;
	}
	if (asurname2 != surname2)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник с фамилией " << asurname2 << std::endl
			<< "Получено: " << surname2 << std::endl;
		return false;
	}

	if (agender1 != gender1)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий пол " << agender1 << std::endl
			<< "Получено: " << gender1 << std::endl;
		return false;
	}
	if (agender2 != gender2)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий пол " << agender2 << std::endl
			<< "Получено: " << gender2 << std::endl;
		return false;
	}

	if (aaddress1.appart != address1.appart || aaddress1.flat != address1.flat ||
		aaddress1.city != address1.city || aaddress1.street != address1.street)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий адрес " << std::endl
			<< aaddress1.city << std::endl
			<< aaddress1.street << std::endl
			<< aaddress1.appart << std::endl
			<< aaddress1.flat << std::endl
			<< "Получено: " << std::endl
			<< address1.city << std::endl
			<< address1.street << std::endl
			<< address1.appart << std::endl
			<< address1.flat << std::endl;
		return false;
	}
	if (aaddress2.appart != address2.appart || aaddress2.flat != address2.flat ||
		aaddress2.city != address2.city || aaddress2.street != address2.street)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий адрес " << std::endl
			<< aaddress2.city << std::endl
			<< aaddress2.street << std::endl
			<< aaddress2.appart << std::endl
			<< aaddress2.flat << std::endl
			<< "Получено: " << std::endl
			<< address2.city << std::endl
			<< address2.street << std::endl
			<< address2.appart << std::endl
			<< address2.flat << std::endl;
		return false;
	}

	if (aposition1 != position1)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий должность " << aposition1 << std::endl
			<< "Получено: " << position1 << std::endl;
		return false;
	}
	if (aposition2 != position2)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий должность " << aposition2 << std::endl
			<< "Получено: " << position2 << std::endl;
		return false;
	}

	if (adepartment1 != department1)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник закреплённый за кафедрой " << adepartment1 << std::endl
			<< "Получено: " << department1 << std::endl;
		return false;
	}
	if (adepartment2 != department2)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник закреплённый за кафедрой " << adepartment2 << std::endl
			<< "Получено: " << department2 << std::endl;
		return false;
	}

	if (aresponsibilities1 != responsibilities1)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий обязанности " << aresponsibilities1 << std::endl
			<< "Получено: " << responsibilities1 << std::endl;
		return false;
	}
	if (aresponsibilities2 != responsibilities2) 
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий обязанности " << aresponsibilities2 << std::endl
			<< "Получено: " << responsibilities2 << std::endl;
		return false;
	}

	if (asalary1 != salary1)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий зарплату " << asalary1 << std::endl
			<< "Получено: " << salary1 << std::endl;
		return false;
	}
	if (asalary2 != salary2)
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий зарплату " << asalary2 << std::endl
			<< "Получено: " << salary2 << std::endl;
		return false;
	}
	system("cls");
	return true;
}

bool UnitTestCW2::TestCaseTwo() // set double salary from file loaded employees
{
	std::vector<Personality*> employees{};
	const int employees_amount = 2;
	const double asalary1 = 10000, asalary2 = 100000.265;
	double salary1{}, salary2{};
	GetEmployeesFromFile(employees, employees_amount, "test2cw2.txt");
	std::vector<Personality*>::iterator it = employees.begin();
	salary1 = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();
	it++;
	salary2 = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();
	if (salary1 != asalary1)
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий зарплату " << asalary1 << std::endl
			<< "Получено: " << salary1 << std::endl;
		return false;
	}
	if (salary2 != asalary2)
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий зарплату " << asalary2 << std::endl
			<< "Получено: " << salary2 << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW2::TestCaseThree() // check Employees file where salary is negative digit
{
	std::vector<Personality*> employees{};
	const int employees_amount = 1;
	const double normal_salary = 1000, wrong_salary = -1000;
	double salary{};
	GetEmployeesFromFile(employees, employees_amount, "test3cw2.txt");
	std::vector<Personality*>::iterator it = employees.begin();
	salary = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();

	if (salary == wrong_salary)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "сотрудник имеющий зарплату " << normal_salary << std::endl
			<< "Получено: " << salary << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW2::TestCaseFour() // check Employees file where salary is not a digit
{
	std::string path = "test4cw2.txt";
	std::ifstream file(path);
	if (IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::TestCaseFive() // check Employees valid file
{
	std::string path = "test5cw2.txt";
	std::ifstream file(path);
	if (!IsDataCorrectCW2(file))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "данные корректны " << std::endl
			<< "Получено: " << "данные некорректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

void UnitTestCW2::RunAllTests()
{
	UnitTestCW2 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
