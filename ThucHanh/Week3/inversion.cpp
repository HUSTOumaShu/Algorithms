#include <iostream>
#include <math.h>
using namespace std;
int const MOD = (1e9 + 7);
#define MAX 10

int n, a[MAX];
int tmp[MAX];

int _merge(int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    int count = 0;

    while ((i <= mid - 1) && (j <= right))
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
        {
            tmp[k++] = a[j++];
            count += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        tmp[k++] = a[i++];
    }

    while (j <= right)
    {
        tmp[k++] = a[j++];
    }

    for (int i = left; i <= right; i++)
    {
        a[i] = tmp[i];
    }
    return count;
}

int mergeSort(int left, int right)
{
    int mid, count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        count = (count + mergeSort(left, mid)) % MOD;
        count = (count + mergeSort(mid + 1, right)) % MOD;
        count = (count + _merge(left, mid, right)) % MOD;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << mergeSort(1, n) << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
