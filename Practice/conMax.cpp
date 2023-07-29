#include <iostream>
using namespace std;

int n, x, y;
int mark[21][21] = {0};
int rX[] = {-2, -2, -1, -1, +1, +1, +2, +2};
int rY[] = {-1, +1, -2, +2, -2, +2, -1, +1};
int res[21][2];

void solution()
{
    for (int i = 1; i <= n * n; i++)
        cout << res[i][0] << " " << res[i][1];
    cout << endl;
}

bool check(int k, int v)
{
    int vX = res[k - 1][0] + rX[v];
    int vY = res[k - 1][1] + rY[v];
    if (vX <= 0 || vY <= 0 || vX > n || vY > n || mark[vX][vY] == 1)
        return false;
    return true;
}

void Try(int k)
{
    for (int v = 0; v < 8; v++)
    {
        int vX = res[k - 1][0] + rX[v];
        int vY = res[k - 1][1] + rY[v];
        if (check(k, v))
        {
            res[k][0] = vX;
            res[k][1] = vY;
            mark[vX][vY] = 1;
            if (k == n * n - 1)
                solution();
            else
                Try(k + 1);
            mark[vX][vY] = 0;
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
