#include "tests_cw3.h"
#include "cw3_functions.h"
#include "filefunctions_cw3.h"
#include "matrix.h"

void UnitTestCW3::PrintArray(std::vector<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << ' ';
	std::cout << std::endl;
}

bool UnitTestCW3::TestCaseOne() // test bubble sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ChessMatrix cmatrix{};
	BubbleSort bubble_sort{};
	bubble_sort.Sort(array);
	if (!cmatrix.IsSorted(array))
	{
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseTwo() // test selection sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ChessMatrix cmatrix{};
	SelectionSort selection_sort{};
	selection_sort.Sort(array);
	if (!cmatrix.IsSorted(array))
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseThree() // test insertion sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ChessMatrix cmatrix{};
	InsertionSort insertion_sort{};
	insertion_sort.Sort(array);
	if (!cmatrix.IsSorted(array))
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseFour() // test shell sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ChessMatrix cmatrix{};
	ShellSort shell_sort{};
	shell_sort.Sort(array);
	if (!cmatrix.IsSorted(array))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseFive() // test quick sort
{
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ChessMatrix cmatrix{};
	QuickSort quick_sort{};
	quick_sort.Sort(array);
	if (!cmatrix.IsSorted(array))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		PrintArray(answer);
		std::cout << "Получено: " << std::endl;
		PrintArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::TestCaseSix() //test sort matrix
{
	int rows{}, columns{};
	std::vector<std::vector<int>> matrix{}, rows_to_test{}, columns_to_test{};
	ChessMatrix cmatrix{};
	std::vector<ISort*> sorts{};
	BubbleSort* bubble_sort = new BubbleSort;
	sorts.push_back(bubble_sort);
	SelectionSort* selection_sort = new SelectionSort;
	sorts.push_back(selection_sort);
	InsertionSort* insertion_sort = new InsertionSort;
	sorts.push_back(insertion_sort);
	ShellSort* shell_sort = new ShellSort;
	sorts.push_back(shell_sort);
	QuickSort* quick_sort = new QuickSort;
	sorts.push_back(quick_sort);
	std::string path = "test6cw3.txt";

	std::vector<std::vector<int>> answerRows{ {44, 81 }, {-30, 58}, {-20, 80}, {-60, -10}, {-75,  84} };
	std::vector<std::vector<int>> answerColumns{ {53, -87}, {91, 80, -62}, {79, 58}, {30, -38, -89} };
	GetMatrixFromFile(matrix, rows, columns, path);
	system("cls");
	for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++)
	{
		cmatrix.StartSort(matrix, rows, columns, it);
		rows_to_test = cmatrix.GetSortedRows();
		columns_to_test = cmatrix.GetSortedColumns();
		for (size_t i = 0; i < rows; i++) // check sorted rows
		{
			if (rows_to_test[i] != answerRows[i])
			{
				std::cout
					<< "Тест 6 провален." << std::endl
					<< "Ожидалось: " << "отсортированные элементы строки " << i + 1 << ": " << std::endl;
				PrintArray(answerRows[i]);
				std::cout << "Получено сортировкой: "; 
				std::cout << (*it)->GetSortName() << std::endl;
				PrintArray(rows_to_test[i]);
				return false;
			}
		}

		for (size_t i = 0; i < columns; i++) // check sorted columns
		{
			if (columns_to_test[i] != answerColumns[i])
			{
				std::cout
					<< "Тест 6 провален." << std::endl
					<< "Ожидалось: " << "отсортированные элементы столбца " << i + 1 << ": " << std::endl;
				PrintArray(answerColumns[i]);
				std::cout << "Получено сортировкой: ";
				std::cout << (*it)->GetSortName() << std::endl;
				PrintArray(columns_to_test[i]);
				return false;
			}
		}
	}

	delete bubble_sort;
	delete selection_sort;
	delete insertion_sort;
	delete shell_sort;
	delete quick_sort;

	return true;
}


void UnitTestCW3::RunAllTests()
{
	UnitTestCW3 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive() && test.TestCaseSix())
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
