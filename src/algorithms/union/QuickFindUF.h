#ifndef __QUICK_FIND_UF__
#define __QUICK_FIND_UF__

#include <vector>
#include <iostream>

class QuickFindUF
{
    private:
        std::vector<int> data;
        
        void init(uint size);

    public:
        QuickFindUF(uint size);

        bool isConnected(int x, int y);

        void unionData(int x, int y);
};

#endif