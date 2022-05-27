#ifndef __SORTS__
#define __SORTS__

#include <vector>

void selection_sort(std::vector<int>& input);

void insert_sort(std::vector<int>& input);

void merge_sort_recursive(std::vector<int>& input, const int right, const int left);

void merge_sort(std::vector<int>& input);

#endif