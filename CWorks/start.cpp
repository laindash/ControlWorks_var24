#include "filefunctions_cw1.h"
#include "filefunctions_cw2.h"
#include "filefunctions_cw3.h"
#include "filefunctions_cw4.h"
#include "input.h"
#include "cw_info.h"
#include "cw1_functions.h"
#include "menu_cw1.h"
#include "tests_cw1.h"
#include "cw2_functions.h"
#include "menu_cw2.h"
#include "tests_cw2.h"
#include "cw3_functions.h"
#include "tests_cw3.h"
#include "cw4_functions.h"
#include "tests_cw4.h"


void StartCW1(void)
{
    int user_choice{};
    do
    {
        int clients_amount{};
        std::string file_path = "";
        Client* clients = nullptr;
        UnitTestCW1 tests{};

        InfoCW1();
        ShowMainMenuCW1();
        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
            {
                do
                {
                    file_path = CheckFile();
                    clients_amount = (CountStrings(file_path) / 10);

                    std::cout << "Загружено клиентов: " << clients_amount << std::endl;
                    if (AllocateArray(clients, clients_amount))
                        clients = new Client[clients_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!AllocateArray(clients, clients_amount));

                GetListFromFile(clients, clients_amount, file_path);
                break;
            }

            case MANUAL_INPUT:
            {
                do
                {
                    std::cout << "Введите число клиентов: ";
                    clients_amount = GetPosInt();
                    if (AllocateArray(clients, clients_amount))
                        clients = new Client[clients_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!AllocateArray(clients, clients_amount));

                AddNewClient(clients, clients_amount);
                break;
            }

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT: 
                break;
        }

        while (user_choice != QUIT)
        {
            ShowMenuCW1();
            switch (user_choice = GetKey(ALPH_SEARCH, SAVE))
            {
            case ALPH_SEARCH:
                if (!IsListEmpty(clients, clients_amount))
                    SearchByAlph(clients, clients_amount);
                else
                    std::cout << "Список пуст!" << std::endl;
                break;

            case CARD_SEARCH:
                if (!IsListEmpty(clients, clients_amount))
                    SearchByCardRange(clients, clients_amount);
                else
                    std::cout << "Список пуст!" << std::endl;
                break;

            case ADDorMODIFY:
                ShowSubMenuCW1();
                switch (int mod_choice = GetKey(ADD, MODIFY))
                {
                    case ADD:
                        clients = AllocMore(clients, clients_amount);
                        if (!IsListFull(clients, clients_amount))
                            AddNewClient(clients, clients_amount);
                        else
                            std::cout << "Список переполнен!" << std::endl;
                        break;

                    case MODIFY:
                        if (!IsListEmpty(clients, clients_amount))
                            StartModMenuCW1(clients, clients_amount);
                        else
                            std::cout << "Список пуст!" << std::endl;
                        break;

                    case QUIT:
                        break;
                }
                break;


            case SAVE:
                if (!IsListEmpty(clients, clients_amount))
                    SaveToFile(clients, clients_amount);
                else
                    std::cout << "Список пуст!" << std::endl;
                break;

            case QUIT:
                break;
            }
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW2(void)
{
    int user_choice{};
    do
    {
        std::vector<Personality*> personalities{};
        int personalities_amount{};
        std::string file_path = "";
        UnitTestCW2 tests{};

        InfoCW2();
        ShowMainMenuCW2();
        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
                file_path = CheckFileCW2();
                personalities_amount = (CountStringsCW2(file_path) / 10);
                std::cout << "Загружено сотрудников: " << personalities_amount << std::endl;
                GetEmployeesFromFile(personalities, personalities_amount, file_path);
                break;

            case MANUAL_INPUT:
                std::cout << "Введите число сотрудников: ";
                personalities_amount = GetPosInt();
                FillEmployees(personalities, personalities_amount);
                break;

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT:
                break;
        }

        while (user_choice != QUIT)
        {
            ShowMenuCW2();
            switch (user_choice = GetKey(SHOW, SAVECW2))
            {
                case SHOW:
                    if (!(personalities.size() < 1))
                        ShowEmployees(personalities);
                    else
                        std::cout << "Список пуст!" << std::endl;
                    break;

                case ADDorMODIFYCW2:
                    ShowSubMenuCW2();
                    switch (int mod_choice = GetKey(ADD, MODIFY))
                    {
                        case ADD:
                            std::cout << "Введите, сколько сотрудников добавить: " << std::endl;
                            personalities_amount = GetPosInt();
                            FillEmployees(personalities, personalities_amount);
                            break;

                        case MODIFY:
                            if (!(personalities.size() < 1))
                                StartModMenuCW2(personalities);
                            else
                                std::cout << "Список пуст!" << std::endl;
                            break;

                        case QUIT:
                            break;
                    }
                    break;

                case SAVECW2:
                    if (!(personalities.size() < 1))
                        SaveToFile(personalities);
                    else
                        std::cout << "Список пуст!" << std::endl;
                    break;

                case QUIT:
                    break;
            }
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW3(void)
{
    int user_choice{};
    do
    {
        std::vector<ISort*> sorts{};
        std::vector<ChessMatrix*> cmatrices{};

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

        std::vector<std::vector<int>> matrix{}, rows_to_save{}, columns_to_save{};
        int rows{}, columns{};
        std::string file_path{};
        UnitTestCW3 tests{};

        InfoCW3();
        ShowMainMenuCW3();

        switch (user_choice = GetKey(FILE_INPUT, RANDOM_INPUT))
        {
            case FILE_INPUT:
                file_path = CheckFileCW3();
                GetMatrixFromFile(matrix, rows, columns, file_path);
                break;

            case MANUAL_INPUT:
                std::cout << "Введите количество строк: ";
                rows = GetPosInt();
                std::cout << "Введите количество столбцов: ";
                columns = GetPosInt();

                FillMatrix(matrix, rows, columns);
                break;

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case RANDOM_INPUT:
                std::cout << "Введите количество строк: ";
                rows = GetPosInt();
                std::cout << "Введите количество столбцов: ";
                columns = GetPosInt();

                FillMatrixRandomly(matrix, rows, columns);
                break;

            case QUIT:
                break;
        }
        GoSort(matrix, rows, columns, sorts, cmatrices);

        while (user_choice != QUIT && user_choice != MODUL_TESTS)
        { 
            ShowMenuCW3();
            switch (user_choice = GetKey(SHOW, SAVECW3))
            {
                case SHOW:
                    ShowResults(matrix, rows, columns, sorts, cmatrices);
                    break;

                case SAVECW3:
                    SaveToFile(sorts, cmatrices, matrix, rows, columns);
                    break;

                case QUIT:
                    break;
            }
        }

        for (std::vector<ChessMatrix*>::iterator it = cmatrices.begin(); it != cmatrices.end(); it++)
        {
            delete *it;
        }
        delete bubble_sort;
        delete selection_sort;
        delete insertion_sort;
        delete shell_sort;
        delete quick_sort;

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW4(void)
{
    int user_choice{};
    do
    {
        std::string restoredText{}, modifiedText{}, text{}, file_path{};
        bool isSubstringSizeSetted = false, isLoopMenu = false;
        size_t substring_size = 2;
        UnitTestCW4 tests{};

        InfoCW4();
        ShowMainMenuCW4();

        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
                isLoopMenu = true;
                file_path = CheckFileCW4();
                GetTextFromFile(text, file_path);
                break;

            case MANUAL_INPUT:
                isLoopMenu = true;
                InputText(text);
                break;

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT:
                break;
        }

        while (isLoopMenu)
        {
            ShowMenuCW4();
            switch (user_choice = GetKey(ENTRY_LENGTH, SAVE_MODIFIED))
            {
                case ENTRY_LENGTH:
                    SetSubstringSize(substring_size);
                    isSubstringSizeSetted = true;
                    break;

                case SHOW_RESTORED:
                    if (restoredText.empty())
                        StartRestore(text, restoredText);
                    ShowRestored(restoredText);
                    break;

                case SHOW_MODIFIED:    
                    if (!isSubstringSizeSetted)
                    {
                        SetSubstringSize(substring_size);
                        isSubstringSizeSetted = true;
                    }
                    RestoreText(text);
                    std::cout << "Размер подстроки взят со значением = " << substring_size << std::endl;
                    StartModify(text, modifiedText, substring_size);
                    ShowModified(modifiedText);
                    break;

                case SAVE_RESTORED:
                    if (restoredText.empty())
                    {
                        std::cout << "Сначала восстановите текст!" << std::endl;
                        break;
                    }
                    SaveToFile(restoredText, modifiedText, SAVE_RESTORED);
                    break;

                case SAVE_MODIFIED:
                    if (modifiedText.empty())
                    {
                        std::cout << "Сначала модифицируйте текст!" << std::endl;
                        break;
                    }
                    SaveToFile(restoredText, modifiedText, SAVE_MODIFIED);
                    break;

                case QUIT:
                    isLoopMenu = false;
                    break;
            }
        }

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}
