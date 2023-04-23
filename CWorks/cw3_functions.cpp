#include "input.h"
#include "matrix.h"
#include "ISort.h"
#include <iostream>


void ShowUnsortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns)
{
    int white_cage(0), black_cage(1);
    size_t max_length = GetMaxNumLength(arr, rows, columns);
    std::cout << "»значальный массив: " << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ((i + j) % 2 == white_cage)
                ShowColoredNum(arr[i][j], max_length, white_cage);
            else
                ShowColoredNum(arr[i][j], max_length, black_cage);
        }
        std::cout << std::endl;
    }
}

void ShowComparisonTable(std::vector<ISort*>& sorts)
{
    for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++)
    {
        std::cout 
            << std::endl << (*it)->GetSortName() << std::endl
            << "(—равнений: " << (*it)->GetComparisons() 
            << ", ѕерестановок: " << (*it)->GetSwaps() << ")" << std::endl;
    }
}

void FillMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns)
{
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) 
    {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++)
        {
            std::cout << "¬ведите €чейку " << i + 1 << " строки " << j + 1 << " столбца " << std::endl;
            matrix[i][j] = GetInt();
        }
    }
}

void FillMatrixRandomly(std::vector<std::vector<int>>& matrix, int rows, int columns)
{
    const int lowBound = -100, upBound = 100;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++)
            matrix[i][j] = GetRandInt(lowBound, upBound);
    }
}

void GoSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<ChessMatrix*>& cmatrices)
{
    for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++)
    {
        ChessMatrix* cmatrix = new ChessMatrix;
        cmatrix->StartSort(arr, rows, columns, it);
        cmatrices.push_back(cmatrix);
    }
}

void ShowResults(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<ChessMatrix*>& cmatrices)
{   
    ShowUnsortedMatrix(arr, rows, columns);
    std::vector<ChessMatrix*>::iterator cm_it = cmatrices.begin();
    std::vector<ISort*>::iterator it = sorts.begin();
    for ( ; (it != sorts.end()) && (cm_it != cmatrices.end()); it++, cm_it++)
    {
        (*cm_it)->ShowSortedMatrix(arr, rows, columns, it);
    }
    ShowComparisonTable(sorts);
}
