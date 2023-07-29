#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int u, v, weight;
    edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

struct Union_Find
{
    vector<int> iParent;
    Union_Find(int n)
    {
        iParent = vector<int>(n);
        for (int i = 0; i < n; i++)
            iParent[i] = i;
    }

    int Find(int x)
    {
        if (iParent[x] == x)
            return x;
        else
        {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }

    void Unite(int x, int y)
    {
        iParent[Find(x)] = Find(y);
    }
};

bool Edge_Cmp(const edge &a, const edge &b)
{
    return a.weight < b.weight;
}

int main()
{
}
