#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "ISort.h"

class ChessMatrix
{
	std::vector<int> _whiteCage{}, _blackCage{};
	std::vector<std::vector<int>> _sortedRows{}, _sortedColumns{};
public:

	void StartSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it);
	void ShowSortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it);
	bool IsSorted(std::vector<int>& arr);
	std::vector<std::vector<int>> GetSortedRows() { return _sortedRows; };
	std::vector<std::vector<int>> GetSortedColumns() { return _sortedColumns; };

};

#endif