#include <iostream>
using namespace std;
#define MAX 20

int n, M;
int a[MAX];
int MinRes[21][100000];

int MinCoin(int i, int x)
{
    if (x < 0 || i == 0)
        return 100000;
    if (x == 0)
        return 0;
    if (MinRes[i][x] != 0)
        return MinRes[i][x];
    int res = min(1 + MinCoin(i, x - a[i]), MinCoin(i - 1, x));
    MinRes[i][x] = res;
}

int main()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (MinCoin(n, M) > M)
        cout << -1 << endl;
    else
        cout << MinCoin(n, M);
}
