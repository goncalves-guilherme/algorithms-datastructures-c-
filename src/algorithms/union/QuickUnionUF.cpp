#include "QuickUnionUF.h"

void QuickUnionUF::init(uint size)
{
    this->data = std::vector<int>(size);

    for (int i = 0; i <= this->data.size(); i++)
    {
        data[i] = i;
    }
}

QuickUnionUF::QuickUnionUF(uint size)
{
    this->init(size);
}

bool QuickUnionUF::isConnected(int x, int y)
{
    return this->data[x] == this->data[y];
}

int QuickUnionUF::root(int i)
{
    while(this->data[i] != i)
    {
        i = data[i];
    }

    return i;
}

void QuickUnionUF::unionData(int x, int y)
{
    int i = root(x);
    int j = root(y);

    this->data[i] = j;
}