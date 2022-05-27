#include "Sorts.h"

int selection_sort_recursive_find_minimum(std::vector<int>& input, const int index);
void merge(std::vector<int>& input, const int begin, const int mid, const int end);

// Find the minimum and accumulate in the index i++ where i starts in 0
void selection_sort(std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        int min = i;

        // Find the minimum value
        for(int j = i + 1; j < input.size(); j++)
        {
            if(input[j] < input[min])
            {
                min = j;
            }
        }

        int temp = input[i];
        input[i] = input[min]; 
        input[min] = temp; 
    }
}

int selection_sort_recursive_find_minimum(std::vector<int>& input, const int index)
{
    if(index == input.size() - 1)
    {
        return index;
    }

    int k = selection_sort_recursive_find_minimum(input, index + 1);

    return input[index] > input[k] ? k : index;
}

void selection_sort_recursive(std::vector<int>& input, const int index)
{
    if(index == input.size())
    {
        return;
    }

    const int m = selection_sort_recursive_find_minimum(input, index);

    if(index != m)
    {
        const int temp = input[index];
        
        input[index] = input[m];
        input[m] = temp;
    }

    selection_sort_recursive(input, index + 1);
}

// Iterate over the list and shift your current value until it is less than the one on its left
void insert_sort(std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        // Find the minimum value
        for(int j = i; j > 0; j--)
        {
            if(input[j] < input[j-1])
            {
                int temp = input[j-1];

                input[j-1] = input[j];
                input[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

void merge(std::vector<int>& input, const int begin, const int mid, const int end)
{
    const int size1 = mid - begin + 1;
    const int size2 = end - mid;

    auto temp1 = std::vector<int>(size1);
    auto temp2 = std::vector<int>(size2);

    // Copy values from array to temp arrays
    for(int i = 0; i < size1; i++)
    {
        temp1[i] = input[i + begin];
    }
    for(int i = 0; i < size2; i++)
    {
        temp2[i] = input[i + mid + 1];
    }

    int index1 = 0;
    int index2 = 0;
    int inputIndex = begin;

    while(index1 < size1 && index2 < size2)
    {
        if(temp1[index1] <= temp2[index2])
        {
            input[inputIndex] = temp1[index1]; 
            index1++;
        }
        else
        {
            input[inputIndex] = temp2[index2]; 
            index2++;
        }

        inputIndex++;
    }

    while(index1 < size1)
    {
        input[inputIndex] = temp1[index1];

        index1++;
        inputIndex++;
    }

    while(index2 < size2)
    {
        input[inputIndex] = temp2[index2];

        index2++;
        inputIndex++;
    }
}

void merge_sort_recursive(std::vector<int>& input, const int begin, const int end)
{
    if(begin >= end)
    {
        return;
    }

    const int medium = begin + (end - begin) / 2;

    merge_sort_recursive(input, begin, medium);

    merge_sort_recursive(input, medium + 1, end);

    merge(input, begin, medium, end);
}

/*void merge_sort(std::vector<int>& input)
{   
}*/