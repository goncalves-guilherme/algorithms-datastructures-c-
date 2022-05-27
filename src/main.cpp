#include <iostream>
#include <vector>

#include "algorithms/sorts/Sorts.h"

int main()
{
     std::vector<int> toSort = {10,3,1,2,5};

     merge_sort_recursive(toSort, 0, (int) toSort.size() - 1);
     
     return 0;
}