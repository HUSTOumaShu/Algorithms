#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool check(long long n)
{
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        if (check(arr.at(i)))
            count[arr[i]]++;
    for (auto it : count)
        cout << it.first << " ";
}
