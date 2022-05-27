#include "QuickUnionBalanced.h"

void QuickUnionBalanced::init(uint size)
{
    this->data = std::vector<int>(size);
    this->weigths = std::vector<int>(size);

    for (int i = 0; i <= this->data.size(); i++)
    {
        this->data[i] = i;
        this->weigths[i] = 1;
    }
}

QuickUnionBalanced::QuickUnionBalanced(uint size)
{
    this->init(size);
}

bool QuickUnionBalanced::isConnected(int x, int y)
{
    return this->data[x] == this->data[y];
}

int QuickUnionBalanced::root(int i)
{
    while(this->data[i] != i)
    {
        i = this->data[i];
    }

    return i;
}

void QuickUnionBalanced::unionData(int x, int y)
{
    int i = root(x);
    int j = root(y);

    if(this->weigths[i] > this->weigths[j])
    {
        this->data[j] = i;
    }
    else
    {
        this->data[i] = j;
    }
}