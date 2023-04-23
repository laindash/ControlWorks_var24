#include "tests_cw4.h"
#include "cw4_functions.h"
#include "filefunctions_cw4.h"
#include <iostream>

bool UnitTestCW4::TestCaseOne() // test
{
	
	return true;
}

bool UnitTestCW4::TestCaseTwo() // test 
{
	
	return true;
}

bool UnitTestCW4::TestCaseThree() // test
{
	
	return true;
}

bool UnitTestCW4::TestCaseFour() // test
{
	
	return true;
}

bool UnitTestCW4::TestCaseFive() // test
{
	
	return true;
}


void UnitTestCW4::RunAllTests()
{
	UnitTestCW4 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
