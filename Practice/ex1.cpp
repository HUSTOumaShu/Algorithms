#include <iostream>
#include <string.h>
using namespace std;

int n, num, m;
int a[100001], mark[100001];

int solve(int l, int r, int Sum, int Num)
{
    if (Sum < 0)
        return 0;
    if (l == r)
        if (Sum == a[l] && Num == 1)
            return 1;
        else
            return 0;
    if (Num == 0)
        if (Sum == 0)
            return 1;
        else
            return 0;
    return solve(l + 1, r, Sum, Num) + solve(l + 1, r, Sum - a[l], Num - 1);
}

int main()
{
    cin >> n >> num >> m;
    memset(mark, 0, n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1, m, num);
}
