#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr;
    for (long long i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    long long Max = 0;
    Max = arr[n - 1] * arr[n - 2] * arr[n - 3];
    Max = max(Max, arr[0] * arr[1] * arr[n - 1]);
    cout << Max << " ";
}
