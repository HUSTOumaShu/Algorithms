#include <iostream>
using namespace std;

int n, A, B;
int a[21];

int solve(int l, int r, int Min, int Max)
{
    if (Max < 0)
        return 0;
    if (Min < 0)
        return 1;
    if (l == r)
        if (a[l] >= Min && a[l] <= Max)
            return 1;
        else
            return 0;
    return solve(l + 1, r, Min, Max) + solve(l + 1, r, Min - a[l], Max - a[l]);
}

int main()
{
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1, A, B);
}
