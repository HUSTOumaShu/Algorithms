#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int t;
int n, c, a[MAX];

bool check(int distance)
{
    int s1 = 1;
    int i = 1, j = 2;
    while (i < n)
    {
        while (j <= n && a[j] - a[i] < distance)
            j++;
        if (j <= n)
            s1++;
        if (s1 >= c)
            return true;
        i = j;
        j++;
    }
    return false;
}

int maxDistance()
{
    int l = 0;
    int r = a[n] - a[l];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << maxDistance() << endl;
    }
}
