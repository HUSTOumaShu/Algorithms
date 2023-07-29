#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int Max = -1000000000;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        Max = max(arr[i], Max);
    }
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] == Max)
        {
            cout << i << endl;
            break;
        }
}
