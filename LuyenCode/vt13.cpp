#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int Max = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
        Max = max(Max, arr[i] + arr[i + 1]);
    Max = max(Max, arr[0] + arr[n - 1]);

    int a = arr[0], b;
    for (int i = 0; i < n - 1; i++)
        if (Max == arr[i] + arr[i + 1])
            if (arr[i] > a)
            {
                a = arr[i];
                b = arr[i + 1];
            }
    if (Max == arr[n - 1] + arr[0])
        if (arr[n - 1] > a)
        {
            a = arr[n - 1];
            b = arr[0];
        }
    cout << a << " " << b << endl;
}
