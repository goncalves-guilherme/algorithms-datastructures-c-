#ifndef __QUICK_UNION_UF__
#define __QUICK_UNION_UF__

#include <vector>
#include <iostream>

class QuickUnionUF
{
    private:
        std::vector<int> data;
        
        void init(uint size);

        int root(int i);

    public:
        QuickUnionUF(uint size);

        bool isConnected(int x, int y);

        void unionData(int x, int y);
};

#endif