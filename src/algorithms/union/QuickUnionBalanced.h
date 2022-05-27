#ifndef __QUICK_UNION_BALANCED__
#define __QUICK_UNION_BALANCED__

#include <vector>
#include <iostream>

class QuickUnionBalanced
{
    private:
        std::vector<int> data;
        std::vector<int> weigths;

        void init(uint size);

        int root(int i);

    public:
        QuickUnionBalanced(uint size);

        bool isConnected(int x, int y);

        void unionData(int x, int y);
};

#endif