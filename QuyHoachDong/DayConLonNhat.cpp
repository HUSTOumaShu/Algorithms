#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000

int n, arr[MAX], res[MAX];

int result(int i)
{
    // -16 7 -3 0 -1 5 -4
    if (i == 0)
        return max(arr[i], 0);
    if (arr[i] <= 0)
        return result(i - 1);
    else
    {
        int resu = result(i - 1);
        int j = i - 1;
        while (arr[j] <= 0 && j >= 0)
        {
            resu += arr[j];
            j--;
        }

        return max(max(resu + arr[i], arr[i]), result(i - 1));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << result(n - 1);
}
