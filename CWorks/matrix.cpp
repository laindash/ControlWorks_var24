#include "matrix.h"
#include "ISort.h"
#include "input.h"


bool ChessMatrix::IsSorted(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

void ChessMatrix::StartSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it)
{
    int white_cage(0), black_cage(1);

    //sort white cages
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ((i + j) % 2 == white_cage)
                _whiteCage.push_back(arr[i][j]);
        }
        if (!_whiteCage.empty())
        {
            (*it)->Sort(_whiteCage);
            _sortedRows.push_back(_whiteCage);
            _whiteCage.clear();
        }
    }

    // sort black cages
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if ((i + j) % 2 == black_cage)
                _blackCage.push_back(arr[j][i]);
        }
        if (!_blackCage.empty())
        {
            (*it)->Sort(_blackCage);
            std::reverse(_blackCage.begin(), _blackCage.end()); //if sorting return reverse, else sorted and go reverse
            _sortedColumns.push_back(_blackCage);
            _blackCage.clear();
        }
    }
}

void ChessMatrix::ShowSortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it)
{
    std::cout << std::endl << (*it)->GetSortName() << std::endl;
    size_t max_length = GetMaxNumLength(arr, rows, columns);
    int el_index_even_row(0), el_index_odd_row(0), white_cage(0), black_cage(1), b_index(0), w_index(0);
    for (int i = 0; i < rows; i++)
    {
        int el_index = 0;
        if (columns != 1)
            w_index = i;

        for (int j = 0; j < columns; j++)
        {
            if (rows != 1)
                b_index = j;

            if ((i + j) % 2 == white_cage)
                ShowColoredNum(_sortedRows[w_index][el_index++], max_length, white_cage);
            else if (((i + j) % 2 == black_cage) && (i % 2 == 0))
                ShowColoredNum(_sortedColumns[b_index++][el_index_even_row], max_length, black_cage);
            else if (((i + j) % 2 == black_cage) && (i % 2 == 1))
                ShowColoredNum(_sortedColumns[b_index++][el_index_odd_row], max_length, black_cage);
        }
        if ((columns == 1) && (i % 2 == white_cage))
            w_index++;

        if (i % 2 == 0)
            el_index_even_row++;

        else
            el_index_odd_row++;

        std::cout << std::endl;
    }
}
