#include "ISort.h"
#include "input.h"


void BubbleSort::Sort(std::vector<int>& arr)
{
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                _swapCount++;
            }
            _comparisonCount++;
        }
    }
}


void SelectionSort::Sort(std::vector<int>& arr)
{
    size_t n = arr.size(), minIndex{};
    for (size_t i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            _comparisonCount++;
        }

        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
            _swapCount++;
        }
    }
}


void InsertionSort::Sort(std::vector<int>& arr)
{
    int temp = 0;
    bool same_index{};
    size_t n = arr.size(), i{}, j{};
    for (i = 1; i < n; i++)
    {
        same_index = false;
        j = i;
        temp = arr[i];
        while (j > 0 && arr[j - 1] > temp)
        {
            same_index = true;
            _comparisonCount++;
            arr[j] = arr[j - 1];
            j--;
        }
       _comparisonCount++;
       if (same_index)
       {
           arr[j] = temp;
           _swapCount++;
       }
    }
}


void ShellSort::Sort(std::vector<int>& arr)
{
    size_t n = arr.size(), gap = n / 2, i{}, j{};
    int temp{};
    bool same_index{};
    while (gap > 0)
    {
        for (i = gap; i < n; i++)
        {
            same_index = false;
            j = i;
            temp = arr[i];
            while (j >= gap && arr[j - gap] > temp)
            {
                same_index = true;
                _comparisonCount++;
                arr[j] = arr[j - gap];
                _swapCount++;
                j -= gap;
            }
           _comparisonCount++;
           if (same_index)
           {
               arr[j] = temp;
               _swapCount++;
           }
        }
        gap /= 2;
    }
}

void QuickSort::SortPartition(std::vector<int>& arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
            _comparisonCount++;
        }
        _comparisonCount++;

        while (arr[j] > pivot)
        {
            j--;
            _comparisonCount++;
        }
        _comparisonCount++;

        if (i <= j)
        {
            std::swap(arr[i++], arr[j--]);
            _swapCount++;
        }
    }

    if (left < j)
    {
        SortPartition(arr, left, j);
    }

    if (i < right)
    {
        SortPartition(arr, i, right);
    }
}

void QuickSort::Sort(std::vector<int>& arr)
{
    SortPartition(arr, 0, static_cast<int>(arr.size()) - 1);
}
