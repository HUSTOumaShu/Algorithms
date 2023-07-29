#include <iostream>
#include <string.h>
using namespace std;

long arr[1005], iSolve[1005];
long n;

int LIS(int i)
{
    if (i == 0)
    {
        iSolve[i] = 1;
        return iSolve[i];
    }
    if (iSolve[i] != -1)
        return iSolve[i];
    for (int j = 0; j < i; j++)
    {
        if (arr[j] < arr[i])
        {
            int res = max(1, LIS(j) + 1);
            iSolve[i] = res;
        }
    }
    if (iSolve[i] == -1)
        iSolve[i] = 1;
    return iSolve[i];
}

int main()
{
    memset(iSolve, -1, 1005);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << LIS(n - 1) << endl;
    for (int i = 0; i < n; i++)
        cout << LIS(n - 1) << " ";
}
