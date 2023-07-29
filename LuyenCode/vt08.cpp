#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 3] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        if (i % 2 == 1)
            arr[i] += abs(arr[i + 1] - arr[i - 1]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
