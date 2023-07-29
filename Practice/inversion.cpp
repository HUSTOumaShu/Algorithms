#include <iostream>
#include <math.h>
const int MOD = pow(10, 9) + 7;
using namespace std;

int n, count = 0;
int a[15], tmp[1000005];

void print()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Merge 2 array arr[l..m] & arr[m+1..r]
int merge(int arr[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;

    // Merge 2 array arr1 & arr2 to arr with sort
    while (i < m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
            count += (m - i);
            cout << count << endl;
        }
    }

    while (i <= m)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for (int i = 0; i <= r; i++)
        arr[i] = tmp[i];
    return count;
}

int mergeSort(int arr[], int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        count = (count + mergeSort(arr, l, m)) % MOD;
        count = (count + mergeSort(arr, m + 1, r)) % MOD;
        count = (count + merge(arr, l, m, r)) % MOD;
    }
    return count;
}

int main()
{
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << mergeSort(a, 0, n - 1) << endl;
    print();
}
