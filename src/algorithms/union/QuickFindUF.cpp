#include "QuickFindUF.h"

void QuickFindUF::init(uint size)
{
    this->data = std::vector<int>(size);

    for (int i = 0; i <= this->data.size(); i++)
    {
        data[i] = i;
    }
}

QuickFindUF::QuickFindUF(uint size)
{
    this->init(size);
}

bool QuickFindUF::isConnected(int x, int y)
{
    return this->data[x] == this->data[y];
}

void QuickFindUF::unionData(int x, int y)
{
    int toUpdate = this->data[x];
    int newConnection = this->data[y];

    for (int i = 0; i <= this->data.size(); i++)
    {
        if (this->data[i] == toUpdate)
        {
            this->data[i] = newConnection;
        }
    }
}