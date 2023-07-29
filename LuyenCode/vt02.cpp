#include <iostream>
#include <map>
using namespace std;

map<int, int> count;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        count[tmp]++;
    }
    if (count.size() <= 1)
        cout << "NOT FOUND";
    else
    {
        int arr[1000005];
        int i = 0;
        for (auto it : count)
        {
            arr[i] = it.first;
            i++;
        }
        cout << arr[i - 2];
    }
}
