#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

int n, x, y;
int mark[MAX][MAX] = {0};
int runX[] = {-2, -2, -1, -1, +1, +1, +2, +2};
int runY[] = {-1, +1, -2, +2, -2, +2, -1, +1};
int res[MAX][2];

void solution()
{
    for (int i = 1; i <= n * n; i++)
        cout << res[i][0] << " " << res[i][1];
    cout << endl;
}

bool check(int k, int v)
{
    int x = res[k - 1][0] + runX[v];
    int y = res[k - 1][0] + runY[v];
    if (x <= 0 || y <= 0 || x >= n || y >= n || mark[x][y] == 1)
        return false;
    return true;
}

void Try(int k)
{
    for (int v = 0; v < 7; v++)
    {
        if (check(k, v))
        {
            int x = res[k - 1][0] + runX[v];
            int y = res[k - 1][0] + runY[v];
            mark[x][y] = 1;
            res[k][0] = x;
            res[k][0] = y;
            if (k == n * n)
                solution();
            else
                Try(k + 1);
            mark[x][y] = 0;
        }
    }
}

int main()
{
    cin >> n >> x >> y;
    mark[x][y] = 1;
    res[1][0] = x;
    res[1][1] = y;
    Try(2);
}
