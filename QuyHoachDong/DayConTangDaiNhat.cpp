#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000

int n, arr[MAX], iSolve[MAX]; // iSolve luu tru loi giai bai toan thu i

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

void Trace(int i)
{
    for (int j = i - 1; j >= 0; j++)
    {
        if ((LIS(j) == LIS(i) - 1) && (arr[j] < arr[i]))
        {
            Trace(j);
            break;
        }
    }
    cout << arr[i] << " ";
}

int main()
{
    memset(iSolve, -1, sizeof(iSolve));
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << LIS(n - 1) << endl;
    Trace(n - 1);
}
