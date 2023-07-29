#include <iostream>
#include <math.h>
using namespace std;

int n;
int a[100001], res[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    res[0] = a[0];
    res[1] = a[1];
    for (int i = 2; i < n; i++)
    {
        res[i] = max(res[i - 1], res[i - 2] + a[i]);
    }
    cout << res[n - 1];
}
