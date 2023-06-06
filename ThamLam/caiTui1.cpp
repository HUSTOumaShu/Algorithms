#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b;
vector<int> w;
vector<int> c;

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        w.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }

    sort(w.begin(), w.end(), greater<int>());
}
