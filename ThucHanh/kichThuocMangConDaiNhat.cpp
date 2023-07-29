#include <iostream>
#include <map>
#include <math.h>
using namespace std;
#define MAX 100000

int n, arr[MAX], tmp[MAX];
map<int, int> count;

int main()
{
    int maxRes = 0, j = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (auto it : count)
    {
        tmp[j] = it.second;
        j++;
    }
    for (int i = 0; i < j - 1; i++)
        maxRes = max(maxRes, (tmp[i] + tmp[i + 1]));
    cout << maxRes << endl;
}
