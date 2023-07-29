#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
            count++;
        }
    }
    cout << setprecision(4) << fixed << (double)sum / (double)count;
}
