#include <iostream>
using namespace std;
#define MAX 50000

int N, C;
int w[MAX];
int MinRes[51][MAX];

int MinCost(int i, int x)
{
    if (x < 0)
        return 1000000;
    if (i == 0)
        return x;
    if (MinRes[i][x] != 0)
        return MinRes[i][x];
    int res = min(MinCost(i - 1, x), MinCost(i - 1, x - w[i]));
    MinRes[i][x] = res;
}

int main()
{
    cin >> N >> C;
    for (int i = 1; i <= N; i++)
        cin >> w[i];
    cout << C - MinCost(N, C);
    return 0;
}
