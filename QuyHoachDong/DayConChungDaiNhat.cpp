#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000

string x, y;
int iSolve[MAX][MAX];

int LIS(int i, int j)
{
    if (i == 0 || j == 0)
    {
        iSolve[i][j] = 0;
        return iSolve[i][j];
    }
    if (iSolve[i][j] != -1)
        return iSolve[i][j];
    int res = max(LIS(i, j - 1), LIS(i - 1, j));
    if (x[i - 1] == y[j - 1])
        res = max(res, LIS(i - 1, j - 1) + 1);
    iSolve[i][j] = res;
    return res;
}

void Trace(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (iSolve[i][j] == iSolve[i - 1][j])
    {
        Trace(i - 1, j);
        return;
    }
    if (iSolve[i][j] == iSolve[i][j - 1])
    {
        Trace(i, j - 1);
        return;
    }
    if ((iSolve[i][j] == iSolve[i - 1][j - 1] + 1) && x[i - 1] == y[j - 1])
    {
        Trace(i - 1, j - 1);
        cout << x[i - 1] << " ";
        return;
    }
}

int main()
{
    memset(iSolve, -1, sizeof(iSolve));
    getline(cin, x);
    getline(cin, y);
    cout << LIS(x.length(), y.length()) << endl;
    Trace(x.length(), y.length());
}
